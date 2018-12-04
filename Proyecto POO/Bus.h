#ifndef BUS_H
#define BUS_H
#include <iostream>

using namespace std;
class Bus
{
	short int control;
	string nombreConductor;
	
	public:
		Bus();
		Bus(short int control,string);
		virtual void imprimir();
		~Bus();
	protected:
};

#endif
