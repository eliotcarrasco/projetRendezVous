#ifndef DATE_H
#define DATE_H

class Date
{
	public:
        Date();
		Date(int jour, int mois, int annee);
        Date(const Date& date);
    
		// getters
		int jour() const;
		int mois() const;
		int annee() const;
		// setters
		void setJour(int j);
		void setMois(int m);
		void setAnnee(int a);
		
		//operators
		bool operator==(Date d);
		bool operator!=(Date d);
		bool operator<(Date d);
		
		bool valide() const;

	private:
		int d_jour;
		int d_mois;
		int d_annee;
};

#endif
