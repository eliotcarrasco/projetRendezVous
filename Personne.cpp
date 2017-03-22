#include "Personne.h"
#include "Date.h"
#include "Heure.h"
#include "globals.h"

#include <string>
#include <iostream>

Personne::Personne(const string& nom, const string& prenom, const string& telephone, const string& mail) : d_nom{convertToUpper(nom)},
																			   d_prenom{convertForName(prenom)},
																			   d_telephone{telephone}, 
																			   d_mail{mail}
{}




/**
    Constructeur par recopie
    @param pers - une personne
 */

Personne::Personne(const Personne& pers) : d_nom{convertToUpper(pers.Nom())},
                                        d_prenom{convertForName(pers.Prenom())},
                                        d_telephone{pers.Telephone()},
                                        d_mail{pers.Mail()}
{}


/**
 Constructeur vide
 */

Personne::Personne() : d_nom{},
                        d_prenom{},
                        d_telephone{},
                        d_mail{}
{}


Personne::~Personne()
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
	Retourne le telephone de la personne interroge
	@return d_telephone - le telephone
 */
string Personne::Telephone() const
{
    return d_telephone;
}


/**
	Retourne le mail de la personne interroge
	@return d_mail - le mail
 */
string Personne::Mail() const
{
    return d_mail;
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
	Afficher les informations de la personne concerne
*/
void Personne::afficherPersonne() const
{
	std::cout << "Nom : " << d_nom << endl;
	std::cout << "Preom : " << d_prenom << endl;
	std::cout << "Numero de telephone : " << d_telephone << endl;
	std::cout << "Adresse mail : " << d_mail << endl;
}

/**
     Operateur =
     @param pers - une personne
*/
Personne& Personne::operator=(const Personne& pers)
{
    if(this == &pers) return *this; // mettre par référence ou pas ?
    
    d_nom = pers.Nom();
    d_prenom = pers.Prenom();
    d_telephone = pers.Telephone();
    d_mail = pers.Mail();
    
    return *this;
}

/**
    Operateur ==
    @param pers - une personne
    @return Vrai si les deux personnes sont egales, Faux sinon
 */
bool Personne::operator==(const Personne& pers) const
{
    if(this == &pers) return true; // que pour les listes chainee ou la aussi ?
    
    return (d_nom == pers.Nom() && d_prenom == pers.Prenom());
}


/**
 Operateur !=
 @param pers - une personne
 @return Vrai si les deux personnes sont differente, Faux sinon
 */
bool Personne::operator!=(const Personne& pers) const
{
    return (d_nom != pers.Nom() || d_prenom != pers.Prenom());
}
