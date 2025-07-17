<!---

This file is used to generate your project datasheet. Please fill in the information below and delete any unused
sections.

You can also include images in this folder and reference them in the markdown. Each image must be less than
512 kb in size, and the combined size of all images must be less than 1 MB.
-->

## What it does

pretends to be a WS2812b addresable led, it can be daisychained with other real WS2812b leds

## Register map

Document the registers that are used to interact with your peripheral

| Address | Name        | Access | Description                                                                  |
|---------|-------------|--------|------------------------------------------------------------------------------|
| 0x01    | RED_BYTE    | R      | Last Received RED byte                                                       |
| 0x02    | GREEN_BYTE  | R      | Last Received GREEN byte                                                     |
| 0x03    | BLUE_BYTE   | R      | Last Received BLUE byte                                                      |

## How to test

BLA BLA BLA

## External hardware

BLA BLA WS2812b driver BLA BLA
