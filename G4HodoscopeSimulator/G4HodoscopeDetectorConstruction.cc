// implementation of the G4HodoscopeDetectorConstruction class
#include <iostream>

#include "G4HodoscopeDetectorConstruction.h"
#include "Materials.h"

#include "G4SDManager.hh"
#include "G4UnitsTable.hh"

using namespace std;


G4HodoscopeDetectorConstruction::G4HodoscopeDetectorConstruction(Event& theEvent) : 
	G4VUserDetectorConstruction(),
	fEvent(theEvent)
{ 
}

G4HodoscopeDetectorConstruction::~G4HodoscopeDetectorConstruction() 
	{ }

G4VPhysicalVolume*
G4HodoscopeDetectorConstruction::CreateDetector()
{

	CreateWorld();
	//CreateGround();
	PlaceDetector(fEvent);
	return physWorld;
}

void
G4HodoscopeDetectorConstruction::CreateWorld()
{

	// size definitions
	const Event::Config &cfg = fEvent.GetConfig();	

	// double fGroundSizeX = 5 * CLHEP::m;
	// double fGroundSizeY = 5 * CLHEP::m;
	// double fGroundSizeZ = 1 * CLHEP::m;

	double fWorldSizeX = 6 * CLHEP::m;
	double fWorldSizeY = 6 * CLHEP::m;
	double fWorldSizeZ = 6 * CLHEP::m;

	solidWorld  = new G4Box("World", fWorldSizeX/2, fWorldSizeY/2, fWorldSizeZ/2);
	logicWorld = new G4LogicalVolume(solidWorld, Materials().Air, "World");
	physWorld  =  new G4PVPlacement(nullptr, G4ThreeVector(), "World", logicWorld, 0, false, 0, fCheckOverlaps);




//########################--------OBJETIVO CON INTERFASE------------#################################


	// lead bricks
	double fBrickSizeX = 15.5 * CLHEP::cm;
	double fBrickSizeY = 15.5 * CLHEP::cm;
	double fBrickSizeZ = 150.0 * CLHEP::cm;

	solidBrick = new G4Box("LeadBrick", fBrickSizeX/2, fBrickSizeY/2, fBrickSizeZ/2);
	G4VisAttributes cgray(G4Colour::Gray());
	logicBrick = new G4LogicalVolume(solidBrick, Materials().Lead, "LeadBrick");
	logicBrick->SetVisAttributes(cgray);
	physBrick = new G4PVPlacement(nullptr, G4ThreeVector(0., 0., fBrickSizeZ/2 + 10*CLHEP::cm), logicBrick, "LeadBrick", logicWorld, false, 0, cfg.fCheckOverlaps);


// Tamaño de los bloques
//double fBrickSizeX = 8.0 * CLHEP::cm;
//double fBrickSizeY = 20.0 * CLHEP::cm;
//double fBrickSizeZ = 40.0 * CLHEP::cm;

//double altura = 10.0 * CLHEP::cm;

// Crear el primer bloque
//G4Box* solidBrick1 = new G4Box("LeadBrick1", fBrickSizeX, fBrickSizeY, fBrickSizeZ);
//G4LogicalVolume* logicBrick1 = new G4LogicalVolume(solidBrick1, Materials().Oil, "LeadBrick1");
//G4VPhysicalVolume* physBrick1 = new G4PVPlacement(nullptr, G4ThreeVector(-fBrickSizeX * 2, 0.,altura+ fBrickSizeZ), logicBrick1, "LeadBrick1", logicWorld, false, 0, cfg.fCheckOverlaps);

// Asignar un atributo visual (color) al primer bloque
//G4VisAttributes* azul = new G4VisAttributes(G4Colour::Blue());
//logicBrick1->SetVisAttributes(azul);

// Crear el segundo bloque al lado del primero
//G4Box* solidBrick2 = new G4Box("LeadBrick2", fBrickSizeX, fBrickSizeY, fBrickSizeZ);
//G4LogicalVolume* logicBrick2 = new G4LogicalVolume(solidBrick2, Materials().Water, "LeadBrick2");
//G4VPhysicalVolume* physBrick2 = new G4PVPlacement(nullptr, G4ThreeVector(0., 0.,altura+ fBrickSizeZ), logicBrick2, "LeadBrick2", logicWorld, false, 0, cfg.fCheckOverlaps);

//G4VisAttributes* cyan = new G4VisAttributes(G4Colour::Cyan());
//logicBrick2->SetVisAttributes(cyan);


// Crear el tercer bloque al lado del segundo
//G4Box* solidBrick3 = new G4Box("LeadBrick3", fBrickSizeX, fBrickSizeY, fBrickSizeZ);
//G4LogicalVolume* logicBrick3 = new G4LogicalVolume(solidBrick3, Materials().Oil, "LeadBrick3");
//G4VPhysicalVolume* physBrick3 = new G4PVPlacement(nullptr, G4ThreeVector(fBrickSizeX*2, 0.,altura+ fBrickSizeZ), logicBrick3, "LeadBrick3", logicWorld, false, 0, cfg.fCheckOverlaps);

//logicBrick3->SetVisAttributes(azul);













//########################## Esructura



	// lead bricks I (CAPA DE PLOMO ATENUADORA)
        double fBrickSizeXI = 28.5 * CLHEP::cm;
        double fBrickSizeYI = 28.5 * CLHEP::cm;
        double fBrickSizeZI = 1.0 * CLHEP::cm;

        solidBrickI = new G4Box("LeadBrickI", fBrickSizeXI, fBrickSizeYI, fBrickSizeZI);
        logicBrickI = new G4LogicalVolume(solidBrickI, Materials().Lead, "LeadBrickI");
	physBrickI = new G4PVPlacement(nullptr, G4ThreeVector(0., 0., 5.0*CLHEP::cm), logicBrickI, "LeadBrickI", logicWorld, false, 0, cfg.fCheckOverlaps); 

	G4VisAttributes* negro = new G4VisAttributes(G4Colour::Black());
	logicBrickI->SetVisAttributes(negro);


//########################################## RECORDAR QUE EL PANEL I ESTA EN (0,0,0)
	// Recubrimeinto de Hierro I
	double fIronCoverSizeX = 25.5 * CLHEP::cm;
	double fIronCoverSizeY = 25.5 * CLHEP::cm;
	double fIronCoverSizeZ = 0.2 * CLHEP::cm;

	solidIronCoverI = new G4Box("IronCoverI", fIronCoverSizeX, fIronCoverSizeY, fIronCoverSizeZ);
	logicIronCoverI = new G4LogicalVolume(solidIronCoverI, Materials().Iron, "IronCoverI");
	physIronCoverI = new G4PVPlacement(nullptr, G4ThreeVector(0., 0., 3.0 * CLHEP::cm), logicIronCoverI, "IronCoverI", logicWorld, false, 0, cfg.fCheckOverlaps);

        G4VisAttributes* rojo = new G4VisAttributes(G4Colour::Red());
        logicIronCoverI->SetVisAttributes(rojo);



//##################### II 
	double fIronCoverSizeXII = 25.5 * CLHEP::cm;
	double fIronCoverSizeYII = 25.5 * CLHEP::cm;
	double fIronCoverSizeZII = 0.2 * CLHEP::cm;

	solidIronCoverII = new G4Box("IronCoverII", fIronCoverSizeXII, fIronCoverSizeYII, fIronCoverSizeZII);
	logicIronCoverII = new G4LogicalVolume(solidIronCoverII, Materials().Iron, "IronCoverII");
	physIronCoverII = new G4PVPlacement(nullptr, G4ThreeVector(0., 0., -3.0 * CLHEP::cm), logicIronCoverII, "IronCoverII", logicWorld, false, 0, cfg.fCheckOverlaps);

        logicIronCoverII->SetVisAttributes(rojo);


//######################################### EL PANEL II ESTA EN (0,0,-50.0 CM)
//#################### III

	double posicionsegundopanel = -100.0 * CLHEP::cm;

	double fIronCoverSizeXIII = 25.5 * CLHEP::cm;
	double fIronCoverSizeYIII = 25.5 * CLHEP::cm;
	double fIronCoverSizeZIII = 0.2 * CLHEP::cm;

	solidIronCoverIII = new G4Box("IronCoverIII", fIronCoverSizeXIII, fIronCoverSizeYIII, fIronCoverSizeZIII);
	logicIronCoverIII = new G4LogicalVolume(solidIronCoverIII, Materials().Iron, "IronCoverIII");
	physIronCoverIII = new G4PVPlacement(nullptr, G4ThreeVector(0., 0., posicionsegundopanel+3), logicIronCoverIII, "IronCoverIII", logicWorld, false, 0, cfg.fCheckOverlaps);

        logicIronCoverIII->SetVisAttributes(rojo);

//33333333333333333333 IV

	double fIronCoverSizeXIV = 25.5 * CLHEP::cm;
	double fIronCoverSizeYIV = 25.5 * CLHEP::cm;
	double fIronCoverSizeZIV = 0.2 * CLHEP::cm;

	solidIronCoverIV = new G4Box("IronCoverIV", fIronCoverSizeXIV, fIronCoverSizeYIV, fIronCoverSizeZIV);
	logicIronCoverIV = new G4LogicalVolume(solidIronCoverIV, Materials().Iron, "IronCoverIV");
	physIronCoverIV = new G4PVPlacement(nullptr, G4ThreeVector(0., 0., posicionsegundopanel-3), logicIronCoverIV, "IronCoverIV", logicWorld, false, 0, cfg.fCheckOverlaps);

        logicIronCoverIV->SetVisAttributes(rojo);




}


void
G4HodoscopeDetectorConstruction::PlaceDetector(Event& theEvent)
{
	
	const Event::Config &cfg = theEvent.GetConfig();
	// loop in detector vector
	for (auto detIt = theEvent.DetectorRange().begin(); detIt != theEvent.DetectorRange().end(); detIt++) {
		auto& currentDet = detIt->second;
		BuildDetector(logicWorld, currentDet, theEvent, cfg.fCheckOverlaps);
	}

}

G4VPhysicalVolume* 
G4HodoscopeDetectorConstruction::Construct() 
{

	if (!physWorld) {
		//CreateElements();
		return CreateDetector();
	}
	return physWorld;

}
