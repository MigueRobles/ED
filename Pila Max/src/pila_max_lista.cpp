/**
  * @author Miguel Angel Robles Urquiza
  * @author Alberto Estepa Fernandez
  * @file pila_max_lista.cpp
  * @brief Implementación del TDA Pila_max versión lista
  *
  */


#include <cassert>

template <class T>
Pila_max<T>::Pila_max() : topepil (0) {}

template <class T>
Pila_max<T>::Pila_max(const Pila_max& p) {

		if (p.topepil == 0)
			topepil=0 ;
		else {
			topepil = new Celda ;
			topepil -> elem = p.topepil -> elem ;
			Celda * origen = p.topepil ;
			Celda * destino = topepil ;
			while(origen->sig != 0) {
				destino->sig = new Celda ;
				origen = origen -> sig ;
				destino = destino -> sig ;
				destino -> elem = origen -> elem ;
			}

			destino -> sig = 0 ;
		}
}

template <class T>
Pila_max<T>::~Pila_max<T>() {
	Celda * aux;
	while(topepil!=0) {
		aux = topepil ;
		topepil = topepil -> sig ;
		delete aux ;
	}
}

template <class T>
Pila_max<T>& Pila_max<T>::operator=(const Pila_max& p) {

	if (this != *p) {
			Pila_max paux(p) ;
			Celda * aux ;
			aux = this->topepil ;
			this->topepil = paux.topepil ;
			paux.topepil = aux ;
	}

	return *this ;
}


template <class T>
void Pila_max<T>::poner(T e) {
	Celda * aux = new Celda ;
	aux -> elem.ele = e ;
	aux -> sig = topepil ;
	topepil = aux ;

	if (topepil->sig != 0) {
		if (topepil->elem.ele >= topepil->sig->elem.maximo )
			topepil->elem.maximo = topepil->elem.ele ;
		else
			topepil->elem.maximo = topepil->sig->elem.maximo ;
	}
	else
		topepil->elem.maximo = topepil->elem.ele ;

}


template <class T>
void Pila_max<T>::quitar() {
	assert(topepil != 0);
	Celda * aux = topepil ;
	topepil = topepil -> sig ;
	delete aux ;
}


template <class T>
elemento<T> Pila_max<T>::tope() const {
	assert(topepil!=0);
	return topepil -> elem ;
}

template <class T>
bool Pila_max<T>::vacia() const {
	return topepil == 0 ;
}
