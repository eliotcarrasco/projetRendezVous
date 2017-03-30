#ifndef LCRENDEZVOUS_H
#define LCRENDEZVOUS_H
#include <string>
#include "Date.h"
#include "Heure.h"
#include "RendezVous.h"
#include "Personne.h"


class ChainonRdV
{
    public:
        ChainonRdV();
        ChainonRdV(const RendezVous& rdv);
        RendezVous& getRdV();
        ChainonRdV* getSuiv();
    
    private:
        RendezVous RdV;
        ChainonRdV* suiv;

    friend class LCRendezVous;

};

class LCRendezVous
{
	public:
		LCRendezVous();
        LCRendezVous(const LCRendezVous& lrv);
		~LCRendezVous();
    
        ChainonRdV* getTete() const;
		void InsererRendezVous(const RendezVous& r);
        void SupprimerRendezVous(const std::string& nom);
        void getRendezVous(LCRendezVous& listeRdv, const Personne& pers) const;
        bool occupee(const Date& date, const Heure& heureDeb, const Heure& heureFin) const;
        bool nomRdvDisponible(const string & nomRdv);

		
	private:
		ChainonRdV* t;
};

#endif
