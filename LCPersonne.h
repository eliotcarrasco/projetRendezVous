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
		void Inserer(Personne p);
		void Supprimer(Personne p);
		void Modifier(string nom, string prenom);
		
	private:
		ChainonPersonne* t;		
};

#endif
