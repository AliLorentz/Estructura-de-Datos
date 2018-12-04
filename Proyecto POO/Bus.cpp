#include "Bus.h"

using namespace std;
Bus::Bus()
{
	short int control =0;
	this->nombreConductor = "";
}
Bus::Bus(short int control, string nombreConductor){
	this->control=control;
	this->nombreConductor=nombreConductor;
}

 void Bus::imprimir(){
 	cout<<"Nombre:"<<this->nombreConductor<<"\t control :"<<this->control<<endl;
 }

Bus::~Bus()
{
	cout<<"Datos de ciudad eliminados"<<endl;
}
