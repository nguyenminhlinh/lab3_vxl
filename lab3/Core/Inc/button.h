/*
 * button.h
 *
 *  Created on: Nov 5, 2022
 *      Author: minhl
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_
#include "main.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET
extern int button1_flag;
extern int button2_flag;
extern int button3_flag;
void getKeyInput();
int isButton1Pressed();
int isButton2Pressed();
int isButton3Pressed();

#endif /* INC_BUTTON_H_ */
