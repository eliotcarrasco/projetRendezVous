#ifndef RENDEZVOUS_H
#define RENDEZVOUS_H
#include <string>
#include "Date.h"
#include "Heure.h"

using namespace std;

class RendezVous
{
	public:
		RendezVous();
	private:
		string nomRdV;
		Date d;
		Heure heureDeb;
		Heure heureFin;
		
		
};

#endif
