#include <iostream>
#include "math.h"
#include <vector> //Lo necesitaremos para guardar datos en el
#include "windows.h" //Para colorear



using namespace std;

void Radix(char [],int);
vector < vector <int> >Vec;//Creamos un vector 
 
int main(int argc, char** argv) {
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);//Coloreamos
	char numeros[]={'T','H','E','G','O','A','T'}; //Cadena que queremos que se ordene alfabetiamente
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),12);//Coloreamos
	cout<<"Cadena Principal"<<endl;
	for(int i=0;i<sizeof(numeros)/sizeof(char);i++){
		cout<<numeros[i]<<" ";;
	}
 		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);//Coloreamos
 		//Pasamos el vector y el numero de elementos del vector
	Radix(numeros,sizeof(numeros)/sizeof(char));
	
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),11);//Coloreamos
			cout<<"\nOrden alfabetico"<<endl;
			
	for(int i=0;i<sizeof(numeros)/sizeof(char);i++){
		cout<<numeros[i]<<" ";;
	}
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);//Coloreamos
}

void Radix(char a[],int n){
	cout<<endl<<endl;
	Vec.resize(10);
	int temp,m=0;//cálculo el número máximo de dígitos y  maximaClave
	for(int i = 0;i<7;i++){
		for(int j=0;j<n;j++){
			temp=(int)(a[j]/pow(10,i))%10; //vector/peso modulo 10
			Vec[temp].push_back(a[j]);		//Añadimos en una urna								
		}
			
			cout<<i<<" "<<a<<endl;//Mostramos el proceso de a (vector)
	//Hay que recordar que debemos hacer una búsqueda de primera urna no vacía
		for(int k=0;k<10;k++){
			for(int l=0;l<Vec[k].size();l++){
				a[m]=Vec[k][l];
				m++;				
			}	
			Vec[k].clear();//Limpiamos
		}	
		m=0;	
	}
}
