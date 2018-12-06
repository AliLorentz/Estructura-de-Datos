#ifndef VUELOS_H
#define VUELOS_H

using namespace std;
class Vuelos
{
	int nom;
	int retorno;
	int ida;
	public:
		Vuelos();
		vuelos(int n,int ret,int id){
			n=nom;
			ret=retorno;
			id=ida;
		}
		void calcular(){
		}
		~Vuelos();
	protected:
};

#endif
