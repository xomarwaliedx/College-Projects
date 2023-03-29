#include <LiquidCrystal_I2C.h>
#include <Wire.h>

//inputs
int ldr=A0;
bool pirPin=2;
bool flameSensorHall=5;
bool flameSensorGarage=6;
bool flameSensorRoom=7;
bool flameSensorKitchen=8;
bool flameSensorBathroom=9;
bool closed=10;
bool opened=11;

//outputs
bool HallLight=3;
bool buzzer=4;
bool motorOpen=12;
bool motorClose=13;
bool gardenLight=14;
LiquidCrystal_I2C lcd(0x27, 20, 4);

//variables to be used throughout the code
bool pirValue=0;
bool inHome=1;
bool flameSensorHallReading=0;
bool flameSensorGarageReading=0;
bool flameSensorRoomReading=0;
bool flameSensorKitchenReading=0;
bool flameSensorBathroomReading=0;
bool dayTime=0;
bool curtainOpen=0;
bool curtainClose=0;
int lightFactor=0;
int lightReading=0;

void setup() {
lcd.init();                     
Serial.begin(9600);
lcd.backlight();
pinMode(HallLight,OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(motorOpen,OUTPUT);
pinMode(motorClose,OUTPUT);
pinMode(gardenLight,OUTPUT);

}

void loop() {
  disp();
  PIRSensor();
  lightDetectAndRoutine();

}
void disp(){
  lcd.clear();
  lcd.print("saba7 tata");
  lcd.setCursor(0,1);
  lcd.print("etnen fe talata");
  lcd.setCursor(0,2);
  lcd.print("7aleeb shokalata");
  delay(1000);
}
void PIRSensor(){
  pirValue=digitalRead(pirPin);
  Serial.print(pirValue);
if(pirValue==1)
{
  if (inHome==1)
 {
  digitalWrite(HallLight,HIGH);
  digitalWrite(buzzer,LOW);
 }
 else
 {
  digitalWrite(HallLight,LOW);
  digitalWrite(buzzer,HIGH);
 }
}
else
{
  digitalWrite(HallLight,LOW);
  digitalWrite(buzzer,LOW);
}
}
void lightDetectAndRoutine() {
  lightReading=analogRead(ldr);
 // Serial.print(lightReading);
 // Serial.print("\n");
  curtainOpen=digitalRead(opened);
  curtainClose=digitalRead(closed);
  if (lightReading>700)
  dayTime=1;

  if(dayTime==1)
  {
 //   lcd.backlight();
    if (!curtainOpen)
    {
      digitalWrite(motorOpen,HIGH);
      digitalWrite(motorClose,LOW);
    } else{
      digitalWrite(motorOpen,LOW);
      digitalWrite(motorClose,LOW);
    }
  }
  else
  {
  //  lcd.noBacklight();
    if(!curtainClose)
    {
      digitalWrite(motorOpen,LOW);
      digitalWrite(motorClose,HIGH);
    } else {
      digitalWrite(motorOpen,LOW);
      digitalWrite(motorClose,LOW);
    }
  }
  if(ldr<200)
  analogWrite(gardenLight,255);
  else if(lightReading>800)
  analogWrite(gardenLight,0);
  else
  {
    lightFactor=(800-ldr)*255/600;
    analogWrite(gardenLight,lightFactor);
  }

}
