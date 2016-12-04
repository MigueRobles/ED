#ifndef LISTA_VECTORES_H_
#define LISTA_VECTORES_H_

typedef char Tbase;

class Lista;

class Posicion {
    int i;  // Podrı́a ser un puntero

  public:
    Posicion(): i(0) {}

    //Posicion(const Posicion& p);
    // ∼ Posicion();
    //Posicion& operator = (const Posicion& p);

    Posicion& operator++() {
      ++i;
      return ∗ this;
    }

    Posicion& operator--() {
      --i;
      return ∗ this;
    }

    bool operator==(const Posicion& p)
      { return i==p.i; }

    bool operator ! = (const Posicion& p)
      { return i ! = p.i; }

    friend class Lista;
};

class Lista {
    Tbase ∗ datos;
    int nelementos;
    int reservados;
    void resize(int n);
    
  public:
    Lista(): nelementos(0),reservados(1) {
      datos= new Tbase[1];
    }

    Lista(const Lista& l);

    ∼ Lista() { delete[] datos; }

    Lista& operator= (const Lista& l);

    void set (Posicion p, Tbase e) {
      assert(p.i >= 0 && p.i < nelementos);
      datos[p.i]= e;
    }

    Tbase get (Posicion p) const {
      assert(p.i >= 0 && p.i < nelementos);
      return datos[p.i];
    }

    Posicion insertar(Posicion p, Tbase e);

    Posicion borrar(Posicion p);

    Posicion begin() const {
      Posicion p; p.i=0; return p; }

    Posicion end() const {
      Posicion p; p.i=nelementos; return p; }
};

#endif
