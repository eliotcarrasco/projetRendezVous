#include "LCPersonne.h"

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
	Ajoute une nouvelle personne dans la liste
	@param pers - la personne a ajouter
*/
void LCPersonne::Inserer(Personne pers)
{
	ChainonPersonne* nouv;
	nouv->p = pers;
	nouv->suiv = 0;
	if( t == 0 )
		t = nouv;
	else if(pers < t->p)
	{
		nouv->suiv = t;
		t = nouv;
	}
	else
	{
		ChainonPersonne *c1 = t, *c2 = t->suiv;
		while( c2 != 0 && pers > c2->p)
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
void LCPersonne::Supprimer(Personne pers)
{
	if(t == 0) {}
	else if(t->p == pers)
	{
		ChainonPersonne* tmp = t;
		t = t->suiv;
		delete tmp;
		cout << "La personne a ete supprimee avec succes";
	}
	else
	{
		ChainonPersonne* c1 = t, c2 = t->suiv;
		while(c2 != 0 && c2 != pers)
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
	Modifier le num�ro et/ou le mail � partir du nom et du prenom
	@param nom - Le nom de la personne a modifier
	@param prenom - Le prenom de la personne a modifer
*/
void LCPersonne::Modifier(string nom, string prenom)
{
	if(t == 0)
		cout << "Cette personne n'existe pas";
	else
	{
		
	}
}