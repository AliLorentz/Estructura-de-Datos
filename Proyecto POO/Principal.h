#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include "Ciudad.h"
#include "Ruta.h"
#include "Pasajero.h"
#include "Boleto.h"
#include "Asignacion.h"
#include "Bus.h"

using namespace std;
class Principal
{
	Ciudad **ciudad;
	int cantCiudad;
	
	Ruta **rutas;
	int cantRutas;
	
	Pasajero **pasajero;
	int cantPasajero;
	
	Boleto * *boleto;
	int cantBoleto;
	
	Asignacion ** asignaciones;
	int cantAsignaciones;
	
	Bus ** bus;
	int cantBus;
	
	
	public:
		Principal();
		void Menu();
		void comprarBoleto();
		void agregarPasajero();
		void addPasajero(Pasajero *p);
		void agregarBus();
		void asignarBusaRuta();
		void mostrarBuses();
		void mostrarRutas(bool asignar);
		void addBus(Bus * bus);
		void addBoleto(Boleto *b);
		void addAsignacion(Asignacion *a);
		void resetMenu();
		~Principal(){	cout<<"ELIMINAR"<<endl;}
	protected:
};

#endif
