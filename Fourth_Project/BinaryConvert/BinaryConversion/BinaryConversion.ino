void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
}

String received = "";
int wartosc = 0;

void loop() {
  if(Serial.available() > 0)
  {
    received = Serial.readStringUntil('\n');
    wartosc = received.toInt();
    Serial.println(wartosc);
    for(int i = 2; i <=9; i++)
    {
      if(wartosc%2)
      {
        digitalWrite(i, HIGH);
      }
      else
      {
        digitalWrite(i, LOW);
      }
      wartosc = wartosc/2;
    }
  }
}
