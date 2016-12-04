//VECTOR_DISPERSO.H

#ifndef _vector_disperso_h
#define _vector_disperso_h

class Vector_Disperso{
  private:
    struct Elemento{
      int indice;
      float valor;
    };
    Elemento * datos;
    int nelementos;
    int reservados;
    float valor_por_defecto;
    bool posicion_indice(int& pos, int i) const;
    void resize(int n);
  public:
    Vector_Disperso(float def);
    Vector_Disperso(const Vector_Disperso& orig);
    ~Vector_Disperso();
    Vector_Disperso& operator=(const Vector_Disperso& original);
    float get_default() const;
    float get (int i) const;
    void set (int i, float f);
    int num_no_default() const;
    void datos_posicion (int i, int &indice, float& valor) const;
};

#endif;
