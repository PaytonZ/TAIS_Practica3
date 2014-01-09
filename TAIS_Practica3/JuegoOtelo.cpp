#include "JuegoOtelo.h"


void JuegoOtelo::aplicaJugada(unsigned int c,unsigned int f) throw(EJuego) {
	if(sePuede(c,f) && !ganador) {
		tablero->at(c,f)=turno;
		libres--;
		//ganador=conecta3(c,f);
		if(!ganador) turno=cambia(turno);
	} else throw EJuego("Jugada incorrecta");
}


bool JuegoOtelo::vertical(unsigned int c,unsigned int f) const
{
	return true;
}
bool JuegoOtelo::horizontal(unsigned int c,unsigned int f) const
{
	auto resultado = false;
	auto izq = false;
	auto dcha= false;
	auto salir=false;

	if(tablero->at(c-1,f)==cambia(turno))
	{
		izq= true;
	}
	else if(tablero->at(c+1,f)==cambia(turno))
	{
		dcha= true;
	}
	if(izq || dcha ) 
	{
		auto i=2;

		while(!salir)
		{
			if(izq) { 
				if((c-i>=0))
				{
					salir=true;
					if((tablero->at(c-i,f)==turno))
				{
					resultado=true;
					
				}

				
				}

			}
			else if(dcha)
			{
				if(c+i < numCol() && tablero->at(c+i,f)==turno)
				{
					resultado=true;
					salir=true;
				}
			}

			i++;
		}
	}
	return resultado;
}
bool JuegoOtelo::diagonal(unsigned int c,unsigned int f) const
{
	return true;

}