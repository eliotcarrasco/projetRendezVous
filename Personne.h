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
		bool aRendezVous(Date d, Heure h);
	private:
		string nom;
		string prenom;
		string telephone;
		string mail;
		
};

#endif
