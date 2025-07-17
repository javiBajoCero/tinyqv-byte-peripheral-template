    `timescale 1ns / 1ps

module ws2812b_pulse_decoder #(
    parameter CLK_HZ = 64000000,            // system clock frequency
    parameter THRESHOLD_CYCLES = 38         // ~600ns at 64MHz (decoding threshold)
)(
    input  wire clk,
    input  wire reset,
    input  wire din,         // raw WS2812B signal
    output reg  bit_valid,   // pulse decoded, valid for 1 cycle
    output reg  bit_value    // 0 or 1 based on HIGH pulse width
);

    // FSM states
    typedef enum logic [1:0] {
        IDLE      = 2'b00,
        COUNT_HIGH= 2'b01,
        WAIT_LOW  = 2'b10
    } state_t;

    state_t state, next_state;

    reg [7:0] high_counter;  // counts length of HIGH pulse
    reg       din_sync_0, din_sync_1;

    // Synchronize DIN to clk domain (helps with metastability)
    always @(posedge clk) begin
        din_sync_0 <= din;
        din_sync_1 <= din_sync_0;
    end

    wire din_stable = din_sync_1;

    // State transition
    always @(posedge clk) begin
        if (reset) begin
            state <= IDLE;
            high_counter <= 0;
            bit_valid <= 0;
            bit_value <= 0;
        end else begin
            state <= next_state;
            bit_valid <= 0;  // default: deassert

            case (state)
                IDLE: begin
                    if (din_stable)
                        high_counter <= 1;
                end
                COUNT_HIGH: begin
                    if (din_stable)
                        high_counter <= high_counter + 1;
                end
                WAIT_LOW: begin
                    if (!din_stable) begin
                        // Decode bit
                        bit_valid <= 1;
                        bit_value <= (high_counter > THRESHOLD_CYCLES) ? 1'b1 : 1'b0;
                    end
                end
            endcase
        end
    end

    // Next state logic
    always @(*) begin
        case (state)
            IDLE:
                next_state = (din_stable) ? COUNT_HIGH : IDLE;

            COUNT_HIGH:
                next_state = (din_stable) ? COUNT_HIGH : WAIT_LOW;

            WAIT_LOW:
                next_state = (!din_stable) ? IDLE : WAIT_LOW;

            default:
                next_state = IDLE;
        endcase
    end

endmodule
