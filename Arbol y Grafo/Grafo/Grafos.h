#ifndef GRAFOS_H
#define GRAFOS_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "ColaNodo.h"
#include "PilaNodo.h"
#include "ListaSimpleEnlazada.h"

using namespace std;

class NodoAdy
{
      char ver;
      float pes;
   public:
      NodoAdy( char e, float p=1 ) { ver=e; pes=p; }
      NodoAdy( ) {   }
      float GetVal ( ) { return pes; }
      char  GetVer ( ) { return ver; }
      bool operator==( NodoAdy d ) { return this->ver==d.ver; }
      bool operator< ( NodoAdy d ) { return this->ver< d.ver; }      
      friend ostream& operator << ( ostream& salida,NodoAdy nodoAdy){
			salida << "["<< nodoAdy.ver<< "] Peso:"<<nodoAdy.pes<<" - ";
			return salida;
		}
	  void imprimir() { cout<<"["<< ver << "] Peso:"<<pes; }
};

class NodoDir
{
      char ver;
      ListaSimpleEnlazada< NodoAdy > *ady;
   public:
      NodoDir( char e, bool band=true ) { ver=e; if (band) ady= new ListaSimpleEnlazada< NodoAdy >; }
      NodoDir()        {                                   }
      char GetVer ( )  { return ver;                       }
      Nodo<NodoAdy> *GetCab() { return ady->get_cab();     }
      bool operator==( NodoDir d ) { return this->ver==d.ver; }
      bool operator< ( NodoDir d ) { return this->ver< d.ver; }
      int  AgregarAdy( NodoAdy e ) { ady->agregar(e);         }
      void imprimir() { cout<<endl <<ver <<" Nodos Adyacentes: "; ady->imprimir();}
	  friend ostream& operator << ( ostream& salida,NodoDir nodoDir){
			salida << nodoDir.ver<< "   Nodods Adyacentes: "<<nodoDir.ady;
			return salida;
		}
};


class Grafos {
	char *vertices;
	float **m;
	int n, tam;
	bool dir;
	ListaSimpleEnlazada< NodoDir > *lisady;
	
	public:
		
		Grafos(int n, bool dir = false);
		Grafos(char *nom_arc);
		void agregarVertices(char *v);
		int agregarVertice(char ver);
		int agregarArista(char ori, char des, float pes = 1);
		void imprimirArreglos();
		void recorridoAnchura(char v);
		void recorridoProfundidad(char v);
		void warshall();
		void floyd();
		void dijkstra(char origen);
		void prim();
		bool isMarcado(int *v);
};

Grafos :: Grafos(int tam, bool dir) {
	this->dir = dir;
	this->tam = tam;
	n = 0;
	vertices = new char[tam];
	m = new float *[tam];
	
	for(int i = 0; i < tam; i++)
		m[i] = new float[tam];

	for(int i = 0; i < tam; i++) {
		vertices[i] = 0;
		for(int j = 0; j < tam; j++)
			m[i][j] = 0;
	}
}

Grafos :: Grafos(char *nom_arc) {
	fstream archivo;
    archivo.open(nom_arc, ios::in);
    char cadena[10];
    int lineas=1;
    lisady = new ListaSimpleEnlazada<NodoDir>;

    while(archivo.good()){
        if(archivo.get()=='\n')
        lineas++;
    }
    archivo.close();

    ListaSimpleEnlazada<char> listaVertices;
    archivo.open(nom_arc, ios::in);
    for(int i=0; i<lineas; i++){

        if(i==0){
            archivo.getline(cadena, 10, '\n');
            if(tolower(cadena[0])=='f'){
                this->dir=false;
            }else{
                this->dir=true;
            }
        }else{
            archivo.getline(cadena, 10, ' ');

            if( listaVertices.buscar(cadena[0]) <= 0){

                listaVertices.agregar(cadena[0],true);
              }
              
            archivo.getline(cadena, 10, ' ');

           if( listaVertices.buscar(cadena[0]) <= 0){

               listaVertices.agregar(cadena[0], true);
            }

            archivo.getline(cadena, 10, '\n');
        }
    }

    archivo.close();

    archivo.open(nom_arc, ios::in);

    int tam=listaVertices.getSize();
    this->tam=tam;
    vertices = new char[tam];
    char dato;
    for(int i=0; i<tam; i++){
		listaVertices.eliminar(dato);
        vertices[i] = dato;
    }

    this->m = new float *[tam];

    for(int i = 0; i < tam; i++)
        this->m[i] = new float[tam];

    for(int i = 0; i < tam; i++) {
        for(int j = 0; j < tam; j++)
            m[i][j] = 0;
    }
    char org, dest;
    float peso;
    archivo.getline(cadena, 10, '\n');
    for(int i=0; i<lineas - 1; i++){
            archivo.getline(cadena, 10, ' ');
            org=cadena[0];
            archivo.getline(cadena, 10, ' ');
            dest=cadena[0];
            archivo.getline(cadena, 10, '\n');
            peso = atof(cadena);
            this->agregarArista(org,dest, peso);
    }

    archivo.close();
    listaVertices.imprimir();
}

