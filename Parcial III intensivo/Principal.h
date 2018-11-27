#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <stdlib.h>
#include <string.h>
#include <fstream>

#include "Persona.h"
#include "PersonaPos.h"
#include "ArbolAVL.h"

using namespace std;
class Principal{
	fstream ficheroTexto;
	fstream ficheroBinario;
	Persona leer;
	string cadena;
	ArbolAVL<PersonaPos>arbol;
	char *auxCadena;
	char *aux;
	public:
		void Menu();
		void separar();
		void llenarArbol();
     	void imprimirArbol();
		void buscarDato();
		void buscarCedula(int cedula);
};

void Principal::Menu(){
	Principal::separar();
	Principal::llenarArbol();
	Principal::imprimirArbol();
	Principal::buscarDato();
}

void Principal::separar(){
	char nombre[40] = "Personas.txt";
	string auxCad;
	ficheroBinario.open("Personas.dat",ios::binary|ios::out);
	ficheroTexto.open(nombre,ios::in);
	
	if(ficheroTexto.fail()){
		cout<<"Error"<<endl;
	}else{
		while(getline(ficheroTexto,cadena)){
			
			for(int i = 0; 	i<cadena.size(); i++){
				auxCad+=cadena[i];
				if(cadena[i]==59 && cadena[i+1]==59){
					auxCad+="x";
				}
			}
				cadena = auxCad;
			
				auxCadena = strtok(&cadena[0],";");
				int auxCedula = atoi(auxCadena);
					
				auxCadena = strtok(NULL,";");
				char auxApellido1[40];
				strcpy(auxApellido1,auxCadena);
	
				auxCadena = strtok(NULL,";");
				char auxApellido2[40];
				strcpy(auxApellido2,auxCadena);
	
				auxCadena = strtok(NULL,";");
				char auxNombre1[40];
				strcpy(auxNombre1,auxCadena);
		
				auxCadena = strtok(NULL,";");
				char auxNombre2[40];
				strcpy(auxNombre2,auxCadena);
				
				auxCadena = strtok(NULL,";");
				int auxCodigo = atoi(auxCadena);
			
				auxCadena = strtok(NULL,";");
				char vacio[40];
				strcpy(vacio,auxCadena);
				
				
				Persona u(auxCedula,auxApellido1,auxApellido2,auxNombre1,auxNombre2,auxCodigo,vacio);
				ficheroBinario.write(reinterpret_cast<char*>(&u),sizeof(Persona));
			//cout<<"Cedula: "<<auxCedula<<" Apellido 1: "<<auxApellido1<< " Apellido 2: "<<auxApellido2<<" Nombre 1:"<<auxNombre1<<" Nombre 2:"<<auxNombre2<<" Codigo: "<<auxCodigo<<endl;
				auxCad= "";
		}
	}
	
	ficheroBinario.close();
	ficheroTexto.close();
		
}

void Principal::llenarArbol(){
	int posCont=0;
	ficheroBinario.open("Personas.dat",ios::binary| ios::in);
	while(!ficheroBinario.eof() && ficheroBinario.read((char*)(&leer),sizeof(Persona))){
		PersonaPos aux(leer.getCedula(), posCont);
		posCont++;
		arbol.Anadir(aux);	
		
	}
	ficheroBinario.close();
}

void Principal::imprimirArbol(){
	arbol.imprimir(2);
	cout<<endl<<endl;
	system("pause");
}

void Principal::buscarDato(){
	system("cls");
	bool band = true;
	int cedula;
	char tecla;
	do{
		cout<<"1) Hacer Busqueda."<<endl;
		cout<<"2) Salir."<<endl;
		tecla = getch();
		switch(tecla){
			case '1':
				system("cls");
				cout<<"Ingrese el numero de cedula: ";
				cin>>cedula;
				Principal::buscarCedula(cedula);
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				cout<<"Gracias por usar nuestro servicio"<<endl;
				band = false;
				break;
			default:
				system("cls");
				cout<<"Opcion invalida"<<endl;
				system("pause");
				system("cls");
			
			
		}
	}while(band);
}

void Principal::buscarCedula(int cedula){
	PersonaPos buscar(cedula,0);
	Persona leer;
	int pos,cont=0;
	bool band = false;
	if(arbol.Buscar(buscar)){
		buscar = arbol.ValorActual();
		cout<<"Busqueda Finalizada!"<<endl<<"Datos: "<<buscar<<endl<<endl;
		pos = buscar.getPosicion();
		band=true;
	}else{
		cout<<"Persona no encontrada"<<endl;
	}
	
	if(band){
		cout<<"Archivo Binario"<<endl;
		ficheroBinario.open("Personas.dat",ios::binary| ios::in);
		ficheroBinario.seekg(pos*sizeof(Persona),ios::cur);
		ficheroBinario.read((char*)(&leer),sizeof(Persona));
		cout<<leer<<endl;
		
		ficheroBinario.close();
	}
}


#endif
