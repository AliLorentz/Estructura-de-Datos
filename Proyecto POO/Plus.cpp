#include "Plus.h"

Plus::Plus()
{
}

Plus::Plus(short int control,string nombreConductor,bool servicioPantalla):Bus(control,nombreConductor){
	this->servicioPantalla=servicioPantalla;
	
}

void Plus::imprimir(){
	Bus::imprimir();
	if(this->servicioPantalla)
	cout<<"Servicio de pantalla agregado"<<endl;
	else
	cout<<"No posee servicio de pantalla"<<endl;
}

Plus::~Plus()
{
}
