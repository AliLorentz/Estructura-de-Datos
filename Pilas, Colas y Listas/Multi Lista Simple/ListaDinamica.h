#include <iostream>
#include "Nodo.h"

//#include "main.h"

using namespace std;

/*LISTA ENLAZADA DINÁMICA (SIMPLE ENLAZADA)*/

template <class T>
class ListaDinamica{
	Nodo<T> *cab;
	
	public:
		ListaDinamica(){ cab=NULL; }
		
		int Agregar(T E, int aux){//bool band=false, cero si no quiero que añada repetidos
			Nodo<T> *nue, *P, *ant;
			nue=new Nodo<T>(E);
			if(!nue){
				return -1;
			}
			if(cab==NULL){
				cab=nue;
			}else{
				ant=NULL;
				P=cab;
				while(P!=NULL){
					
				   if(aux==0){
				       if(E == (P->get_Info())){
				         return 0;
					   }
				   }
					if(E < (P->get_Info())){
						break;
					}else{//OJO
						ant=P;
						P=P->get_Sig();
					}//OJO
				}	
				if(P==cab){//CASO: INSERCION EN CABEcERA
					nue->set_Sig(cab);
					cab=nue;
				}else{
					ant->set_Sig(nue);
					nue->set_Sig(P);
				}
			}
			return 1;
		}
		
		int Eliminar(T &E){
			Nodo<T> *nue, *P, *ant;
			int aux;
			if(cab==NULL){
				return -1;
			}else{
				ant=NULL;
				P=cab;
				while(P!=NULL){
					if(E == P->get_Info()){
						aux=1;
						break;
					}else{
						//aux=1;
						ant=P;
						P=P->get_Sig();
					}
				}	
				if(P==NULL) return 0;
				if(P==cab){
					aux=1;
					P=P->get_Sig();
					cab=P;
				}else{
					aux=1;
					nue=P;
					P=P->get_Sig();
					ant->set_Sig(P);
					delete (nue);
				}
			}
			if(aux==1)return 1;
			else return 0;
		}
		
		Nodo<T> *get_Cabecera(){
			return cab;
		}
		
		void Imprimir(){
			Nodo<T> *P=cab;
			cout<<"LISTA:\n";
			while(P!=NULL){
				cout<<"|"<<P->get_Info()<<"|"<<endl;
				P=P->get_Sig();
			}
		}
		
		int Elimina_Final(T &E){
			Nodo<T> *nue, *P, *ant;
			int aux;
			if(cab==NULL){
				return -1;
			}else{
				nue=NULL;
				ant=NULL;
				P=cab;
				while(P!=NULL){
					if(nue == P->get_Sig()){
						aux=1;
						break;
					}else{
						//aux=1;
						ant=P;
						P=P->get_Sig();
					}
				}	
				if(P==NULL) return 0;
				if(P==cab){
					aux=1;
					P=P->get_Sig();
					cab=P;
				}else{
					aux=1;
					nue=P;
					P=P->get_Sig();
					ant->set_Sig(P);
					E = nue->get_Info();
					delete (nue);
				}
			}
		
			if(aux==1)return 1;
			else return 0;
		}	
		
		int Modificar_Ordenar(T E, T e){//E el que va ser modificado , por el que se va modificar 
			Nodo<T> *nue, *P, *ant,*nuevo;// ordenar el que ingreso como si estuviera agregando
			int aux;
			if(cab==NULL){
				return -1;
			}else{
				ant=NULL;
				P=cab;
				while(P!=NULL){
					if(E == P->get_Info()){
						aux=1;
						P->set_Info(e);
						break;
					}else{
						ant=P;
						P=P->get_Sig();
					}
				}	
				if(P==NULL) return 0;
				if(P==cab){
					aux=1;
					P=P->get_Sig();
					cab=P;
				}else{
					aux=1;
					nue=P;
					P=P->get_Sig();
					ant->set_Sig(P);
					E = nue->get_Info();
				}
			}
			if(aux==1){
			nuevo=new Nodo<T>(E);
			if(!nuevo){
				return -1;
			}
			if(cab!=NULL){
			    nue=NULL;
				ant=NULL;
				P=cab;
				while(P!=NULL){
					if(E < P->get_Info()){
						break;
					}else{
						ant=P;
						P=P->get_Sig();
					}
				}	
				if(P==cab){
					nuevo->set_Sig(cab);
					cab=nuevo;
				}else{
					ant->set_Sig(nuevo);
					nuevo->set_Sig(P);
				}
			}
		    }
			if(aux==1)return 1;
			else return 0;
		}
		
