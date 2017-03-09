#ifndef PERSONNE_H
#define PERSONNE_H
#include <string>
#include "Date.h"
#include "Heure.h"

using namespace std;

class Personne
{
	public:
		Personne(string nom, string prenom, string telephone, string mail);
		string Nom();
		stirng Prenom();
		bool aRendezVous(Date d, Heure h);
		void ModificationPersonne();
	private:
		string d_nom;
		string d_prenom;
		string d_telephone;
		string d_mail;
		
};

#endif
