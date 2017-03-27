#ifndef RENDEZVOUS_H
#define RENDEZVOUS_H

#include "Date.h"
#include "Heure.h"
#include "Personne.h"

#include <string>
#include <vector>

class RendezVous
{
	public:
        RendezVous();
        RendezVous(const std::string& nom, Date date, Heure heureDeb, Heure heureFin);
        ~RendezVous();
    
        // getters
        std::string nom() const;
        Date date() const;
        Heure heureDeb() const;
        Heure heureFin() const;
        std::vector<int> listeParticipants();
    
        //setters
        void setNom(const std::string& nom);
        void setDate(const Date& date);
        void setHeureDeb(const Heure& heureDeb);
        void setHeureFin(const Heure& heureFin);
        void setHeure(const Heure& heureDeb, const Heure& heureFin);
    
        void ajouterParticipant(const Personne& pers);
        void supprimerParticipant(const Personne& pers);
        int nombreParticipants() const;
        
        bool operator!=(const RendezVous& rdv) const;
        bool operator==(const RendezVous& rdv) const;
        
        //manque les surcharges d'operateurs pour utiliser les fonction modifier et supprimer de LCRendezVous avec des rdv
    

	private:
        std::string d_nom;
		Date d_date;
		Heure d_heureDeb;
		Heure d_heureFin;
        std::vector<int> d_participants;
		
};

#endif
