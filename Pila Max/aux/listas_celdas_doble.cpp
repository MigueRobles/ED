include "listas_celdas_doble.h"
include <cassert>

Lista::Lista() {
  cab= new CeldaLista;
  cab → siguiente= cab;
  cab → anterior=cab;
}

Lista::Lista(const Lista& l) {
  cab= new CeldaLista;
  cab → siguiente= cab;
  cab → anterior=cab;
  CeldaLista ∗ p= l.cab → siguiente;
  while (p ! = l.cab) {
    CeldaLista ∗ q;
    q= new CeldaLista;
    q → elemento=p → elemento;
    q → anterior= cab → anterior;
    cab → anterior → siguiente= q;
    cab → anterior= q;
    q → siguiente =cab;
    p= p → siguiente;
  }
}

Lista:: ∼ Lista() {
  while (begin() ! = end())
    borrar(begin());
  delete cab;
}

Lista& Lista::operator= (const Lista& l) {
  Lista aux(l);
  CeldaLista ∗ p;
  p=this → cab;
  this → cab= aux.cab;
  aux.cab=p;
  return ∗ this;
}

Posicion Lista::insertar(Posicion p, Tbase e) {
  CeldaLista ∗ q= new CeldaLista;
  q → anterior= p.puntero → anterior;
  q → siguiente=p.puntero;
  p.puntero → anterior= q;
  q → anterior → siguiente= q;
  q → elemento= e;
  p.puntero=q;
  return p;
}

Posicion Lista::borrar(Posicion p) {
  assert (p ! = end());
  CeldaLista ∗ q= p.puntero;
  q → anterior → siguiente= q → siguiente;
  q → siguiente → anterior= q → anterior;
  p.puntero=q → siguiente;
  delete q;
  return p;
}
