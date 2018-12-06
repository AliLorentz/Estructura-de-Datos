#ifndef PAISS_H
#define PAISS_H
#include <iostream>
#include "string.h"
#include <cstdlib>
#include <stdio.h>

//ALi Colmenares 26675502
using namespace std;
class Paiss
{
	char codigo[10];
	char country[20];
	char capital[80];
	
	public:
	bool operator<( Paiss &x ) { 
	return strcmpi(codigo, x.codigo) < 0; 
		}

	Paiss(){
		}
	Paiss(char codigo[],char country[],char capital[]){
		strcpy(this->codigo, codigo);
		strcpy(this->country, country);
		strcpy(this->capital, capital);
	}
	
	void setValue(char value[]) { strcpy(this->codigo, value); };
	
	void imprimir(){
		switch(atoi(codigo)){
			case 45:cout<<"Oceania";
			break;
			case 15:cout<<"Africa";
			break;
			case 23:cout<<"America";
			break;
			case 27:cout<<"Asia";
			break;
			case 32:cout<<"Europa";
			break;
		}
		
		cout<<" Pais:"<<country<<" Capital:"<<capital<<endl;
	}
	
};



#endif
