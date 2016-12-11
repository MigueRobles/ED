#include "chronology.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){
  string palabra_clave;

  if (argc > 4 && argc < 2){
    cout<<"Error: debe dar el nombre de un archivo origen. "<<endl;
    cout<<"[Opcional]: palabra clave por la que buscar. Si no se especifica, se pedirá por teclado " <<endl;
    cout<<"[Opcional]: un segundo nombre de fichero para guardar la cronología resultante."<<endl;
    return 0;
  }

  ifstream f (argv[1]);
  if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
  }

  if (argc > 2)
    palabra_clave = argv[2];
  else{
    cout << "Introduce la palabra clave por la que buscar los eventos: ";
    cin >> palabra_clave;
  }

  chronology c1;
  f >> c1;
  chronology cFiltrado(c1, palabra_clave);


  if (argc<=3)   //No se dio fichero de salida, imprimimos en cout
    cout << cFiltrado;
  else{
    ofstream fout(argv[3]);
    if (!fout){
      cout<<"No puedo crear el fichero "<<argv[3]<<endl;
      return 0;
    }
    fout << cFiltrado;
  }
};
