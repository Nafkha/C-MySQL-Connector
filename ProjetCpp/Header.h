#pragma once
#include <iostream>
#include "Enseignant.h"
#include "Etudiant.h"
#include "Groupe.h"
#include "GroupeModule.h"
#include "Matiere.h"
#include "Note.h"
#include "databaseConnection.h"
#include "iomanip"
#include <cmath>
using namespace std;
void creationEtudiant(); //Cr�er un �tudiant;
void afficherListeEtudiants(); 
void supprimerEtudiant();
void creationGroupe(); // Cr�er un groupe
void afficherListeGroupe();
void creationEnseignant(); //Cr�er un enseignant
void afficherListeEnseignant();
void creationGroupeModule(); //Cr�er un Groupe Module
void afficherListeGroupeModule();
void creationMatiere();
void addNote();
//Obtenir les donn�es de la BD
void remplirGroupe();
void remplirGroupeModule(GroupeModule gm);
void afficherGroupe(Groupe gp);