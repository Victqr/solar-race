#include <SoftwareSerial.h>
SoftwareSerial bluetoothSerial(0, 1); // RX, TX pinnen voor de Bluetooth-module

int relayPin1 = 2;
int relayPin2 = 3;
int relayPin3 = 4;
int relayPin4 = 5;
 
int motor = 1;
int batterij = 2;
int sensor4 = 4;

int lichtwaarde = 0; // variable to store the value coming from the sensor


void setup() {
  Serial.begin(19200);
  bluetoothSerial.begin(9600); // Start de Bluetooth-verbinding
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  pinMode(relayPin3, OUTPUT);
  pinMode(relayPin4, OUTPUT);
}

void loop() {
    sensoren();

  if (bluetoothSerial.available()) {
    char bluetooth_send = bluetoothSerial.read(); // Lees het ontvangen commando
        Serial.println(bluetooth_send);

    if (bluetooth_send == '1') {
      digitalWrite(relayPin1, HIGH);
      digitalWrite(relayPin2, HIGH);
      digitalWrite(relayPin3, HIGH);
      digitalWrite(relayPin4, HIGH);
    }
    if (bluetooth_send == '0') {
      digitalWrite(relayPin1, LOW);
      digitalWrite(relayPin2, LOW);
      digitalWrite(relayPin3, LOW);
      digitalWrite(relayPin4, LOW);

    }
  }
}

// void sensoren()
// {
//       motortemper = analogRead(motor);  
//       UTempmotor = motortemper/204.8;      
//       temperatuurmotor =  16+((UTempmotor - 1.52) / 0.0150); 
//       Serial.println("temperatuurmotor [C]: "); 
//       Serial.println(temperatuurmotor);   
//       baterijtemper = analogRead(motor);  
//       UTempbatterij = baterijtemper/204.8;     
//       temperatuurbaterij=  16+((UTempbatterij - 1.52) / 0.0150); 
//       Serial.println("temperatuurbaterij [C]: "); 
//       Serial.println(temperatuurbaterij);   
//       sensor3temper = analogRead(motor);  
//       UTempsensor3 = sensor3temper/204.8;     
//       temperatuursensor3 =  16+((UTempsensor3 - 1.52) / 0.0150);  
//       Serial.println("temperatuursensor3 [C]: "); 
//       Serial.println(temperatuursensor3);   
//       sensor4temper = analogRead(motor);  
//       UTempsensor4 = sensor4temper/204.8;      
//       temperatuursensor4 =  16+((UTempsensor4 - 1.52) / 0.0150);  
//       Serial.println("temperatuursensor4 [C]: "); 
//       Serial.println(temperatuursensor4);   
// }

void sensoren()
{
  int motorreading = analogRead(motor);
  float motorvoltage = motorreading * (5.0  / 1024.0);
  float motortemperature = (motorvoltage - 5.0 ) / 100;
    Serial.println("temperatuurmotor [C]: "); 
      Serial.println(motortemperature); 
  
  int batterijreading = analogRead(batterij);
  float batterijvoltage = batterijreading * (5.0  / 1024.0);
  float batterijtemperature = (batterijvoltage - 5.0 ) / 100;
    Serial.println("temperatuurmotor [C]: "); 
      Serial.println(batterijtemperature);

  lichtwaarde = analogRead(sensor4); // read the value from the sensor
      Serial.println("lichtwaarde LUX: "); 
      Serial.println(lichtwaarde); 
}