using namespace std;

template <class T>
class NodoA
{
      T inf;
      int fe;
      NodoA<T> *izq, *der;
  public:
      NodoA( T e ){ inf=e; izq=der=NULL;  fe=0;}
      NodoA<T> *GetIzq() { return izq;   }
      NodoA<T> *GetDer() { return der;   }
      T         GetInf() { return inf;   }
      int       GetFE () { return fe;    }
      void SetIzq( NodoA<T> *p ) { izq=p;}
      void SetDer( NodoA<T> *p ) { der=p;}
      void SetInf(  T e  )       { inf=e;}
      bool Hoja() { return (izq==NULL && der==NULL)? true : false; }
      void FE()   { int ai=0, ad=0;
                    if ( Hoja() ) fe=0; 
                    else {
                      if (izq) ai=izq->Altura();
                      if (der) ad=der->Altura();
                      fe= ad-ai;  
                    } 
                  }
      int Altura();      
};
      
template <class T>
int NodoA<T>::Altura()
{
    int ai=1, ad=1;
    if ( izq!=NULL ) ai= 1 + izq->Altura();
    if ( der!=NULL ) ad= 1 + der->Altura();
    return ( ai>ad )? ai: ad;    
}      
      
template <class T>
class ArbolBB
{
      NodoA<T> *raiz, *p, *ant;
      bool AVL;
   public:
      ArbolBB( bool tip=false ) { raiz=p=ant=NULL; AVL=tip; }
      NodoA<T> *GetRaiz() { return raiz; }
      NodoA<T> *GetVisi() { return p;    }
      NodoA<T> *GetAnte() { return ant;  }
      void Mayor ( NodoA<T> *&pt ) { while(pt->GetDer()!=NULL) pt=pt->GetDer();}
      void Menor ( NodoA<T> *&pt ) { while(pt->GetIzq()!=NULL) pt=pt->GetIzq();} 
      int Agregar ( T e, bool band=true   );
      int Buscar  ( T e, NodoA<T> *pt=NULL);
      int Eliminar( T e, NodoA<T> *pt=NULL);
};

template <class T>
int ArbolBB<T>::Buscar ( T e, NodoA<T> *pt )
{
    int enc=0;
    if ( !pt ) p= raiz;
    else       p= pt;
    while ( p && !enc ) {
          if ( e==p->GetInf() )
              enc=1;
          else if ( e<p->GetInf() ) {
              ant= p;
              p=p->GetIzq();
          }
          else
          {
              ant=p;
              p=p->GetDer();
          }
    }
    return enc;
}    
               
template <class T>
int ArbolBB<T>::Agregar( T e, bool band  )
{
    NodoA<T> *nue;
    nue= new NodoA<T>( e );
    if ( !nue ) return 0;
    if ( !raiz) raiz=p= nue;
    else {
        if ( Buscar(e)==1 && band==true ) return 0;     
        if ( e<ant->GetInf() )
           ant->SetIzq(nue);
        else
           ant->SetDer(nue);     
    } 
    if ( AVL ) {
         
    }       
    return 1; 
}      

template <class T>
int ArbolBB<T>::Eliminar ( T e, NodoA<T> *pt )
{
    NodoA<T> *aux;
    if ( !raiz || Buscar(e,pt)==0 ) return 0;   
    if ( p->GetIzq()==NULL && p->GetDer()==NULL ){
       if ( p==raiz ) 
            raiz=NULL;
       else {
         if ( p==ant->GetIzq() )
            ant->SetIzq(NULL);
         else
            ant->SetDer(NULL);
       }
       delete p; 
       p=raiz;
       return 1;
    }
    if ( p->GetIzq() ) {
       aux=p->GetIzq();
       Mayor(aux);
       p->SetInf(aux->GetInf() );    
       return Eliminar(aux->GetInf(),p->GetIzq());  
    }  
    else {
       aux=p->GetDer();
       Menor(aux);
       p->SetInf(aux->GetInf() );
       return Eliminar(aux->GetInf(),p->GetDer()); 
    }    
}    
