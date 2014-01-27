#include "JugadorMinimaxT2.h"
#include "JuegoOtelo.h"



#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)

float JugadorMinimaxT2::valoraMin(const JuegoLogT2& EJ, Turno T, int n, float A, float B) const throw(EJugador)
{
	if (EJ.final() || n == 0) return Heuristica(EJ,T);
	else
	{
		for(auto c=0; c < EJ.numCol() ;c++)
		{
			for (auto f=0; f < EJ.numFil() ; f++)
			{
				Casilla jugadaActual(c,f);
				if(EJ.sePuede(jugadaActual)){
					auto EJcloned = EJ.clona();
					EJcloned->aplicaJugada(jugadaActual);
					B = MIN((valoraMax(*EJcloned,T,n-1, A, B)), B); 
					delete EJcloned;
					EJcloned=NULL;
					if(A >= B ) return B;
				}
			}
		}
		return B; 
	}

}

float JugadorMinimaxT2::valoraMax(const JuegoLogT2& EJ, Turno T, int n, float A, float B) const throw(EJugador)
{
	if (EJ.final() || n == 0) return Heuristica(EJ,T);
	else
	{
		for(auto c=0; c < EJ.numCol() ;c++)
		{
			for (auto f=0; f < EJ.numFil() ; f++)
			{
				Casilla jugadaActual(c,f);
				if(EJ.sePuede(jugadaActual)){
					auto EJcloned = EJ.clona();
					EJcloned->aplicaJugada(jugadaActual);
					A=  MAX( valoraMin(*EJcloned,T,n-1, A, B ), A); 
					delete EJcloned;
					EJcloned=NULL;
					if(A >= B ) return A;
				}
			}
		}
		return A;
	}
}

Casilla JugadorMinimaxT2::juega(const JuegoLogT2& EJ) const throw(EJugador)
{
	Casilla jugadamejor;
	
	auto mejorJugada = -std::numeric_limits<float>::infinity();
	Turno turnoactual(EJ.dameTurno());
	if(!EJ.fin())
	{
		for(auto c=0; c < EJ.numCol(); c++ )
		{
			for(auto f=0; f < EJ.numFil(); f++)
			{
				Casilla jugadaActual(c,f);
				if(EJ.sePuede(jugadaActual))
				{

					auto EJcloned = EJ.clona();
					EJcloned->aplicaJugada(jugadaActual);
					auto aux= valoraMin(*EJcloned,turnoactual,nivel-1,mejorJugada, std::numeric_limits<float>::infinity());
					delete EJcloned;
					EJcloned=NULL;
					if(aux > mejorJugada) 
					{
						mejorJugada= aux;
						jugadamejor = jugadaActual;
					}
				}
			}
		}
	}
	else
	{
		throw(EJugador("Fin de la partida"));
	}
	if(jugadamejor.col > EJ.numCol() || jugadamejor.fil > EJ.numFil() )
	{
		jugadamejor = Casilla(8,0);
		//throw(EJugador("No se pudo determinar una jugada valida"));
	}
	return jugadamejor;
}