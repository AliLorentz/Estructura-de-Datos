#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;
void loop(char c[3][3]);
void intro_Primero(char c[3][3]);
void tablero (char c[3][3]);
void intro_Yo(char c[3][3]);
void turno_AI(char c[3][3]);
void turno_AI2(char c[3][3]);
int ganador(char c[3][3]);

int main(int argc, char** argv) {
	char c [3][3];
	srand (time(NULL));
	loop(c);//Llama a todas las funciones fundamentales y refresca la pantalla
	system("pause>0");
	return 0;
}

void loop(char c[3][3]){
	
	int i = 0,j;
	intro_Primero(c);
	c[1][1]='O';
	do{
	i++;
	turno_AI2(c);
	system("cls");
	tablero(c);
	j = ganador(c);
	intro_Yo(c);
	j = ganador(c);

	}while(i<=9 && j == 2);
	system("cls");
	cout<<j<<endl<<endl;
	tablero(c);
	if(j=1);
	
	

}

void intro_Primero(char c[3][3]){
	char aux;
	aux = '1';
	for(int i =0 ;i<3;i++){
		for(int j=0; j<3;j++){
			c [i][j]= aux++;
		}
	}
}

void tablero(char c[3][3]){
	for(int i=0 ; i< 3 ; i++){
		for(int j=0; j<3; j++){
			printf(" %c |",c[i][j]);
		}
		if(i < 2)
		printf("\n-------------\n");
	}
	cout<<endl<<endl;
}

void intro_Yo(char c[3][3]){
	char aux;
	int i,j,k;
	do{
		do{
			printf("\nColoca una ficha : ");
			fflush(stdin);
			scanf("%c", &aux);
		}while(aux<'1' || aux> '9');
		
		k=0;
		switch (aux){
			case '1':
			i=0;
			j=0;
			if(c[i][j]=='X' || c[i][j] == 'O'){
				cout<<"Casilla ocupada intente lo de nuevo"<<endl;
				k=1;
			}
			break;
			case '2':
			i=0;
			j=1;
			if(c[i][j]=='X' || c[i][j] == 'O'){
				cout<<"Casilla ocupada intente lo de nuevo"<<endl;
				k=1;
			}
			break;
			case '3':
			i=0;
			j=2;
			if(c[i][j]=='X' || c[i][j] == 'O'){
				cout<<"Casilla ocupada intente lo de nuevo"<<endl;
				k=1;
			}
			break;
			case '4':
			i=1;
			j=0;
			if(c[i][j]=='X' || c[i][j] == 'O'){
				cout<<"Casilla ocupada intente lo de nuevo"<<endl;
				k=1;
			}
			break;
			case '5':
			i=1;
			j=1;
			if(c[i][j]=='X' || c[i][j] == 'O'){
				cout<<"Casilla ocupada intente lo de nuevo"<<endl;
				k=1;
			}
			break;
			case '6':
			i=1;
			j=2;
			if(c[i][j]=='X' || c[i][j] == 'O'){
				cout<<"Casilla ocupada intente lo de nuevo"<<endl;
				k=1;
			}
			break;	
			case '7':
			i=2;
			j=0;
			if(c[i][j]=='X' || c[i][j] == 'O'){
				cout<<"Casilla ocupada intente lo de nuevo"<<endl;
				k=1;
			}
			break;					
			case '8':
			i=2;
			j=1;
			if(c[i][j]=='X' || c[i][j] == 'O'){
				cout<<"Casilla ocupada intente lo de nuevo"<<endl;
				k=1;
			}
			break;
			case '9':
			i=2;
			j=2;
			if(c[i][j]=='X' || c[i][j] == 'O'){
				cout<<"Casilla ocupada intente lo de nuevo"<<endl;
				k=1;
			}
			break;			
		}
	}while(k==1);
	c[i][j]='X';
}

