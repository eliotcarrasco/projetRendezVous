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
/*bool Personne::aRendezVous(const Date& date, const Heure& heureDeb, const Heure& heureFin) const
{
    return d_listeRdv->occupee(date, heureDeb, heureFin);
}*/

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
     Modifie le no de telephone
     @param telephone - le no de telephone
 */
void Personne::setTelephone(const string& telephone)
{
     d_telephone = telephone;
}

/**
    Modifie le mail
    @param mail - le mail
 */
void Personne::setMail(const string& mail)
{
     d_mail = mail;
}


/**
    Operateur ==
    @param pers - une personne
    @return Vrai si les deux personnes sont egales, Faux sinon
 */
bool Personne::operator==(const Personne& pers) const
{
    return (d_nom == pers.Nom() && d_prenom == pers.Prenom());
}
