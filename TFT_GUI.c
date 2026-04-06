#include "stm32f10x.h"                  // Device header
#include "MySPI.h" 
#include "TFT_GUI.h" 
#include "TFT_GUI_Font.h"
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

/*使用竖屏——128*160  原点->最右边->下一行最左边->该行最右边>...... */
void TFT_GUI_Init(u16 Color) // 初始化TFT，背板为Color
{
	
	Lcd_Init();
	Lcd_Clear(Color);

}

void TFT_Show_Point(u8 X,u8 Y)
{
	Gui_DrawPoint(X,Y,0x0000);
}

/*****************************************
 函数功能：画一条横线                        
 出口参数：颜色                               
******************************************/

void DrawLine(u8 X, u8 Y ,u16 Color)
{
	for(u8 i =0 ;i<128-X ;i++)
	{
		Gui_DrawPoint(X+i,Y,Color);
	}
	
}

/*****************************************
 函数功能：输出一个字符                     
 出口参数：区域                               
******************************************/

void TFT_ShowChar(u8 X_Start, u8 Y_Start , char Num)
{
	Lcd_SetRegion(X_Start, Y_Start, X_Start+6,Y_Start+12 );
	for(u8 i=0 ;i< 12;i++)
	{
		for(u8 j =0; j<= 6;j++)
		{
			if((TFT_Font[Num-' '][i] & (0x01<<j)) == 0)
			{
				LCD_WriteData_16Bit(BackColor);//背景颜色
			}
			
			else{LCD_WriteData_16Bit(FrontColor);}//文字颜色
			
		}
	}
}


/*****************************************
 函数功能：输出一串字符                     
 出口参数：区域                               
******************************************/

void TFT_ShowString(u8 X_Start, u8 Y_Start , char *String)
{
		for (u8 i = 0; String[i] != '\0'; i++)
	{
		TFT_ShowChar(X_Start+6*i, Y_Start , String[i]);
	}
}

/*****************************************
 函数功能：计算相应位的余数                   
 出口参数：区域                               
******************************************/
uint32_t TFT_Pow(uint32_t X, uint32_t Y)
{
	u32 Result = 1;
	while (Y--)
	{
		Result *= X;
	}
	return Result;
}


/*****************************************
 函数功能：输出数字                 
 出口参数：区域                               
******************************************/

void TFT_ShowUnSignedNum(u8 X_Start , u8 Y_Start ,u32 Number , u8 Length )
{
	
	for (u8 i = 0; i < Length; i++)							
	{
		TFT_ShowChar(X_Start + 6*i, Y_Start , Number / TFT_Pow(10, Length - i - 1) % 10 + '0');
	}
	
}


/*****************************************
 函数功能：输出有符号数                
 出口参数：区域                               
******************************************/
void TFT_ShowSignedNum(u8 X_Start , u8 Y_Start ,s32 SignedNumber , u8 Length )
{
	
	if(SignedNumber>=0)
	{
		TFT_ShowChar(X_Start, Y_Start , '+');
		for (u8 i = 1; i <=Length; i++)							
		{
		TFT_ShowChar(X_Start + 6*i, Y_Start , SignedNumber / TFT_Pow(10, Length - i - 1) % 10 + '0');
		}
	}
	else
	{
		s32 Number = -SignedNumber;
		TFT_ShowChar(X_Start, Y_Start , '-');
		for (u8 i = 1; i <=Length; i++)							
		{
		TFT_ShowChar(X_Start + 6*i, Y_Start , Number / TFT_Pow(10, Length - i - 1) % 10 + '0');
		}
	}
	
}

//uint8_t TFT_Font[][16]
