#include "JugadorAutoT2.h"

#pragma once
class JugadorAleaOtelo : public JugadorAutoT2 {
public:
	JugadorAleaOtelo(){};
	virtual ~JugadorAleaOtelo(){};
	virtual Casilla juega(const JuegoLogT2& EC) const throw(EJugador);
};