#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include<stdlib.h>
#include<time.h>
#include <string>
#include <sstream>

#include "Continente.h"
#include "Poblacion.h"
#include "Pais.h"
#include "Paiss.h"
#include "MezclaDirecta.h"
#include "Sector.h"


using namespace std;

void menu();
void listaPaises();
void preguntas();
void listCountry();
template <class T>
void ShellMejorado(vector<T> &v);
void visualizar();

int main(int argc, char** argv) {
	menu();
	return 0;
}

void menu(){
	int elect;
	bool escoger=false;
	do{	
	system("cls");
	cout<<"\n--------------------Menu de Opciones------------------------"<<endl<<endl;
	cout<<"\n1)Consultar info de un pais"<<endl;
	cout<<"\n2)Test de un pais"<<endl;
	cout<<"\n3)Ver lista"<<endl;
	cout<<"\n4)Ver Estadisticas"<<endl;
	cin>>elect;
	switch(elect){
		case 1:
			listaPaises();
		break;
		case 2:
			preguntas();
		break;
		case 3:
		listCountry();
		break;
		case 4:
		visualizar();
		break;
	}
	}while(escoger==true);
}

void preguntas(){	
  
	vector <Pais> paisa;
	fstream archivo;
	archivo.open("Pais.txt",ios::in);
	string lineas;
	char *separa;
	if(archivo.fail()){
		cout<<"error"<<endl;
	}
	else{
		string capital;
		while(getline(archivo,lineas)){
			separa = strtok(&lineas[0],";");
			int codigo = atoi(separa);
			separa = strtok(NULL,";");
			string pais = (string)separa; 
			separa = strtok(NULL,";");
			string capital = (string)separa; 
			separa = strtok(NULL,";");
		//cout<<"Codigo:"<<codigo<<" Pais:"<<pais<<" Capital:"<<capital<<endl;
		Pais pp(codigo,pais,capital);
		paisa.push_back(pp);
		}
	}
	archivo.close();
	int cont=0,puntuacion=0;
	do{
		system("cls");
	  srand(time(NULL));
	  char opcion;
	  int a = rand()%paisa.size();
  
	  int op = rand()%(4-1);
	 
	cout<<"Ingrese cual cree que es la capital correcta con 1 2 3 4"<<endl;
      cout<<paisa[a].get_Pais()<<endl<<endl;
      	
    for(int i =0 ;i<4;i++){
    	if(op==i){
    		cout<<i+1<<")"<<paisa[a].get_Capital()<<endl;
		}else{
				cout<<i+1<<")"<<paisa[rand()%paisa.size()].get_Capital()<<endl;
		} 	   
	}
	
	int opc;
	cin>>opc;
	if(opc==op+1){
		cout<<"CORRECTO"<<endl;
		puntuacion++;
	}else{
		cout<<"INCORRECTO :C"<<endl;
	}
	cont++;
	system("pause");
	}while(cont!=10);
	
	cout<<"Ingrese nombre"<<endl;
	string nombre;
	fflush(stdin);
	cin>>nombre;
	string point =static_cast<std::ostringstream*>(&(std::ostringstream() << puntuacion))->str();
	string total = nombre + "," + point ;
	fstream ing;
	ing.open("Score.txt",ios::app);
	if(ing.fail()){
		cout<<"Fallo"<<endl;
	}else{
		ing<<total<<"\n";
	}
	ing.close();
}

