/**
 * @ file : chronology.h
 * @brief: TDA chronology
 * */

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


  chronology () = default;
  ~chronology () = default;
  chronology(const chronology& other);
  chronology(chronology& other, string key); //Constructor para filtrado por palabra clave


  friend ostream & operator<<(ostream & os, chronology &c);
  friend istream & operator>>(istream & is, chronology &e);

  void insert(const historicalevent& e);
  chronology insertrange(const string &min, string max);
  void clear();

  historicalevent getevents(const string &s);
  int num_event(); //numero de historicalevent
  int num_happening(); //numero total de acontecimientos
  int max(); //numero de acontecimientos del evento de la cronologia con mas acontecimientos
  historicalevent & operator[](const string &nombre);
  chronology& operator+(const chronology &c);



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
