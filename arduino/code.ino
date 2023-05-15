#include <SoftwareSerial.h>
SoftwareSerial bluetoothSerial(0, 1); // RX, TX pinnen voor de Bluetooth-module

int relayPin1 = 2;
int relayPin2 = 3;
int relayPin3 = 4;

int escpin = 5;
 
int motor = 1;
int batterij = 2;
int sensor3 = 3;
int sensor4 = 4;


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
  float motorvoltage = motorreading * (5000 / 1024.0);
  float motortemperature = (motorvoltage - 500) / 100;
    Serial.println("temperatuurmotor [C]: "); 
      Serial.println(motortemperature); 
  
  int batterijreading = analogRead(batterij);
  float batterijvoltage = batterijreading * (5000 / 1024.0);
  float batterijtemperature = (batterijvoltage - 500) / 100;
    Serial.println("temperatuurmotor [C]: "); 
      Serial.println(batterijtemperature);

  int sensor3reading = analogRead(sensor3);
  float sensor3voltage = sensor3reading * (5000 / 1024.0);
  float sensor3temperature = (sensor3voltage - 500) / 100;
    Serial.println("temperatuursensor3 [C]: "); 
      Serial.println(sensor3temperature); 
      
  int lichtwaarde=analogRead(sensor4);//Reads the Value of LDR(light).
    Serial.println("lichtwaarde LUX:");//Prints the value of LDR to Serial Monitor.
    Serial.println(lichtwaarde);
}
