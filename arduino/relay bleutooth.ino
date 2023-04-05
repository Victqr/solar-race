#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(0, 1); // RX, TX pinnen voor de Bluetooth-module

int relayPin1 = 1;
int relayPin2 = 2;
int relayPin3 = 3;


void setup() {
  Serial.begin(9600);
  bluetoothSerial.begin(9600); // Start de Bluetooth-verbinding
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  pinMode(relayPin3, OUTPUT);

}

void loop() {
  if (bluetoothSerial.available()) {
    char bluetooth_send = bluetoothSerial.read(); // Lees het ontvangen commando
        Serial.println(bluetooth_send);

    if (bluetooth_send == '1') {
      digitalWrite(relayPin1, HIGH);
      digitalWrite(relayPin2, HIGH);
      digitalWrite(relayPin3, HIGH);
    }
    if (bluetooth_send == '0') {
      digitalWrite(relayPin1, LOW);
      digitalWrite(relayPin2, LOW);
      digitalWrite(relayPin3, LOW);
    }
  }
}
