	#include <iostream>
using namespace std;

//********************************************************** Clase Cola_Circular *****************************************************************
template <class T>
class Cola_Circular {
	
	private:
		T * array;
		int inicio;
		int final;
		int tamano_cola;
	
	public:
		Cola_Circular(int tamano_cola);
		bool Esta_Vacia();
		bool Esta_Llena();
		void Anadir(T valor);
		T Leer();
		void Eliminar();
		void Ordenar_Cola();
		void Imprimir();
};

//**********************************************************
template <class T> 
Cola_Circular<T>::Cola_Circular(int tamano_cola) {
	this->tamano_cola = tamano_cola;
	inicio = final = -1;
	array = new T[tamano_cola];
}

//**********************************************************
template <class T>
void Cola_Circular<T>::Anadir(T valor) {
	int posicion = (final + 1) % tamano_cola;
		
	if (!Esta_Llena() && (array != NULL)) {
		if (inicio == -1) { inicio = 0; }
	array[posicion] = valor;
	final = posicion;
	}
}

//**********************************************************
template <class T>
T Cola_Circular<T>::Leer() {
	T valor;
	if(!Esta_Vacia()) {
		valor = array[inicio];
		if (inicio == final) { 
			inicio = final = -1; 
		} else {
			inicio = (inicio + 1) % tamano_cola;
		}		
	return valor;
	}
}

//**********************************************************
template <class T> // El primero que se añadio es el primero que sale ( ESO ES LO QUE SIGNIFICA FIFO)
void Cola_Circular<T>::Eliminar() { 
	if(!Esta_Vacia()) {  // si la cola ya posee elementos
		if (inicio == final) { // si inicio es igual a final es porque se eliminaron todos los elemento y "inicio" se corrió hasta llegar a "ultimo"
			inicio = final = -1; 
		} else {
			inicio = (inicio + 1) % tamano_cola;
		}		
	}
}

//**********************************************************
template <class T>
void Cola_Circular<T>::Ordenar_Cola() {
    T auxiliar;
    for (int i=0; i < tamano_cola; i++) {
        for (int j = i; j >= 0 && array[j+1] < array[j]; j--) {
            auxiliar = array[j+1];
            array[j+1] = array[j];
            array[j] = auxiliar;
        }
    }
}

//**********************************************************
template <class T>
bool Cola_Circular<T>::Esta_Llena() {
	if ((inicio == 0 && final == tamano_cola-1) || ((final+1) == inicio)) {
		return true; // Retorna true si la cola esta llena
	} else {
		return false;
	}
}

//**********************************************************
template <class T>
bool Cola_Circular<T>::Esta_Vacia() {
	if (inicio == -1 && final == -1) {
		return true;
	}else {
		return false;
	}
}

//**********************************************************
template <class T>
void Cola_Circular<T>::Imprimir() {
	if (!Esta_Vacia()) {
		if (inicio <= final)
			for (int i = inicio; i <= final; i++)
				cout << array[i] << "  ";
		if (final < inicio) {
			for (int i = inicio; i < tamano_cola; i++)
				cout << array[i] << "  ";
			for (int i = 0; i <= final; i++)
				cout << array[i] << "  ";
		}
	}
}
