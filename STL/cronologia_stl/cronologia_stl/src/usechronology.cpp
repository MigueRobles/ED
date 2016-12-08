#include "../include/chronology.h"
#include <fstream>
#include <iostream>

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

chronology c;
historicalevent e2;

e2.setyear("1997");
e2.setevents("Pablo Picasso's Tête de Femme is stolen ");
e2.setevents("Fire damages the Turin Cathedral");
e2.setevents("The Russian–Chechen Peace Treaty is signed");
e2.setevents("The mixed martial arts organization Pride Fighting Championships holds its inaugural event at the Tokyo Dome");

//c1.chrono["1997"] = e2;

 }
