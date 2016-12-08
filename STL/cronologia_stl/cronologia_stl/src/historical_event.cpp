/**
 * @ file : historical_event.cpp
 * @brief: TDA historicalevent
 * */

typedef typename set<string>::iterator iterator;
typedef typename set<string>::const_iterator const_iterator;

historicalevent::historicalevent(historicalevent &h){
	history.first = h.history.first;
	history.second = h.history.second;

}

historicalevent::historicalevent(pair<string, set<string> > &p){
				history.first = p.first;
				history.second = p.second;
		}


ostream &operator<<(ostream & os, historicalevent & e){
	set<string>::iterator it;
	os<<e.history.first;
	for (it=e.history.second.begin(); it!=e.history.second.end();++it){
			os <<"#"<< *it;
	}
	return os;
}

istream &operator>>(istream & is, historicalevent &e){
	string events;
	string aux;
	getline(is,e.history.first,'#');
	getline(is,events);
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

		return is;
}

set<string> historicalevent::getallevents(){
	return history.second;
}

string historicalevent::year(){
	return history.first;
}

void historicalevent::setevents(string events){
	history.second.insert(events);
}

void historicalevent::setyear(string y){
	history.first = y;
}
