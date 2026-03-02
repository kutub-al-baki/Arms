// ------------------ Stepper 1 ------------------
int s1_1 = 13;
int s1_2 = 12;
int s1_3 = 14;
int s1_4 = 27;

// ------------------ Stepper 2 ------------------
int s2_1 = 26;
int s2_2 = 25;
int s2_3 = 33;
int s2_4 = 32;

// ------------------ N20 Motor 1 ------------------
int m1_in1 = 18;
int m1_in2 = 19;
int m1_en  = 5;

// ------------------ N20 Motor 2 ------------------
int m2_in1 = 21;
int m2_in2 = 22;
int m2_en  = 4;

char cmd;

// Stepper sequence
int stepSequence[4][4] = {
  {1,0,1,0},
  {0,1,1,0},
  {0,1,0,1},
  {1,0,0,1}
};

void setup() {

  Serial.begin(115200);

  pinMode(s1_1, OUTPUT);
  pinMode(s1_2, OUTPUT);
  pinMode(s1_3, OUTPUT);
  pinMode(s1_4, OUTPUT);

  pinMode(s2_1, OUTPUT);
  pinMode(s2_2, OUTPUT);
  pinMode(s2_3, OUTPUT);
  pinMode(s2_4, OUTPUT);

  pinMode(m1_in1, OUTPUT);
  pinMode(m1_in2, OUTPUT);
  pinMode(m1_en, OUTPUT);

  pinMode(m2_in1, OUTPUT);
  pinMode(m2_in2, OUTPUT);
  pinMode(m2_en, OUTPUT);
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

    // N20 Motor 1
    case 'z': dcMotor(m1_in1,m1_in2,m1_en,1); break;
    case 'x': dcMotor(m1_in1,m1_in2,m1_en,-1); break;

    // N20 Motor 2
    case 'd': dcMotor(m2_in1,m2_in2,m2_en,1); break;
    case 'f': dcMotor(m2_in1,m2_in2,m2_en,-1); break;
  }
}

// ------------------ Stepper Function ------------------

void stepperMove(int a,int b,int c,int d,int dir) {

  for(int i=0;i<200;i++) {   // 200 steps
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

// ------------------ DC Motor Function ------------------

void dcMotor(int in1,int in2,int en,int dir) {

  if(dir==1){
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
  }
  else{
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
  }

  analogWrite(en,200);
}