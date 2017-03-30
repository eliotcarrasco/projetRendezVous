#ifndef LCPERSONNE_H 
#define LCPERSONNE_H
#include "Personne.h"

#include <string>

class ChainonPersonne
{
    public:
        ChainonPersonne();
        ChainonPersonne(const Personne& pers);
        Personne& getPersonne();
        ChainonPersonne* getSuiv();
    private:
        Personne prsn;
        ChainonPersonne* suiv;
    
    friend class LCPersonne;
    
};


class LCPersonne
{
	public:
		LCPersonne();
        LCPersonne(const LCPersonne& lcp);
		~LCPersonne();
    
        ChainonPersonne* getTete() const;
        Personne getPersonneById(int pId) const;
    
		void Inserer(const Personne& pers);
		void Supprimer(const Personne& pers);
		void Modifier(const Personne& pers);
        int Compter() const;
    
        bool nomPersonneDisponible(const std::string & nomPers, const std::string & prenomPers);
    
	private:
		ChainonPersonne* t;
    
};

#endif
