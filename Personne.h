#ifndef PERSONNE_H
#define PERSONNE_H
	
#include <string>
#include "Date.h"
#include "Heure.h"

using namespace std;

class Personne
{
	public:
		Personne(const string& nom, const string& prenom, const string& telephone, const string& mail);
        Personne(const Personne& pers);
		string Nom() const;
		string Prenom() const;
        string Telephone() const;
        string Mail() const;
		//bool aRendezVous(const Date& date, const Heure& heureDeb, const Heure& heureFin) const;
		void setTelephone(const string& telephone);
		void setMail(const string& mail);
    
        // opérateurs
        Personne& operator=(const Personne& pers);
    
        //opérateur de comparaison
        bool operator==(const Personne& pers) const;
    
		
	private:
		string d_nom;
		string d_prenom;
		string d_telephone;
		string d_mail;
		
    
    
};

#endif
