#ifndef PILANODO_H
#define PILANODO_H

#include <iostream>
#include "Nodo.h"
using namespace std;

template <class T>
class PilaNodo {
	
	Nodo<T> *tope;
	
	public:
	
	PilaNodo() { tope = NULL; }
	int agregar(T );
	int eliminar(T &);
	void imprimir();
	bool isVacia() { return (tope == NULL); }
	//otros
};

template <class T>
int PilaNodo<T> :: agregar(T dato) {
	Nodo<T> *nuevo = new Nodo<T> (dato);

	if(!nuevo) return 0;

	nuevo -> setSiguiente(tope);
	tope = nuevo;
}

template <class T>
int PilaNodo<T> :: eliminar(T &dato) {
	Nodo<T> *p;
	
	if(!tope) return 0;
	
	p = tope;
	dato = p -> getDato();
	tope = tope -> getSiguiente();
	p -> setSiguiente(NULL);
	
	delete p;
	return 0;
}

template <class T>
void PilaNodo<T> ::imprimir() {
	Nodo<T> *p;
	p = tope;
	
	cout << endl << "tope -> ";
	
	while ( p ) {
		cout << p -> getDato() << " -> ";
		p = p -> getSiguiente();
	}
	
	cout << " NULL." << endl;
}

#endif
