#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Departamento.h"

using namespace std;

int main(){
				//MULTILISTA
	listasimple<Departamento> tienda;//multilista
	Departamento V[]={Departamento(15, "Ropa"), Departamento(12, "Muebles")};//, Departamento(14, "Articulos de deporte")
    //carga de departamentos
	for(int i=0;i<(sizeof(V)/sizeof(V[0]));i++) {
		tienda.agregar(V[i]);//.Agregar(V[i],0);
		cout<<"DEPARTAMENTO AGREGADO\n"<<endl;
	}
		tienda.imprimir();//.Imprimir();
	//carga de articulos para los departamentos(no se puede agregar un articulo a la tienda)
	Articulo A[]={ Articulo(1510,"camisa"),
	               Articulo(1210,"cesa"),
	               Articulo(1516,"pantalon"),
	               Articulo(1512,"franela"),
	               Articulo(1219,"silla") };
	int codart;              
	for(int i=0;i<(sizeof(A)/sizeof(A[0]));i++)
	{
		codart=A[i].get_Cod()/100;//acomodarlo pasando a un char o string y asimiro digitos
		cout<<"CODIGO ACTUAL: "<<codart<<endl;
        Departamento Busdep(codart," ");
		if(tienda.buscar(Busdep)){//.Buscar(Busdep)
		cout<<"ENCONTRADO"<<endl;
		Busdep.Agregar_Articulo(A[i]);//agrego en el departamento
		tienda.modificar(Busdep);//.Modificar(Busdep);
		//Busdep.Imprimir(false);
		//cout<<"aca"<<endl;
	    //tienda.Modificar(Busdep ,Busdep);//encuentra departamento y lo actualiza con la nueva data
		//Busdep.Imprimir(false);
		//cout<<endl<<endl<<endl;
		}
	}
	//tienda.imprimir();//.Imprimir();
	//Departamento Busde(12," ");
	//Departamento Busd(15," ");
	int buscador;
	for(int i=0;i<2;i++){//(sizeof(V)/sizeof(V[0]))
	cout<<"Ingrese codigo de departamento que desea consultar"<<endl;
	cin>>buscador;
	Departamento Busde(buscador," ");
	if(tienda.buscar(Busde)){
		//cout<<"ENCONTRADO"<<endl;
		//Busdep.Agregar_Articulo(A[i]);
		//tienda.modificar(Busdep);
		Busde.Imprimir(false);
		}
	
		//cout<<"aca"<<endl;
	//	Busde.Imprimir(false);
	//	Busd.Imprimir(false);
		//Busdep=tienda.//.Buscar_Por_Digito(i);
		//cout<<Busdep<<endl;
		
		//Busdep.Imprimir(false);
		
    }
   
    //
		
	return 0;
}
