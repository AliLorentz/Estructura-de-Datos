#include <iostream>
#include <conio.h>
//Busqueda Binaria
//Debe estar el arreglo ordenado para poder realizarlo (Orden ascendente)

using namespace std;
int main(int argc, char** argv) {

	int numero[]={1,2,3,4,5};
	int inf,sup,mitad,dato; //Dato numero que deseamos buscar
	char band = 'F'; //Determina si el elemento existe
	
	dato=4;//Deseamos buscar este Dato
	
	//Aqui comienza el agoritmo
	inf=0;
	sup=5;//Numero de arreglos
	
	while(inf<=sup){
		mitad = (sup+inf)/2;
		
		if(numero[mitad]== dato){
			band='V';
			break;//Me saca del bucle whiler para no desperdiciar rendimiento
		}
		if(numero[mitad]>dato){
			sup = mitad;
			mitad =(inf+sup)/2;	
		}
		if(numero[mitad]<dato){
			inf=mitad;
			mitad=(inf+sup)/2;
		}
	}
	
	if(band== 'V'){
		cout<<"La posicion fue encontrada "<<mitad<<endl;
		cout<<"Numero "<<numero[mitad]<<endl;
	}else{
		cout<<"No se encontro"<<endl;
	}

}
