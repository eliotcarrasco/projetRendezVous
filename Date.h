#ifndef DATE_H
#define DATE_H

class Date
{
	public:
		Date(int jour, int mois, int annee);
        Date (Date& date);
    
		// getters
		int jour() const;
		int mois() const;
		int annee() const;
		// setters
		void setJour(int j);
		void setMois(int m);
		void setAnnee(int a);
		
		bool valide() const;

	private:
		int d_jour;
		int d_mois;
		int d_annee;
};

#endif
