#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Database.h"
//#include "Sequence.h"

using namespace std;

//TODO:Score matrix
int gapOpenPenalty;
int gapExtensionPenalty;
//Sequence query;


int main(int argc, char *argv[]) 
{
	/*if((argc < 3) || (argc > 6))
	{
		cout << "Erreur, veuillez vérifier les paramètres." << endl;
		return -1;
	}
	else
	{*/
		//query = Sequence(argv[1]); //juste l'idée générale, à modifier
			const char* fileName = "/home/student/Documents/algo/uniprot_sprot.fasta.pin";

			Database *db = new Database(fileName);
			cout << db->getTitle() << endl;
			cout << db->getResiduesSize() << endl;
			cout << db->getHeaderOffsets()[2] << endl;

		//if(argv[3] != NULL)
			//matrix = argv[3];
		//else
			//matrix = blosum62;
		/*if(argv[4] != NULL)
			gapOpenPenalty = atoi(argv[4]);
		else
			gapOpenPenalty = 11;
		if(argv[5] != NULL)
			gapExtensionPenalty = atoi(argv[5]);
		else
			gapExtensionPenalty = 1;*/

		

		//TODO: algorithme

		return 0; 
	//}
}
