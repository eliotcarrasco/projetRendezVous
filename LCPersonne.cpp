#include "LCPersonne.h"
#include "Personne.h"
#include <iostream>
#include <string>

using namespace std;

/**
    Constructeur ChainonPersonne
 */
ChainonPersonne::ChainonPersonne() : p{}, suiv{nullptr}
{}

ChainonPersonne::ChainonPersonne(const Personne& pers) : p{pers}, suiv{nullptr}
{}

//ChainonPersonne::ChainonPersonne(const ChainonPersonne& cp) : p{cp.p}, suiv{cp.suiv}
//{}


LCPersonne::LCPersonne():t{nullptr}
{}


/**
    Constructeur par recopie
 */
LCPersonne::LCPersonne(const LCPersonne& lcp) : t{nullptr}
{
    ChainonPersonne* tmp = lcp.getTete();
    
    while(tmp)
    {
        this->Inserer(tmp->p);
        tmp = tmp->suiv;
    }
}


/**
    Destructeur
 */
LCPersonne::~LCPersonne()
{
	while(t)
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
    ChainonPersonne* nouv = new ChainonPersonne{pers}; //CreerUnChainon()

	if(t == nullptr)
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
	cout << "La personne a ete ajoute avec succes" << endl;
}

/**
	Enlever une personne 
	@param pers - la personne a supprimer
*/
void LCPersonne::Supprimer(const Personne& pers)
{
	if(t->p == pers)
	{
		ChainonPersonne* tmp = t;
		t = t->suiv;
		delete tmp;
        //DetruireMonChainon(tmp);
	}
	else
	{
		ChainonPersonne *c1 = t, *c2 = t->suiv;
		while(c2->p != pers)
		{
			c1 = c2;
			c2 = c2->suiv;
		}
		c1->suiv = c2->suiv;
		delete c2;
	}
	cout << "La personne a ete supprimee avec succes" << endl << endl;
}

/**
	Modifier le numero et/ou le mail d'une personne
	@param pers - la personne a supprimer
*/
void LCPersonne::Modifier(const Personne& pers)
{
	ChainonPersonne* tmp = t;
    while(tmp != nullptr && tmp->p != pers)
		tmp = tmp->suiv;
	if(tmp->p == pers)
	{
		string c;
		
		do	
		{		
			cout << "Voulez-vous modifier le numero de telephone de la personne? (O/N) : ";
			cin >> c;
		}
		while(c != "O" && c != "o" && c != "N" && c != "n");
        
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
		while(c != "O" && c != "o" && c != "N" && c != "n");
        
		if(c == "O" || c == "o")
		{
			string mail;
			cout << "Veuillez inscrire le nouveau mail : ";
			cin >> mail;
			tmp->p.setMail(mail);
		}
	}
	cout << "Modifications enregistrees avec succees" << endl << endl;
}


/**
    Compte le nombre de chainon dans la liste
    @return nb le nombre de chainon
*/
int LCPersonne::Compter() const
{
    int nb = 0;
    
    if (t==nullptr) return nb;
    else
    {
        ChainonPersonne* tmp = t;
        
        while (tmp)
        {
            ++nb;
            tmp = tmp->suiv;
        }
        
        return nb;
    }
}





