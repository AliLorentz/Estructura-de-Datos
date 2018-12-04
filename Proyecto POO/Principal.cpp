#include "Principal.h"
#include <iostream>
#include "string.h"
#include "stdlib.h"
#include "Confort.h"
#include "Plus.h"

using namespace std;

Principal::Principal()
{
	this->cantCiudad=4;
	this->ciudad = new Ciudad*[this->cantCiudad];
	this->ciudad[0] = new Ciudad("BOGOTA","BOG");
	this->ciudad[1] = new Ciudad("CUCUTA","CUC");
	this->ciudad[2] = new Ciudad("CALI","CAL");
	this->ciudad[3] = new Ciudad("CARTAGENA","CAR");
	
	
	this->cantRutas=6;

	rutas =  new Ruta * [this->cantRutas];
	this->rutas[0] = new Ruta(this->ciudad[0] , this->ciudad[1] , "1900");
	this->rutas[1] = new Ruta(this->ciudad[0] , this->ciudad[2] , "1830");
	this->rutas[2] = new Ruta(this->ciudad[3] , this->ciudad[1] , "1700");
	this->rutas[3] = new Ruta(this->ciudad[2] , this->ciudad[3] , "1080");
	this->rutas[4] = new Ruta(this->ciudad[1] , this->ciudad[3] , "1010");
	this->rutas[5] = new Ruta(this->ciudad[2] , this->ciudad[0] , "1601");
	
	
	this->bus=NULL;
	this->cantBus=0;
	
	this->pasajero=NULL;
	this->cantPasajero=0;
	
	this->boleto=NULL;
	this->cantBoleto=0;
	
	this->asignaciones=NULL;
	this->cantAsignaciones=0;
	

}

void Principal::Menu(){
	int opcion=0;
	bool escoger = false;
	do{
	cout<<"Bienvenido a berlinas"<<endl;
	cout<<"\n1)-Ingresar bus"<<endl;
	cout<<"\n2)-Agregar bus a ruta"<<endl;
	cout<<"\n3)-Agregar pasajero"<<endl;
	cout<<"\n4)-ComprarBoleto"<<endl;
	cout<<"\n5)-Salir"<<endl<<endl;
	cin>>opcion;
	
	escoger=false;
	switch(opcion){
			case 1:
				agregarBus();
			break;
			case 2:
				asignarBusaRuta();
			break;
			case 3:
			agregarPasajero();
			break;
			case 4:
			comprarBoleto();
			break;
			case 5:
			cout<<"\n\n\tGracias por escogernos"<<endl;
			exit(0);
			default:
		
				cout<<"Intentalo de nuevo";	
				escoger=true;
			break;
			
	
	}
	
	system("cls");
	}while(escoger==true);


}

void Principal::comprarBoleto(){
	cout<<"Ingrese Cedula"<<endl;
	string cedula;
	cin>>cedula;
	int i;
	bool encontrado = false;
	for( i =0;i<this->cantPasajero;i++){
		if(this->pasajero[i]->getCedula()==cedula){
			encontrado=true;
			break;
		}
	}
	
	if(!encontrado){
		cout<<"No se encontro a nadie"<<endl;
		this->resetMenu();
	}

	
	this->pasajero[i]->imprimir();
	
	string salida ,llegada;
	cout<<"Indice el codigo de salida"<<endl;
	cin>>salida;
	cout<<"Indique el codigo de salida de la ciudad"<<endl;
	cin>>llegada;
	int cont =0;
	for(int k=0; k<this->cantAsignaciones;k++){			
		if(this->asignaciones[k]->getCodSalida() ==salida && this->asignaciones[k]->getCodLlegada()==llegada){
			if (cont==0){
				cont++;
				cout<<"Horarios disponibles"<<endl;
				cout<<k+1<<")"<<this->asignaciones[i]->getHoraSalida()<<endl;
			}		
		}
	}
	if(cont==0){
		cout<<"Horarios no disponibles"<<endl;
		this->resetMenu();
	}
	int opcHorario;
	do{
		cout<<"Seleccione un horario"<<endl;
		cin>>opcHorario;
		
	}while(opcHorario<0 || opcHorario>cont);
	
	cont=0;
	int p;
	
	for(p=0;p<this->cantAsignaciones;p++){
		if(this->asignaciones[p]->getCodSalida()==salida && this->asignaciones[p]->getCodLlegada()==llegada)
		{
			cont++;
			if(cont==opcHorario)break;
		}
	}
	
	Boleto *boleto = new Boleto(this->cantBoleto,this->pasajero[i],this->asignaciones[p]);
	this->addBoleto(boleto);
	boleto->generarCodigo();
	boleto->emitirBoleto();
	this->resetMenu();
	
}

/*

	Boleto *boleto = new Boleto(this->cantBoletos , this->asignaciones[p] , this->pasajeros[i]);
	this->addBoleto(boleto);
	boleto->emitirBoleto();
	
	cout<<"Boleto comprado con exito!"<<endl;
	this->volverMenu();
}*/

