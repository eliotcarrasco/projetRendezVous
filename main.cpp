#include <iostream>
#include "interface.h"
#include "LCPersonne.h"
#include "LCRendezVous.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	interface inter;
	LCPersonne listePersonnes;
	LCRendezVous listeRdv;
	// Creation des listes principales
	// Lecture du fichier contenant les listes
	inter.menuPrincipal(listePersonnes, listeRdv);
	return 0;
}
