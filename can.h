/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    can.h
  * @brief   This file contains all the function prototypes for
  *          the can.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#ifndef __CAN_H__
#define __CAN_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#include "gpio.h"
//#include "ioControl.h"
/* USER CODE END Includes */

extern CAN_HandleTypeDef hcan;

/* USER CODE BEGIN Private defines */
#define CAN_BUFFER_SIZE    8


typedef struct
{
  uint8_t txBuffer[CAN_BUFFER_SIZE];
  uint8_t rxBuffer[CAN_BUFFER_SIZE];
  uint8_t txLen;
  uint8_t rxLen;
  uint8_t rxStatus;
}CAN_DATA_st;


extern CAN_DATA_st canData;

/* USER CODE END Private defines */

void MX_CAN_Init(void);

/* USER CODE BEGIN Prototypes */
void configureFilters(CAN_HandleTypeDef* canHandle , uint16_t mask , uint16_t id);
void transmitMessage(CAN_HandleTypeDef* canHandle , uint16_t msgId);

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __CAN_H__ */

