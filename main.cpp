#include <iostream>
#include "interface.h"
#include "LCPersonne.h"
#include "LCRendezVous.h"
#include "Personne.h"
#include "RendezVous.h"
#include "Date.h"
#include "Heure.h"
#include <vector>


/**
    Procédure de test temporaire
 */
void testLCPersonne()
{
    /* $$$$$$$ Test de LCPersonne $$$$$$$$$ */
    LCPersonne listePersonnes{};
    
    vector<Personne> vP {
        Personne{"Pfund", "Daniel", "0646231902", "dany.pfd@gmail.com"},
        Personne{"Pfund", "Arnold", "0646231902", "dany.pfd@gmail.com"},
        Personne{"Hindi", "Hassane", "0646231902", "rppalestine@gmail.com"},
        Personne{"Carrasco", "Eliot", "0646121902", "insectsforlife@gmail.com"},
        Personne{"Machin", "Alexandre", "0646352413", "al@yahoo.fr"}
    };
    
    for( int i = 0; i < vP.size(); i++)
        listePersonnes.Inserer(vP[i]);
    
    
    ChainonPersonne* tmp = listePersonnes.getTete();
    
    while(tmp != 0)
    {
        cout << "Test Insertion Personne : " << tmp->p.Nom() << tmp->p.Prenom() <<  endl;
        tmp = tmp->suiv;
    }
    
    listePersonnes.Modifier(Personne{"Pfund", "Daniel", "0646231902", "dany.pfd@gmail.com"});
    
    tmp = listePersonnes.getTete();
    
    while(tmp != 0)
    {
        cout << "Test Modification Personne : " << tmp->p.Nom() << endl << tmp->p.Prenom() << endl << tmp->p.Telephone() << endl << tmp->p.Mail() <<  endl;
        tmp = tmp->suiv;
    }
}



/**
 Procédure de test temporaire
 */
void testLCRendezVous()
{
    /* $$$$$$$ Test de LCRendezVous $$$$$$$$$ */
    LCRendezVous listeRdv{};
    
    vector<RendezVous> vR {
        RendezVous{"Business", Date{16, 3, 2017}, Heure{15, 27}, Heure{17, 30}},
        RendezVous{"Business meeting", Date{17, 3, 2017}, Heure{14, 00}, Heure{15, 30}}
    };
    
    for( int i = 0; i < vR.size(); i++)
        listeRdv.InsererRendezVous(vR[i]);
    
    
    ChainonRdV* tmp2 = listeRdv.getTete();
    
    while(tmp2 != 0)
    {
        cout << "Test Insertion Rdv :  " << tmp2->RdV.nom() << endl;
        tmp2 = tmp2->suiv;
    }
}


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	//interface inter;
	//inter.menuPrincipal(listePersonnes, listeRdv);
    testLCRendezVous();
	return 0;
}


