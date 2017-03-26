#ifndef LCRENDEZVOUS_H
#define LCRENDEZVOUS_H
#include <string>
#include "Date.h"
#include "Heure.h"
#include "RendezVous.h"
#include "Personne.h"


class ChainonRdV
{
//    private:
public:
        ChainonRdV();
        ChainonRdV(const RendezVous& rdv);
        //~ChainonRdV();
        RendezVous RdV;
        ChainonRdV* suiv;
//friend class LCPersonne;
//    friend class LCRendezVous;
//    friend class RendezVous;
//    friend class interface;
//    friend class Personne;
//    friend void testLCRendezVous();
//    friend void testLCPersonne();
//    friend void testParticipantsRDV();
//    friend int main(int argc, char** argv);
};

class LCRendezVous
{
	public:
		LCRendezVous();
        LCRendezVous(const LCRendezVous& lrv);
		~LCRendezVous();
        ChainonRdV* getTete() const;
		void InsererRendezVous(const RendezVous& r);
        void SupprimerRendezVous(const std::string& nom); //utiliser un rdv comme parametre --> manque operateur pour rdv
        											 //manque la fonction qui permet de modifier les rdv
        bool occupee(const Date& date, const Heure& heureDeb, const Heure& heureFin) const;
        void getRendezVous(LCRendezVous& listeRdv, const Personne& pers) const;
		void rechercherRendezVous(Date d);
		
		void modifierRendezVous(RendezVous& rdv);


		
	private:
		ChainonRdV* t;
};

#endif
