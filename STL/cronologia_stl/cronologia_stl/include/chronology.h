/**
 * @ file : chronology.h
 * @brief: TDA chronology
 * */

#ifndef __chronology_H
#define __chronology_H
#include <map>
#include "../include/historical_event.h"

using namespace std;

class chronology{

  map<string,historicalevent> chrono;

public:
  typedef typename map<string, historicalevent>::iterator iterator;
  typedef typename map<string, historicalevent>::const_iterator const_iterator;


  chronology () = default;
  ~chronology () = default;

   /*


friend ostream & operator<<(ostream & os, chronology &c){
    map<string, historicalevent>::iterator it;

      for(map<string, historicalevent>::iterator it = c.begin(); it != c.end(); it++){
        os << it->second;
      }
    return os;

  }
  iterator begin(){
    iterator i;
    i=chrono.begin();
    return i;
  }
  iterator end(){
    iterator i;
    i=chrono.end();
    return i;
  }*/


  /*
  void insert(const historicalevent& e){

  chrono.insert(chrono.begin(), pair<string, historicalevent> (e.year(), e) );
}


  friend istream & operator>>(istream & is, chronology &e);
  iterator begin ();

  const_iterator begin () const;
  iterator end ();
  const_iterator end () const;
  set<string> getallevents();
  string year();
  void setevents(string events);
  void setyear(string y);
    */

  };

#endif
