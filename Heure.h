#ifndef HEURE_H
#define HEURE_H
#include <string>
#include <iostream>

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
        bool setHeures(int j);
        bool setMinutes(int m);
    
        bool valide() const;
        std::string getStringHeure() const;
        
        void lit(std::istream& ist);
    
    	//operateurs
    	bool operator<(const Heure& h) const;
    	bool operator>(const Heure& h) const;
        bool operator<=(const Heure& h) const;
        bool operator>=(const Heure& h) const;
        bool operator==(const Heure& h) const;
        bool operator!=(const Heure& h) const;
        
        friend std::ostream& operator<<(std::ostream& os, const Heure& h);
        friend std::istream& operator>>(std::istream& ist, Heure& h);
    
    
    
	private:
		int d_heures;
		int d_minutes;
};

#endif
