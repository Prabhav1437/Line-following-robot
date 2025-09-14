const int IR_LEFT_PIN = 13; 
const int IR_MIDDLE_PIN = 32;
const int IR_RIGHT_PIN = 33;
const int AIN1_PIN = 14;
const int AIN2_PIN = 27;
const int BIN1_PIN = 26;
const int BIN2_PIN = 25;

void setup() {
  Serial.begin(115200);

  
  pinMode(IR_LEFT_PIN, INPUT);
  pinMode(IR_MIDDLE_PIN, INPUT);
  pinMode(IR_RIGHT_PIN, INPUT);

  
  pinMode(AIN1_PIN, OUTPUT);
  pinMode(AIN2_PIN, OUTPUT);
  pinMode(BIN1_PIN, OUTPUT);
  pinMode(BIN2_PIN, OUTPUT);
}

void loop() {
  
  int irLeftValue = digitalRead(IR_LEFT_PIN);      // black 1 ,  white 0
  int irMiddleValue = digitalRead(IR_MIDDLE_PIN);  // black 1 ,  white 0
  int irRightValue = digitalRead(IR_RIGHT_PIN);    // black 1 ,  white 0


  
  Serial.print("IR Left: ");
  Serial.print(irLeftValue);
  Serial.print(", IR Middle: ");
  Serial.print(irMiddleValue);
  Serial.print(", IR Right: ");
  Serial.println(irRightValue);

  if (irLeftValue == 0 && irMiddleValue == 1 && irRightValue == 0) {
    forward();

  } else if (irLeftValue == 1 && irMiddleValue == 1 && irRightValue == 1) {
    stop();
  } else if (irLeftValue == 1 && irMiddleValue == 0 && irRightValue == 0) {
    left();
  } else if (irLeftValue == 0 && irMiddleValue == 0 && irRightValue == 1) {
    right();
  } else {
    Serial.print("I am in main loop");
  }
  
  delay(50);
}
void forward() {

  digitalWrite(AIN1_PIN, HIGH);  //if we do it low it will rotate in opt direction
  digitalWrite(AIN2_PIN, LOW);
  digitalWrite(BIN1_PIN, HIGH);
  digitalWrite(BIN2_PIN, LOW);
  Serial.print("I am in forward");
}
void backward() {
  digitalWrite(AIN1_PIN, LOW);
  digitalWrite(AIN2_PIN, HIGH);
  digitalWrite(BIN1_PIN, LOW);
  digitalWrite(BIN2_PIN, HIGH);
  Serial.print("I am in backward");
}

void left() {
  digitalWrite(AIN1_PIN, LOW); 
  digitalWrite(AIN2_PIN, LOW);
  digitalWrite(BIN1_PIN, HIGH);
  digitalWrite(BIN2_PIN, LOW);
  Serial.print("I am in left");
}

void right() {
  digitalWrite(AIN1_PIN, HIGH);
  digitalWrite(AIN2_PIN, LOW);
  digitalWrite(BIN1_PIN, LOW);
  digitalWrite(BIN2_PIN, LOW);
  Serial.print("I am in right");
}
void stop() {
  digitalWrite(AIN1_PIN, LOW);
  digitalWrite(AIN2_PIN, LOW);
  digitalWrite(BIN1_PIN, LOW);
  digitalWrite(BIN2_PIN, LOW);
  Serial.print("I am in stop");
}
