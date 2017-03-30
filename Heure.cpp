#include "Heure.h"


/**
	Constructeur vide
 */
Heure::Heure(): d_heures{}, d_minutes{}
{}


/**
	Constructeur
	@param heures - un nombre d'heures
	@param minutes - un nombre de minutes
 */
Heure::Heure(int heures, int minutes): d_heures{heures}, d_minutes{minutes}
{}

/**
	Constructeur par recopie
	@param heure - un instance d'objet heure
 */
Heure::Heure(const Heure& heure): d_heures{heure.heures()}, d_minutes{heure.minutes()}
{}


/**
	Renvoie le nombre d'heures
	@return le nombre d'heures
 */
int Heure::heures() const
{
    return d_heures;
}

/**
	Renvoie le nombre de minutes
	@return le nombre de minutes
 */
int Heure::minutes() const
{
    return d_minutes;
}


/**
	Modifie le nombre d'heures
	@param h - le nombre d'heures
	@return Vrai si l'heure est compris entre 0 et 24
*/
bool Heure::setHeures(int h)
{
    if (h >= 0 && h < 24)
    {    
		d_heures = h;
		return true;
	}
	return false;
}

/**
	Modifie les minutes
	@param m - une minutes
	@return Vrai si les minutes sont comprises entre 0 et 60
 */
bool Heure::setMinutes(int m)
{
    if (m >= 0 && m < 60)
    {
        d_minutes = m;
    	return true;
	}
	return false;
}


/**
	Verifie si la date est valide
	@return Vrai si la date est valide, Faux sinon
 */
bool Heure::valide() const {
    
    
    if(d_heures <= 0 || d_heures > 24) return false;
    if(d_minutes <= 0 || d_minutes > 60) return false;
    
    return true;
}


/**
    Retourne l'heure sous la forme d'une chaine de caracteres
    @return s - l'heure sous forme de chaine de caracteres
 */
std::string Heure::getStringHeure() const
{
    std::string s;
    
    if(d_heures<10)
        s += "0" + std::to_string(d_heures) + ":";
    else
        s += std::to_string(d_heures) + ":";
    
    if(d_minutes<10)
        s += "0" + std::to_string(d_minutes);
    else
        s += std::to_string(d_minutes);
    
    return s;
}

/**
	
*/
void Heure::lit(istream& ist)
{
	int h, m;
	char c;
	ist >> h >> c >> m;
	while (ist.fail() || !setHeures(h) || c != ':' || !setMinutes(m) ||)
    {
        
        ist.clear();
        ist.ignore(256,'\n');
        std::cout << "L'heure n'est pas au bon format (hh:mm)" << endl;
        std::cout << "Reessayer: ";
		ist >> h >> c >> m;
    }
}



/**
	Operateur <
	@params h - une Heure
*/
bool Heure::operator<(const Heure& h) const
{
	return ( (d_heures < h.d_heures) || (d_heures == h.d_heures && d_minutes < h.d_minutes) );
}

/**
	Operateur >
	@params h - une Heure
*/
bool Heure::operator>(const Heure& h) const
{
	return ( (d_heures > h.d_heures) || (d_heures == h.d_heures && d_minutes > h.d_minutes) );
}


/**
	Operateur >=
	@params h - une Heure
 */
bool Heure::operator>=(const Heure& h) const
{
    return ( (d_heures > h.d_heures) || (d_heures == h.d_heures && d_minutes > h.d_minutes) || (d_heures == h.d_heures && d_minutes == h.d_minutes) );
    
}

/**
	Operateur <=
	@params h - une Heure
 */
bool Heure::operator<=(const Heure& h) const
{
    return ( (d_heures < h.d_heures) || (d_heures == h.d_heures && d_minutes < h.d_minutes) || (d_heures == h.d_heures && d_minutes == h.d_minutes) );
}


/**
	Operateur ==
	@params h - une Heure
 */
bool Heure::operator==(const Heure& h) const
{
    return (d_heures == h.d_heures && d_minutes == h.d_minutes);
}

/**
	Operateur !=
	@params h - une Heure
 */
bool Heure::operator!=(const Heure& h) const
{
	return (d_heures != h.d_heures && d_minutes != h.d_minutes);
}

/**
	Operateur <<
	@params os - un flux
	@params h - une Heure
 */
ostream& operator<<(ostream& os, const Heure& h)
{
	os << h.getStringHeure();
	return os;
}

/**
	
*/
istream& operator>>(istream& ist, Heure& h)
{
	h.lit(ist);
	return ist;
}
