bool temp(){
bool check = false;
int t = analogRead(A0);
if ( t >= 104) {
check = true;
}
else {
check = false;
}
return check;
}

void setup(){
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  int a = analogRead(A0);
  if (temp () == true){
    Serial.println(" all ok");
    delay(500);
    
  }
  else{
    Serial.println("not ok");
    delay(500);
    digitalWrite(13, HIGH);
  }
  if (a>153){
    Serial.print(analogRead(A0));
    delay(500);
  }
}
//добавил not ok от себя.