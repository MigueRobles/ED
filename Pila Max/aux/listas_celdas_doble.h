typedef char Tbase;

struct CeldaLista {
  Tbase elemento;
  CeldaLista ∗ anterior;
  CeldaLista ∗ siguiente;
};

class Lista;   // Declaración adelantada

class Posicion {
    CeldaLista ∗ puntero;

  public:
    Posicion(): puntero(0) {}

    //Posicion(const Posicion& p);
    // ∼ Posicion();
    //Posicion& operator = (const Posicion& p);

    Posicion& operator++() {
      puntero= puntero → siguiente;
      return ∗ this;
    }

    Posicion& operator--() {
      puntero= puntero → anterior;
      return ∗ this;
    }

    bool operator==(const Posicion& p)
      { return puntero==p.puntero; }

    bool operator ! = (const Posicion& p)
      { return puntero ! = p.puntero; }

    friend class Lista;
};

class Lista {
    CeldaLista ∗ cab;

  public:
    Lista();

    Lista(const Lista& l);

    ∼ Lista();

    Lista& operator= (const Lista& l);

    void set (Posicion p, Tbase e) {
      p.puntero → elemento= e;
    }

    Tbase get (Posicion p) const {
      return p.puntero → elemento;
    }

    Posicion insertar(Posicion p, Tbase e);

    Posicion borrar(Posicion p);

    Posicion begin() const {
      Posicion p;
      p.puntero= cab → siguiente;
      return p;
    }

    Posicion end() const {
      Posicion p;
      p.puntero= cab;
      return p;
    }
};
