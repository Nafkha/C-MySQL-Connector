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
void databaseConnection::ajouterEtudiant(int id, string nom, string prenom, string mail, int num_insc,string idGRP)
{
	sql::PreparedStatement* pstmt;
	sql::PreparedStatement* eAdd;
	con->setSchema("projetcpp");
	pstmt = con->prepareStatement("INSERT INTO personne(id,nom,prenom,mail) values(?,?,?,?) ");
	pstmt->setInt(1, id);
	pstmt->setString(2, nom);
	pstmt->setString(3, prenom);
	pstmt->setString(4, mail);
	eAdd = con->prepareStatement("INSERT INTO etudiant(num_insc,id,grp) values(?,?,?)");
	eAdd->setInt(1, num_insc);
	eAdd->setInt(2, id);
	eAdd->setString(3, idGRP);


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
void databaseConnection::ajouterMatiere(string idMat, string nomMat,string gm, double coefMat, int cnss,int nbnotes)
{
	sql::PreparedStatement* pstmt;
	
	con->setSchema("projetcpp");
	pstmt = con->prepareStatement("INSERT INTO matiere(idMat,nomMat,coef,ens,gm,nbnotes) values(?,?,?,?,?,?)");
	pstmt->setString(1, idMat);
	pstmt->setString(2, nomMat);
	pstmt->setDouble(3, coefMat);
	pstmt->setInt(4, cnss);
	pstmt->setString(5, gm);
	pstmt->setInt(6, nbnotes);
	try
	{
		pstmt->execute();
		cout << "Matiere ajoutee" << endl;
	}
	catch (sql::SQLException e)
	{
		cout << "Erreur : " << e.what() << endl;
	}
	delete pstmt;

}
void databaseConnection::ajouterGroupeModule(string idGM, string nomGM, double coefGM,string gp)
{
	sql::PreparedStatement* pstmt;
	con->setSchema("projetcpp");

	pstmt = con->prepareStatement("INSERT INTO groupeModule(idGM,nomGM,coefGM,grp) values(?,?,?,?)");
	pstmt->setString(1, idGM);
	pstmt->setString(2, nomGM);
	pstmt->setDouble(3, coefGM);
	pstmt->setString(4, gp);
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
sql::ResultSet* databaseConnection::fetchEtudiants(string id)
{
	sql::ResultSet* rs;
	sql::PreparedStatement* pstmt;
	con->setSchema("projetcpp");
	pstmt = con->prepareStatement("SELECT personne.id,num_insc,nom,prenom,grp,mail FROM ETUDIANT  JOIN PERSONNE ON (PERSONNE.id = ETUDIANT.id) having(grp=?)");
	pstmt->setString(1, id);
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
sql::ResultSet* databaseConnection::fetchEtudiantById(int id)
{
	sql::ResultSet* rs;
	sql::PreparedStatement* pstmt;
	con->setSchema("projetcpp");
	pstmt = con->prepareStatement(" SELECT p.id,e.num_insc,nom,prenom,mail from etudiant e join personne p on (p.id = e.id) having(num_insc=?)");
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
sql::ResultSet* databaseConnection::fetchEnseignant(int cnss)
{
	sql::ResultSet* rs;
	sql::PreparedStatement* pstmt;
	con->setSchema("projetcpp");
	pstmt = con->prepareStatement(" SELECT p.id,e.cnss,nom,prenom,mail from Enseignant e join personne p on (p.id = e.id) having(cnss=?)");
	pstmt->setInt(1, cnss);
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
sql::ResultSet* databaseConnection::listeGroupesModules(string idG)
{
	sql::PreparedStatement* pstmt;
	con->setSchema("projetcpp");
	pstmt = con->prepareStatement("SELECT * FROM GROUPEMODULE WHERE (grp=?)");
	pstmt->setString(1, idG);
	try
	{
		sql::ResultSet*rs = pstmt->executeQuery();
		return rs;

	}
	catch (sql::SQLException e)
	{
		cout << "Erreur : " << e.what() << endl;
	}

	delete pstmt;
 }
sql::ResultSet* databaseConnection::fetchMatieres(string idGM)
{
	sql::PreparedStatement* pstmt;
	con->setSchema("projetcpp");
	pstmt = con->prepareStatement("SELECT * FROM MATIERE WHERE (gm=?)");
	pstmt->setString(1, idGM);
	try
	{
		sql::ResultSet* rs = pstmt->executeQuery();
		return rs;
	}catch (sql::SQLException e)
	{
		cout << "Erreur " << e.what() << endl;
	}

}
sql::ResultSet* databaseConnection::fetchMatierById(string idM)
{
	con->setSchema("projetcpp");
	sql::PreparedStatement* pstmt;
	sql::ResultSet* rs;
	pstmt = con->prepareStatement("SELECT * FROM matiere where idMat = ? ");
	pstmt->setString(1, idM);
	try
	{
		rs = pstmt->executeQuery();
		return rs;
	}
	catch (sql::SQLException e)
	{
		cout << "Error : " << e.what() << endl;
	}
	
}
sql::ResultSet* databaseConnection::fetchMoyMat(string idMat, int idEtu)
{
	sql::PreparedStatement* pstmt;
	sql::ResultSet* rs;
	con->setSchema("projetcpp");
	pstmt = con->prepareStatement("SELECT round(avg(Note),2) from note where(Mat=? and Etu = ?) ");
	pstmt->setString(1, idMat);
	pstmt->setInt(2, idEtu);
	try
	{
		rs = pstmt->executeQuery();
		return rs;

	}
	catch (sql::SQLException e)
	{
		cout << "Error : " << e.what()<<endl;
	}
	
}
sql::ResultSet* databaseConnection::listeEtudiantsByGrp(string idGrp)
{
	sql::PreparedStatement* pstmt;
	sql::ResultSet* rs;
	con->setSchema("projetcpp");
	pstmt = con->prepareStatement("SELECT e.num_insc,p.nom,p.prenom from personne p join etudiant e on p.Id=e.id where(e.grp=?)");
	pstmt->setString(1, idGrp);
	try
	{
		rs = pstmt->executeQuery();
		return  rs;
		
	}
	catch (sql::SQLException e)
	{
		cout << "Erreur : " << e.what();
	}
}
sql::ResultSet* databaseConnection::fetchMatiereByEns(int cnss)
{
	sql::PreparedStatement* pstmt;
	sql::ResultSet* rs;
	con->setSchema("projetcpp");
	pstmt = con->prepareStatement("SELECT nomMat,coef from matiere m join enseignant e on(m.ens=e.cnss) where(e.cnss=?) ");
	pstmt->setInt(1,cnss);
	try
	{
		rs = pstmt->executeQuery();
		return rs;
	}
	catch (sql::SQLException e)
	{
		cout << "Erreur : " << e.what() << endl;
	}
}














