#ifndef DATE_H
#define DATE_H
#include <string>
#include <iostream>


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
		bool setJour(int j);
		bool setMois(int m);
		bool setAnnee(int a);
    
        std::string getStringDate() const;
        void lit(std::istream& ist);
    
		//operators
		bool operator==(const Date& d) const;
		bool operator!=(const Date& d) const;
		bool operator<(const Date& d) const;
        bool operator>(const Date& d) const;
        bool operator<=(const Date& d) const;
    
        friend std::ostream& operator<<(std::ostream& os, const Date& d);
        friend std::istream& operator>>(std::istream &ist, Date& d);
		
		bool valide() const;

	private:
		int d_jour;
		int d_mois;
		int d_annee;
};

#endif
