#ifndef LCPERSONNE_H 
#define LCPERSONNE_H
#include "Personne.h"

#include <string>

class ChainonPersonne
{
    public:
        ChainonPersonne();
//        Personne getP();
//        ChainonPersonne* getSuiv() const;
    
//    private:
        Personne p;
        ChainonPersonne* suiv;
    
};


class LCPersonne
{
	public:
		LCPersonne();
		~LCPersonne();
        ChainonPersonne* getTete() const;
		void Inserer(const Personne& pers);
		void Supprimer(const Personne& pers);
		void Modifier(const Personne &pers);
        int Compter() const;
		
	private:
		ChainonPersonne* t;		
};

#endif
