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
		string d_nomRdv;
		Date d_date;
		Heure d_heureDeb;
		Heure d_heureFin;
		
		
};

#endif
