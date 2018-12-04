#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include "Persona.h"

using namespace std;

template <class T>
void ShellMejorado(vector<T> &v);

void llenar(vector<Persona> &p);

int main(int arc, char**argv) {
	
	vector<Persona> lista;
	llenar(lista);
	ShellMejorado(lista);
	for (int i = 0; i < lista.size(); i++)
		lista[i].imprimir();
	
	return 0;
}

void llenar(vector<Persona> &p) {

	fstream file;
	file.open("datos.txt", ios::in);
	string linea;
	char *separar;
	
	if (file.fail())
		cout << "error al abrir el archivo " << endl;
	else {
		while (getline(file, linea)) {
			separar = strtok(&linea[0],"\t");
			int cedula = atoi(separar);
			separar = strtok(NULL,"\t");
			string apellido = (string)separar;
			separar = strtok(NULL,"\t");
			string nombre = separar;
			separar = strtok(NULL,"\t");
//			cout << cedula << " " << nombre << " " << apellido << endl;
			Persona luis(cedula, nombre, apellido);
			p.push_back(luis);
		}
	}
	

	
		
}

template <class T>
void ShellMejorado(vector<T> &v) {
	bool band;
	int inc = v.size()/2;
	T aux(0, "", "");
	
	while (inc > 0){
		band = false;
		for (int i = 0; i+inc < v.size(); i++) {
			if (v[i] > v[i+inc]) {
				aux = v[i];
				v[i] = v[i+inc];
				v[i+inc] = aux;
				band = true;
			}
		}
		if (!band)
			inc /= 2;
	}
}
