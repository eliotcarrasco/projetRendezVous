#include "globals.h"
#include "Personne.h"
#include <string>
#include <iostream>

using namespace std;


/**
     Converti une chaine entièrement en minuscule
     @param chaine - une chaine de caractere
     @return c - la chaine en minuscule
 */
string convertToLower(const string& chaine)
{
    string c = chaine;
    for (int i = 0; i < chaine.length(); ++i)
        c[i] = tolower(chaine[i]);
    
    return c;
}

/**
    Converti une chaine entièrement en majuscules
    @param chaine - une chaine de caractere
    @return c - la chaine en majuscule
 */
string convertToUpper(const string& chaine)
{
    string c = chaine;
    for (int i = 0; i < chaine.length(); ++i)
        c[i] = toupper(chaine[i]);
    
    return c;
}


/**
     Converti une chaine entièrement en minuscule
     @param chaine - une chaine de caractere
     @return c - la chaine en minuscule
 */
string convertForName(const string& chaine)
{
    string c = chaine;
    int i = 0;
    c[i] = toupper(chaine[i]);
    ++i;
    for (; i < chaine.length(); ++i)
        c[i] = tolower(chaine[i]);
    
    return c;
}




