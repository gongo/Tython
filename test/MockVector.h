// -*- C++ -*-

#ifndef _TYTHON_MOCK_VECTOR_H
#define _TYTHON_MOCK_VECTOR_H

namespace MockVector {
    const Vector v00  = Vector(    2.0f,    0.0f, 0.0f);
    const Vector v30  = Vector( 1.7320f,    1.0f, 0.0f); 
    const Vector v45  = Vector( 1.4142f, 1.4142f, 0.0f);
    const Vector v60  = Vector(    1.0f, 1.7320f, 0.0f); 
    const Vector v90  = Vector(    0.0f,    2.0f, 0.0f);
    const Vector v120 = Vector(   -1.0f, 1.7320f, 0.0f); 
    const Vector v135 = Vector(-1.4142f, 1.4142f, 0.0f);
    const Vector v150 = Vector(-1.7320f,    1.0f, 0.0f); 
    const Vector v180 = Vector(   -2.0f,    0.0f, 0.0f);
    const Vector v210 = v30*-1;
    const Vector v225 = v45*-1;
    const Vector v240 = v60*-1;
    const Vector v270 = v90*-1;
    const Vector v300 = v120*-1;
    const Vector v315 = v135*-1;
    const Vector v330 = v150*-1;
};

#endif // _TYTHON_MOCK_VECTOR_H
