#include<stdio.h>
#include<wiringPi.h>
#include<stdlib.h>


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
		setup();
		while(1)
		{
			int dist=getCM();
			printf("Distance: %dcm\n",dist);
			delay(1000);
		}
	}