void Grafos :: agregarVertices(char *v) {
	for(int i = 0; i < tam; i++)
		vertices[i] = v[i];
	n = tam;
}

int Grafos :: agregarVertice(char v) {
	if( n < tam) {
		vertices[n] = v;
		n++;
		return 1;
	}
	return 0;
}

int Grafos :: agregarArista(char ori, char des, float pes) {
	int i = 0, j = 0, x, y, cox = 0;

	while(i < tam && j < tam && cox < 2) {
		if(vertices[i] == ori) {
			cox++;
			x = i;
		}
		if(vertices[j] == des) {
			cox++;
			y = j;
		}
		i++;
		j++;
	}

	if(cox == 2) {
		m[x][y] = pes;
		if(!this->dir)
			m[y][x] = pes;
		return 1;
	}
	return 0;
}

void Grafos :: imprimirArreglos() {
	
	cout<<endl;
	cout <<"Vertices:";
	for(int i = 0; i < tam; i++)
		cout << vertices[i];
	
//	if(lisady!=NULL){
//		lisady->imprimir();
//	}
	
	cout<<endl<<endl;
//	cout << endl << "Aristas:" << endl;
	cout <<" *** MATRIZ DE ADYACENCIA *** "<<endl;
	for(int i = 0; i < tam; i++) {
		cout << endl;
		for(int j = 0; j < tam; j++) {
			cout << "  " << m[i][j] << " ";
		}	
	}
}

void Grafos :: recorridoAnchura(char v) {
	int *va;
	ColaNodo<char> c;
	char aux;

	va = new int[tam];
	for(int i = 0; i < tam; i++)
		if(vertices[i] == v)
			va[i] = 1;
		else 
			va[i] = 0;

	c.agregar(v);
	cout << endl << endl << "Recorrido :";

	while(!c.isVacia()) {
		c.eliminar(aux);
		cout << endl << aux;
		for(int i = 0; i < tam; i++) {
			if(vertices[i] == aux) {
				for(int j = 0; j < tam; j++) {
					if(m[i][j] != 0) {
						if(va[j] != 1){
							c.agregar(vertices[j]);
							va[j] = 1;
						}
					}
				}
			}
		}
	}
	cout << endl << "Fin del Recorrido." << endl;
}

void Grafos :: recorridoProfundidad(char v) {
	int *va;
	PilaNodo<char> p;
	char aux;

	va = new int[tam];
	for(int i = 0; i < tam; i++)
		if(vertices[i] == v)
			va[i] = 1;
		else 
			va[i] = 0;

	p.agregar(v);
	cout << endl << endl << "Recorrido :";

	while(!p.isVacia()) {
		p.eliminar(aux);
		cout << endl << aux;
		for(int i = 0; i < tam; i++) {
			if(vertices[i] == aux) {
				for(int j = 0; j < tam; j++) {
					if(m[i][j] != 0) {
						if(va[j] != 1){
							p.agregar(vertices[j]);
							va[j] = 1;
						}
					}
				}
			}
		}
	}
	cout << endl << "Fin del Recorrido." << endl;
}

void Grafos :: warshall() {
	float **r, **p, **q;

	r = new float *[tam];
	p = new float *[tam];
	q = new float *[tam];

	for(int i = 0; i < tam; i++) {
		r[i] = new float[tam];
		p[i] = new float[tam];
		q[i] = new float[tam];
	}

	for(int i = 0; i < tam; i++) {
		for(int j = 0; j < tam; j++) {
			if(m[i][j] == 0)
				r[i][j] = p[i][j] = q[i][j] = m[i][j];
			else 
				r[i][j] = p[i][j] = q[i][j] = 1;
		}
	}
	cout << endl << "---------------------------Warshall---------------------------" << endl;
	//this->imprimirArreglos();
	cout << endl << "Vertices:";
	for(int i = 0; i < tam; i++)
		cout << vertices[i];	
	cout << endl;
	cout << endl << "---------------------------M ^ 1---------------------------" << endl;

		for(int i = 0; i < tam; i++) {
			cout << endl;
			for(int j = 0; j < tam; j++)
				cout << " " << r[i][j] << " ";
		}
		
		cin.get();

	for(int x = 2; x <= tam-1; x++) {

		for(int i = 0; i < tam; i++)
			for(int j = 0; j < tam; j++) {
				r[i][j] = 0;
				for(int k = 0; k < tam; k++)
					r[i][j] += (p[k][j] * q[i][k]);
			}
				

		for(int i = 0; i < tam; i++)
			for(int j = 0; j < tam; j++){
				p[i][j] = r[i][j];
				/*if(r[i][j] > 1)// preguntar si esta bien esto o no ?????????????
					r[i][j] = 1;*/
			}
				

		cout << endl << "---------------------------M ^ " << x << "---------------------------" << endl;

		for(int i = 0; i < tam; i++) {
			cout << endl;
			for(int j = 0; j < tam; j++)
				cout << " " << r[i][j] << " ";
		}
		
		cin.get();
	}
}

