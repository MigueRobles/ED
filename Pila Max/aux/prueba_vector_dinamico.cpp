// prueba_vector_dinamico.cpp

#include<iostream>
#include<vector_dinamico.h>

using namespace std;

void cargar_indices (Vector_Dinamico& v){
  for (int i = 0; i < v.size(); ++i)
    v[i]=i;
}

float maximo (const Vector_Dinamico& v){
  float max;
  if (v.size()==0){
    cerr << "Upp... máximo de ???? asignamos cero" << endl;
    max = 0.0;
  }
  else{
    max = v[0];
    for (int i=1; i < v.size(); ++i)
      if (max < v[i])
        max = v[i];
  }
  return max;
}

int main(){
  Vector_Dinamico vec;
  cargar_indices(vec);
  cout << "Maximo de " << vec.size() << "elementos: " << maximo(vec) << endl;
  vec.resize(10);
  cargar_indices(vec);
  cout << "Maximo de " << vec.size() << "elementos: " << maximo(vec) << endl;
  return 0;
}
