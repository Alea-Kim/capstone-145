// UIPEthernet for ENC28J60: https://github.com/ntruchsess/arduino_uip
#include <UIPEthernet.h>
#include <ThingerENC28J60.h>

ThingerENC28J60 thing("pgcaparoso", "SENSORS", "gumanakanaplease");

// defines pins numbers
int trigPin[5] = {A5, A3, 2, 4, 6};
int echoPin[5] = {A4, A2, 3, 5, 7};

// defines variables
long duration;
int distance, ch=0;

void setup() {
  uint8_t mac[6] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05};
  Ethernet.begin(mac, IPAddress(192, 168, 15, 125));
  for (int i = 0; i < 5; i++) {
    pinMode(trigPin[i], OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin[i], INPUT); // Sets the echoPin as an Input
  }

  thing["sensors"] >> [] (pson & out) {
    out["sensor1"] = getDist(0);
    out["sensor2"] = getDist(1);
    out["sensor3"] = getDist(2);
    out["sensor4"] = getDist(3);
    out["sensor5"] = getDist(4);
    delay(10);
  };
}

void loop() {
  thing.handle();
}

int getDist(int ch){
  digitalWrite(trigPin[ch], LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 50 micro seconds
  digitalWrite(trigPin[ch], HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin[ch], LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin[ch], HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  return distance;
}
