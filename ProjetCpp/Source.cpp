#include "Header.h"

vector<Groupe> listeGrp();

void creationEtudiant()
{
	int id, num_insc;
	string nom, prenom, mail,idGRP;
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
	cout << "GROUPE :";
	cin >> idGRP;
	cout << "aaaa" << endl;
	Etudiant e(id, nom, prenom, mail, num_insc,idGRP, true);
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
	string id, nom,gp;
	double coef;
	cout << "ID : ";
	cin.ignore();
	getline(cin, id);
	cout << "Nom Groupe module : ";
	getline(cin, nom);
	cout << "Donner la coeffecient : ";
	cin >> coef;
	cout << "Donner le groupe : " << endl;
	cin.ignore();

	getline(cin, gp);
	GroupeModule gm(id, nom, coef,gp);
}
void creationMatiere()
{
	int ens;
	string id, nom,gm;
	double coef;
	int nb_notes;
	cout << "Donner l'ID de matiere : ";
	cin.ignore();
	getline(cin, id);
	cout << "Donner le nom de la matiere : ";
	getline(cin, nom);
	cout << "Donner le groupe module de la matiere : ";
	getline(cin, gm);
	cout << "Donner la coeffecience : ";
	cin >> coef;
	cout << "Donner l'ID de l'enseignant : ";
	cin >> ens;
	sql::ResultSet* rs = databaseConnection::fetchEnseignant(ens);
	while (rs->next())
	{
		Enseignant e(rs->getInt("id"), rs->getString("nom"), rs->getString("prenom"), rs->getString("mail"), rs->getInt("cnss"), false);
		do {
			cout << "Donner le nombre de notes : ";
			cin >> nb_notes;
		} while (nb_notes < 1 || nb_notes>3);
		Matiere m(id, nom, gm, coef, e, nb_notes, true);

	}
	
}

void remplirGroupe()
{
	sql::ResultSet* rs;
	rs = databaseConnection::listeGroupes();
	vector<Groupe> listeGrp;
	while(rs->next())
	{
		Groupe gp;
		gp.set_id_grp(rs->getString("idGrp"));
		gp.set_niveau(rs->getString("niveau"));
		gp.set_diplome(rs->getString("diplome"));
		gp.set_specialite(rs->getString("specialite"));
		gp.set_num_g(rs->getInt("num_g"));
		listeGrp.push_back(gp);
	}
	for(int i=0;i<listeGrp.size();i++)
	{
		sql::ResultSet* letu = databaseConnection::fetchEtudiants(listeGrp.at(i).get_id_grp());
		while(letu->next())
		{
			Etudiant e(letu->getInt("id"), letu->getString("nom"), letu->getString("prenom"), letu->getString("mail"), letu->getInt("num_insc"),letu->getString("grp"), false);
			listeGrp.at(i).addEtu(e);
		}
	}
	for(int i=0;i<listeGrp.size();i++)
	{
		sql::ResultSet* lGM = databaseConnection::listeGroupesModules(listeGrp.at(i).get_id_grp());
		while(lGM->next())
		{
			GroupeModule gm;
			gm.set_id_gm(lGM->getString("idGM"));
			gm.set_nom_gm(lGM->getString("nomGM"));
			gm.set_coef_gm(lGM->getDouble("coefGM"));
			listeGrp.at(i).addGM(gm);
			
		}
		
	}
	/*---- TEST AFFICHAGE ----*/
	for (int i = 0;i<listeGrp.size();i++)
	{
		listeGrp.at(i).testAfficherEtudiants();
	}
	cout << "Modules : " << endl;
	for(int i=0;i<listeGrp.size();i++)
	{
		for(int j=0;j<listeGrp.at(i).get_groupe_module().size();j++)
		{
			remplirGroupeModule(listeGrp.at(i).get_groupe_module().at(j));
			cout << listeGrp.at(i).get_groupe_module().at(j).get_nom_gm() << endl;
		}

	}
}
void remplirGroupeModule(GroupeModule gm)
{
	sql::ResultSet* rs = databaseConnection::fetchMatieres(gm.get_id_gm());
	while(rs->next())
	{
		sql::ResultSet* lEn = databaseConnection::fetchEnseignant(rs->getInt("ens"));
		while (lEn->next()) {
			Enseignant e(lEn->getInt("id"), lEn->getString("nom"), lEn->getString("prenom"), lEn->getString("mail"), lEn->getInt("cnss"), false);


			Matiere m(rs->getString("idMat"), rs->getString("nomMat"),rs->getString("gm"), rs->getDouble("coef"), e, rs->getInt("nbnotes"), false);
			gm.ajouterMatiere(m);
		}
	}
}
void addNote()
{
	int idEtu;
	string idMat, type;
	double note;
	sql::ResultSet* etu;
	cout << "Donner l'ID de l'etudiant : ";
	cin >> idEtu;
	etu = databaseConnection::fetchEtudiantById(idEtu);
	while(etu->next())
	{
		Etudiant e(etu->getInt("id"), etu->getString("nom"), etu->getString("prenom"), etu->getString("mail"), etu->getInt("num_insc"));
		cout << "Donner l'ID de la matiere : ";
		cin.ignore();
		getline(cin, idMat);
		sql::ResultSet* mat = databaseConnection::fetchMatierById(idMat);
		while(mat->next())
		{
			int x = mat->getInt("nbnotes");
			switch (x)
			{
			case 1:
				do
				{
					cout << "Donner la note d'examen :";
					cin >> note;
				} while (note < 0 || note>20);
				databaseConnection::ajouterNote(e.get_num_insc(), mat->getString("idMat"), note, "Examen");
				break;
			case 2:
				do
				{
					cout << "Donner la note de ds :";
					cin >>note;
				} while (note < 0 || note>20);
				databaseConnection::ajouterNote(e.get_num_insc(), mat->getString("idMat"), note, "DS");
				do
				{
					cout << "Donner la note d'examen :";
					cin >>note;
				} while (note < 0 || note>20);
				databaseConnection::ajouterNote(e.get_num_insc(), mat->getString("idMat"), note, "Examen");
				break;
				case 3:
				do
				{
					cout << "Donner la note de ds :";
					cin >>note;
				} while (note < 0 || note>20);
				databaseConnection::ajouterNote(e.get_num_insc(), mat->getString("idMat"), note, "DS");		do
				{
					cout << "Donner la note de TP :";
					cin >>note;
				} while (note < 0 || note>20);
				databaseConnection::ajouterNote(e.get_num_insc(), mat->getString("idMat"), note, "TP");
				do
				{
					cout << "Donner la note d'examen :";
					cin >>note;
				} while (note < 0 || note>20);
				databaseConnection::ajouterNote(e.get_num_insc(), mat->getString("idMat"), note, "Examen");
				break;

			}
		}
	}


		
	
	
}