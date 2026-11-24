
#include <LiquidCrystal.h>
LiquidCrystal LCD(12,11,5,4,3,2);

int buzz = 9;
int SensorTemp=0;//A0
int blue=8; 
int red=13;//LED   
int tempmin=0; 
int tempmax=40;

void setup() {
	
  	pinMode(blue, OUTPUT);
	pinMode(red, OUTPUT);

	LCD.begin(16,2);
  LCD.clear();
	
}

void loop() {
	
	int voltage=analogRead(SensorTemp);
  	
	float degreeC=voltage*5;
	degreeC/=1024;
  
	float TemperatureC=(degreeC-0.5)*100;

  
    
    LCD.print("The Temperature ");
	LCD.setCursor(0,1);
	LCD.print("is: ");
  	LCD.print(TemperatureC);
  LCD.print(" C");

  	

  	if (TemperatureC>=tempmax) {
  		digitalWrite(blue, LOW);
  		digitalWrite(red, HIGH);
      tone(buzz, 587.23 , 1000);
  delay(1200);
       tone(buzz, 587.23 , 1000);
  delay(1200);
       tone(buzz, 587.23 , 1000);
  delay(1200);
    }
  	else if (TemperatureC<=tempmin){
  		digitalWrite(blue, HIGH);
  		digitalWrite(red, LOW);
       tone(buzz, 100 , 1000);
  delay(1000);
       tone(buzz, 100 , 1000);
  delay(1000);
       
  	}
  	else {
  		digitalWrite(blue, LOW);
  		digitalWrite(red, LOW);
    }

  	delay(3000);
  LCD.clear();
  
  
  float humidity = TemperatureC -12; 
  
  LCD.print("The humidity ");
	LCD.setCursor(0,1);
	LCD.print("is: ");
  	LCD.print(humidity);
  LCD.print(" %");
delay(3000);
  LCD.clear();
  	
}