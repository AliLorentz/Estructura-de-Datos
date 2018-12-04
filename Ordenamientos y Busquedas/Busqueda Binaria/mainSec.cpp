#include <iostream>
#include <conio.h> 
//Busqueda secuencial
//A diferencia del binario no necesitamos que estee arreglado
using namespace std;
int main(int argc, char** argv) {
	int a[]={4,3,2,9,1,6};
	int i,dato;
	char band = 'F';
	//Comienzo el algoritmo
	dato=1;
	i=0;
	while((band=='F')&&(i<6)){// i se coloca en 6 por el numero de arreglos del array
		if(a[i]==dato){
			band = 'V';
			break;
		}
		i++;
	}
	if(band=='F'){
		cout<<"El numero no existe"<<endl;
	}else if(band=='V'){
		cout<<"el numero fue encontrado en la pos: "<<i<<endl;
	}
	return 0;
}
