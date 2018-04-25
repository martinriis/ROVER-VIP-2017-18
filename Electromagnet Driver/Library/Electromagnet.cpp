/*
 * ElectromagnetDriver.cpp
 *
 * Created: 25/04/2018 16:59:29
 * Author : Martin Riis
 */ 

#include "Electromagnet.h"

#define GATE1 PORT_PA22
#define GATE2 PORT_PA23
#define GATE3 PORT_PA10
#define GATE4 PORT_PA11
#define GATE5 PORT_PB10
#define GATE6 PORT_PB11
#define GATE7 PORT_PA20
#define GATE8 PORT_PA21

Electromagnet::Electromagnet() {
	gate = 20; // Initialises gate to a higher value than allowed, ensures .setup() function is ran
}

void Electromagnet::setup(uint8_t gateNumber) {
	SystemInit(); // Initialises SAM system
	gate = gateNumber;
	
	// *** SETS REQUIRED PORTS AS OUTPUTS *** //
	#if gate == 1
		REG_PORT_DIR0 |= GATE1; // Gate 1
	#elif gate == 2
		REG_PORT_DIR0 |= GATE2; // Gate 2
	#elif gate == 3
		REG_PORT_DIR0 |= GATE3; // Gate 3
	#elif gate == 4
		REG_PORT_DIR0 |= GATE4; // Gate 4
	#elif gate == 5
		REG_PORT_DIR1 |= GATE5; // Gate 5
	#elif gate == 6
		REG_PORT_DIR1 |= GATE6; // Gate 6
	#elif gate == 7
		REG_PORT_DIR0 |= GATE7; // Gate 7
	#elif gate == 8
		REG_PORT_DIR0 |= GATE8; // Gate 8	
		
	#else
		#error Invalid gate number, gate number must be between 1 and 8 (inclusive)
	#endif
}

bool Electromagnet::getState() { // Returns state of electromagnet
	return state;
}

void Electromagnet::activate() { // Activates electromagnet
	state = true; // Electromagnet in activated state
	
	#if gate == 1
		REG_PORT_OUT0 &= GATE1; // Activates gate 1
	#elif gate == 2
		REG_PORT_OUT0 &= GATE2; // Activates gate 2
	#elif gate == 3
		REG_PORT_OUT0 &= GATE3; // Activates gate 3
	#elif gate == 4
		REG_PORT_OUT0 &= GATE4; // Activates gate 4
	#elif gate == 5
		REG_PORT_OUT1 &= GATE5; // Activates gate 5
	#elif gate == 6
		REG_PORT_OUT1 &= GATE6; // Activates gate 6
	#elif gate == 7
		REG_PORT_OUT0 &= GATE7; // Activates gate 7
	#elif gate == 8
		REG_PORT_OUT0 &= GATE8; // Activates gate 8
		
	#else
		#error Gate not setup, use .setup() function to setup the output
	#endif
}

void Electromagnet::deactivate() { // Deactivates electromagnet
	state = false; // Electromagnet in deactivated state
	
	#if gate == 1
		REG_PORT_OUT0 &= ~GATE1; // Deactivates gate 1
	#elif gate == 2
		REG_PORT_OUT0 &= ~GATE2; // Deactivates gate 2
	#elif gate == 3
		REG_PORT_OUT0 &= ~GATE3; // Deactivates gate 3
	#elif gate == 4
		REG_PORT_OUT0 &= ~GATE4; // Deactivates gate 4
	#elif gate == 5
		REG_PORT_OUT1 &= ~GATE5; // Deactivates gate 5
	#elif gate == 6
		REG_PORT_OUT1 &= ~GATE6; // Deactivates gate 6
	#elif gate == 7
		REG_PORT_OUT0 &= ~GATE7; // Deactivates gate 7
	#elif gate == 8
		REG_PORT_OUT0 &= ~GATE8; // Deactivates gate 8
		
	#else
		#error Gate not setup, use .setup() function to setup the output
	#endif
}