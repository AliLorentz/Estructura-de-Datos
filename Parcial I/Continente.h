#ifndef CONTINENTE_H
#define CONTINENTE_H
#include <iostream>
#include "string.h"
//ALi Colmenares 26675502
using namespace std;
class Continente
{
	int codigo;
	char nombre[40];
	
	public:
	bool operator<(Continente &x){
		return strcmpi(nombre, x.nombre)<0;
	}
	Continente(){
		strcpy(nombre,"");
		codigo=0;
	}
	Continente(int codigo,char nombre[]){
		this->codigo = codigo;
		strcpy(this->nombre,nombre);
	}
	void imprimir(){
		cout<< nombre <<" "<<codigo<<" "<<endl;
	}
	void setValue(char value[]){
		strcpy(this->nombre,value);
	}
};

#endif

