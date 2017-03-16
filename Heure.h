#ifndef HEURE_H
#define HEURE_H
#include <string>

class Heure
{
	public:
        Heure();
		Heure(int heures, int minutes);
        Heure(const Heure& heure);
    
        // getters
        int heures() const;
        int minutes() const;
        // setters
        void setHeures(int j);
        void setMinutes(int m);
    
        bool valide() const;
        std::string getStringHeure() const;
    
    	//operateurs
    	bool operator<(const Heure& h) const;
    	bool operator>(const Heure& h) const;
        bool operator<=(const Heure& h) const;
        bool operator>=(const Heure& h) const;
        bool operator==(const Heure& h) const;
    
    
    
	private:
		int d_heures;
		int d_minutes;
};

#endif
