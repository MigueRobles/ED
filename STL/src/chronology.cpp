#include "chronology.h"

chronology::chronology(const chronology& other){

  for(map<string, historicalevent>::const_iterator i = other.begin(); i != other.end(); ++i)
    insert(i->second);
}


ostream &operator<<(ostream & os, chronology &c){

  for(map<string, historicalevent>::const_iterator it = c.begin(); it != c.end(); ++it){
    os << it->second;
  }
  return os;
}

istream & operator>>(istream & is, chronology &c){

  historicalevent e;
  while(is>>e){
    if(!e.year().empty())
      c.insert(e);
      e.clear();
  }

  return is;
}

void chronology::insert(const historicalevent& e){

  bool exist = chrono.count(e.year());
  if(!exist)
  chrono.insert(chrono.begin(), pair<string, historicalevent> (e.year(), e) );
  else{
    iterator it =chrono.find(e.year());
    set<string> events = e.getallevents();
    for(set<string>::iterator i = events.begin(); i != events.end(); ++i)
    it->second.setevents(*i);
  }
}
chronology chronology::insertrange(const string &min, const string &max){
  chronology c1;
  iterator low =prev(end());
  iterator up = end();
  bool found_min = false;
  bool found_max = false;

  int mini = stoi(min);
  int maxi = stoi(max);
  for(iterator it = begin(); it != end() && !found_min; it++){
    if(stoi(it->first) >= mini ){
      low = it;
      found_min = true;
    }
  }
    for(iterator it = prev(end()); it != begin()++  && !found_max; it--){
    if(stoi(it->first) <= maxi ){
      up = it;
      found_max = true;
    }
  }
  if(low!= up || found_max || found_min){
    for(; low != up; low++){
      c1.insert(low->second);
    }

    if(up != end())
      c1.insert(low->second);
  }
  else{
    historicalevent e;
    e.setyear("-1");
    c1.insert(e);
  }

  return c1;
}
chronology chronology::insertkey(const string& key) {

	chronology c;
  historicalevent e;
	chronology::const_iterator it = begin();
	historicalevent::iterator it2 ;

	while (it != end()) {
		it2 = it->second.begin();
		while(it2 != it->second.end()){
			if ((it2->find(key)) != (it2->npos)){
        e.setyear(it->second.year());
        e.setevents(*it2);
        c.insert(e);
			 }
			it2++;
		}
		it++;
	}

	return c ;

}
void chronology::clear(){
    chrono.clear();
}
string chronology::year(){
  iterator it = begin();
  return it->first;
}

historicalevent chronology::getevents(const string &s) {
  iterator it = chrono.find(s);
  return it->second;
}

int chronology::num_event(){
  return chrono.size();
}

int chronology::num_happening(){
  int contador = 0;
  for (iterator it = begin(); it != end(); it++)
    contador += it->second.size();
  return contador;
}

int chronology::max(){
  int max = 0;
  for (iterator it = begin(); it != end(); it++)
    if (it->second.size() > max)
      max = it->second.size();
  return max;
}

historicalevent& chronology::operator[](const string &nombre) {
  return chrono[nombre];
}

chronology& chronology::operator+(const chronology &c){
    map<string,historicalevent>::const_iterator it;
    for (it=c.begin();it!=c.end();++it)
       insert(it->second);
    return *this ;
  }

chronology::iterator chronology::begin(){
  iterator i=chrono.begin();
  return i;
}

 chronology::const_iterator chronology::begin() const{
	const_iterator i=chrono.begin();
	return i;
}

chronology::iterator chronology::end(){
  iterator i=chrono.end();
  return i;
}

chronology::const_iterator chronology::end() const {
  const_iterator i=chrono.end();
  return i;
}
