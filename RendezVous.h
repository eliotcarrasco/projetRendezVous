#ifndef RENDEZVOUS_H
#define RENDEZVOUS_H
#include <string>
#include "Date.h"
#include "Heure.h"
#include "LCPersonne.h"
#include "Personne.h"

using namespace std;

class RendezVous
{
	public:
        RendezVous();
		RendezVous(const string& nom, Date date, Heure heureDeb, Heure heureFin);
        ~RendezVous();
    
        // getters
        string nom() const;
        Date date() const;
        Heure heureDeb() const;
        Heure heureFin() const;
        LCPersonne& listeParticipants();
    
        //setters
        void setNom(const string& nom);
        void setDate(const Date& date);
        void setHeureDeb(const Heure& heureDeb);
        void setHeureFin(const Heure& heureFin);
        void setHeure(const Heure& heureDeb, const Heure& heureFin);
    
        void ajouterParticipant(const Personne& pers);
        void supprimerParticipant(const Personne& pers);
        int nombreParticipants() const;
        void afficherParticipants() const;
        
        //manque les surcharges d'operateurs pour utiliser les fonction modifier et supprimer de LCRendezVous avec des rdv
    

	private:
		string d_nom;
		Date d_date;
		Heure d_heureDeb;
		Heure d_heureFin;
        LCPersonne d_participants;
		
};

#endif
