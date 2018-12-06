#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

struct Nodo{
	char dato;
	Nodo *siguiente;	
};

	Nodo *pila =NULL;
	vector <char> lista;
		vector <char> help;
	int band=0;
	template <class T>
	void agregarPila( T n);
	void sacarPila();
	void mostrar();	
		template <class T>
	int comprobar( T n);

int main(int argc, char** argv) {
	
	cout<<"DIGITE EL CODIGO PARA EL ALGORITMO: ";
	char c[14];
	cin>>c;

//-------------------VALORES DE PRUEBA---------------------------------------------------------
//Si desea probbarlos tambien comente la parte de ingresar y descomente 1 (UN VALOR DE PRUEBA A LA VEZ :V)

//	char c[] ="3+4*2/(1-5)^2^3 "; //nice
//	char c[]= "(2 * 7 * 8) / 2 ) ^ 5"; // nice
//	char c[]="3 + 4 * (2 - 1) --->"; //nice
//	char c[]= "(2 * 7 * 8 * 4 / 2)"; //nice
//	char c[] ="3 ^ 2 ^ (5 - 1) / 2 * 4 + 3";//little nice

//----------------------------------------------------------------------------------------------------------

	for(int i = 0;i<15;i++){
		if(c[i]=='1' || c[i]=='2' || c[i]=='3' || c[i]=='4' || c[i]=='5' || c[i]=='6' || c[i]=='7' || c[i]=='8' || c[i]=='9' || c[i]=='0'  ){
		lista.push_back(c[i]);
		} if(c[i]=='*' || c[i]=='+' || c[i]=='-' || c[i]=='/' || c[i]=='^' ){	
		
			comprobar(c[i]);
			agregarPila(c[i]);
		}if(c[i]==')'){
			comprobar(')');
		}if(c[i]=='('){
			comprobar('(');
		}		
	}
	
	
	for(int i = 0; i<lista.size();i++){
		cout<<""<<lista[i]<<" ";
	}
//	cout<<"\n--------------------\n"<<endl;
		mostrar();
	

}

template <class T>
void agregarPila( T n){
	
	
	Nodo *nuevo = new Nodo();
	nuevo->dato = n;
	nuevo->siguiente = pila;
	pila = nuevo;
}

template <class T>
int comprobar(T n){
	Nodo *aux = pila;	
	while(aux!=NULL){
	int pro ,pro2;
	//PARA EL DATO ENTRANTE
	if(n=='*'||n == '/'){
		pro=3;
	}else if(n=='+' || n=='-'){
		pro = 2;
	}else if(n=='^'){
		pro = 4;
	}else if(n=='(' && band==0){
		band++;
	}else if(n==')'&& band==1){
		band++;
	}
	//PARA LA PILA
		if(aux->dato=='*'||aux->dato == '/'){
		pro2=3;
	}else if(aux->dato=='+' ||aux->dato=='-'){
		pro2 = 2;
	}else if(aux->dato=='^'){
		pro2 = 4;
	}
	
	//COMPROBANTE
	if(band==1){
		if(n != '('){
		help.push_back(n);
		}
	}else if(band == 2){
			band=0;
		for(int i = 0 ;i <help.size();i++){
			comprobar(help[i]);
			agregarPila(help[i]);
		
		}
	}
	//Para signos diferentes de ()
	if(band==0){
	if(pro<pro2){
		lista.push_back(n);
		sacarPila();			
	}else if (pro==pro2){
		if(pro==4 && pro2 ==4){
			//NADA :V
		}else{
		lista.push_back(aux->dato);
		sacarPila();
		}

	} else if(pro==4 && pro2== 3){
		if(pro>pro2)
		lista.push_back(aux->dato);
		sacarPila();
	}
	}
	break;
}
}

void sacarPila(){
	
	Nodo *aux = pila;
	pila = aux->siguiente;
	delete aux;
}

void mostrar(){
	Nodo *aux = pila;
	while(aux!=NULL){
		cout<<aux->dato<<" ";
		aux = aux->siguiente;
	}
}








