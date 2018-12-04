#ifndef CIUDAD_H
#define CIUDAD_H
#include <iostream>

using namespace std;
class Ciudad
{
	string codigo;
	string nombre;
	
	public:
		Ciudad();
		Ciudad(string,string);
		~Ciudad(){cout<<"Datos eliminados";	}
		void imprimirCiudad();
		string getCodigo(){	return this->codigo;	}
		string getNombre(){return this->nombre; }
	
	protected:
};

#endif
