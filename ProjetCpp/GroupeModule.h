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
	GroupeModule(string id_gm, string nom_gm, double coef_gm,string gp)
		: idGM(id_gm),
		  nomGM(nom_gm),
		  coefGM(coef_gm)
	{
		databaseConnection::ajouterGroupeModule(idGM, nomGM, coefGM,gp);


	}
	GroupeModule() = default;

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

	void  ajouterMatiere(Matiere m)
	{
		listeMat.push_back(m);
	}
	void ajouterNote(Note n)
	{
		listeNote.push_back(n);
	}
	
	

};

