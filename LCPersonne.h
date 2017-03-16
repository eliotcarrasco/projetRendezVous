#ifndef LCPERSONNE_H 
#define LCPERSONNE_H
#include "Personne.h"

#include <string>

struct ChainonPersonne
{
    Personne p;
    ChainonPersonne* suiv;
};


class LCPersonne
{
    
	public:
		LCPersonne();
		~LCPersonne();
        ChainonPersonne* getTete() const;
		void Inserer(const Personne& p);
		void Supprimer(const Personne& p);
		void Modifier(const string& nom, const string& prenom);
        int Compter() const;
		
	private:
		ChainonPersonne* t;		
};

#endif
