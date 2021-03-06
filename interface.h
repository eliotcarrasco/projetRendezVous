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
        void modifierRendezVous(RendezVous& rdv);
    
        void afficherTousLesRdv(Date d);
        void afficherTousLesRdv();
        void afficherToutesLesPersonnes();
        void afficherParticipants(RendezVous &rdv);
    
    
        int testInt(const std::string& s);
        bool horaireValide(const Heure &heureDeb, const Heure &heureFin);
    
    private:
        LCPersonne lcprincp;
        LCRendezVous lcprincr;
};



#endif
