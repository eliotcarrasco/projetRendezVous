#include "Date.h"
#include <ctime>

using namespace std;

/**
	Constructeur par defaut
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
    @return Vrai si le jour a bien ete modifie (compris entre 1 et 31 inclus), Faux sinon
*/
bool Date::setJour(int j)
{
	if (j <= 31 && j >= 1)
    {
        d_jour = j;
        return true;
    }
    
    return false;
}

/**
	Modifie le mois
	@param m - un mois
    @return Vrai si le mois a bien ete modifie (compris entre 1 et 12 inclus), Faux sinon
*/
bool Date::setMois(int m)
{
	if (m <= 12 && m >= 1)
    {
        d_mois = m;
        return true;
    }
    
    return false;
}

/**
	Modifie l'annee si elle est superieure ou egale a l'annee courante
	@param a - une annee
    @return Vrai si l'annee a bien ete modifiee (superieure ou egale a l'annee courante), Faux sinon
*/
bool Date::setAnnee(int a)
{
	time_t currentTime;
	struct tm *localTime;
	
	time( &currentTime );                   // Get the current time
	localTime = localtime( &currentTime );  // Convert the current time to the local time
	int year = localTime->tm_year + 1900;
  
	if(a >= year)
    {
        d_annee = a;
        return true;
    }
    
    return false;
}

/**
    Retourne la date sous la forme d'une chaine de caracteres
    @return s - la date sous forme de chaine de caracteres
 */
std::string Date::getStringDate() const
{
    std::string s = "";
    
    if(d_jour<10)
        s += "0" + std::to_string(d_jour) + "/";
    else
        s += std::to_string(d_jour) + "/";
    
    if(d_mois<10)
        s += "0" + std::to_string(d_mois) + "/";
    else
        s += std::to_string(d_mois) + "/";
    
    s += std::to_string(d_annee);
    
    return s;
}

/**
    Fonction qui permet de lire une date
    @param ist - le flot d'entree
 */
void Date::lit(istream& ist)
{
    int j, m, a;
    char c1, c2;
    
    ist >> j >> c1 >> m >> c2 >> a;
    
    while (ist.fail() || !setJour(j) || c1 != '/' || !setMois(m) || c2 != '/' || !setAnnee(a))
    {
        
        ist.clear();
        ist.ignore(256,'\n');
        std::cout << "La date n'est pas au bon format (jj/mm/2017+)" << endl;
        std::cout << "Reessayer: ";
        ist >> j >> c1 >> m >> c2 >> a;
    }
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
	@param d - une Date
    @return Vrai si la date courante est differente a celle passee en parametre, Faux sinon
*/
bool Date::operator!=(const Date& d) const
{
	return (d.d_annee!=d_annee || d.d_mois!=d_mois || d.d_jour!=d_jour);
}

/**
	Operateur ==
	@param d - une Date
    @return Vrai si la date courante est egale a celle passee en parametre, Faux sinon
*/
bool Date::operator==(const Date& d) const
{
	return (d.d_annee==d_annee && d.d_mois==d_mois && d.d_jour==d_jour);
}

/**
	Operateur <
	@param d - une Date
    @return Vrai si la date courante est inferieure a celle passee en parametre, Faux sinon
*/
bool Date::operator<(const Date& d) const
{
	return ( (d_annee < d.d_annee) || (d_annee == d.d_annee && d_mois < d.d_mois) || (d_annee == d.d_annee && d_mois == d.d_mois && d_jour < d.d_jour) );
}


/**
	Operateur >
	@param d - une Date
    @return Vrai si la date courante est superieure a celle passee en parametre, Faux sinon
 */
bool Date::operator>(const Date& d) const
{
    return ( (d_annee > d.d_annee) || (d_annee == d.d_annee && d_mois > d.d_mois) || (d_annee == d.d_annee && d_mois == d.d_mois && d_jour > d.d_jour) );
}

/**
	Operateur <=
	@param d - une date
*/
bool Date::operator<=(const Date& d) const
{
	return ( (*this < d) || (*this == d));
}

/**
	Surcharge de l'operateur d'ecriture
	@param os - un flot de sortie
	@param d - une date
    @return le flot
*/
ostream& operator<<(ostream& os, const Date& d)
{
	os << d.getStringDate();
	return os;
}


/**
    Surcharge de l'operateur de lecture
    @param ist - un flot d'entree
	@param d - une date
    @return le flot
 */
istream& operator>>(istream &ist, Date& d)
{
    d.lit(ist);
    return ist;
}
