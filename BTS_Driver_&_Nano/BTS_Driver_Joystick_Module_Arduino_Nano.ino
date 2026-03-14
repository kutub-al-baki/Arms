int VRx = A0;
int VRy = A1;

int RPWM = 5;
int LPWM = 6;

int xValue = 0;
int yValue = 0;

void setup() 
{
  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);
}

void loop() 
{
  xValue = analogRead(VRx);
  yValue = analogRead(VRy);

  int speed = map(abs(yValue - 512), 0, 512, 0, 255);

  if (yValue > 600)   // Forward
  {
    analogWrite(RPWM, speed);
    analogWrite(LPWM, 0);
  }

  else if (yValue < 400)   // Reverse
  {
    analogWrite(RPWM, 0);
    analogWrite(LPWM, speed);
  }

  else   // Stop
  {
    analogWrite(RPWM, 0);
    analogWrite(LPWM, 0);
  }

  delay(10);
}
