// UIPEthernet for ENC28J60: https://github.com/ntruchsess/arduino_uip
#include <UIPEthernet.h>
#include <ThingerENC28J60.h>

ThingerENC28J60 thing("pgcaparoso", "SENSORS", "gumanakanaplease");

// defines pins numbers
int trigPin[5] = {A5, A3, 2, 4, 6};
int echoPin[5] = {A4, A2, 3, 5, 7};

// defines variables
long duration;
int distance;

void setup() {
  uint8_t mac[6] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05};
  Ethernet.begin(mac, IPAddress(192, 168, 15, 125));
  for (int i = 0; i < 5; i++) {
    pinMode(trigPin[i], OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin[i], INPUT); // Sets the echoPin as an Input
  }

  thing["sensor1"] >> [] (pson & out) {
    // Clears the trigPin
    digitalWrite(trigPin[0], LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 50 micro seconds
    digitalWrite(trigPin[0], HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin[0], LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin[0], HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
    // Prints the distance on the Serial Monitor
    out = distance;
    delay(100);
  };
  thing["sensor2"] >> [] (pson & out) {
    // Clears the trigPin
    digitalWrite(trigPin[1], LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 50 micro seconds
    digitalWrite(trigPin[1], HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin[1], LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin[1], HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
    // Prints the distance on the Serial Monitor
    out = distance;
    delay(100);
  };
  thing["sensor3"] >> [] (pson & out) {
    // Clears the trigPin
    digitalWrite(trigPin[2], LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 50 micro seconds
    digitalWrite(trigPin[2], HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin[2], LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin[2], HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
    // Prints the distance on the Serial Monitor
    out = distance;
    delay(100);
  };
  thing["sensor4"] >> [] (pson & out) {
    // Clears the trigPin
    digitalWrite(trigPin[3], LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 50 micro seconds
    digitalWrite(trigPin[3], HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin[3], LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin[3], HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
    // Prints the distance on the Serial Monitor
    out = distance;
    delay(100);
  };
  thing["sensor5"] >> [] (pson & out) {
    // Clears the trigPin
    digitalWrite(trigPin[4], LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 50 micro seconds
    digitalWrite(trigPin[4], HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin[4], LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin[4], HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
    // Prints the distance on the Serial Monitor
    out = distance;
    delay(100);
  };
}

void loop() {
  thing.handle();
}
