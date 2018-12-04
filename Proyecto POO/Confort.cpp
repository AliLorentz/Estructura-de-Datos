#include "Confort.h"

Confort::Confort()
{
}
Confort::Confort(short int control,string nombreConductor,bool servicioBano):Bus(control,nombreConductor){
	this->servicioBano=servicioBano;
}

void Confort::imprimir(){
	Bus::imprimir();
	if(this->servicioBano)
	cout<<"Agregado servicio de baño"<<endl;
	else
	cout<<"Se va a mear en el camino :v"<<endl;
		
	
}

Confort::~Confort()
{
	cout<<"Serivicio eliminado"<<endl;
}
