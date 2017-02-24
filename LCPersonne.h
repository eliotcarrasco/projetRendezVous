#ifndef LCPERSONNE_H 
#define LCPERSONNE_H
#include "Personne.h"

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
		
	private:
		ChainonPersonne* t;		
};

#endif
