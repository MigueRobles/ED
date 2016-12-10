
#include <fstream>
#include <iostream>
#include "chronology.h"


int main(int argc , char * argv[]){
    if (argc!=2){
        cout<<"Tell me the file name with the chronology"<<endl;
        return 0;
    }
    ifstream f(argv[1]);
    if (!f){
        cout<<"Imposible to open the file "<<argv[1]<<endl;
        return 0;
    }

  chronology c1;

  f>>c1;
  cout << endl <<"Testing in/out:" << endl;

  cout << c1;


  //-------------------------------------------------------------------------------
  historicalevent e1;

  e1.setyear("1996");
  e1.setevents("Pablo Picasso's Tête de Femme is stolen ");
  e1.setevents("Fire damages the Turin Cathedral");
  e1.setevents("The Russian–Chechen Peace Treaty is signed");
  e1.setevents("The mixed martial arts organization Pride Fighting Championships holds its inaugural event at the Tokyo Dome");
  //-------------------------------------------------------------------------------
  historicalevent e2;

  e2.setyear("1999");
  e2.setevents("BOOOOM");
  e2.setevents("KABOOOOOM");
  //-------------------------------------------------------------------------------
  cout << endl <<"Testing insert:" << endl;
  chronology c2;

  c2.insert(e1);
  c2.insert(e2);


  cout << c2;
  //-------------------------------------------------------------------------------

  cout << endl <<"Testing assignation constructor:" << endl;
  chronology c3;
  chronology c4(c3);
  chronology c5(c2);
  cout <<"C3:" << c3 << endl;
  cout <<"C4:" << c4 << endl;
  cout <<"C5:" << c5 << endl;

  //-------------------------------------------------------------------------------
  cout << endl <<"Testing []:" << endl;
  historicalevent e3;
  e3 = c2["1999"];
  c3.insert(e3);

  cout <<"C3:" << c3 << endl;

  //-------------------------------------------------------------------------------

  chronology cUnion;

  cUnion = c1 + c3;
  cout << endl <<"Testing operator +:" << endl;

  cout << cUnion;

 }
