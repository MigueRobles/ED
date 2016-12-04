/**
* @author Miguel Angel Robles Urquiza
* @author Alberto Estepa Fernandez
* @file pila_max_cola.h
* @brief Fichero cabecera del TDA Pila
*
*/
#ifndef PILA_MAX_COLA_H_
#define PILA_MAX_COLA_H_

#include "cola.h"


template <class T>
class Pila_max{

    Cola <elemento <T> > c;

  public:
    /**
  	* @brief Constructor por defecto
  	*
  	*/
    Pila_max();
    /**
  	* @brief Constructor de copias
  	* @param p es una pila constante
  	* @post La pila se queda con los valores del parámetro
  	*/
    Pila_max(const Pila_max<T>& p);
    /**
  	* @brief Sobrecarga del operador =
  	* @param p pila constante
  	* @return La pila implícita con los nuevos valores
  	*/
    Pila_max& operator= (const Pila_max<T>& p);
    /**
    * @brief Devuelve si la pila está vacía
    *
    */
    bool vacia() const;
    /**
    * @brief Añade un elemento al tope de la pila
    * @param c elemento a meter en la pila
    * @post La pila se queda con un elemento más
    */
    void poner (T c);
    /**
    * @brief Elimina el tope de la pila
    * @post La pila se queda con un elemento menos
    */
    void quitar();
    /**
    * @brief Devuelve el tope de la pila
    * @return Tope de la pila
    */
    elemento<T> tope() const;
};

#include "../src/pila_max_cola.cpp"

#endif
