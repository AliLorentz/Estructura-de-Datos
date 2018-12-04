#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

template <class T>
class Mezcla_Directa {
	
	//private:
		string nombre_archivo;
		
	public:
		Mezcla_Directa(string nombre_archivo);
		void Ordenar(int &N);
		void Partir(fstream &archivo_1, fstream &archivo_2, int &bloque);
		void Mezclar(fstream &archivo_1, fstream &archivo_2, int &bloque, int &N);
		
};

template <class T>
Mezcla_Directa<T>::Mezcla_Directa(string nombre_archivo) { 
	this->nombre_archivo = nombre_archivo;
}

template <class T>
void  Mezcla_Directa<T>::Partir(fstream &archivo_1, fstream &archivo_2, int &bloque) {
			T buffer;
			int cadena_1 = 0, cadena_2;
			fstream archivo;
			
			archivo.open(nombre_archivo.c_str(), ios::in | ios::binary);
			archivo_1.open("particion_1.dat", ios::out | ios::binary); 
			archivo_2.open("particion_2.dat", ios::out | ios::binary); 
			archivo.clear(); archivo_1.clear(); archivo_2.clear();
			
			archivo.seekg(0, ios::beg); 
			while (true) {
				archivo.read((char*)&buffer, sizeof(buffer));
				if (archivo.eof()) {
					break;	
				}
				
				if (cadena_1 < bloque) {
				    archivo_1.write((char*)&buffer, sizeof(buffer));
				    cadena_1++; 
				    if (cadena_1 == bloque){
				    	cadena_2 = 0;	
					} 
				} else {
				    archivo_2.write((char*)&buffer, sizeof(buffer));
				    cadena_2++; 
				    if (cadena_2 == bloque) { 
				    	cadena_1 = 0;
					}
				}
			}
			
			archivo.close();
			archivo_1.close();
			archivo_2.close();  
}

template <class T>
void Mezcla_Directa<T>::Ordenar (int &N) {
	fstream particion_1, particion_2;
	int bloque = 1;
	
	while (bloque < N) {
		Partir (particion_1, particion_2, bloque);
		Mezclar(particion_1, particion_2, bloque, N );
		bloque *=2;
	}
	remove("particion_1.dat");
	remove("particion_2.dat");
}



template <class T>
void Mezcla_Directa<T>::Mezclar(fstream &archivo_1, fstream &archivo_2, int &bloque, int &N) {
			T buffer_1, buffer_2;
			int cadena_1 = 0, cadena_2 = 0;
			fstream archivo;
			
			archivo.open(nombre_archivo.c_str(), ios::out | ios::binary);
			archivo_1.open("particion_1.dat", ios::in  | ios::binary); 
			archivo_2.open("particion_2.dat", ios::in  | ios::binary); 
			archivo_1.clear(); archivo_2.clear(); archivo.clear();
			archivo_1.seekg(0, ios::beg);
			archivo_2.seekg(0, ios::beg); 
			archivo_1.read((char*)&buffer_1, sizeof(buffer_1));
			archivo_2.read((char*)&buffer_2, sizeof(buffer_2));
			for (int i = 0; i < N; i++) {
				if (buffer_1 < buffer_2) {
					if (cadena_1 < bloque) {
						archivo.write((char*)&buffer_1, sizeof(buffer_1));
						cadena_1++;
						archivo_1.read((char*)&buffer_1, sizeof(buffer_1)); 
					} else {
						archivo.write((char*)&buffer_2, sizeof(buffer_2));
						cadena_2++;
						archivo_2.read((char*)&buffer_2, sizeof(buffer_2));
					}
				} else {
					if (cadena_2 < bloque) {
						archivo.write((char*)&buffer_2, sizeof(buffer_2));
						cadena_2++;
						archivo_2.read((char*)&buffer_2, sizeof(buffer_2));
					}
					else {
						archivo.write((char*)&buffer_1, sizeof(buffer_1));
						cadena_1++;
						archivo_1.read((char*)&buffer_1, sizeof(buffer_1)); 
					}
				}
				if (archivo_1.eof()) buffer_1.setValue(99999);
				if (archivo_2.eof()) buffer_2.setValue(99999);
				if (cadena_1 == bloque && cadena_2 == bloque) cadena_1 = cadena_2 = 0;
			}
			archivo.close();
			archivo_1.close();
			archivo_2.close();  
}
