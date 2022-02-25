#include<iostream>
#include <stdlib.h>
#include "Etudiant.h"
#include "Enseignant.h"
#include "Matiere.h"
#include "GroupeModule.h"
#include "Groupe.h"
#include "Note.h"
#include "Header.h"
using namespace std;
#include "databaseConnection.h";

const string server = "localhost:3306";
const string username = "root";
const string password = "admin";

int main()
{
	databaseConnection db(server, username, password);
	db.createConnexion();
	
	Menu_Principale:
	cout << "1-Gestion des Groupes " << endl;
	cout << "2-Gestion des Etudiants " << endl;
	cout << "3-Gestion des Enseignants " << endl;
	cout << "4-Gestion des Groupes Modules " << endl;
	cout << "5-Gestion des Matieres " << endl;
	cout << "6-Gestion des Notes" << endl;
	int choice;
	do
	{
		cout << "Donner votre choix" << endl;
		cin >> choice;
	} while (choice < 0 || choice>6);
	switch (choice)
	{
	case 0 :
		exit(1);
	case 1 :
		goto  Menu_Groupe;
		break;
	case 2:
		goto Menu_Etudiants;
	case 3:
		goto Menu_Enseignant;
	case 4 :
		goto Menu_GroupeModule;
	case 5:
		goto  Menu_Matieres;
	case 6:
		goto  Menu_Note;
	}
	Menu_Groupe:
	cout << "0-Quitter le programme" << endl;
	cout << "1-Ajouter un groupe" << endl;
	cout << "2-Afficher les PV des groupes" << endl;
	cout << "3-Menu Principale" << endl;
	do
	{
		cout << "Donner votre choix" << endl;
		cin >> choice;
	} while (choice < 0 || choice>3);
	switch (choice)
	{
	case 0:
		exit(1);
	case 1:
		creationGroupe();
		goto Menu_Groupe;
	case 2:
		remplirGroupe();
		goto Menu_Groupe;
	case 3:
		goto Menu_Principale;
	}

	Menu_Etudiants:
	cout << "1-Ajouter un etudiant" << endl;
	cout << "2-Afficher la liste des etudiants" << endl;
	cout << "3-Afficher la liste des etudiants par groupe" << endl;
	cout << "4-Supprimer un etudiant" << endl;
	cout << "5-Menu Principale" << endl;
	do
	{
		cout << "Donner votre choix" << endl;
		cin >> choice;
	} while (choice < 0 || choice>5);
	switch (choice)
	{
	case 0:
		exit(1);
	case 1:
		creationEtudiant();
		goto Menu_Principale;
	case 2:
		afficherListeEtudiants();
		goto Menu_Principale;
	case 3:
		afficherEtudiantsParGroupe();
		goto Menu_Principale;
	case 4 :
		supprimerEtudiant();
		goto Menu_Etudiants;
	case 5:
		goto Menu_Principale;
	}
	Menu_Enseignant:
	cout << "1-Ajouter un enseignant" << endl;
	cout << "2-Afficher la liste des tous les enseignants" << endl;
	cout << "3-Afficher la liste des matieres d'un enseignant" << endl;
	cout << "4-Supprimer un enseingnat" << endl;
	cout << "5-Menu Principale" << endl;
	do
	{
		cout << "Donner votre choix" << endl;
		cin >> choice;
	} while (choice < 0 || choice>5);
	switch (choice)
	{
	case 0:
		exit(1);
	case 1:
		creationEnseignant();
		goto Menu_Principale;
	case 2:
		afficherListeEnseignant();
		goto Menu_Principale;
	case 3:
		affciherMatiereParEsneignant();
		goto  Menu_Principale;
	case 4:
		cout << "Supprimer un enseignant" << endl;
		goto Menu_Etudiants;
	case 5:
		goto Menu_Principale;
	}
	Menu_GroupeModule:
	cout << "0-Quitter le programme" << endl;
	cout << "1-Ajouter un groupe module"<<endl;
	cout << "2-Afficher la liste des groupes modules"<<endl;
	cout << "3-Supprimer un groupe module"<<endl;
	cout << "4-Menu Principale"<<endl;
	do
	{
		cout << "Donner votre choix" << endl;
		cin >> choice;
	} while (choice < 0 || choice>4);
	switch (choice);
	switch (choice)
	{
	case 0 :
		exit(1);
	case 1:
		creationGroupeModule();
		goto Menu_GroupeModule;
	case 2:
		cout << "Groupe Module" << endl;
		goto Menu_GroupeModule;
	case 3:
		cout << "Supprimer Groupe module" << endl;
		goto Menu_GroupeModule;
		
	case 4:
		goto Menu_Principale;
	}
	Menu_Matieres:
	cout << "0-Quitter le programme" << endl;
	cout << "1-Ajouter une matiere " << endl;
	cout << "2-Supprimer une matiere " << endl;
	cout << "3-Mattre a jour une matiere " << endl;
	cout << "4-Menu Principale " << endl;
	do
	{
		cout << "Donner votre choix" << endl;
		cin >> choice;
	} while (choice < 0 || choice>4);
	switch (choice)
	{
	case 0 :
		exit(1);
	case 1 :
		creationMatiere();
		goto Menu_Principale;
	case 2 :
		cout << "Supprimer une matiere" << endl;
		goto Menu_Principale;
	case 3:
		cout << "Mettre a jour une matiere" << endl;
		goto Menu_Principale;
	case 4:
		goto Menu_Principale;
	}
	Menu_Note:
	cout << "0-Quitter le programme" << endl;
	cout << "1-Ajouter une Note " << endl;
	cout << "2-Mettre a jour une Note " << endl;
	cout << "3-Menu principale " << endl;
	do
	{
		cout << "Donner votre choix" << endl;
		cin >> choice;
	} while (choice < 0 || choice >3);
	switch (choice)
	{
	case 0:
		exit(1);
	case 1:
		addNote();
		goto Menu_Principale;
	case 2:
		cout << "Mise a jour" << endl;
		goto Menu_Principale;
	case 3:
		goto Menu_Principale;
	}




}
