#ifndef PERSONNE_H
#define PERSONNE_H

#include "Date.h"
#include "Heure.h"

#include <string>


class Personne
{
	public:
        Personne(const std::string& nom, const std::string& prenom, const std::string& telephone, const std::string& mail);
        Personne(const Personne& pers);
        Personne();
    
        int Id() const;
		std::string Nom() const;
		std::string Prenom() const;
        std::string Telephone() const;
        std::string Mail() const;
		
        void setTelephone(const std::string& telephone);
		void setMail(const std::string& mail);
		void afficherPersonne() const;
    
        //operateurs de comparaison
        bool operator==(const Personne& pers) const;
        bool operator!=(const Personne& pers) const;
        bool operator<(const Personne& pers) const;
        bool operator>(const Personne& pers) const;
    
		
	private:
        static int id_suiv;
        int d_id;
		std::string d_nom;
		std::string d_prenom;
		std::string d_telephone;
		std::string d_mail;
    
};


#endif
