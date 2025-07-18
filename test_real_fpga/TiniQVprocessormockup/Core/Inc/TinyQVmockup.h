/*
 * TinyQVmockup.h
 *
 *  Created on: Jul 18, 2025
 *      Author: JavierMunozSaez
 */

#ifndef INC_TINYQVMOCKUP_H_
#define INC_TINYQVMOCKUP_H_

#include "main.h"
#include "tt_um_impostor_WS2812b.h"

extern GPIO_PinState data_write_wire;
extern GPIO_PinState addr_bus[4];
extern GPIO_PinState data_in_bus[8];
extern GPIO_PinState data_out_bus[8];

void writeRegisterToPheripheral(uint8_t addr, uint8_t data);
uint8_t readRegisterFromPheripheral(uint8_t addr);

#endif /* INC_TINYQVMOCKUP_H_ */
