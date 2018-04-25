/*
 * Electromagnet.h
 *
 * Created: 25/04/2018 17:04:14
 * Author: Martin Riis
 */


#ifndef ELECTROMAGNET_H_
#define ELECTROMAGNET_H_

#include "Dependencies\port.h"
#include "Dependencies\samd21g18a.h"
//#include "sam.h" // Uncomment if using Atmel Studio

class Electromagnet {
	private:
	bool state; // True = on, false = off
	uint8_t gate; // Gate number

	public:
	Electromagnet(); // Default constructor
	void setup(uint8_t); // Setup function for gate number declaration and pin direction configuration
	bool getState(); // Returns state of electromagnet true = on, false = off
	void activate(); // Activates the electromagnet
	void deactivate(); // Deactivates the electromagnet
};

#endif /* ELECTROMAGNET_H_ */
