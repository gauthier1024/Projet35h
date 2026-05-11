/* 
https://docs.arduino.cc/tutorials/motor-shield-rev3/msr3-controlling-dc-motor/?_gl=1*2ba1jw*_up*MQ..*_ga*OTE0MDk4Njk5LjE3Nzg0ODA5MjQ.*_ga_NEXN8H46L5*czE3Nzg0ODA5MjMkbzEkZzEkdDE3Nzg0ODA5OTgkajYwJGwwJGg2ODM0MDMyNDA.

Shield:
But if we want to do a bit more than just making a motor spin full speed in two directions, we need a motor control circuit. 
More specifically, the dual full-bridge driver L298P, which we can find on the Motor Shield Rev3.

With this IC, we can set the work duty (0-100), enable brakes (HIGH, or LOW), and set the direction (HIGH or LOW). 
Each of these features can be controlled using a different set of pins. 
As we are going to control a DC motor in this tutorial, let's take a look at the pins that are used:

Channel A:

    D12 - Direction
    D3 - PWM (work duty)
    D9 - Brake
    A0 - current sensing.

Channel B:

    D13 - Direction
    D11 - PWM (work duty)
    D8 - Brake
    A1 - current sensing.

*/

#define directionPinA 12     // D
#define directionPinB 13     // D
#define pwmPinA 3            // A
#define pwmPinB 11           // A
// #define brakePinA 9          // D
// #define brakePinB 8          // D
// #define currentSensingPinA 0 // A
// #define currentSensingPinB 1 // A

#include <stdint.h>
#include <cmath>

typedef enum {
	BOUTON_1 = 0,
	BOUTON_2 = 1,
	BOUTON_3 = 2,
	BOUTON_4 = 3,
	BOUTON_5 = 4,
	BOUTON_6 = 5,
	BOUTON_7 = 6,
	BOUTON_8 = 7,
	BOUTON_9 = 8,
	ASTERISQUE = 9,
	BOUTON_0 = 10,
	DIESE = 11,
	HAUT = 12,
	GAUCHE = 13,
	OK = 14,
	DROITE = 15,
	BAS = 16
} touche_t;

typedef enum {
	MANUEL = false,
	AUTOMATIQUE = true
} mode_robot_t;

bool mode = MANUEL;

void setup() {
  // roue A
	pinMode(directionPinA, OUTPUT);
  pinMode(pwmPinA, OUTPUT);

  // roue B
  pinMode(directionPinB, OUTPUT);
  pinMode(pwmPinB, OUTPUT);


}


/*-----------------------------------------*/

void input_roues(){
  analogWrite(pwmPinA, 255);
  analogWrite(pwmPinB, 255);
  if (false) {   // placeholder bouton pour avancer (HAUT)
    digitalWrite(directionPinA, LOW);
    digitalWrite(directionPinB, LOW);
  }
	if (false) {   // placeholder bouton pour gauche  (GAUCHE)
    digitalWrite(directionPinA, HIGH);
    digitalWrite(directionPinB, LOW);
  }
	if (false) {   // placeholder bouton pour droite  (DROITE)
    digitalWrite(directionPinA, LOW);
    digitalWrite(directionPinB, HIGH);
  }
	if (false) {   // placeholder bouton pour reculer (BAS)
    digitalWrite(directionPinA, HIGH);
    digitalWrite(directionPinB, HIGH);
  }

  digitalWrite(directionPinA, LOW);
  digitalWrite(directionPinB, LOW);
  analogWrite(pwmPinA, 0);
  analogWrite(pwmPinB, 0);
  return;
}

void loop() {
	if (false) mode = !mode; // placeholder bouton pour changer de mode
	
	if (mode == MANUEL) {
		input_roues();
	} 
	else {
		

	}

	
}
