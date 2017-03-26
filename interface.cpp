#include "interface.h"
#include "LCRendezVous.h"
#include "globals.h"
#include "Date.h"
#include "Heure.h"
#include <iostream>
#include <string>

using namespace std;


/**
    Constructeur vide
 */
interface::interface() :lcprincp{}, lcprincr{}
{}

/**
    Constructeur
 */
interface::interface(LCPersonne &listePersonnes, LCRendezVous &listeRdv) : lcprincp{listePersonnes}, lcprincr{listeRdv}
{}


/**
	Recupere les differentes informations concernant la nouvelle personne a ajouter
 */

void interface::ajouterPersonne()
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
    
    lcprincp.Inserer(Personne{nom, prenom, telephone, mail});    
	cout << /*"La personne a ete ajoute avec succes" << endl <<*/ endl;
}

/**
	Regarde a partir du nom et du prenom si la personne recherchee existe
	@param person - La personne recherchee (intialement vide puis remplit grace a cette fonction)
	@return Vrai si la personne existe, Faux sinon
 */
bool interface::rechercherPersonne(Personne& person)
{
    string nom, prenom;
    
    cout << "Nom de la personne : ";
    cin >> nom;
    
    cout << "Prenom de la personne : ";
    cin >> prenom;
    
    ChainonPersonne* tmp = lcprincp.getTete();
    while(tmp != 0 && (tmp->prsn.Nom() != convertToUpper(nom) || tmp->prsn.Prenom() != convertForName(prenom) ) )
    {
        tmp = tmp->suiv;
    }
    if(tmp != 0)
    {
        person = tmp->prsn;
        return true;
    }
    cout << "Cette personne n'existe pas" << endl << endl;
    return false;
}

/**
	Recupere les differentes informations concernant le nouveau rdv a ajouter
 */
void interface::ajouterRdv()
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
    Date date{j, m, a};
    
    cout << "Horaire du debut : " << endl << "	Heure : ";
    cin >> hdeb;
    cout << "	Minute : ";
    cin >> mindeb;
    Heure heuredeb{hdeb, mindeb};
    
    cout << "Horaire de fin : " << endl << "	Heure : ";
    cin >> hfin;
    cout << "	Minute : ";
    cin >> minfin;
    Heure heurefin{hfin, minfin};
    
    RendezVous rdv{nom, date, heuredeb, heurefin};
    
    //manque l'ajout des particiapants (ne pas oublier de verifier les disponibilité de chaques participants)
    Personne person;
    LCPersonne participants;
    int nbparticipants;
    cout << "Combien de participants pour ce rendez-vous? " << endl;
    do
    {
    	cout << "Nombre de participants : ";
	    cin >> nbparticipants;
    	if( cin.fail() )
    	{
	    	cin.clear();
			cin.ignore(256,'\n');
			nbparticipants = -1;
		}
	}while( nbparticipants <= -1 );
	if( nbparticipants > lcprincp.Compter() )
		nbparticipants = lcprincp.Compter();
	int i = 0;
	do
	{
		cout << endl << "Personne " << i+1 << " : " << endl;

		if( rechercherPersonne(person) )
		{
			cout << "Personne trouve" << endl;
			LCRendezVous listeRdvDuParticipant;
			lcprincr.getRendezVous(listeRdvDuParticipant, person);
			if( !listeRdvDuParticipant.occupee(date, heuredeb, heurefin) )
			{
				rdv.ajouterParticipant(person);
				i++;
			}
			else
			{
				cout << "La personne est deja occupe a ce moment" << endl;
			}
		}
	}
	while( i != nbparticipants );
    
    lcprincr.InsererRendezVous(rdv);
    
    cout << "Rendez-vous ajoute avec succees" << endl << endl;
}

/**
	Regarde a partir du nom si le rdv rechercher existe
	@param rdv - Le rdv recherche (initialement vide puis rempli grace a cette fonction)
	@return Vrai si le rdv existe, Faux sinon
 */
