#include <iostream>
using namespace std;
template <class T>
class nodos
{
	T inf;
	nodos<T> *sig;
	public:
	nodos(T d){
		inf=d;
		sig=NULL;
	}		
	nodos()
	{
		sig=NULL;
	}	
	T getinf()
	{
		return inf;
	}
	nodos<T> *getsig()
	{
		return sig;
	}
	void setinf(T d)
	{
		inf=d;
	}
	void setsig(nodos<T>* p)
	{
		sig=p;
	}
};

template <class T>
class listasimple
{
	nodos<T>* cab;
	public:
		listasimple()
		{
			cab=NULL;
		}
		nodos<T>* getcab(){
			return cab;
		}
		int agregar(T e);
		int eliminar(T &e);
		void imprimir();
		int buscar (T &e);
		int modificar(T &e);
};
template <class T>
int listasimple<T>::modificar(T &e)
{
	if(cab==NULL) return 0;
	nodos<T> *p,*ant;
	p=cab;
	while(p!=NULL)
	{
		if(p->getinf()==e)break;
		ant=p;
		p=p->getsig();
	}
	if(p==NULL)
	{
		return -1;
	}
	p->setinf(e);
	e=p->getinf();
	
	
	return 1;
}
template <class T>
void listasimple<T>::imprimir()
{
	nodos<T> *p=cab;
	while(p)
	{
		cout<<p->getinf()<<endl;
		p=p->getsig();
	}
}
//agregar:
template <class T>
int listasimple<T>::agregar(T e)
{
	nodos<T> *nue, *p, *ant;
	nue = new nodos<T>(e);
	if(nue==NULL) return 0;
	if(cab==NULL)cab=nue;
	else{
		p=cab; ant=NULL;
		while(p!=NULL)
		{
			if(e<p->getinf())break;
			ant=p;p=p->getsig();
		}
		if(p==cab) cab=nue;
		else ant->setsig(nue);
		nue->setsig(p);
	}
	return 1;
}
template <class T>
int listasimple<T>::buscar(T &e)
{
	if(cab==NULL) return 0;
	nodos<T> *p,*ant;
	p=cab;
	while(p!=NULL)
	{
		if(p->getinf()==e)break;
		ant=p;
		p=p->getsig();
	}
	if(p==NULL)
	{
		return -1;
	}
	
	e=p->getinf();
	
	
	return 1;
}

template <class T>
int listasimple<T>::eliminar(T &e)
{
	if(cab==NULL) return 0;
	nodos<T> *p=cab,*ant;
	while(p!=NULL)
	{
		if(p->getinf()==e)break;
		ant=p;
		p=p->getsig();
	}
	if(p==NULL)
	{
	return -1;	
	}
	if(p==cab) cab=cab->getsig();
	else ant->setsig(p->getsig());
	e=p->getinf();
	
	delete p;
	return 1;
}


