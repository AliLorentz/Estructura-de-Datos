#ifndef BOLETO_H
#define BOLETO_H
#include "Asignacion.h"
#include "Pasajero.h"

class Boleto
{
	int numero;
	Pasajero *pasajero;
	Asignacion * asignacion;
	int codigoVerificacion;
	
	public:
		Boleto();
		Boleto(int,Pasajero *pasajero, Asignacion * asignacion);
		~Boleto();
		void generarCodigo();
		void emitirBoleto();
		
		Pasajero *getPasjaero(){	return this->pasajero;	}
		Asignacion *getasignacion(){	return this->asignacion;	}
		int getNumeroBoleto (){return numero;}
		int getCodigoVerificacion(){	return codigoVerificacion;	}
		
		
		
	protected:
};

#endif
