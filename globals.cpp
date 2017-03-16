#include "globals.h"
#include "Personne.h"
#include <string>
#include <iostream>

using namespace std;

string convertToLower(const string& chaine)
{
    string c = chaine;
    for (int i = 0; i < chaine.length(); ++i)
        c[i] = tolower(chaine[i]);
    
    return c;
}
