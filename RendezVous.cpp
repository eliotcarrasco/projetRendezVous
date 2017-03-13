#include "RendezVous.h"
#include "Date.h"
#include "Heure.h"
#include "globals.h"




/**
 Constructeur vide
 */
RendezVous::RendezVous() : d_nom{}, d_date{}, d_heureDeb{}, d_heureFin{}
{}


/**
    Constructeur
    @param nom - le nom du rdv
    @param date - la date fixee du rdv
    @param heureDeb - l'heure a laquelle commence le rdv
    @param heureFin - l'heure a laquelle termine le rdv
 */
RendezVous::RendezVous(string nom, Date& date, Heure& heureDeb, Heure& heureFin) : d_nom{convertToLower(nom)},
                                                                                d_date{date},
                                                                                d_heureDeb{heureDeb},
                                                                                d_heureFin{heureFin}
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
LCPersonne RendezVous::listeParticipants() const
{
    return d_participants;
}


/**
    Modifie le nom du rdv
    @param nom - nom du rdv
 */
void RendezVous::setNom(string nom)
{
    d_nom = convertToLower(nom);
}

/**
     Modifie la date du rdv
     @param date - date du rdv
 */
void RendezVous::setDate(Date date)
{
    d_date = date;
}

/**
     Modifie l'heure de debut du rdv
     @param heureDeb - heure de debut du rdv
 */
void RendezVous::setHeureDeb(Heure heureDeb)
{
    d_heureDeb = heureDeb;
}

/**
     Modifie l'heure de fin du rdv
     @param heureFin - heure de fin du rdv
 */
void RendezVous::setHeureFin(Heure heureFin)
{
    d_heureFin = heureFin;
}

/**
     Modifie l'heure du rdv
     @param heureDeb - heure de debut du rdv
     @param heureFin - heure de fin du rdv
 */
void RendezVous::setHeure(Heure heureDeb, Heure heureFin)
{
    d_heureDeb = heureDeb;
    d_heureFin = heureFin;
}

/**
    Permet d'ajouter un participant a la liste de participants d'un rdv
    @param pers - une personne
 */
void RendezVous::ajouterParticipant(Personne pers)
{
    d_participants.Inserer(pers);
}

/**
    Permet de supprimer un participant de la liste de participants d'un rdv
    @param pers - une personne
 */
void RendezVous::supprimerParticipant(Personne pers)
{
    d_participants.Supprimer(pers);
}

/**
    Compte le nombre de participants au rdv
    @return le nombre de participants
 */

int RendezVous::nombreParticipants() const
{
    int nb = d_participants.Compter();
    return nb;
}
