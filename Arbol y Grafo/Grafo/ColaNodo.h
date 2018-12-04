#ifndef COLANODO_H
#define COLANODO_H

#include <iostream>
#include "Nodo.h"

using namespace std;

template <class T>
class ColaNodo {
	
	Nodo<T> *frente, *fin;
	
	public :
		
		ColaNodo () { frente = NULL; fin = NULL; }
		int agregar(T );
		int eliminar(T &);
		void imprimir();
		bool isVacia() { return ( frente == NULL );}
		
};

template <class T>
int ColaNodo<T> :: agregar(T dato) {
	Nodo<T> *nuevo = new Nodo<T> (dato);
	
	if ( !nuevo ) return 0;
	
	if ( !frente ) 
		frente = nuevo;	
	else 
		fin -> setSiguiente(nuevo);
	
	fin = nuevo;
	return 1;
}

template <class T>
int ColaNodo<T> :: eliminar(T &dato) {
	Nodo<T> *p;
	if ( !frente ) return 0;
	
	dato = frente -> getDato();
	
	p = frente;
	
	if (frente == fin)
		frente = fin = NULL;
	else		
		frente = frente -> getSiguiente();
	
	delete p;
	return 1;
}

template <class T>
void ColaNodo<T> :: imprimir() {
	Nodo<T> *p;
	
	p = frente;
	cout << endl;
	
	while ( p ) {
		cout << p -> getDato() << " -> ";
		p = p -> getSiguiente();
	}
	cout << " NULL.";
}
#endif
