//Cola_celdas.CPP

#include <cola_celdas.h>
#include <cassert>

Cola::Cola(): primera(0), ultima(0){}

Cola::Cola(const Cola& c){
  if (c.primera==0)
    primera= ultima= 0;
  else {
    primera= new CeldaCola;
    primera→elemento= c.primera→elemento;
    CeldaCola ∗src=c.primera;
    ultima=primera;
    while (src→sig! =0) {
      ultima→sig= new CeldaCola;
      src= src→sig;
      ultima= ultima→sig;
      ultima→elemento= src→elemento
    }
    ultima→sig=0;
  }
}

Cola::∼Cola(){
  CeldaCola ∗aux;
  while (primera! =0) {
    aux= primera;
    primera= primera→sig;
    delete aux;
  }
}

Cola& Cola::operator= (const Cola& c){
  Cola caux(c);
  CeldaCola ∗aux;
  aux= this→primera;
  this→primera= caux→primera;
  caux→primera= aux;
  aux= this→ultima;
  this→ultima= caux→ultima;
  caux→ultima= aux;
  return ∗this;
}

void Cola::poner(TBase c){
  CeldaCola ∗aux= new CeldaCola;
  aux→elemento= c;
  aux→sig= 0;
  if (primera==0) primera=ultima=aux;
  else {
    ultima→sig= aux;;
    ultima= aux;
  }
}

void Cola::quitar(){
  assert (primera! =0);
  CeldaCola ∗aux= primera;
  primera= primera→sig;
  delete aux;
  if (primera==0) ultima=0;
}

TBase Cola::frente() const{
  assert (primera! =0);
  return primera→elemento;
}
