#ifndef FINAL_H
#define FINAL_H
#include <string>
#include "listasimple.h"
#include <iostream>
using namespace std;
class Final
{
	string nombre; /*Me falto lo ultimo los cod de las avionestas */
	string cod;
	public:
		Final();
		Final(string _nombre, string _cod){
			nombre=_nombre;
			cod=_cod;
		}
		void imprimir(){
			cout<<"cod:"<<nombre<<" "<<"Nombre: "<<cod<<endl;
		}
		void final(){
			listasimple<string>ll;
			ll.agregar(nombre);
				cout<<"cod:"<<nombre<<" "<<"Nombre: "<<cod<<endl;
		}
		
		~Final();
	protected:
};

#endif
