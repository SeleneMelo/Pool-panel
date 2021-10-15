// C++ code

#include <Wire.h>
#include <Pump.h>
#include <ButtonEvents.h>

#define SLAVE_ADRESS;

//The pump needs to run at a higher speed if the pool cleaner is runningThe pump needs to run at a higher speed if the heater is onThe pump needs to run at a lower speed when only in a filter/skimmer cycle
bool manu_on = false; //prioridade 1
bool cascata_on = false; //prioridade 2
bool hidro_on = false //prioridade 3
bool luz_on = false; //prioridade 4 -> ?
bool bomba_on = false;  
bool aquece_on = false;  //manual


void

void control_bomba(){
  if ((digitalRead(5) == HIGH && digitalRead(3) == LOW || digitalRead(11) == HIGH && digitalRead(3) == LOW) && (digitalRead(12) == HIGH || digitalRead(13) == HIGH)) {
    digitalWrite(11, HIGH);
    bomba_on = true;
  } else {
    digitalWrite(11, LOW);
    bomba_on = false;
  }
}
 
void setup()
{
  pinMode(2, INPUT); //XMANU
  pinMode(3, INPUT); //XSTOP
  pinMode(4, INPUT); //XRESISTENCIA
  pinMode(9, INPUT); //YRESISTENCIA
  pinMode(5, INPUT); //XBOMBA
  pinMode(11, INPUT); //YBOMBA
  pinMode(6, INPUT); //XLUZ
  pinMode(10, INPUT); //YLUZ
  pinMode(7, INPUT); //XELT_CASCATA
  pinMode(13, INPUT); //YELT_CASCATA
  pinMode(8, INPUT); //XELT_IDRO -> ELETROVALV
  pinMode(12, INPUT); //YELT_IDROV-> ELETROVALV
  
  pinMode(9, OUTPUT); 
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  if ((digitalRead(5) == HIGH && digitalRead(3) == LOW || digitalRead(11) == LOW && digitalRead(3) == LOW) && (digitalRead(12) == LOW || digitalRead(13) == LOW)) {
    digitalWrite(11, LOW);
  } else {
    digitalWrite(11, HIGH);
  }

  if ((digitalRead(4) == HIGH && digitalRead(3) == LOW || digitalRead(9) == LOW && digitalRead(3) == LOW) && digitalRead(11) == LOW) {
    digitalWrite(9, LOW);
  } else {
    digitalWrite(9, HIGH);
  }

  if (digitalRead(6) == HIGH && digitalRead(3) == LOW || digitalRead(10) == LOW && digitalRead(3) == LOW) {
    digitalWrite(10, LOW);
  } else {
    digitalWrite(10, HIGH);
  }

  if (digitalRead(8) == HIGH && digitalRead(3) == LOW || digitalRead(12) == LOW && digitalRead(3) == LOW) {
    digitalWrite(12, LOW);
  } else {
    digitalWrite(12, HIGH);
  }

  if (digitalRead(7) == HIGH && digitalRead(3) == LOW || digitalRead(13) == LOW && digitalRead(3) == LOW) {
    digitalWrite(13, LOW);
  } else {
    digitalWrite(13, HIGH);
  }
  delay(10); // Delay a little bit to improve simulation performance
}
