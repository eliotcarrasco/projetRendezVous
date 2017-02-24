#ifndef LCRENDEZVOUS_H
#define LCRENDEZVOUS_H
#include "RendezVous.h"

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
		
	private:
		ChainonRdV* t;
};

#endif
