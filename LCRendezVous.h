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
		void InsererRendezVous(RendezVous r);
        void SupprimerRendezVous(string nom);
        bool occupee(Date date, Heure heureDeb, Heure heureFin);
		
	private:
		ChainonRdV* t;
};

#endif
