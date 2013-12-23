#include "JuegoLogT2.h"


#ifndef JUEGOOTELO_H_
#define JUEGOOTELO_H_
class JuegoOtelo : public JuegoLogT2 {

public:

	static const int numCols = 9;
	static const int numFils = 8;

private:
	unsigned int libres;
	int numFichas[3];
	bool haPasado;

public:

	JuegoOtelo(Turno JI=Jn) : libres((numCols-1)*numFils){
		turno=JI;
		tablero=new Matriz<Ficha>(numCols,numFils,Jn);
	}
	JuegoOtelo(const JuegoOtelo& EJ) : JuegoLogT2(EJ) {
		libres=EJ.libres;
	}
	virtual ~JuegoOtelo(){

	}

	// deja el tablero en su configuraci�n inicial y el turno pasa a ser de JI
	virtual void reinicia(Turno JI)
	{
		JuegoLogT2::reinicia(JI);
		libres=(numCols-1)*numFils;
	}
	// m�todo abstracto que determina si se puede jugar en la posici�n (c,f)
	virtual bool sePuede(unsigned int c,unsigned int f) const throw()
	{
		try {
			return dameCasilla(c,f)==Jn;
		} catch(EJuego &) { return false; }
		return false;
	}

	// m�todo abstracto que aplica la jugada caracterizada por la posici�n (c,f) del tablero.
	// Si dicha jugada no es legal se lanza una excepci�n
	virtual void aplicaJugada(unsigned int c,unsigned int f) throw(EJuego)
	{
		if(sePuede(c,f) && !ganador) {


		}
		else
		{
			throw EJuego("Jugada incorrecta");
		}

	}



	// indica si no se pueden realizar m�s jugadas
	virtual bool fin() const
	{
		return false;
	}

	// devuelve el ganador, que por defecto es el turno actual cuando hay un ganador
	virtual Turno dameGanador() const throw()
	{
		return Jn;
	}
	// m�todo abstracto que devuelve un puntero a una copia del juego actual
	virtual JuegoLogT2* clona() const
	{
		return new JuegoOtelo(*this);
	}

};

#endif