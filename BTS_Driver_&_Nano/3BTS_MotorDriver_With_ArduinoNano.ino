// Motor 1
int M1_RPWM = 3;
int M1_LPWM = 4;

// Motor 2
int M2_RPWM = 5;
int M2_LPWM = 6;

// Motor 3
int M3_RPWM = 9;
int M3_LPWM = 10;

void setup()
{
  pinMode(M1_RPWM, OUTPUT);
  pinMode(M1_LPWM, OUTPUT);

  pinMode(M2_RPWM, OUTPUT);
  pinMode(M2_LPWM, OUTPUT);

  pinMode(M3_RPWM, OUTPUT);
  pinMode(M3_LPWM, OUTPUT);
}

void loop()
{

// MOTOR 1 FORWARD
analogWrite(M1_RPWM, 200);
analogWrite(M1_LPWM, 0);

// MOTOR 2 FORWARD
analogWrite(M2_RPWM, 200);
analogWrite(M2_LPWM, 0);

// MOTOR 3 FORWARD
analogWrite(M3_RPWM, 200);
analogWrite(M3_LPWM, 0);

delay(3000);

// STOP ALL
analogWrite(M1_RPWM, 0);
analogWrite(M1_LPWM, 0);

analogWrite(M2_RPWM, 0);
analogWrite(M2_LPWM, 0);

analogWrite(M3_RPWM, 0);
analogWrite(M3_LPWM, 0);

delay(2000);

// REVERSE ALL
analogWrite(M1_RPWM, 0);
analogWrite(M1_LPWM, 200);

analogWrite(M2_RPWM, 0);
analogWrite(M2_LPWM, 200);

analogWrite(M3_RPWM, 0);
analogWrite(M3_LPWM, 200);

delay(3000);

}
