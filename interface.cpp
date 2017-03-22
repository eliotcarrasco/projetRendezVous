#include "interface.h"
#include "LCRendezVous.h"
#include "globals.h"
#include "Date.h"
#include "Heure.h"
#include <iostream>
#include <string>

using namespace std;

interface::interface()
{}

/**
	Recupere les differentes informations concernant la nouvelle personne a ajouter
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

/**
	Regarde a partir du nom et du prenom si la personne rechercher existe
	@param p - Liste de personne existante dans le programme
	@parma person - La personne recherchee (intialement vide puis remplit grace a cette fonction)
	@return Vrai si la personne existe, Faux sinon
 */
bool rechercherPersonne(LCPersonne &p, Personne& person)
{
    string nom, prenom;
    
    cout << "Nom de la personne : ";
    cin >> nom;
    
    cout << "Prenom de la personne : ";
    cin >> prenom;
    
    ChainonPersonne* tmp = p.getTete();
    while(tmp != 0 && tmp->p.Nom() != convertToUpper(nom) && tmp->p.Prenom() != convertForName(prenom) )
    {
        tmp = tmp->suiv;
    }
    if(tmp != 0)
    {
        person = tmp->p;
        return true;
    }
    cout << "Cette personne n'existe pas" << endl << endl;
    return false;
}

/**
	Recupere les differentes informations concernant le nouveau rdv a ajouter
	@param r - La liste chainee des rdv
 */
void ajouterRdv(LCPersonne &p, LCRendezVous &r)
{
    string nom;
    int j, m, a, hdeb, mindeb, hfin, minfin;
    
    cout << "Nom du rendez-vous : ";
    cin >> nom;
    
    cout << "Jour (1-31) : ";
    cin >> j;
    cout << "Mois (1-12) : ";
    cin >> m;
    cout << "Annee (ex : 2017) : ";
    cin >> a;
    
    cout << "Horaire du debut : " << endl << "	Heure : ";
    cin >> hdeb;
    cout << "	Minute : ";
    cin >> mindeb;
    
    cout << "Horaire de fin : " << endl << "	Heure : ";
    cin >> hfin;
    cout << "	Minute : ";
    cin >> minfin;
    
    //manque l'ajout des particiapants (ne pas oublier de verifier les disponibilité de chaques participants)
    
    RendezVous rdv{nom, Date{j, m, a}, Heure{hdeb, mindeb}, Heure{hfin, minfin}};
    r.InsererRendezVous(rdv);
    
    cout << "Rendez-vous ajoute avec succees" << endl << endl;
}

/**
	Regarde a partir du nom si la rdv rechercher existe
	@param r - Liste de rdv existante dans le programme
	@parma rdv - Le rdv recherchee (intialement vide puis remplit grace a cette fonction)
	@return Vrai si le rev existe, Faux sinon
 */
bool rechercherRdv(LCRendezVous &r, RendezVous &rdv)
{
    string nom;
    cout << "Nom du rendez-vous : ";
    cin >> nom;
    
    ChainonRdV *tmp = r.getTete();
    while(tmp != 0 && tmp->RdV.nom() != nom)
    {
        tmp = tmp->suiv;
    }
    if(tmp != 0)
    {
        rdv = tmp->RdV;
        return true;
    }
    cout << "Ce rendez-vous n'existe pas" << endl << endl;
    return false;
}

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
    	cout << "Choix : ";
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
	while( i != 0 && i != 1 && i != 2 );
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
    cout << "4. Voir si une personne a un rendez-vous prevu a une certaine date";
    cout << "0. Retour" << endl;
    
	do
    {
    	cout << "Choix : ";
    	cin >> i;
    	cout << endl;
    	Personne prsn;
    	if( !cin.fail() )
    	{
    		switch(i)
		    {
		        case 1 :
		        	ajouterPersonne(p);
		        	menuPersonnes(p, r);
		            break;
		        case 2 :
		        	if (rechercherPersonne(p, prsn))
		        		{
		        			prsn.afficherPersonne();
		        			p.Modifier(prsn);	
						}
		        	menuPersonnes(p, r);
		            break;
		        case 3 :
		        	if (rechercherPersonne(p, prsn)) //penser a verifier que la personne n'a pas de rdv avant de la supprimer -->
		        		{
		        			prsn.afficherPersonne();
							p.Supprimer(prsn);
		        		}
		        	menuPersonnes(p, r);
		        	break;
		        case 4 :
		        	
		        	menuPrincipal(p, r);
		        	break;
		        case 0 :
		        	menuPrincipal(p, r);
		        	break;
		        default :
		            cout << "Veuillez selectionner une option valide" << endl;
		    }
		}
		else
		{
			cin.clear();
			cin.ignore(256,'\n');
			
		}
	    
	}
	while( i != 0 && i != 1 && i != 2 && i != 3 && i != 4 );
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
    cout << "4. Afficher les rendez-vous pour une date donee" << endl;
    cout << "5. Afficher les rendez-vous d'une personne" << endl;
    cout << "6. Afficher les participants a un rendez-vous" << endl;
    cout << "0. Retour" << endl;
    
	do
    {	
		cout << "Choix2 : ";
		cin >> i;
		cout << endl;
		RendezVous rdv;
		if( !cin.fail() )
		{
			switch(i)
			{
		    	case 1 :
		    		ajouterRdv(p, r);
		    		menuRendezVous(p, r);
		        	break;
		    	case 2 :
		    		if(rechercherRdv(r, rdv))
		    		{
		    			
					}
		    		menuRendezVous(p, r);
		        	break;
		    	case 3 :
		    		if(rechercherRdv(r, rdv))
		    		{
		    		
					}
		    		menuRendezVous(p, r);
		    		break;
		    	case 4 :
		    		
		    		menuRendezVous(p, r);
		    	case 5 :
		    		
		    		menuRendezVous(p, r);
		    	case 6 :
		    		
		    		menuRendezVous(p, r);
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
	while( (i != 0 && i != 1 && i != 2 && i != 3 && i != 4 && i != 5 && i != 6 ) || (cin.fail()));
}


