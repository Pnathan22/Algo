#include "Database.h"

using namespace std;

Database::Database(ifstream file)
{
	file.seekg(0, file.end);
	length = file.tellg();
	file.seekg(0, file.beg);
	unsigned char* buffer = new unsigned char[length];
	file.read((char*)buffer, length);

	
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
