/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define TiniQVdata_out7_Pin GPIO_PIN_10
#define TiniQVdata_out7_GPIO_Port GPIOB
#define TiniQVdata_out6_Pin GPIO_PIN_11
#define TiniQVdata_out6_GPIO_Port GPIOB
#define TiniQVdata_out5_Pin GPIO_PIN_12
#define TiniQVdata_out5_GPIO_Port GPIOB
#define TiniQVdata_out4_Pin GPIO_PIN_13
#define TiniQVdata_out4_GPIO_Port GPIOB
#define TiniQVdata_out3_Pin GPIO_PIN_14
#define TiniQVdata_out3_GPIO_Port GPIOB
#define TiniQVdata_out2_Pin GPIO_PIN_15
#define TiniQVdata_out2_GPIO_Port GPIOB
#define TiniQVdata_out1_Pin GPIO_PIN_6
#define TiniQVdata_out1_GPIO_Port GPIOC
#define DC_Pin GPIO_PIN_7
#define DC_GPIO_Port GPIOC
#define TiniQVdata_out0_Pin GPIO_PIN_8
#define TiniQVdata_out0_GPIO_Port GPIOC
#define TiniQVdata_write_Pin GPIO_PIN_9
#define TiniQVdata_write_GPIO_Port GPIOC
#define TiniQVaddr3_Pin GPIO_PIN_8
#define TiniQVaddr3_GPIO_Port GPIOA
#define RST_Pin GPIO_PIN_9
#define RST_GPIO_Port GPIOA
#define TiniQVaddr2_Pin GPIO_PIN_10
#define TiniQVaddr2_GPIO_Port GPIOA
#define TiniQVaddr1_Pin GPIO_PIN_11
#define TiniQVaddr1_GPIO_Port GPIOA
#define TiniQVaddr0_Pin GPIO_PIN_12
#define TiniQVaddr0_GPIO_Port GPIOA
#define TiniQVdata_in7_Pin GPIO_PIN_15
#define TiniQVdata_in7_GPIO_Port GPIOA
#define TiniQVdata_in6_Pin GPIO_PIN_10
#define TiniQVdata_in6_GPIO_Port GPIOC
#define TiniQVdata_in5_Pin GPIO_PIN_11
#define TiniQVdata_in5_GPIO_Port GPIOC
#define TiniQVdata_in4_Pin GPIO_PIN_12
#define TiniQVdata_in4_GPIO_Port GPIOC
#define TiniQVdata_in3_Pin GPIO_PIN_2
#define TiniQVdata_in3_GPIO_Port GPIOD
#define TiniQVdata_in2_Pin GPIO_PIN_3
#define TiniQVdata_in2_GPIO_Port GPIOB
#define TiniQVdata_in1_Pin GPIO_PIN_4
#define TiniQVdata_in1_GPIO_Port GPIOB
#define TiniQVdata_in0_Pin GPIO_PIN_5
#define TiniQVdata_in0_GPIO_Port GPIOB
#define CS_Pin GPIO_PIN_6
#define CS_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
