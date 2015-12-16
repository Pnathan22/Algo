#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include "Sequence.h"

using namespace std;

class Database 
{
private:
	string fileName;
	string title;
	int residuesSize;
	int sequenceSize;
	int longestSeq;	
	vector<unsigned long> headerOffsets;
	vector<unsigned long> seqOffsets;
public:
	Database(ifstream file);
	string getFileName();
	string getTitle();
	int getResiduesSize();
	int getSequenceSize();
	int getLongestSeq();
	vector<unsigned long> getHeaderOffsets();
	vector<unsigned long> getSeqOffsets();
	Sequence seekSequence();
}:
