/**
* @author Miguel Angel Robles Urquiza
* @author Alberto Estepa Fernandez
* @file pila_max_cola.cpp
* @brief Implementación del TDA Pila con colas
*
*/
template <class T>
  Pila_max<T>::Pila_max(){}

template <class T>
  Pila_max<T>::Pila_max(const Pila_max<T>& p){
      c = p.c;
  }

template <class T>
  Pila_max<T>& Pila_max<T>::operator= (const Pila_max<T>& p){
    c = p.c;
  }
template <class T>
  bool Pila_max<T>::vacia() const{
    return c.vacia();
  }
template <class T>
void Pila_max<T>::poner (T elem){
    Cola<elemento<T> > aux;
    elemento<T> e;
    e.ele = elem;
    if(!this->c.vacia())
      e.maximo = (elem < this->c.frente().maximo) ? this->c.frente().maximo : elem;
    else
      e.maximo = elem;
    aux.poner(e);

    while(this->c.num_elementos() > 0){
      aux.poner(this->c.frente());
      c.quitar();
    }

    while(aux.num_elementos() > 0){
      this->c.poner(aux.frente());
      aux.quitar();
    }
}

template <class T>
  void Pila_max<T>::quitar(){
    c.quitar();
  }

template <class T>
  elemento<T> Pila_max<T>::tope() const{
    return c.frente();
  }
