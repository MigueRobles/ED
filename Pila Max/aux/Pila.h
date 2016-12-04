//PILA.H celdas enlazadas

#ifndef PILA_H__
#define PILA_H__

typedef char Tbase;
struct CeldaPila{
  Tbase elemento;
  CeldaPila ∗sig;
};

class Pila{
    CeldaPila *primera;
  public:
    Pila();
    Pila(const Pila& p);
    ∼Pila();
    Pila& operator= (const Pila& p);
    bool vacia() const;
    void poner (TBase c)
    void quitar();
    Tbase tope() const;
};

#endif
