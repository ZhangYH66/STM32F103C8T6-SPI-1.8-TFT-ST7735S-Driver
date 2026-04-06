#ifndef __TFT_GUI_H
#define __TFT_GUI_H
#include "stm32f10x.h"                  // Device header

#define BackColor WHITE
#define FrontColor RED

//                颜色在MySPI.h中定义
//#define RED  	  0xf800
//#define GREEN	  0x07e0
//#define BLUE 	  0x001f
//#define WHITE	  0xffff
//#define BLACK	  0x0000
//#define YELLOW  0xFFE0
//#define GRAY0   0xEF7D   	//灰色0 3165 00110 001011 00101
//#define GRAY1   0x8410      	//灰色1      00000 000000 00000
//#define GRAY2   0x4208      	//灰色2  1111111111011111


void TFT_GUI_Init(u16 Color);
void TFT_ShowChar(u8 X_Start, u8 Y_Start , char Num);
void TFT_ShowString(u8 X_Start, u8 Y_Start , char *String);
void TFT_ShowUnSignedNum(u8 X_Start , u8 Y_Start ,u32 Number , u8 Length );
void TFT_ShowSignedNum(u8 X_Start , u8 Y_Start ,s32 SignedNumber , u8 Length );


void TFT_Show_Point(u8 X,u8 Y);
void DrawLine(u8 X, u8 Y ,u16 Color);


#endif
