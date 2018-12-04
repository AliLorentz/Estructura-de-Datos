#include "Pasajero.h"
using namespace std;
#include <iostream>
using namespace std;
Pasajero::Pasajero()
{
	this->cedula = "";
	this->nombre = "";
	this->apellido = "";
}

Pasajero::Pasajero(string cedula,string nombre, string apellido){
	
	this->cedula = cedula;
	this->nombre = nombre;
	this->apellido = apellido;
	
	
} 

void Pasajero::imprimir(){
	 cout<<"Nombre: "<<this->nombre<<endl;
	 cout<<"Apellido: "<<this->apellido<<endl;
	 cout<<"Cedula: "<<this->cedula<<endl;
	 
}

Pasajero::~Pasajero()
{
	cout<<"Datos de pasajero eliminados"<<endl;
}
