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
void creationEtudiant(); //Créer un étudiant;
void afficherListeEtudiants(); 
void supprimerEtudiant();
void creationGroupe(); // Créer un groupe
void afficherListeGroupe();
void creationEnseignant(); //Créer un enseignant
void afficherListeEnseignant();
void creationGroupeModule(); //Créer un Groupe Module
void afficherListeGroupeModule();
void creationMatiere();
void addNote();
//Obtenir les données de la BD
void remplirGroupe();
void remplirGroupeModule(GroupeModule gm);
void afficherGroupe(Groupe gp);