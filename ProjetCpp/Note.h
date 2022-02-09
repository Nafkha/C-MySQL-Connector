#pragma once
#include "Etudiant.h"
#include "Matiere.h"
#include  "databaseConnection.h"

class Note
{
private:
	Etudiant etu;
	Matiere mat;
	double note;
	string type;
public:
	Note( Etudiant etu,  Matiere mat, double note,  string type, bool addToDb)
		: etu(etu),
		  mat(mat),
		  note(note),
		  type(type)
	{
		if(addToDb)
		databaseConnection::ajouterNote(etu.get_id(), mat.get_id_mat(), note, type);

	}

	Note() = default;

	Etudiant get_etu() const
	{
		return etu;

	}

	Matiere get_mat() const
	{
		return mat;
	}

	double get_note() const
	{
		return note;
	}

	string get_type() const
	{
		return type;
	}

	void set_note(double note)
	{
		this->note = note;
	}

	void set_type(string type)
	{
		this->type = type;
	}
	void set_mat(Matiere mat )
	{
		this->mat = mat;
;	}
	void set_etu(Etudiant e)
	{
		this->etu = e;
	}

};

