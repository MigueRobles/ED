//VECTOR_DISPERSO.CPP

#include <cassert>
#include <vector_disperso.h>

bool Vector_Disperso::posicion_indice(int & pos, int i) const{
  int izq = 0, der = nelementos -1, centro;
  while (der - izq >= 0){
    centro = (izq + der)/2;
    if (i < datos[centro].indice)
      der = centro - 1;
    else if (i > datos[centro].indice)
        izq = centro + 1;
      else{
        pos = centro;
        return true;
      }
  }
  pos = izq;
  return false;
}

void Vector_Disperso::resize(int n){
  assert(n >= nelementos && n > 0);
  Elemento * nuevos_datos = new Elemento[n];
  for (int j = 0; j < nelementos ; ++j)
    nuevos_datos[j] = datos[j];
  delete[] datos;
  datos = nuevos_datos;
  reservados = n;
}

Vector_Disperso::Vector_Disperso(float def){
  datos = new Elemento[1];
  nelementos = 0;
  reservados = 1;
  valor_por_defecto = def;
}

Vector_Disperso::Vector_Disperso(const Vector_Disperso& orig){
  valor_por_defecto = orig.valor_por_defecto;
  reservados = nelementos = orig.nelementos;
  if (nelementos > 0){
    datos = new Elemento[nelementos];
    for (int i = 0; i < nelementos; ++i)
      datos[i] = orig.datos[i];
  }
  else datos = 0;
}

Vector_Disperso::Vector_Disperso(){
  datos = 0;
  nelementos = reservados = 0;
  valor_por_defecto = 0.0;
}

Vector_Disperso::~Vector_Disperso(){
  if (reservados > 0)
    delete[] datos;
}

Vector_Disperso& Vector_Disperso::operator=(const Vector_Disperso& orig){
  is (this! = &orig){
    if (reservados > 0)
      delete[] datos;
    valor_por_defecto = orig.valor_por_defecto;
    reservados = nelementos = orig.nelementos;
    if (nelementos > 0){
      datos = new Elemento[nelementos];
      for (int i=0; i < nelementos; ++i)
        datos[i] = orig.datos[i];
    }
    else datos = 0;
  }
  return *this;
}

int Vector_Disperso::num_no_default() const{
  return nelementos;
}

void Vector_Disperso::datos_posicion(int i, int& indice, float& valor) const{
  assert(0 <= i && i < nelementos);
  indice = datos[i].indice;
  valor = datos[i].valor;
}

float Vector_Disperso::get_default() const{
  return valor_por_defecto;
}

float Vector_Disperso::get (int i) const{
  int pos;
  if (posicion_indice(pos, i))
    return datos[pos].valor;
  else return valor_por_defecto;
}

void Vector_Disperso::set(int i, float f){
  int pos;
  if (posicion_indice(pos, i)){ //Esta en pos
    if (f != valor_por_defecto)
      datos[pos].valor = f;
    else{       //hay que eliminarlo
      nelementos = nelementos - 1;
      for (int j = pos; j < nelementos; ++j)
        datos[j] = datos[j+1];
      if (nelementos < reservados/4)
        resize(reservados/2);
    }
  }
  else{ //No esta en el vector (estaria en pos)
    if (f != valor_por_defecto){
      if (nelementos == reservados)
        resize(reservados*2);
      for (int j=nelementos; j > pos; --j)
        datos[j] = datos[j-1];
      datos[pos].indice = i;
      datos[pos].valor = f;
      ++nelementos;
    }
  }
}
