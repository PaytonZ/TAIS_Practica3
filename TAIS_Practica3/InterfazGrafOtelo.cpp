#include "InterfazGrafOtelo.h"

#include "JuegoOtelo.h"


using namespace System::Drawing;

InterfazGrafOtelo::InterfazGrafOtelo(int w, int h) : InterfazGrafT2(w,h), ladoCasilla(window_width/10) {}
InterfazGrafOtelo::~InterfazGrafOtelo(){}

void InterfazGrafOtelo::muestraEst(Graphics^ canvas, const JuegoOtelo& EJ) const throw(){

	canvas->FillRectangle( Brushes::Gainsboro, 0,0, window_width, window_height ); // borra el tablero

	// rotulo informativo
	Font^ letra = gcnew Font( "Arial", 12 );
	Point pr(165,20);

	Point pasar((8+1)*ladoCasilla+10,window_height - (8+2)*ladoCasilla+42);

	Point posresultado(100,window_height- ladoCasilla/2);

	
	auto aux = "Blancas : " + EJ.getNumFichas(Jhum) + " Negras : "  + EJ.getNumFichas(Jmaq) + " Libres: " + convertInt(EJ.getLibres()) ;
	System::String ^resultado =  gcnew System::String(aux.c_str()) ;

	canvas->DrawString(resultado,letra,Brushes::Black,posresultado);

	if(!EJ.final()) 
		switch(EJ.dameTurno()){
		case Jhum: canvas->DrawString( "Turno usuario", letra, Brushes::Blue, pr); break;
		case Jmaq: canvas->DrawString( "Turno m�quina", letra, Brushes::Blue, pr); break;
	}
	else {
		switch(EJ.dameGanador()){
		case Jhum: canvas->DrawString( "GANADOR: Usuario", letra, Brushes::Red, pr); break;
		case Jmaq: canvas->DrawString( "GANADOR: M�quina", letra, Brushes::Red, pr); break;
		case Jn: canvas->DrawString( "EMPATE", letra, Brushes::Red, pr); break;
		}
	}

	canvas->DrawString("P\n\n\nA\n\n\nS\n\n\nA\n\n\nR", letra, Brushes::Red, pasar);

	unsigned int c, f, x, y;
	for(c=0; c<EJ.numCol()-1; c++) {


		x = (c+1)*ladoCasilla;
		for(f=0; f<EJ.numFil(); f++) {
			y = window_height - (f+2)*ladoCasilla;  // dar la vuelta: y crece hacia abajo

			// dibuja el fondo de la casilla
			canvas->FillRectangle(Brushes::Chocolate, x, y, ladoCasilla-1, ladoCasilla-1);

			Ficha fi = EJ.dameCasilla(c,f);

			switch(fi){
			case Jn :  
				break;
			case Jhum : // ficha del humano: circulo blanco
				canvas->FillEllipse(Brushes::White, x+5, y+5, ladoCasilla-10,ladoCasilla-10); 
				break;
			case Jmaq : // ficha de la maquina: circulo negro
				canvas->FillEllipse(Brushes::Black, x+5, y+5, ladoCasilla-10,ladoCasilla-10); 
				break;
			}
		}

	}
}

void  InterfazGrafOtelo::muestraEstado(Graphics^ canvas, const JuegoLogT2& EJ)const throw(EInterfaz) { // posible error de casting
	if (typeid(EJ) != typeid(JuegoOtelo))
		throw EInterfaz();
	else {
		muestraEst(canvas, (const JuegoOtelo&) EJ);
	}
};

