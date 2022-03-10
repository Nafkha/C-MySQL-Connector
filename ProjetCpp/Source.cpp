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
	Etudiant e(id, nom, prenom, mail, num_insc,idGRP, true);
}
void afficherListeEtudiants()
{
	int colwidth = 30;
	sql::ResultSet* rs = databaseConnection::listeEtudiants();
	//cout << "ID" << setw(5) << "Nom" << setw(10) << "Prenom" << setw(5) << endl;
	cout <<setw(9)<<left << "NUM_INSC" << '|' << setw(colwidth) << "Nom" << '|' << setw(colwidth) << "Prenom" <<'|'<<setw(colwidth)<<"Email" << endl;
	while (rs->next())
	{
		//cout << rs->getString("idGRP")<<endl;
		Etudiant e(rs->getInt("id"), rs->getString("nom"), rs->getString("prenom"), rs->getString("mail"), rs->getInt("num_insc"), rs->getString("grp"), false);
		//cout <<setw(7)<<left << rs->getInt("id") << '|' << setw(colwidth) << rs->getString("nom") << '|' << setw(colwidth) << rs->getString("prenom")  << endl;
		cout << e;
	}	
}
void modifierEtudiant()
{
	int numInsc;
	string grp;
	cout << "Donner le numero d'inscription " << endl;
	cin >> numInsc;
	cout << "Donner le nouveau groupe " << endl;
	cin >> grp;
	databaseConnection::updateStudent(numInsc,grp);
}
void supprimerGroupeModule()
{
	string idGM;
	cout << "Donner l'id de groupe module a supprimer" << endl;
	cin >> idGM;
	databaseConnection::deleteGroupeModule(idGM);
}
void supprimerMatiere()
{
	string idMat;
	cout << "Donner l'id de matiere a supprimer" << endl;
	cin >> idMat;
	databaseConnection::deleteMatiere(idMat);
}
void supprimerGroupe()
{
	char c;
	do
	{
		cout << "Est-ce-que vous avez met a jour les groupes des etudiants ? (O/N) : ";
		cin >> c;
	}
	while (c!='O' && c!='o' && c!='N' && c!='n');
	if(c=='O' || c=='o'){
	string idGRP;
	cout << "Donner l'id de groupe a supprimer : ";
	cin >> idGRP;
	databaseConnection::deleteGroupe(idGRP);
	}
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
void  afficherListeGroupeModule()
{
	sql::ResultSet* rs;
	rs = databaseConnection::listeGM();
	int colwidth = 20;
	cout << setw(colwidth)<<internal<< "ID Groupe Module " << setw(45) << internal << "Groupe Module" << setw(colwidth) << internal << "Coeffecient"  << endl;
	while(rs->next())
	{
		cout << setw(colwidth)<<left << rs->getString("idGM") << setw(45) << internal << rs->getString("nomGM") << setprecision(2) << setw(colwidth) << internal << rs->getString("coefGM") << endl;
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
	cout << "Donner le groupe : ";
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
	cout << "Donner la coeffecient : ";
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
void modifierMatiere()
{
	string idMat;
	double newCef;
	cout << "Donner l'id de matiere : ";
	cin >> idMat;
	cout << "Donner la nouveau coeffecient : ";
	cin >> newCef;
	databaseConnection::updateMatiere(idMat, newCef);
	
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

			sql::ResultSet* gr = databaseConnection::fetchMatieres(gm.get_id_gm());
			while (gr->next())
			{
				sql::ResultSet* lEn = databaseConnection::fetchEnseignant(gr->getInt("ens"));
				while (lEn->next()) {
					Enseignant e(lEn->getInt("id"), lEn->getString("nom"), lEn->getString("prenom"), lEn->getString("mail"), lEn->getInt("cnss"), false);


					Matiere m(gr->getString("idMat"), gr->getString("nomMat"), gr->getString("gm"), gr->getDouble("coef"), e, gr->getInt("nbnotes"), false);
					gm.ajouterMatiere(m);
				}
			}

			listeGrp.at(i).addGM(gm);
			
		}
		
	}

	/*---- TEST AFFICHAGE ----*/
	for (int i = 0;i<listeGrp.size();i++)
	{
		afficherGroupe(listeGrp.at(i));
		cout << endl;
	}
	cout << endl;
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
string testAdmission(double moy)
{
	if(moy>=10)
	{
		return "Admis";
	}else
	{
		return "Ajournee";
	}
}
string testMention(double moy)
{
	if(moy<10)
	{
		return "";
	}
	if(moy>=10 && moy<12)
	{
		return "Passable";
	}
	if(moy>=12 && moy<14)
	{
		return "Assez Bien";
	}if(moy>=14 && moy<16)
	{
		return "Bien";
	}if(moy>=16 && moy<18)
	{
		return "Tres Bien";
	}if(moy>=18 && moy<20)
	{
		return "Excellent";
	}
}
void afficherGroupe(Groupe gp)
{
	int colwidth = 10;
	vector<GroupeModule> listModule = gp.getListModule();
	if(gp.getListModule().size()>0){
		cout << setw(100) << internal << gp.get_id_grp() << " " << gp.get_diplome() << endl;
	cout << setfill(' ') <<left<< setw(60)<<" ";
	for (int i = 0;i < gp.getListModule().size();i++) {
		cout<<setprecision(0) << setfill(' ') << setw(colwidth * (gp.getListModule().at(i).get_liste_mat().size()+1)+ gp.getListModule().at(i).get_liste_mat().size()) << gp.getListModule().at(i).get_nom_gm() << "|";
	}
	cout << setw(colwidth) << "Moyenne" << '|' << setw(colwidth) << "Resultat" << '|' << setw(colwidth) << "Mention" << '|';
	cout << endl;
	cout << setfill(' ') << left << setw(60) << " ";

	for (int i = 0;i < gp.getListModule().size();i++) {
		cout << setprecision(0) << setfill(' ') << setw(colwidth * (gp.getListModule().at(i).get_liste_mat().size() + 1) + gp.getListModule().at(i).get_liste_mat().size()) << gp.getListModule().at(i).get_coef_gm() << "|";
	}
	cout << endl;

	cout << setfill(' ') << left << setw(60) << " ";

	for(int i=0;i<gp.getListModule().size();i++)
	{
		{
			for (int j = 0;j < gp.getListModule().at(i).get_liste_mat().size();j++)
			{
				cout << setprecision(0)<<setfill(' ') << setw(colwidth) << gp.getListModule().at(i).get_liste_mat().at(j).get_nom_mat() << '|';
			}
			cout << setw(colwidth) << "Moyenne"<<'|';
			
		}
	}
		cout << endl;
		cout << setfill(' ') << left << setw(60) << " ";

	for(int i=0;i<gp.getListModule().size();i++)
	{
		for(int j = 0;j < gp.getListModule().at(i).get_liste_mat().size();j++)
		{
			cout << setprecision(0) << setw(colwidth) << gp.getListModule().at(i).get_liste_mat().at(j).get_coef_gm()<<'|';
		}
		cout << setw(colwidth) << " " << '|';
	}
		cout << endl;
		cout <<setw(15)<<"Numero"<<'|' << setw(45) << "Nom et Prenom " << endl;
	
	for(int i=0;i<gp.getListEtudiants().size();i++)
	{
		double moy = 0;
		double coefTot = 0;
		cout << setprecision(0)<<setw(15)<<gp.getListEtudiants().at(i).get_num_insc()<<'|' << setw(44) << gp.getListEtudiants().at(i).get_nom() + ' ' + gp.getListEtudiants().at(i).get_prenom();
		for(int j=0;j<gp.getListModule().size();j++)
		{
			double coef = 0;
			double note = 0;
			for (int k = 0;k < gp.getListModule().at(j).get_liste_mat().size();k++) {
				coef += gp.getListModule().at(j).get_liste_mat().at(k).get_coef_gm();
				sql::ResultSet* rs = databaseConnection::fetchMoyMat(gp.getListModule().at(j).get_liste_mat().at(k).get_id_mat(), gp.getListEtudiants().at(i).get_num_insc());
				while(rs->next()){
					note += rs->getDouble(1) * gp.getListModule().at(j).get_liste_mat().at(k).get_coef_gm();
					cout << fixed;
				cout << setprecision(2)<<setfill(' ') << setw(colwidth) << rs->getDouble(1) << '|';
				
				}
				delete rs;
			}
			double moyGm = note / coef;
			coefTot += gp.getListModule().at(j).get_coef_gm();
			moy += moyGm*gp.getListModule().at(j).get_coef_gm();
				
				cout << fixed;
			cout << setprecision(2) << setfill(' ') << setw(colwidth) << moyGm << '|';
			
		}

		moy = moy / coefTot;
		cout << setprecision(2) << setfill(' ') << setw(colwidth) << moy << '|' << setw(colwidth)<< testAdmission(moy) << '|'<< setw(colwidth) << testMention(moy) << '|';
		cout << endl;
	}
	}
	
}
void afficherEtudiantsParGroupe()
{
	cout << "Donner l'ID de GROUPE : " << endl;
	string idg;
	cin >> idg;
	sql::ResultSet* rs = databaseConnection::listeEtudiantsByGrp(idg);
	cout << setw(20) << left << "Num Inscription" << '|' << setw(20) << "Nom" << '|' << setw(20) << "Prenom" << '|' << endl;
	while(rs->next())
	{
		cout << setw(20) << left << rs->getInt("num_insc") << '|' << setw(20) << rs->getString("nom") << '|' << setw(20) << rs->getString("prenom") << '|' << endl;
	}
	cout << endl;
	
	delete rs;
}
void affciherMatiereParEsneignant()
{
	sql::ResultSet* rs;
	cout << "Donner le code de l'enseignant";
	int cd;
	cin >> cd;
	cout << endl;
	rs = databaseConnection::fetchMatiereByEns(cd);
	cout << setw(20) << left << "Matiere " << '|' << setw(20) << "Coeffecient" << endl;
	while(rs->next())
	{
		cout << fixed;
		cout << setw(20) << left << rs->getString("nomMat") << '|' << setw(20) <<setprecision(1) << rs->getDouble("coef") << endl;
	}
}

