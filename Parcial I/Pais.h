#ifndef PAIS_H
#define PAIS_H
#include <iostream>
#include "string.h"
//ALi Colmenares 26675502
using namespace std;
class Pais
{
	int codigo;
	string country;
	string capital;
	
	public:

	Pais(){
	}
	Pais(int codigo,string nombre,string capi){
		this->codigo = codigo;
		this->country=nombre;
		this->capital=capi;
	}
	string get_Pais(){
		return country;
	}
	
	string get_Capital(){
		return capital;
	}
	
	int get_codigo(){
		return codigo;
	}
	
	void imprimir(){
		if(codigo==23){
			cout<<"Continente:Americano";
		}else if(codigo==32){
			cout<<"Continente:Europa";
		}else if(codigo==27){
				cout<<"Continente:Asia";
		}else if(codigo==15){
				cout<<"Continente:Africa";
		}else{
			cout<<"Continente Oceania";
		}
		
		cout<<" Pais:"<<country<<" Capital:"<<capital<<endl;
	}
	
	void imprimirCode(){
			cout<<codigo<<" Pais:"<<country<<" Capital:"<<capital<<endl;
	}
};



#endif

