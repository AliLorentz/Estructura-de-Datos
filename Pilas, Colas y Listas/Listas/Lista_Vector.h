#include <iostream>

using namespace std; 
//************************************************************ Clase Lista_Vector *******************************************************************
template <class T>
class Lista_Vector {
	T * vector;
	int tamano;
	int cabecera;
	int libre;
	
	public:
		Lista_Vector (int tamano);
		int Agregar_Elemento  (T  valor);
		int Eliminar_Elemento (T &valor);
		T Obtener_Cabecera();
		bool Esta_Vacia();
		bool Esta_Llena();
		void Imprimir();
};

//************************************************************
template<class T>
Lista_Vector<T>::Lista_Vector(int tamano){
	this->tamano = tamano;
	cabecera = 0;
	libre = 0;
	vector = new T[tamano];
	if(!vector) {
		cout << "FALTA MEMORIA" << endl;	
	} 
}

//************************************************************
template<class T>
int Lista_Vector<T>::Agregar_Elemento(T valor){
	int i = libre-1;
	
	if(!vector) {  return -1; }
	if(Esta_Llena()) { return 0; }
	
	while( i >= cabecera && valor < vector[i]) {
		vector [i+1] = vector[i];
		i--;
	}
	vector[i+1] = valor;
	libre++;
	return 1;
}


//************************************************************
template<class T>
int Lista_Vector<T>::Eliminar_Elemento(T &valor){
	
	int i;
	if(!vector) { return -1; } 
	if(Esta_Vacia()) { return 0; }
	
	for(int i=cabecera; i<libre && vector[i] !=valor; i++);  // cambia el I y cuando ya no se cumple una de las dos condiciones entonces rompe el ciclo y en el I queda guardado el indice deseado
	
	if( i==libre) {	return -2; }
	for( /*i ya posee el valor obtenido en el for anterior*/; i<libre-1; i++) { vector[i] = vector[i+1]; }
		
	libre --;
	return 1;
}


//************************************************************
template<class T>
T Lista_Vector<T>::Obtener_Cabecera() { 
	return vector[cabecera]; 
}

//************************************************************
template<class T>
bool Lista_Vector<T>::Esta_Vacia() {	
	return libre == 0; // la comparacion dara un bool y ese valor es el que retornará 
}

//************************************************************
template<class T>
bool Lista_Vector<T>::Esta_Llena() {	
	return libre == tamano;	
}

//************************************************************
template<class T>
void Lista_Vector<T>::Imprimir(){
	
	for(int i=cabecera; i<libre; i++){
		if(i  < libre-1 )   cout << " " << vector[i] << " -- ";
		if(i == libre-1)    cout << " " << vector[i] << endl;
		
	}
}
