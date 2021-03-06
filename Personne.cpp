#include "Personne.h"
#include "Date.h"
#include "Heure.h"
#include "globals.h"

#include <string>
#include <iostream>

using namespace std;

int Personne::id_suiv = 0;




/**
	Constructeur par defaut
 */

Personne::Personne() :  d_id{id_suiv++},
                        d_nom{},
                        d_prenom{},
                        d_telephone{},
                        d_mail{}
{}



/**
    Constructeur
    @param nom - un nom
    @param prenom - un prenom
    @param telephone - un numero de telephone
    @param mail - une adresse e-mail
 */
Personne::Personne(const string& nom, const string& prenom, const string& telephone, const string& mail) :  d_id{id_suiv++},
                                                                                                            d_nom{convertToUpper(nom)},
                                                                                                            d_prenom{convertForName(prenom)},
                                                                                                            d_telephone{telephone},
                                                                                                            d_mail{mail}
{}


/**
    Constructeur par recopie
    @param pers - une personne
 */

Personne::Personne(const Personne& pers) :  d_id{pers.Id()},
                                            d_nom{convertToUpper(pers.Nom())},
                                            d_prenom{convertForName(pers.Prenom())},
                                            d_telephone{pers.Telephone()},
                                            d_mail{pers.Mail()}
{}



/**
    Retourne l'id de la personne
    @return d_id - le numero id de la personne
 */
int Personne::Id() const
{
    return d_id;
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
    Modifie le numero de telephone
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
	Afficher les informations de la personne concerne dans la console
*/
void Personne::afficherPersonne() const
{
	std::cout << "Nom : " << d_nom << endl;
	std::cout << "Prenom : " << d_prenom << endl;
	std::cout << "Numero de telephone : " << d_telephone << endl;
	std::cout << "Adresse mail : " << d_mail << endl << endl;
}


/**
    Operateur ==
    @param pers - une personne
    @return Vrai si les deux personnes sont egales, Faux sinon
 */
bool Personne::operator==(const Personne& pers) const
{
    if(this == &pers) return true;
    
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

/**
	Operateur <
	@param pers - une personne
	@return Vrai si la personne courante se trouve avant (alphabetiquement) que la personne (pers), Faux sinon
*/
bool Personne::operator<(const Personne& pers) const
{
    return ( ( d_nom < pers.d_nom ) || ( d_nom == pers.d_nom && d_prenom < pers.d_nom ) );
}

/**
	Operateur >
	@param pers - une personne
	@return Vrai si la personne courante se trouve apres (alphabetiquement) que la personne (pers), Faux sinon
*/
bool Personne::operator>(const Personne& pers) const
{
    return ( ( d_nom > pers.d_nom ) || ( d_nom == pers.d_nom && d_prenom > pers.d_nom ) );
}
