#ifndef DATE_H
#define DATE_H
#include <string>
#include <iostream>

using namespace std;

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
    
        std::string getStringDate() const;
		
		//operators
		bool operator==(const Date& d) const;
		bool operator!=(const Date& d) const;
		bool operator<(const Date& d) const;
        bool operator>(const Date& d) const;
        bool operator<=(const Date& d) const;
        
        friend ostream& operator<<(ostream& os, const Date& d);
		
		bool valide() const;

	private:
		int d_jour;
		int d_mois;
		int d_annee;
};

#endif
