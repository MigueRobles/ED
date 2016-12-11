/**
 * @ file : historical_event.cpp
 * @brief: TDA historicalevent
 * */

#include "historical_event.h"
#include <stdio.h>
#include <string.h>

typedef typename set<string>::iterator iterator;
typedef typename set<string>::const_iterator const_iterator;

historicalevent::historicalevent(const historicalevent &h){
	history.first = h.history.first;
	history.second = h.history.second;

}

historicalevent::historicalevent(const pair<string, set<string> > &p){
				history.first = p.first;
				history.second = p.second;
		}

ostream &operator<<(ostream & os, const historicalevent & e){
	set<string>::iterator it;

	os<<e.history.first << endl;
	for (it=e.history.second.begin(); it!=e.history.second.end();++it){
			os << "\t"<< "#" << *it << endl;
	}
	return os;
}
istream &operator>>(istream & is, historicalevent &e){
	string year;
	string events;
	string aux ;
	getline(is,year,'#');
	getline(is,events);
	e.history.first = year;

	if (!events.empty() && !e.history.first.empty()){
	for(unsigned int i= 0; i < events.size(); i++){
		if(events[i] == '#'){
			e.history.second.insert(aux);
			aux.clear();
		}
		else{
			aux+=events[i];
		}
	}
	e.history.second.insert(aux);
	aux.clear();
	}
		return is;
}
 const set<string> historicalevent::getallevents() const{
	return history.second;
}

const string historicalevent::year() const{
	return history.first;
}

void historicalevent::setevents(string events){
	history.second.insert(events);
}

void historicalevent::setyear(string y){
	history.first = y;
}

void historicalevent::clear(){
	history.first = "";
	history.second.clear();
}

int historicalevent::size(){
	return history.second.size();
}


historicalevent::iterator historicalevent::begin(){
	iterator i=history.second.begin();
	return i;
}

historicalevent::const_iterator historicalevent::begin()const{
	iterator i=history.second.begin();
	return i;
}

historicalevent::iterator historicalevent::end(){
	iterator i=history.second.end();
	return i;
}

historicalevent::const_iterator historicalevent::end()const {
	iterator i=history.second.end();
	return i;
}
