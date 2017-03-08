#ifndef LCRENDEZVOUS_H
#define LCRENDEZVOUS_H
#include "RendezVous.h"
#include <string>

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
		void SupprimerRendezVous(String nom);
		
	private:
		ChainonRdV* t;
};

#endif
