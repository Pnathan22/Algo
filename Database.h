#include <string>
#include "sequence.h"

using namespace std;

class Database 
{
private:
	string fileName;
	string title;
	int residuesSize;
	int sequenceSize;
	int longestSeq;	

public:
	Database(string fileName, string title, int residuesSize, int sequenceSize, int longestSeq);
	string getFileName();
	string getTitle();
	int getResiduesSize();
	int getSequenceSize();
	int getLongestSeq();
	Sequence seekSequence();
}:
