#include "Personne.h"
#include "Date.h"
#include "Heure.h"
#include <string>

Personne::Personne(string nom, string prenom, string telephone, string mail) : d_nom{nom}, 
																			   d_prenom{prenom}, 
																			   d_telephone{telephone}, 
																			   d_mail{mail}
{}

bool Personne::aRendezVous(Date d, Heure h)
{
}

string Personne::Nom()
{
	return d_nom;
}

