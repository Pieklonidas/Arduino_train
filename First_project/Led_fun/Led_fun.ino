void Light_all()
{
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(9, HIGH);
  delay(1000);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(9, LOW);
  delay(1000);
}

void Light_one_by_one()
{
  digitalWrite(5, HIGH);
  delay(500);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  delay(500);
  digitalWrite(6, LOW);
  digitalWrite(9, HIGH);
  delay(500);
  digitalWrite(9, LOW);
  digitalWrite(6, HIGH);
  delay(500);
  digitalWrite(6, LOW);
}

int current_duty_marker_green = 0;
int current_duty_marker_yellow = 0;
int current_duty_marker_blue = 0;
bool increasing_PWM_green = false;
bool increasing_PWM_yellow = true;
bool increasing_PWM_blue = false;
bool from_g_to_b = true;
bool from_b_to_g = false;

void PWM_for_fun()
{
  /* Increasing and decreasing PWM ----------------------------------------------*/
  if(increasing_PWM_green == true) current_duty_marker_green++;
  else if (increasing_PWM_green == false) current_duty_marker_green--;  

  if(increasing_PWM_yellow == true) current_duty_marker_yellow++;
  else if (increasing_PWM_yellow == false) current_duty_marker_yellow--;

  if(increasing_PWM_blue == true) current_duty_marker_blue++;
  else if (increasing_PWM_blue == false) current_duty_marker_blue--;
  /* Increasing and decreasing PWM ----------------------------------------------*/
  /* Logic ----------------------------------------------------------------------*/
  if(current_duty_marker_green < 127 && from_g_to_b) {increasing_PWM_yellow = true;}
  if(current_duty_marker_yellow >= 127 && from_g_to_b) {increasing_PWM_green = false; increasing_PWM_blue = true;}
  if(current_duty_marker_blue >= 127 && from_g_to_b) {increasing_PWM_yellow = false;}
  if(current_duty_marker_blue == 255 && from_g_to_b) {from_g_to_b = false; from_b_to_g = true; increasing_PWM_blue = false;}
  if(current_duty_marker_blue < 127 && from_b_to_g) {increasing_PWM_yellow = true;}
  if(current_duty_marker_yellow >= 127 && from_b_to_g) {increasing_PWM_green = true; increasing_PWM_blue = false;}
  if(current_duty_marker_green >= 127 && from_b_to_g) {increasing_PWM_yellow = false;}
  if(current_duty_marker_green == 255 && from_b_to_g) {from_g_to_b = true; from_b_to_g = false; increasing_PWM_green = false;}
  /* Logic ----------------------------------------------------------------------*/
  /* Not to overload our PWM -----------------------------------------------------*/
  if(current_duty_marker_green > 254) current_duty_marker_green = 255;
  else if(current_duty_marker_green < 1) current_duty_marker_green = 0;

  if(current_duty_marker_yellow > 254) current_duty_marker_yellow = 255;
  else if(current_duty_marker_yellow < 1) current_duty_marker_yellow = 0;

  if(current_duty_marker_blue > 254) current_duty_marker_blue = 255;
  else if(current_duty_marker_blue < 1) current_duty_marker_blue = 0;
  /* Not to overload our PWM -----------------------------------------------------*/
  
  analogWrite(9, current_duty_marker_green);
  analogWrite(6, current_duty_marker_yellow);
  analogWrite(5, current_duty_marker_blue);
  delay(10);
}

void setup() {
  pinMode(5,OUTPUT);  //Blue LED
  Serial.begin(9600);
  pinMode(6,OUTPUT);  //Yellow LED
  Serial.begin(9600);
  pinMode(9,OUTPUT);  //Green LED
  Serial.begin(9600);
}

void loop() {
  //Light_all(); //Light up all LEDs
  //Light_one_by_one(); //Light up all LEDs in order
  //PWM_for_fun();
}
