#ifndef ASIGNACION_H
#define ASIGNACION_H
#include "Ruta.h"
#include "Bus.h"
class Asignacion
{
	Ruta * ruta;
	Bus * bus;
	public:
		Asignacion();
		Asignacion(Ruta *ruta,Bus * bus);
		
		string getCodLlegada();
		string getCodSalida();
		string getHoraSalida();
		
		~Asignacion();
		
		Ruta* getRuta();
		Bus* getBus();
	protected:
};

#endif
