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
		: server("localhost:3306"),
		  username("root"),
		  password("admin")
	{
	}
 	static void  ajouterEtudiant(int id, string nom, string prenom, string mail, int num_insc);
	static void ajouterEnseignant(int id, string nom, string prenom, string mail, int cnss);
	void createConnexion();
	static void afficher()
	{
		cout << "Hello World !!!!!!";
	}
};

