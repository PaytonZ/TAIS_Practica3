#include "JuegoOtelo.h"


void JuegoOtelo::aplicaJugada(unsigned int c,unsigned int f) throw(EJuego) {
    if(sePuede(c,f) && !ganador) {
        tablero->at(c,f)=turno;
		libres--;
        //ganador=conecta3(c,f);
        if(!ganador) turno=cambia(turno);
    } else throw EJuego("Jugada incorrecta");
}