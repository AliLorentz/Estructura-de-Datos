#ifndef RUTA_H
#define RUTA_H
#include "Ciudad.h"
#include <iostream>


class Ruta
{
	Ciudad *ciudadSalida;
	Ciudad *ciudadLLegada;
	string horaSalida;
	string codigo;
	
	public:
		Ruta();
		Ruta(Ciudad *ciudadSalida, Ciudad *ciudadLlegada,string);
		void imprimir();
		string getHoraSalida(){return this->horaSalida;}
		string getCodigo(){	return this->codigo;}
		string getSalida();
		string getLlehada();
		~Ruta();
	protected:
};

#endif
