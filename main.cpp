#include <iostream>
#include <vector>
#include "interface.h"
#include "LCPersonne.h"
#include "LCRendezVous.h"
#include "Personne.h"
#include "RendezVous.h"
#include "Date.h"
#include "Heure.h"
#include "globals.h"

using namespace std;

/**
    Procedure de test temporaire
 */
void testLCPersonne()
{
    /* $$$$$$$ Test de LCPersonne $$$$$$$$$ */
    LCPersonne listePersonnes{};

    vector<Personne> vP {
        Personne{"Pfund", "Daniel", "0646231902", "dany.pfd@gmail.com"},
        Personne{"Pfund", "aRnoLd", "0646231902", "dany.pfd@gmail.com"},
        Personne{"Hindi", "Hassane", "0646231902", "rppalestine@gmail.com"},
        Personne{"Carrasco", "Eliot", "0646121902", "insectsforlife@gmail.com"},
        Personne{"Machin", "Alexandre", "0646352413", "al@yahoo.fr"}
    };

    for( int i = 0; i < vP.size(); i++)
        listePersonnes.Inserer(vP[i]);


    ChainonPersonne* tmp = listePersonnes.getTete();

    while(tmp != 0)
    {
        cout << "Test Insertion Personne : " << tmp->prsn.Nom() << " " << tmp->prsn.Prenom() <<  endl;
        tmp = tmp->suiv;
    }

    listePersonnes.Modifier(Personne{"Pfund", "Daniel", "0646231902", "dany.pfd@gmail.com"});
    //modifierPersonne(listePersonnes);

    tmp = listePersonnes.getTete();

    while(tmp != 0)
    {
        cout << "Test Modification Personne : " << tmp->prsn.Nom() << endl << tmp->prsn.Prenom() << endl << tmp->prsn.Telephone() << endl << tmp->prsn.Mail() <<  endl;
        tmp = tmp->suiv;
    }

    cout << endl << "Test nombre de personne dans la liste : " << listePersonnes.Compter();
    
}



/**
    Procedure de test temporaire
 */
void testLCRendezVous()
{
    /* $$$$$$$ Test de LCRendezVous $$$$$$$$$ */
    LCRendezVous listeRdv{};

    vector<RendezVous> vR {
        RendezVous{"Business", Date{16, 3, 2017}, Heure{15, 27}, Heure{17, 30}},
        RendezVous{"Business 6", Date{17, 3, 2017}, Heure{15, 31}, Heure{16,30}},
        RendezVous{"Business 2", Date{17, 3, 2017}, Heure{14, 00}, Heure{15, 30}},
        RendezVous{"Business 3", Date{17, 3, 2017}, Heure{15, 00}, Heure{15, 30}},
        RendezVous{"Business meeting 4", Date{19, 3, 2017}, Heure{14, 00}, Heure{15, 30}},
        RendezVous{"Business meeting 3", Date{18, 3, 2017}, Heure{14, 00}, Heure{15, 30}}

    };

    for( int i = 0; i < vR.size(); i++)
        listeRdv.InsererRendezVous(vR[i]);


    ChainonRdV* tmp2 = listeRdv.getTete();

    while(tmp2 != 0)
    {
        cout << "Test Insertion Rdv :  " << tmp2->RdV.nom() << endl;
        tmp2 = tmp2->suiv;
    }

    listeRdv.SupprimerRendezVous("Business meeting 4");

    tmp2 = listeRdv.getTete();

    while(tmp2 != 0)
    {
        cout << "Test Insertion Rdv :  " << tmp2->RdV.nom() << endl;
        tmp2 = tmp2->suiv;
    }
    //cout << "Test de la date et l'heure : " << Date{17, 3, 2017}.getStringDate() << " a " << Heure{15, 30}.getStringHeure() << endl;
    
}



/**
    Procedure de test temporaire pour les participants a un RdV
 */
void testParticipantsRDV()
{

    LCRendezVous listeRdv{};
    
    vector<RendezVous> vR {
        RendezVous{"Business", Date{16, 3, 2017}, Heure{15, 27}, Heure{17, 30}},
        RendezVous{"Business 6", Date{17, 3, 2017}, Heure{15, 31}, Heure{16,30}},
        RendezVous{"Business 2", Date{17, 3, 2017}, Heure{14, 00}, Heure{15, 30}},
        RendezVous{"Business 3", Date{17, 3, 2017}, Heure{15, 00}, Heure{15, 30}},
        RendezVous{"Business meeting 4", Date{19, 3, 2017}, Heure{14, 00}, Heure{15, 30}},
        RendezVous{"Business meeting 3", Date{18, 3, 2017}, Heure{14, 00}, Heure{15, 30}}
        
    };
    
    for( int i = 0; i < vR.size(); i++)
        listeRdv.InsererRendezVous(vR[i]);
    
    
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
    
    
    listeRdv.getTete()->RdV.ajouterParticipant(vP[0]);
    listeRdv.getTete()->RdV.ajouterParticipant(vP[1]);
    listeRdv.getTete()->RdV.ajouterParticipant(vP[2]);
    
}


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{

    LCPersonne listePersonnes{};
    
    vector<Personne> vP {
        Personne{"Pfund", "Daniel", "0646231902", "dany.pfd@gmail.com"},
        Personne{"Pfund", "aRnoLd", "0646231902", "dany.pfd@gmail.com"},
        Personne{"Hindi", "Hassane", "0646231902", "rppalestine@gmail.com"},
        Personne{"Carrasco", "Eliot", "0646121902", "insectsforlife@gmail.com"},
        Personne{"Machin", "Alexandre", "0646352413", "al@yahoo.fr"}
    };
    
    for( int i = 0; i < vP.size(); i++)
        listePersonnes.Inserer(vP[i]);
    
    LCRendezVous listeRdv{};
    
    vector<RendezVous> vR {
        RendezVous{"Business", Date{16, 3, 2017}, Heure{15, 27}, Heure{17, 30}},
        RendezVous{"Business 6", Date{17, 3, 2017}, Heure{15, 31}, Heure{16,30}},
        RendezVous{"Business 2", Date{17, 3, 2017}, Heure{14, 00}, Heure{15, 30}},
        RendezVous{"Business 3", Date{17, 3, 2017}, Heure{15, 00}, Heure{15, 30}},
        RendezVous{"Business meeting 4", Date{19, 3, 2017}, Heure{14, 00}, Heure{15, 30}},
        RendezVous{"Business meeting 3", Date{18, 3, 2017}, Heure{14, 00}, Heure{15, 30}}
        
    };
    
    for( int i = 0; i < vR.size(); i++)
        listeRdv.InsererRendezVous(vR[i]);
    

    interface inter{listePersonnes, listeRdv};
	inter.menuPrincipal();

//	for(int i = 0; i < vR.size(); i++)
//	{
//		vR[i].afficherRendezVous();
//	}
    
	return 0;

}







