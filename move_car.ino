const int A_1B = 5;
const int A_1A = 6;
const int B_1B = 9;
const int B_1A = 10;
const int S_X = 4;

void setup() {
  pinMode(A_1B, OUTPUT);
  pinMode(A_1A, OUTPUT);
  pinMode(B_1B, OUTPUT);
  pinMode(B_1A, OUTPUT);
  pinMode (S_X,OUTPUT);
}

void loop() {
makePiep();
  moveForward();
  delay(2000);
  stopMove();
  delay(500);

   makePiep();
  turnLeft();
  delay(500);
  stopMove();
  delay(500);

  makePiep();
   makePiep();
}
  

void moveForward() {
  digitalWrite(A_1B, LOW);
  digitalWrite(A_1A, HIGH);
  digitalWrite(B_1B, HIGH);
  digitalWrite(B_1A, LOW);
}

void makePiep(){
digitalWrite(S_X, HIGH);
  delay(500);
  digitalWrite(S_X, LOW);
 
}


void moveBackward() {
  digitalWrite(A_1B, HIGH);
  digitalWrite(A_1A, LOW);
  digitalWrite(B_1B, LOW);
  digitalWrite(B_1A, HIGH);
}

void turnRight() {
  digitalWrite(A_1B, HIGH);
  digitalWrite(A_1A, LOW);
  digitalWrite(B_1B, HIGH);
  digitalWrite(B_1A, LOW);
}

void turnLeft() {
  digitalWrite(A_1B, LOW);
  digitalWrite(A_1A, HIGH);
  digitalWrite(B_1B, LOW);
  digitalWrite(B_1A, HIGH);
}

void stopMove() {
  digitalWrite(A_1B, LOW);
  digitalWrite(A_1A, LOW);
  digitalWrite(B_1B, LOW);
  digitalWrite(B_1A, LOW);
}