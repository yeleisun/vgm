// $Id$
//
// Class Units
// ------------------
// Conversion of Root geometry units into CLHEP system of units.
//
// Author: Ivana Hrivnacova; IPN Orsay

#include <iostream>

#include "CLHEP/Units/SystemOfUnits.h" 

#include "RootGM/common/Units.h"

//
// static const data members
//

const double RootGM::Units::fgkLength = cm;
const double RootGM::Units::fgkAngle  = deg;
const double RootGM::Units::fgkMassDensity  = g/cm3;
const double RootGM::Units::fgkAtomicWeight = g/mole;

//_____________________________________________________________________________
RootGM::Units::Units() {
//
}
  
//_____________________________________________________________________________
RootGM::Units::~Units() {
//
}

//
// public functions
//

//_____________________________________________________________________________
double RootGM::Units::AxisUnit(VGM::Axis axis)
{
  if (axis == VGM::kXAxis || 
      axis == VGM::kYAxis || 
      axis == VGM::kZAxis ||
      axis == VGM::kRho   || 
      axis == VGM::kRadial3D) { 
    
    return Length();
  }  

  if (axis == VGM::kPhi || 
      axis == VGM::kSphTheta) {
    return Angle();
  }  

  // axis == kUndefined  
  std::cerr << "    RootGM::Units::AxisUnit:"       << std::endl; 
  std::cerr << "    Undefined axis"                 << std::endl;
  std::cerr << "*** Error: Aborting execution  ***" << std::endl; 
  exit(1);
}
