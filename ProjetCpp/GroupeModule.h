#pragma once
#include <vector>
#include "databaseConnection.h"
#include "Matiere.h"
class GroupeModule
{
private:
	string idGM;
	string nomGM;
	double coefGM;
	vector<Matiere> listeMat;
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
	void ajouterMatiereGM(Matiere m)
	{
			databaseConnection::setGM(idGM, m.get_id_mat());
			listeMat.push_back(m);
		
	}

};

