#include "JugadorAleaOtelo.h"
#include "JuegoOtelo.h"



Casilla JugadorAleaOtelo::juega(const JuegoLogT2& EC) const throw(EJugador)
{
	if (typeid(EC) != typeid(JuegoOtelo)) throw EJugador();
	else
	{
		if (EC.final()) throw EJugador();
		int col,fil;
        unsigned int Ncol=EC.numCol();
        unsigned int Nfil=EC.numFil();
        col=rand() % Ncol;
        fil=rand() % Nfil;
        while (!EC.sePuede(col,fil)) {
            col=rand() % Ncol;
            fil=rand() % Nfil;
        }
        return Casilla(col,fil);
	}
}