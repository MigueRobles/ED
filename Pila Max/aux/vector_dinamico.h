// VECTOR_DINAMICO.H

#ifndef _vectorDinamico_h
#define _vectorDinamico_h

class Vector_Dinamico{
  private:
    float *datos;
    int nelementos;
  public:
    Vector_Dinamico(int n);
    Vector_Dinamico(const Vector_Dinamico& original);
    ~Vector_Dinamico();
    int size() const;
    float &operator[](int i);
    const float& operator[](int i) const;
    void resize(int n);
    Vector_Dinamico& operator=(const Vector_Dinamico& original);
};

#endif
