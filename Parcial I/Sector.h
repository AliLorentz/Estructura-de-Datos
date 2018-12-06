#ifndef SECTOR_H
#define SECTOR_H
#include <iostream>
#include "string.h"
#include <cstdlib>
//ALi Colmenares 26675502
using namespace std;
class Sector{
	char Pais[80];
		int poblacion;
	public:
	Sector(){		
	}
	Sector(int poblacion,char Pais[]){
			strcpy(this->Pais, Pais);
			this->poblacion=poblacion;
	}
	int get_Poblacion(){
		return poblacion;
	}
	char *ger_Pais(){
		return Pais;
	}
	void set_Pais(char *n){
		strcpy(Pais,n);
	}
	void set_poblacion(char *n){
		poblacion = atoi(n);
	}
	
	void imprimir(){
		cout<<"Pais:"<<Pais<<" Poblacion:"<<poblacion<<endl;
	}
	
};


#endif
