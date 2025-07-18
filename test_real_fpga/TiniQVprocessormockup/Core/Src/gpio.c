/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, DC_Pin|TiniQVdata_write_Pin|TiniQVdata_in6_Pin|TiniQVdata_in5_Pin
                          |TiniQVdata_in4_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, TiniQVaddr3_Pin|RST_Pin|TiniQVaddr2_Pin|TiniQVaddr1_Pin
                          |TiniQVaddr0_Pin|TiniQVdata_in7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(TiniQVdata_in3_GPIO_Port, TiniQVdata_in3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, TiniQVdata_in2_Pin|TiniQVdata_in1_Pin|TiniQVdata_in0_Pin|CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : TiniQVdata_out7_Pin TiniQVdata_out6_Pin TiniQVdata_out5_Pin TiniQVdata_out4_Pin
                           TiniQVdata_out3_Pin TiniQVdata_out2_Pin */
  GPIO_InitStruct.Pin = TiniQVdata_out7_Pin|TiniQVdata_out6_Pin|TiniQVdata_out5_Pin|TiniQVdata_out4_Pin
                          |TiniQVdata_out3_Pin|TiniQVdata_out2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : TiniQVdata_out1_Pin TiniQVdata_out0_Pin */
  GPIO_InitStruct.Pin = TiniQVdata_out1_Pin|TiniQVdata_out0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : DC_Pin TiniQVdata_write_Pin TiniQVdata_in6_Pin TiniQVdata_in5_Pin
                           TiniQVdata_in4_Pin */
  GPIO_InitStruct.Pin = DC_Pin|TiniQVdata_write_Pin|TiniQVdata_in6_Pin|TiniQVdata_in5_Pin
                          |TiniQVdata_in4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : TiniQVaddr3_Pin RST_Pin TiniQVaddr2_Pin TiniQVaddr1_Pin
                           TiniQVaddr0_Pin TiniQVdata_in7_Pin */
  GPIO_InitStruct.Pin = TiniQVaddr3_Pin|RST_Pin|TiniQVaddr2_Pin|TiniQVaddr1_Pin
                          |TiniQVaddr0_Pin|TiniQVdata_in7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : TiniQVdata_in3_Pin */
  GPIO_InitStruct.Pin = TiniQVdata_in3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(TiniQVdata_in3_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : TiniQVdata_in2_Pin TiniQVdata_in1_Pin TiniQVdata_in0_Pin CS_Pin */
  GPIO_InitStruct.Pin = TiniQVdata_in2_Pin|TiniQVdata_in1_Pin|TiniQVdata_in0_Pin|CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */
