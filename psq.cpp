#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <math.h>


using namespace std;

char get_residue(unsigned int value)
{
	if(value > 27)
		return '-';
	else
	{
		char residues[] = "-ABCDEFGHIKLMNPQRSTVWXYZU*OJ";
	return residues[value];
	}
}
int main()
{
	cout << get_residue(20) << endl;
	cout << get_residue(28) << endl;
	cout << get_residue(25) << endl;
	return 0;
}


				
