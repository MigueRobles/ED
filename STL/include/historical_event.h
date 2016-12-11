/**
  * @file historicalevent.h
  * @Author Miguel Ángel Robles Urquiza && Alberto Estepa Fernandez
  * @brief Fichero cabecera del TDA historicalevent
  *
  */

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
		/**
		* @brief Constructor sin parametros de la clase historicalevent
		*/
		historicalevent() = default;
		/**
			* @brief Constructor de copias de la clase
			* @param historicalevent eventohistorico a copiar
			*/
		historicalevent(const historicalevent &h);
		/**
			* @brief Constructor de asigancion
			* @param p pareja de <string, set<string> > a copiar
			*/
		historicalevent(const pair<string, set<string> > &p);
		/**
		* @brief Destructor de la clase historicalevent
		*/
		~historicalevent() = default;

		typedef typename set<string>::iterator iterator;
		typedef typename set<string>::const_iterator const_iterator;
		/**
		* @brief sobrecarga del operador << para historicalevent
		* @param os flujo de salida
		* @param e eventohistorico que anhelamos mostrar
		* @return devuelve el flujo de salida
		*/

		friend ostream & operator<<(ostream & os, const historicalevent & e);
		/**
		* @brief sobrecarga del operador >> para historicalevent
		* @param is flujo de entrada
		* @param e eventohistorico que queremos leer
		* @return devuelve el flujo de entrada
		*/
		friend istream & operator>>(istream & is, historicalevent &e);
		/**
		* @brief Devuelve los eventos
		* @return Devuelve los eventos
		*/
		const set<string> getallevents() const;
		/**
		* @brief Devuelve el año
		* @return Devuelve el año
		*/
		const string year() const;
		/**
		* @brief Devuelve el numero de eventos
		* @return Devuelve el numero de eventos
		*/
		int size();
		/**
		* @brief inserta un acontecimiento
		* @param events acontecimiento a insertar
		*/
		void setevents(string events);
		/**
		* @brief inserta el año
		* @param y año a insertar
		*/
		void setyear(string y);
		/**
		* @brief borra el eventohistorico
		*/
		void clear();
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
