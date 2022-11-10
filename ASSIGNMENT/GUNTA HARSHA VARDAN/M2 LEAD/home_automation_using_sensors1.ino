int trigger_pin = 2;
int echo_pin = 3;
int buzzer_pin = 10; 
int time;
int distance; 
void setup() 
{
     Serial.begin  (9600); 
     pinMode (trigger_pin, OUTPUT); 
     pinMode (echo_pin, INPUT);
     pinMode (buzzer_pin, OUTPUT);
     pinMode (10,OUTPUT);
}
void loop() 
{    
    digitalWrite(13,HIGH);
    digitalWrite(13,LOW);
    double a = analogRead(A0);
    double c = (((a/1024)*5)-0.5)*100;
    Serial.print("Celsius value: ");
    Serial.println(c);
    delay(1000);
    digitalWrite (trigger_pin, HIGH);
    delayMicroseconds (10);
    digitalWrite (trigger_pin, LOW);
    time = pulseIn (echo_pin, HIGH);
    distance = (time * 0.034) / 2;

  if (distance <= 10) 
        {
        Serial.println (" Door Open ");
        Serial.print (" Distance= ");              
        Serial.println (distance);        
        digitalWrite (buzzer_pin, HIGH);
        delay (500);
        }
  else {
        Serial.println (" Door closed ");
        Serial.print (" Distance= ");              
        Serial.println (distance);        
        digitalWrite (buzzer_pin, LOW);
        delay (500);        
       } 
}