void Grafos :: floyd() {
	float **md;
	
	md = new float * [tam];
	for(int i = 0; i< tam; i++)
		md[i] = new float[tam];
		
	for(int i = 0; i < tam; i++)
		for(int j = 0; j < tam; j++)
			if(m[i][j] == 0)
				md[i][j] = INT_MAX;
			else
				md[i][j] = m[i][j];
				
	for(int k = 0; k < tam; k++)
		for(int i = 0; i < tam; i++)
			for(int j = 0; j < tam; j++)
				if(i != j && i != k && j != k)
					if(md[i][k] + md [k][j] < md[i][j])
						md[i][j] = md[i][k] + md [k][j];
						
	cout << endl << "---------------------------Floyd---------------------------" << endl;

	for(int i = 0; i < tam; i++) {
		cout << endl;
		for(int j = 0; j < tam; j++) {
			if(md[i][j] == INT_MAX)
				cout << " - ";
			else
				cout << " " << md[i][j] << " ";
		}
			
	}
		
	cin.get();
}

void Grafos :: dijkstra(char origen) {
	char *prev;
	int *marc, s = 0, r = 0;
	float *dis, **aux;


	aux = new float *[tam];
	for(int i = 0; i < tam; i++)
		aux[i] = new float[tam];

	prev = new char[tam];
	marc = new int[tam];
	dis = new float[tam];

	for(int i = 0; i < tam; i++) {
		prev[i] = '-';
		marc[i] = 0;
		dis[i] = INT_MAX;

		for (int j = 0; j < tam; j++) {
			if(m[i][j] == 0)
				aux[i][j] = INT_MAX;
			else
				aux[i][j] = m[i][j];
		}
		
		
	}
	cout << endl << "---------------------------Dijkstra---------------------------" << endl;
	for(int i = 0; i < tam; i++)
		if(vertices[i] == origen) {
			s = i;
			break;
		}

	dis[s] = 0;
	marc[s] = 1;
	//prev[r++] = origen; 
	//prev[s] = origen;
	//cout << endl << "s :" << s;cin.get();
	for(int x = 0; x < tam; x++) {
		int menor = INT_MAX;
		for (int i = 0; i < tam; i++) 
			if(marc[i] != 1 && (menor > dis[i])) {
				menor = dis[i];
				s = i;
			}
		
		marc[s] = 1;
	
		for(int i = 0; i < tam; i++)
			if(marc[i] != 1 && i != s) {
				if(dis[s] + aux[s][i] < dis[i]) {
					dis[i] = dis[s] + aux[s][i];
					
				}
			}
		prev[r] = vertices[s];
		r++;
	}
	
	cout << endl << endl << "Vector de distancia minima :";
	for(int i = 0; i < tam; i++)
		cout << " " << dis[i] << " ";
		
	cout << endl << endl << "Vector de Recorrido de distancia minima :";
	for(int i = 0; i < tam; i++)
		cout << " " << prev[i] << " ";
	
	cin.get();
}

void Grafos :: prim() {
	int *marc, vertice = 0;;
	float **aux;
	
	marc = new int[tam];
	aux = new float * [tam];
	
	for(int i = 0; i < tam; i++) {
		marc[i] = 0;
		aux[i] = new float[tam];
		
		for(int j = 0; j < tam; j++)
			aux[i][j] = 0;
	}
	marc[0] = 1;
	while(!this->isMarcado(marc)) {
		int au = INT_MAX;
		for(int i = 0; i < tam; i++) {
			if(marc[i] == 1) {
				for(int j = 0; j < tam; j++) {
					if(m[i][j] != 0) {
						if(marc[j] == 0) {
							if(au > m[i][j])
								au = m[i][j];
						}
					}
				}
			}
		}
		for (int i = 0; i < tam; i++) {
            if(marc[i] == 1) {
                for (int j = 0; j < tam; j++) {
                    if (m[i][j] == au) {
                        if (marc[j] == 0) { //Si no ha sido marcado antes
                            aux[i][j] = au; //Se llena la matriz final con el valor
                        	aux[j][i] = au;//Se llena la matriz final con el valor
                        	marc[j] = 1;
                            break;
                        }
                    }
                }
            }
        }
	}
	
	cout << endl << "---------------------------Prim---------------------------" << endl;
	for(int i = 0; i < tam; i++) {
		cout << endl;
		for(int j = 0; j < tam; j++)
			cout << " " << aux[i][j] << " ";
	}
	cin.get();
}

bool Grafos :: isMarcado(int *v) {
	for(int i = 0; i < tam; i++)
		if(v[i] == 0)
			return false;
			
	return true;
}
#endif
