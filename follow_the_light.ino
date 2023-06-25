//Program for Photodiode Light detection with Arduino
//Source: https://www.ee-diary.com
#include <Servo.h>

#define DIFF_MULTI  3
// ### Pins ###
int sensor1 = A0;
int sensor2 = A1;
int sensor3 = A2;
int greenLedPin = 5;
int servoPin = 3;

unsigned int i;
Servo s1;

int  clampInt(int n, int min, int max)
{
  if (n < min)
    return (min);
  if (n > max)
    return (max);
  return (n);
}

void setup(){
  Serial.begin(9600); //set Serial output baud rate
  //For output format
  Serial.println("\nVoltage(V):");
  Serial.print("--------------------------------------------------\n");
  i = 0;
  s1.attach(servoPin);
  s1.write(90); //reset Servo to neutral position
}

void loop() {
    int anaValue = analogRead(sensor1); // potentiometer voltage
    int ana2Value = analogRead(sensor2);
    int ana3Value = analogRead(sensor3);

    float voltage = 5-(anaValue/1024.0)*5;
    float secondVoltage = 5-(ana2Value/1024.0)*5;
    float thirdVoltage = 5-(ana2Value/1024.0)*5;
    s1.write(clampInt(((ana2Value - anaValue) * DIFF_MULTI + 90), 0, 180));
    analogWrite(greenLedPin, i++ % 6);
    Serial.println(String(voltage,2)+"V  | AnaVal:"+String(anaValue, 10)+"   "+String(secondVoltage,2)+"V  | Ana2Val:"+String(ana2Value, 10)+"   "+String(thirdVoltage,2)+"V  | Ana3Val: "+String(ana3Value, 10));
  
    delay(500);
}
