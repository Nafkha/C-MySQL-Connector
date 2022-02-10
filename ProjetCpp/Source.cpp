#include "Header.h"

void afficher()
{
	cout << "Hello World !!!" << endl;
}
void creationEtudiant()
{
	int id, num_insc;
	string nom, prenom, mail;
	cout << "ID : ";
	cin >> id;
	cout << "Nom : ";
	cin >> nom;
	cout << "Prenom : ";
	cin >> prenom;
	cout << "Mail : ";
	cin >> mail;
	cout << "Numero d'inscription : ";
	cin >> num_insc;
	Etudiant e(id, nom, prenom, mail, num_insc, true);
}