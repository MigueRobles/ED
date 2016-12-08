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
		historicalevent(pair<string, set<string> > &p);
		~historicalevent() = default;

		typedef typename set<string>::iterator iterator;
		typedef typename set<string>::const_iterator const_iterator;

		friend ostream & operator<<(ostream & os, historicalevent & e);

		friend istream & operator>>(istream & is, historicalevent &e);

		set<string> getallevents();

		string year();

		void setevents(string events);
		void setyear(string y);

	/**
     * @brief Inicializa un iterator al comienzo del evento
     * */
		 iterator begin(){
		 	iterator i;
		 	i=history.second.begin();
		 	return i;
		 }


	/**
     * @brief Inicializa un iterator constante al comienzo del evento
     * */
		 const iterator begin()const{
			 iterator i;
			 i=history.second.begin();
			 return i;
		 }


	/**
	 * @brief Inicializa un iterator al final del evento
	 * */

	 iterator end(){
		 iterator i;
		 i=history.second.end();
		 return i;
	 }

	/**
	* @brief Inicializa un iterator constante al final del evento
	* */
	const iterator end()const {
		iterator i;
		i=history.second.end();
		return i;
	}

};

#endif
