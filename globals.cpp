#include "globals.h"
#include <string>

using namespace std;

string convertToLower(string& chaine)
{
    for (int i = 0; i < chaine.length(); ++i)
        chaine[i] = tolower(chaine[i]);
    
    return chaine;
}
