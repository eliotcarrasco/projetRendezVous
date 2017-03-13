#ifndef RENDEZVOUS_H
#define RENDEZVOUS_H
#include <string>
#include "Date.h"
#include "Heure.h"
#include "LCPersonne.h"

using namespace std;

class RendezVous
{
	public:
		RendezVous(string nom, Date date, Heure heureDeb, Heure heureFin);
    
        // getters
        string nom() const;
        Date date() const;
        Heure heureDeb() const;
        Heure heureFin() const;
        LCPersonne listeParticipants() const;
    
        //setters
        void setNom(string nom);
        void setDate(Date date);
        void setHeureDeb(Heure heureDeb);
        void setHeureFin(Heure heureFin);
        void setHeure(Heure heureDeb, Heure heureFin);
    
        void ajouterParticipant(Personne pers);
        void supprimerParticipant(Personne pers);
    

	private:
		string d_nom;
		Date d_date;
		Heure d_heureDeb;
		Heure d_heureFin;
        LCPersonne d_participants;
		
};

#endif
