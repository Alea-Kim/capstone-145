//#include <UIPEthernet.h>

// defines data array per sensor
int arr1[60];
int arr2[60];
int arr3[60];
int arr4[60];
int arr5[60];
// defines pins numbers
int trigPin[5] = {A5,A3,2,4,6};
int echoPin[5] = {A4,A2,3,5,7};
// defines variables
int num=0, ch=0, sum=0, ave = 0;
int maxx[5];
long duration;
int distance;

void setup() {
  for(int i = 0; i<5;i++){
    pinMode(trigPin[i], OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin[i], INPUT); // Sets the echoPin as an Input
  }
  Serial.begin(9600); // Starts the serial communication
  //Serial.println(Ethernet.localIP());
  
  for(int i = 0; i<5;i++){
     maxx[i] = getDistance(i);
  }

//  for(int i = 0; i<5;i++){
//     Serial.print(maxx[i]);
//  }

}

int tobin(int distance, int m){
  if(distance >= m) return 0;
  else if(distance<m) return 1;
}

void loop() {
  if (num == 10) {
    for (int i=0; i<10; i++){
      Serial.print(arr1[i]);
      Serial.print(" ");
      Serial.print(arr2[i]);
      Serial.print(" ");
      Serial.print(arr3[i]);
      Serial.print(" ");
      Serial.print(arr4[i]);
      Serial.print(" ");
      Serial.println(arr5[i]);
//      Serial.println("maxx1: ");
//      Serial.print(maxx[0]);
//      Serial.println(" ");

    }
    num = 0;
  }
  // Calculating the distance
  // Prints the distance on the Serial Monitor
  arr1[num] = tobin(getDistance(0), maxx[0]);
  delay(200);
  arr2[num] = tobin(getDistance(1), maxx[1]);
  delay(200);
  arr3[num] = tobin(getDistance(2),  maxx[2]);
  delay(200);
  arr4[num] = tobin(getDistance(3),  maxx[3]);
  delay(200);
  arr5[num] = tobin(getDistance(4),  maxx[4]);
  delay(200);
  num++;
}

long getDistance(int ch){
  // Clears the trigPin
  digitalWrite(trigPin[ch], LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin[ch], HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin[ch], LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin[ch], HIGH);
  distance= duration*0.034/2;
  return distance;
}
