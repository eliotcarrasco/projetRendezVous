#include "RendezVous.h"
#include "Date.h"
#include "Heure.h"
#include "globals.h"
#include <iostream>




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
{
    d_date.~Date();
    d_heureDeb.~Heure();
    d_heureFin.~Heure();
    d_participants.~LCPersonne();
}

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
LCPersonne& RendezVous::listeParticipants()
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
    d_heureDeb = heureDeb;
}

/**
     Modifie l'heure de fin du rdv
     @param heureFin - heure de fin du rdv
 */
void RendezVous::setHeureFin(const Heure& heureFin)
{
    d_heureFin = heureFin;
}

/**
     Modifie l'heure du rdv
     @param heureDeb - heure de debut du rdv
     @param heureFin - heure de fin du rdv
 */
void RendezVous::setHeure(const Heure& heureDeb, const Heure& heureFin)
{
    d_heureDeb = heureDeb;
    d_heureFin = heureFin;
}

/**
    Permet d'ajouter un participant a la liste de participants d'un rdv
    @param pers - une personne
 */
void RendezVous::ajouterParticipant(const Personne& pers)
{
    d_participants.Inserer(pers);
}

/**
    Permet de supprimer un participant de la liste de participants d'un rdv
    @param pers - une personne
 */
void RendezVous::supprimerParticipant(const Personne& pers)
{
    d_participants.Supprimer(pers);
}

/**
    Compte le nombre de participants au rdv
    @return le nombre de participants
 */

int RendezVous::nombreParticipants() const
{
    return d_participants.Compter();
}
/**
	Affiche les infos des particpant a une reunion
*/
void RendezVous::afficherParticipants() const
{
	ChainonPersonne* tmp = d_participants.getTete();
	
	if(tmp == 0)
		std::cout << "Aucun participant pour ce rendez-vous" << endl <<endl;
	else
	{
		std::cout << "Liste des particiants de ce rendez-vous : " << endl;
		while(tmp != 0)
		{
			tmp->p.afficherPersonne();
			tmp = tmp->suiv;
		}
	}
}
