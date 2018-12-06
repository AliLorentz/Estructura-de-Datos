#include <iostream>
//#include "ListaDinamica.h"
#include "Articulo.h"
#include "listasimple.h"
using namespace std;

class Departamento{
	int cod;
	string nom;
	listasimple<Articulo> *listArt;
	
	public:
		Departamento(){	cod=0; nom=" ";	listArt=NULL;	}
		Departamento(int c, string n){	cod=c; nom=n; listArt=new listasimple<Articulo>;	}
				void set_Cod(int c);
		void set_Nom(string n);
		int get_Cod();
		string get_Nom();
		void Agregar_Articulo(Articulo A);
		void Eliminar_Articulo(Articulo &A);
		void Imprimir(bool band=true);//BAND TRUE PARA IMPRIMIR SOLO LOS DATOS SIN ARTICULO
		
		bool operator <(Departamento D){	return this->cod<D.cod;	}
		bool operator >(Departamento D){	return this->cod>D.cod;	}
		bool operator ==(Departamento D){	return this->cod==D.cod;	}
		
		
		friend ostream & operator << (ostream &p, Departamento D){
			return p<<"  "<<D.cod<<"\t   "<<D.nom; 
		}
};

void Departamento::set_Cod(int c){	cod=c;	}

void Departamento::set_Nom(string n){	nom=n;	}

int Departamento::get_Cod(){	return cod;	}

string Departamento::get_Nom(){	return nom;	}

void Departamento::Agregar_Articulo(Articulo A){
	listArt->agregar(A);//->Agregar(A,0);
}

void Departamento::Eliminar_Articulo(Articulo &A){
	listArt->eliminar(A);//->Eliminar();
}

void Departamento::Imprimir(bool band){
	cout<<"CODIGO DEL DEPARTAMENTO: "<<cod<<"\t NOMBRE DEL DEPARTAMENTO: "<<nom<<endl;
	if(!band) cout<<"ARTICULOS:\n"; listArt->imprimir();//->Imprimir();
}
