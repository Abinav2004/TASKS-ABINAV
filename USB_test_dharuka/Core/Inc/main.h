/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Speed4_Pin GPIO_PIN_1
#define Speed4_GPIO_Port GPIOA
#define Dir4_Pin GPIO_PIN_2
#define Dir4_GPIO_Port GPIOA
#define Speed3_Pin GPIO_PIN_5
#define Speed3_GPIO_Port GPIOA
#define Dir3_Pin GPIO_PIN_6
#define Dir3_GPIO_Port GPIOA
#define Speed1_Pin GPIO_PIN_4
#define Speed1_GPIO_Port GPIOB
#define Dir1_Pin GPIO_PIN_5
#define Dir1_GPIO_Port GPIOB
#define Speed2_Pin GPIO_PIN_8
#define Speed2_GPIO_Port GPIOB
#define Dir2_Pin GPIO_PIN_9
#define Dir2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
