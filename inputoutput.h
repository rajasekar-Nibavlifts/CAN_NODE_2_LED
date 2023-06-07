/*
 * ioControl.h
 *
 *  Created on: 13-Aug-2022
 *      Author: ADMIN
 */

#ifndef SRC_IOCONTROL_H_
#define SRC_IOCONTROL_H_


#include "gpio.h"
#include "stdbool.h"
#include "common.h"
#include "stm32f1xx_hal.h"



//

#define DOOR_LOCK_INPUT_PORT        GPIOA
#define DOOR_LOCK_INPUT_PIN         GPIO_PIN_6

#define DOOR_LOCK_OUTPUT_PORT        GPIOB
#define DOOR_LOCK_OUTPUT_PIN         GPIO_PIN_9

#define MECH_LOCK_INPUT_PORT        GPIOB
#define MECH_LOCK_INPUT_PIN         GPIO_PIN_0

#define MECH_SENSOR_INPUT_PORT        GPIOA
#define MECH_SENSOR_INPUT_PIN         GPIO_PIN_7


#define FLOOR_SEL_IO1_PORT           GPIOB
#define FLOOR_SEL_IO1_PIN            GPIO_PIN_13

#define FLOOR_SEL_IO2_PORT           GPIOB
#define FLOOR_SEL_IO2_PIN            GPIO_PIN_14

#define FLOOR_SEL_IO3_PORT           GPIOB
#define FLOOR_SEL_IO3_PIN            GPIO_PIN_15

#define FLOOR_SEL_IO4_PORT           GPIOA
#define FLOOR_SEL_IO4_PIN            GPIO_PIN_8




void initIOctrl();
/// INPUTS
bool readMechanicalLock();
bool readDoorLock();
bool readMechanicalSensor();

//outputs
void setDoorLock(bool state);

/**
 * floor id
 */
uint8_t getFloorId();


#endif /* SRC_IOCONTROL_H_ */


