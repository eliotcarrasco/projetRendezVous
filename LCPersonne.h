#ifndef LCPERSONNE_H 
#define LCPERSONNE_H
#include "Personne.h"
#include "LCPersonne.h"

#include <string>

class ChainonPersonne
{
//    private:
    public:
        ChainonPersonne();
        ChainonPersonne(const Personne& pers);
//        ChainonPersonne(const ChainonPersonne&);
        Personne p;
        ChainonPersonne* suiv;
//    friend class LCPersonne;
//    friend class LCRendezVous;
//    friend class interface;
//    friend class RendezVous;
//    friend void testLCRendezVous();
//    friend void testLCPersonne();
//    friend void testParticipantsRDV();
//    friend int main(int argc, char** argv);
    
};


class LCPersonne
{
	public:
		LCPersonne();
        LCPersonne(const LCPersonne& lcp);
		~LCPersonne();
        ChainonPersonne* getTete() const;
		void Inserer(const Personne& pers);
		void Supprimer(const Personne& pers);
		void Modifier(const Personne& pers);
        int Compter() const;
		
	private:
		ChainonPersonne* t;
    
};

#endif
