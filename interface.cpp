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
//	system("cls");
    int i;
    cout << "Gestion des personnes : " << endl;
    cout << "Veuillez selectionner une action : " << endl;
    cout << "1. Ajouter une personne" << endl;
    cout << "2. Modifier une personne" << endl;
    cout << "3. Supprimer une personne" << endl;
    cout << "4. Voir si une personne a un rendez-vous prevu a une date et un horaire donne" << endl;
    cout << "5. Afficher les rendez-vous d'une personne" << endl;
    cout << "6. Afficher la liste des personnes" << endl;
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
							lcprincp.Supprimer(person);
						}
						else
							cout << "Suppression impossible : la personne fait partie d'au moins un rdv" << endl << endl;
	        		}
//		        	system("PAUSE");
		        	menuPersonnes();
		        	break;
		        case 4 :
		        	if( rechercherPersonne(person) )
		        	{
		        		int jour, mois, annee, hdeb, mindeb, hfin, minfin;
					    
					    jour = testInt("Jour (1-31) : ");
						mois = testInt("Mois (1-12) : ");
						annee = testInt("Annee (ex : 2017) : ");
					    Date date{jour, mois, annee};
					    
					    cout << "Horaire du debut : " << endl;
						hdeb = testInt("	Heure : ");
						mindeb = testInt("	Minute : ");
					    Heure heuredeb{hdeb, mindeb};
					    
					    cout << "Horaire de fin : " << endl;
						hfin = testInt("	Heure : ");
						minfin = testInt("	Minute : ");
					    Heure heurefin{hfin, minfin};
					    
		        		LCRendezVous listeRdvDeLaPersonne;
						lcprincr.getRendezVous(listeRdvDeLaPersonne, person);
						if( listeRdvDeLaPersonne.occupee(date, heuredeb, heurefin) )
							cout << "Cette personne est occupee a cette date" << endl << endl;
						else
							cout << "Cette personne n'a rien de prevu pour cette date" << endl << endl;
					}
