#include <cstdlib>
#include <iostream>
#include "arbol.h"

template <class T>
void InOrden( NodoA<T> *Pt, int Niv )
{
     if ( !Pt ) return;
     if ( Pt->GetIzq() )  InOrden(Pt->GetIzq(), Niv+1);
     for (int i=0; i<Niv; i++) cout<<"     "; 
     Pt->FE();
     cout<< Pt->GetInf()<<":"<<Pt->GetFE()<<endl;
     if ( Pt->GetDer() )  InOrden(Pt->GetDer(), Niv+1);
}

int main(int argc, char *argv[])
{
    ArbolBB<int> obj;
    obj.Agregar(40);
    obj.Agregar(30);
    obj.Agregar(50);
    obj.Agregar(37);
    obj.Agregar(33);
    obj.Agregar(45);
    obj.Agregar(43);
    obj.Agregar(49);
    obj.Agregar(34);
    obj.Agregar(35);
    obj.Agregar(36); 
/*    obj.Agregar(38);
//    obj.Agregar(39);  
    obj.Agregar(32);
    obj.Agregar(31);     
    InOrden( obj.GetRaiz(), 0 );
    obj.Eliminar(40);
    cout<<"\nDespues de eliminar:\n";*/
    InOrden( obj.GetRaiz(), 0 );
    system("PAUSE");
    return EXIT_SUCCESS;
}
