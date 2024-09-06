bool buttoncheck(){
  bool check = false;
  int buttonstate = digitalRead(2);
  if ( buttonstate == HIGH) {
    check = true;
  }
  else {
    check = false;
  }
  return check;
}
   

void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  if (buttoncheck()== true){
    digitalWrite (13, HIGH);
  }
  else {
    digitalWrite (13, LOW);
  }
}


//bool check = false;
//bool buttoncheck(){
  //int buttonstate = digitalRead(2);
  //if ( buttonstate == HIGH) {
    //check = true;
  //}
  //else {
    //check = false;
  //}
  //return check;
//}
    