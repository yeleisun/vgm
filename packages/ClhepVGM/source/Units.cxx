// $Id$
//
// Class Units
// ------------------
// Conversion from CLHEP physical units to VGM units..
//
// Author: Ivana Hrivnacova; IPN Orsay

#include <iostream>

#include "CLHEP/Units/SystemOfUnits.h" 

#include "ClhepVGM/Units.h"

//
// static const data members
//

const double ClhepVGM::Units::fgkLength       = 1./mm;
const double ClhepVGM::Units::fgkAngle        = 1./deg;
const double ClhepVGM::Units::fgkMassDensity  = 1./(g/cm3);
const double ClhepVGM::Units::fgkAtomicWeight = 1./(g/mole);
/*
const double ClhepVGM::Units::fgkLength       = mm;
const double ClhepVGM::Units::fgkAngle        = deg;
const double ClhepVGM::Units::fgkMassDensity  = (g/cm3);
const double ClhepVGM::Units::fgkAtomicWeight = (g/mole);
*/
//_____________________________________________________________________________
ClhepVGM::Units::Units() {
//
}
  
//_____________________________________________________________________________
ClhepVGM::Units::~Units() {
//
}

//
// public functions
//

//_____________________________________________________________________________
double ClhepVGM::Units::AxisUnit(VGM::Axis axis)
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
  std::cerr << "    ClhepVGM::Units::AxisUnit:"       << std::endl; 
  std::cerr << "    Undefined axis"                 << std::endl;
  std::cerr << "*** Error: Aborting execution  ***" << std::endl; 
  exit(1);
}
