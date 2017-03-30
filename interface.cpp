#include "interface.h"
#include "LCRendezVous.h"
#include "globals.h"
#include "Date.h"
#include "Heure.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>


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
	Affiche le menu principal de l'application
 */
void interface::menuPrincipal()
{
//	system("cls");
    int i;
    cout << "Gestionnaire de Rendez-Vous : " << endl;
    cout << "Action sur les : " << endl;
    cout << "1. Personnes" << endl;
    cout << "2. Rendez-Vous" << endl;
    cout << "0. Quitter" << endl;
    
    do
    {
    	i = testInt("Choix : ");
		cout << endl;
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
	while( i != 0 && i != 1 && i != 2 );
}

/**
	Affiche le menu de modification des personnes
 */
void interface::menuPersonnes()
{
//	system("cls");
    int i;
    cout << "Gestion des personnes : " << endl;
    cout << "Veuillez selectionner une action : " << endl;
    cout << "1. Ajouter une personne" << endl;
    cout << "2. Modifier une personne" << endl;
    cout << "3. Supprimer une personne" << endl;
    cout << "4. Afficher une personne" << endl;
    cout << "5. Verifier si une personne est disponible pour une date et un horaire donne" << endl;
    cout << "6. Afficher les rendez-vous d'une personne" << endl;
    cout << "7. Afficher la liste de toutes les personnes" << endl;
    cout << "0. Retour" << endl;
    
	do
    {
		i = testInt("Choix : ");
		cout << endl;
    	Personne person;
		switch(i)
	    {
	        case 1 :
	        	ajouterPersonne();
//		        	system("PAUSE");
	        	menuPersonnes();
	            break;
	        case 2 :
	        	if (rechercherPersonne(person))
        		{
        			person.afficherPersonne();
        			lcprincp.Modifier(person);	
				}
//					system("PAUSE");
	        	menuPersonnes();
	            break;
	        case 3 :
	        	if (rechercherPersonne(person))
        		{
        			LCRendezVous rdvDePersonne;
        			lcprincr.getRendezVous( rdvDePersonne, person);
        			if( rdvDePersonne.getTete() == nullptr)
        			{
	        			person.afficherPersonne();
                        string rep;
                        cout << "Voulez-vous vraiment supprimer cette personne ? (O/N) ";
                        cin >> rep ;
                        if(rep == "O" || rep == "o")
                        {
                            lcprincp.Supprimer(person);
                        }
                        else
                        	cout << "Suppression annulee" << endl << endl;
					}
					else
						cout << "Suppression impossible : la personne fait partie d'au moins un rdv" << endl << endl;
        		}
//		        	system("PAUSE");
	        	menuPersonnes();
	        	break;
            case 4:
                if(rechercherPersonne(person))
                {
                    person.afficherPersonne();
                }
//					system("PAUSE");
                menuPersonnes();
                break;
	        case 5 :
	        	if( rechercherPersonne(person) )
	        	{
                    cout << "Entrez une date : ";
                    Date date;
                    cin >> date;
                    
                    Heure heureDeb, heureFin;
                    
                    do{
                        cout << "Entrez une heure de debut : ";
                        cin >> heureDeb;
                        
                        cout << "Entrez une heure de fin : ";
                        cin >> heureFin;
                    }
                    while(!horaireValide(heureDeb, heureFin));
                    
                    
				    
	        		LCRendezVous listeRdvDeLaPersonne;
					lcprincr.getRendezVous(listeRdvDeLaPersonne, person);
					if( listeRdvDeLaPersonne.occupee(date, heureDeb, heureFin) )
						cout << "Cette personne est occupee a cette date" << endl << endl;
					else
						cout << "Cette personne n'a rien de prevu pour cette date" << endl << endl;
				}
//					system("PAUSE");
	        	menuPersonnes();
	        	break;
	        case 6 :
	    		{
		    		Personne person;
		    		int cmpt = 1;
		    		if( rechercherPersonne(person) )
		    		{
			    		LCRendezVous rdvperson;
			    		lcprincr.getRendezVous( rdvperson, person);
                        
                        ChainonRdV *tmp = rdvperson.getTete();
                        
                        if(tmp == nullptr) cout << "Aucun rendez-vous de prevu pour cette personne" << endl << endl;
                        while(tmp != nullptr)
                        {
                            cout << "Rendez-vous " << cmpt << " : ";
                            tmp->getRdV().afficherRendezVous();
                            tmp = tmp->getSuiv();
                            cmpt++;
                            cout << endl;
                        }
			    	}
//				    	system("PAUSE");
		    		menuPersonnes();
		    	}
	    		break;
            case 7:
                afficherToutesLesPersonnes();
//					system("PAUSE");
                menuPersonnes();
                break;
	        case 0 :
	        	menuPrincipal();
	        	break;
	        default :
	            cout << "Veuillez selectionner une option valide" << endl;
	    }
	}
	while( i != 0 && i != 1 && i != 2 && i != 3 && i != 4 && i != 5 );
}

/**
	Affiche le menu de modification des rendez-vous
 */
void interface::menuRendezVous()
{
//	system("cls");
    int i;
    cout << "Gestion des rendez-vous : " << endl;
    cout << "Veuillez selectionner une action : " << endl;
    cout << "1. Ajouter un rendez-vous" << endl;
    cout << "2. Modifier un rendez-vous" << endl;
    cout << "3. Supprimer un rendez-vous" << endl;
    cout << "4. Afficher un rendez-vous" << endl;
    cout << "5. Afficher les rendez-vous pour une date donnee" << endl;
    cout << "6. Afficher les participants a un rendez-vous" << endl;
    cout << "7. Afficher la liste de tous les rendez-vous" << endl;
    cout << "0. Retour" << endl;
    
	do
    {	
		i = testInt("Choix : ");
		cout << endl;
		RendezVous rdv;
		switch(i)
		{
	    	case 1 :
	    		ajouterRdv();
//		    		system("PAUSE");
	    		menuRendezVous();
	        	break;
	    	case 2 :
	    		if(rechercherRdv(rdv))
	    		{
	    			modifierRendezVous(rdv);
				}
				menuRendezVous();
//					system("PAUSE");
	        	break;
	    	case 3 :
	    		if(rechercherRdv(rdv))
	    		{
                    
                    string rep;
                    cout << "Voulez-vous vraiment supprimer " << rdv.nom() << " ? (O/N) : ";
                    cin >> rep;
                    if( rep == "O" || rep == "o" )
                    {
                        lcprincr.SupprimerRendezVous(rdv.nom());
                        cout << endl;
                    }
                    else
                        cout << "Suppression annulee" << endl << endl;
				}
//					system("PAUSE");
	    		menuRendezVous();
	    		break;
            case 4:
                if(rechercherRdv(rdv))
                {
                    rdv.afficherRendezVous();
                    afficherParticipants(rdv);
                }
//					system("PAUSE");
                menuRendezVous();
                break;
	    	case 5 :
	    		{
		    		cout << "Entrez la date recherchee : ";
		    		Date rech;
                    cin >> rech;
		    		afficherTousLesRdv(rech);
//			    		system("PAUSE");
		    		menuRendezVous();
	    		}
	    		break;
	    	case 6 :
	    		if( rechercherRdv(rdv) )
	    		{
	    			afficherParticipants(rdv);
				}
//					system("PAUSE");
				menuRendezVous();
	    		break;
            case 7:
                afficherTousLesRdv();
//					system("PAUSE");
                menuRendezVous();
	   		case 0 :
	    		menuPrincipal();
	    		break;
	    	default :
	        	cout << "Veuillez selectionner une option valide." << endl;
		}
	}
	while( i != 0 && i != 1 && i != 2 && i != 3 && i != 4 && i != 5 );
}

/**
	Recupere les differentes informations concernant la nouvelle personne a ajouter
 */
void interface::ajouterPersonne()
{
    string nom, prenom, telephone, mail;
    
    do
    {
        cout << "Nom de la personne : ";
        cin >> nom;
        
        cout << "Prenom de la personne : ";
        cin >> prenom;
    }
    while (!lcprincp.nomPersonneDisponible(nom, prenom));
    
    cout << "Numero de telephone de la personne (sous la forme 0612345678) : ";
    cin >> telephone;
    
    cout << "Mail de la personne : ";
    cin >> mail;
    
    lcprincp.Inserer(Personne{nom, prenom, telephone, mail});    
	cout << "La personne a ete ajoute avec succes" << endl << endl;
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
    cout << endl;
    
    ChainonPersonne* tmp = lcprincp.getTete();
    while(tmp != 0 && (tmp->getPersonne().Nom() != convertToUpper(nom) || tmp->getPersonne().Prenom() != convertForName(prenom) ) )
    {
        tmp = tmp->getSuiv();
    }
    if(tmp != 0)
    {
        person = tmp->getPersonne();
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
	
	do
	{
		cout << "Nom du rendez-vous (exemple_de_nom) : ";
	    cin >> nom;
	    if(!lcprincr.nomRdvDisponible(nom))
	    	cout << "Ce nom de rendez-vous est deja pris" << endl;
	}while( !lcprincr.nomRdvDisponible(nom) );
    
    cout << "Entrez une date : ";
    Date date;
    cin >> date;
    
    cout << "Entrez une heure de debut : ";
    Heure heureDeb;
    cin >> heureDeb;
    
    cout << "Entrez une heure de fin : ";
    Heure heureFin;
    cin >> heureFin;
    
    RendezVous rdv{nom, date, heureDeb, heureFin};
    
    Personne person;
    LCPersonne participants;
    cout << "Combien de participants pour ce rendez-vous? " << endl;
    int nbparticipants = testInt("Nombre de participants : ");
	
	if( nbparticipants > lcprincp.Compter() )
		nbparticipants = lcprincp.Compter();
		
	int i = 0;
	while( i < nbparticipants )
	{
		cout << endl << "Personne " << i+1 << " : " << endl;

		if( rechercherPersonne(person) )
		{
			LCRendezVous listeRdvDuParticipant;
			lcprincr.getRendezVous(listeRdvDuParticipant, person);
			if( !listeRdvDuParticipant.occupee(date, heureDeb, heureFin) )
			{
				rdv.ajouterParticipant(person);
				i++;
			}
			else
			{
				cout << "La personne est deja occupee a ce moment" << endl;
				string ajoutperson;
				do
				{
					cout << "Voulez-vous remplacer cette personne par une autre ? (O/N) : ";
					cin >> ajoutperson;
				}
				while( ajoutperson != "O" && ajoutperson != "o" && ajoutperson != "N" && ajoutperson != "n");
				if( ajoutperson == "N" || ajoutperson == "n" )
					i++;
			}
		}
	}
    
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
    cout << "Nom du rendez-vous (exemple_de_nom) : ";
    cin >> nom;
    
    ChainonRdV *tmp = lcprincr.getTete();
    while(tmp != 0 && tmp->getRdV().nom() != nom)
    {
        tmp = tmp->getSuiv();
    }
    if(tmp)
    {
        rdv = tmp->getRdV();
        return true;
    }
    cout << "Ce rendez-vous n'existe pas" << endl << endl;
    return false;
}



/**
    Afficher touts les rendez-vous de la liste principale
 */
void interface::afficherTousLesRdv()
{
    ChainonRdV* tmp = lcprincr.getTete();
    while(tmp)
    {
        tmp->getRdV().afficherRendezVous();
        tmp = tmp->getSuiv();
    }
}



/**
    Affiche tous les rdv pour une date donnee
    @param d - une date
 */
void interface::afficherTousLesRdv(Date d)
{
    ChainonRdV* tmp = lcprincr.getTete();
    
    bool rdv = false;
    
    while(tmp != 0 && tmp->getRdV().date() <= d ) //puisque les rdv sont classes par ordre chronologique
    {
        if(tmp->getRdV().date() == d)
        {
            rdv = true;
            tmp->getRdV().afficherRendezVous();
            
            afficherParticipants(tmp->getRdV());
        }
        tmp = tmp->getSuiv();
    }
    
    if(!rdv)
    {
        cout << "Aucun rendez-vous pour cette date.";
    }
}

/**
    Affiche tous les participants a un rendez-vous
    @param rdv - un rendez-vous
 */
void interface::afficherParticipants(RendezVous &rdv)
{
    if(rdv.nombreParticipants() == 0)
    {
        cout << "Aucun participant pour ce rendez-vous" << endl << endl;
    }
    else{
        
        cout << "Liste des participants a ce rendez-vous : " << endl << endl;
    
        vector<int> vPart = rdv.listeParticipants();
        
        for (int i = 0; i < vPart.size(); i++)
            lcprincp.getPersonneById(vPart[i]).afficherPersonne();

    }
}

/**
	Modifie un rendez-vous
	@param rdv - un rendez-vous
*/
void interface::modifierRendezVous(RendezVous& rdv)
{
	ChainonRdV* tmp = lcprincr.getTete();
	while(tmp != nullptr && tmp->getRdV() != rdv)
		tmp = tmp->getSuiv();
		
	if(tmp->getRdV() == rdv)
	{
//		system("cls");
		int i = -1;
        
            cout << "1. Afficher les informations du rendez-vous" << endl;
			cout << "2. Modifier la date" << endl;
			cout << "3. Modifier l'heure de debut" << endl;
			cout << "4. Modifier l'heure de fin" << endl;
			cout << "5. Ajouter un participant" << endl;
			cout << "6. Supprimer un participant" << endl;
			cout << "0. Retour" << endl;
		
        do
        {
            i = testInt("Choix : ");
            cout << endl;
            switch(i)
            {
                case 1:
                {
                    tmp->getRdV().afficherRendezVous();
                    afficherParticipants(tmp->getRdV());
//					system("PAUSE");
                    modifierRendezVous(tmp->getRdV());
                    break;
                    
                }
                case 2:
                {
                    cout << "Entrez la nouvelle date (jj/mm//2017+): ";
                    Date date;
                    cin >> date;
                    cout << "La date a bien ete modifiee" << endl << endl;
                    tmp->getRdV().setDate(date);
//					system("PAUSE");
                    modifierRendezVous(tmp->getRdV());
                    break;
                }
                case 3:
                {
                    cout << "Entrez la nouvelle heure de debut (hh:mm) : ";
                    Heure heureDeb;
                    cin >> heureDeb;
                    
                    while(!horaireValide(heureDeb, tmp->getRdV().heureFin()))
                    {
                        cout << "Heure de fin : " << tmp->getRdV().heureFin() << endl << "Reessayer : ";
                        cin >> heureDeb;
                    }
                          
                    cout << "L'heure de debut a bien ete modifiee" << endl << endl;
                    tmp->getRdV().setHeureDeb(heureDeb);
//					system("PAUSE");
                    modifierRendezVous(tmp->getRdV());
                    break;
                }
                case 4:
                {
                    cout << "Entrez la nouvelle heure de fin (hh:mm) : ";
                    Heure heureFin;
                    cin >> heureFin;
                    
                    while(!horaireValide(tmp->getRdV().heureDeb(), heureFin))
                    {
                        cout << "Heure de debut : " << tmp->getRdV().heureDeb() << endl << "Reessayer : ";
                        cin >> heureFin;
                    }
                    
                    cout << "L'heure de fin a bien ete modifiee" << endl << endl;
                    tmp->getRdV().setHeureFin(heureFin);
//					system("PAUSE");
                    modifierRendezVous(tmp->getRdV());
                    break;
                }
                case 5:
                {
                    Personne ajout;
                    if( rechercherPersonne(ajout) )
                    {
                        LCRendezVous rdvparticipants;
                        lcprincr.getRendezVous(rdvparticipants, ajout);
                        if( !rdvparticipants.occupee( tmp->getRdV().date(), tmp->getRdV().heureDeb(), tmp->getRdV().heureFin() ) )
                        {
                            tmp->getRdV().ajouterParticipant(ajout);
                            cout << "Participant ajoute" << endl << endl;
                        }
                        else
                            cout << "Cette personne est deja occupee et ne peut donc pas etre ajoutee" << endl << endl;
                    }
//						system("PAUSE");
                    modifierRendezVous(tmp->getRdV());
                    break;
                }
                case 6:
                {
                    afficherParticipants(tmp->getRdV());
                    
                    if(tmp->getRdV().nombreParticipants() != 0)
                    {
                        Personne suppr;
                        if( rechercherPersonne(suppr) )
                        {
                            string rep;
                            cout << "Voulez-vous vraiment supprimer " << suppr.Nom() << " " << suppr.Prenom() << " ? (O/N) : ";
                            cin >> rep;
                            if( rep == "O" || rep == "o" )
                            {
                                tmp->getRdV().supprimerParticipant(suppr);
                                cout << "Participant supprime" << endl << endl;
                            }
                            else
                                cout << "Suppression annulee" << endl << endl;
                        }

                    }
//						system("PAUSE");
                    modifierRendezVous(tmp->getRdV());
                    break;
                }
                case 0:
                    break;
                default:
                	cout << "Veuillez selectionner une option valide" << endl;
                    break;
            }
        }
        while(i > 6 || i < 0);
			
	}
	
}

/**
    Afficher toutes les personnes de la liste principale
 */
void interface::afficherToutesLesPersonnes()
{
    ChainonPersonne* tmp = lcprincp.getTete();
    while(tmp)
    {
        tmp->getPersonne().afficherPersonne();
        tmp = tmp->getSuiv();
    }
}


/**
	Test si ce que l'utilisateur a rentre est bien un entier
	@param s - La chaine de caractere que l'on veut afficher avant la saisie
	@return L'entier saisie
*/
int interface::testInt(const string& s)
{
	int i;
	do
    {
	    cout << s;
	    cin >> i;
		if( cin.fail() )
	    {
			cin.clear();
			cin.ignore(256,'\n');
			i = -1;
		}
	}
	while( i == -1 );
	return i;
}



/**
    Verifie si un horaire entre une heure de debut et une heure de fin est valide
 */
bool interface::horaireValide(const Heure &heureDeb, const Heure &heureFin)
{
    if(heureDeb>=heureFin)
    {
        cout << "L'horaire n'est pas valide" << endl;
        return false;
    }
    return true;
}

