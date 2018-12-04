#include "Asignacion.h"

using namespace std;
Asignacion::Asignacion()
{
}

Asignacion::Asignacion(Ruta*ruta,Bus *bus){
	this->ruta = ruta;
	this->bus = bus;
}


Asignacion::~Asignacion(){cout<<"Asignaciones eliminadas"<<endl;}


string Asignacion::getCodLlegada(){return this->ruta->getLlehada();}
string Asignacion::getCodSalida(){return this->ruta->getSalida();}
string Asignacion::getHoraSalida(){return this->ruta->getHoraSalida();}


Bus* Asignacion::getBus(){	return this->bus;}
Ruta* Asignacion::getRuta(){return this->ruta;}


