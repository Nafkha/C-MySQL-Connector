#pragma once
#include "GroupeModule.h"
#include "Etudiant.h"
#include "databaseConnection.h"
class Groupe
{
private:
	string idGRP;
	string niveau;
	string diplome;
	string specialite;
	int num_g;
	vector<GroupeModule> listeModules;
	vector<Etudiant> listeEtudiants;
public:
	Groupe(string id_grp, string niveau, string diplome, string specialite, int num_g)
		: idGRP(id_grp),
		  niveau(niveau),
		  diplome(diplome),
		  specialite(specialite),
		  num_g(num_g)
	{
		databaseConnection::ajouterGroupe(idGRP,niveau,diplome,specialite,num_g);
	}

	Groupe() = default;

	string get_id_grp() const
	{
		return idGRP;
	}

	void set_id_grp(const string& id_grp)
	{
		idGRP = id_grp;
	}

	string get_niveau() const
	{
		return niveau;
	}

	void set_niveau(const string& niveau)
	{
		this->niveau = niveau;
	}

	string get_diplome() const
	{
		return diplome;
	}

	void set_diplome(const string& diplome)
	{
		this->diplome = diplome;
	}

	string get_specialite() const
	{
		return specialite;
	}

	void set_specialite(const string& specialite)
	{
		this->specialite = specialite;
	}

	int get_num_g() const
	{
		return num_g;
	}

	void set_num_g(int num_g)
	{
		this->num_g = num_g;
	}
	void addEtu(Etudiant e)
	{
		listeEtudiants.push_back(e);
	}

	void testAfficherEtudiants()
	{
		for(int i=0;i<listeEtudiants.size();i++)
		{
			cout << "Nom : " << listeEtudiants.at(i).get_nom() << endl;
		}
	}

}; 

