#pragma once
#include<string>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
using namespace std;
class Personne
{
public:
	int get_id() const
	{
		return id;
	}

	string get_nom() 
	{
		return nom;
	}

	string get_prenom() const
	{
		return prenom;
	}

	string get_mail() const
	{
		return mail;
	}


protected:
	int id;
	string nom;
	string prenom;
	string mail;
public:
	Personne(int id, const string& nom, const string& prenom, const string& mail)
		: id(id),
		  nom(nom),
		  prenom(prenom),
		  mail(mail)
	{
	}

	void set_id(int id)
	{
		this->id = id;
	}

	void set_nom(const string& nom)
	{
		this->nom = nom;
	}

	void set_prenom(const string& prenom)
	{
		this->prenom = prenom;
	}

	void set_mail(const string& mail)
	{
		this->mail = mail;
	}
};

