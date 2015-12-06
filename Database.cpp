#include "Database.h"

using namespace std;

Database::Database(string fileName, string title, int residuesSize, int sequenceSize, int longestSeq)
{
	fileName = fileName;
	title = title;
	residuesSize = residuesSize;
	sequenceSize = sequenceSize;
	longestSeq = longestSeq;
}

string Database::getFileName()
{
	return fileName;
}

string Database::getTitle()
{
	return title;
}

int  Database::getResiduesSize()
{
	return residuesSize;
}

int  Database::getSequenceSize()
{
	return sequenceSize;
}

int  Database::getLongestSeq()
{
	return longestSeq;
}

Sequence Database::seekSequence()
{
}
