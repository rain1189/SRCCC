#include <SoftwareSerial.h>

SoftwareSerial btSerial(2, 3);

void setup() {
  btSerial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  if (btSerial.available()) {
    char c = btSerial.read();

    switch(c) {
      case 'S':
        stop();
        break;
      case 'F':
        forward();
        break;
      case 'B':
        backward();
        break;
      case 'L': 
        turnleft();
        break;
      case 'R':
        turnright();
        break;
    }
  }
}

void stop() {
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
}

void forward() {
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
}

void backward() {
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
}

void turnleft() {
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
}

void turnright() {
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
}


