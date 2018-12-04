#include "Ciudad.h"
#include <iostream>

using namespace std;

Ciudad::Ciudad(){
	this->nombre="";
	this->codigo ="";
}

Ciudad::Ciudad(string nombre,string codigo){
	this->nombre= nombre;
	this->codigo = codigo;
	
}

void Ciudad::imprimirCiudad(){
	cout<<"Nombre: "<<this->nombre<<endl;
	cout<<"codigo: "<<this->codigo<<endl;
}
