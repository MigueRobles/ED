#include <iostream>

using namespace std;

template <class T>
struct elemento{
  T ele; // elemento a almacenar
  T maximo; // el máximo
};
template <class T>
ostream& operator<< (ostream& os, const elemento<T>& element){
  return os << "Elemento: " << element.ele << ", Maximo: " << element.maximo << endl;
}

 #define CUAL_COMPILA 2
 #if CUAL_COMPILA==1
 #include "pila_max_vd.h"
 #elif CUAL_COMPILA==2
 #include "pila_max_lista.h"
 #else
 #include "pila_max_cola.h"
 #endif
