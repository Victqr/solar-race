char Incoming_value = 0;

const int relay1_pin = 1;
const int relay2_pin = 2;
const int relay3_pin = 3;

void setup() 
{
  Serial.begin(9600);         
  pinMode(relay1_pin, OUTPUT);
  pinMode(relay2_pin, OUTPUT);
  pinMode(relay3_pin, OUTPUT);
}

void loop()
{
  if(Serial.available() > 0)  
  {
    Incoming_value = Serial.read();      
    Serial.print(Incoming_value);        
    Serial.print("\n");        
    if(Incoming_value == '1')             
      digitalWrite(relay1_pin, HIGH);  
      digitalWrite(relay2_pin, HIGH);  
      digitalWrite(relay3_pin, HIGH);  

    if(Incoming_value == '0')       
      digitalWrite(relay1_pin, LOW);  
      digitalWrite(relay2_pin, LOW);  
      digitalWrite(relay3_pin, LOW);  
  }                            
} 
