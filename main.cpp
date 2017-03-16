#include <iostream>
#include "interface.h"
#include "LCPersonne.h"
#include "LCRendezVous.h"
#include "Personne.h"
#include <vector>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	//interface inter;
    
    // Creation des listes principales
    LCPersonne listePersonnes{};
    //LCRendezVous listeRdv{};
    
//        vector<Personne> vP {
//            Personne{"Pfund", "Daniel", "dany.pfd@gmail.com", "0646231902"},
//            Personne{"Machin", "Alexandre", "al@yahoo.fr", "0646352413"},
//            Personne{"Hindi", "Hassane", "rppalestine@gmail.com", "0646231902"},
//            Personne{"Carrasco", "Eliot", "insectsforlife@gmail.com", "0646121902"},
//        };
//    
//        for( int i = 0; i < vP.size(); i++)
//            listePersonnes.Inserer(vP[i]);
//    
//        ChainonPersonne* tmp = listePersonnes.getTete();
//    
//        while(tmp != 0)
//            cout << "Test $$$$$$" << tmp->p.Nom() << endl;

    Personne p{"Pfund", "Daniel", "dany.pfd@gmail.com", "0646231902"};
    
    cout << p.Nom() << endl;
    

    
    listePersonnes.Inserer(p);
//    listePersonnes.Inserer(Personne{"Machin", "Alexandre", "al@yahoo.fr", "0646352413"});
    
    
    
    
    
	// Lecture du fichier contenant les listes
	//inter.menuPrincipal(listePersonnes, listeRdv);
	return 0;
}


