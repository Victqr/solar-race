#include <SoftwareSerial.h>

//hallo
SoftwareSerial bluetoothSerial(0, 1); // RX, TX pinnen voor de Bluetooth-module

int relayPin1 = 2;
int relayPin2 = 3;
int relayPin3 = 4;

int escpin = 5;

float temperatuurmotor, temperatuurbaterij, temperatuursensor3, temperatuursensor4  ; 
float UTempmotor, UTempbatterij, UTempsensor3, UTempsensor4; 
int motor = 1;  
int motortemper = 0; 
int batterij = 2; 
int baterijtemper = 0; 
int sensor3 = 3;  
int sensor3temper = 0; 
int sensor4 = 4;  
int sensor4temper = 0; 



void setup() {
  Serial.begin(19200);
  bluetoothSerial.begin(9600); // Start de Bluetooth-verbinding
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  pinMode(relayPin3, OUTPUT);

  pinMode(escpin, OUTPUT);
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

      digitalWrite(escpin, HIGH);
    }
    if (bluetooth_send == '0') {
      digitalWrite(relayPin1, LOW);
      digitalWrite(relayPin2, LOW);
      digitalWrite(relayPin3, LOW);

      digitalWrite(escpin, LOW);

    }
  }
}

void sensoren()
{
      motortemper = analogRead(motor);  
      UTempmotor = motortemper/204.8;      
      temperatuurmotor =  16+((UTempmotor - 1.52) / 0.0150); 
      Serial.println("temperatuurmotor [C]: "); 
      Serial.println(temperatuurmotor);   
      baterijtemper = analogRead(motor);  
      UTempbatterij = baterijtemper/204.8;     
      temperatuurbaterij=  16+((UTempbatterij - 1.52) / 0.0150); 
      Serial.println("temperatuurbaterij [C]: "); 
      Serial.println(temperatuurbaterij);   
      sensor3temper = analogRead(motor);  
      UTempsensor3 = sensor3temper/204.8;     
      temperatuursensor3 =  16+((UTempsensor3 - 1.52) / 0.0150);  
      Serial.println("temperatuursensor3 [C]: "); 
      Serial.println(temperatuursensor3);   
      sensor4temper = analogRead(motor);  
      UTempsensor4 = sensor4temper/204.8;      
      temperatuursensor4 =  16+((UTempsensor4 - 1.52) / 0.0150);  
      Serial.println("temperatuursensor4 [C]: "); 
      Serial.println(temperatuursensor4);   
}

