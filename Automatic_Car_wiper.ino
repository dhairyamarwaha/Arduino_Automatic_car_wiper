#include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
Servo myservo; 

int pos = 0; 
int sensorValue = 0;
int led_red = 8;
int led_green = 10;
int led_yellow = 12;
void setup() {
  Serial.begin(9600);
  lcd.begin();
  myservo.attach(7);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("   AUTOMATIC "); 
  lcd.setCursor(0,1);
  lcd.print("   CAR WIPER ");
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  delay(5000); 
}

void loop() 
{
sensorValue = analogRead(A0);
Serial.println(sensorValue);
if(sensorValue>800){
  myservo.write(180);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("     NO RAIN ");
  digitalWrite(led_red, LOW);
  digitalWrite(led_red, LOW);
  digitalWrite(led_red, LOW);
  delay(1000);
  }
if(sensorValue<=800 && sensorValue>600){
  lcd.setCursor(0,0);
  lcd.print("IT IS RAINING ");
  lcd.setCursor(0,1);
  lcd.print("AMOUNT : LOW  ");
  digitalWrite(led_red, LOW);
  digitalWrite(led_green, HIGH);
  digitalWrite(led_yellow, LOW);
  
  for (pos = 180; pos >= 0; pos-=1) {
    myservo.write(pos);            
    delay(3);                    
  }
  for (pos = 0; pos <= 180; pos+=1) { 
    myservo.write(pos);             
    delay(3);        
  }
  delay(2000);
}

if(sensorValue<=600 && sensorValue>460){
  lcd.setCursor(0,0);
  lcd.print("IT IS RAINING   ");
  lcd.setCursor(0,1);
  lcd.print("AMOUNT: MEDIUM ");
  digitalWrite(led_red, LOW);
  digitalWrite(led_green,HIGH);
  digitalWrite(led_yellow, HIGH);
  for (pos = 180; pos >= 0; pos-=1) {
    myservo.write(pos);            
    delay(3);                   
  }
  for (pos = 0; pos <= 180; pos+=1) { 
    myservo.write(pos);             
    delay(3);        
  }
  delay(1000);
}

if(sensorValue<460){
  lcd.setCursor(0,0);
  lcd.print("IT IS RAINING   ");
  lcd.setCursor(0,1);
  lcd.print("AMOUNT: HIGH    ");
  digitalWrite(led_red, HIGH);
  digitalWrite(led_green, HIGH);
  digitalWrite(led_yellow, HIGH);
  for (pos = 180; pos >= 0; pos-=1) {
    myservo.write(pos);            
    delay(3);                    
  }
  for (pos = 0; pos <= 180; pos+=1) { 
    myservo.write(pos);             
    delay(3);        
  }
  delay(100);
}

}
