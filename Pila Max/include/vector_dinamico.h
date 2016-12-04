#ifndef __Vector_Dinamico_VD_
#define __Vector_Dinamico_VD_


template <class T>
class Vector_Dinamico{

  private:
    T *datos;
    int nelementos;
  public:
    Vector_Dinamico<T>();
    Vector_Dinamico<T>(int n);
    Vector_Dinamico<T>(const Vector_Dinamico<T>& original);
    ~Vector_Dinamico<T>();
    int size() const;
    T &operator[](int i);
    const T& operator[](int i) const;
    void resize(int n);
    Vector_Dinamico<T>& operator=(const Vector_Dinamico<T>& original);
};
#include "../src/vector_dinamico.cpp"


#endif
