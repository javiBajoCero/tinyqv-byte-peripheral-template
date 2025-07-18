<!---

This file is used to generate your project datasheet. Please fill in the information below and delete any unused
sections.

You can also include images in this folder and reference them in the markdown. Each image must be less than
512 kb in size, and the combined size of all images must be less than 1 MB.
-->

## What it does

pretends to be a WS2812b addresable led, it can be daisychained with other real WS2812b leds

## Register map


| Address | Name        | Access | Description                                                                  |
|---------|-------------|--------|------------------------------------------------------------------------------|
| 0x0    | reg_r        | R      | Last Received RED byte                                                       |
| 0x1    | reg_g        | R      | Last Received GREEN byte                                                     |
| 0x2    | reg_b        | R      | Last Received BLUE byte                                                      |
| 0xF    | rgb_ready    | R      | 0xFF if just received data 0x0 otherwise                                     |
## How to test

BLA BLA BLA

## External hardware

BLA BLA WS2812b driver BLA BLA
