#include <iostream>
#include "windows.h"//Libreria necesesaria para el color


//Inserccion Directa y Binaria

void ordenamientoInserccion(int tam,char num[]);
void ordenamientoBinario(int tam,char num[]);

using namespace std;

int main(int argc, char** argv) {
	//Creo la cadena y le doy tamaño
	int TOTAL=4,select;
//	cout<<"Ingrese el numero de cuantos datos habran en la cadena"<<endl;
//	cin>>TOTAL;
	char numero[]={'G','O','A','T'};
	
	//La lleno de datos ahora con el TOTAL tengo tamaño del array para su futuro ordenamiento
//	for(int i=0;i<TOTAL;i++){		
//	    system("cls");
//		cout<<"Ingrese los datos de la cadena pos:"<<i+1<<endl;
//		cin>>numero[i];
//		system("cls");
//	}
	cout<<"Escoga un tipo de ordenamiento"<<endl;
	cout<<"1)Inserccion Binaria \n2)Inserccion Directa"<<endl;
	cin>>select;
	//llama un metodo para empezar el algoritmo de ordenamiento y mando por parametros el tamaño del vector como el array a odenar
	if(select==1){
		ordenamientoBinario(TOTAL,numero);
	}
	else if(select==2){
			ordenamientoInserccion(TOTAL,numero);
	}else{
			cout<<"No escogio una opcion"<<endl;
	}	
	//Mostramos la cadena ya ordenada 
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),11); //Codigo usado para colorear el texto
		for(int i=0;i<TOTAL;i++){
			cout<<numero[i]<<" ";}
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15); //Codigo usado para colorear el texto, ahora coloreamos todo el resto de blanco	
	return 0;
}



void ordenamientoInserccion(int x,char numero[]){	
	//El metodo de inserccion directa posee un nivel de eficiencia de n elvado a la 2 (n al cuadrado) Siendo n el numero de elementos
	//Para mas informacion del nivel de eficiencia del algoritmo->libro Estructura de Datos c++ Joyanes
	//pagina 219 para mas informacion pedir el libro directammente en clases (no poseeo internet)
			
	int ord[x]={0};//almacena los numeros de la array ya ordenados
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
		ord[i]=numero[pos];//Este linea de codigo lo que hace es almacenar los numeros que ya se ordenaron para luego poder colorearlos
	//Esta parte no tiene nada que ver con el algoritmo de ordenamiento, solo muestra la lista miestra se ordena
	for(int z=0;z<to;z++){
				if(numero[pos]==ord[z]){//Se colorean ya los ordenados
						SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),12);	//Coloreamos
						cout<<numero[z]<<" ";
					}else if(numero[pos]<ord[z]){//Se colorean ya los ordenados
						SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),11);	//Coloreamos
					cout<<numero[z]<<" ";		
					}else{//Se colorean los que tampoco se han ordenados
						cout<<numero[z]<<" ";
					}
						//Pinta el resto de blanco para que vea mejor la interfas
					SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);	//Coloreamos
		}
				cout<<endl;
		system("pause");					
	}
	system("cls");
			cout<<"Es el menos eficiente de los metodos de inserccion"<<endl;


}

void ordenamientoBinario(int x,char numero[]){
	//El metodo es mucho mas eficiente que la inserccion directa 
	//en analizis se supondria que segun mis calculos debe tener una eficiencia de f-(n) ya que 
	//Este metodo depende solamente de los bucles anidados mas informacion capitulo 6 ->Análisis y eficiencias de algoritmos Estructura de Datos c++ Joyanes
	//pagina 155 para mas informacion pedir el libro directammente en clases
	int to=x;
	int i,j,aux,izq,der,m=0;
	int ord[x]={0};//almacena los numeros de la array ya ordenados
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
			ord[i]=numero[izq];//Este linea de codigo lo que hace es almacenar los numeros que ya se ordenaron para luego poder colorearlos
			//Esta parte no tiene nada que ver con el algoritmo solo muestra los pasos hasta que se resuelva el ordenamiento
					for(int z=0;z<x;z++){	
					if(numero[izq]==ord[z]){//Se colorean ya los ordenados
						SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),12);	//Coloreamos
						cout<<numero[z]<<" ";
					}else if(numero[izq]<ord[z]){//Se colorean ya los ordenados
						SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),11);	//Coloreamos
					cout<<numero[z]<<" ";		
					}else{//Se colorean  los que no ordenados
						cout<<numero[z]<<" ";
					}
						//Pinta el resto de blanco para que vea mejor la interfas
					SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);	//Coloreamos
			}
			cout<<endl;
				system("pause");
			}
			system("cls");
			cout<<"Es el mas eficiente de los metodos de inserccion"<<endl;
}
