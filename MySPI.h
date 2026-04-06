#ifndef __MYSPI_H
#define __MYSPI_H
#include "stm32f10x.h"                  // Device header

#if USE_HORIZONTAL==1	//使用横屏
#define X_MAX_PIXEL	        160
#define Y_MAX_PIXEL	        128
#else
#define X_MAX_PIXEL	        128
#define Y_MAX_PIXEL	        160
#endif

#define USE_HORIZONTAL  	0   //定义是否使用横屏 		0,不使用.  1,使用.


//LCD重要参数集
typedef struct  
{										    
	u16 width;			//LCD 宽度
	u16 height;			//LCD 高度
	u16 id;				//LCD ID
	u8  dir;			//横屏还是竖屏控制：0，竖屏；1，横屏。	
	u16	 wramcmd;		//开始写gram指令
	u16  setxcmd;		//设置x坐标指令
	u16  setycmd;		//设置y坐标指令	 
}_lcd_dev; 	

//LCD参数
extern _lcd_dev lcddev;	//管理LCD重要参数


#define RED  	  0xf800
#define GREEN	  0x07e0
#define BLUE 	  0x001f
#define WHITE	  0xffff
#define BLACK	  0x0000
#define YELLOW  0xFFE0
#define GRAY0   0xEF7D   	//灰色0 3165 00110 001011 00101
#define GRAY1   0x8410      	//灰色1      00000 000000 00000
#define GRAY2   0x4208      	//灰色2  1111111111011111



//液晶控制口置1操作语句宏定义
#define	LCD_SDA_SET  	GPIO_SetBits(GPIOA,GPIO_Pin_7) //PA7-MOSI
#define	LCD_SCL_SET  	GPIO_SetBits(GPIOA,GPIO_Pin_5) //PA5-SCL

#define	LCD_CS_SET  	GPIO_SetBits(GPIOA,GPIO_Pin_4) //PA4-NSS，主机选中引脚
#define LCD_RST_SET   GPIO_SetBits(GPIOA,GPIO_Pin_6);//PA6-MISO，RST引脚输出为高

#define	LCD_RS_SET  	GPIO_SetBits(GPIOB,GPIO_Pin_11)  //PB0 决定数据还是命令，0命令1数据
#define	LCD_BLK_SET  	GPIO_SetBits(GPIOB,GPIO_Pin_12)  //PB1背光引脚 

//液晶控制口置0操作语句宏定义

#define	LCD_SDA_CLR  	GPIO_ResetBits(GPIOA,GPIO_Pin_7)    
#define	LCD_SCL_CLR  	GPIO_ResetBits(GPIOA,GPIO_Pin_5)  

#define	LCD_CS_CLR  	GPIO_ResetBits(GPIOA,GPIO_Pin_4) 
#define LCD_RST_CLR   GPIO_ResetBits(GPIOA,GPIO_Pin_6);//RST引脚输出为低

#define	LCD_RS_CLR  	GPIO_ResetBits(GPIOB,GPIO_Pin_11) 
#define	LCD_BLK_CLR  	GPIO_ResetBits(GPIOB,GPIO_Pin_12) 

void Lcd_Init(void);
void Lcd_SetRegion(u16 x_start,u16 y_start,u16 x_end,u16 y_end);//设置显示区域
void Lcd_Clear(u16 Color);//用某一颜色清屏
uint16_t Lcd_ReadPoint_16(u16 x,u16 y ,uint16_t Data);//读出某一点的色彩，交换
void Gui_DrawPoint(u16 x,u16 y,u16 Data);//画一个2*3或者3*2的点
void Lcd_SetXY(u16 x,u16 y);//设置光标

//以下为底层函数，基本用不上
void  SPI_WriteData(u8 Data);
void Lcd_WriteIndex(u8 Index);
void Lcd_WriteData(u8 Data);
void LCD_SetParam(void);
void LCD_WriteData_16Bit(uint16_t Data);//写入某一点数据
void Lcd_Reset(void);

uint8_t MySPI_SwapByte(uint8_t ByteSend);//交换8位数据

void MySPI_Init(void);
void Lcd_WriteReg(u8 Index,u8 Data);







#endif
