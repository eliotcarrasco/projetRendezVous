#include <iostream>
#include "LCRendezVous.h"
#include "RendezVous.h"

using namespace std;

/**
	Constructeur
*/
LCRendezVous::LCRendezVous():t{nullptr}
{}

/**
	Destructeur
*/
LCRendezVous::~LCRendezVous()
{
	while(t != 0)
	{
		ChainonRdV* s = t->suiv;
		delete t;
		t=s;
	}
}

/**
	Ajouter un rendez vous a une liste
	@param r - le rendez vous a ajouter
*/
void LCRendezVous::InsererRendezVous(RendezVous r)
{
	ChainonRdV* nouv;
	nouv->RdV = r;
	nouv->suiv = 0;
	if(t==0)
	{
		t=nouv;
	}
	else if ( (r.date() < t->RdV.date()) && (r.heureDeb() < t->RdV.heureDeb()) ) // operateurs à coder pour classe date et heure
	{
		nouv->suiv = t;
		t = nouv;
	}
	else
	{
		ChainonRdV *c1 = t, *c2 = t->suiv;
		while(c2 != 0 && (c2->RdV.date() < r.date()) && (c2->RdV.heureDeb() < r.heureDeb())) //opérateurs à coder
		{
			c1 = c2;
			c2 = c2->suiv;
		}
		c1->suiv = nouv;
		nouv->suiv = c2;
	}
	
}

/**
	Supprimer un rendez vous
	@param nom - le nom du rendez vous
*/
void LCRendezVous::SupprimerRendezVous(string nom)
{
	if(t == 0)
	{ 
		cout << "Le rendez vous n'existe pas";
	}
	else if (t->RdV.nom() == nom)
	{
		ChainonRdV* tmp = t;
		t = t->suiv;
		delete tmp;
		cout << "Le rendez-vous a ete supprime avec succes";
	}
	else
	{
		ChainonRdV *c1 = t, *c2 = t->suiv;
		while(c2 != 0 && c2->RdV.nom() != nom)
		{
			c1 = c2;
			c2 = c2->suiv;
		}
		if(c2 != 0)
		{
			c1->suiv = c2->suiv;
			delete c2;
			cout << "Le rendez-vous a ete supprime avec succes";
		}
		else
		{
			cout << "Le rendez vous n'existe pas";
		}
		
	}
}



/**
    Verifie si la personne a deja un rdv a une date et une heure donnee
    @param date - une date
    @param heure - une heure
    @return Vrai si la personne est disponible (n'a pas de rdv pendant cette heure), Faux sinon
 */
bool LCRendezVous::disponible(Date date, Heure heure)
{
    // attention fonction a modifier car il faut verifier si la duree du rdv n'empiete pas sur un autre
    
    
    if(t == 0)
    {
        return true;
    }
    else
    {
        ChainonRdV* tmp = t;
        
        while(tmp->RdV.date() != date) //operateur a coder
        {
            tmp = tmp->suiv;
        }
        
        if (tmp->RdV.date() == date) //operateur a coder
        {
            if(heure > tmp->RdV.heureDeb() && heure < tmp->RdV.heureFin()) //operateur a coder
                return false;
        }
        
        delete tmp;
        
        return true;
    }

}
