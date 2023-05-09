#include <SoftwareSerial.h>
SoftwareSerial bluetoothSerial(0, 1); // RX, TX pinnen voor de Bluetooth-module

int motor = 1;
int batterij = 2;
int sensor3 = 3;
int sensor4 = 4;


void setup() {
  Serial.begin(19200);
  bluetoothSerial.begin(9600); // Start de Bluetooth-verbinding
}

void loop()
{
  int motorreading = analogRead(motor);
  float motorvoltage = motorreading * (5000 / 1024.0);
  float motortemperature = (motorvoltage - 500) / 10;
    Serial.println("temperatuurmotor [C]: "); 
      Serial.println(motortemperature); 
  
  int batterijreading = analogRead(batterij);
  float batterijvoltage = batterijreading * (5000 / 1024.0);
  float batterijtemperature = (batterijvoltage - 500) / 10;
    Serial.println("temperatuurmotor [C]: "); 
      Serial.println(batterijtemperature);

  int sensor3reading = analogRead(sensor3);
  float sensor3voltage = sensor3reading * (5000 / 1024.0);
  float sensor3temperature = (sensor3voltage - 500) / 10;
    Serial.println("temperatuursensor3 [C]: "); 
      Serial.println(sensor3temperature); 

  int sensor4reading = analogRead(sensor4);
  float sensor4voltage = sensor4reading * (5000 / 1024.0);
  float sensor4temperature = (sensor4voltage - 500) / 10;
    Serial.println("temperatuursensor3 [C]: "); 
      Serial.println(sensor4temperature); 

}
