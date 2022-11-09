/*
 * button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: minhl
 */
#include "button.h"

int KeyReg0[3]= {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg1[3] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg2[3] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg3[3] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int TimeOutForKeyPress =  100;
int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;


int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}
int isButton2Pressed(){
	if(button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	return 0;
}
int isButton3Pressed(){
	if(button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	return 0;
}
void subKeyProcess(int i){
	//TODO
	if(i==0){
	button1_flag = 1;
	}
	else if(i==1){
		button2_flag = 1;
	}
	else if(i == 2){
		button3_flag = 1;
	}
}

void getKeyInput(){
  for(int i=0;i<3;i++){
	  KeyReg0[i] = KeyReg1[i];
	  KeyReg1[i] = KeyReg2[i];
	  if( i== 0){
	  KeyReg2[i] = HAL_GPIO_ReadPin(BTN1_GPIO_Port, BTN1_Pin);
	  }
	  else if(i==1){
		  KeyReg2[i] = HAL_GPIO_ReadPin(BTN2_GPIO_Port, BTN2_Pin);
	  }
	  else if(i==2){
		  KeyReg2[i] = HAL_GPIO_ReadPin(BTN3_GPIO_Port, BTN3_Pin);
	  }
	  if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
		  if (KeyReg2[i] != KeyReg3[i]){
			  KeyReg3[i] = KeyReg2[i];
			  if (KeyReg2[i] == PRESSED_STATE){
				TimeOutForKeyPress = 100;
				subKeyProcess(i);
			  }
		}else{
		   TimeOutForKeyPress --;
			if (TimeOutForKeyPress == 0){
			  KeyReg3[i] = NORMAL_STATE;
			}
		}
	  }
	}
}



