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
	bool vertical(unsigned int c,unsigned int f) const;
	bool horizontal(unsigned int c,unsigned int f) const ;
	bool diagonal(unsigned int c,unsigned int f) const;



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

	// deja el tablero en su configuración inicial y el turno pasa a ser de JI
	virtual void reinicia(Turno JI)
	{
		JuegoLogT2::reinicia(JI);
		libres=(numCols-1)*numFils;
		tablero->at(3,3)=Jhum;
		tablero->at(4,4)=Jhum;
		tablero->at(4,3)=Jmaq;
		tablero->at(3,4)=Jmaq;
		libres-=4;
		numFichas[0]=2;
		numFichas[1]=2;
	}
	// método abstracto que determina si se puede jugar en la posición (c,f)
	virtual bool sePuede(unsigned int c,unsigned int f) const throw()
	{
		
		try {


			if( dameCasilla(c,f)!=Jn) return false;
			

			return horizontal(c,f) && vertical(c,f) && diagonal(c,f);

		} catch(EJuego &) { return false; }
		return false;
	}

	// método abstracto que aplica la jugada caracterizada por la posición (c,f) del tablero.
	// Si dicha jugada no es legal se lanza una excepción
	virtual void aplicaJugada(unsigned int c,unsigned int f) throw(EJuego);

	// indica si no se pueden realizar más jugadas
	virtual bool fin() const
	{
		return false;
	}
	// devuelve el ganador, que por defecto es el turno actual cuando hay un ganador
	virtual Turno dameGanador() const throw()
	{
		return Jn;
	}
	// método abstracto que devuelve un puntero a una copia del juego actual
	virtual JuegoLogT2* clona() const
	{
		return new JuegoOtelo(*this);
	}
};

#endif