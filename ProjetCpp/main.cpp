#include<iostream>
#include <stdlib.h>
#include "Etudiant.h"
#include "Enseignant.h"
#include "Matiere.h"
#include "GroupeModule.h"
using namespace std;

const string server = "localhost:3306";
const string username = "root";
const string password = "admin";
//sql::Connection* con;
#include "databaseConnection.h";


int main()
{
	databaseConnection::afficher();
	databaseConnection db(server, username, password);
	db.createConnexion();
	Enseignant en(1, "Mohamed Youssef", "Nafkha", "m.nafkha@pi.tn", 1919);
	Matiere m1("math101", "Math", 3, en);
	GroupeModule g1("fonda", "maths", 3);
	g1.ajouterMatiereGM(m1);

}