
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <unistd.h>
#include <termio.h>     // Linux/Windows users
//#include <termios.h>    // Mac OSX users
#include "JugadorAutomatico.h"
#include "ArbolGeneral.h"
#include "tablero.h"
#include "mando.h"

using namespace std;

/******************************************************************************/
/**
 * @brief Comprueba que los argumentos introducidos por el usuario sean correctos.
 * @param filas : filas del tablero (>= 4).
 * @param columnas : columnas del tablero (>= 4).
 * @param metrica : nivel de dificultad del tablero (>= 0).
 * @param turno : jugador que empieza(1 o 2) .

 */

bool argumentos_correctos(const int filas, const int columnas, const int metrica, const int turno){
  if (filas < 4 || columnas < 4 || metrica < 0 || (turno != 1 && turno != 2))
    return false;
  else
    return true;
}

/******************************************************************************/
/**
 * @brief Captura el caracter pulsado por teclado (sin necesidad de pulsar, a continuación, Enter).
 * @return: Caracter pulsado (char).
 */
char getch() {
        char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
                perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
                perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
                perror ("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
                perror ("tcsetattr ~ICANON");
        return (buf);
}

/******************************************************************************/
/**
 * @brief Imprime en pantalla el tablero completo, con el mando y el jugador.
 * @param t : Tablero que se va a imprimir.
 * @param m : Mando indicando la posición del jugador.
 */
void imprimeTablero(Tablero & t, Mando & m){
    cout << m.GetJugador() << endl;
    cout << t ;
    cout << m.GetBase() << endl;
    cout << m.GetMando() << endl;
}

/******************************************************************************/
/**
 * @brief Implementa el desarrollo de una partida de Conecta 4 sobre un tablero 5x7, pidiendo por teclado los movimientos de ambos jugadores según turno.
 * @return : Identificador (int) del jugador que gana la partida (1 o 2).
 */
int jugar_partida(const int filas, const int columnas, const int metrica, const int turno_inicial){
    srand(time(NULL));

    Tablero tablero(filas, columnas);
    if (turno_inicial == 2){
      tablero.cambiarTurno();
    }
    Mando mando(tablero);       //Mando para controlar E/S de tablero
    char c = 1;
    int quienGana = tablero.quienGana();
    //mientras no haya ganador y no se pulse tecla de terminación
    if (metrica == 0){
      while(c != Mando::KB_ESCAPE && quienGana == 0) {
          system("clear");
          mando.actualizarJuego(c, tablero);  // actualiza tablero según comando c
          imprimeTablero(tablero, mando);     // muestra tablero y mando en pantalla
          quienGana = tablero.quienGana();    // hay ganador?
          if(quienGana==0) c = getch();       // Capturamos la tecla pulsada.
      }
    }
    else{
          JugadorAutomatico jugador;
          int contador = 0;
          while(c != Mando::KB_ESCAPE && quienGana == 0) {
          system("clear");
          cout << "Player(x) vs Computer(o)" << endl;
          //PARTIDA CON JUGADOR ALEATORIO
          //METRICA == 1;
          mando.actualizarJuego(c, tablero);  // actualiza tablero según comando c
          imprimeTablero(tablero, mando);     // muestra tablero y mando en pantalla
          quienGana = tablero.quienGana();
          if (tablero.GetTurno() == 2 ){
            jugador.metrica1(mando, c, contador, quienGana);

        }else if(quienGana==0)
          c = getch();
      }
  }
  cerr << "AMAPOLA";
  quienGana = tablero.quienGana();
  return quienGana;
}
int main(int argc, char *argv[]){
  if (argc == 5){
    const int filas = atoi(argv[1]);
    const int columnas = atoi(argv[2]);
    const int metrica = atoi(argv[3]);
    const int turno = atoi(argv[4]);
    int ganador;

    if(argumentos_correctos(filas, columnas, metrica, turno))
      ganador = jugar_partida(filas, columnas, metrica, turno);
    else
      ganador = jugar_partida(4, 4, 0, 1); //Por defecto

    cout << "Ha ganado el jugador " << ganador << endl;
  }
  else if (argc == 1){
    int ganador = jugar_partida(4, 4, 0, 1); //Por defecto
    cout << "Ha ganado el jugador " << ganador << endl;
  }
  else{
    cout << "Argumentos invalidos, modo de uso './conecta4 <filas_tablero> <cols_tablero> <metrica> <turno>'" << endl;
  }
}
