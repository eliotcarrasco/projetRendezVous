#include "LCPersonne.h"
#include "Personne.h"
#include "globals.h"
#include <iostream>
#include <string>

using namespace std;

/**
    Constructeur par defaut de ChainonPersonne
 */
ChainonPersonne::ChainonPersonne() : prsn{}, suiv{nullptr}
{}

/**
    Constructeur de recopie
 */
ChainonPersonne::ChainonPersonne(const Personne& pers) : prsn{pers}, suiv{nullptr}
{}


/**
    Retourne la personne du chainon
    @return la personne
 */
Personne& ChainonPersonne::getPersonne()
{
    return prsn;
}

/**
    Retourne le chainon suivant
    @return le chainon suivant
 */
ChainonPersonne* ChainonPersonne::getSuiv()
{
    return suiv;
}


/**
    Constructeur par defaut
 */
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
        this->Inserer(tmp->prsn);
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
    Retourne une instance de personne à partir de son identifiant
    @return une personne
    @pre - la personne doit exister
 */
Personne LCPersonne::getPersonneById(int pId) const
{
    
    ChainonPersonne* tmp = t;
    
    while (tmp && tmp->prsn.Id() != pId)
        tmp = tmp->suiv;
    
    if(tmp)
        return tmp->prsn;
    
    return Personne{}; //renvoie une personne vide si n'existe pas
}


/**
	Ajoute une nouvelle personne dans la liste
	@param pers - la personne a ajouter
*/
void LCPersonne::Inserer(const Personne& pers)
{
    ChainonPersonne* nouv = new ChainonPersonne{pers};

	if(t == nullptr)
		t = nouv;
	else if( pers < t->prsn )
	{
		nouv->suiv = t;
		t = nouv;
	}
	else
	{
		ChainonPersonne *c1 = t, *c2 = t->suiv;
		while( c2 != 0 && ( pers > c2->prsn ) )
		{
			c1 = c2;
			c2 = c2->suiv;
		}
		c1->suiv = nouv;
		nouv->suiv = c2;
	}
}

/**
	Supprime une personne
	@param pers - la personne a supprimer
*/
void LCPersonne::Supprimer(const Personne& pers)
{
	if(t->prsn == pers)
	{
		ChainonPersonne* tmp = t;
		t = t->suiv;
		delete tmp;
	}
	else
	{
		ChainonPersonne *c1 = t, *c2 = t->suiv;
		while(c2->prsn != pers)
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
    while(tmp != nullptr && tmp->prsn != pers)
		tmp = tmp->suiv;
	if(tmp->prsn == pers)
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
			tmp->prsn.setTelephone(tel);
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
			tmp->prsn.setMail(mail);
		}
	}
	cout << "Modifications enregistrees avec succees" << endl << endl;
}


/**
    Compte le nombre de chainon dans la liste
    @return nb le nombre de chainon c-a-d la taille de la liste
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


/**
	Verifie si le nom d'une personne est deja pris ou pas
	@param nomPers - un nom
	@param prenomPers - un prenom
	@return Vrai si le nom n'est pas deja pris par une personne, Faux sinon
*/
bool LCPersonne::nomPersonneDisponible(const string & nomPers, const string & prenomPers)
{
    string lowerNomPers = convertToUpper(nomPers);
    string lowerPrenomPers = convertForName(prenomPers);
    
    if(t)
    {
        ChainonPersonne* tmp = t;
        
        while(tmp != nullptr && (tmp->prsn.Nom() != lowerNomPers || tmp->prsn.Prenom() != lowerPrenomPers) )
        {
            tmp = tmp->suiv;
        }
        
        if(tmp)
        {
            cout << "Il existe deja une personne de meme nom et de meme prenom" << endl << endl;
            return false;
        }
    }
    
    return true;
    
}




