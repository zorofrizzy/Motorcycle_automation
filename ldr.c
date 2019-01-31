#include<stdio.h>
#include<wiringPi.h>

#define LIGHT 2 // pin 2 for sensor
#define RELAY 9 // pin 9 for relay

int main()
{
  int LIGHT=0, RELAY=1, L;
  wiringPiSetup();
  pinMode(LIGHT, INPUT);
  pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, HIGH);
  
while(1)
  {
      L=digitalRead(LIGHT); // READ THE SENSOR
	

       if(L==1)
    {
	printf("LIGHT IS ON");
	digitalWrite(RELAY, LOW);
    }
     
       else
    {
	printf("LIGHT IS OFF");
	digitalWrite(RELAY, HIGH);
    }
   delay(500);


}
//END
}	