void listaPaises(){
	
	//Continente Numero
	fstream arch;
	Continente mostrar;
	arch.open("Continente.dat", ios::binary | ios::in);
	if(arch.fail()){
		cout<<"Error"<<endl;
	}else{
		while(true){
			arch.read((char*)&mostrar,sizeof(Continente));
			if(arch.eof()) break;
			
		}
	}
	arch.close();
	//3
	vector <Pais> paisa;
	fstream archivo;
	archivo.open("Pais.txt",ios::in);
	string lineas;
	char *separa;
	if(archivo.fail()){
		cout<<"error"<<endl;
	}
	else{
		string capital;
		while(getline(archivo,lineas)){
			separa = strtok(&lineas[0],";");
			int codigo = atoi(separa);
			separa = strtok(NULL,";");
			string pais = (string)separa; 
			separa = strtok(NULL,";");
			string capital = (string)separa; 
			separa = strtok(NULL,";");
//		cout<<"Codigo:"<<codigo<<" Pais:"<<pais<<" Capital:"<<capital<<endl;
		Pais pp(codigo,pais,capital);
		paisa.push_back(pp);
		}
	}
	archivo.close();
	
	
	vector <Poblacion> p;
	fstream file;
	file.open("Poblacion.txt",ios::in);
	string linea;
	char *separar;
	if(file.fail())
	cout<<"Error al abrir el archivo"<<endl;
	else{
		string cantidad;
		string pais;
		while(getline(file,linea)){
			
			separar=strtok(&linea[0],";");	
			string pais = (string)separar;
			separar = strtok(NULL,";");
			cantidad =  (string)separar;
			
			Poblacion pa(pais,cantidad);
			pa.Imprimir();
			p.push_back(pa);
			
		}
	}
	

//	ShellMejorado(string p);

	string nombre;
	file.close();
	system("pause");
	system("cls");
	cout<<"Ingrese el nombre del Pais a consultar"<<endl;
	cin>>nombre;
	for(int i =0 ;i<p.size();i++){
		if(p[i].get_Pais()==nombre){
			p[i].Imprimir();
		}
	}
	
		for(int j=0; j<paisa.size();j++){
		if(paisa[j].get_Pais()==nombre){	
			paisa[j].imprimir();
		}
	}
			
	}
	
	void listCountry(){
		
//	vector <Paiss> paisa;
//	fstream archivo;
//	archivo.open("Pais.txt",ios::in);
//	string lineas;
//	char *separa;
//	if(archivo.fail()){
//		cout<<"error"<<endl;
//	}
//	else{
//		string capital;
//		while(getline(archivo,lineas)){
//			separa = strtok(&lineas[0],";");
//			char codigo2[20];
//			string codigo = (string)separa;
//			strcpy(codigo2,codigo.c_str());
//			separa = strtok(NULL,";");
//			char pais2[20];
//			string pais = (string)separa; 
//			strcpy(pais2,pais.c_str());
//			separa = strtok(NULL,";");
//			char capital2[80];
//			string capital = (string)separa; 
//			strcpy(capital2,capital.c_str());
//			separa = strtok(NULL,";");
//		cout<<"Codigo:"<<codigo<<" Pais:"<<pais<<" Capital:"<<capital<<endl;
//		strcpy(code,codigo.c_str());
//		cout<<capital2<<endl;
//		Paiss pp(codigo2,pais2,capital2);
//		paisa.push_back(pp);
//		pp.imprimir();
//		}
//	}
//	archivo.close();
//	archivo.open("data.dat",ios::out | ios::binary);
//	for(int i=0; i<paisa.size();i++)
//		archivo.write((char*) &paisa[i], sizeof(Paiss));			
//	archivo.close();
	
	
	
	fstream archivo ("data.dat",ios::in | ios::binary);
	vector<Paiss>lista;
	
	while(true){
		Paiss temp;
		archivo.read((char*)&temp,sizeof(Paiss));
		if(archivo.eof())break;
		lista.push_back(temp);
	}
	
	archivo.close();
	int tam=lista.size();
	cout<<"-------"<<endl;
	
	MezclaDirecta<Paiss> ordenar("data.dat");
	ordenar.Ordenar(tam);
	
	archivo.open("data.dat", ios::in | ios::binary);
	lista.clear();

	while(true) {
		Paiss temp;
		archivo.read((char*) &temp, sizeof(Paiss));
		if (archivo.eof())
			break;
		lista.push_back(temp);
		temp.imprimir();
	}	
}
	
	
template <class T>
void ShellMejorado(vector<T> &v) {
	bool band;
	int inc = v.size()/2;
	T aux;
	
	while (inc > 0){
		band = false;
		for (int i = 0; i+inc < v.size(); i++) {
			if (v[i] > v[i+inc]) {
				aux = v[i];
				v[i] = v[i+inc];
				v[i+inc] = aux;
				band = true;
			}
		}
		if (!band)
			inc /= 2;
	}
}

