#include <iostream>>
#include "LCRendezVous.h"

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
LCRendezVous::InsererRendezVous(RendezVous r)
{
	ChainonRenChainonRdVdezVous* nouv;
	nouv->RdV = r;
	nouv->suiv = 0;
	if(t==0)
	{
		t=nouv;
	}
	else
	{
		nouv->suiv = t;
		t = nouv;
	}
	else
	{
		ChainonRdV *c1 = t, *c2 = t->suiv;
		while(c2 != 0 && c2->RdV.GetDate() < r.GetDate())
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
LCRendezVous::SupprimerRendezVous(String nom)
{
	if(t == 0)
	{ 
		cout << "Le rendez vous n'existe pas";
	}
	else if (r == t)
	{
		ChainonRdV* tmp = t;
		t = t->suiv;
		delete tmp;
		cout << "Le rendez-vous a ete supprime avec succes";
	}
	else
	{
		ChainonRdV* c1 = t, c2 = t->suiv;
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
