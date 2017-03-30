#include "RendezVous.h"
#include "Date.h"
#include "Heure.h"
#include "globals.h"

#include <iostream>

using namespace std;

/**
 Constructeur vide
 */
RendezVous::RendezVous() : d_nom{}, d_date{}, d_heureDeb{}, d_heureFin{}, d_participants{}
{}


/**
    Constructeur
    @param nom - le nom du rdv
    @param date - la date fixee du rdv
    @param heureDeb - l'heure a laquelle commence le rdv
    @param heureFin - l'heure a laquelle termine le rdv
 */
RendezVous::RendezVous(const string& nom, Date date, Heure heureDeb, Heure heureFin) : d_nom{convertToLower(nom)},
                                                                                d_date{date},
                                                                                d_heureDeb{heureDeb},
                                                                                d_heureFin{heureFin},
                                                                                d_participants{}
{}


RendezVous::~RendezVous()
{}

/**
    Renvoie le nom du rdv
    @return nom du rdv
 */
string RendezVous::nom() const
{
    return d_nom;
}


/**
	Renvoie la date du rdv
	@return date du rdv
*/
Date RendezVous::date() const
{
    return d_date;
}

/**
	Renvoie l'heure de debut du rdv
	@return heure de debut du rdv
*/
Heure RendezVous::heureDeb() const
{
    return d_heureDeb;
}

/**
	Renvoie l'heure de fin du rdv
	@return heure de fin du rdv
 */
Heure RendezVous::heureFin() const
{
    return d_heureFin;
}


/**
    Renvoie la liste des personnes participants au rdv
    @return liste de personnes du rdv
 */
vector<int> RendezVous::listeParticipants()
{
    return d_participants;
}


/**
    Modifie le nom du rdv
    @param nom - nom du rdv
 */
void RendezVous::setNom(const string& nom)
{
    d_nom = convertToLower(nom);
}

/**
    Modifie la date du rdv
    @param date - date du rdv
 */
void RendezVous::setDate(const Date& date)
{
    d_date = date;
}

/**
    Modifie l'heure de debut du rdv
    @param heureDeb - heure de debut du rdv
 */
void RendezVous::setHeureDeb(const Heure& heureDeb)
{
    if(heureDeb.valide())
        d_heureDeb = heureDeb;
}

/**
    Modifie l'heure de fin du rdv
    @param heureFin - heure de fin du rdv
 */
void RendezVous::setHeureFin(const Heure& heureFin)
{
    if(heureFin.valide())
        d_heureFin = heureFin;
}

/**
    Modifie l'heure du rdv
    @param heureDeb - heure de debut du rdv
    @param heureFin - heure de fin du rdv
 */
void RendezVous::setHeure(const Heure& heureDeb, const Heure& heureFin)
{
    setHeureDeb(heureDeb);
    setHeureFin(heureFin);
}

/**
    Permet d'ajouter un participant a la liste de participants d'un rdv
    @param pers - une personne
 */
void RendezVous::ajouterParticipant(const Personne& pers)
{
    int i = 0;
    
    for (; i < d_participants.size() && d_participants[i] != pers.Id() ; i++);
    
    if(i == d_participants.size())
        d_participants.push_back(pers.Id());
}

/**
    Permet de supprimer un participant de la liste de participants d'un rdv
    @param pers - une personne
 */
void RendezVous::supprimerParticipant(const Personne& pers)
{
    int i = 0;
    string rep;
    
    for(; i < d_participants.size() && d_participants[i] != pers.Id(); i++);
    
    if(d_participants[i] == pers.Id())
    {
    	cout << "Etes vous sur de vouloir supprimer " + pers.Prenom() + " " + pers.Nom() + " ? O/N";
    	cin >> rep;
    	
    	if(rep == "o" || rep =="O")
    		d_participants.erase(d_participants.begin() + i);
    	else
    		cout << "Suppression annulee" << endl << endl;
	}
        
        
}

/**
    Compte le nombre de participants au rdv
    @return le nombre de participants
 */

int RendezVous::nombreParticipants() const
{
    return static_cast<int>(d_participants.size());
}

void RendezVous::afficherRendezVous()
{
	cout << "Nom : " << d_nom << endl;
	cout << "Date : " << d_date << endl;
	cout << "Heure de debut : " << d_heureDeb << endl;
	cout << "Heure de fin : " << d_heureFin << endl << endl;
}

/**
    Surcharge de l'operateur != pour les rendez-vous
    @param rdv - un rdv
    @return Vrai si les deux rendez-vous sont differents, Faux sinon
 */
bool RendezVous::operator!=(const RendezVous& rdv) const
{
	return (d_nom != rdv.d_nom || d_date != rdv.d_date || d_heureDeb != rdv.d_heureDeb || d_heureFin != rdv.d_heureFin || d_participants != rdv.d_participants);
}

/**
    Surcharge de l'operateur == pour les rendez-vous
    @param rdv - un rdv
    @return Vrai si les deux rendez-vous sont egaux, Faux sinon
 */
bool RendezVous::operator==(const RendezVous& rdv) const
{
	return (d_nom == rdv.d_nom && d_date == rdv.d_date && d_heureDeb == rdv.d_heureDeb && d_heureFin == rdv.d_heureFin && d_participants == rdv.d_participants);	
}

/**
	Surcharge de l'operateur < pour les rendez-vous
	@param rdv - un rdv
	@return Vrai si le rendez-vous a lieu avant le rendez-vous passe en parametre, Faux sinon
*/
bool RendezVous::operator<(const RendezVous& rdv) const
{
    return (d_date < rdv.date()) || (d_date == rdv.date() && d_heureDeb < rdv.heureDeb());
}

/**
	Surcharge de l'operateur != pour les rendez-vous
	@param rdv - un rdv
	@return Vrai si le rendez-vous a lieu apres le rendez-vous passe en parametre, Faux sinon
*/
bool RendezVous::operator>(const RendezVous& rdv) const
{
    return (d_date > rdv.date()) || (d_date == rdv.date() && d_heureDeb > rdv.heureDeb());
}
