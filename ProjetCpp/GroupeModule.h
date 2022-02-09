#pragma once
#include <vector>
#include "databaseConnection.h"
#include "Matiere.h"
#include "Note.h"
#include "Etudiant.h"
class GroupeModule
{
private:
	string idGM;
	string nomGM;
	double coefGM;
	vector<Matiere> listeMat;
	//vector<Note> lisetNote;
	vector<Note> listeNote;

public:
	GroupeModule(string id_gm, string nom_gm, double coef_gm)
		: idGM(id_gm),
		  nomGM(nom_gm),
		  coefGM(coef_gm)
	{
		databaseConnection::ajouterGroupeModule(idGM, nomGM, coefGM);
	}

	string get_id_gm() const
	{
		return idGM;
	}

	void set_id_gm(const string& id_gm)
	{
		idGM = id_gm;
	}

	string get_nom_gm() const
	{
		return nomGM;
	}

	void set_nom_gm(const string& nom_gm)
	{
		nomGM = nom_gm;
	}

	double get_coef_gm() const
	{
		return coefGM;
	}

	void set_coef_gm(double coef_gm)
	{
		coefGM = coef_gm;
	}

	vector<Matiere> get_liste_mat() const
	{
		return listeMat;
	}
	/*vector<Note> get_liste_notes() const
	{
		return  lisetNote;
	}*/
	void ajouterMatiereGM(Matiere m)
	{
			databaseConnection::setGM(idGM, m.get_id_mat());
			listeMat.push_back(m);
		
	}
	void getNotes()
	{
		sql::ResultSet* rs;
		for(int i = 0;i<listeMat.size();i++)
		{
			rs = databaseConnection::fetchNotes(listeMat.at(i).get_id_mat());

			while(rs->next())
			{
				sql::ResultSet* et = databaseConnection::fetchEtudiants(rs->getInt("Etu"));
				while (et->next()) {
					Etudiant e(et->getInt("id"), et->getString("nom"), et->getString("prenom"), et->getString("mail"), et->getInt("num_insc"), false);
					Note nt(e, listeMat.at(i), rs->getDouble("Note"), rs->getString("Type"), false);
					listeNote.push_back(nt);
				}
				
			}
		}
		for(int i=0;i<listeNote.size();i++)
		{
			cout << "Nom : " << listeNote.at(i).get_etu().get_nom() << " Note : " << listeNote.at(i).get_note() << endl;
		}
	}
	/*void getNotes()
	{
		sql::ResultSet* rs;
		Note nt;
		
		
		cout << listeMat.size() << endl;
		//cout << listeMat.at(0).get_id_mat() << endl;
		/*for (int i = 0;i<listeMat.size();i++)
		{
			rs= databaseConnection::fetchNotes(listeMat.at(i).get_id_mat());
			while (rs->next())
			{
				Etudiant e;
				//sql::ResultSet* et;
				//et = databaseConnection::fetchEtudiants(rs->getInt("Etu"));
				//e.set_id(et->getInt("id"));
				//e.set_num_insc(et->getInt("num_insc"));
				//e.set_nom(et->getString("nom"));
				//e.set_prenom(et->getString("prenom"));
				//e.set_mail(et->getString("mail"));


				//nt.set_etu(e);
				//nt.set_mat(listeMat.at(i));
				//nt.set_note(rs->getDouble("Note"));
				//
				//nt.set_type(rs->getString("Type"));
				//lisetNote.push_back(nt);
				cout << "Hello" << endl;


			}
			cout << i << endl;
		}
		cout << "HELLO WORLD" << endl;
		
	}*/

};

