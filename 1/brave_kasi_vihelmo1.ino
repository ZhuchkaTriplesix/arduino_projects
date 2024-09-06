#include <Servo.h> 
Servo servo;
float k=0;
int x;
int a;
int  func () 
{
  int result = 0 ;
  for (int i = 0; i < 8; i++){
    x = analogRead(A0);
    result = result + x; 
  }
  result = result/8;
  return result;
}

void setup()
{
  Serial.begin(57600);
  pinMode (A0, INPUT);
  servo.attach(13);
  servo.write(0);
}
void loop(){
  a = func();
if (a>50)
{
	servo.write(180);
}
}
