#include "Boleto.h"
#include <iostream>
#include <string.h>
#include <cstring>
#include <stdlib.h>
using namespace std;
Boleto::Boleto()
{
	this->numero =0;
	this->codigoVerificacion =0;
}

Boleto::Boleto(int numero, Pasajero *pasajero,Asignacion * asignacion){
	this->numero = numero;
	this->pasajero = pasajero;
	this->asignacion = asignacion;
}

void Boleto::emitirBoleto(){
	system("cls");
	cout<<"----------------------------------------------------"<<endl;
	cout<<"Boleto #"<<this->numero<<endl;
	cout<<"----------------------------------------------------"<<endl;
	this->pasajero->imprimir();
	cout<<"----------------------------------------------------"<<endl;
	this->asignacion->getRuta()->imprimir();
	cout<<"----------------------------------------------------"<<endl;
	//this->asignacion->getBus()->imprimir();
	cout<<"----------------------------------------------------"<<endl;
	cout<<"Codigo de Verficacion"<<this->codigoVerificacion<<endl;;
	cout<<"----------------------------------------------------"<<endl;
}

/*unsigned int cod = 0;
	
	int num = this->pasajero->getCedula().length();
	string str = this->pasajero->getCedula().substr(num-2);
	num = atoi(str.c_str());
	cod = cod | num;
	cod = cod << 8 ;
	
	str = this->asignacion->().substr(0,1);
	char *var;
	strcpy( var , str.c_str() );
	cod = cod | (int) var[0];
	cod = cod << 8;
	
	str = this->asignacion->getCodLlegada().substr(0,1);
	strcpy( var , str.c_str() );
	cod = cod | (int) var[0];
	cod = cod << 8 ;
	
	str = this->asignacion->getHoraSalida().substr(0,2);
	num = atoi(str.c_str());
	cod = cod | num;
	
	this->codigoVerificacion = cod;
*/

void Boleto::generarCodigo() {
	unsigned int cod = 0;
	
	int num = this->pasajero->getCedula().length();
	string str = this->pasajero->getCedula().substr(num-2);
	num = atoi(str.c_str());
	cod = cod | num;
	cod = cod << 8 ;
		
	string aux = this->asignacion->getCodSalida().substr(0,1);
//	char b=aux;
		int c;
	//char b = aux;
//	cout<<b<<endl;
//	c = aux;
//	cout<<c<<endl;
	system("pause");

	
	this->codigoVerificacion = cod;
	
}

Boleto::~Boleto()
{
	cout<<"Archivos de boletos eliminados"<<endl;
}
