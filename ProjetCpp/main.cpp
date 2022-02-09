#include<iostream>
#include <stdlib.h>
#include "Etudiant.h"
#include "Enseignant.h"
#include "Matiere.h"
#include "GroupeModule.h"
#include "Groupe.h"
#include "Note.h"
#include "a.h"
using namespace std;

const string server = "localhost:3306";
const string username = "root";
const string password = "admin";
//sql::Connection* con;
#include "databaseConnection.h";


int main()
{
	databaseConnection db(server, username, password);
	db.createConnexion();
	/*---------------- Debut  de programme ----------------*/
/*	cout << "---------- Bonjour ----------" << endl;
	int x;
	cout << "Choisissez " << endl;
	do
	{
		cout << "1-Gestion de groupe " << endl;
		cout << "2-Gestion des etudiants " << endl;
		cout << "3-Gestion des enseignants " << endl;
		cout << "4-Gestion des matieres" << endl;
		cout << "5-gestion des modules" << endl;
		cout << "0-quitter le programme" << endl;
		cin >> x;

		
	} while (x<0 || x>5);
	switch (x)
	{
	case 1 :
		cout << "Groupe";
		break;
	case 2 :
		cout << "Etudiants";
		break;
	case 3 :
		break;
	case 4 :
		break;
	case 5 :
		break;
	case 0 :
		exit(1);
		
	}
	*/
	//Groupe::fetchgroup();
	Etudiant e(0, "Nafkha", "Youssef", "nafkha.m.youssef@gmail.com", 0,true);
	Enseignant en(1, "AAA", "BBBB", "aaa@bbb.com", 1);
	cout << "Ajout de matiere" << endl;
	Matiere m("m", "math", 3, en, 3);
	cout << "Ajoute de groupe module" << endl;
	GroupeModule gm("g", "m", 3);
	gm.ajouterMatiereGM(m);
	cout << "Ajotu de note" << endl;
	Note nt1(e, m, 15, "DS",true);
	cout << "Ajotu de note" << endl;

	Note nt2(e, m, 16, "TP",true);
	cout << "Ajotu de note" << endl;

	Note nt3(e, m, 17, "Exam",true);
	Groupe gp("irm", "1ere", "ing", "inf", 3);
	Groupe gp1;
	gp.fetchgroup();
	gm.getNotes();
	//gm.getNotes();
	//gm.getNotes();
	//nt1.getN();
	//gm.getNotes();
	//vector<Note> listeNote = gm.get_liste_notes();
	/*for (int i = 0;i<listeNote.size();i++)
	{
		cout << listeNote.at(i).get_note() << " " << listeNote.at(i).get_type() << endl;
	}*/


}