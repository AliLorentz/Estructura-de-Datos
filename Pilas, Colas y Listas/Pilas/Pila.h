#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

template <class T>
class Pila{
	int tam;
	T *v, valini;
	int tope;
	public:
		Pila(int n, T ini);
		int  Agregar(T ele);
		int  Eliminar(T &Eli);
		void ordenar();
		void Imprimir();
		int vacia();
		int llena();
		int AgregarInicio(T ele);
		int busqueda(T e);
		int BandD(T e); //Buscar and Destruir
		void invertir();
};

template <class T>
Pila <T>::Pila(int n, T ini){
	tam=n; //Tamaño del vector
	tope=-1; //Tapa del vector
	v= new T[tam]; //Realizamos el vectir
	if(!v) //Si es diferente a NULL
     	cout<<"Falla de Memoria"<<endl;
	else { 
	    valini=ini; //Valor de inicio que usaremos a la hora de eliminar
	    for ( int i=0; i<tam; i++)
	        v[i]=ini; //Rellenamos el vector 
    }
}

template <class T>
void Pila<T>::invertir(){
	T z[tam];
	int j=tam;
	for(int i = -1 ; i< tam ; i ++){
		j--;
		z[j]=v[i];
			
	}
	j = tam;
	for(int i = 0; i< tam ; i++){
		v[i]=z[i];
	
	}
	
}

template <class T> //retor 1 Eliminado | retor 0 No encontrado	
int Pila<T>::BandD(T e){
	int pos ;
	for(int i =0; i<tam;i++){
		if(v[i]==e){
			v[i]=0;
			pos = i;
			break;
		}else{
			return 0;
		}
	}
	for(int i = pos;i<tam;i++){
		v[i]=v[i+1];
	}
	tope--;
	return 1;
}

template <class T> //Encontrado retorna 1 | else 0
int Pila<T>:: busqueda(T e){
	for(int i = 0;i<tam;i++){
		if(v[i]==e){
		return 1;
		break;		
		}
	}
	return 0;
}

template <class T>
int Pila <T>::Agregar(T ele){
	//cout<<"\nTOPE:"<<tope<<"   Tam:"<<tam-1<<endl;
	if(!v)return -1; //Si no es NULL
	if(tope==tam-1)return 0;  //tope se sumara hasta que el tope que va sumando == tamaño es ctte
	v[tope+1]=ele; //Como tope es -1 al sumarle 1 se vuelve 0;
	tope++;
	return 1;
}

template <class T>
int Pila <T>::AgregarInicio(T ele){
	T aux;
	aux=v[0];
	tope++;
	int i=tope; 
	while(i!=0){
		v[i]=v[i-1];
		i--;
	}
		v[1]=aux;
		v[0]=ele;	
	return 1;
}

template <class T>
int Pila <T>::Eliminar(T &eli){ 
	if(!v) return -1;
	if(tope==-1) return 0;
	eli=v[tope]; //<--- No aporta nada :v
	v[tope]=valini; //Vuelve el ultimo valor inicial que hayamos dado al principio
	tope--; //Y se resta el tope para que cuando agreguemos volvamos a rellenar este espacio
	return 1;
}

template <class T>
void Pila <T>::Imprimir(){
    cout<<"Pila:\n";
	for(int i=0;i<=tope; i++)
		cout<<v[i]<<endl;	
}

template <class T>
void Pila <T>::ordenar(){
	T tmp;
	for(int i=tam/2;i>0;i/=2){
		for (int j = i; j < tope+1; j++){ //problema con el tam :L
            for(int k = j - i; k >= 0; k = k - i){
                if(v[k+i] >= v[k])
                    break;
                else{
                    tmp = v[k];
                    v[k] = v[k+i];
                    v[k+i] = tmp;
                }
            }
        }	
}

}

template <class T> // si retorna 1 es vacio | 0 esta con elementos
int Pila <T>::vacia(){
	if(tope==-1) return 1;
	return 0;
}

template <class T> // Si retorna 1 esta llena | 0 le queda espacio
int Pila <T> :: llena(){
	if(tope==tam-1) return 1;
	return 0;
}
