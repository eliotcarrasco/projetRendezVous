#ifndef LCRENDEZVOUS_H
#define LCRENDEZVOUS_H
#include "Date.h"
#include "Heure.h"
#include <string>
#include "RendezVous.h"
#include "Personne.h"

using namespace std;

class ChainonRdV
{
    public:
        ChainonRdV();
        RendezVous RdV;
        ChainonRdV* suiv;
};


class LCRendezVous
{
	public:
		LCRendezVous();
		~LCRendezVous();
        ChainonRdV* getTete() const;
		void InsererRendezVous(const RendezVous& r);
        void SupprimerRendezVous(const string& nom); //utiliser un rdv comme parametre --> manque operateur pour rdv
        											 //manque la fonction qui permet de modifier les rdv
        bool occupee(const Date& date, const Heure& heureDeb, const Heure& heureFin) const;
        LCRendezVous getRendezVous(const Personne& pers) const;
		
	private:
		ChainonRdV* t;
};

#endif
