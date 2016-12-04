//Colas_celdas.h

#ifndef COLA H
#define COLA H

typedef char Tbase;

struct CeldaCola{
  Tbase elemento;
  CeldaCola ∗sig;
};

class Cola{
    CeldaCola ∗primera;
    CeldaCola ∗ultima;
  public:
    Cola();
    Cola(const Cola& p);
    ∼Cola();
    Cola& operator= (const Cola& p);
    bool vacia() const { return primera==0;}
    void poner (TBase c);
    void quitar();
    Tbase frente() const;
};

#endif
