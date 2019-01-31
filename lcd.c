#include<stdio.h>
#include<wiringPi.h>
#include<stdlib.h>
#include<lcd.h>

#define LCD_RS 25
#define LCD_E 24
#define LCD_D4 29
#define LCD_D5 28
#define LCD_D6 27
#define LCD_D7 26

#define TRIG 0
#define ECHO 1

void setup()
	{

		wiringPiSetup();

		pinMode(TRIG, OUTPUT);
		pinMode(ECHO,INPUT);

		digitalWrite(TRIG,LOW);
		delay(30);
	}




	int getCM()
	{
		

		digitalWrite(TRIG,HIGH);
		delayMicroseconds(20);
		digitalWrite(TRIG,LOW);

		while(digitalRead(ECHO)==LOW);
		
		long startTime=micros();
		
		while(digitalRead(ECHO)==HIGH);
		
		long travelTime=micros()-startTime;
		
		int distance=travelTime*0.034/2;
		
		return distance;
	}	
	



	int main()
	{
		int lcd;
		setup();

		lcd=lcdInit(2,16,4,LCD_RS,LCD_E,LCD_D4,LCD_D5,LCD_D6,LCD_D7,0,0,0,0);

		while(1)
		{lcdPosition(lcd,0,0);
			int dist=getCM();
		lcdPrintf(lcd,"Distance:%dcm\n",dist);
		printf("Distance:%d\n",dist);
		delay(100);
			
		}}
