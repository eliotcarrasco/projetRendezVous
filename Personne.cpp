#include "Personne.h"
#include "Date.h"
#include "Heure.h"
#include <string>

Personne::Personne(string nom, string prenom, string telephone, string mail) : d_nom{nom}, 
																			   d_prenom{prenom}, 
																			   d_telephone{telephone}, 
																			   d_mail{mail}
{}

/**
	Verifie que la personne est disponible
	@return Vrai si la personne a deja un rdv de prevu a la date d et l'heure h, Faux sinon
*/
bool Personne::aRendezVous(Date d, Heure h)
{
	
}

/**
	Retourne le nom de la personne interroge
	@retrun d_nom - le nom
*/
string Personne::Nom()
{
	return d_nom;
}

/**
	Retourne le prenom de la personne interroge
	@retrun d_prenom - le prenom
*/
string Personne::Prenom()
{
	return d_prenom;
}
