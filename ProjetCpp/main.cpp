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

const string server = "localhost:3306";
const string username = "root";
const string password = "admin";
//sql::Connection* con;
#include "databaseConnection.h";
/*void test()
{
	Etudiant e(0, "Nafkha", "Youssef", "nafkha.m.youssef@gmail.com", 0, true);
	Enseignant en(1, "AAA", "BBBB", "aaa@bbb.com", 1);
	cout << "Ajout de matiere" << endl;
	Matiere m("m", "math", 3, en, 3);
	cout << "Ajoute de groupe module" << endl;
	GroupeModule gm("g", "m", 3);
	gm.ajouterMatiereGM(m);
	cout << "Ajotu de note" << endl;
	Note nt1(e, m, 15, "DS", true);
	cout << "Ajotu de note" << endl;

	Note nt2(e, m, 16, "TP", true);
	cout << "Ajotu de note" << endl;

	Note nt3(e, m, 17, "Exam", true);
	Groupe gp("irm", "1ere", "ing", "inf", 3);
	Groupe gp1;
	//gp.fetchgroup();
	gm.getNotes();
	vector<Note> lnotes = gm.get_liste_note();
	for (int i = 0;i < lnotes.size();i++)
	{
		cout << "Note : " << lnotes.at(i).get_note() << " Type : " << lnotes.at(i).get_type() << endl;
	}

}
*/

int main()
{
	databaseConnection db(server, username, password);
	db.createConnexion();
	/*---Menu---*/
	Menu_Principale:
	cout << "1-Gestion des Groupe " << endl;
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
		
	}
	Menu_Groupe:
	cout << "1-Ajouter un groupe" << endl;
	cout << "2-Afficher la liste de groupes" << endl;
	cout << "3-Selectionner un groupe" << endl;
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
		afficherListeGroupe();
		goto Menu_Groupe;
	case 3:
		exit(0);
	}

	Menu_Etudiants:
	cout << "1-Ajouter un etudiant" << endl;
	cout << "2-Afficher la liste des etudiants" << endl;
	cout << "3-Supprimer un etudiant" << endl;
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
		creationEtudiant();
		goto Menu_Principale;
	case 2:
		afficherListeEtudiants();
		goto Menu_Principale;
	case 3 :
		supprimerEtudiant();
		goto Menu_Etudiants;
	}
	Menu_Enseignant:
	cout << "1-Ajouter un enseignant" << endl;
	cout << "2-Afficher la liste des tous les enseignants" << endl;
	cout << "3-Supprimer un enseingnat" << endl;
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
		creationEnseignant();
		goto Menu_Principale;
	case 2:
		afficherListeEnseignant();
		goto Menu_Principale;
	case 3:
		cout << "Function not ready yet" << endl;
		goto Menu_Etudiants;
	}
	Menu_GroupeModule:
	cout << "1-Ajouter un groupe module"<<endl;
	cout << "2-Afficher la liste des groupes modules"<<endl;
	cout << "3-Afficher la liste des groupes modules"<<endl;
	do
	{
		cout << "Donner votre choix" << endl;
		cin >> choice;
	} while (choice < 0 || choice>3);
	switch (choice);
	switch (choice)
	{
	case 0 :
		exit(1);
	case 1:
		creationGroupeModule();
		goto Menu_GroupeModule;
	case 2:
		afficherListeGroupeModule();
		goto Menu_GroupeModule;
	case 3:
		cout << "Supprimer Groupe module" << endl;
		goto Menu_GroupeModule;
		

	}




}