/*
 * ioControl.c
 *
 *  Created on: 13-Aug-2022
 *      Author: ADMIN
 */

#include "inputoutput.h"

#define MECH_LOCK_OPEN            HIGH
#define MECH_LOCK_CLOSED          LOW


bool readDoorLock()
{
  return (bool)HAL_GPIO_ReadPin(DOOR_LOCK_INPUT_PORT, DOOR_LOCK_INPUT_PIN);
}


void setDoorLock(bool state)
{
  HAL_GPIO_WritePin(DOOR_LOCK_OUTPUT_PORT, DOOR_LOCK_OUTPUT_PIN,(GPIO_PinState)!state);
}


bool readMechanicalLock()
{
  return (bool)HAL_GPIO_ReadPin(MECH_LOCK_INPUT_PORT, MECH_LOCK_INPUT_PIN);
}


bool readMechanicalSensor()
{
  return (bool)HAL_GPIO_ReadPin(MECH_SENSOR_INPUT_PORT, MECH_SENSOR_INPUT_PIN);
}


void setMechanicalLock()
{

}



void initIOctrl()
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = DOOR_LOCK_INPUT_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(DOOR_LOCK_INPUT_PORT, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = MECH_LOCK_INPUT_PIN;
  HAL_GPIO_Init(MECH_LOCK_INPUT_PORT, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = MECH_SENSOR_INPUT_PIN;
  HAL_GPIO_Init(MECH_SENSOR_INPUT_PORT, &GPIO_InitStruct);

  /***************** OUTPUT DEF ********************/

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = DOOR_LOCK_OUTPUT_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(DOOR_LOCK_OUTPUT_PORT, &GPIO_InitStruct);


  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = FLOOR_SEL_IO1_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(FLOOR_SEL_IO1_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = FLOOR_SEL_IO2_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(FLOOR_SEL_IO2_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = FLOOR_SEL_IO3_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(FLOOR_SEL_IO3_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = FLOOR_SEL_IO4_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(FLOOR_SEL_IO4_PORT, &GPIO_InitStruct);

}



uint8_t getFloorId()
{
  uint8_t floorId;

  floorId = false;

  floorId |= HAL_GPIO_ReadPin(FLOOR_SEL_IO4_PORT, FLOOR_SEL_IO4_PIN);
  floorId = floorId<<1;
  floorId |= HAL_GPIO_ReadPin(FLOOR_SEL_IO3_PORT, FLOOR_SEL_IO3_PIN);
  floorId = floorId<<1;
  floorId |= HAL_GPIO_ReadPin(FLOOR_SEL_IO2_PORT, FLOOR_SEL_IO2_PIN);
  floorId = floorId<<1;
  floorId |= HAL_GPIO_ReadPin(FLOOR_SEL_IO1_PORT, FLOOR_SEL_IO1_PIN);

  return floorId;
}







