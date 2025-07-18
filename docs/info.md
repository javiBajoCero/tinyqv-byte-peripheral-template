<!---

This file is used to generate your project datasheet. Please fill in the information below and delete any unused
sections.

You can also include images in this folder and reference them in the markdown. Each image must be less than
512 kb in size, and the combined size of all images must be less than 1 MB.
-->

## What it does

pretends to be a WS2812b addresable led, it can be daisychained with other real WS2812b leds, it fowards signals from DIN DOUT like  a real WS2812b LEd so it can be daisychained.

## Register map


| Address | Name        | Access | Description                                                                  |
|---------|-------------|--------|------------------------------------------------------------------------------|
| 0x0    | reg_r        | R      | Last Received RED byte                                                       |
| 0x1    | reg_g        | R      | Last Received GREEN byte                                                     |
| 0x2    | reg_b        | R      | Last Received BLUE byte                                                      |
| 0xE    | rgb_clear    | W      | clears rgb_ready when written with 0x00 this is not a register per se, it toggles back to 0x01 after clearing rgb_ready        |
| 0xF    | rgb_ready    | R      | 0xFF if just received data , latches to 0xFF untill cleared by rgb_clear  0x00 otherwise                            |

## How to test

-Connect a WS2812b driver on DIN pin ui_in[1],
-write 3byte rgb colours,
-rgb_ready should be 0xFF now
-proceed to read each colour byte.

## External hardware

WS2812b driver, more WS2812b LEDS or more impostors could be daisy chained DIN DOUT.