void Principal::addBoleto(Boleto *b){
	this->cantBoleto++;
	Boleto **auxBoletos=this->boleto;
	
	this->boleto = new Boleto *[this->cantBoleto];
	for(int i =0 ;i< this->cantBoleto-1;i++){
		this->boleto[i]=auxBoletos[i];
	} 
	
	this->boleto[this->cantBoleto-1]=b;
}

void Principal::agregarPasajero(){
	string cedula , nombre , apellido;
	cout<<"Cedula:"<<endl;
	cin>>cedula;
	cin.sync();
	
	cout<<"Nombre: "<<endl;
	cin>>nombre;
	cin.sync();
	
	cout<<"Apellido: "<<endl;
	cin>>apellido;
	cin.sync();
	
	Pasajero *pasajero = new Pasajero(cedula,nombre,apellido);
	this->addPasajero(pasajero);
	cout<<"\nPasajero agregado con exito!"<<endl;
	this->resetMenu();
}

void Principal::addPasajero(Pasajero *p){
	this->cantPasajero++;
	Pasajero **auxPasajero = this->pasajero;
	this->pasajero = new Pasajero * [this->cantPasajero];
	for(int i =0;i<this->cantAsignaciones-1;i++){
		this->pasajero[i] = auxPasajero[i];
	}
	this->pasajero[this->cantPasajero-1]=p;
}

void Principal::asignarBusaRuta(){
	if(this->cantBus==0){
		cout<<"Pimero ingrese un bus al sistema"<<endl;
		this->resetMenu();
	}
	this->mostrarBuses();
	int opc;
	do{
		cout<<"Seleccione algun bus"<<endl;
		cin>>opc;
	}while(opc < 1 || opc > this->cantBus);
	
	this->mostrarRutas(true);
	int opcRuta;
	do{
		cout<<"Selecciona alguna ruta "<<endl;
		cin>>opcRuta;
		
	}while(opcRuta<1 || opcRuta > this->cantRutas);
	opcRuta-=1;
	Asignacion * asignacion = new Asignacion(this->rutas[opcRuta],this->bus[opc]);
	this->addAsignacion(asignacion);
	cout<<"Asignacion Realizada con exito!"<<endl;
	this->resetMenu();
}

void Principal::addAsignacion(Asignacion *a){
	
		this->cantAsignaciones++;
		Asignacion **auxAsignaciones = this->asignaciones;
		
		this->asignaciones = new Asignacion * [this->cantAsignaciones];
	
		for ( int i = 1; i < this->cantAsignaciones ; i++){
			this->asignaciones[i] = auxAsignaciones[i];
		}
		
		this->asignaciones[this->cantAsignaciones-1] = a;		
		
}

void Principal::mostrarRutas(bool asignar){
	cout<<"\t\t Rutas"<<endl;
	cout<<"SALIDA\tLLEGADA\tHORA\tCODIGO"<<endl;
	cout<<"______________________________________________________________"<<endl;
	for(int i=0;i<this->cantRutas;i++){
		if(asignar)
		cout<<"Ruta"<<i+1<<endl;
		this->rutas[i]->imprimir();
		cout<<"_______________________________________________________"<<endl;
		
	}
	if(!asignar)
	this->resetMenu();
	
}

void Principal::mostrarBuses(){
	system("cls");
	for(int i=0;i<this->cantBus;i++){
		cout<<"___________________________________"<<endl;
		cout<<"Bus numero "<<i+1<<endl;
		this->bus[i]->imprimir();
		cout<<"___________________________________"<<endl;
	}
}

void Principal::agregarBus(){
	system("cls");
	bool bandera = false;
	int opcion;
	do{
	cout<<"1-Confort"<<endl;
	cout<<"2-Plus"<<endl;
	cin>>opcion;
	if(opcion == 1 || opcion==2)
		bandera=true;
	}while(bandera==false);
	
	short int control;
	string nombreConductor;
	
	cout<<"Nombre Conductor: ";
	cin>>nombreConductor;
	cout<<"Control: ";
	cin>>control;
	
	
	Bus *bus =NULL;
	bool servicio;
	
	if(opcion==1){
		char var;
		cout<<"\n Posee servicio de baño? y/n"<<endl;
		cin>>var;
		
		servicio = (var=='y');
	
	Confort *aux = new Confort(control,nombreConductor,servicio);
	bus = (Bus *) aux;
		
	}else{
		char var;
		cout<<"\n Posee servicio de pantalla? y/n"<<endl;
		cin>>var;
		
		servicio = (var=='y');
		
	Plus *aux = new Plus(control,nombreConductor,servicio);
	bus = (Bus*)aux;
	}
	
	this->addBus(bus);
	this->resetMenu();
	
}


void Principal::addBus(Bus *bus){
		this->cantBus++;
		Bus **auxBuses = this->bus;
		
		this->bus = new Bus * [this->cantBus];
		
		for ( int i = 0; i < this->cantBus-1 ; i++){
			this->bus[i] = auxBuses[i];
		}
		
		this->bus[this->cantBus-1] = bus;
	
}

void Principal::resetMenu(){
	system("pause");
	system("cls");

	this->Menu();
}