void visualizar(){
	
	fstream arch;
	Continente mostrar;
	arch.open("Continente.dat", ios::binary | ios::in);
	if(arch.fail()){
		cout<<"Error"<<endl;
	}else{
		while(true){
			arch.read((char*)&mostrar,sizeof(Continente));
			if(arch.eof()) break;
			//mostrar.imprimir();
		}
	}
	arch.close();
	
	
	
		vector <Pais> paisa;
	fstream archivo;
	archivo.open("Pais.txt",ios::in);
	string lineas;
	char *separa;
	if(archivo.fail()){
		cout<<"error"<<endl;
	}
	else{
		string capital;
		while(getline(archivo,lineas)){
			separa = strtok(&lineas[0],";");
			int codigo = atoi(separa);
			separa = strtok(NULL,";");
			string pais = (string)separa; 
			separa = strtok(NULL,";");
			string capital = (string)separa; 
			separa = strtok(NULL,";");
		Pais pp(codigo,pais,capital);
	//	pp.imprimirCode();
		paisa.push_back(pp);
		}
	}
	//ID
	archivo.close();
	
	
	vector <Poblacion> p;
	fstream file;
	file.open("Poblacion.txt",ios::in);
	string linea;
	char *separar;
	if(file.fail())
	cout<<"Error al abrir el archivo"<<endl;
	else{
		string cantidad;
		string pais;
		while(getline(file,linea)){
			
			separar=strtok(&linea[0],";");	
			string pais = (string)separar;
			separar = strtok(NULL,";");
			cantidad =  (string)separar;
			
			Poblacion pa(pais,cantidad);
		//	pa.Imprimir();
			p.push_back(pa);
			
		}
	}
	file.close();
	
	for(int i = 0 ; i<paisa.size();i++){
		int c=0;
		if(paisa[i].get_codigo()==15){
			for(int j=0;j<p.size();j++){
				if(paisa[i].get_Pais()==p[j].get_Pais()){
					char a[80];
					strcpy(a,p[j].get_Cantidad().c_str());
					char b[80];
					int j=0;
					for(int i =0 ;a[i]!=0;++i){
						if(a[i] != 32){
	  					 b[j]=a[i];
    					  j++;
		 			}
					}
						c = atoi(b);
						//paisa[i] pais-----c poblacion
					
					fstream arch;
					arch.open("Africa.dat",ios::binary| ios::app);
						
					Sector agr;
					string nombre,pob;
					pob = c;
					nombre=paisa[i].get_Pais();
					agr.set_Pais(&nombre[0]);
					agr.set_poblacion(&pob[0]);
					arch.write((char*)&agr,sizeof(Sector));
					arch.close();
					
					//cout<<paisa[i].get_Pais()<<" "<<c<<endl;
				}
			}
		}else if(paisa[i].get_codigo()==23){
						for(int j=0;j<p.size();j++){
				if(paisa[i].get_Pais()==p[j].get_Pais()){
					char a[80];
					strcpy(a,p[j].get_Cantidad().c_str());
					char b[80];
					int j=0;
					for(int i =0 ;a[i]!=0;++i){
						if(a[i] != 32){
	  					 b[j]=a[i];
    					  j++;
		 			}
					}
						c = atoi(b);
						//paisa[i] pais-----c poblacion
						fstream arch;
					arch.open("America.dat",ios::binary| ios::app);
						
					Sector agr;
					string nombre,pob;
					pob = c;
					nombre=paisa[i].get_Pais();
					agr.set_Pais(&nombre[0]);
					agr.set_poblacion(&pob[0]);
					arch.write((char*)&agr,sizeof(Sector));
					arch.close();
				//	cout<<paisa[i].get_Pais()<<" "<<c<<endl;
				}
			}
			
		}else if(paisa[i].get_codigo()==32){
							for(int j=0;j<p.size();j++){
				if(paisa[i].get_Pais()==p[j].get_Pais()){
					char a[80];
					strcpy(a,p[j].get_Cantidad().c_str());
					char b[80];
					int j=0;
					for(int i =0 ;a[i]!=0;++i){
						if(a[i] != 32){
	  					 b[j]=a[i];
    					  j++;
		 			}
					}
						c = atoi(b);
						//paisa[i] pais-----c poblacion
						fstream arch;
					arch.open("Europa.dat",ios::binary| ios::app);
						
					Sector agr;
					string nombre,pob;
					pob = c;
					nombre=paisa[i].get_Pais();
					agr.set_Pais(&nombre[0]);
					agr.set_poblacion(&pob[0]);
					arch.write((char*)&agr,sizeof(Sector));
					arch.close();
				//	cout<<paisa[i].get_Pais()<<" "<<c<<endl;
				}
			}
		}else if(paisa[i].get_codigo()==27){
								for(int j=0;j<p.size();j++){
				if(paisa[i].get_Pais()==p[j].get_Pais()){
					char a[80];
					strcpy(a,p[j].get_Cantidad().c_str());
					char b[80];
					int j=0;
					for(int i =0 ;a[i]!=0;++i){
						if(a[i] != 32){
	  					 b[j]=a[i];
    					  j++;
		 			}
					}
						c = atoi(b);
						//paisa[i] pais-----c poblacion
						fstream arch;
					arch.open("Asia.dat",ios::binary| ios::app);
						
					Sector agr;
					string nombre,pob;
					pob = c;
					nombre=paisa[i].get_Pais();
					agr.set_Pais(&nombre[0]);
					agr.set_poblacion(&pob[0]);
					arch.write((char*)&agr,sizeof(Sector));
					arch.close();
				//	cout<<paisa[i].get_Pais()<<" "<<c<<endl;
				}
			}
			
		}else if(paisa[i].get_codigo()==45){
								for(int j=0;j<p.size();j++){
				if(paisa[i].get_Pais()==p[j].get_Pais()){
					char a[80];
					strcpy(a,p[j].get_Cantidad().c_str());
					char b[80];
					int j=0;
					for(int i =0 ;a[i]!=0;++i){
						if(a[i] != 32){
	  					 b[j]=a[i];
    					  j++;
		 			}
					}
						c = atoi(b);
						//paisa[i] pais-----c poblacion
						fstream arch;
					arch.open("Oceania.dat",ios::binary| ios::app);						
					Sector agr;
					string nombre,pob;	
					pob=b;
					
					nombre=paisa[i].get_Pais();
					agr.set_Pais(&nombre[0]);
					agr.set_poblacion(&pob[0]);
					arch.write((char*)&agr,sizeof(Sector));
					arch.close();
					//cout<<paisa[i].get_Pais()<<" "<<c<<endl;
				}
			}			
		}
	}
	
//			Sector sect;
//	fstream ar;
//	ar.open("Asia.dat",ios::binary | ios::in);
//	if(ar.fail()){
//		cout<<"error"<<endl;
//	}else{
//		while(true){
//			ar.read((char*)&sect,sizeof(Sector));
//			if(ar.eof())break;
//			sect.imprimir();
//		}
//	}
//	ar.close();
	

	 }
	 



	




