#ifndef LCRENDEZVOUS_H
#define LCRENDEZVOUS_H
#include "RendezVous.h"
#include "Date.h"
#include "Heure.h"
#include <string>

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
        bool disponible(Date date, Heure heure);
		
	private:
		ChainonRdV* t;
};

#endif
