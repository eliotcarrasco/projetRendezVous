#ifndef LCRENDEZVOUS_H
#define LCRENDEZVOUS_H
#include "Date.h"
#include "Heure.h"
#include <string>
#include "RendezVous.h"

using namespace std;

struct ChainonRdV
{
    RendezVous RdV;
	ChainonRdV* suiv;
};


class LCRendezVous
{
	public:
		LCRendezVous();
		~LCRendezVous();
		void InsererRendezVous(const RendezVous& r);
        void SupprimerRendezVous(const string& nom);
        bool occupee(const Date& date, const Heure& heureDeb, const Heure& heureFin) const;
		
	private:
		ChainonRdV* t;
};

#endif
