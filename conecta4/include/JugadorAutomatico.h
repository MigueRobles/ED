#include "ArbolGeneral.h"
#include "tablero.h"
#include "mando.h"
#include <cstdlib>

class JugadorAutomatico{
    ArbolGeneral<Tablero> arbol_tableros;

  public:

    JugadorAutomatico() = default;

    JugadorAutomatico(const Tablero& t){
      arbol_tableros.AsignaRaiz(t);
    }

    JugadorAutomatico(const ArbolGeneral<Tablero>& copiar){
      arbol_tableros = copiar;
    }

    ~JugadorAutomatico(){
      arbol_tableros.~ArbolGeneral();
    }
/*
    ArbolGeneral<Tablero> GetArbol(){
      return arbol_tableros;
    }

    JugadorAutomatico& operator=(const JugadorAutomatico &j){
      arbol_tableros = j.GetArbol();
    }
*/
    /**
      * @brief Devuelve el tablero de la raíz del arbol de tableros
      * @return Devuelve la etiqueta de la raíz del arbol de tableros
      */
/*
    Tablero Raiz(){
      return arbol_tableros.etiqueta(arbol_tableros.raiz());
    }
    */
    /**
      * @brief Columnas del modelo de tablero que tenemos
      * @pre Que el arbol de tableros no este vacío
      * @return Devuelve 0 si el arbol esta vacío o el numero de columnas
      * del tablero modelo a partir del cual se crea el arbol de tableros
      * si no esta vacio
      */
/*
    const int GetColumnasTablero(){
      if (!arbol_tableros.empty())
        return Raiz().GetColumnas();
      else
        return 0;
    }
*/
    /**
      * @brief Inserta los tableros posibles generados por la siguiente jugada
      * @return Devuelve el arbol con los tableros posibles
      */
      /*
    ArbolGeneral<Tablero> SiguientesTablerosPosibles(){
      for(int i = GetColumnasTablero()-1; i >= 0; i--){
        Tablero copia(Raiz());
        if(copia.colocarFicha(i)){
          ArbolGeneral<Tablero> arbolillo(copia);
          arbol_tableros.insertar_hijomasizquierda(arbol_tableros.raiz(), arbolillo);
        }
      }
      return arbol_tableros;
    }
*/
    /**
      * @brief Inserta los tableros posibles generados por la siguiente jugada a partir de un nodo cualquiera
      * @param t Nodo a partir del cual queremos generar los posibles siguientes tableros
      * @return Devuelve el arbol con los tableros posibles
      */
      /*
    ArbolGeneral<Tablero> SiguientesTablerosPosiblesA(ArbolGeneral<Tablero>::Nodo t){
      for(int i = GetColumnasTablero()-1; i >= 0; i--){
        Tablero copia (arbol_tableros.etiqueta(t));
        if(copia.colocarFicha(i))
          arbol_tableros.insertar_hijomasizquierda(t, copia);
      }
      return arbol_tableros;
    }
*/
    /**
      * @brief Borrar los Tableros que no elegimos //Solo valido a nivel 1
      * @param t Nodo cuya etiqueta es el tablero elegido como mas viable para ganar
      * @return Devuelve el arbol actualizado con solo un nodo cuya etiqueta es el tablero mas viable
      */

      /*
    ArbolGeneral<Tablero> CambiaRaiz(ArbolGeneral<Tablero>::Nodo t){
      arbol_tableros.AsignaRaiz(arbol_tableros.etiqueta(t));
    }

    ArbolGeneral<Tablero> PodarHermanosInviablesNivel1(ArbolGeneral<Tablero>::Nodo t){//SIN TERMINAR
      //DEBE DE SER CON ITERADORES
      arbol_tableros.insertar_hijomasizquierda(t.padre(), t)
      //while (queden hermanos a la derecha)
        //borramos hermano a la derecha
    }
*/
    /**
      * @brief Borrar los Tableros que no elegimos //Valido a cualquier nivel del arbol
      * @param t Nodo cuya etiqueta es el tablero elegido como mas viable para ganar
      * @return Devuelve el arbol actualizado con el tablero mas viable como etiqueta del nodo raiz
      */
      /*
    ArbolGeneral<Tablero> PodarHermanosInviablesNivelN(ArbolGeneral<Tablero>::Nodo t){ //SIN TERMINAR
      if (t.padre() != 0){ //El padre no es la raiz;

      }
      else
        PodarHermanosInviablesNivel1(t);
      return arbol_tableros;
    }
*/

//----------------------------------------  METRICAS  ------------------------------------------//
      int metrica1(Mando &mando, char &c, int &contador, const int &quienGana){
        int aleatorio;
        if(quienGana==0){
          aleatorio = rand() % 2;
          if (aleatorio == 0)
            c = Mando::KB_LEFT;
          else if (aleatorio == 1)
            c = Mando::KB_RIGHT;
          contador ++;
          if (contador % 10 == 0)
            c = Mando::KB_SPACE;
        }
    }
};
