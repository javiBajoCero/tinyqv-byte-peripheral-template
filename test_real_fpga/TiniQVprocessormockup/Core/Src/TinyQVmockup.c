/*
 * TinyQVmockup.c
 *
 *  Created on: Jul 18, 2025
 *      Author: JavierMunozSaez
 */


#include "TinyQVmockup.h"

GPIO_PinState data_write_wire;
GPIO_PinState addr_bus[4];
GPIO_PinState data_in_bus[8];
GPIO_PinState data_out_bus[8];

void from_byte_to_gpio_status(uint8_t byte, uint8_t* gpio_status_array, uint8_t bit_size) {
	if (gpio_status_array == NULL) return;
	if (bit_size > 8) bit_size = 8;

	for (uint8_t i = 0; i < bit_size; ++i) {
		gpio_status_array[i] = (byte >> i) & 0x1 ? GPIO_PIN_SET : GPIO_PIN_RESET;
	}
}

uint8_t from_gpiostatus_to_byte(uint8_t* gpio_status_array, uint8_t bit_size) {
	if (gpio_status_array == NULL) return 0;
	if (bit_size > 8) bit_size = 8;

	uint8_t byte = 0;

	for (uint8_t i = 0; i < bit_size; ++i) {
		if (gpio_status_array[i] == GPIO_PIN_SET) {
			byte |= (1 << i);
		}
	}

	return byte;
}


void writeGPIOSaddr_bus(uint8_t* array){
	HAL_GPIO_WritePin(TiniQVaddr0_GPIO_Port, TiniQVaddr0_Pin, array[0]);
	HAL_GPIO_WritePin(TiniQVaddr1_GPIO_Port, TiniQVaddr1_Pin, array[1]);
	HAL_GPIO_WritePin(TiniQVaddr2_GPIO_Port, TiniQVaddr2_Pin, array[2]);
	HAL_GPIO_WritePin(TiniQVaddr3_GPIO_Port, TiniQVaddr3_Pin, array[3]);
}

void writeGPIOSdata_in_bus(uint8_t* array){
	HAL_GPIO_WritePin(TiniQVdata_in0_GPIO_Port, TiniQVdata_in0_Pin, array[0]);
	HAL_GPIO_WritePin(TiniQVdata_in1_GPIO_Port, TiniQVdata_in1_Pin, array[1]);
	HAL_GPIO_WritePin(TiniQVdata_in2_GPIO_Port, TiniQVdata_in2_Pin, array[2]);
	HAL_GPIO_WritePin(TiniQVdata_in3_GPIO_Port, TiniQVdata_in3_Pin, array[3]);
	HAL_GPIO_WritePin(TiniQVdata_in4_GPIO_Port, TiniQVdata_in4_Pin, array[0]);
	HAL_GPIO_WritePin(TiniQVdata_in5_GPIO_Port, TiniQVdata_in5_Pin, array[1]);
	HAL_GPIO_WritePin(TiniQVdata_in6_GPIO_Port, TiniQVdata_in6_Pin, array[2]);
	HAL_GPIO_WritePin(TiniQVdata_in7_GPIO_Port, TiniQVdata_in7_Pin, array[3]);
}

void readGPIOSdata_out_bus(uint8_t* array){
	array[0]=HAL_GPIO_ReadPin(TiniQVdata_out0_GPIO_Port, TiniQVdata_out0_Pin);
	array[1]=HAL_GPIO_ReadPin(TiniQVdata_out1_GPIO_Port, TiniQVdata_out1_Pin);
	array[2]=HAL_GPIO_ReadPin(TiniQVdata_out2_GPIO_Port, TiniQVdata_out2_Pin);
	array[3]=HAL_GPIO_ReadPin(TiniQVdata_out3_GPIO_Port, TiniQVdata_out3_Pin);
	array[4]=HAL_GPIO_ReadPin(TiniQVdata_out4_GPIO_Port, TiniQVdata_out4_Pin);
	array[5]=HAL_GPIO_ReadPin(TiniQVdata_out5_GPIO_Port, TiniQVdata_out5_Pin);
	array[6]=HAL_GPIO_ReadPin(TiniQVdata_out6_GPIO_Port, TiniQVdata_out6_Pin);
	array[7]=HAL_GPIO_ReadPin(TiniQVdata_out7_GPIO_Port, TiniQVdata_out7_Pin);
}


void writeRegisterToPheripheral(uint8_t addr, uint8_t data){
	from_byte_to_gpio_status(addr,addr_bus,4);
	from_byte_to_gpio_status(addr,data_in_bus ,8);
	writeGPIOSaddr_bus(addr_bus);
	writeGPIOSdata_in_bus(data_in_bus);
	HAL_GPIO_WritePin(TiniQVdata_write_GPIO_Port, TiniQVdata_write_Pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(TiniQVdata_write_GPIO_Port, TiniQVdata_write_Pin, GPIO_PIN_RESET);
}

uint8_t readRegisterFromPheripheral(uint8_t addr){
	from_byte_to_gpio_status(addr,addr_bus,4);
	writeGPIOSaddr_bus(addr_bus);
	HAL_Delay(1);
	readGPIOSdata_out_bus(data_out_bus);
	return from_gpiostatus_to_byte(data_out_bus, 8);
}
