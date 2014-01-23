#include "JuegoOtelo.h"
#include <sstream>

void JuegoOtelo::aplicaJugada(unsigned int c,unsigned int f) throw(EJuego) {
	if(sePuede(c,f) && !ganador) {
		tablero->at(c,f)=turno;
		comer(c,f);
		if(turno==Jhum)
		{
			numFichas[0]++;
		}else
		{
			numFichas[1]++;
		}
		libres--;
		//ganador=conecta3(c,f);
		if(!ganador) turno=cambia(turno);
	} else throw EJuego("Jugada incorrecta");
}


bool JuegoOtelo::vertical(int c, int f) const
{

	return verticalabajo(c,f) || verticalarriba(c,f);


}
bool JuegoOtelo::horizontal(int c, int f) const
{
	return horizontalderecha(c,f) || horizontalizquierda(c,f);

}
bool JuegoOtelo::diagonal(int c,int f) const
{
	return diagonalabajoderecha(c,f) || diagonalabajoizquierda(c,f)|| diagonalarribaderecha(c,f) || diagonalarribaizquierda(c,f);

}

bool JuegoOtelo::horizontalderecha( int c, int f) const 
{
	auto resultado = false;
	auto salir= false;

	if (enRango(c+1,f))
	{
		// la pieza a comer esta por la derecha
		if (dameCasilla(c+1,f) == cambia(turno)) 
		{
			int i = c+2;
			int numcol = numCol();
			while(enRango(i,f) && !resultado && !salir )
			{
				if(dameCasilla(i,f)==turno) resultado=true;
				if(dameCasilla(i,f)==Jn) salir=true;
				i++;
			}
		}
	}

	return resultado && !salir;


}
bool JuegoOtelo::horizontalizquierda( int c, int f) const 
{
	auto resultado = false;
	auto salir= false;
	if (enRango(c-1,f))
	{
		// la pieza a comer esta por la izq
		if (dameCasilla(c-1,f) == cambia(turno)) 
		{
			int i = c-2;
			while(enRango(i,f) && !resultado && !salir)
			{
				if(dameCasilla(i,f)==turno) resultado=true;
				if(dameCasilla(i,f)==Jn) salir=true;
				i--;
			}
		}

	}

	return resultado && !salir;
}

bool JuegoOtelo::verticalarriba( int c, int f) const
{
	auto resultado = false;
	auto salir= false;
	if (enRango(c,f-1))
	{
		// la pieza a comer esta por la izq
		if (dameCasilla(c,f-1) == cambia(turno)) 
		{
			int i = f-2;
			while(enRango(c,i) && !resultado && !salir)
			{
				if(dameCasilla(c,i)==turno) resultado=true;
				if(dameCasilla(c,i)==Jn) salir=true;
				i--;
			}
		}

	}
	return resultado && !salir;
}
bool JuegoOtelo::verticalabajo( int c, int f) const
{
	auto resultado = false;
	auto salir= false;
	if (enRango(c,f+1))
	{
		// la pieza a comer esta por la derecha
		if (dameCasilla(c,f+1) == cambia(turno)) 
		{
			int i = f+2;
			while(enRango(c,i) && !resultado && !salir )
			{
				if(dameCasilla(c,i)==turno) resultado=true;
				if(dameCasilla(c,i)==Jn) salir=true;
				i++;
			}
		}
	}

	return resultado && !salir;
}

