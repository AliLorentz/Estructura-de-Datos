#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include "string.h"

using namespace std;

class Persona
{
	int cedula;
	string nombre;
	string apellido;
	public:
		Persona();
		Persona(int c, string nom, string ape) {
			this->cedula = c;
			this->nombre = nom;
			this->apellido = ape;
		}
		void imprimir() {
			cout << nombre << " " << apellido  << endl;
		}
		bool operator>(const Persona& datos){ 
			return (this->cedula > datos.cedula);
		}
};

#endif
