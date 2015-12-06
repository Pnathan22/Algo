#include "Sequence.h"

using namespace std;

Sequence::Sequence(string name, int lenght, string description) 
{
	name = name;
	lenght = lenght;
	description = description;	
}

string Sequence::getName()
{
	return name;
}

int Sequence::getLenght()
{
	return lenght;
}

string Sequence::getDescription()
{
	return description;
}	

int Sequence::compareTo(Sequence seq)
{
}