bool interface::rechercherRdv(RendezVous &rdv)
{
    string nom;
    cout << "Nom du rendez-vous : ";
    cin >> nom;
    
    ChainonRdV *tmp = lcprincr.getTete();
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
    Affiche tous les rdv pour une date donnee
    @param d - une date
 */
void interface::afficherTousLesRdv(Date d)
{
    ChainonRdV* tmp = lcprincr.getTete();
    
    bool rdv = false;
    
    while(tmp != 0 && tmp->RdV.date() <= d ) //puisque les rdv sont classes par ordre chronologique
    {
        if(tmp->RdV.date() == d)
        {
            rdv = true;
            //afficher tmp->RdV
            cout << "Nom du rendez-vous : " << tmp->RdV.nom() << endl;
            cout << "Heure de debut : " << tmp->RdV.heureDeb().getStringHeure() << endl;
            cout << "Heure de fin : " << tmp->RdV.heureFin().getStringHeure() <<endl;
            
            afficherParticipants(tmp->RdV);
        }
        tmp = tmp->suiv;
    }
    
    if(!rdv)
    {
        cout << "Aucun rendez-vous pour cette date.";
    }
}


/**
    Affiche tous les participants a un rendez-vous
 */
void interface::afficherParticipants(RendezVous &rdv)
{
    vector<int> vPart = rdv.listeParticipants();
    
    for (int i = 0; i < vPart.size(); i++)
    {
        lcprincp.getPersonneById(vPart[i]).afficherPersonne();
    }
}

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
    cout << "0. Quitter" << endl;
    
    do
    {
    	cout << "Choix : ";
    	cin >> i;
    	cout << endl;
		if( !cin.fail() )
		{   
		    switch(i)
		    {
		        case 1 :
		            menuPersonnes();
		            break;
		        case 2 :
		            menuRendezVous();
		            break;
		        case 0 :
		        	break;
		        default :
		            cout << "Veuillez selectionner une option valide." << endl;
		    }
		}
		else
		{
			cin.clear();
			cin.ignore(256,'\n');
			i = -1;
		}
	}
	while( i != 0 && i != 1 && i != 2 );
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
    cout << "4. Voir si une personne a un rendez-vous prevu a une certaine date" << endl;
    cout << "0. Retour" << endl;
    
	do
    {
    	cout << "Choix : ";
    	cin >> i;
    	cout << endl;
    	Personne person;
    	if( !cin.fail() )
    	{
    		switch(i)
		    {
		        case 1 :
		        	ajouterPersonne();
		        	menuPersonnes();
		            break;
		        case 2 :
		        	if (rechercherPersonne(person))
		        		{
		        			person.afficherPersonne();
		        			lcprincp.Modifier(person);	
						}
		        	menuPersonnes();
		            break;
		        case 3 :
		        	if (rechercherPersonne(person)) //penser a verifier que la personne n'a pas de rdv avant de la supprimer -->
		        		{
		        			person.afficherPersonne();
							lcprincp.Supprimer(person);
		        		}
		        	menuPersonnes();
		        	break;
		        case 4 :
		        	
		        	menuPrincipal();
		        	break;
		        case 0 :
		        	menuPrincipal();
		        	break;
		        default :
		            cout << "Veuillez selectionner une option valide" << endl;
		    }
		}
		else
		{
			cin.clear();
			cin.ignore(256,'\n');
			i = -1;
			
		}
	    
	}
	while( i != 0 && i != 1 && i != 2 && i != 3 && i != 4 );
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
		    		ajouterRdv();
		    		menuRendezVous();
		        	break;
		    	case 2 :
		    		if(rechercherRdv(rdv))
		    		{
		    			
					}
		    		menuRendezVous();
		        	break;
		    	case 3 :
		    		if(rechercherRdv(rdv))
		    		{
		    		
					}
		    		menuRendezVous();
		    		break;
		    	case 4 :
		    		{
			    		int jour, mois, annee;
			    		cout << "Entrez la date recherchee : " << endl;
			    		cout << "Jour : ";
			    		cin >> jour;
			    		cout << "Mois : ";
			    		cin >> mois;
			    		cout << "Annee : ";
			    		cin >> annee;
			    		Date rech{jour, mois, annee};
			    		afficherTousLesRdv(rech);
			    		menuRendezVous();
		    		}
		    	case 5 :
		    		
		    		menuRendezVous();
		    	case 6 :
		    		
		    		menuRendezVous();
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
			i = -1;
		}
	}
	while( i != 0 && i != 1 && i != 2 && i != 3 && i != 4 && i != 5 && i != 6 );
}


