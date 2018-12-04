#define trigPin1 13
#define echoPin1 12
#define trigPin2 11
#define echoPin2 10
#define trigPin3 9
#define echoPin3 8
const int RELAY = 7;
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2,3);

void setup() 
{
  mySerial.begin(9600); 
  Serial.begin (9600);
  delay(100);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(RELAY, OUTPUT);
}
void loop() 
{
  
  
  //digitalWrite(RELAY, HIGH);
  long duration, distance,inches,durationa,durationb,durationc,durationd;
  digitalWrite(trigPin1, LOW);        
  delayMicroseconds(2);              
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);           
  digitalWrite(trigPin1, LOW);
  durationa = pulseIn(echoPin1, HIGH);
  delay(10);

  digitalWrite(trigPin1, LOW);        
  delayMicroseconds(2);              
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);           
  digitalWrite(trigPin1, LOW);
  durationb = pulseIn(echoPin1, HIGH);
  delay(10);

  digitalWrite(trigPin1, LOW);        
  delayMicroseconds(2);              
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);           
  digitalWrite(trigPin1, LOW);
  durationc = pulseIn(echoPin1, HIGH);
  delay(10);

  digitalWrite(trigPin1, LOW);        
  delayMicroseconds(2);              
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);           
  digitalWrite(trigPin1, LOW);
  durationd = pulseIn(echoPin1, HIGH);
  delay(10);

  duration=(durationa+durationb+durationc+durationd) / 4 ;
  
  distance = (duration/2) / 29.1;
  inches = microsecondsToInches(duration);

  //Serial.println(durationa);
  //Serial.println(durationb);
  //Serial.println(durationc);
  //Serial.println(durationd);
  
  if (distance >=1  && distance <= 50)
  {
    digitalWrite(RELAY, LOW);
    Serial.print("obstacle found at ");
    Serial.print(distance);
    Serial.print(" cm, ");
    Serial.print(inches);
    Serial.println(" inches");
   

     mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+919488790369\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("obstacle is at location-GPS");// The SMS text you want to send
  delay(1000);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
    
  }
  else
  {
    Serial.println(distance);
    //digitalWrite(RELAY, HIGH);
  
 
  //delay(50);

  long duration1, distance1;
  digitalWrite(trigPin2, LOW);        
  delayMicroseconds(2);              
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);           
  digitalWrite(trigPin2, LOW);
  duration1 = pulseIn(echoPin2, HIGH);
  distance1 = (duration1/2) / 29.1;
  if (distance1 > 5 && distance1 <= 10)
  {
  digitalWrite(RELAY, LOW);
   mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+919488790369\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("crack is at location-GPS");// The SMS text you want to send
  delay(1000);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(7000);
  digitalWrite(RELAY, HIGH);
  
    Serial.print("crack is at this location-GPS ");
    Serial.print(distance1);
    Serial.println(" cm");
  }
  else 
  {
    Serial.print("track intact ");
    Serial.println(distance1); 
  
  delay(50);
  
  long duration2, distance2;
  digitalWrite(trigPin3, LOW);        
  delayMicroseconds(2);              
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);           
  digitalWrite(trigPin3, LOW);
  duration2 = pulseIn(echoPin3, HIGH);
  distance2 = (duration2/2) / 29.1;
  if (distance2 > 4 && distance2 <= 10)
  {
    digitalWrite(RELAY, LOW);         //normally close will be open
    mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+919488790369\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("mudhole is at location-GPS");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(7000);
  digitalWrite(RELAY,HIGH);
    Serial.print("possibility of hAving a mudhole at -GPS ");
    Serial.print(distance2);
    Serial.println(" cm");
  }
  else 
  {
    Serial.print("ballast is proper ");  
    Serial.println(distance2);
    digitalWrite(RELAY, HIGH);
  }
  }}
  Serial.println();
  delay(50);
  }

 long microsecondsToInches(long microseconds) //sub-function should be declared outside the main function or loop
  {
   return microseconds / 74 / 2;
  }
