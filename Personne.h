#ifndef PERSONNE_H
#define PERSONNE_H
	
#include <string>
#include "Date.h"
#include "Heure.h"

using namespace std;

class LCRendezVous;

class Personne
{
	public:
		Personne(string nom, string prenom, string telephone, string mail);
		string Nom();
		string Prenom();
		bool aRendezVous(Date date, Heure heure);
		void setNoTelephone(string telephone);
		void setMail(string mail);
		
	private:
		string d_nom;
		string d_prenom;
		string d_telephone;
		string d_mail;
        LCRendezVous* d_listeRdv;
		
};

#endif
