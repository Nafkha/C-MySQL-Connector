#pragma once
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <string>


using namespace std;
 class databaseConnection
{
private:
	string server;
	string username;
	string password;
public:

	databaseConnection(string server, string username, string password)
		: server(server),
		  username(username),
		  password(password)
	{
	}
 	static void  ajouterEtudiant(int id, string nom, string prenom, string mail, int num_insc);
	static void ajouterEnseignant(int id, string nom, string prenom, string mail, int cnss);
	static void ajouterMatiere(string idMat, string nomMat, double coefMat, int cnss, int nbnotes);
	static void setGM(string idGM,string idM);
	static void ajouterGroupeModule(string idGM, string nomGM, double coefGM);
	static void ajouterGroupe(string idGRP, string niveau, string diplome, string specialite, int num_g);
	static void ajouterNote(int idEtu, string idMat, double note, string type);
	static sql::ResultSet* fetchGroup();
	static sql::ResultSet* fetchNotes(string idMat);

	static sql::ResultSet* fetchEtudiants(int id);
	void createConnexion();
};

