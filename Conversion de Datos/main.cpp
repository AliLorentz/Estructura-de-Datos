#include <iostream>
#include <cstring>//String  a char
#include <string>// string a char
#include <stdlib.h> /*Atoi string a int*/
#include <sstream>

/*CoNVERSION DE DATOS */
using namespace std;
int main(int argc, char** argv) {
/*---------------CHAR----------------------------*/

/*De char a int y para long*/
char a[]="4654163";
int auxA = (int)a;
long auxD =(long)a;
cout<<auxA<<" "<<auxD<<endl;;

/*De char a String*/
char aa[]="TheGoat";
string auxB=aa;
cout<<auxB<<endl;

/*De char a Bool*/
 char ac='1';
 bool auxC=ac;
 cout<<auxC<<endl;
 
 /*de char a float, tambien puede separar tokens*/
 char ad[]="12.34 2.3 4.5";
 char* tok, *tok2;
 float f1,f2,f3;
 f1 = strtof(ad,&tok);
 f2 =strtof(tok,&tok2);
 f3=strtof(tok2,NULL);
 cout<<f1<<"|"<<f2<<"|"<<f3<<endl;

/*------STRING----------------------------------*/

/*De string a char | #include <cstring> | #include <string> */
string b="Hola mundo";
char bCha[100];
strcpy(bCha,b.c_str());
cout<<bCha<<endl;
	
/*De string a int    #include <stdlib.h> */
string bb="123456";
int bInt = atoi(bb.c_str());
cout<<bInt<<endl;

/*De string a double*/
string bc="123.4";
float bFloat=atof(bc.c_str());
cout<<bFloat<<endl;

/*De igual manera existen
atol = Convert string to long integer
*/



/*-----------------INT---------------------*/

/*De int a char*/
int c=1324;
char cCha[50];
itoa(c,cCha,10); //si el ultimo parametro es 10 retorna decimal |16 hexadecimal |2 binario
cout<<"Int:"<<cCha<<endl;

/*De int a string |#include <sstream>*/
stringstream ss;
ss<<c;
string number = ss.str();
cout<<"Listo:"<<number<<endl;


}
