#include "globals.h"
#include "Personne.h"

#include <string>
#include <iostream>
#include <stdio.h>



using namespace std;


/**
     Convertit une chaine entierement en minuscule
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
    Convertit une chaine entierement en majuscules
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
     Convertit une chaine entierement en minuscule avec la premiere lettre en majuscule
     @param chaine - une chaine de caractere
     @return c - la chaine au format specifique
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




