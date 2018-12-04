#ifndef PASAJERO_H
#define PASAJERO_H
#include <iostream>

using namespace std;
class Pasajero
{
	string cedula;
	string nombre;
	string apellido;
	
	public:
		Pasajero();
		Pasajero(string,string,string);
		~Pasajero();
		
		string getCedula(){	return cedula;}
		string getNombre(){return nombre;}
		string getApellido(){	return apellido;}
		
		void imprimir();
		
	protected:
};

#endif
