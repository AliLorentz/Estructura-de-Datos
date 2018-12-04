#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
void shell(vector <string> &vec){
	//cambiamos de enteros a string
	string tmp;
	//Hay que cambiar la n por vec.size para conocer el tamaño del vector
	for(int i=vec.size()/2;i>0;i/=2){
		for (int j = i; j < vec.size(); j++){
            for(int k = j - i; k >= 0; k = k - i){
                if(vec[k+i] >= vec[k])
                    break;
                else{
                    tmp = vec[k];
                    vec[k] = vec[k+i];
                    vec[k+i] = tmp;
                }
            }
        }		
	}

	
}


int main(int argc, char** argv) {

	vector<string>lista;
	
	fstream archivo("Nombres2.txt", ios::in);
	
	if(archivo.fail())
		cout<<"No funciona"<<endl;
	else{
		string linea;
		char *separar;
		
		while(getline(archivo,linea)){
			lista.push_back(linea);//Guardo xD
		}
	}
	archivo.close();
		
	for(int i=0;i< lista.size();i++){
		cout<<lista[i]<<endl;
	}
	cout<<endl<<endl;
	
	shell(lista);//Lo ordenamos
	
		for(int i=0;i< lista.size();i++){
		cout<<lista[i]<<endl;
	}
	
	
	return 0;
}
