#include "JugadorMinimaxT2.h"



float JugadorMinimaxT2::valoraMin(const JuegoLogT2& EJ, Turno T, int n, float A, float B) const throw(EJugador)
{
	if (EJ.fin() || n == 0) return Heuristica(EJ,T);
	else
	{
		for(auto c=0; c < EJ.numCol() ;c++)
		{
			for (auto f=0; f < EJ.numFil() ; f++)
			{
				B = min ( valoraMax(EJ,T,n-1, A, B ), B); 
				if(A >= B ) return B;
			}
		}
        
	}

}

float JugadorMinimaxT2::valoraMax(const JuegoLogT2& EJ, Turno T, int n, float A, float B) const throw(EJugador)
{

}