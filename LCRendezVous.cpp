#include "LCRendezVous.h"

using namespace std;

LCRendezVous::LCRendezVous():t{nullptr}
{}

LCRendezVous::~LCRendezVous()
{
	while(t != 0)
	{
		ChainonRdV* s = t->suiv;
		delete t;
		t=s;
	}
//test	
}
