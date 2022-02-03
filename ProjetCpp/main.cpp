#include<iostream>
#include <stdlib.h>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include "Personne.h"
using namespace std;

const string server = "localhost:3306";
const string username = "root";
const string password = "admin";
//sql::Connection* con;


int main()
{
	//cout << P.get_id() << " " << P.get_nom() << endl;
	int id;
	string nom, prenom, mail;
	cout << "Donner ID : " << endl;
	cin >> id;
	cout << "Donner le nom : " << endl;
	cin >> nom;
	cout << "Donner le prenom : " << endl;
	cin >> prenom;
	cout << "Donner l'email : " << endl;
	cin >> mail;
	Personne P(id, nom, prenom, mail);
	sql::Driver* driver;
	cout << "Hello World " << endl;
	sql::Connection* con;


	try
	{
		driver = get_driver_instance();
		con = driver->connect(server, username, password);
		cout << "Serveur BD : " << server << " Connected as " << username << endl;
	}
	catch (sql::SQLException e)
	{
		cout << "Erreur : " << e.what() << endl;
		system("pause");
		exit(1);
	}
	con->setSchema("testdb");
	sql::PreparedStatement* pstmt;
	sql::Statement* stmt;
	stmt = con->createStatement();


	try {
		stmt->execute("CREATE TABLE personne( id int, nom varchar(50), prenom varchar(50), email varchar(50));");
		cout << "Table Cree avec success" << endl;
	}catch (sql::SQLException e)
	{
		cout << "Erreur de creation de table : "<< e.what() << endl;
	}
	delete stmt;
	try
	{
		pstmt = con->prepareStatement("INSERT INTO personne(id,nom,prenom,email) VALUES(?,?,?,?)");
		pstmt->setInt(1, P.get_id());
		pstmt->setString(2, P.get_nom());
		pstmt->setString(3, P.get_prenom());
		pstmt->setString(4, P.get_mail());
		pstmt->execute();
		cout << "Personne inserted" << endl;

	}
	catch (sql::SQLException e)
	{
		cout << "Erreur d'insertion : " << e.what() << endl;
	}

	return 0;
}