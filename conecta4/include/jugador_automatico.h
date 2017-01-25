#include "ArbolGeneral.h"
#include "tablero.h"
#include "mando.h"
#include <cstdlib>
#include<stdlib.h>
#include<time.h>

class jugador_automatico{
    ArbolGeneral<Tablero> arbol_tableros;
    const int NIVEL;

  public:
    /**
      * @brief Constructor por defecto de la clase jugador_automatico
      */

    jugador_automatico();
    /**
      * @brief Constructor de la clase jugador_automatico
      * @param t Tablero actual
      * @param nivel altura del árbol
      */

    jugador_automatico(const Tablero& t, const int& nivel);

    /**
      * @brief Constructor copia de la clase jugador_automatico
      * @param copiar jugador_automatico a copiar
      */

    jugador_automatico(const jugador_automatico& copiar);

    /**
      * @brief Destructor de la clase jugador_automatico
      */
    ~jugador_automatico();
    /**
      * @brief Devuelve el Arbol del juego actual
      * @return Devuelve el Arbol del juego actual
      */

    ArbolGeneral<Tablero> GetArbol() const;
    /**
      * @brief Operador de asignacion entre jugadores
      * @return Devuelve el jugador por referencia
      * @param jugador_automatico el jugador_automatico a igualar
      */

    jugador_automatico& operator=(const jugador_automatico &j);

    /**
      * @brief Devuelve el nivel de el arbol
      * @return Devuelve el nivel de el arbol
      */

    const int Nivel() const;

    /**
      * @brief Devuelve el tablero de la raíz del arbol de tableros
      * @return Devuelve la etiqueta de la raíz del arbol de tableros
      */

    Tablero Raiz();

    /**
      * @brief Columnas del modelo de tablero que tenemos
      * @pre Que el arbol de tableros no este vacío
      * @return Devuelve 0 si el arbol esta vacío o el numero de columnas
      * del tablero modelo a partir del cual se crea el arbol de tableros
      * si no esta vacio
      */

    const int GetColumnasTablero();

    /**
      * @brief Inserta los tableros posibles generados por la siguiente jugada
      * @return Devuelve el nodo al que se le ha insertado
      */

    void SiguientesTablerosPosibles();
    /**
      * @brief Inserta los tableros posibles generados por la siguiente jugada a partir de un nodo cualquiera
      * @param t Nodo a partir del cual queremos generar los posibles siguientes tableros
      * @return Devuelve el nodo al que se le ha insertado
      */

    void SiguientesTablerosPosiblesA(ArbolGeneral<Tablero>::Nodo t);
    /**
      * @brief Construye un el Arbol asociado a el tablero deseado
      * @param n Nodo a partir del cual queremos generar el arbol
      * @param profundidad Altura que tendrá el Arbol
      */
    void ConstruirArbol(ArbolGeneral<Tablero>::Nodo n, int profundidad);


    /**
      * @brief Buscamos 3 fichas alineadas de un mismo jugador
      * @return Devuelve
*/
    int BuscarTresAlineadas(const Tablero& t);
  //hacer la funcion bajar dos niveles
  //hacer la funcion puntuacion
//----------------------------------------  METRICAS  ------------------------------------------//
      void metrica1(Tablero &tablero);
      void metrica2(Tablero &tablero);
      /**
        *@brief Métrica que recorre el árbol y si puede ganar en el siguiente turno, gana.
        *@param tablero Tablero por referencia de la partida actual
        */
      void metrica3(Tablero &tablero);
      /**
        *@brief
        *@param tablero Tablero por referencia de la partida actual
        */
      void metrica4(Tablero &tablero);


};
