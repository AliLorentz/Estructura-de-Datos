#include <iostream>

using namespace std;

template <class T>
class Nodo{
      T info;
      Nodo<T> *ant, *sig;
    public:
        Nodo(T E)                  { info=E; ant=sig=NULL; }
        void  set_Info( T val )     { info=val; }
        void  set_Ant( Nodo<T> *p ) { ant= p;   }
        void  set_Sig( Nodo<T> *p ) { sig= p;   }
        T get_Info()        		   { return info; }
        Nodo<T> *get_Sig() 		   { return sig;  }
        Nodo<T> *get_Ant()          { return ant;  }   
        //Nodo<T> *get_Info()          { return  info;  }
		//void set_Sig(Nodo<T> *P){	sig=P;	}                      
};