bool JuegoOtelo::diagonalarribaderecha( int c, int f) const
{
	auto resultado = false;
	auto salir= false;

	if (enRango(c+1,f+1))
	{
		// la pieza a comer esta por la derecha
		if (dameCasilla(c+1,f+1) == cambia(turno)) 
		{
			int i = c+2;
			int j= f+2;

			while(enRango(i,j) && !resultado && !salir )
			{
				if(dameCasilla(i,j)==turno) resultado=true;
				if(dameCasilla(i,j)==Jn) salir=true;
				i++;
				j++;
			}
		}
	}

	return resultado && !salir;
}
bool JuegoOtelo::diagonalabajoderecha( int c, int f) const
{
	auto resultado = false;
	auto salir= false;

	if (enRango(c-1,f-1))
	{
		// la pieza a comer esta por la derecha
		if (dameCasilla(c-1,f-1) == cambia(turno)) 
		{
			int i = c-2;
			int j= f-2;

			while(enRango(i,j) && !resultado && !salir )
			{
				if(dameCasilla(i,j)==turno) resultado=true;
				if(dameCasilla(i,j)==Jn) salir=true;
				i--;
				j--;
			}
		}
	}

	return resultado && !salir;
}
bool JuegoOtelo::diagonalabajoizquierda( int c, int f) const
{

	auto resultado = false;
	auto salir= false;

	if (enRango(c+1,f-1))
	{
		// la pieza a comer esta por la derecha
		if (dameCasilla(c+1,f-1) == cambia(turno)) 
		{
			int i = c+2;
			int j= f-2;

			while(enRango(i,j) && !resultado && !salir )
			{
				if(dameCasilla(i,j)==turno) resultado=true;
				if(dameCasilla(i,j)==Jn) salir=true;
				i++;
				j--;
			}
		}
	}

	return resultado && !salir;
}
bool JuegoOtelo::diagonalarribaizquierda( int c, int f) const
{

	auto resultado = false;
	auto salir= false;

	if (enRango(c-1,f+1))
	{
		// la pieza a comer esta por la derecha
		if (dameCasilla(c-1,f+1) == cambia(turno)) 
		{
			int i = c-2;
			int j= f+2;

			while(enRango(i,j) && !resultado && !salir )
			{
				if(dameCasilla(i,j)==turno) resultado=true;
				if(dameCasilla(i,j)==Jn) salir=true;
				i--;
				j++;
			}
		}
	}

	return resultado && !salir;
}


void JuegoOtelo::comerhorizontal(int c, int f) 
{
	auto comidas = 0;
	if(horizontalderecha(c,f))
	{

		auto i = c+1;
		while(enRango(i,f) && dameCasilla(i,f) == cambia(turno))
		{
			tablero->at(i,f) = turno;
			i++;
			comidas++;

		}
	}
	if(horizontalizquierda(c,f))
	{

		auto i = c-1;
		while(enRango(i,f) && dameCasilla(i,f) == cambia(turno))
		{
			tablero->at(i,f) = turno;
			i--;
			comidas++;
		}
	}
	actualizarfichas(comidas);

}

void JuegoOtelo::comervertical(int c, int f) 
{
	auto comidas = 0;
	if(verticalabajo(c,f))
	{
		auto i = f+1;
		while(enRango(c,i) && dameCasilla(c,i) == cambia(turno))
		{
			tablero->at(c,i) = turno;
			i++;
			comidas++;

		}

	}
	if(verticalarriba(c,f))
	{
		auto i = f-1;
		while(enRango(c,i) && dameCasilla(c,i) == cambia(turno))
		{
			tablero->at(c,i) = turno;
			i--;
			comidas++;

		}

	}
	actualizarfichas(comidas);

}
void JuegoOtelo::comerdiagonal(int c, int f) 
{
	auto comidas = 0;
	if(diagonalabajoderecha(c,f))
	{
		int i = c-1;
		int j= f-1;
		while(enRango(i,j) && dameCasilla(i,j) == cambia(turno))
		{
			tablero->at(i,j) = turno;
			i--;
			j--;
			comidas++;

		}
			
	}
	
	if(diagonalabajoizquierda(c,f))
	{
		int i = c+1;
		int j= f-1;
		while(enRango(i,j) && dameCasilla(i,j) == cambia(turno))
		{
			tablero->at(i,j) = turno;
			i++;
			j--;
			comidas++;

		}

	}
	if(diagonalarribaderecha(c,f))
	{
		int i = c+1;
		int j= f+1;
		while(enRango(i,j) && dameCasilla(i,j) == cambia(turno))
		{
			tablero->at(i,j) = turno;
			i++;
			j++;
			comidas++;

		}
	}	
	if(diagonalarribaizquierda(c,f))
	{
		int i = c-1;
		int j= f+1;
		while(enRango(i,j) && dameCasilla(i,j) == cambia(turno))
		{
			tablero->at(i,j) = turno;
			i--;
			j++;
			comidas++;

		}
	}
	actualizarfichas(comidas);
}
void JuegoOtelo::comer(int c,int f)
{
	comerhorizontal(c,f);
	comervertical(c,f);
	comerdiagonal(c,f);
}

void JuegoOtelo::actualizarfichas(int num_fichas)
{
	if(turno==Jhum)
	{
		numFichas[0]+=num_fichas;
		numFichas[1]-=num_fichas;
	}
	else
	{
		numFichas[0]-=num_fichas;
		numFichas[1]+=num_fichas;
	}

}

string JuegoOtelo::getNumFichas(Turno t) const
{
	stringstream aux;
	string aux1;

	if(t==Jhum) 
		{
			aux << numFichas[0];
	}
	if(t==Jmaq) {
		aux << numFichas[1];
	}

	return aux.str();
}