#include <LiquidCrystal.h>

String data; 
// initialize the library with the numbers of the interface pins
int len = 0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup(){
    Serial.begin(9600); //Sets the baud for serial data transmission                               
    pinMode(13, OUTPUT); //Sets digital pin 13 as output pin
    lcd.begin(16, 2);
    lcd.print("hello, world!");
}
void loop(){
   if(Serial.available() > 0){
       data = Serial.readString();
       if(data[0] == 'D'){
          if(data[2] == '1')
            digitalWrite(13, HIGH);   //If value is 1 then LED turns ON
          else
            digitalWrite(13, LOW);    //If value is 0 then LED turns OFF
       } else {
          data.remove(0,2);
          len = data.length();
          if(len < 17){
            lcd.setCursor(0, 0);
            lcd.print(data);
            Serial.println(data);
          } else {
            lcd.setCursor(0, 0);
            lcd.print(data.substring(0, 16));
            lcd.setCursor(0, 1);
            data.remove(0,16);
            lcd.print(data);
          }
       }
   }
}


