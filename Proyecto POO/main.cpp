#include <iostream>
#include "Principal.h"

using namespace std;

int main(int argc, char** argv) {
	
	
	Principal *p = new Principal;
	p->Menu();
	
}

/*void Principal::mostrarRutas(bool asignar)
{
	cout<<"Rutas :D"<<endl;
	cout<<"SALIDA: \t"<<"LLEGADA: \t"<<"HORA: "<<ends<<"CODIGO:"<<endl;
	cout<<"--------------------------------------------------------------------------------------"<<endl;
	for ( int i=0; i < this->cantRutas ; i++){
		if(asignar)
		cout<<"RUTA "<<(i+1)<<endl;
		this->rutas[i]->imprimir();
	
	}
	if(!asignar)
	this->volverMenu();
}*/

