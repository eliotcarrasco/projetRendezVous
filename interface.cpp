#include "interface.h"
#include <iostream>

using namespace std;

interface::interface()
{}

/**
	Affiche le menu principal de l'application
 */
void interface::menuPrincipal()
{
    int i;
    cout << "Gestionnaire de Rendez-Vous : " << endl;
    cout << "Action sur les : " << endl;
    cout << "1. Personnes" << endl;
    cout << "2. Rendez-Vous" << endl;
    cin >> i;
    
    switch(i)
    {
        case 1 :
            menuPersonnes();
            break;
        case 2 :
            menuRendezVous();
            break;
        default :
            cout << "Veuillez selectionner une option valide.";
    }
}

/**
	Affiche le menu de modification des personnes
 */
void interface::menuPersonnes()
{
    int i;
    cout << "Gestion des personnes : " << endl;
    cout << "Veuillez selectionner une action : " << endl;
    cout << "1. Ajouter une personne" << endl;
    cout << "2. Modifier une personne" << endl;
    cout << "3. Supprimer une personne" << endl;
    cin >> i;
}

/**
	Affiche le menu de modification des rendez-vous
 */
void interface::menuRendezVous()
{
    int i;
    cout << "Gestion des rendez-vous : " << endl;
    cout << "Veuillez selectionner une action : " << endl;
    cout << "1. Ajouter un rendez-vous" << endl;
    cout << "2. Modifier un rendez-vous" << endl;
    cout << "3. Supprimer un rendez-vous" << endl;
    cin >> i;
}
