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
	@return Vrai si la personne est deja a un rdv de prevu a la date d et pendant le creneau heureDeb/heureFin, Faux sinon
*/
bool Personne::aRendezVous(const Date& date, const Heure& heureDeb, const Heure& heureFin) const
{
    return d_listeRdv->occupee(date, heureDeb, heureFin);
}

/**
	Retourne le nom de la personne interroge
	@return d_nom - le nom
*/
string Personne::Nom() const
{
	return d_nom;
}

/**
	Retourne le prenom de la personne interroge
	@return d_prenom - le prenom
*/
string Personne::Prenom() const
{
	return d_prenom;
}

/**
	Modifie le numero de telephone de la personne interroge
	@param telephone - le nouveau numero de telephone
*/
void Personne::setTelephone(const string& telephone)
{
     d_telephone = telephone;
}

/**
	Modifie le mail de la personne interroge
	@param mail - le nouveau mail
*/
void Personne::setMail(const string& mail)
{
     d_mail = mail;
}
