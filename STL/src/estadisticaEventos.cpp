#include "chronology.h"
#include <fstream>
#include <iostream>

using namespace std;

double average(chronology c){ //promedio de acontecimientos de los eventos de la cronologia
  double num_event = c.num_event();
  if (c.num_event() != 0)
    return c.num_happening()/num_event;
  else
    return 0;
}

int main(int argc, char * argv[]){

  if (argc != 2){
    cout<<"Error: debe dar el nombre de un archivo origen. "<<endl;
    return 0;
  }

  ifstream f (argv[1]);
  if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
  }
  chronology c;
  f >> c;


  cout << "******ESTADISTICAS*******" << endl;
  cout << endl;
  cout << "Numero total de años que tienen Eventos Historicos en la cronologia: " << c.num_event() << endl;
  cout << "Numero total de acontecimientos: " << c.num_happening() << endl;
  cout << "Maximo de acontecimientos en un año: " << c.max() << endl;
  cout << "Promedio de acontecimientos en un año: " << average(c) << endl;
/*
Para ello, se propone calcular el número total de años para
los que se especifican EventoHistóricos en la cronología, el número total de acontecimientos,
y el máximo y promedio de estos acontecimientos por año.
*/
};
