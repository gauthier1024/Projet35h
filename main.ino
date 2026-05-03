/* https://github.com/adafruit/Adafruit_Motor_Shield_V2_Library/blob/master/Adafruit_MotorShield.h

#define FORWARD 1
#define BACKWARD 2
#define BRAKE 3
#define RELEASE 4


Pins A4 et A5 utilisés par le shield
*/

#include <stdint.h>
#include <cmath>

#include <Wire.h>
#include <Adafruit_MotorShield.h>

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
} key_t;

typedef enum {
	MANUEL = false,
	AUTOMATIQUE = true
} mode_t;

bool mode = MANUEL;

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *moteur1 = AFMS.getMotor(1); // M1
Adafruit_DCMotor *moteur2 = AFMS.getMotor(2); // M2

/*-----------------------------------------*/

void moteur(uint8_t gauche_commande, uint8_t gauche_puissance, uint8_t droite_commande, uint8_t droite_puissance) {
	moteur1->setSpeed(gauche_puissance);
	moteur2->setSpeed(droite_puissance);
	moteur1->run(gauche_commande);
	moteur2->run(droite_commande);
}

/*-----------------------------------------*/

void setup() {
	AFMS.begin();         // Initialise le shield
	moteur1->setSpeed(0); // Vitesse
	moteur2->setSpeed(0); // Vitesse
}

/*-----------------------------------------*/

void loop() {
	if (false) mode = !mode; // placeholder bouton pour changer de mode
	
	if (mode == MANUEL) {
		if (false) moteur(FORWARD, 255, FORWARD, 255);   // placeholder bouton pour avancer (HAUT)
		if (false) moteur(BACKWARD, 0, FORWARD, 255);    // placeholder bouton pour gauche  (GAUCHE)
		if (false) moteur(FORWARD, 255, BACKWARD, 0);    // placeholder bouton pour droite  (DROITE)
		if (false) moteur(BACKWARD, 255, BACKWARD, 255); // placeholder bouton pour reculer (BAS)
	} 
	else {
		

	}

	
}
