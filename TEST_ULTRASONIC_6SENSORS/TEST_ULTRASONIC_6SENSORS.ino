/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* Crated by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/
// defines pins numbers
int trigPin = 1;
int echoPin = 2;
// defines variables
long duration;
int distance;
void setup() {
for(int i = 0; i<5;i++){
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  trigPin+=2;
  echoPin+=2;
}
Serial.begin(9600); // Starts the serial communication
Serial.print("TEST");
}
void loop() {
if (trigPin == 11) trigPin = 1;
if (echoPin == 12) echoPin = 2;
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Sensor: ");
Serial.println(echoPin/2);
Serial.print("Distance: ");
Serial.println(distance);
delay(500);
trigPin+=2;
echoPin+=2;
}
