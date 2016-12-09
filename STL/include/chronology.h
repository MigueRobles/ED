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


  friend ostream & operator<<(ostream & os, chronology &c);
  friend istream & operator>>(istream & is, chronology &e);

  void insert(const historicalevent& e);
  void clear();

  historicalevent getevents(const string &s);
  int num_event();


  /**
     * @brief Inicializa un iterator al comienzo del evento
     * */
	iterator begin();

	/**
     * @brief Inicializa un iterator constante al comienzo del evento
     * */
  //const_iterator begin() const;
	/**
	 * @brief Inicializa un iterator al final del evento
	 * */

	iterator end();
	/**
	* @brief Inicializa un iterator constante al final del evento
	* */
	//const_iterator  end() const;

  /*


  set<string> getallevents();
  string year();
  void setevents(string events);
  void setyear(string y);
    */

  };

#endif
