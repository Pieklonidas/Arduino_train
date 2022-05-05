#include <HCSR04.h> // biblioteka do obsługi sensora


#define ECHO 9 
#define TRIG 8


HCSR04 hc(TRIG,ECHO); // obiekt do obsługi sensora


void setup() {
  Serial.begin(9600);
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);

}

void printing_dist()
{
  Serial.println( hc.dist() );
}

void loop() 
{
   //printing_dist(); // metoda dist() zwraca dystans między sensorem a jakimś obiektem, w centymetrach
   
}
