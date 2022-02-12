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
using namespace std;
void afficher();
void creationEtudiant();
void afficherListeEtudiants();
void supprimerEtudiant();
void creationGroupe();
void afficherListeGroupe();
void creationEnseignant();
void afficherListeEnseignant();
void creationGroupeModule();
void afficherListeGroupeModule();