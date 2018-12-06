#include <iostream>
#include <string.h> 
#include "ListaCirDob.h"

using namespace std;
int primerFuncion();
int segunaFuncion();
//Variables Globales 
char nombre[30];
char cedula [30];

int main(int argc, char** argv) {
	cout<<"\n\n-------------------------BIENVENIDO VISA© 2018---------------------------------"<<endl;
	cout<<"\n\n\t  Sistema de creacion de claves Especiales\n";
	cout<<"\n    Se creara 2 claves especiales utilisando sus datos personales";
	cout<<"\nIngrese Su Nombre:   ";
		cin.getline(nombre,30);
	cout<<"\nIngrese Su cedula:   ";
	 cin.getline(cedula,30);
	cout<<"\n-----------------------------------------------------------------------------"<<endl<<endl;

	primerFuncion();
	segunaFuncion();

}

int primerFuncion(){
	
	ListaCirDob<char>obj;	
	//Solicitud de datos

	int longitud = strlen(cedula);//Tamaño de la cedula
	string clave;
	for(int i=0;nombre[i]!=0;i++)
	if(nombre[i]!=32){
	  obj.agregar(nombre[i]);//Ingresa los caracteres uno por uno a la lista
	}
	int i=0;
	bool band=true;
	for(int j=0;i<longitud;j++){
	int numero=(int)cedula[i];
	char letra=obj.mover(numero,band); //Retorna la posicion de la letra a la que se mueve para eliminar
	clave+=letra;
	i++;
	clave+=cedula[i];	
	i++;
	if(band==true)band=false;
	else band=true;
	}
	cout<<"\n---------------------Sus Claves Especial -------------------------------------"<<endl;
	cout<<endl<<"clave #1)   "<<clave;	
	i=0;
	 return 0;
	 }
	 
int segunaFuncion(){
	ListaCirDob<char>obj;
	int longitud=0;
	int tam = strlen(cedula);
	string clave;

	for(int i=0;nombre[i]!=0;i++){		
	if(nombre[i]!=32){
		longitud++;
	  obj.agregar(nombre[i]);//Ingresa los caracteres uno por uno a la lista
	}}
	char aux=obj.mover(longitud,true);
	int  i = 0;
	bool band=true;
	
	for(int j=0; i<=longitud;j++){
	int numero =(int)cedula[i];
	char letra = obj.practica(numero,true); 
	clave+=letra;
	i++;
	clave+=cedula[i];
	i++;
	numero=(int)cedula[i];
	letra=obj.practica(numero,false);
	clave+=letra;
	i++;
	clave+=cedula[i];
	i++;
	}
	if(longitud<=3)clave+=aux;
	
	for(i; i<tam;i++)
	clave+=cedula[i];

	cout<<endl<<"Clave #2)   "<<clave<<endl;
	cout<<"-----------------------VISA© 2018---------------------------------------------"<<endl<<endl;
	return 0;//Clave especial creada con exito
}


