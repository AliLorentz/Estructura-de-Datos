class Alumno
{
      int ced;
      char nom[30];
   public:
      Alumno() { }
      Alumno( int v, char *c ) { ced=v; strcpy(nom,c); }
      int Get_ced()  { return ced; }
      char *Get_nom(){ return nom; }
      bool operator<(Alumno &a)  { return this->ced<a.ced;  }
      bool operator==(Alumno &a) { return this->ced==a.ced; }
      friend ostream & operator<<(  ostream &os, Alumno  c ) { 
          os<< " "<<c.ced<<"  "<<c.nom; 
          return os;
       } 
};

Alumno funcion( char c[180] )
{
       char val2[30], *p;
       p= strtok(c,",");
       int val1= atoi(p);
       p=strtok(NULL,"\n");
       strcpy(val2,p);
       return ( Alumno(val1,val2) );
}

