// VECTOR_DINAMICO.H con TEMPLATE

template <class T>
class Vector_Dinamico{
  private:
    T *datos;
    int nelementos;
  public:
    Vector_Dinamico<T>(int n);
    Vector_Dinamico<T>(const Vector_Dinamico<T>& original);
    ~Vector_Dinamico<T>();
    int size() const;
    T &operator[](int i);
    const T& operator[](int i) const;
    void resize(int n);
    Vector_Dinamico<T>& operator=(const Vector_Dinamico<T>& original);
};

/*INSTANCIACION DE UN TIPO CONCRETO

Vector_Dinamico<int> valores;
Vector_Dinamico<string> nombres;
Vector_Dinamico<Polinomio> polinimios;

*/

#endif
