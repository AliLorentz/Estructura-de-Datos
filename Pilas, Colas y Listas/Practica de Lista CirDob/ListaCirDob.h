#ifndef LISTACIRDOB_H
#define LISTACIRDOB_H
#include <iostream>

using namespace std;

template <class T> class ListaCirDob;

template <class T>
class nodo{
	private:
		T valor;
		nodo<T> * siguiente;
		nodo<T> * anterior;
	public:
		nodo(T v, nodo<T> *sig = NULL, nodo<T> *ant=NULL) : valor(v),	siguiente(sig), anterior(ant){};
		void set_Info(T _valor) { valor = _valor; }
		void set_Sig(nodo<T> *p) { siguiente = p; }
		void set_Ante(nodo<T>*p){anterior = p;}
		T get_Info(){return valor;}
		T getValor() { return valor; }
		nodo<T> *get_Sig() { return siguiente;	}
		nodo<T> *get_Ante(){ return anterior;}
};

template <class T>
class ListaCirDob
{
	nodo<T> *cab, *p;
	int numeroNodos;
	public:
		ListaCirDob(){cab = p= NULL; numeroNodos=0;}
		T *get_cab(){return cab;}
		nodo <T> *get_visit(){return p;}
		void reset(){p=cab;}
		//Mover
		T mover(int pasos=1,bool band=true){//true derecha // false left
			if(band){
				for(int i=-1;i<pasos;i++){
					p=p->get_Sig();
					}
				}else{
					for(int i =0 ; i<pasos;i++){
						p=p->get_Ante();
					}
				}
				return getInfoVisit();
			}
		
		T getInfoVisit(){return p->getValor();}
		int agregar(T E);
		int eliminar(T &E);
		void imprimir(bool BAND = true); // True cab hacia el ultimo
		T practica(int pasos=1,bool band=true);
		
		
};

template<class T>
void ListaCirDob<T>::imprimir(bool BAND){
	reset();
	if(cab==NULL) return;
	if(BAND){
		do{
			cout<<p->getValor();
			p=p->get_Sig();
		}while(p!=cab);
	}else{
		do{
			p=p->get_Ante();
			cout<<p->getValor();
		}while(p!=cab);
	}

	
}

template<class T>
int ListaCirDob<T>::agregar(T E){
	nodo <T> *pNue = new nodo<T>(E);
	if(!pNue) return 0;
	if(cab==NULL){
		cab = pNue; 
		pNue->set_Sig(pNue);
		pNue->set_Ante(pNue);
	}else{
		
		reset();
		
		do{
			if(E<getInfoVisit()) break;
			mover();
		}while(p!=cab);
		pNue->set_Sig(p);
		pNue->set_Ante(p->get_Ante());
		p->get_Ante()->set_Sig(pNue);
		p->set_Ante(pNue);
		if(E<cab->get_Info()){
			cab = pNue;
		}
	}//fin else
	numeroNodos++;
	return 1;
}//fin agregar

template<class T>
int ListaCirDob<T>::eliminar(T &E){	
	bool band = false;
	
	if(cab==NULL) return 0; //0 Esta Vacio
	if(E < cab->get_Info() || E > cab->get_Ante()->get_Info()) return -1; //Quiere decir que no existe es decir buscar un dato que no esta
	reset(); // p = cab;
	do{
		if(E==getInfoVisit()){  //getInfoVisit es igual que p->getInfo();
			band=true;
		}
		else{
			mover();
		}
	}while(!band && p!=cab);
	
	if(!band) return -1;
	E = getInfoVisit();
	if(p->get_Ante()==p && p->get_Sig()==p){
		 cab = NULL;//pendiente delete P
	}else{
		p->get_Ante()->set_Sig(p->get_Sig());
		p->get_Sig()->set_Ante(p->get_Ante());
		if(p==cab){
			cab = p->get_Sig();
		}
	} 
	delete p;
	return 1;
} // fin eliminar

template<class T>
T ListaCirDob<T>::practica(int pasos,bool band){
	
	char letter;
	for(int i=0;i<pasos;i++)
	if(!band){
		p=p->get_Sig();	
	}
	else{
		p=p->get_Ante();	
	}
	letter=getInfoVisit();
	
	nodo<T> *aux = p;
	if(cab==NULL) return 0;
	numeroNodos--;
	if(numeroNodos>0){
		p->get_Ante()->set_Sig(p->get_Sig());
		p->get_Sig()->set_Ante(p->get_Ante());
		p=aux->get_Sig();
	}
	delete(aux);
	return letter;
	
}



#endif

