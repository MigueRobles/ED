#include "../include/historical_event.h"
#include <fstream>
#include <iostream>

int main(int argc , char * argv[]){
  if (argc!=2){
      cout<<"Tell me the file name with the events"<<endl;
      return 0;
  }
  ifstream f(argv[1]);
  if (!f){
      cout<<"Imposible to open the file "<<argv[1]<<endl;
      return 0;
  }

 HistoricalEvent e1;

	f>>e1;

 cout<<"Insert events are:" << endl;
 cout << e1<<endl;
 cin.clear();

	HistoricalEvent e2;

	e2.setyear("1997");
	e2.setevents("Pablo Picasso's Tête de Femme is stolen ");
	e2.setevents("Fire damages the Turin Cathedral");
	e2.setevents("The Russian–Chechen Peace Treaty is signed");
	e2.setevents("The mixed martial arts organization Pride Fighting Championships holds its inaugural event at the Tokyo Dome");

	cout << endl<<"Testing set functions:" << endl;
	cout << e2 << endl;

	pair<string, set<string> > p;

	p.first = e1.year();
	p.second = e1.getallevents();

	cout << endl <<"Testing iterators:" << endl;

	HistoricalEvent::iterator iterador;
	iterador = e2.begin();
	cout << *iterador << endl;
	iterador++;
	iterador++;
	cout << *iterador << endl;

	HistoricalEvent::iterator iterador1;
	iterador1 = e2.end();
	iterador1--;
	iterador1--;
	cout << *iterador1 << endl;

	cout << endl <<"Testing assignation constructor:" << endl;

	HistoricalEvent e3(p);
	cout << e3 << endl;

 }
