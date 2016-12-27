#include <SoftwareSerial.h>
#include <Wire.h>
SoftwareSerial mySerial(3, 2); // RX, TX

int skinPin   = 1;
int skinValue;
int pulseValue;
unsigned char c;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  skinValue = analogRead(A1);
  Wire.requestFrom(0xA0 >> 1, 1);  
  while(Wire.available()) {        
    c = Wire.read();   
  }

  Serial.print(c);
  Serial.print(";");
  Serial.println(skinValue);
  mySerial.print(c);
  mySerial.print(";");
  mySerial.println(skinValue);
  
  delay(500);

}



