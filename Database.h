#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "Sequence.h"

using namespace std;

class Database 
{
private:
	string fileName;
	string title;
	unsigned long residuesSize;
	unsigned long sequenceSize;
	unsigned long longestSeq;	
	vector<unsigned long> headerOffsets;
	vector<unsigned long> seqOffsets;
public:
	Database(const char* fileName);
	string getFileName();
	string getTitle();
	unsigned long getResiduesSize();
	unsigned long getSequenceSize();
	unsigned long getLongestSeq();
	vector<unsigned long> getHeaderOffsets();
	vector<unsigned long> getSeqOffsets();
	void setFileName(string name);
	void setTitle(string title);
	void setResiduesSize(unsigned long residue_nb);
	void setSequenceSize(unsigned long seq_nb);
	void setLongestSeq(unsigned long max_seq);
	void setHeaderOffsets(vector<unsigned long> header_offsets);
	void setSeqOffsets(vector<unsigned long> seq_offsets);
	void init(unsigned char* buffer, Database* db);
	Sequence seekSequence();
};
