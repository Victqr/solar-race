const int relay1_pin = 1;
const int relay2_pin = 2;
const int relay3_pin = 3;

void setup() {
  pinMode(relay1_pin, OUTPUT);
  pinMode(relay2_pin, OUTPUT);
  pinMode(relay3_pin, OUTPUT);
}

void loop() {
  digitalWrite(relay1_pin, HIGH);
  delay(5000);
  digitalWrite(relay1_pin, LOW);

  digitalWrite(relay2_pin, HIGH);
  delay(5000);
  digitalWrite(relay2_pin, LOW);

  digitalWrite(relay3_pin, HIGH);
  delay(5000);
  digitalWrite(relay3_pin, LOW);
}
