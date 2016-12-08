/**
 * @ file : historical_event.h
 * @brief: TDA HistoricalEvent
 * */

#ifndef _HistoricalEvent_H
#define _HistoricalEvent_H
#include <utility>
#include <iostream>
#include <string>
#include <set>
using namespace std;

class HistoricalEvent{
	private:
	    pair<string,set <string> > history;

  public:
		HistoricalEvent(){}

		HistoricalEvent(pair<string, set<string> > p){
			history.first = p.first;
			history.second = p.second;
		}

		typedef typename set<string>::iterator iterator;
		typedef typename set<string>::const_iterator const_iterator;

		friend ostream & operator<<(ostream & os, HistoricalEvent & e){
			set<string>::iterator it;
			os<<e.history.first;
			for (it=e.history.second.begin(); it!=e.history.second.end();++it)
				os <<"#"<< *it;
			return os;
		}

		friend istream & operator>>(istream & is, HistoricalEvent &e){
			string events;
			string aux;
			getline(is,e.history.first,'#');
			getline(is,events);
			for(unsigned int i= 0; i < events.size(); i++){
				if(events[i] == '#'){
					e.history.second.insert(aux);
					aux.clear();
				}
				else
					aux+=events[i];
			}
			e.history.second.insert(aux);
			aux.clear();
			return is;
		}

		set<string> getallevents(){
			return history.second;
		}

		string year(){
			return history.first;
		}

		void setevents(string events){
			history.second.insert(events);
		}

		void setyear(string y){
			history.first = y;
		}

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

		iterator &operator++(){
			iterator i;
			return ++i;
		}

	 	iterator &operator--(){
	  	iterator i;
	  	return --i;
	 	}
/*	iterator &operator =(const_iterator &it){}
		iterator &operator ==(const_iterator &it){}
		iterator &operator !=(const_iterator &it){}
	 */

	 string operator*(){
		 iterator i;
		 return *i;
	 }
	 
};
#endif
