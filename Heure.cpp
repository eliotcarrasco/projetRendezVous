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
 */
void Heure::setHeures(int h)
{
    if (h >= 0 && h <= 24)
        d_heures = h;
}

/**
	Modifie le mois
	@param m - un mois
 */
void Heure::setMinutes(int m)
{
    if (m >= 0 && m <= 60)
        d_minutes = m;
}


/**
	Verifie si la date est valide
	@return Vrai si la date est valide, Faux sinon
 */
bool Heure::valide() const {
    
    
    if(d_heures < 0 || d_heures > 24) return false;
    if(d_minutes < 0 || d_minutes > 60) return false;
    
    return true;
}

bool Heure::operator<(Heure h)
{
	return ( (d_heures < h.d_heures) || (d_heures == h.d_heures && d_minutes < h.d_minutes) );
}

bool Heure::operator>(Heure h)
{
	return ( (d_heures > h.d_heures) || (d_heures == h.d_heures && d_minutes > h.d_minutes) );
}
