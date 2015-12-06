#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Database.h"
#include "Sequence.h"

using namespace std;

TODO:Score matrix
int gapOpenPenalty;
int gapExtensionPenalty;
Sequence query;

int main(int argc, char *argv[]) 
{
	query = Sequence(argv[1]); //juste l'idée générale, à modifier
	gapOpenPenalty = atoi(argv[4]);
	gapExtensionPenalty = atoi(argv[5]);

	TODO: algorithme

	return 0 
}
