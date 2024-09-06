void setup(){
Serial.begin(9600);
pinMode(A0, INPUT);
}

void loop (){
int a = analogRead(A0);
int n = 5;
int b = a;
int c;
c = func1(a, n);
Serial.println(c);
  do{
	Serial.println(n);
	delay(500);
	b= b-1;
	}while (b>0);
}

int func1 (int a, int n){
int result;
result = n + a;
return result;
}
//сначала выводит функцию, а потом столько раз значение n
//сколько значение датчика