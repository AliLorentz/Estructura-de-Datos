#include <iostream>
#include "Bicola.h"
#include "Vuelos.h"
#include "ListaCirDob.h"

#include "Final.h"
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <string>
//Segundo Parcial
using namespace std;

void recorrido(int lugar);

int main(int argc, char** argv) {
	//Aqui Colocamos las avionetas en una bicola
	Bicola <string>b;
	fstream archivo("aeronaves.txt",ios::in);
	if(archivo.fail())
	cout<<"Error a la lectura";
	else{
		string linea;
		bool band=false;
		while(getline(archivo,linea)){
			if(band==true){
				b.push_back(linea);
				band=false;
			}else{
				b.push_front(linea);
				band=true;
			}
			
		}
	}
	archivo.close();
	cout<<"------------------DEPOSITO DE HANGAR-------------------------------"<<endl;
	b.print();
	//Aqui decidiremos si salen por la parte frontal o por la parte trasera
	//Adelante 1 atras 0
	int pos=0;
	while(pos!=1 && pos!=2){
		cout<<"\n\nEscoga como saldran los aviones: "<<endl<<"1-Alante"<<" 2-Atras: ";
		cin>>pos;
	}
	


	if(pos==1){
		cout<<"Se Escogio la puerta de ALANTE como salida principal"<<endl;
	//	b.pop_front();
	}else if(pos==2){
		cout<<"Se Escogio la puerta de ATRAS como salida principal"<<endl;
	//	b.pop_back();
	}
	//
	//Destinos
	
	fstream archivos("destinos.txt",ios::in);
	if(archivos.fail())
	cout<<"Nope"<<endl;
	else{
		string linea;
		char *separar;
		string x,y;
		int xz;
		while(getline(archivos,linea)){
			xz=0;
			separar=strtok(&linea[0],","); //1 cod // 2 destino
			while(separar){
				xz++;
			x=separar;
			//cout<<x<<" "<<xz<<endl;
			separar=strtok(NULL,",");
			if(xz==1){
			y=x;
			}else if(xz==2){
				Final ff(y,x);
				//ff.imprimir();
			}
				}
		}
	}
	
	//Aqui saco aviones y asigno vuelos
	//vuelos numero de vuelo, destino,pasajeros
	fstream datos("vuelos.txt",ios::in);
	if(datos.fail())
	cout<<"Error en la lectura";
	else{
		string linea;
		char*separar;
		string x;
		int nv,des,pasa,xz;
		while(getline(datos,linea)){
			xz=0;
			//cout<<linea;
			separar=strtok(&linea[0],",");
		while(separar){
			xz++;
					x=separar;
			int c=atoi(x.c_str());
			separar=strtok(NULL,",");
			if(xz==1){
				nv=c;
			}if(xz==2){
				des=c;
			}if(xz==3){
				pasa=c;
			}
		}
					cout<<"Numero de vuelos del avion: "<<nv<<"| Codigo de destino: #"<<des<<"| Pasajeros:"<<pasa;
					if(pos==1){				
					cout<<" Cod Avion: "<<b.pop_front()<<endl;
					}
					else if(pos==2){
						cout<<" Cod Avion: "<<b.pop_back()<<endl;
					}else if(b.isEmpty()){ //POR SI NO QUEDAN MAS AVIONES EN EL HANGAR
						cout<<"No quedan mas aviones disponbibles"<<endl;
						break;
					}
					
					
					recorrido(des);
					cout<<"------------------------------------------------------------------------"<<endl;
		}
	}
	datos.close();
		
	
		cout<<"\n------------------------AVIONES DISPONIBLES-------------------------"<<endl;
		b.print();
	
	return 0;
}

void recorrido(int lugar){
	//separamos los datos de los recorridos
		ListaCirDob<int>list1,list2;
			ListaCirDob<int>list3;
		fstream archivo("recorrido.txt",ios::in);	
		if(archivo.fail())	
		cout<<"El archivo fallo al abrir"<<endl;
		else{
			int xz=0;
			string linea;
			char *separar;
			string x;
		while(getline(archivo,linea)){
	
			separar=strtok(&linea[0],",");
			xz=0;
			while(separar){
				xz++;
				x=separar;
				int c =atoi(x.c_str()); //cout<<c<<"-"<<xz<<"-"<<endl; //hacemos la tranformacion a int de los datos
				separar = strtok(NULL, ",");
				if(xz==1){
					list1.agregar(c);
				}else if(xz==2){
					list2.agregar(c);
				}else if(xz==3){
					list3.agregar(c);
				}
			}
			
		}	
		}
		int busquedad=lugar,km1=0,km2=0;
			do{
		
			km1+=list2.getInfoVisit();
			list2.mover(1,false);
			list1.mover(1,false);
	}while(list1.getInfoVisit()!=busquedad);				
			//calculamos de ida
			list1.reset();
			list2.reset();
			
			do{
			km2+=list3.getInfoVisit();
			list3.mover(0,true);
			list1.mover(0,true);				
			}while(list1.getInfoVisit()!=busquedad);
		//	cout<<endl<<km2;
		if(km1<km2){
			cout<<"El recorrido mas corto es girar el avion hacia la derecha"<<endl;
			cout<<km1<<"KM"<<endl;
		}else{
			cout<<"El recorrido mas corto es girar el avion hacia la izquierda"<<endl;
			cout<<km2<<"KM"<<endl;
		}

	}

