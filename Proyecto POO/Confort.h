#ifndef CONFORT_H
#define CONFORT_H

#include "Bus.h"

class Confort : public Bus
{
	bool servicioBano;
	public:
		Confort();
		Confort(short int control,string,bool);
		void imprimir();
		~Confort();
	protected:
};

#endif
