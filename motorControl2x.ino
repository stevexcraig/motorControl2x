const int switchPin1 = 17;
const int switchPin2 = 18;
const int motor1Pin = 3;
const int motor2Pin = 4;
const int enablePinA = 2;
int potPinA = 26;
int motorSpeedA = 0;

const int switchPin3 = 19;
const int switchPin4 = 20;
const int motor3Pin = 6;
const int motor4Pin = 7;
const int enablePinB = 5;
int potPinB = 27;
int motorSpeedB = 0;

void setup() {
  // set the switch as an input:
  pinMode(switchPin1, INPUT_PULLUP);
  pinMode(switchPin2, INPUT_PULLUP);
  pinMode(switchPin3, INPUT_PULLUP);
  pinMode(switchPin4, INPUT_PULLUP);

  // set all the other pins you're using as outputs:
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  pinMode(enablePinA, OUTPUT);

  pinMode(motor3Pin, OUTPUT);
  pinMode(motor4Pin, OUTPUT);
  pinMode(enablePinB, OUTPUT);

  // set enablePin high so that motor can turn on:
  digitalWrite(enablePinA, HIGH);
  digitalWrite(enablePinB, HIGH);
}

void loop() {

    // if the switch is high, motor will turn on one direction:
    if (digitalRead(switchPin1) == LOW) {
      digitalWrite(motor1Pin, LOW);   // set leg 1 of the H-bridge low
      digitalWrite(motor2Pin, HIGH);  // set leg 2 of the H-bridge high
      motorSpeedA = analogRead(potPinA) / 4;
      analogWrite(enablePinA, motorSpeedA);
    }
    // if the switch is high, motor will turn on one direction:
    else if (digitalRead(switchPin2) == LOW) {
      digitalWrite(motor1Pin, HIGH);   // set leg 1 of the H-bridge low
      digitalWrite(motor2Pin, LOW);  // set leg 2 of the H-bridge high
      motorSpeedA = analogRead(potPinA) / 4;
      analogWrite(enablePinA, motorSpeedA);
    }
    // if the switch is low, motor will turn in the other direction:
    else if ((digitalRead(switchPin1) == HIGH) && (digitalRead(switchPin2) == HIGH)) {
      digitalWrite(motor1Pin, LOW);  // set leg 1 of the H-bridge high
      digitalWrite(motor2Pin, LOW);   // set leg 2 of the H-bridge low
  
    }

  // if the switch is high, motor will turn on one direction:
  if (digitalRead(switchPin3) == LOW) {
    digitalWrite(motor3Pin, LOW);   // set leg 1 of the H-bridge low
    digitalWrite(motor4Pin, HIGH);  // set leg 2 of the H-bridge high
    motorSpeedB = analogRead(potPinB) / 4;
    analogWrite(enablePinB, motorSpeedB);
  }
  // if the switch is high, motor will turn on one direction:
  else if (digitalRead(switchPin4) == LOW) {
    digitalWrite(motor3Pin, HIGH);   // set leg 1 of the H-bridge low
    digitalWrite(motor4Pin, LOW);  // set leg 2 of the H-bridge high
    motorSpeedB = analogRead(potPinB) / 4;
    analogWrite(enablePinB, motorSpeedB);
  }
  // if the switch is low, motor will turn in the other direction:
  else if ((digitalRead(switchPin3) == HIGH) && (digitalRead(switchPin4) == HIGH)) {
    digitalWrite(motor3Pin, LOW);  // set leg 1 of the H-bridge high
    digitalWrite(motor4Pin, LOW);   // set leg 2 of the H-bridge low

  }
}
