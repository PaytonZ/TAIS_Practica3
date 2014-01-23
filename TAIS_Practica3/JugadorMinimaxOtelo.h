#pragma once
#include "JugadorMinimaxT2.h"
#include "JuegoOtelo.h"

class JugadorMinimaxOtelo : public JugadorMinimaxT2{
public:
	int nivel;
	JugadorMinimaxOtelo(unsigned int n=4) : nivel(n) {};

	Casilla juega(const JuegoLogT2& EJ) const throw(EJugador)
	{
		if (typeid(EJ) == typeid(JuegoOtelo))
		{
			return JugadorMinimaxT2::juega(EJ);
		}
		else
		{
			throw EJugador("");

		}


	}

	float Heuristica(const JuegoLogT2& EJ, Turno T) const
	{
		const int pesos[8][8] = {
			{50, -1,5,2,2,5, -1,50},
			{-1,-10,1,1,1,1,-10,-1},
			{ 5, 1,1,1,1,1, 1, 5},
			{ 2, 1,1,0,0,1, 1, 2},
			{ 2, 1,1,0,0,1, 1, 2},
			{ 5, 1,1,1,1,1, 1, 5},
			{-1,-10,1,1,1,1,-10,-1},
			{50, -1,5,2,2,5, -1,50}
		};
		auto propio=0.0f , rival =0.0f;
		for(auto c=0; c < EJ.numCol()-1; c++ )
		{
			for(auto f=0; f < EJ.numFil(); f++)
			{
				auto fichaactual = EJ.dameCasilla(c,f);

				if(fichaactual==T)
				{
					propio += pesos[c][f];
				}
				else if(fichaactual==cambia(T))
				{
					rival+=pesos[c][f];
				}


			}
		}

		return propio - rival;
	}

private:


};

