//COMPLEJO.H

#ifndef _complejo_h
#define _complejo_h

#include <iostream>

class Complejo{
  private:
    double v_real;
    double v_imaginario;
  public:
    Complejo(double r=0, double i=0): v_real(r), v_imaginario(i){}
    //Complejo (const COmplejo& c);
    //~Complejo ();
    //operator=
    double real() const
      {return v_real;}
    double imaginaria() const
      {return v_imaginario;}
};

inline Complejo operator+(Complejo c1, Complejo c2){
  return Complejo(c1.real()+c2.real(), c1.imaginaria()+c2.imaginaria());
}

inline Complejo operator- (Complejo c1, Complejo c2){
  return Complejo(c1.real()-c2.real(), c1.imaginaria()-c2.imaginaria());
}

inline std::ostream& operator<<(std::ostream& os, const Complejo& c){
  return os << '(' << c.real() << ',' << c.imaginaria() << ')';
}

inline std::istream& operator>> (std::istream& is, Complejo& c){
  char caracter;
  double r,i;
  is >> caracter >> r >> caracter >> i >> caracter;
  c=Complejo(r,i);
  return is;
}

#endif
