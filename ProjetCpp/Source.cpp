#include "Header.h"

vector<Groupe> listeGrp();
void afficher()
{
	cout << "Hello World !!!" << endl;
}
void creationEtudiant()
{
	int id, num_insc;
	string nom, prenom, mail;
	cout << "ID : ";
	cin >> id;
	cout << "Nom : ";
	cin.ignore();
	getline(cin, nom);
	cout << "Prenom : ";
	getline(cin, prenom);
	cout << "Mail : ";
	cin >> mail;
	cout << "Numero d'inscription : ";
	cin >> num_insc;
	Etudiant e(id, nom, prenom, mail, num_insc, true);
}
void afficherListeEtudiants()
{
	int colwidth = 20;
	sql::ResultSet* rs = databaseConnection::listeEtudiants();
	//cout << "ID" << setw(5) << "Nom" << setw(10) << "Prenom" << setw(5) << endl;
	cout << setw(colwidth) << "ID" << setw(colwidth) << "Nom" << setw(colwidth) << "Prenom" << setw(colwidth) << endl;
	while (rs->next())
	{
		cout <<setprecision(0) <<setw(colwidth) << rs->getInt("id")<<setprecision(4) << setw(colwidth) << rs->getString("nom") <<setprecision(4) << setw(colwidth) << rs->getString("prenom") << endl;
	}
}
void supprimerEtudiant()
{
	int idEtu;
	cout << "Donner l'id d'etudiant " << endl;
	cin >> idEtu;
	databaseConnection::deleteStudent(idEtu);
}
void creationGroupe()
{
	string id, niveau, diplome, specialite;
	int num_g;
	cout << "ID :";
	cin.ignore();
	getline(cin, id);
	cout << "Niveau :";
	getline(cin, niveau);
	cout << "Diplome :";
	getline(cin, diplome);
	cout << "Specialite :";
	getline(cin, specialite);
	cout << "Numero groupe :";
	cin >> num_g;
	Groupe g(id, niveau, diplome, specialite, num_g);
}
void afficherListeGroupe()
{
	sql::ResultSet* rs;
	rs = databaseConnection::listeGroupes();
	int colwidth = 20;
	cout << setw(colwidth) << "ID" << setw(colwidth) << "Niveau" << setw(colwidth) << "Diplome" << setw(colwidth) <<"Specialite" <<setw(colwidth) << "Numero" << endl;
	while (rs->next())
	{
		cout << setprecision(0) << setw(colwidth) << rs->getString("idGrp") << setprecision(4) << setw(colwidth)
		<< rs->getString("niveau") << setprecision(4) << setw(colwidth)
		<< rs->getString("diplome")<<setprecision(4)<<setw(colwidth)<<rs->getString("specialite")<<setprecision(4)<<
			setw(colwidth)<<rs->getInt("num_g") << endl;
	}
}
void creationEnseignant()
{
	int id, cnss;
	string nom, prenom, mail;
	cout << "ID : ";
	cin >> id;
	cout << "Nom : ";
	cin.ignore();
	getline(cin, nom);
	cout << "Prenom : ";
	getline(cin, prenom);
	cout << "Mail : ";
	cin >> mail;
	cout << "CNSS : ";
	cin >> cnss;
	Enseignant e(id, nom, prenom, mail, cnss, true);

}
void afficherListeEnseignant()
{
	int colwidth = 20;
	sql::ResultSet* rs = databaseConnection::listeEnseignants();
	cout << setw(colwidth) << "ID" << setw(colwidth) << "Nom" << setw(colwidth) << "Prenom" << setw(colwidth) << endl;
	while (rs->next())
	{
		cout << setprecision(0) << setw(colwidth) << rs->getInt("id") << setprecision(4) << setw(colwidth) << rs->getString("nom") << setprecision(4) << setw(colwidth) << rs->getString("prenom") << endl;
	}
}
void creationGroupeModule()
{
	string id, nom;
	double coef;
	cout << "ID : ";
	cin.ignore();
	getline(cin, id);
	cout << "Nom Groupe module : ";
	getline(cin, nom);
	cout << "ID : ";
	cin >> coef;
	GroupeModule gm(id, nom, coef);
}
void afficherListeGroupeModule()
{
	int colwidth = 20;
	sql::ResultSet* rs = databaseConnection::listeGroupesModules();
	cout << setw(colwidth) << "ID" << setw(colwidth) << "Nom" << setw(colwidth) << "Coef" << setw(colwidth) << endl;
	while(rs->next())
	{
		cout << setprecision(0) << setw(colwidth) << rs->getString("idGM")
			<< setprecision(4) << setw(colwidth) << rs->getString("nomGM")
			<< setprecision(4) <<setw(colwidth) << rs->getDouble("coefGM") << endl;
	}
}