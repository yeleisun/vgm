// $Id$
//
// Class TstPrimaryGeneratorAction
// -------------------------------
// The test detector construction
//
// Author: Ivana Hrivnacova; IPN Orsay


#ifndef TST_DETECTOR_CONSTRUCTION_H
#define TST_DETECTOR_CONSTRUCTION_H

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

#include "VGM/volumes/IFactory.h"
#include "Geant4GM/volumes/Factory.h"
#include "RootGM/volumes/Factory.h"
#include "XmlVGM/VExporter.h"

class TstVGeometry;

class TstDetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    TstDetectorConstruction(const G4String& inputType, 
                            const G4String& inputFactory,
                            const G4String& outputFactory,
			    const G4String& outputXML);
    virtual ~TstDetectorConstruction();

    virtual G4VPhysicalVolume* Construct();
    void SelectTest(const G4String& testName, G4bool fullAngle);
    void SelectVisualization(const G4String& visMode);
    void SetDebug(G4bool debugMode);

  private:
    bool IsGeant4Geometry() const;
    bool IsRootGeometry() const;
    void SelectChannels(const G4String& inputType, 
                        const G4String& inputFactory, 
                        const G4String& outputFactory,
			const G4String& outputXML);
    void SetG4VisAttributes() const;
    void DrawRootGeometry(bool withRayTrace) const;
    void SaveRootGeometry() const;
    void PrintGeant4Materials() const;
    void PrintRootMaterials() const;
    void GenerateXML() const;

    // static data members
    static const G4String  fgkTestNameCandidates;
    static const G4String  fgkVisModeCandidates;
    static const G4String  fgkInputCandidates;
    static const G4String  fgkFactoryCandidates;
    static const G4String  fgkOutputXMLCandidates;

    // data members
    G4String           fSelectedTest;
    G4String           fSelectedVisMode;
    G4bool             fFullAngle;
    VGM::IFactory*     fInputFactory;
    VGM::IFactory*     fOutputFactory;
    Geant4GM::Factory* fGeant4Factory;
    RootGM::Factory*   fRootFactory;
    XmlVGM::VExporter* fXMLExporter;
    G4String           fXMLFileName;
    TstVGeometry*      fGeometry;
};

#endif //TST_V_DETECTOR_CONSTRUCTION_H

