#ifndef LISTASIMPLEENLAZADA_H
#define LISTASIMPLEENLAZADA_H

#include <iostream>
#include "Nodo.h"
using namespace std;

template <class T>
class ListaSimpleEnlazada {
	
	Nodo<T> *cab;
	int size;
	public :
	
	ListaSimpleEnlazada(){ cab = NULL ; size = 0; }
	Nodo<T> *get_cab(){ return cab;}
	int agregar(T );
	int agregar(T , bool );
	int eliminarDato(T );
	int eliminar(T &);
	void imprimir();
	bool isVacia() { return (cab == NULL);}
	void vaciar();
	int buscar(T &ele);
	int getSize() { return size; }
	//otros	
};

template <class T>
int ListaSimpleEnlazada<T> :: agregar(T ele) {
	Nodo<T> *nuevo, *p, *ant;
	nuevo = new Nodo<T> (ele);
	p = cab;
	ant = NULL;
	
	if(nuevo == NULL) return 0;
	
	while (p != NULL) {
		ant = p;
		p = p -> getSiguiente(); 
	}
	
	if(p == cab) { //caso 1: inserccion cad
		nuevo -> setSiguiente(cab);
		cab = nuevo;
	} else { //caso 2: inserccion != cad
		nuevo -> setSiguiente(p);
		ant -> setSiguiente(nuevo);
	}
	size++;
	return 1;
}

template <class T>
int ListaSimpleEnlazada<T> :: agregar(T ele, bool ord) {
	Nodo<T> *nuevo, *p, *ant;
	nuevo = new Nodo<T> (ele);
	p = cab;
	ant = NULL;
	
	if(nuevo == NULL) return 0;
	
	while (p != NULL) {
		if ( ord ) {//asendente
			if (nuevo -> getDato() <= p -> getDato())
				break;
			else {
				ant = p;
				p = p -> getSiguiente(); 
			}	
		} else { //desendente
			if (nuevo -> getDato() >= p -> getDato())
				break;
			else {
				ant = p;
				p = p -> getSiguiente(); 
			}
		}

	}
	
	if(p == cab) { //caso 1: inserccion cad
		nuevo -> setSiguiente(cab);
		cab = nuevo;
	} else { //caso 2: inserccion != cad
		nuevo -> setSiguiente(p);
		ant -> setSiguiente(nuevo);
	}
	size++;
	return 1;
}

template <class T>
int ListaSimpleEnlazada<T> :: eliminarDato(T dato) {
	Nodo<T> *p, *ant;
	p = cab;
	ant = NULL;
	
	if (cab == NULL) return 0;
	
	while (p != NULL) {
		if (p -> getDato() == dato) 
			break;
		else {
			ant = p;
			p = p -> getSiguiente();
		}
	}
	
	if(p == NULL)
		return 0;
	else if(ant == NULL){
		cab = cab -> getSiguiente();
		delete p;
	} else {
		ant -> setSiguiente(p -> getSiguiente());
		delete p;
		
	}
	size--;
	return 1;
}

template <class T>
int ListaSimpleEnlazada<T> :: eliminar(T &dato) {
	Nodo <T> *p;
	
	if(cab == NULL) return 0;
	
	p = cab;
	dato  = p -> getDato();
	cab = cab -> getSiguiente();
	size--;
	delete p;
	return 1;
}

template <class T>
void ListaSimpleEnlazada<T> :: imprimir() {
	ListaSimpleEnlazada obj;
	cout << obj.getSize();
	
	Nodo<T> *aux = cab;
	cout << endl;
	while (aux) { //si aux tiene una direccion es true y si es igual null es falso
		cout << " " << aux -> getDato() << " ->";
		aux = aux -> getSiguiente();
	}
	//cout << " NULL";
}

template <class T>
void ListaSimpleEnlazada<T> :: vaciar() {
	Nodo<T> *p;
	
	if(cab == NULL) return;
	
	while (cab != NULL) {
		p = cab;
		cab = cab -> getSiguiente();
		delete p;
		this->imprimir();
	}
}

template <class T>
int ListaSimpleEnlazada<T> :: buscar(T &ele) {
	Nodo<T> *p;
	
	if (cab == NULL) return -1;
	p = cab;
	for(int i = 0; i < size; i++) {
		if (p->getDato() == ele){
			ele = p->getDato();
			return 1;
		}
		p = p->getSiguiente();
	}
	return 0;
}
#endif
