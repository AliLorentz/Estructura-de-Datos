#ifndef PERSONA_H
#define PERSONA_H

#include <string.h>

using namespace std;
class Persona{
	int cedula;
	char apellido[20];
	char apellido2[20];
	char nombre[20];
	char nombre2[20];
	int codigo;
	char vacio[10];
	public:
		Persona(){}
		Persona(int ced, char *ape, char *ape2, char *nom, char *nom2, int cod, char *va){
			this->cedula = ced;
			strcpy(this->apellido, ape);
			strcpy(this->apellido2, ape2);
			strcpy(this->nombre, nom);
			strcpy(this->nombre2, nom2);
			this->codigo = cod;
			strcpy(this->vacio,va);
			
		}
		
		friend ostream& operator<<(ostream& os, const Persona& datos){
			os<<"Cedula: "<<datos.cedula<<"\nApellido: "<<datos.apellido<<"      2do-Apellido: "<<datos.apellido2<<" \nNombre: "<<datos.nombre<<"      2do-Nombre: "<<
			datos.nombre2<<" \nCodigo: "<<datos.codigo<<"  Basura: "<<datos.vacio<<endl;  
			return os;
		}
		void mostrar(){
			cout<<nombre<<" "<<apellido<<endl;
		}
		
		int getCedula(){return cedula;}
	
	
};

#endif

