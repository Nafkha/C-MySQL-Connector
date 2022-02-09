#pragma once
#include "databaseConnection.h"
#include "Personne.h"
//#include  "databaseConnection.h"
class Etudiant:public Personne
{
private:
	int num_insc;
public:
	Etudiant() = delete;
	Etudiant(int id, const string& nom, const string& prenom, const string& mail, int num_insc,bool addToDb)
		: Personne(id, nom, prenom, mail),
		  num_insc(num_insc)
	{
		//databaseConnection::afficher();
		if(addToDb)
		databaseConnection::ajouterEtudiant(id, nom, prenom, mail, num_insc);
	}

	void set_num_insc(int num_insc)
	{
		this->num_insc = num_insc;
	}


	int get_num_insc() const
	{

		return num_insc;
	}
	static void af()
	{
		cout << "hello world ";
	}
};

