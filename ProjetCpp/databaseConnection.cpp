#include "databaseConnection.h"
sql::Connection* con;

void databaseConnection::createConnexion()
{
	sql::Driver* driver;
	try
	{
		driver = get_driver_instance();
		con = driver->connect(server, username, password);
		//cout << "Serveur BD : " << server << " Connected as " << username << endl;
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
void databaseConnection::ajouterMatiere(string idMat, string nomMat, double coefMat, int cnss,int nbnotes)
{
	sql::PreparedStatement* pstmt;
	
	con->setSchema("projetcpp");
	pstmt = con->prepareStatement("INSERT INTO matiere(idMat,nomMat,coef,ens,nbnotes) values(?,?,?,?,?)");
	pstmt->setString(1, idMat);
	pstmt->setString(2, nomMat);
	pstmt->setDouble(3, coefMat);
	pstmt->setInt(4, cnss);
	pstmt->setInt(5, nbnotes);
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
	con->setSchema("projetcpp");

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
	con->setSchema("projetcpp");
	pstmt = con->prepareStatement("INSERT INTO groupe (idGrp,niveau,diplome,specialite,num_g) values(?,?,?,?,?)");
	pstmt->setString(1, idGRP);
	pstmt->setString(2, niveau);
	pstmt->setString(3, diplome);
	pstmt->setString(4, specialite);
	pstmt->setInt(5,num_g);
	cout << "Hello" << endl;
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
sql::ResultSet* databaseConnection::fetchGroup()
{
	sql::ResultSet* rs;
	sql::PreparedStatement *pstmt;
	con->setSchema("projetcpp");
	pstmt = con->prepareStatement("SELECT * FROM groupe where idGrp = ?");
	pstmt->setString(1, "IRM");
	try{
		rs = pstmt->executeQuery();
	cout << "SUCCESS"<<endl;
	}catch (sql::SQLException e)
	{
		cout << "Erreur : " << e.what() << endl;
		exit(1);
	}
	delete pstmt;
	return rs;

}
sql::ResultSet* databaseConnection::fetchNotes(string idMat)
{
	sql::ResultSet* rs;
	sql::PreparedStatement* pstmt;
	con->setSchema("projetcpp");
	pstmt = con->prepareStatement("SELECT * FROM NOTE WHERE mat=?");
	pstmt->setString(1, idMat);
	try
	{
		rs = pstmt->executeQuery();
	}
	catch (sql::SQLException e)
	{
		cout << "Erreur : " << e.what() << endl;
		exit(1);
	}
	delete pstmt;
	return rs;

}
sql::ResultSet* databaseConnection::fetchEtudiants(int id)
{
	sql::ResultSet* rs;
	sql::PreparedStatement* pstmt;
	con->setSchema("projetcpp");
	pstmt = con->prepareStatement("SELECT * FROM ETUDIANT INNER JOIN PERSONNE ON (PERSONNE.id = ETUDIANT.id && PERSONNE.id = ?)");
	pstmt->setInt(1, id);
	try
	{
		rs = pstmt->executeQuery();
	}
	catch (sql::SQLException e)
	{
		cout << "Erreur :  " << e.what() << endl;
		exit(1);
	}
}
sql::ResultSet* databaseConnection::listeEtudiants()
{
	sql::ResultSet* rs;
	sql::PreparedStatement* pstmt;
	sql::Statement* stmt;

	con->setSchema("projetcpp");
	stmt = con->createStatement();
	try
	{
		rs = stmt->executeQuery("SELECT * FROM ETUDIANT INNER JOIN PERSONNE ON (PERSONNE.id = ETUDIANT.id)");
		return rs;
	}
	catch (sql::SQLException e)
	{
		cout << "Erreur :  " << e.what() << endl;
		exit(1);
	}
}
sql::ResultSet* databaseConnection::listeEnseignants()
{
	sql::ResultSet* rs;
	sql::PreparedStatement* pstmt;
	sql::Statement* stmt;

	con->setSchema("projetcpp");
	stmt = con->createStatement();
	try
	{
		rs = stmt->executeQuery("SELECT * FROM ENSEIGNANT INNER JOIN PERSONNE ON (PERSONNE.id = ENSEIGNANT.id)");
		return rs;
	}
	catch (sql::SQLException e)
	{
		cout << "Erreur :  " << e.what() << endl;
		exit(1);
	}
}
sql::ResultSet* databaseConnection::listeGroupes()
{
	sql::ResultSet* rs;
	sql::PreparedStatement* pstmt;
	sql::Statement* stmt;

	con->setSchema("projetcpp");
	stmt = con->createStatement();
	try
	{
		rs = stmt->executeQuery("SELECT * FROM GROUPE");
		return rs;
	}
	catch (sql::SQLException e)
	{
		cout << "Erreur :  " << e.what() << endl;
		exit(1);
	}
}
void databaseConnection::ajouterNote(int idEtu, string idMat, double note, string type)
{
	cout << "Ajout de note" << endl;
	sql::PreparedStatement* pstmt;
	con->setSchema("projetcpp");
	pstmt = con->prepareStatement("INSERT INTO NOTE(Mat,Etu,Note,Type) values(?,?,?,?)");
	pstmt->setInt(2, idEtu);
	pstmt->setString(1, idMat);
	pstmt->setDouble(3, note);
	pstmt->setString(4, type);
	try
	{
		pstmt->execute();
		cout << "Note ajoutée" << endl;
		
	}
	catch (sql::SQLException e)
	{
		cout << "Erreur :  " << e.what() << endl;
	}
	delete pstmt;



}
void databaseConnection::deleteStudent(int id)
{
	sql::PreparedStatement* pstmt;
	con->setSchema("projetcpp");
	pstmt = con->prepareStatement("Delete from personne where id=?");
	pstmt->setInt(1, id);
	try
	{
		pstmt->execute();
	}
	catch (sql::SQLException e)
	{
		cout << "Erreur de supression : " << e.what() << endl;
	}
	delete pstmt;
	
}
sql::ResultSet* databaseConnection::listeGroupesModules()
{
	sql::Statement* stmt;
	con->setSchema("projetcpp");
	stmt = con->createStatement();
	try
	{
		sql::ResultSet*rs = stmt->executeQuery("SELECT * FROM GROUPEMODULE;");
		return rs;

	}
	catch (sql::SQLException e)
	{
		cout << "Erreur : " << e.what() << endl;
	}

	cout << "aaa" << endl;
	delete stmt;
}












