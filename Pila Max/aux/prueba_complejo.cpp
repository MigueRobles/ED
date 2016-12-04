//PROGRAMA PRUEBA Complejo

#include <iostream>
#include <complejo.h>

using namespace std;

int main(){
  Complejo c1, c2;
  cout << "Introduce un complejo usando el formato (r,i): " << endl;
  cin >> c1;
  cout << "Introduce un complejo usando el formato (r,i): " << endl;
  cin >> c2;
  cout << "La suma es " << c1+c2 << " y la resta " << c1-c2 << endl;
  cout << "Si sumo 1 al primer complejo da como resultado " << c1+1 << endl;
  cout << "Si a 1 le resto el segundo complejo da como resultado " << 1-c2 << endl;
  return 0;
}
