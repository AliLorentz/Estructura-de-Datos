#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

template <class T>
class Archivo
{
      fstream obj;
      char nom[30];
      T(*pf)(char *k );
      int tam;
      T buf;
   public:
      Archivo() { }
      Archivo( char *n )                      { strcpy(nom,n); tam=0; pf=NULL; }
      Archivo( char *n, T(*f)(char *k ) )     { strcpy(nom,n); tam=0; pf=f;    }
      void Abrir(const std::_Ios_Openmode &t) { obj.open(nom,t);               }
      void Cerrar()                           { obj.close();                   }
      void Reiniciar()                        { obj.clear(); obj.seekg(0);     }
      bool Falla ()                           { return obj.fail();             }
      bool Es_Fin()                           { return obj.eof();              }
      T Get_buf()                             { return buf;                    }
      void Leer(char c[180])                  { obj.getline(c,180,'\n');       }                     
      void Escribir( char c[180] )            { obj.clear(); obj<<c<<endl;     }
      void Conver(char c[180] )               { buf=pf(c);                     }
      T Leerbuf(char c[180]);
      bool Buscar_Simple( T &e );
      void Ordenar();
};

template <class T>
T Archivo<T>::Leerbuf(char c[180])                     
{   
    char aux[180];
    Leer(c);  
    strcpy(aux,c);
    if ( !Es_Fin() ) Conver(aux);  
    return buf;  
}

template <class T>
bool Archivo<T>::Buscar_Simple( T &e )
{
     char lin[180]; bool ban=false;
     while(!ban)
    {
      Leer(lin);
      if ( Es_Fin() ) break;
      buf= pf(lin);
      if (e==buf) {
         e=buf;
         ban=true;
      }
    }
    return ban;
}

template <class T>
void Archivo<T>::Ordenar( )
{
     T reg1, reg2;
     char lin[180], l2n[180]; bool sw=true; int blo=1;
     Archivo<T> f1("aux1.txt", pf), f2("aux2.txt", pf);
     f1.Abrir(ios::out);  f2.Abrir(ios::out);
     while( true )
     {
            Leer(lin);
            if ( Es_Fin() ) break;
            if ( sw ) 
                 f1.Escribir(lin);
            else
                 f2.Escribir(lin);
            sw= !sw;
     }           
     f1.Cerrar(); f2.Cerrar(); Cerrar();
     Abrir(ios::out); f1.Abrir(ios::in); f2.Abrir(ios::in);
     reg1= f1.Leerbuf(lin);  reg2=f2.Leerbuf(l2n);
     while ( !f1.Es_Fin() && !f2.Es_Fin() )
     {
           if ( reg1<reg2 )
           {
                this->Escribir(lin); 
                this->Escribir(l2n);
           }
           else
           {
                this->Escribir(l2n);
                this->Escribir(lin);              
           }
           reg1= f1.Leerbuf(lin);  
           reg2= f2.Leerbuf(l2n);
     } 
     while ( !f1.Es_Fin() )
     {
           this->Escribir(lin);
           f1.Leer(lin);
     }
     while ( !f2.Es_Fin() )
     {
           this->Escribir(l2n);
           f2.Leer(l2n);
     }
     f1.Cerrar(); f2.Cerrar(); Cerrar();  
}
