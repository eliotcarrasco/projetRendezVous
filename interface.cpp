#include "interface.h"
#include "LCRendezVous.h"
#include <iostream>
#include <string>

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
    
    do
    {
    	cout << "Choix1 : ";
    	cin >> i;
    	cout << endl;
	    switch(i)
	    {
	        case 1 :
	            menuPersonnes();
	            break;
	        case 2 :
	            menuRendezVous();
	            break;
	        default :
	            cout << "Veuillez selectionner une option valide." << endl;
	    }
	}
	while( i != 1 && i != 2);
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
    cout << "0. Retour" << endl;
    
	do
    {
    	cout << "Choix2 : ";
    	cin >> i;
    	cout << endl;
    	if( !cin.fail() )
    	{
    		switch(i)
		    {
		        case 1 :
		        	ajouterPersonne();
		            break;
		        case 2 :
		        	
		            break;
		        case 3 :
		        	
		        	break;
		        case 0 :
		        	menuPrincipal();
		        	break;
		        default :
		            cout << "Veuillez selectionner une option valide." << endl;
		    }
		}
		else
		{
			cin.clear();
			cin.ignore(256,'\n');
			
		}
	    
	}
	while( i != 1 && i != 2 && i != 3 && i != 0);
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
    cout << "0. Retour" << endl;
    
	do
    {	
		cout << "Choix2 : ";
		cin >> i;
		cout << endl;
		if( !cin.fail() )
		{
			switch(i)
			{
		    	case 1 :
		    		
		        	break;
		    	case 2 :
		    		
		        	break;
		    	case 3 :
		    		
		    		break;
		   		case 0 :
		    		menuPrincipal();
		    		break;
		    	default :
		        	cout << "Veuillez selectionner une option valide." << endl;
			}
		}
		else
		{
			cin.clear();
			cin.ignore(256,'\n');
			
		}
	}
	while( (i != 1 && i != 2 && i != 3 && i != 0) || (cin.fail()));
}

void ajouterPersonne()
{
	string nom, prenom, telephone, mail;
	cout << "Nom de la personne : ";
	cin >> nom;	

	cout << "Prenom de la personne : ";
	cin >> prenom;
	
	cout << "Numero de telephone de la personne (sous la forme 0612345678) : ";
	cin >> telephone;
	
	cout << "Mail de la personne : ";
	cin >> mail;
	//Personne(nom, prenom, telephone, mail);
}
