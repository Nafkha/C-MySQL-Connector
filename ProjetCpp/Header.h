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
void modifierEtudiant();
void supprimerGroupeModule();
void supprimerMatiere();
void supprimerGroupe();
void creationGroupe(); // Cr�er un groupe
void afficherListeGroupe();
void creationEnseignant(); //Cr�er un enseignant
void afficherListeEnseignant();
void creationGroupeModule(); //Cr�er un Groupe Module
void afficherListeGroupeModule();
void creationMatiere();
void addNote();
void afficherEtudiantsParGroupe();
//Obtenir les donn�es de la BD
void remplirGroupe();
void remplirGroupeModule(GroupeModule gm);
void afficherGroupe(Groupe gp);
string testAdmission(double moy);
string testMention(double moy);
void affciherMatiereParEsneignant();
void modifierMatiere();


