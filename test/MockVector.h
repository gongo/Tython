// -*- C++ -*-

#ifndef _TYTHON_MOCK_VECTOR_H
#define _TYTHON_MOCK_VECTOR_H

#include "Vector.h"

namespace MockVector {
    const ty::Vector v00  = ty::Vector(    2.0f,    0.0f, 0.0f);
    const ty::Vector v30  = ty::Vector( 1.7320f,    1.0f, 0.0f); 
    const ty::Vector v45  = ty::Vector( 1.4142f, 1.4142f, 0.0f);
    const ty::Vector v60  = ty::Vector(    1.0f, 1.7320f, 0.0f); 
    const ty::Vector v90  = ty::Vector(    0.0f,    2.0f, 0.0f);
    const ty::Vector v120 = ty::Vector(   -1.0f, 1.7320f, 0.0f); 
    const ty::Vector v135 = ty::Vector(-1.4142f, 1.4142f, 0.0f);
    const ty::Vector v150 = ty::Vector(-1.7320f,    1.0f, 0.0f); 
    const ty::Vector v180 = ty::Vector(   -2.0f,    0.0f, 0.0f);
    const ty::Vector v210 = v30*-1;
    const ty::Vector v225 = v45*-1;
    const ty::Vector v240 = v60*-1;
    const ty::Vector v270 = v90*-1;
    const ty::Vector v300 = v120*-1;
    const ty::Vector v315 = v135*-1;
    const ty::Vector v330 = v150*-1;

    // [img:https://cacoo.com/diagrams/Bb3xMwCFtoBe92mD-EEFFA.png]
    const ty::Vector vHEAD           = ty::Vector(0.0f, 5.0f, 0.0f);
    const ty::Vector vNECK           = ty::Vector(0.0f, 3.0f, 0.0f);
    const ty::Vector vRIGHT_SHOULDER = ty::Vector(3.0f, 3.0f, 0.0f);
    const ty::Vector vRIGHT_ELBOW    = ty::Vector(3.0f, 1.0f, 0.0f);
    const ty::Vector vRIGHT_HAND     = ty::Vector(3.0f, -1.0f, 0.0f);
    const ty::Vector vLEFT_SHOULDER  = ty::Vector(-3.0f, 3.0f, 0.0f);
    const ty::Vector vLEFT_ELBOW     = ty::Vector(-3.0f, 1.0f, 0.0f);
    const ty::Vector vLEFT_HAND      = ty::Vector(-3.0f, -1.0f, 0.0f);
    const ty::Vector vWAIST          = ty::Vector(0.0f, 0.0f, 0.0f);
    
};

#endif // _TYTHON_MOCK_VECTOR_H