		int Modificar(T E){//E el que va ser modificado , por el que se va modificar , T e
			/*Nodo<T> *P;
			int aux;
			if(cab==NULL){
				return -1;
			}else{
				P=cab;
				while(P!=NULL){
					if(E == P->get_Info()){
						aux=1;
						P->set_Info(e);
						break;
					   }
						P=P->get_Sig();
					}
				}	
			   if(P==NULL) return 0;
               if(aux==1)return 1;
			    else return 0;*/
			    Nodo <T> *p=cab, *ant;
			    if(Buscar(E)==1){//, &p, &ant
                 p->set_Info(E);
	            }
	          return 1;   
		}
			
		int Buscar(T E){// el que voy a buscar en la posicion que se encuentra, T &e
			Nodo<T> *P;
			int aux, cont;
			cont=0;
			aux=0;
			if(cab==NULL){
				return -1;
			}else{
				P=cab;
				while(P!=NULL){
					cont++;
					if(E == P->get_Info()){
						aux=1;
						//P->set_Info(e);
						break;
					   }
						P=P->get_Sig();
					}
				}	
			   if(P==NULL) return 0;
			   if(aux==0) return 0;
			  //e=cont; 
              return cont;
			}
			
		int Total(){
			Nodo<T> *P=cab;
			int cont=0;
			while(P!=NULL){
				cont++;
				P=P->get_Sig();
			}
			return cont;
		}

		T Buscar_Por_Digito(int w){// en la posicion del que voy a buscar el que se encuentra alli, T E, T &e
			Nodo<T> *P=cab;
			if(w<=0) P=NULL;
			int cont=0;
			while(P!=NULL){
				cont++;
				if(cont==w)
				break;
				P=P->get_Sig();
			}
			if(P!=NULL)
		    return P->get_Info();
			//cout<<"|"<<P->get_Info()<<"|"<<endl;
		}
		
		 T Devolver_Por_Digito(int w){// en la posicion del que voy a buscar el que se encuentra alli, T E, T &e
			Nodo<T> *P=cab;
			if(w<=0) P=NULL;
			int cont=0;
			while(P!=NULL){
				cont++;
				if(cont==w)
				break;
				P=P->get_Sig();
			}
			if(P!=NULL){
			//cab=P;
			return P->get_Info();
			}
			//cout<<"|"<<P->get_Info()<<"|"<<endl;
		}
		
		/*
		template <class T>
        int ListaDinamica <T>::Modificar(T E){
	    Nodo <T> *p=cab, *ant;
	    if(Buscar(E, &p, &ant)){
        p->Set_Info(E);
	    }
	    return 1;
       }*/
       
		/*int Eliminar_Por_Posicion(T &E, int pos){
			Nodo<T> *nue, *P, *ant;
			int aux;
			if(cab==NULL){
				return -1;
			}else{
				ant=NULL;
				P=cab;
				while(P!=NULL){
					if(E == P->get_Info()){
						aux=1;
						break;
					}else{
						ant=P;
						P=P->get_Sig();
					}
				}	
				if(P==NULL) return 0;
				if(P==cab){
					aux=1;
					P=P->get_Sig();
					cab=P;
				}else{
					aux=1;
					nue=P;
					P=P->get_Sig();
					ant->set_Sig(P);
					delete (nue);
				}
			}
			if(aux==1)return 1;
			else return 0;
		}	*/	
};
