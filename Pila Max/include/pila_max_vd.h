/**
* @author Alberto Estepa Fernandez
* @author Miguel Angel Robles Urquiza
* @file pila_max_vd.h
* @brief Fichero cabecera del TDA Pila
**/

#ifndef PILA_MAX_VD_H_
#define PILA_MAX_VD_H_

#include "vector_dinamico.h"

template <class T>
class Pila_max{

Vector_Dinamico <elemento <T> > vd;

  public:

    /**
  	* @brief Constructor por defecto
  	* @post La pila queda inicializada a 0
  	*/
    Pila_max();

    /**
  	* @brief Constructor de copias
  	* @param p es una pila constante y por referencia para que no se produzca copia
  	* @post La pila se queda con los valores del parámetro
  	*/
    Pila_max(const Pila_max<T>& p);

    /**
  	* @brief Destructor
  	* @post Se vacía la pila
  	*/
    ~Pila_max();

    /**
  	* @brief Sobrecarga del operador =
  	* @param p es una pila constante y por referencia para que no se produzca copia
  	* @return Se devuelve la pila de la izquierda del operador con los valores de la de la derecha
  	*/
    Pila_max& operator= (const Pila_max<T>& p);

    /**
  	* @brief Pregunta si la pila está vacia
  	* @return true si la pila esta vacía
  	*/
    bool vacia() const;

    /**
    * @brief Añade un elemento a la pila
    * @param elem elemento que introducimos en la pila (nuevo tope)
    */
    void poner (T elem);

    /**
  	* @brief Elimina un elemento de la pila
  	* @post Se elimina el tope de la pila
  	*/
    void quitar();

    /**
  	* @brief Se devuelve el elemento tope de la pila
  	* @return el ultimo elemento introducido en la pila (tope)
  	*/
    elemento<T> tope() const;
};

#include "../src/pila_max_vd.cpp"


#endif
