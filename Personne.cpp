#include "Personne.h"
#include "Date.h"
#include "Heure.h"
#include <string>

Personne::Personne(string nom, string prenom, string telephone, string mail) : nom{nom}, 
																			   prenom{prenom}, 
																			   telephone{telephone}, 
																			   mail{mail}
{}

bool Personne::aRendezVous(Date d, Heure h)
{
}

string Personne::Nom()
{
	return nom;
}
