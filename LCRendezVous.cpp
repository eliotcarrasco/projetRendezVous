#include "LCRendezVous.h"
#include "RendezVous.h"
#include "Personne.h"
#include "globals.h"

#include <iostream>

using namespace std;


/**
	Constructeur ChainonRdV
 */
ChainonRdV::ChainonRdV(): RdV{}, suiv{nullptr}
{}


ChainonRdV::ChainonRdV(const RendezVous& rdv): RdV{rdv}, suiv{nullptr}
{}


/**
	Constructeur
*/
LCRendezVous::LCRendezVous():t{nullptr}
{}

/**
    Constructeur par recopie
 */
LCRendezVous::LCRendezVous(const LCRendezVous& lrv) : t{nullptr}
{
    ChainonRdV* tmp = lrv.getTete();
    
    while(tmp)
    {
        this->InsererRendezVous(tmp->RdV);
        tmp = tmp->suiv;
    }
}


/**
	Destructeur
*/
LCRendezVous::~LCRendezVous()
{
	while(t)
	{
		ChainonRdV* s = t->suiv;
		delete t;
		t=s;
	}
}


/**
 Fonction qui retourne la tete de la liste
 @return t - la tete de la liste
 */

ChainonRdV* LCRendezVous::getTete() const
{
    return t;
}

/**
	Ajouter un rendez vous a une liste
	@param r - le rendez vous a ajouter
*/
void LCRendezVous::InsererRendezVous(const RendezVous& r)
{
    ChainonRdV* nouv = new ChainonRdV(r);
	if(t==nullptr)
	{
		t=nouv;
	}
	else if ( (r.date() < t->RdV.date()) || (r.date() == t->RdV.date() && r.heureDeb() < t->RdV.heureDeb()) )
	{
		nouv->suiv = t;
		t = nouv;
	}
	else
	{
		ChainonRdV *c1 = t, *c2 = t->suiv;
		while(c2 != 0 && ( (r.date() > c2->RdV.date()) || (r.date() == c2->RdV.date() && r.heureDeb() > c2->RdV.heureDeb()) ) )
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
void LCRendezVous::SupprimerRendezVous(const string& nom)
{
	if(t == nullptr)
	{ 
		cout << "Le rendez vous n'existe pas" << endl;
	}
	else if (t->RdV.nom() == convertToLower(nom) )
	{
		ChainonRdV* tmp = t;
		t = t->suiv;
		delete tmp;
		cout << "Le rendez-vous a ete supprime avec succes" << endl;
	}
	else
	{
		ChainonRdV *c1 = t, *c2 = t->suiv;
		while(c2 != nullptr && c2->RdV.nom() != convertToLower(nom) )
		{
			c1 = c2;
			c2 = c2->suiv;
		}
		if(c2)
		{
			c1->suiv = c2->suiv;
			delete c2;
			cout << "Le rendez-vous a ete supprime avec succes" << endl;
		}
		else
		{
			cout << "Le rendez vous n'existe pas" << endl;
		}
		
	}
}



/**
    Renvoie la liste des rdv pour une personne donnée
    @listeRdv - la liste des rdv
 */

void LCRendezVous::getRendezVous(LCRendezVous& listeRdv, const Personne& pers) const
{
    if (t)
    {
        ChainonRdV *tmp = t; // tete de la LCRendezVous dans une variable
        while(tmp)
        {
            vector<int> vPart = tmp->RdV.listeParticipants();
            
            for (int i = 0; i < vPart.size(); i++)
            {
                if(vPart[i] == pers.Id())
                {
                    ChainonRdV* nc = tmp;
                    listeRdv.InsererRendezVous(nc->RdV); // insere le nouveau chainon dans la liste des rdv
                }
            }
            
            tmp = tmp->suiv;
        }
    }
}



/**
    Verifie si la personne a deja un rdv a une date et une heure donnee
    @param date - une date
    @param heureDeb - une heure de début
    @param heureFin - une heure de fin
    @return Vrai si la personne est occupee (a un rdv pendant cette heure, ou la duree empietera sur un un rdv), Faux sinon
 */
bool LCRendezVous::occupee(const Date& date, const Heure& heureDeb, const Heure& heureFin) const
{
    
    if(t == nullptr)
    {
        return false;
    }
    else
    {
        ChainonRdV* tmp = t;
        
        //cout << "Tete " << tmp->RdV.date().getStringDate() << endl;
        
        while(tmp != nullptr && tmp->RdV.date() != date)
        {
            tmp = tmp->suiv;
        }
        
        if (tmp)
        {
            if(heureDeb >= tmp->RdV.heureDeb() && heureDeb <= tmp->RdV.heureFin()) // heure de debut compris dans un creneau existant
                return true;
            else if (heureFin >= tmp->RdV.heureDeb() && heureFin <= tmp->RdV.heureFin())// heure de fin compris dans un creneau
                return true;
            else if(heureDeb < tmp->RdV.heureDeb() && heureFin > tmp->RdV.heureFin()) // creneau heureDeb...heureFin englobe un autre creneau
                return true;
        }
    }
    
    return false;
}






