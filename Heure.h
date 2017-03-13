#ifndef HEURE_H
#define HEURE_H

class Heure
{
	public:
		Heure(int heures, int minutes);
        Heure(Heure& heure);
    
        // getters
        int heures() const;
        int minutes() const;
        // setters
        void setHeures(int j);
        void setMinutes(int m);
    
        bool valide() const;
    
	private:
		int d_heures;
		int d_minutes;
};

#endif
