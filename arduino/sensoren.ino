const int Baterijtemp_pin = A0; // analoge ingang voor de NTC-thermistor
const int Motortemp_pin = A1; // analoge ingang voor de NTC-thermistor
const int Omgevevingtemp_pin = A2; // analoge ingang voor de NTC-thermistor
const int Binnentemp_pin = A3; // analoge ingang voor de NTC-thermistor


const float weerstand_batterij = 8000.0; // waarde van de serie-weerstand in ohm
const float weerstand_motor = 5656.0; // waarde van de serie-weerstand in ohm
const float weerstand_omgeving = 5656.0; // waarde van de serie-weerstand in ohm
const float weerstand_binnen = 5656.0; // waarde van de serie-weerstand in ohm

const float ref_waarde_temp = 1880.0; // weerstand van de NTC-thermistor bij referentietemperatuur in ohm
const float ref_temp = 19.0; // referentietemperatuur in graden Celsius

const float A = 0.003354016; // Steinhart-Hart coëfficiënt A
const float B = 0.0002569850; // Steinhart-Hart coëfficiënt B
const float C = 2.620131e-7; // Steinhart-Hart coëfficiënt C

const float voltage_temp = 5.0; // referentie spanning van de Arduino

void setup() {
  Serial.begin(9600); // start de seriële communicatie
}

void loop() {
  float voltage_Batterij, voltage_Motor, voltage_Omgeving, voltage_Binnen, resistance_batterij, resistance_motor, temperature_batterij, temperature_motor;

  // lees de spanning over de NTC-thermistor
  voltage_Batterij = analogRead(Baterijtemp_pin) * voltage_temp / 1023.0;
  voltage_Motor = analogRead(Motortemp_pin) * voltage_temp / 1023.0;
   voltage_Omgeving = analogRead(Omgevevingtemp_pin) * voltage_temp / 1023.0;
  voltage_Binnen = analogRead(Binnentemp_pin) * voltage_temp / 1023.0;

  // bereken de weerstand van de NTC-thermistor
  resistance_batterij = weerstand_batterij * (voltage_temp / voltage_Batterij - 1.0);
  resistance_motor = weerstand_motor * (voltage_temp / voltage_Motor - 1.0);
  resistance_omgeving = weerstand_omgeving * (voltage_temp / voltage_Omgeving - 1.0);
  resistance_binnen = weerstand_binnen * (voltage_temp / voltage_Binnen - 1.0);

  // bereken de temperatuur met behulp van de Steinhart-Hart-vergelijking
  temperature_batterij = 1.0 / (A + B * log( resistance_batterij / ref_waarde_temp ) + C * pow(log( resistance_batterij / ref_waarde_temp ), 3)) - 273.15 + ref_temp;
  temperature_motor = 1.0 / (A + B * log( resistance_motor / ref_waarde_temp ) + C * pow(log(resistance_motor / ref_waarde_temp ), 3)) - 273.15 + ref_temp;
  temperature_omgeving = 1.0 / (A + B * log( resistance_omgeving / ref_waarde_temp ) + C * pow(log( resistance_omgeving / ref_waarde_temp ), 3)) - 273.15 + ref_temp;
  temperature_binnen = 1.0 / (A + B * log( resistance_binnen / ref_waarde_temp ) + C * pow(log(resistance_binnen / ref_waarde_temp ), 3)) - 273.15 + ref_temp;

  // toon de resultaten op de seriële monitor
  Serial.print("Temperatuur batterij: ");
  Serial.print( temperature_batterij);
  Serial.println(" graden Celsius");
  Serial.print("Temperatuur motor: ");
  Serial.print( temperature_motor);
  Serial.println(" graden Celsius");
  Serial.print("Temperatuur omgeving: ");
  Serial.print( temperature_omgeving);
  Serial.println(" graden Celsius");
  Serial.print("Temperatuur binnen: ");
  Serial.print( temperature_binnen);
  Serial.println(" graden Celsius");

  // wacht een korte tijd
  delay(1000);
}
