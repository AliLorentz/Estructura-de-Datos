#include "Ruta.h"
#include <iostream>

Ruta::Ruta()
{
	this->ciudadSalida=NULL;
	this->ciudadLLegada=NULL;
}

Ruta::Ruta(Ciudad *ciudadSalida, Ciudad *ciudadLLegada,string horaSalida){
	this->ciudadSalida = ciudadSalida;
	this->ciudadLLegada = ciudadLLegada;
	this->horaSalida = horaSalida;
	this->codigo="ERROR";
	
	if( this->ciudadSalida && this->ciudadLLegada ) {
		this->codigo = this->ciudadSalida->getCodigo()+this->ciudadLLegada->getCodigo()+this->horaSalida;
	}

}

void Ruta::imprimir(){
	cout<<this->ciudadLLegada->getCodigo()<<":"<<this->ciudadLLegada->getNombre()<<"      ";
	cout<<this->ciudadSalida->getCodigo()<<":"<<this->ciudadSalida->getNombre()<<"       ";
	cout<<this->horaSalida<<"      ";
	cout<<this->codigo<<endl;
	
}



Ruta::~Ruta()
{
	cout<<"Datos de rutas eliminados";
}

string Ruta::getSalida(){
	return this->ciudadSalida->getCodigo();
}
string Ruta::getLlehada(){
	return this->ciudadLLegada->getCodigo();
}
