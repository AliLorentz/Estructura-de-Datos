#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include "Persona.h"

using namespace std;

void opciones();
void agregarEstudiante();
void registro();
void searchPer();
template <class T>
void shell(vector<T> &x);

void eliminar();

int main(int argc, char** argv) {
	cout<<"Bienvenido a datos Binarios"<<endl;
	opciones();
	return 0;
}

void opciones(){
	int elect;
	bool escoger = false;
	
	do{
		system("cls");
		cout<<"\n---------------------Bienvenido a datos Binarios-------------------------"<<endl<<endl;
		cout<<"\n1)-Agregar un nuevo Persona"<<endl;
		cout<<"\n2)-Buscar Persona"<<endl;
		cout<<"\n3)-Eliminar una Persona"<<endl;
		cout<<"\n4)-Mostrar Registro"<<endl;
		cout<<"\n5)-Salir"<<endl<<endl;
		cin>>elect;
		
		escoger=false;
		switch(elect){
			case 1:
			agregarEstudiante();
			break;
			case 2:
			searchPer();
			break;
			case 3:
			eliminar();
			break;
			case 4:
			registro();
			break;
			case 5:
			exit(1);
			default:
			cout<<"Intentelo de nuevo"<<endl;
			escoger=true;
		}
		
	}while(escoger==true);
	
}

void eliminar(){
	fstream arch;
	Persona p;
	vector <Persona> eli;
	
	arch.open("Datos.dat", ios::binary | ios::in);
	if(arch.fail()){
		cout<<"error al abrir archivo"<<endl;
		system("pause");
		opciones();		
	}else{
		while(true){
			arch.read((char*)&p, sizeof(Persona));
			if(arch.eof()) break;
			eli.push_back(p);
		}
	}
	arch.close();

	
	int cedula;
	cout<<"Ingrese la cedula para eliminar a una persona: "<<endl;
	cin>>cedula;
	arch.open("Datos.dat",ios::binary | ios::out);
	for(int i=0; i< eli.size();i++){
		if(eli[i].get_clave(0) != cedula){
			arch.write((char*)&eli[i],sizeof(Persona));
		}
	}
	arch.close();
	cout<<"Eliminado"<<endl;
	system("pause");
	opciones();
}

void searchPer()
{
		system("cls");
	fstream arch;
	Persona buscar;
	vector<Persona>bq;
	
	arch.open("Datos.dat", ios::binary | ios::in);
	if(arch.fail()){
		cout<<"error al abrir archivo"<<endl;
		system("pause");
		opciones();
	}else{
		while(true){
			arch.read((char*) &buscar, sizeof(Persona));
			if(arch.eof()) break; //Rompo cuando llegue al final
			bq.push_back(buscar);
		}
	}
	arch.close();
		int ced;	
	cout<<"Ingrese la cedula de la persona que desea buscar"<<endl;
	cout<<"Cedula: ";
	fflush(stdin);
	cin>>ced;
	for(int i=0;i<bq.size();i++){
		if(bq[i].get_clave(0)==ced){
			bq[i].imprimir();
		}
	}
	system("pause");
	opciones();
}

void agregarEstudiante(){
		system("cls");
	fstream arch;
	vector<Persona>lista;
	
	string nombre;
	string cedula;
	
	cout<<"Ingrese datos Nombre y Cedula :"<<endl;
	cout<<"Nombre y Apellido: ";
	fflush(stdin); // a la hora de pedir datos :L
	getline(cin,nombre);
	cout<<"\nCedula: "<<endl;
	cin>>cedula;
	
	arch.open("Datos.dat",ios::binary | ios::app);
	Persona agr;
	agr.set_nom(&nombre[0]);
	agr.set_ced(&cedula[0]);
	arch.write((char*)&agr, sizeof(Persona));
	arch.close();
	
	system("pause");
	opciones();
	
}

void registro(){
	system("cls");
	fstream arch;
	Persona mostrar;
	vector<Persona>datos;
	arch.open("Datos.dat",ios::binary | ios::in);
	if(arch.fail()){
		cout<<"error al abrir archivo"<<endl;
		system("pause");
		opciones();
	}else{
		while(true){
			arch.read((char*) &mostrar, sizeof(Persona));
			if(arch.eof())	break; //Verifica si ya leyo todas las condenadas lineas
			
			datos.push_back(mostrar);
		}
	}
	//shell(datos);
	arch.close();
	cout<<endl;
	for(int i=0; i<datos.size();i++){
		cout<<"\t"<<datos[i];		
	}
	cout<<endl<<endl;
	system("pause");
	opciones();
}

template <class T>
void shell(vector<T> &x) {
	bool band;
	int inc = x.size()/2;
	T aux;
	
	while (inc > 0){
		band = false;
		for (int i = 0; i+inc < x.size(); i++) {
			if (x[i] > x[i+inc]) {
				aux = x[i];
				x[i] = x[i+inc];
				x[i+inc] = aux;
				band = true;
			}
		}
		if (!band)
			inc /= 2;
	}
}
