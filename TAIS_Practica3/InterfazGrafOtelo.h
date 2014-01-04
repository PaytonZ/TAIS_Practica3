
#ifndef INTERFAZGRAFOTELO_H_
#define INTERFAZGRAFOTELO_H_

using namespace System::Drawing;
#include "InterfazGrafT2.h"
#include "JuegoOtelo.h"

class InterfazGrafOtelo : public InterfazGrafT2 {

private:
    int ladoCasilla;
	virtual void muestraEst(Graphics^ canvas, const JuegoOtelo& EJ) const throw();
public:
    InterfazGrafOtelo(int w, int h);
    virtual ~InterfazGrafOtelo();

    virtual unsigned int dameColumna(unsigned int X) const throw(EInterfaz) { return X/ladoCasilla - 1;};

    virtual unsigned int dameFila(unsigned int Y) const throw(EInterfaz) { return Y/ladoCasilla - 1;};

    virtual void muestraEstado(Graphics^ canvas, const JuegoLogT2& EJ) const throw(EInterfaz);
	
};

#endif