int ganador(char c[3][3]){
	//Linea 7 8 9
	if(c[0][0] == 'X' || c[0][0]=='O'){
		if(c[0][0]==c[0][1] && c[0][0]==c[0][2]){
			if(c[0][0]== 'X'){
				return 0; //He ganado
			}else{
				return 1; //he perdido
			}
		}
		if(c[0][0]== c[1][0] && c[0][0] == c[2][0]){
						if(c[0][0]== 'X'){
				return 0; //He ganado
			}else{
				return 1; //he perdido			
			}
		}
		
	}
	
	if(c[1][1]=='X' || c[1][1]=='O'){
		if(c[1][1]== c[0][0] && c[1][1]== c[2][2]){
				if(c[1][1]== 'X'){
				return 0; //He ganado
			}else{
				return 1; //he perdido
			}
		}
		if(c[1][1]==c[1][0] && c[1][1] == c[1][2]){
				if(c[1][1]== 'X'){
				return 0; //He ganado
			}else{
				return 1; //he perdido
			}			
		}
		
		if(c[1][1]==c[2][0] && c[1][1] == c[0][2]){
				if(c[1][1]== 'X'){
				return 0; //He ganado
			}else{
				return 1; //he perdido
			}			
		}
		if(c[1][1]==c[0][1] && c[1][1] == c[2][1]){
				if(c[1][1]== 'X'){
				return 0; //He ganado
			}else{
				return 1; //he perdido
			}			
		}		
		
	}
	
	if(c[2][2]== 'X' || c[2][2] == 'O'){
		if(c[2][2] == c[2][0] && c[2][1]==c[2][1]){
				if(c[2][2]== 'X'){
				return 0; //He ganado
			}else{
				return 1; //he perdido
			}			
		}
		
		if(c[2][2] == c[0][2] && c[2][2]==c[1][2]){
				if(c[2][2]== 'X'){
				return 0; //He ganado
			}else{
				return 1; //he perdido
			}			
		}		
	}
	
	return 2; //NADIE GANA
	
}


void turno_AI(char c[3][3]){
	
	int alarm=0;
	string datos,datos2[3],aux;;

	for(int i = 0 ;i <3 ;i++){
		for(int j=0 ; j<3 ; j++){
			if(c[i][j]=='X')
				datos+="1";	
				else
				datos+="0";
				if(c[i][j]=='X')
				datos2[i]+="1";
				else if( c[i][j]=='O')
				datos2[i]+="2";
				else
				datos2[i]+="0";
				
		}
	}
//	if(datos=="100000000"){
//		c[2][2]='O';
//			return;
//	}else if(datos=="001000000"){
//		c[0][2]='O';
//			return;
//	}else if(datos=="000000100"){
//		c[0][2]='O';
//			return;
//	}else if(datos=="000000001"){
//		c[0][0]='O';
//			return;
//	}
	
	//Comprobar si podemos ganar horizontal o bloquemos
	int con;
	for(int z=0; z<3;z++){
	aux=datos2[z];
	con= atoi(aux.c_str());
	if(con==22){
		for(int i=0; i<aux.size(); i++ ){
			if(aux[i]=='0'){
				if(c[z][i]!='X' && alarm==0){
				c[z][i]='O';
				alarm=1;
				}		
			}
		}
	}else if(con==11){
			for(int i=0; i<aux.size(); i++ ){
			if(aux[i]=='0' && alarm==0){
				if(c[z][i]!='X'){
				c[z][i]='O';
				alarm=1;
				}

			}
		}
	}
	}
	//Comprobar si ganamos vertical o bloqueamos 
	int conv[3];
	string a=datos2[0],b=datos2[1],cc=datos2[2];
	for(int i=0 ;i<a.size();i++){
		if(b[i]==a[i] && alarm==0){
			if(c[2][i]!='X' ){
			c[2][i]='O';
			alarm=1;
			}

		}else if(b[i]==cc[i] && alarm==0){
			if(c[0][i]!='X'){
			c[0][i]='O';
			alarm=1;
			}

		}	
	}
	//Comprobar si ganamos en diagonal o bloqueamos
	if(c[1][1]==c[0][0]){
		if(c[2][2]!='X' && alarm==0){
		c[2][2]='O';
		alarm=1;
		}
	}else if(c[1][1]==c[2][2]){
		if(c[0][0]!='X' && alarm==0){
		c[0][0]='O';
		alarm=1;
		}

	}
	int bandera=0;
	do{
			int XX = rand()%2+1;
			int YY = rand()%2+1;
			
		if(c[XX][YY]!='X' && alarm==0){
			c[XX][YY]='O';
			bandera=1;
			alarm=0;
		}
	}while(bandera==0 && alarm==0);

}

void turno_AI2(char c[3][3]){
	int contX=0,XX,YY,band=0;
	for(int i =0; i<3; i++){
		for(int j=0; j<3; j++){
			if(c[i][j]!='X'){
			
				
			}else{
			contX++;
			XX=i,YY=j;
			}
	
		}
	}
	
	if(c[0][1]=='X' || c[2][1]=='X'){
		if(contX==1){
			c[XX][0]='O';
			return;
		}
	}
	
	if(XX<2)
	turno_AI(c);
	
	
} 

	 
