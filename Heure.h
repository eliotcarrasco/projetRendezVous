#ifndef HEURE_H
#define HEURE_H
#include <string>
#include <iostream>

using namespace std;

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
        bool operator!=(const Heure& h) const;
        
        friend ostream& operator<<(ostream& os, const Heure& h);
    
    
    
	private:
		int d_heures;
		int d_minutes;
};

#endif
