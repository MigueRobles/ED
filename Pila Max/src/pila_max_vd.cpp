/**
* @author Miguel Angel Robles Urquiza
* @author Alberto Estepa Fernandez
* @file pila_max_vd.cpp
* @brief Implementación del TDA Pila con colas
*
*/

template <class T>
  Pila_max<T>::Pila_max(){}

template <class T>
  Pila_max<T>::Pila_max(const Pila_max<T>& p){
    vd = p.vd;
  }

template <class T>
  Pila_max<T>::~Pila_max(){}

template <class T>
Pila_max<T>&   Pila_max<T>::operator= (const Pila_max<T>& p){
      vd = p.vd;
  }

template <class T>
  bool Pila_max<T>::vacia() const{
    return vd.size() == 0;
  }


template <class T>

  void Pila_max<T>::poner (T elem){
    T maximo;    // calculo el máximo
    if (vd.size() != 0) {    // Si el vector no está vacío, miro si el máximo que tengo es mejor que elem o no, y asigno en consecuencia
        maximo = vd[vd.size()-1].maximo;
        if (maximo < elem) {
            maximo = elem;
        }
    }
    else {    // Si está vacío, el máximo es mi elem.
        maximo = elem;
    }

    vd.resize(vd.size()+1);    //redimensiono y asigno
    vd[vd.size()-1].ele = elem;
    vd[vd.size()-1].maximo = maximo;
  }

template <class T>
  void Pila_max<T>::quitar(){
    vd.resize(vd.size()-1);
  }

template <class T>
  elemento<T> Pila_max<T>::tope() const{
    assert(vd.size() > 0);
      return vd[vd.size()-1];
  }
