#ifndef INTERFACE_H
#define INTERFACE_H

#include "LCPersonne.h"
#include "LCRendezVous.h"

class interface
{
    public:
        interface();
        void menuPrincipal(LCPersonne &p, LCRendezVous &r);
        void menuPersonnes(LCPersonne &p, LCRendezVous &r);
        void menuRendezVous(LCPersonne &p, LCRendezVous &r);
};

void ajouterPersonne(LCPersonne &p);
void modifierPersonne(LCPersonne &p);

#endif
