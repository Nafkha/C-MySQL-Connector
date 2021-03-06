#pragma once
#include "Enseignant.h"
#include  "databaseConnection.h"

class Matiere
{
private:
	string idMat;
	string nomMat;
	double coef;
	Enseignant ens;
	int nbNotes;
public:
	Matiere(string id_mat, string nom_mat,string gm, double coef, Enseignant ens,int nbNotes,bool addToDb)
		: idMat(id_mat),
		  nomMat(nom_mat),
		  coef(coef),
		  ens(ens),
		  nbNotes(nbNotes)
	{
		if(addToDb)
		databaseConnection::ajouterMatiere(idMat, nomMat,gm, coef, ens.get_cnss(),nbNotes);
	}

	string get_id_mat() const
	{
		return idMat;
	}

	void set_id_mat(const string& id_mat)
	{
		idMat = id_mat;
	}

	string get_nom_mat() const
	{
		return nomMat;
	}

	void set_nom_mat(const string& nom_mat)
	{
		nomMat = nom_mat;
	}

	double get_coef_gm() const
	{
		return coef;
	}

	void set_coef_gm(double coef_gm)
	{
		coef = coef_gm;
	}

	Enseignant get_ens() const
	{
		return ens;
	}

	void set_ens(const Enseignant& ens)
	{
		this->ens = ens;
	}
	int get_nbNotes() const
	{
		return  nbNotes;
	}
};

