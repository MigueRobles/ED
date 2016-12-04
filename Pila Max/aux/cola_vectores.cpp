//Cola_vectores.CPP

#include<cola_vectores.h>
#include<cassert>

void Cola::resize(int n){
  assert(n>=numelem && n>0);
  Tbase ∗aux= new Tbase[n];
  for (int i=0;i<numelem;++i)
    aux[i]= datos[(anterior+i) %reservados];
  anterior=0;
  posterior= anterior+ numelem;
  delete[] datos;
  datos= aux;
  reservados=n;
}

Cola::∼Cola(){
  delete[] datos;
}

Cola::Cola(){
  datos= new Tbase[1];
  reservados= 1;          // siempre >=1
  anterior= posterior= numelem= 0;
}

Cola::Cola(const Cola& c){
  reservados= c.reservados;
  datos= new Tbase[c.reservados];
  for (int i=anterior;i! =posterior;i=(i+1) %reservados)
    datos[i]= c.datos[i];
  anterior=c.anterior;
  posterior=c.posterior;
  numelem=c.numelem;
}

Cola& Cola::operator= (const Cola& c){
  if (this! =&c) {
    delete[]datos;
    reservados=c.reservados;
    datos= new Tbase[c.reservados];
    for (int i=anterior;i! =posterior;i=(i+1) %reservados)
      datos[i]= c.datos[i];
    anterior=c.anterior;
    posterior=c.posterior;
    numelem=c.numelem;
  }
  return ∗this;
}

void Cola::poner(TBase c){
  if (numelem==reservados)
    resize(2∗reservados);
  datos[posterior]= c;
  posterior= (posterior+1)%reservados;
  numelem++;
}

void Cola::quitar(){
  assert (numelem! =0);
  anterior=(anterior+1)%reservados;
  numelem--;
  if (numelem<reservados/4)
    resize(reservados/2);
}

TBase Cola::frente() const{
  assert (numelem! =0);
  return datos[anterior];
}
