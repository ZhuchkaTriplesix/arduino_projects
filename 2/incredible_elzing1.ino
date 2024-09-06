


void setup()
{
  pinMode(13, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  Serial.begin(9600);
  digitalWrite(13, LOW);
}

void loop()
{
  int a = analogRead(A0);
  int b = analogRead(A1);
  int c = analogRead(A2);
  Serial.println(a);
  delay(1000);
  if (a > 155){
  digitalWrite(13, HIGH);
  delay(1000); 
  Serial.print("all ok");
}
}