#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Persona {
		int ced;
		char nom[30];
	public:
		Alumno() { ced = 0; }
		Alumno( char *n, int c ) { strcpy(nom, n); ced = c;}
		int get_clave(int flag) { return ced; }
		char *get_nom() { return nom; }
		void set_nom(char *n) { strcpy(nom, n); }
		void set_ced(char *n) { ced = atoi(n); }
		void imprimir() { std::cout << nom << " " << ced << std::endl; }
		bool operator>(const Persona& datos){ 
			return (this->ced > datos.ced);
		}
		
	friend ostream &operator <<(ostream &o, const Persona &p) {
		o << p.nom << " " << p.ced << endl;
		return o;
	}
};



#endif
