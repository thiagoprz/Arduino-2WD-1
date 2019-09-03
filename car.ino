#include <SoftwareSerial.h>

int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;

const int pinRX = 2; // DIGITAL 2 (RX)
const int pinTX = 3; // DIGITAL 3 (TX)

int btData = 0; // Var to store data received from BT
SoftwareSerial bluetoothSerial(pinTX, pinRX); // Serial emulator pins


void setup(){
  Serial.begin(9600); // Only for debug if needed
  bluetoothSerial.begin(9600); // Initializing Blueooth serial

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop(){
  if(bluetoothSerial.available()){ // Blueooth is available
    btData = bluetoothSerial.read(); // Data received
    switch(btData) {
      case '1':
        left(IN1, IN2, IN3, IN4);
        break;
      case '0':
        stop(IN1, IN2, IN3, IN4);
        break;
      case '2':
        stop(IN1, IN2, IN3, IN4);
        break;
      case '3':
        right(IN1, IN2, IN3, IN4);
        break;
      case '4':
        stop(IN1, IN2, IN3, IN4);
        break;
      case '5':
        forward(IN1, IN2, IN3, IN4);
        break;
      case '6':
        stop(IN1, IN2, IN3, IN4);
        break;
      case '7':
        backward(IN1, IN2, IN3, IN4);
        break;
    }
  }
}

void stop(int IN1, int IN2, int IN3, int IN4)
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void forward(int IN1, int IN2, int IN3, int IN4)
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward(int IN1, int IN2, int IN3, int IN4)
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left(int IN1, int IN2, int IN3, int IN4)
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void right(int IN1, int IN2, int IN3, int IN4)
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

