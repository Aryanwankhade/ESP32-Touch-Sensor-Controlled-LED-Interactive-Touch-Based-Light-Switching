void setup() {
  // put your setup code here, to run once:
  pinMode(23,OUTPUT);
pinMode(4,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print("Value\n ");
int touchdata=touchRead(4);
Serial.print(touchRead(4));
if(touchdata>50)
  {
  digitalWrite(23,0);
  }
  if(touchdata<20)
  {
  digitalWrite(23,1);
  }
delay(100);
}
