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
	Verifie que la personne est occupee
    @param date - une date
    @param heureDeb - l'heure de début du creneau
    @param heureFin - l'heure de fin du créneau
	@return Vrai si la personne est deja a un rdv de prevu a la date d et pendant la duree heureDeb...heureFin, Faux sinon
*/
bool Personne::aRendezVous(Date date, Heure heureDeb, Heure heureFin)
{
    return d_listeRdv->occupee(date, heureDeb, heureFin);
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
