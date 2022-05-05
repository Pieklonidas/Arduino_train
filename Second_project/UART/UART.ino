void setup() {
  Serial.begin(9600); 
  pinMode(5, OUTPUT); // BLUE
  pinMode(6, OUTPUT); // GREEN
  digitalWrite(5, LOW); // Because I used transistor pnp my LED will glow on LOW pin state 
  digitalWrite(6, LOW);
  Serial.println("Hello World!");
}

bool blue_high = false;
bool green_high = false;
String received = "";

void Changing_LED_state()
{
  if(Serial.available() > 0)
  {
    received = Serial.readStringUntil('\n');
    
    if(received == "g")
    {
      if(green_high)
      {
        green_high = false;
        digitalWrite(6, LOW);
      }
      else
      {
        green_high = true;
        digitalWrite(6, HIGH);
      }
    }
    
    else if(received == "b")
    {
      if(blue_high)
      {
        blue_high = false;
        digitalWrite(5, LOW);
      }
      else
      {
        blue_high = true;
        digitalWrite(5, HIGH);
      }
    }

    else
    {
      Serial.println("You have chosen a wrong action!\n");
    }

    Serial.println("Please choose your next action and press enter!\n");
    
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  //Changing_LED_state();
}
