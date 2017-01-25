#include <iostream>
#include "jugador_automatico.h"

using namespace std;

jugador_automatico::jugador_automatico(): NIVEL(0){
  Tablero t;
  arbol_tableros.AsignaRaiz(t);
}

jugador_automatico::jugador_automatico(const Tablero& t, const int& nivel): NIVEL(nivel){
  arbol_tableros.AsignaRaiz(t);
  ConstruirArbol(arbol_tableros.raiz(), 0);
}

jugador_automatico::jugador_automatico(const jugador_automatico& copiar): NIVEL(copiar.NIVEL){
  arbol_tableros = copiar.arbol_tableros;
}

jugador_automatico::~jugador_automatico(){
  arbol_tableros.~ArbolGeneral();
}

ArbolGeneral<Tablero> jugador_automatico::GetArbol() const{
  return arbol_tableros;
}

jugador_automatico& jugador_automatico::operator=(const jugador_automatico &j){
  arbol_tableros = j.GetArbol();
  return *this;
}

const int jugador_automatico::Nivel() const{
  return NIVEL;
}

Tablero jugador_automatico::Raiz(){
  return arbol_tableros.etiqueta(arbol_tableros.raiz());
}

const int jugador_automatico::GetColumnasTablero(){
  if (!arbol_tableros.empty())
    return Raiz().GetColumnas();
  else
    return 0;
}

void jugador_automatico::SiguientesTablerosPosibles(){
  for(int i = GetColumnasTablero()-1; i >= 0; i--){
    Tablero copia(Raiz());
    if(copia.colocarFicha(i)){
      ArbolGeneral<Tablero> arbolillo(copia);
      arbol_tableros.insertar_hijomasizquierda(arbol_tableros.raiz(), arbolillo);
    }
  }
}

void jugador_automatico::SiguientesTablerosPosiblesA(ArbolGeneral<Tablero>::Nodo t){
  for(int i = GetColumnasTablero()-1; i >= 0; i--){
    Tablero copia (arbol_tableros.etiqueta(t));
    if(copia.colocarFicha(i)){
      ArbolGeneral<Tablero> arbolillo(copia);
      arbol_tableros.insertar_hijomasizquierda(t, arbolillo);
    }
  }
}
void jugador_automatico::ConstruirArbol(ArbolGeneral<Tablero>::Nodo n, int profundidad){
  int columnas = GetColumnasTablero()-1;
  if(profundidad < NIVEL){
    while(columnas >= 0 && arbol_tableros.etiqueta(n).quienGana() == 0){
      Tablero copia (arbol_tableros.etiqueta(n));
      copia.cambiarTurno();
      if(copia.colocarFicha(columnas)){
        ArbolGeneral<Tablero> arbolillo(copia);
        arbol_tableros.insertar_hijomasizquierda(n, arbolillo);
        ConstruirArbol(arbol_tableros.hijomasizquierda(n), ++profundidad);
        profundidad--;
      }
      columnas--;
    }
  }
}


/**
  * @brief Buscamos 3 fichas alineadas de un mismo jugador
  * @return Devuelve
  */
