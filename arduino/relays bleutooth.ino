const int relay1_pin = 1;
const int relay2_pin = 2;
const int relay3_pin = 3;

bool relay1Status = false;
bool relay2Status = false;
bool relay3Status = false;

void setup() {
  pinMode(relay1_pin, OUTPUT);
  pinMode(relay2_pin, OUTPUT);
  pinMode(relay3_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    switch (command) {
      case '1':
        digitalWrite(relay1_pin, !relay1Status);
        relay1Status = !relay1Status;
        break;
      case '2':
        digitalWrite(relay2_pin, !relay2Status);
        relay2Status = !relay2Status;
        break;
      case '3':
        digitalWrite(relay3_pin, !relay3Status);
        relay3Status = !relay3Status;
        break;
    }
  }
}

