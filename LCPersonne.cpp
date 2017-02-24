#include "LCPersonne.h"

using namespace std;

LCPersonne::LCPersonne():t{nullptr}
{}

LCPersonne::~LCPersonne()
{
	while(t != 0)
	{
		ChainonPersonne* s = t->suiv;
		delete t;
		t=s;
	}
}

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

void LCPersonne::Supprimer(Personne pers)
{
	if(t == 0) {}
	else if(t->p == pers)
	{
		ChainonPersonne* tmp = t;
		t=t->suiv;
		delete tmp;
	}
}