int jugador_automatico::BuscarTresAlineadas(const Tablero& tab){
  vector < vector <int> > tablero = tab.GetTablero();
  const int N_FICHAS_GANAR = 4;
  int ganador = 0;
  int count = 0;
  int i, j;

  for (i = tab.GetFilas() - 1; i >= 0; i--){
      for (j = tab.GetColumnas() - 1; j >= 0; j--){
          // comprobar columnas
      /*    count = 0;
          for (int k = 0; k < N_FICHAS_GANAR - 1  && i - k > 0; k++) {
              if (tablero[i - k][j] != 0 ) {
                  if (count == 0) {
                      ganador = tablero[i - k][j];
                      count++;
                  } else {
                      if (ganador == tablero[i - k][j]) {
                          count++;
                      } else {
                          count = 0;
                          break;
                      }
                  }
                  if (count == N_FICHAS_GANAR - 1 && tablero[i - k - 1][j] == 0) {
                    return j;
                  }
              } else {
                  break;
              }
          }
*/
          // comprobar filas
          count = 0;
          for (int k = 0; k < N_FICHAS_GANAR - 1 && j - k > 0; k++) {
              if (tablero[i][j - k] != 0) {
                  if (count == 0) {
                      ganador = tablero[i][j - k];
                      count++;
                  } else {
                      if (ganador == tablero[i][j - k]) {
                          count++;
                      } else {
                          count = 0;
                          break;
                      }
                  }
                  if (count == N_FICHAS_GANAR - 1){
                    if(i <= tab.GetFilas() - 2){
                      if(tablero[i][j-k-1] == 0 && tablero[i+1][j-k-1] != 0)
                        return j-k-1;
                      else if (tablero[i][j-k-1] == 0)
                        srand(time(NULL));
                        int ret = rand()%tab.GetColumnas();
                        while(ret == j-k-1 && !tab.llenoSalvo(j-k-1))
                          ret = rand()%tab.GetColumnas();
                        return ret;
                    }
                    else{
                      if(tablero[i][j-k-1] == 0)
                        return j-k-1;
                    }
                  }
              } else {
                  break;
              }
          }
          // comprobar diagonal 1
        /*  count = 0;

          for (int k = 0; k < N_FICHAS_GANAR && i + k > 0 && j - k > 0; k++) {
              if (tablero[i -k][j - k] != 0) {
                  if (count == 0) {
                      ganador = tablero[i - k][j - k];
                      count++;
                  } else {
                      if (ganador == tablero[i - k][j - k]) {
                          count++;
                      } else {
                          count = 0;
                          break;
                      }
                  }
                  if (count == N_FICHAS_GANAR) {
                      return j-k;
                  }
              } else {
                  break;
              }
          }
*/
          /*
          // comprobar diagonal 2

          count = 0;
          for (int k = 0; k < N_FICHAS_GANAR && i - k >= 0 && j + k < tablero.GetColumnas(); k++) {
              if (tablero[i - k][j + k] != 0) {
                  if (count == 0) {
                      ganador = tablero[i - k][j + k];
                      count++;
                  } else {
                      if (ganador == tablero[i - k][j + k]) {
                          count++;
                      } else {
                          count = 0;
                          break;
                      }
                  }
                  if (count == N_FICHAS_GANAR) {
                      return ganador;
                  }
              } else {
                  break;
              }
          }
          */
      }
  }
  for (i = tab.GetFilas() - 1 ; i >= 0; i--){
      for (j = 0; j <= tab.GetColumnas() - 1; j++){
        count = 0;
        for (int k = 0; k < N_FICHAS_GANAR - 1 && j + k < tab.GetColumnas(); k++) {
            if (tablero[i][j + k] != 0) {
                if (count == 0) {
                    ganador = tablero[i][j + k];
                    count++;

                } else {
                    if (ganador == tablero[i][j + k]) {
                        count++;
                    } else {
                        count = 0;
                        break;
                    }
                }
                if (count == N_FICHAS_GANAR - 1){
                  if(i <= tab.GetFilas() - 2){
                    if(tablero[i][j+k-1] == 0 && tablero[i+1][j+k+1] != 0)
                      return j+k+1;
                    else if (tablero[i][j+k-1] == 0)
                      srand(time(NULL));
                      int ret = rand()%tab.GetColumnas();
                      while(ret == j+k+1 && !tab.llenoSalvo(j+k-1))
                        ret = rand()%tab.GetColumnas();
                      return ret;
                  }
                  else{
                    if(tablero[i][j+k+1] == 0)
                      return j+k+1;
                  }
                }
            } else {
                break;
            }
        }
        }
      }
  return -1;
}
//hacer la funcion bajar dos niveles
//hacer la funcion puntuacion

//----------------------------------------  METRICAS  ------------------------------------------//
  void jugador_automatico::metrica1(Tablero &tablero){
    srand(time(NULL));
    tablero.colocarFicha(rand()%tablero.GetColumnas());
    tablero.cambiarTurno();
   }
   void jugador_automatico::metrica2(Tablero &tablero){
     int columna = BuscarTresAlineadas(tablero);
     if(columna+1){
       tablero.colocarFicha(columna);
       tablero.cambiarTurno();
     }else{
     srand(time(NULL));
     tablero.colocarFicha(rand()%tablero.GetColumnas());
     tablero.cambiarTurno();
    }
  }

  void jugador_automatico::metrica3(Tablero &tablero){
    tablero.cambiarTurno();
    bool ganado = false;
    arbol_tableros.AsignaRaiz(tablero);
    ConstruirArbol(arbol_tableros.raiz(), 0);
    ArbolGeneral<Tablero>::preorden_iterador it;


    for(it = arbol_tableros.beginpreorden(); it != arbol_tableros.endpreorden() && !ganado; ++it)
        if ((*it).quienGana() == 2){
          tablero = *it;
          ganado = true;
     }
     if(!ganado){
       srand(time(NULL));
       tablero.cambiarTurno();
       tablero.colocarFicha(rand()%tablero.GetColumnas());
      }
      tablero.cambiarTurno();
   }

   void jugador_automatico::metrica4(Tablero &tablero){
     tablero.cambiarTurno();
     bool hay_arbol_ganador = false;

     arbol_tableros.AsignaRaiz(tablero);
     ConstruirArbol(arbol_tableros.raiz(), 0);
     ArbolGeneral<Tablero>::preorden_iterador it;

     for(it = arbol_tableros.beginpreorden(); it != arbol_tableros.endpreorden() && !hay_arbol_ganador; ++it){
       Tablero ganador = tablero;
         if ((*it).quienGana() != 1 && ((*it).FichasIntroducidas()%2 != 0) &&  it != arbol_tableros.beginpreorden()){
            Tablero tab = *it.padre();
            ArbolGeneral<Tablero> partida;
            partida.AsignaRaiz(tab);
            ConstruirArbol(partida.raiz(), 1);
            ArbolGeneral<Tablero>::preorden_iterador it2;
            for(it2 = partida.beginpreorden(); it2 != partida.endpreorden(); ++it2){
              if((*it2).quienGana() == 1){
                hay_arbol_ganador = true;
                ganador = *it2;
              }
            }
            if(!hay_arbol_ganador){
            tablero = tab;
            hay_arbol_ganador = true;

            break;
          }else{
            tablero.cambiarTurno();
            cout << BuscarTresAlineadas(ganador) << endl;
            tablero.colocarFicha(BuscarTresAlineadas(ganador)-1);
            break;
          }
      }
    }
//  tablero.cambiarTurno();

  }
