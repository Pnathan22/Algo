#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Database.h"
#include "Sequence.h"

using namespace std;

//TODO:Score matrix
int gapOpenPenalty;
int gapExtensionPenalty;
Sequence query;
Database databse;

int main(int argc, char *argv[]) 
{
	if((argc < 3) || (argc > 6))
	{
		cout << "Erreur, veuillez vérifier les paramètres." << endl;
		return -1;
	}
	else
	{
		query = Sequence(argv[1]); //juste l'idée générale, à modifier
		ifstream pin_file(argv[2], ios::binary);
		if(pin_file)
			db = new Database(pin_file);
		//if(argv[3] != NULL)
			//matrix = argv[3];
		//else
			//matrix = blosum62;
		if(argv[4] != NULL)
			gapOpenPenalty = atoi(argv[4]);
		else
			gapOpenPenalty = 11;
		if(argv[5] != NULL)
			gapExtensionPenalty = atoi(argv[5]);
		else
			gapExtensionPenalty = 1;

		

		TODO: algorithme

		return 0 
	}
}
