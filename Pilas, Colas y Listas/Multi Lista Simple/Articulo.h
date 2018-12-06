#include <iostream>
using namespace std;

class Articulo{
	int cod;
	string nom;
	
	public:
		Articulo(){cod=0; nom=" ";}
		Articulo(int c, string n){cod=c; nom=n;}
		void set_Cod(int c);
		void set_Nom(string n);
		int get_Cod();
		string get_Nom();
		void Imprimir();
		
		bool operator <(Articulo A){	return this->cod<A.cod;	}
		bool operator >(Articulo A){	return this->cod>A.cod;	}
		bool operator ==(Articulo A){	return this->cod==A.cod;	}
		
		
		friend ostream & operator << (ostream &p, Articulo A){
			return p<<"  "<<A.cod<<"\t   "<<A.nom; 
		}
};

void Articulo::set_Cod(int c){	cod=c;	}

void Articulo::set_Nom(string n){	nom=n;	}

int Articulo::get_Cod(){	return cod;	}

string Articulo::get_Nom(){	return nom;	}

void Articulo::Imprimir(){
	cout<<"COD: "<<cod<<"\t NOMBRE: "<<nom<<endl;
}
