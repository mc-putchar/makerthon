//Program for Photodiode Light detection with Arduino
//Source: https://www.ee-diary.com
#include <Servo.h>

//alias pin name for Photodiode
int sensor1 = A0;
int sensor2 = A1;
int greenLedPin = 5;
int i;

Servo s1;

void setup(){
  Serial.begin(9600); //set Serial output baud rate
  //For output format
  Serial.println("\nVoltage(V):");
  Serial.print("--------------------------------------------------\n");
  i = 0;
  s1.attach(3);
  s1.write(90);
}

void loop() {
    int anaValue = analogRead(sensor1); // potentiometer voltage
    int ana2Value = analogRead(sensor2);

    float voltage = 5-(anaValue/1024.0)*5;
    float secondVoltage = 5-(ana2Value/1024.0)*5;
    s1.write(90 - (anaValue - ana2Value) * 3);
    analogWrite(greenLedPin, i++ % 6);
    Serial.println(String(voltage,2)+"V  | AnaVal:"+String(anaValue, 10));
    Serial.println(String(secondVoltage,2)+"V  | Ana2Val:"+String(ana2Value, 10));
    delay(100); //delay 2000ms to prevent any duplicates
}