//CONJUNTO_REALES.H

#ifndef _conjunto_reales_h
#define _conjunto_reales_h

#include <vector_dinamico.h>
#include <cassert>

class Conjunto_Reales{
  private:
    Vector_Dinamico v;
    int nelementos;
    bool posicion_elemento(int& pos, float val) const;
  public:
    Conjunto_Reales(): nelementos(0){}
    //Conjunto_Reales(const Conjunto_Reales& c)
    //~Conjunto_Reales();
    //Conjunto_Reales& operator=(const Conjunto_Reales& c);
    bool insertar(float f);
    bool borrar(float f);
    bool pertenece(float f) const {int pos; return posicion_elemento(pos,f);}
    float elemento(int i) const {assert(0<=i && i<=v.size()); return v[i];}
    bool vacio() const {return nelementos == 0;}
    int size() const {return nelementos;}
};

#endif
