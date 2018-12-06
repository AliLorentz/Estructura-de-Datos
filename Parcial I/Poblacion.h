#ifndef POBLACION_H
#define POBLACION_H
#include "string.h"
#include <iostream>
//ALi Colmenares 26675502
using namespace std;
class Poblacion
{
	string Pais;
	string Cantidad;
	 public:
	 	Poblacion(){
		 }
		Poblacion(string pa, string ca){
			this->Pais = pa;
			this->Cantidad = ca;
			
		}
		string get_Pais(){
			return Pais;}
			
		string get_Cantidad(){
			return Cantidad;}		
		
		void Imprimir(){
			cout<<"Pais:"<<Pais<<" "<<"Poblacion:"<<Cantidad<<endl;
		}
};


#endif
