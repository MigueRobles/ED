#include "chronology.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){

  if (argc > 5 && argc < 2 && argc != 3){
      cout<<"Error: debe dar el nombre de un archivo origen. "<<endl;
      cout<<"[Opcional]: 2 limites anuales. Si no se especifica, se pedirá por teclado " <<endl;
      cout<<"[Opcional]: un segundo nombre de fichero para guardar la cronología resultante."<<endl;
      return 0;
   }


   ifstream f1 (argv[1]);
   if (!f1){
     cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
     return 0;
   }

     string min;
     string max;
     if (argc > 2){
       min = argv[2];
       max = argv[3];
     }else{
       cout << "Introduce el minimo: ";
       cin >> min;
       cout << "Introduce el max: ";
       cin >> max;
     }

    chronology origen;

    f1 >> origen;

    chronology destino(origen.insertrange(min, max));



    if (argc==2 || argc == 4){   //No se dio fichero de salida, imprimimos en cout
      if(destino.year() != "-1"){
        cout << "Los eventos entre " << min << " y " << max << " son: "<< endl;
        cout << destino;
      }
      else
        cout << "No hay eventos entre esos años" << endl;
    }else if( argc == 3 || argc == 5){
     ofstream fout(argv[4]);
     if (!fout){
      cout<<"No puedo crear el fichero "<<argv[3]<<endl;
      return 0;
     }
     fout << destino;
   }

}
