#ifndef DIODE_SHOCKLEY_H
#define DIODE_SHOCKLEY_H

#include "Electronic Components/ElectronicComponent.h"

class Diode_Shockley : public ElectronicComponent{

public:
    Diode_Shockley();

    //Drawing the component:
    void Show();
};

#endif // DIODE_SHOCKLEY_H