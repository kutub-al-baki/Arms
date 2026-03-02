// ---------------- Stepper 1 ----------------
int s1_1 = 2;
int s1_2 = 3;
int s1_3 = 4;
int s1_4 = 5;

// ---------------- Stepper 2 ----------------
int s2_1 = 6;
int s2_2 = 7;
int s2_3 = 8;
int s2_4 = 9;

// ---------------- DC Motor 1 ----------------
int m1_in1 = 10;
int m1_in2 = 11;
int m1_en  = 12;

// ---------------- DC Motor 2 ----------------
int m2_in1 = A0;
int m2_in2 = A1;
int m2_en  = A2;

char cmd;

// 4-step sequence
int stepSequence[4][4] = {
  {1,0,1,0},
  {0,1,1,0},
  {0,1,0,1},
  {1,0,0,1}
};

void setup() {

  Serial.begin(9600);

  for(int i=2; i<=12; i++){
    pinMode(i, OUTPUT);
  }

  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
}

void loop() {

  if (Serial.available()) {
    cmd = Serial.read();
  }

  switch(cmd) {

    // Stepper 1
    case 'a': stepperMove(s1_1,s1_2,s1_3,s1_4,1); break;
    case 's': stepperMove(s1_1,s1_2,s1_3,s1_4,-1); break;

    // Stepper 2
    case 'q': stepperMove(s2_1,s2_2,s2_3,s2_4,1); break;
    case 'w': stepperMove(s2_1,s2_2,s2_3,s2_4,-1); break;

    // DC Motor 1
    case 'z': dcMotor(m1_in1,m1_in2,m1_en,1); break;
    case 'x': dcMotor(m1_in1,m1_in2,m1_en,-1); break;

    // DC Motor 2
    case 'd': dcMotor(m2_in1,m2_in2,m2_en,1); break;
    case 'f': dcMotor(m2_in1,m2_in2,m2_en,-1); break;
  }
}

// ---------------- Stepper Function ----------------

void stepperMove(int a,int b,int c,int d,int dir) {

  for(int i=0;i<200;i++) {

    for(int step=0; step<4; step++) {

      int index = (dir==1) ? step : (3-step);

      digitalWrite(a, stepSequence[index][0]);
      digitalWrite(b, stepSequence[index][1]);
      digitalWrite(c, stepSequence[index][2]);
      digitalWrite(d, stepSequence[index][3]);

      delay(5);
    }
  }
}

// ---------------- DC Motor Function ----------------

void dcMotor(int in1,int in2,int en,int dir) {

  if(dir==1){
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
  }
  else{
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
  }

  digitalWrite(en,HIGH);   // Full speed
}