//					system("PAUSE");
		        	menuPersonnes();
		        	break;
		        case 5 :
		    		{
			    		Personne person;
			    		int cmpt = 1;
			    		if( rechercherPersonne(person) )
			    		{
				    		LCRendezVous rdvperson;
				    		lcprincr.getRendezVous( rdvperson, person);
				    		ChainonRdV *tmp = rdvperson.getTete();
				    		while(tmp != nullptr)
				    		{
				    			cout << "Rendez-vous " << cmpt << " : ";
				    			tmp->RdV.afficherRendezVous();
				    			tmp = tmp->suiv;
				    			cmpt++;
				    			cout << endl;
							}
				    	}
//				    	system("PAUSE");
			    		menuRendezVous();
			    	}
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
    cout << "4. Afficher les rendez-vous pour une date donnee" << endl;
    cout << "5. Afficher les participants a un rendez-vous" << endl;
    cout << "0. Retour" << endl;
    
	do
    {	
		cout << "Choix : ";
		cin >> i;
		cout << endl;
		RendezVous rdv;
		if( !cin.fail() )
		{
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
//					system("PAUSE");
		    		menuRendezVous();
		        	break;
		    	case 3 :
		    		if(rechercherRdv(rdv))
		    		{
		    			lcprincr.SupprimerRendezVous(rdv.nom());
					}
//					system("PAUSE");
		    		menuRendezVous();
		    		break;
		    	case 4 :
		    		{
			    		int jour, mois, annee;
			    		cout << "Entrez la date recherchee : " << endl;
						jour = testInt("Jour : ");
						mois = testInt("Mois : ");
						annee = testInt("Annee : ");
			    		Date rech{jour, mois, annee};
			    		afficherTousLesRdv(rech);
//			    		system("PAUSE");
			    		menuRendezVous();
		    		}
		    		break;
		    	case 5 :
		    		if( rechercherRdv(rdv) )
		    		{
		    			afficherParticipants(rdv);
					}
//					system("PAUSE");
					menuRendezVous();
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
			i = -1;
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
    
    cout << "Nom de la personne : ";
    cin >> nom;
    
    cout << "Prenom de la personne : ";
    cin >> prenom;
    
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
	
	do
	{
		cout << "Nom du rendez-vous : ";
	    cin >> nom;
	    if(!lcprincr.nomRdvDisponible(nom))
	    	cout << "Ce nom de rendez-vous est deja pris" << endl;
	}while( !lcprincr.nomRdvDisponible(nom) );
    
    j = testInt("Jour (1-31) : ");
    m = testInt("Mois (1-12) : ");
    a = testInt("Annee (ex : 2017) : ");
    Date date{j, m, a};
    
    cout << "Horaire du debut : " << endl;
    hdeb = testInt( "	Heure : ");
    mindeb = testInt("	Minute : ");
    Heure heuredeb{hdeb, mindeb};
    
    cout << "Horaire de fin : " << endl;
	hfin = testInt("	Heure : ");
    minfin = testInt("	Minute : ");
    Heure heurefin{hfin, minfin};
    
    RendezVous rdv{nom, date, heuredeb, heurefin};
    
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
			if( !listeRdvDuParticipant.occupee(date, heuredeb, heurefin) )
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
    cout << "Nom du rendez-vous : ";
    cin >> nom;
    
    ChainonRdV *tmp = lcprincr.getTete();
    while(tmp != 0 && tmp->RdV.nom() != nom)
    {
        tmp = tmp->suiv;
    }
    if(tmp)
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


void interface::modifierRendezVous(RendezVous& rdv)
{
	ChainonRdV* tmp = lcprincr.getTete();
	while(tmp != nullptr && tmp->RdV != rdv)
		tmp = tmp->suiv;
		
	if(tmp->RdV == rdv)
	{
		int i = -1;
		do
		{
			cout << "1. Modifier la date" << endl;
			cout << "2. Modifier l'heure de debut" << endl;
			cout << "3. Modifier l'heure de fin" << endl;
			cout << "4. Ajouter un participant" << endl;
			cout << "5. Supprimer un participant" << endl;
			cout << "0. Retour" << endl;
			cin >> i;
		}
		while(i > 5 || i < 0);
			
		switch(i)
		{
			case 1:
				int jour, mois, annee;
		    	cout << "Entrez la nouvelle date : " << endl;
				jour = testInt("Jour : ");
				mois = testInt("Mois : ");
				annee = testInt("Annee : ");
		    	tmp->RdV.setDate({jour, mois, annee});
		    	break;
			case 2:
				int heureDeb, minutesDeb;
				cout << "Entrez la nouvelle heure :";
				heureDeb = testInt("Heure : ");
				minutesDeb = testInt("Minutes : ");
				tmp->RdV.setHeureDeb({heureDeb, minutesDeb});
				break;
			case 3:
				int heureFin, minutesFin;
				cout << "Entrez la nouvelle heure :";
				heureFin = testInt("Heure : ");
				minutesFin = testInt("Minutes : ");
				tmp->RdV.setHeureFin({heureFin, minutesFin});
				break;
			case 4:
				{
					Personne ajout;
					if( rechercherPersonne(ajout) )
					{
						LCRendezVous rdvparticipants;
						lcprincr.getRendezVous(rdvparticipants, ajout);
						if( !rdvparticipants.occupee( tmp->RdV.date(), tmp->RdV.heureDeb(), tmp->RdV.heureFin() ) )
						{
							tmp->RdV.ajouterParticipant(ajout);
							cout << "Participant ajoute" << endl << endl;
						}
						else
							cout << "Cette personne est occupee et ne peut donc pas etre ajoutee" << endl << endl;
					}	
					break;
				}
				
			case 5:
				{
					Personne suppr;
					if( rechercherPersonne(suppr) )
					{
						tmp->RdV.supprimerParticipant(suppr);
						cout << "Participant supprime" << endl << endl;
					}
					break;
				}
			case 0:
				//retour en arriere
				break;
			default:
				break;
		}
			
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

