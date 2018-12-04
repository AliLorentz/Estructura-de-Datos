#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

template <class T> //Nos ahorra tener que crear un nuevo metodo de ordenamiento
void Shell(T v[], int n) {
	T aux;
	
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


int main(int argc, char** argv) {

	char vec[]={'L','O','R','E','N','T'}; //vec de caracteres
	int n =6;
	
	Shell(vec,n);
	for(int i =0;i<n;i++){ //Mostramos
		cout<<vec[i]<<" ";
	}
	
	int vec2[]={1,4,2,5,7}; //vec de int
	int n2=5;
	Shell(vec2,n2);
	cout<<endl<<endl;
	for(int i =0;i<n2;i++){//Mostramos
		cout<<vec2[i]<<" ";
	}
	
	string vec3[]={"AD","AC","AB","AA"}; //Vec de string
	int n3=4;
	Shell(vec3,n3);
	cout<<endl<<endl;
	for(int i =0;i<n3;i++){//Mostramos
		cout<<i+1<<")"<<vec3[i]<<" ";
	}
	
}


