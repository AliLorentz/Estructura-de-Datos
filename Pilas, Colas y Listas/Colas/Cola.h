using namespace std;

template <class T>
class ColaCir
{
	T *V;
	int tam, fre, fin;
   public:
   	ColaCir( int s);
   	int Agregar( T e );
   	int Eliminar( T&e);
   	void Imprimir();
   	T Frente()   { return V[fre];          }
   	T Final()    { return V[fin];          }
	bool Vacia() { return fre==-1;         }
	bool Llena() { return fre==(fin+1)%tam;}	
};

template <class T>
ColaCir<T>::ColaCir( int s)
{
	tam= s; fre=fin=-1;
	V= new T[s];
	if ( !V ) cout<<"Error! no hay espacio para crear la Cola";
}

template <class T>
int ColaCir<T>:: Agregar( T e )
{
	if ( !V ) return -1;
    if ( Llena() )	return 0;
    if ( Vacia() )  fre=fin=0;
    else            fin= (fin+1)%tam;
    V[fin] = e;
    return 1;
}
	
template <class T>
int ColaCir<T>::Eliminar( T&e)
{
	if ( !V ) return -1;
    if ( Vacia() )	return 0;
    e= V[fre];
    if ( fre==fin) 
       fre=fin=-1;
    else
       fre= (fre+1)%tam;
    return 1;
}	

template <class T>
void ColaCir<T>::Imprimir()
{
	int i=fre;
	if ( Vacia() ) return;
  	do {
	  cout<< V[i]<< endl;
	  i=(i+1)%tam ;
	} while ( i!=(fin+1)%tam ) ; 
}
