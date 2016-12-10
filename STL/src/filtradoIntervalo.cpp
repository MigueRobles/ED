#include "chronology.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){
/*
  if (argc!=4 && argc!=5){
      cout<<"Error: debe dar el nombre de un archivo origen y los limites anuales . "<<endl;
      cout<<"[Opcional]: un segundo nombre de fichero para guardar la cronología resultante."<<endl;
      return 0;
   }
*/
   ifstream f1 (argv[1]);
   if (!f1){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }

   chronology origen;
   chronology destino;

   f1 >> origen;

   destino.insertrange("1500", "1750");

   cout << destino;








/*
    if (argc==4)   //No se dio fichero de salida, imprimimos en cout
      cout << cUnion;
    else{
     ofstream fout(argv[3]);
     if (!fout){
      cout<<"No puedo crear el fichero "<<argv[3]<<endl;
      return 0;
     }
     fout << cUnion;

   }*/
}
