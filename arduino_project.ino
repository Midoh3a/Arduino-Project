#include <Servo.h>
#define trigPin 13
#define echoPin 12
int LDR = A0 ;
int led = 2 ;

Servo myservo;  //  servo object to control a servo
int pos = 0;    // variable to store the servo position

void setup() {

  myservo.attach(9);
  pinMode(LDR, INPUT);
  pinMode(led, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
 
 digitalWrite(led, LOW);
  int sensorValue = analogRead(LDR);
  
  if( sensorValue <75 )  
  {
    
   long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
  if (distance < 30) {
  
  digitalWrite(led,HIGH);
  
  
       Serial.print("LDR Sensor Readings:");
       Serial.println(sensorValue);
       Serial.println("Led ON");
       delay(1500);
  }

  else
  {
       digitalWrite(led, LOW);
       Serial.print("LDR Sensor Readings:");
       Serial.println(sensorValue);
       Serial.println("Led OFF");
              delay(1500);

  }       
  }
  
    if(sensorValue <= 300 && pos == 0)
  {
    for (pos = 0; pos < 90; pos += 1) 
       { 
        myservo.write(pos); 
        delay(15); 
    }
    
    Serial.println(pos);
    
  }
  
  if(sensorValue > 300 && pos == 90)
  {
    for (pos = 90; pos > 0; pos -= 1) 
      { 
        myservo.write(pos);              
        delay(15);
    }
    
    Serial.println(pos);
    
  }
  
  }
