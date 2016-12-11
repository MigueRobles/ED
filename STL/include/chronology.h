/**
  * @file cronologia.h
  * @Author Miguel Ángel Robles Urquiza && Alberto Estepa Fernandez
  * @brief Fichero cabecera del TDA cronologia
  *
  */
#ifndef __chronology_H
#define __chronology_H
#include <map>
#include "historical_event.h"

using namespace std;

class chronology{

  map<string,historicalevent> chrono;

public:
  typedef typename map<string, historicalevent>::iterator iterator;
  typedef typename map<string, historicalevent>::const_iterator const_iterator;

  /**
  * @brief Constructor sin parametros de la clase cronologia
  */
  chronology () = default;
  /**
  * @brief Destructor de la clase cronologia
  */
  ~chronology () = default;
  /**
    * @brief Constructor de copias de la clase
    * @param other cronologia a copiar
    */
  chronology(const chronology& other);

  /**
  * @brief sobrecarga del operador << para chronology
  * @param os flujo de salida
  * @param c chronology que anhelamos mostrar
  * @return devuelve el flujo de salida
  */

  friend ostream & operator<<(ostream & os, chronology &c);
  /**
  * @brief sobrecarga del operador >> para chronology
  * @param is flujo de entrada
  * @param c chronology que queremos leer
  * @return devuelve el flujo de entrada
  */
  friend istream & operator>>(istream & is, chronology &e);
  /**
  * @brief inserta un historicalevent a la chronology
  * @param e historicalevent a copiar
  */
  void insert(const historicalevent& e);
  /**
  * @brief inserta eventos desde min hasta max
  * @param min limite inferior
  * @param max limite superior
  * @pre min y max tienen que ser numeros
  * @return chronology con los eventos entre min y max
  */
  chronology insertrange(const string &min, const string& max);
  /**
  * @brief vacia la chronology
  */
  void clear();
  /**
  * @brief inserta eventos con la key deseada
  * @param key clave a buscar
  * @return chronology con los eventos con la key
  */
  chronology insertkey(const string& key);
  /**
  * @brief devuelve un historicalevent con los eventos deseados
  * @param s acontecimiento a buscar
  * @return historicalevent con el acontecimiento
  */
  historicalevent getevents(const string &s);
  /**
  * @brief devuelve el numero de historicalevents
  * @return numero de historicalevent
  */
  int num_event();
  /**
  * @brief devuelve el numero acontecimientos
  * @return numero de acontecimientos
  */
  int num_happening();
  /**
  * @brief devuelve el numero de acontecimientos del evento de la cronologia con mas acontecimientos
  * @return numero de acontecimientos del evento de la cronologia con mas acontecimientos
  */
  int max();
  /**
  * @brief sobrecarga del operador [] para chronology
  * @param nombre key deseada
  * @return historicalevent de la key
  */

  historicalevent & operator[](const string &nombre);
  /**
  * @brief sobrecarga del operador + para chronology
  * @param c cronologia a unir
  * @return chronology suma
  */
  chronology& operator+(const chronology &c);
  /**
  * @brief devuelve el año del principio de la chronology
  * @return años de la chronology
  */
  string year();




  /**
     * @brief Inicializa un iterator al comienzo del evento
     * */
	iterator begin();
	/**
     * @brief Inicializa un iterator constante al comienzo del evento
     * */
  const_iterator begin() const;
	/**
	 * @brief Inicializa un iterator al final del evento
	 * */
	iterator end();
	/**
	* @brief Inicializa un iterator constante al final del evento
	* */
	const_iterator  end() const;


  };

#endif
