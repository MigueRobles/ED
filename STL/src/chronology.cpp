#include "chronology.h"

chronology::chronology(const chronology& other) {
/*
  for(iterator i = other.begin(); i != ohter.end(); ++i)
    chrono.insert(oh)
*/
}


ostream &operator<<(ostream & os, chronology &c){

  for(map<string, historicalevent>::iterator it = c.begin(); it != c.end(); ++it){
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
  chrono.insert(chrono.begin(), pair<string, historicalevent> (e.year(), e) );
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



chronology::iterator chronology::begin(){
  iterator i=chrono.begin();
  return i;
}
/*
 chronology::const_iterator chronology::begin(){
	const_iterator i=chrono.begin();
	return i;
}
*/
chronology::iterator chronology::end(){
  iterator i=chrono.end();
  return i;
}
/*
  chronology::const_iterator chronology::end()const {
  const iterator i=chrono.end();
  return i;
}*/
