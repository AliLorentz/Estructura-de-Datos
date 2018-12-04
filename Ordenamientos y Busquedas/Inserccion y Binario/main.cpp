#include <iostream>
#include "windows.h"//Libreria necesesaria para el color

//Inserccion Directa

void ordenamientoInserccion(int tam,int num[]);
void ordenamientoBinario(int tam,int num[]);
using namespace std;

int main(int argc, char** argv) {
	//Creo la cadena y le doy tamaño
	int TOTAL,datos,select;
	cout<<"Ingrese el numero de cuantos datos habran en la cadena"<<endl;
	cin>>TOTAL;
	int numero[TOTAL];
	
	//La lleno de datos ahora con el TOTAL tengo tamaño del array para su futuro ordenamiento
	for(int i=0;i<TOTAL;i++){		
	    system("cls");
		cout<<"Ingrese los datos de la cadena pos:"<<i+1<<endl;
		cin>>numero[i];
		system("cls");
	}
	cout<<"Escoga un tipo de ordenamiento"<<endl;
	cout<<"1)Inserccion Binaria \n 2)Inserccion Directa"<<endl;
	cin>>select;
	//llama un metodo para empezar el algoritmo de ordenamiento
	if(select==1){
		ordenamientoBinario(TOTAL,numero);
	}
	
	else if(select==2){
			ordenamientoInserccion(TOTAL,numero);
	}	
	//Mostramos la cadena ya ordenada 
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),11); //Coidigo usado para colorear el texto
		for(int i=0;i<TOTAL;i++){
			cout<<numero[i]<<" ";}
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15); 	
	return 0;
}



void ordenamientoInserccion(int x,int numero[]){	
	//El metodo de inserccion directa posee un nivel de eficiencia de n elvado a la 2 (n al cuadrado) Siendo n el numero de elementos
	//Para mas informacion del nivel de eficiencia del algoritmo->libro Estructura de Datos c++ Joyanes
	//pagina 219 para mas informacion pedir el libro directammente en clases (no poseeo internet)
			
	int to = x;
	int pos,aux;
	for(int i=0;i<x+1;i++){
		system("cls");
		pos=i;
		aux=numero[i];
		while((pos>0) && (aux< numero[pos-1])){
			numero[pos]=numero[pos-1];
			pos--;		
		}
		numero[pos]=aux;
	//Esta parte no tiene nada que ver con el algoritmo de ordenamiento, solo muestra la lista miestra se ordena
	for(int j=0;j<to;j++){
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),12); //Coloreamos
			cout<<numero[j]<<" " ;
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15); //Coloreamos
		}
				cout<<endl;
		system("pause");					
	}
	system("cls");
			cout<<"Es el menos eficiente"<<endl;


}

void ordenamientoBinario(int x,int numero[]){
	//El metodo es mucho mas eficiente que la inserccion directa 
	int to=x;
	int i,j,aux,izq,der,m=0;
	for(i=0;i<x;i++){
			system("cls");
			aux = numero[i];
			izq=0;
			der=i-1;
			while(izq<=der){
				m=((izq+der)/2);
				if(aux<numero[m])
				der=m-1;
				else
				izq=m+1;
			}
			j=i-1;
			while(j>=izq){
				numero[j+1]=numero[j];
				j=j-1;
			}
					
			
			numero[izq]=aux;
			//Esta parte no tiene nada que ver con el algoritmo solo muestra los pasos hasta que se resuelva el ordenamiento
					for(int z=0;z<x;z++){	
					SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),12);	
					cout<<numero[z]<<" ";		
					SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);	
			}
			cout<<endl;
				system("pause");
			}
			system("cls");
			cout<<"Es el mas eficiente"<<endl;
}



