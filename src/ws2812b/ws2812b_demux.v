`timescale 1ns / 1ps

module ws2812b_demux (
    input  wire clk,
    input  wire reset,

    input  wire din_raw,
    input  wire bit_valid,
    input  wire bit_value,
    input  wire byte_valid,
    input  wire idle,

    input  wire read_en,            // NEW: High for one clk when register is read
    input  wire [3:0] read_address, // NEW: Register address being read

    output reg  dout,
    output reg  rgb_ready           // Stays high until all 3 bytes are read
);

    // FSM
    localparam WAIT_RGB   = 2'b00;
    localparam FORWARDING = 2'b01;

    reg [1:0] state, next_state;
    reg [1:0] byte_count;

    // NEW: register read tracking
    reg [2:0] rgb_read_mask;

    // State + control
    always @(posedge clk) begin
        if (reset) begin
            state          <= WAIT_RGB;
            byte_count     <= 2'd0;
            dout           <= 1'b0;
            rgb_ready      <= 1'b0;
            rgb_read_mask  <= 3'b000;
        end else begin
            state <= next_state;

            case (state)
                WAIT_RGB: begin
                    dout <= 1'b0;
                    if (byte_valid) begin
                        byte_count <= byte_count + 1;
                        if (byte_count == 2'd2) begin
                            rgb_ready <= 1'b1;       // latch ready
                            rgb_read_mask <= 3'b000;  // reset read tracking
                        end
                    end
                end

                FORWARDING: begin
                    dout <= din_raw;

                    // Track reads to R, G, B (0x0, 0x1, 0x2)
                    if (read_en) begin
                        case (read_address)
                            4'h0: rgb_read_mask[0] <= 1;
                            4'h1: rgb_read_mask[1] <= 1;
                            4'h2: rgb_read_mask[2] <= 1;
                        endcase
                    end

                    // Auto-clear rgb_ready once all 3 read
                    if (rgb_read_mask == 3'b111)
                        rgb_ready <= 0;
                end
            endcase

            if (idle) begin
                byte_count     <= 2'd0;
                rgb_read_mask  <= 3'b000;
                rgb_ready      <= 0;
            end
        end
    end

    // FSM transitions
    always @(*) begin
        case (state)
            WAIT_RGB:
                next_state = (byte_count == 2'd2 && byte_valid) ? FORWARDING : WAIT_RGB;

            FORWARDING:
                next_state = idle ? WAIT_RGB : FORWARDING;

            default:
                next_state = WAIT_RGB;
        endcase
    end

endmodule
