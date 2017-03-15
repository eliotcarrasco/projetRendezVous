#include "LCPersonne.h"
#include <iostream>
#include <string>

using namespace std;

LCPersonne::LCPersonne():t{0}
{}

LCPersonne::~LCPersonne()
{
	while(t != 0)
	{
		ChainonPersonne* s = t->suiv;
		delete t;
		t = s;
	}
}


/**
    Fonction qui retourne la tete de la liste
    @return t - la tete de la liste
 */

ChainonPersonne* LCPersonne::getTete() const
{
    return t;
}

/**
	Ajoute une nouvelle personne dans la liste
	@param pers - la personne a ajouter
*/
void LCPersonne::Inserer(const Personne& pers)
{
	ChainonPersonne* nouv;
	nouv->p = pers;
	nouv->suiv = 0;
	if( t == 0 )
		t = nouv;
	else if(pers.Nom() < t->p.Nom() || (pers.Nom() == t->p.Nom() && pers.Prenom() < t->p.Prenom()) )
	{
		nouv->suiv = t;
		t = nouv;
	}
	else
	{
		ChainonPersonne *c1 = t, *c2 = t->suiv;
		while( c2 != 0 && ( pers.Nom() > c2->p.Nom() || (pers.Nom() == c2->p.Nom() && pers.Prenom() > c2->p.Prenom()) ) )
		{
			c1 = c2;
			c2 = c2->suiv;
		}
		c1->suiv = nouv;
		nouv->suiv = c2;
	}
}

/**
	Enlever une personne 
	@param pers - la personne a supprimer
*/
void LCPersonne::Supprimer(const Personne& pers)
{
	if(t == 0) {}
	else if(t->p.Nom() == pers.Nom())
	{
		ChainonPersonne* tmp = t;
		t = t->suiv;
		delete tmp;
		cout << "La personne a ete supprimee avec succes";
	}
	else
	{
		ChainonPersonne *c1 = t, *c2 = t->suiv;
		while(c2 != 0 && c2->p.Nom() != pers.Nom())
		{
			c1 = c2;
			c2 = c2->suiv;
		}
		if(c2 == 0)
			cout << "La personne n'existe pas";
		else
		{
			c1->suiv = c2->suiv;
			delete c2;
			cout << "La personne a ete supprimee avec succes";
		}
	}
}

/**
	Modifier le numero et/ou le mail a partir du nom et du prenom
	@param nom - Le nom de la personne a modifier
	@param prenom - Le prenom de la personne a modifer
*/
void LCPersonne::Modifier(const string& nom, const string& prenom)
{
	if(t == 0)
		cout << "Cette personne n'existe pas";
	else
	{
		ChainonPersonne* tmp = t;
		while(tmp->p.Nom() != nom && tmp->p.Prenom() != prenom && tmp->suiv != 0)
			tmp = tmp->suiv;
		if(tmp->p.Nom() == nom && tmp->p.Prenom() == prenom)
		{
			string c;
			
			do	
			{		
				cout << "Voulez-vous modifier le numero de telephone de la personne? (O/N) : ";
				cin >> c;
			}
			while(c != "O" || c != "o" || c != "N" || c != "n");
			if(c == "O" || c == "o")
			{
				string tel;
				cout << "Veuillez inscrire le nouveau numero : ";
				cin >> tel;
				tmp->p.setTelephone(tel);
			}
			
			do
			{			
				cout << "Voulez-vous modifier le mail de la personne? (O/N) : ";
				cin >> c;
			}
			while(c != "O" || c != "o" || c != "N" || c != "n");
			if(c == "O" || c == "o")
			{
				string mail;
				cout << "Veuillez inscrire le nouveau mail : ";
				cin >> mail;
				tmp->p.setMail(mail);
			}
		}
		else
			cout << "Cette personne n'existe pas";
	}
}


/**
    Compte le nombre de chainon dans la liste
    @return nb le nombre de chainon
*/
int LCPersonne::Compter() const
{
    int nb = 0;
    
    if (t==0) return nb;
    else
    {
        ChainonPersonne* tmp = t;
        
        while (tmp != 0)
        {
            ++nb;
            tmp = tmp->suiv;
        }
        
        return nb;
    }
}





