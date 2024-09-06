const int btn1Pin=13;
const int btn2Pin=12;
const int led1Pin=11;
const int led2Pin=10;
int valBtn1=0;
int valBtn2=0;
void setup() {
pinMode(btn1Pin,INPUT);
pinMode(btn2Pin,INPUT);
pinMode(led1Pin,OUTPUT);
pinMode(led2Pin,OUTPUT);
while ((valBtn1==0)&&(valBtn2==0)){
valBtn1=digitalRead(btn1Pin);
valBtn2=digitalRead(btn2Pin);
}
}

void loop() {
if ((valBtn1==1)&&(valBtn2==0)){
digitalWrite(led1Pin,HIGH);
}
else if ((valBtn2==1)&&(valBtn1==0)){
digitalWrite(led2Pin,HIGH);
}
}