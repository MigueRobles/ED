//PILA.CPP celdas

#include<pila.h>
#include<cassert>

Pila::Pila(): primera(0){}

Pila::Pila(const Pila& p){
  if (p.primera==0)
    primera= 0;
  else{
    primera= new CeldaPila;
    primera→elemento=p.primera→elemento;
    CeldaPila∗src=p.primera,∗dest=primera;
    while (src→sig! =0){
      dest→sig= new CeldaPila;
      src= src→sig;
      dest=dest→sig;
      dest→elemento= src→elemento
    }
    dest→sig=0;
  }
}
Pila::∼Pila(){
  CeldaPila ∗aux;
  while (primera! =0){
    aux=primera;
    primera=primera→sig;
    delete aux;
  }
}


Pila& Pila::operator= (const Pila& p){
  Pila paux(p);
  CeldaPila ∗aux;
  aux= this→primera;
  this→primera= paux→primera;
  paux→primera= aux;
  return ∗this;
}

void Pila::poner(TBase c){
  CeldaPila ∗aux= new CeldaPila;
  aux→elemento= c;
  aux→sig= primera;
  primera= aux;
}

void Pila::quitar(){
  assert (primera! =0);
  CeldaPila ∗aux= primera;
  primera= primera→sig;
  delete aux;
}

TBase Pila::tope() const{
  assert (primera! =0);
  return primera→elemento;
}

bool Pila::vacia() const{
  return primera==0;
}
