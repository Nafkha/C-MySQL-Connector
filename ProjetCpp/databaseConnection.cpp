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
void databaseConnection::ajouterMatiere(string idMat, string nomMat, double coefMat, int cnss)
{
	sql::PreparedStatement* pstmt;
	
	con->setSchema("projetcpp");
	pstmt = con->prepareStatement("INSERT INTO matiere(idMat,nomMat,coef,ens) values(?,?,?,?)");
	pstmt->setString(1, idMat);
	pstmt->setString(2, nomMat);
	pstmt->setDouble(3, coefMat);
	pstmt->setInt(4, cnss);
	try
	{
		pstmt->execute();
		cout << "Une nouvelle matiere ajoutee" << endl;
	}
	catch (sql::SQLException e)
	{
		cout << "Erreur : " << e.what() << endl;
	}
	delete pstmt;

}
void databaseConnection::setGM(string idGM, string idM)
{
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("UPDATE Matiere set gm=? where idMat = ?");
	pstmt->setString(1, idGM);
	pstmt->setString(2, idM);
	try
	{
		pstmt->execute();
		cout << "Matiere ajoutee au groupe avec success" << endl;
	}
	catch (sql::SQLException e)
	{
		cout << "Erreur d'execution" << endl;
	}
	delete pstmt;
}
void databaseConnection::ajouterGroupeModule(string idGM, string nomGM, double coefGM)
{
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("INSERT INTO groupeModule(idGM,nomGM,coefGM) values(?,?,?)");
	pstmt->setString(1, idGM);
	pstmt->setString(2, nomGM);
	pstmt->setDouble(3, coefGM);
	try
	{
		pstmt->execute();
		cout << "Groupe module ajoutee aveec succes" << endl;
	}
	catch (sql::SQLException e)
	{
		cout << "Erreur  : " << e.what() << endl;
	}
	delete pstmt;
}
void databaseConnection::ajouterGroupe(string idGRP, string niveau, string diplome, string specialite, int num_g)
{
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("INSERT INTO groupe (idGrp,niveau,diplome,specialite,num_g) values(?,?,?,?,?)");
	pstmt->setString(1, idGRP);
	pstmt->setString(2, niveau);
	pstmt->setString(3, diplome);
	pstmt->setString(4, specialite);
	pstmt->setInt(5,num_g);
	try
	{
		pstmt->execute();
		cout << "Groupe ajoutee" << endl;
		
	}
	catch (sql::SQLException e)
	{
		cout << "Erreur d'insertion dans la table GROUPE  : " << e.what() << endl;
	}
	delete pstmt;
}







