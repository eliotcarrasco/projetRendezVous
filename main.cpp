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
        RendezVous{"Business_6", Date{17, 3, 2017}, Heure{15, 31}, Heure{16,30}},
        RendezVous{"Business_2", Date{17, 3, 2017}, Heure{14, 00}, Heure{15, 30}},
        RendezVous{"Business_3", Date{17, 3, 2017}, Heure{15, 00}, Heure{15, 30}},
        RendezVous{"Business_meeting_4", Date{19, 3, 2017}, Heure{14, 00}, Heure{15, 30}},
        RendezVous{"Business_meeting_3", Date{18, 3, 2017}, Heure{14, 00}, Heure{15, 30}}
        
    };
    
    for( int i = 0; i < vR.size(); i++)
        listeRdv.InsererRendezVous(vR[i]);

    interface inter{listePersonnes, listeRdv};
	inter.menuPrincipal();
    
	return 0;

}







