/**
 * @ file : historical_event.h
 * @brief: TDA historicalevent
 * */

#ifndef _historicalevent_H
#define _historicalevent_H
#include <utility>
#include <iostream>
#include <string>
#include <set>
using namespace std;

class historicalevent{
	private:
		pair<string,set <string> > history;

  public:
		historicalevent() = default;
		historicalevent(const historicalevent &h);
		historicalevent(const pair<string, set<string> > &p);
		~historicalevent() = default;

		typedef typename set<string>::iterator iterator;
		typedef typename set<string>::const_iterator const_iterator;

		friend ostream & operator<<(ostream & os, const historicalevent & e);

		friend istream & operator>>(istream & is, historicalevent &e);

		const set<string> getallevents() const;

		const string year() const;

		int size();

		void setevents(string events);
		void setyear(string y);
		void clear();

		bool foundkey(string key);
		historicalevent& eventskey(string key);

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
	const_iterator end() const;

};

#endif
