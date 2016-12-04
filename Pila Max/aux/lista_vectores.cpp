#include "lista_vectores_h"
#include <cassert>

void Lista::resize(int n) {
  assert(n >= nelementos && n > 0);
  Tbase ∗ aux= new Tbase[n];
  for (int i=0;i < nelementos;++i)
    aux[i]= datos[i];
  delete[] datos;
  datos= aux;
  reservados= n;
}

Lista::Lista(const Lista& l) {
  datos= new Tbase[l.reservados];
  nelementos=l.nelementos;
  reservados=l.reservados;
  for (int i=0;i < nelementos;i++)
    datos[i]=l.datos[i];
}

Lista& Lista::operator= (const Lista& l) {
  Lista aux(l);
  Tbase ∗ paux;
  paux=datos; datos=l.datos; l.datos=paux;
  int iaux;
  iaux=nelementos; nelementos=l.nelementos; l.nelementos=iaux;
  iaux=reservados; reservados=l.reservados; l.reservados=iaux;
  return ∗ this;
}

Posicion Lista::insertar(Posicion p, Tbase e) {
  if (nelementos==reservados) resize(2 ∗ reservados);
  for (int j=nelementos;j > p.i;--j)
    datos[j]= datos[j-1];
  datos[p.i]=e;
  nelementos++;
  return p;    // posición del insertado
}

Posicion Lista::borrar(Posicion p) {
  assert (p ! = end());
  for (int j=p.i;j < nelementos-1;;++j)
  datos[j]=datos[j+1];
  nelementos--;
  if (nelementos < reservados / 4) resize(reservados / 2);
  return p;    // posición del siguiente
}
