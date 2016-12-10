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

void chronology::insertrange(const string &min, const string& max){
  
  for(iterator it = begin(); it != end(); ++it)
    insert(o->second);

}

void chronology::clear(){
    chrono.clear();
}


 historicalevent chronology::getevents(const string &s) {
  iterator it = chrono.find(s);
  return it->second;
}

int chronology::num_event(){
  return chrono.size();
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
