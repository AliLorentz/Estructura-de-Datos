#ifndef PLUS_H
#define PLUS_H

#include "Bus.h"

class Plus : public Bus
{
	bool servicioPantalla;
	public:
		Plus();
		Plus(short int control,string,bool);
		void imprimir();
		~Plus();
	protected:
};

#endif
