//Cola.h vectores

#ifndef _Cola_H_
#define _Cola_H_

typedef char Tbase;

class Cola{
    Tbase ∗datos;
    int reservados;
    int num elem;
    int anterior, posterior;
    void resize(int n);
    
  public:
    Cola();
    Cola(const Cola& p);
    ∼Cola();
    Cola& operator= (const Cola& p);
    bool vacia() const { return numelem==0;}
    void poner (TBase c);
    void quitar();
    Tbase frente() const;
};

#endif
