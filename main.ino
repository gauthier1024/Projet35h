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

digitalWrite(directionPinA, LOW); // sens
analogWrite(pwmPinA, 255); // vitesse

D0 *
D1 *
D2 * IR
D3 * PWM Shield
D4
D5 * Servo
D6 * Suivi de ligne
D7 * Suivi de ligne
D8 * Shield Brake
D9 * Shield Brake
D10
D11 * PWM Shield
D12 * Direction Shield
D13 * Direction Shield
A0 * Shield Current sensing
A1 * Shield Current sensing
A2
A3
A4
A5
*/


#define directionPinA 12     // D
#define directionPinB 13     // D
#define pwmPinA 3            // A
#define pwmPinB 11           // A
// #define brakePinA 9          // D
// #define brakePinB 8          // D
// #define currentSensingPinA 0 // A
// #define currentSensingPinB 1 // A
#define IRPin 2              // D
#define servoPin 5           // D
#define lignePinA 6
#define lignePinB 7

#include <stdint.h>

#include <Servo.h>

/*
typedef uint32_t etat_clavier_t;
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

etat_clavier_t scan_clavier(){
  // placeholder car IR marche pas
  return 0;
}

static inline bool touche_appuyee(etat_clavier_t etat, touche_t touche) {
  return (etat >> (uint8_t)touche) & 1;
}

*/

typedef enum {
	MANUEL = false,
	AUTOMATIQUE = true
} mode_robot_t;


bool mode = AUTOMATIQUE;

Servo servo;

void setup() {
  Serial.begin(9600);

  servo.attach(servoPin);
  servo.write(180);

  // roue A
	pinMode(directionPinA, OUTPUT);
  pinMode(pwmPinA, OUTPUT);

  // roue B
  pinMode(directionPinB, OUTPUT);
  pinMode(pwmPinB, OUTPUT);

  // analogWrite(pwmPinA, 255);
  // analogWrite(pwmPinB, 255);
}

void loop() {
  // etat_clavier_t etat = scan_clavier();
  
	// if (touche_appuyee(etat, BOUTON_1)) mode = !mode; // changer de mode si btn1
	
	// if (mode == MANUEL) {
	//  	if (touche_appuyee(etat, HAUT)){
  //     analogWrite(pwmPinA, 255);
  //     analogWrite(pwmPinB, 255);
  //     digitalWrite(directionPinA, HIGH);
  //     digitalWrite(directionPinB, HIGH);
  //   }
  //   else if (touche_appuyee(etat, BAS)){
  //     analogWrite(pwmPinA, 255);
  //     analogWrite(pwmPinB, 255);
  //     digitalWrite(directionPinA, LOW);
  //     digitalWrite(directionPinB, HIGH);
  //   }
  //   else if (touche_appuyee(etat, GAUCHE)){
  //     analogWrite(pwmPinA, 255);
  //     analogWrite(pwmPinB, 255);
  //     digitalWrite(directionPinA, HIGH);
  //     digitalWrite(directionPinB, LOW);
  //   }
  //   else if (touche_appuyee(etat, DROITE)){
  //     analogWrite(pwmPinA, 255);
  //     analogWrite(pwmPinB, 255);
  //     digitalWrite(directionPinA, LOW);
  //     digitalWrite(directionPinB, LOW);
  //   }
  //   else {
  //     analogWrite(pwmPinA, 0);
  //     analogWrite(pwmPinB, 0);
  //   }
	// }
	// else {
		
	// }

  
  
  
	
}
