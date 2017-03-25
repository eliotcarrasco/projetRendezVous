#ifndef INTERFACE_H
#define INTERFACE_H

#include "LCPersonne.h"
#include "LCRendezVous.h"

class interface
{
    public:
        interface();
        interface(LCPersonne &listePersonnes, LCRendezVous &listeRdv);
        void menuPrincipal();
        void menuPersonnes();
        void menuRendezVous();
    
        void ajouterPersonne();
        bool rechercherPersonne(Personne &person);
        void ajouterRdv();
        bool rechercherRdv(RendezVous &rdv);
        void afficherTousLesRdv(Date d);
        void afficherParticipants(RendezVous &rdv);
    
    private:
        LCPersonne p;
        LCRendezVous r;
};



#endif
