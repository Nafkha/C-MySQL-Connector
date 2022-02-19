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
	void createConnexion();
 	static void  ajouterEtudiant(int id, string nom, string prenom, string mail, int num_insc,string idGRP);
	static void ajouterEnseignant(int id, string nom, string prenom, string mail, int cnss);
	static void ajouterMatiere(string idMat, string nomMat,string gm, double coefMat, int cnss, int nbnotes);
	static void ajouterGroupeModule(string idGM, string nomGM, double coefGM,string gp);
	static void ajouterGroupe(string idGRP, string niveau, string diplome, string specialite, int num_g);
	static void ajouterNote(int idEtu, string idMat, double note, string type);
	static sql::ResultSet* fetchGroup();
	static sql::ResultSet* fetchNotes(string idMat);
	static sql::ResultSet* fetchMoyMat(string idMat, int idEtu);
	static sql::ResultSet* fetchMoyGM(int id, string idGM);
	static sql::ResultSet* fetchMatieres(string idGM);
	static sql::ResultSet* fetchMatierById(string idM);
	static sql::ResultSet* fetchMatiereByEns(int cnss);
	static sql::ResultSet* listeEtudiants();
	static sql::ResultSet* listeGroupes();
	static sql::ResultSet* fetchEtudiants(string id);
	static sql::ResultSet* fetchEtudiantById(int id);
	static sql::ResultSet* fetchEnseignant(int cnss);
	static void deleteStudent(int id);
	static sql::ResultSet* listeEnseignants();
	static sql::ResultSet* listeGroupesModules(string idG);
	static sql::ResultSet* listeEtudiantsByGrp(string idGrp);
};

