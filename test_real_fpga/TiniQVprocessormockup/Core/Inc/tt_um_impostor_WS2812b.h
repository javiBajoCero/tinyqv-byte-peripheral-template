/*
 * tt_um_impostor_WS2812b.h
 *
 *  Created on: Jul 18, 2025
 *      Author: JavierMunozSaez
 */

#ifndef INC_TT_UM_IMPOSTOR_WS2812B_H_
#define INC_TT_UM_IMPOSTOR_WS2812B_H_

typedef enum {
    REG_R         = 0x00,  // Last received RED byte (read-only)
    REG_G         = 0x01,  // Last received GREEN byte (read-only)
    REG_B         = 0x02,  // Last received BLUE byte (read-only)

    REG_RGB_CLEAR = 0x0E,  // Write-only: clears rgb_ready when written with 0x00
    REG_RGB_READY = 0x0F   // Read-only: 0xFF = data received, 0x00 = cleared
} Registers_t;

typedef enum {
    RGB_NOT_READY = 0x00,  // No new data (cleared)
    RGB_READY     = 0xFF   // New data has been received
} RgbReadyState_t;

typedef enum {
    RGB_CLEAR_CMD = 0x00,  // Command to clear rgb_ready (write this)
    RGB_CLEAR_IDLE = 0x01  // Internal/reset state after clear (readback not allowed)
} RgbClearCommand_t;


#endif /* INC_TT_UM_IMPOSTOR_WS2812B_H_ */
