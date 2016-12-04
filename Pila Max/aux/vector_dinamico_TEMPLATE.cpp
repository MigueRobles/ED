//Vector_Dinamico.CPP //Con template

#include <cassert>
#include "Vector_Dinamico_TEMPLATE.h"

template<class T>
void intercambiar(T& a, T& b){
  T aux=a;
  a=b;
  b=aux;
}

template<class T>
Vector_Dinamico<T>::Vector_Dinamico<T>(int n){
  assert(n>=0);
  if (n>0)
    datos = new T[n];
  nelementos = n;
}


template<class T>
Vector_Dinamico<T>& Vector_Dinamico<T>::operator=(const Vector_Dinamico<T>& original){
  if (this! == &original){
    if(nelementos > 0)
      delete[] datos;
    nelementos = original.nelementos;
    datos = new T[nelementos];
    for (int i=0; i < nelementos; ++i)
      datos[i] = original.datos[i];
  }
  return *this;
}

template<class T>
void ordenar_seleccion (Vector_Dinamico<T>& vector){
  int i, minimo;
  for (i=0; i<vector.size()-1; i++){
    minimo = i;
    for (j=i+1; j<vector.size(); j++)
      if (vector[j] < vector[minimo])
        minimo = j;
    intercambiar(vector[i], vector[minimo]);
  }
}
