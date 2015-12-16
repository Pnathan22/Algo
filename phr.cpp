#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <math.h>


using namespace std;
vector<unsigned char> int_buf;
unsigned long number;
string word;
unsigned int int_length; 
unsigned long string_length;
unsigned int nb_byte;
int length;

unsigned long decode_any(vector<unsigned char> buf)
{
	unsigned long result = 0;
	int size = buf.size();
	for(int i=0; i<size;i++)
		result += buf[size-1-i]*pow(16,2*i);
	return result;	
}

int main()
{

	ifstream file("/home/student/Documents/algo/uniprot_sprot.fasta.phr", ios::binary);

	if(file)
	{
		file.seekg(0, file.end);
		length = file.tellg();
		file.seekg(0, file.beg);
		unsigned char* buffer = new unsigned char[length];
		file.read((char*)buffer, length);
		
		long cursor = 0;
		while(cursor<250)
		{
			switch((unsigned int)buffer[cursor])
			{
				case 2:
					cursor++;
					int_length = (unsigned int)buffer[cursor];
					cursor++;
					for(int j=cursor;j<cursor+int_length; j++)
						int_buf.push_back(buffer[j]);
					cursor += int_length;
					number = decode_any(int_buf);
					int_buf.clear();
					cout << number << endl;
					break;
				case 26:
					cursor++;
					word = "";
					if((unsigned int)buffer[cursor] <= 128)
					{
						string_length = (unsigned long)buffer[cursor];
						cursor++;
					}
					else
					{
						nb_byte = (unsigned int)buffer[cursor]-128;
						cursor++;
						for(int j=cursor;j<cursor+nb_byte; j++)
							int_buf.push_back(buffer[j]);
						cursor += nb_byte;
						string_length = decode_any(int_buf);
					}	
					for(int j=cursor;j<(cursor+string_length); j++)
						 word += buffer[j];
					cursor += string_length;
					cout << word << endl;
					break;
				default:
					cursor++;
					break;
			}
		}	

						
							
	}
	return 0;
}

