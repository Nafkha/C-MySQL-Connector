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
	vector<Note> listeNote;

public:
	GroupeModule(string id_gm, string nom_gm, double coef_gm)
		: idGM(id_gm),
		  nomGM(nom_gm),
		  coefGM(coef_gm)
	{
		databaseConnection::ajouterGroupeModule(idGM, nomGM, coefGM);
		cout << "GM" << endl;

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
	
	}
	vector<Note> get_liste_note()
	{
		return listeNote;
	}
	

};

