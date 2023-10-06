// definition of the G4HodoscopeDetectorConstruction class
#ifndef G4HodoscopeDetectorConstruction_h
#define G4HodoscopeDetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "G4SDManager.hh"
#include "globals.hh"
#include "G4Element.hh"
#include "G4ElementTable.hh"
#include "G4Material.hh"
#include "G4MaterialTable.hh"
#include "G4PVPlacement.hh"
#include "G4LogicalVolume.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4SystemOfUnits.hh"
#include "G4LogicalSkinSurface.hh"
#include "G4OpticalSurface.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"

#include "Event.h"
#include "Detector.h"

class G4VPhysicalVolume;
class G4LogicalVolume;
class G4OpticalSkinSurface;

// Detector construction class to define materials and geometry

class G4HodoscopeDetectorConstruction : public G4VUserDetectorConstruction {
	
	public:
		G4HodoscopeDetectorConstruction(Event& theEvent);
		virtual ~G4HodoscopeDetectorConstruction();
		virtual G4VPhysicalVolume* Construct();

	private:

		void CreateWorld();
		void CreateGround();
		void PlaceDetector(Event& theEvent);
		G4VPhysicalVolume* CreateDetector();
		
		bool fCheckOverlaps = false;

		// solids
		G4Box* solidWorld = nullptr;
		G4Box* solidGround = nullptr;
		//++++++++++++++++++++++++++++
		G4Tubs* solidBrick01 = nullptr;//Editando aquì para definir 7 porciones de cilindros en variables solidBrick
		G4Tubs* solidBrick02 = nullptr;
		G4Tubs* solidBrick03 = nullptr;
		G4Tubs* solidBrick04 = nullptr;
		G4Tubs* solidBrick05 = nullptr;
		G4Tubs* solidBrick06 = nullptr;
		G4Tubs* solidBrick07 = nullptr;
                //++++++++++++++++++++++++++++
		G4Box* solidBrickI = nullptr;
		G4Box* solidBrick1 = nullptr;
		G4Box* solidBrick2 = nullptr;
		G4Box* solidBrick3 = nullptr;
		G4Box* solidIronCoverI = nullptr;
		G4Box* solidIronCoverII = nullptr;
		G4Box* solidIronCoverIII = nullptr;
		G4Box* solidIronCoverIV = nullptr;

		// logical and physical volumes
		G4LogicalVolume* logicWorld = nullptr;
		G4PVPlacement*   physWorld  = nullptr;
		
		G4LogicalVolume* logicGround = nullptr;
		G4PVPlacement*   physGround  = nullptr;

		//++++++++++++++++++++++++++++++++++++
		G4LogicalVolume* logicBrick01 = nullptr;// editando aquì para tener 7 porciones en variables logicBrick y physBrick
		G4PVPlacement*   physBrick01  = nullptr;
		G4LogicalVolume* logicBrick02 = nullptr;
		G4PVPlacement*   physBrick02  = nullptr;
                G4LogicalVolume* logicBrick03 = nullptr;
                G4PVPlacement*   physBrick03  = nullptr;
		G4LogicalVolume* logicBrick04 = nullptr;
                G4PVPlacement*   physBrick04  = nullptr;
		G4LogicalVolume* logicBrick05 = nullptr;
                G4PVPlacement*   physBrick05  = nullptr;
		G4LogicalVolume* logicBrick06 = nullptr;
                G4PVPlacement*   physBrick06  = nullptr;
		G4LogicalVolume* logicBrick07 = nullptr;
                G4PVPlacement*   physBrick07  = nullptr;
                //++++++++++++++++++++++++++++++++++++

		G4LogicalVolume* logicBrickI = nullptr;
                G4PVPlacement*   physBrickI  = nullptr;

		G4LogicalVolume* logicBrick1 = nullptr;
                G4PVPlacement*   physBrick1  = nullptr;

                G4LogicalVolume* logicBrick2 = nullptr;
                G4PVPlacement*   physBrick2  = nullptr;

                G4LogicalVolume* logicBrick3 = nullptr;
                G4PVPlacement*   physBrick3  = nullptr;

                G4LogicalVolume* logicIronCoverI = nullptr;
                G4PVPlacement*   physIronCoverI  = nullptr;		

                G4LogicalVolume* logicIronCoverII = nullptr;
                G4PVPlacement*   physIronCoverII  = nullptr;

                G4LogicalVolume* logicIronCoverIII = nullptr;
                G4PVPlacement*   physIronCoverIII  = nullptr;

                G4LogicalVolume* logicIronCoverIV = nullptr;
                G4PVPlacement*   physIronCoverIV  = nullptr;



		Event& fEvent;
};


#endif

