#pragma once
#include "databaseConnection.h"
#include "Personne.h"
#include <iomanip>
//#include  "databaseConnection.h"
class Etudiant:public Personne
{
private:
	int num_insc;
public:
	Etudiant() = delete;
	Etudiant(int id, const string& nom, const string& prenom, const string& mail, int num_insc,string idGRP,bool addToDb)
		: Personne(id, nom, prenom, mail),
		  num_insc(num_insc)
	{
		//databaseConnection::afficher();
		if(addToDb)
		databaseConnection::ajouterEtudiant(id, nom, prenom, mail, num_insc,idGRP);
	}
	Etudiant(int id, const string& nom, const string& prenom, const string& mail, int num_insc)
		: Personne(id, nom, prenom, mail),
		  num_insc(num_insc)
	{
	
	}

	void set_num_insc(int num_insc)
	{
		this->num_insc = num_insc;
	}


	int get_num_insc() const
	{

		return num_insc;
	}
	friend ostream& operator<<(ostream& flux,const Etudiant& e)
	{
		flux << setw(9) << left << e.num_insc << '|' << setw(30) <<e.nom << '|' << setw(30) << e.prenom <<'|'<<setw(30)<<e.mail<< endl;
		return  flux;

	}
};

