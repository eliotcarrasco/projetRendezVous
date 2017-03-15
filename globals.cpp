#include "globals.h"
#include "Personne.h"
#include <string>
#include <iostream>

using namespace std;

string convertToLower(string& chaine)
{
    for (int i = 0; i < chaine.length(); ++i)
        chaine[i] = tolower(chaine[i]);
    
    return chaine;
}
