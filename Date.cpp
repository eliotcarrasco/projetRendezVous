#include "Date.h"
#include <ctime>



/**
	Constructeur vide
 */
Date::Date(): d_jour{}, d_mois{}, d_annee{}
{}


/**
	Constructeur
	@param jour - un jour
	@param mois - un mois
	@param annee - une annee
*/
Date::Date(int jour, int mois, int annee): d_jour{jour}, d_mois{mois}, d_annee{annee}
{}


/**
	Constructeur par recopie
	@param date - une instance de l'objet date
 */
Date::Date(const Date& date): d_jour{date.jour()}, d_mois{date.mois()}, d_annee{date.annee()}
{}

/**
	Renvoie le jour
	@return le jour
*/
int Date::jour() const
{
	return d_jour;
}

/**
	Renvoie le mois
	@return le mois
*/
int Date::mois() const
{
	return d_mois;
}

/**
	Renvoie l'annee
	@return l'annee
*/
int Date::annee() const
{
	return d_annee;
}

/**
	Modifie le jour
	@param j - un jour
*/
void Date::setJour(int j)
{
	if (j <= 31 && j >= 1)
		d_jour = j;
}

/**
	Modifie le mois
	@param m - un mois
*/
void Date::setMois(int m)
{
	if (m <= 12 && m >= 1)
		d_mois = m;
}

/**
	Modifie l'annee si elle est superieure ou egale a l'annee courante
	@param a - une annee
*/
void Date::setAnnee(int a)
{
	time_t currentTime;
	struct tm *localTime;
	
	time( &currentTime );                   // Get the current time
	localTime = localtime( &currentTime );  // Convert the current time to the local time
	int year = localTime->tm_year + 1900;
  
	if(a >= year)
		d_annee = a;
}

/**
	Verifie si la date est valide
	@return Vrai si la date est valide, Faux sinon
*/
bool Date::valide() const {
	
	time_t currentTime;
	struct tm *localTime;
	
	time( &currentTime );
	localTime = localtime( &currentTime );
	int anneeCourante = localTime->tm_year + 1900;

	if (d_annee < anneeCourante) return false;
	if (d_mois > 12 || d_mois <1) return false;
	if (d_jour > 31 || d_jour < 1) return false;
	if (d_jour == 30 && d_mois == 2) return false;
	if ((d_jour ==31 && ( d_mois == 2 || d_mois == 4 || d_mois == 6 || d_mois == 9 || d_mois == 11) ) ) return false;
	
	return true;
};

/**
	Operateur !=
	@params d - une Date
*/
bool Date::operator!=(const Date& d) const
{
	return (d.d_annee!=d_annee || d.d_mois!=d_mois || d.d_jour!=d_jour);
}

/**
	Operateur ==
	@params d - une Date
*/
bool Date::operator==(const Date& d) const
{
	return (d.d_annee==d_annee && d.d_mois==d_mois && d.d_jour==d_jour);
}

/**
	Operateur <
	@params d - une Date
*/
bool Date::operator<(const Date& d) const
{
	return ( (d_annee<d.d_annee) || (d_annee == d.d_annee && d_mois < d.d_mois) || (d_annee == d.d_annee && d_mois == d.d_mois && d_jour < d.d_jour) );
}
