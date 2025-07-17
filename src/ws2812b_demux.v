`timescale 1ns / 1ps

module ws2812b_demux (
    input  wire clk,
    input  wire reset,

    input  wire bit_valid,
    input  wire bit_value,
    input  wire byte_valid,
    input  wire idle,

    output reg  dout,
    output reg  rgb_ready  // high for 1 cycle after RGB is captured
);

    typedef enum logic [1:0] {
        WAIT_RGB   = 2'b00,
        FORWARDING = 2'b01
    } state_t;

    state_t state, next_state;

    reg [1:0] byte_count;

    // State + control
    always @(posedge clk) begin
        if (reset) begin
            state <= WAIT_RGB;
            byte_count <= 2'd0;
            dout <= 1'b0;
            rgb_ready <= 1'b0;
        end else begin
            state <= next_state;
            rgb_ready <= 1'b0;

            case (state)
                WAIT_RGB: begin
                    if (byte_valid) begin
                        byte_count <= byte_count + 1;
                        if (byte_count == 2'd2)
                            rgb_ready <= 1'b1;  // signal RGB is fully captured
                    end
                end

                FORWARDING: begin
                    if (bit_valid)
                        dout <= bit_value;
                end
            endcase

            if (state != FORWARDING && next_state == FORWARDING)
                dout <= 1'b0;  // clear output when switching to forwarding

            if (idle) begin
                byte_count <= 2'd0;
            end
        end
    end

    // Next state logic
    always @(*) begin
        case (state)
            WAIT_RGB: begin
                if (byte_count == 2'd2 && byte_valid)
                    next_state = FORWARDING;
                else
                    next_state = WAIT_RGB;
            end

            FORWARDING: begin
                if (idle)
                    next_state = WAIT_RGB;
                else
                    next_state = FORWARDING;
            end

            default: next_state = WAIT_RGB;
        endcase
    end

endmodule
