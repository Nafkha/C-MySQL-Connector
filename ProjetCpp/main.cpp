#include<iostream>
#include <stdlib.h>
#include "Personne.h"
#include "Etudiant.h"
#include "Enseignant.h"
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
	//db.ajouterEtudiant();
	Etudiant e(4, "Khra", "Ben Khra", "khra@benkhra.com", 4);
	//Enseignant e1(2, "Bennour", "Mohamed", "bennourmohamed@pi.tn",1919);

}