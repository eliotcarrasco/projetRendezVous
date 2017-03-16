#include "interface.h"
#include "LCRendezVous.h"
#include "globals.h"
#include <iostream>
#include <string>

using namespace std;

interface::interface()
{}

/**
	Affiche le menu principal de l'application
	@param p - La liste chainee principale des personnes
	@param r - La liste chainee principale des rdv
 */
void interface::menuPrincipal(LCPersonne &p, LCRendezVous &r)
{
    int i;
    cout << "Gestionnaire de Rendez-Vous : " << endl;
    cout << "Action sur les : " << endl;
    cout << "1. Personnes" << endl;
    cout << "2. Rendez-Vous" << endl;
    cout << "0. Quitter" << endl;
    
    do
    {
    	cout << "Choix1 : ";
    	cin >> i;
    	cout << endl;
	    switch(i)
	    {
	        case 1 :
	            menuPersonnes(p, r);
	            break;
	        case 2 :
	            menuRendezVous(p, r);
	            break;
	        case 0 :
	        	break;
	        default :
	            cout << "Veuillez selectionner une option valide." << endl;
	    }
	}
	while( i != 1 && i != 2 && i != 0);
}

/**
	Affiche le menu de modification des personnes
	@param p - La liste chainee principale des personnes
	@param r - La liste chainee principale des rdv
 */
void interface::menuPersonnes(LCPersonne &p, LCRendezVous &r)
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
		        	ajouterPersonne(p);
		        	menuPersonnes(p, r);
		            break;
		        case 2 :
		        	modifierPersonne(p);
		        	menuPersonnes(p, r);
		            break;
		        case 3 :
		        	
		        	menuPersonnes(p, r);
		        	break;
		        case 0 :
		        	menuPrincipal(p, r);
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
	@param p - La liste chainee principale des personnes
	@param r - La liste chainee principale des rdv
 */
void interface::menuRendezVous(LCPersonne &p, LCRendezVous &r)
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
		    		
		    		menuRendezVous(p, r);
		        	break;
		    	case 2 :
		    		
		    		menuRendezVous(p, r);
		        	break;
		    	case 3 :
		    		
		    		menuRendezVous(p, r);
		    		break;
		   		case 0 :
		    		menuPrincipal(p, r);
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

/**
	Récupère les differentes informations concernant la nouvelle personne a ajouter
	@param p - La liste chainee de personnes
*/
void ajouterPersonne(LCPersonne &p)
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
	
	p.Inserer(Personne{nom, prenom, telephone, mail});
	cout << endl;
}

void modifierPersonne(LCPersonne &p)
{
	string nom, prenom;
	
	cout << "Nom de la personne : ";
	cin >> nom;	

	cout << "Prenom de la personne : ";
	cin >> prenom;
	
	p.Modifier(convertToUpper(nom), convertForName(prenom) );
	cout << endl;
}
