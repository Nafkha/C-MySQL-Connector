#pragma once
#include "Personne.h"
#include "databaseConnection.h"
class Enseignant:public Personne
{
private:
	int cnss;
public:
	Enseignant(int id, const string& nom, const string& prenom, const string& mail, int cnss)
		: Personne(id, nom, prenom, mail),
		  cnss(cnss)
	{
		databaseConnection::ajouterEnseignant(id, nom, prenom, mail, cnss);
	}

	int get_cnss() const
	{
		return cnss;
	}

	void set_cnss(int cnss)
	{
		this->cnss = cnss;
	}
};

