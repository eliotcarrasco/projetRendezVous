#ifndef HEURE_H
#define HEURE_H

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
    
    	//operateurs
    	bool operator<(const Heure& h) const;
    	bool operator>(const Heure& h) const;
    	
        bool valide() const;
    
	private:
		int d_heures;
		int d_minutes;
};

#endif
