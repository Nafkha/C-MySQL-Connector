#include "databaseConnection.h"
sql::Connection* con;

void databaseConnection::createConnexion()
{
	sql::Driver* driver;
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
}
void databaseConnection::ajouterEnseignant(int id, string nom, string prenom, string mail, int cnss)
{
	sql::PreparedStatement* pstmt;
	sql::PreparedStatement* eAdd;
	con->setSchema("projetcpp");
	pstmt = con->prepareStatement(("INSERT INTO personne(id,nom,prenom,mail) values(?,?,?,?)"));
	pstmt->setInt(1, id);
	pstmt->setString(2, nom);
	pstmt->setString(3, prenom);
	pstmt->setString(4, mail);
	eAdd = con->prepareStatement("INSERT INTO enseignant(cnss,id) values(?,?)");
	eAdd->setInt(1, cnss);
	eAdd->setInt(2, id);
	try
	{
		pstmt->execute();
		eAdd->execute();
		cout << "L'enseignant " << nom << " " << prenom << " a ete ajoutee a la base" << endl;
	}
	catch (sql::SQLException e)
	{
		cout << "Erreur d'insertion enseignant : " << e.what() << endl;
	}
}

void databaseConnection::ajouterEtudiant(int id, string nom, string prenom, string mail, int num_insc)
{
	sql::PreparedStatement* pstmt;
	sql::PreparedStatement* eAdd;
	con->setSchema("projetcpp");
	pstmt = con->prepareStatement("INSERT INTO personne(id,nom,prenom,mail) values(?,?,?,?) ");
	pstmt->setInt(1, id);
	pstmt->setString(2, nom);
	pstmt->setString(3, prenom);
	pstmt->setString(4, mail);
	eAdd = con->prepareStatement("INSERT INTO etudiant(num_insc,id) values(?,?)");
	eAdd->setInt(1, num_insc);
	eAdd->setInt(2, id);


	try
	{
		pstmt->execute();

		eAdd->execute();
		cout << "l'etudiant : " << nom << " " << prenom << " a ete ajoute avec succes" << endl;
		
	}
	catch (sql::SQLException e)
	{
		cout << "Erreur dans l'insertion : " << e.what() << endl;
	}

	delete pstmt;
	delete eAdd;
	

}




