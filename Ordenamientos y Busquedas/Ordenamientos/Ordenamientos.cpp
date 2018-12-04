#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void Burbuja(int v[], int n);
void BurbujaMejorada(int v[], int n);
void SeleccionDirecta(int v[], int n);
void InsercionDirecta(int v[], int n);
void Shaker(int v[], int n);
void Shell(int v[], int n);
void ShellMejorado(int v[], int n);
void Mostrar(int v[], int n);

int main(int argc, char *argv[]) {
	
	srand(time(NULL));
	
	int n = 25;
	int v[n];
	for (int i = 0; i < n; i++) 
		v[i] = rand()%100+1;
	
	cout << "Antes: ";
	Mostrar(v, n);
	ShellMejorado(v, n);
	cout << "Despues: ";
	Mostrar(v, n);
	
	system("PAUSE");
    return EXIT_SUCCESS;
}

void Burbuja(int v[], int n) {
	int aux;
	for (int i = 0; i < n; i++){
		for (int j = 0 ; j < n-1; j++){
			if (v[j] > v[j+1]){
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;	
			}	
		}		
	}	
}

void BurbujaMejorada(int v[], int n) {
	int aux;
	bool band; 
	
	for (int i = n-1 ; i > 0 ; i--){
		band = true;
		for (int j = 0 ; j < i ; j++){
			if (v[j] > v[j+1]){
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
				band = false;
			}
		}
		if (band == true)
			break;
	}
}

void SeleccionDirecta(int v[], int n) {
	int i, j, mayor, pos = 0, aux;
	
	for (i = n-1; i >= 0; i--) {
		mayor = v[0];
		pos = 0;
		for (j = 0; j <= i; j++) {
			if (v[j] > mayor) {
				mayor = v[j];
				pos = j;
			}
		}
		aux = v[i];
		v[i] = v[pos];
		v[pos] = aux;
	}
}

void InsercionDirecta(int v[], int n) {
	int aux, pos;
	for (int i = 1; i < n; i++){
		pos = i;
		aux = v[i];
		while (pos > 0 && aux < v[pos-1]) {
			v[pos] = v[pos-1];
			pos--;
		}
		v[pos] = aux;
	}
}

void Shaker(int v[], int n) {
	int inicio = 0, final = n-1;
	int aux;
	bool band = false;
	int cont = 0;
	
	do {	
		if (!band) {
			for (int i = 0; i < final; i++) {
				if (v[i] > v[i+1]) {
					aux = v[i];
					v[i] = v[i+1];
					v[i+1] = aux;
				}
			}
			band = true;
			final--;		
		}
		if (band) {	   
			for (int i = final ; i > inicio; i--) {
				if (v[i] < v[i-1]) {
					aux = v[i];
					v[i] = v[i-1];
					v[i-1] = aux;
				}
			}
			band = false;
			inicio++;		
		}	
		cont++;
	} while (cont < n/2);	
}

void Shell(int v[], int n) {
	int aux;
	
	for (int i = n/2; i > 0; i /= 2){
		for (int j = i; j < n; j++){
            for (int k = j - i; k >= 0; k = k - i){
                if (v[k+i] >= v[k])
                    break;
                else {
                    aux = v[k];
                    v[k] = v[k+i];
                    v[k+i] = aux;
                }
            }
        }		
	}
}

void ShellMejorado(int v[], int n) {
	bool band;
	int inc = n/2, aux;
	
	while (inc > 0){
		band = false;
		for (int i = 0; i+inc < n; i++) {
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

void Mostrar(int v[], int n) { 
	for (int i = 0 ; i < n ; i++)
		cout << v[i] << " ";
	cout << endl;
}
