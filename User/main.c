#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Servo.h"
#include "Key.h"

uint8_t KeyNum;
long double Angle;
int d;

int main(void)
{	
	OLED_Init();
	Servo_Init();
	Key_Init();
	d=0;
	Angle=0;
	Servo_SetAngle(Angle);
	OLED_ShowString(1,1,"Angle");
	
	while (1)
	{	KeyNum = Key_GetNum();
		if (KeyNum == 1){
			if(d==0){
				Angle+=90;
				if(Angle>=180){
					d=1;
				}
			}
			else{
				Angle-=90;
				if(Angle<=0){
					d=0;
				}
			}
		}
		
		Servo_SetAngle(Angle);
		OLED_ShowNum(1,7,Angle,3);
		Delay_ms(1);
	}
}
