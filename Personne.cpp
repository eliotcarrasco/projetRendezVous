#include "Personne.h"
#include "Date.h"
#include "Heure.h"
#include <string>
#include "globals.h"
#include "LCRendezVous.h"

Personne::Personne(string nom, string prenom, string telephone, string mail) : d_nom{convertToLower(nom)},
																			   d_prenom{convertToLower(prenom)},
																			   d_telephone{telephone}, 
																			   d_mail{mail}
{}

/**
	Verifie que la personne est disponible
	@return Vrai si la personne est deja a un rdv de prevu a la date d et pendant l'heure h, Faux sinon
*/
bool Personne::aRendezVous(Date date, Heure heure)
{
    return d_listeRdv->disponible(date, heure);
}

/**
	Retourne le nom de la personne interroge
	@return d_nom - le nom
*/
string Personne::Nom()
{
	return d_nom;
}

/**
	Retourne le prenom de la personne interroge
	@return d_prenom - le prenom
*/
string Personne::Prenom()
{
	return d_prenom;
}

void Personne::setTelephone(string telephone)
{
     d_telephone = telephone;
}

void Personne::setMail(string mail)
{
     d_mail = mail;
}
