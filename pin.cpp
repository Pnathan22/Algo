#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <inttypes.h>

using namespace std;

int length;
unsigned char data_buf[4];
unsigned char big_data_buf[8];
string title;
int cursor;
vector<unsigned long> header_offsets;
vector<unsigned long> seq_offsets;

unsigned long decode32(unsigned char* buf)
{	
	return pow(16,6)*(unsigned long)buf[0] + pow(16,4)*(unsigned long)buf[1] + pow(16,2)*(unsigned long)buf[2] + (unsigned long)buf[3];
}

unsigned long decode64(unsigned char* buf)
{
	return (unsigned long)buf[0] + pow(16,2)*(unsigned long)buf[1] + pow(16,4)*(unsigned long)buf[2] + pow(16,6)*(unsigned long)buf[3] + pow(16,8)*(unsigned long)buf[4] + pow(16,10)*(unsigned long)buf[5] + pow(16,12)*(unsigned long)buf[6] + pow(16,14)*(unsigned long)buf[7];
}

int main()
{
	ifstream file("/home/student/Documents/algo/uniprot_sprot.fasta.pin", ios::binary);
	
	if(file)
	{
		file.seekg(0, file.end);
		length = file.tellg();
		file.seekg(0, file.beg);
		unsigned char* buffer = new unsigned char[length];
		file.read((char*)buffer, length);

		for(int j = 4; j<8; j++)
			data_buf[j-4]= buffer[j];
		cursor = 8;	
		unsigned long data_type  = decode32(data_buf);	
		if(data_type == 1)
		{
			for(int j = cursor; j<cursor+4; j++)
				data_buf[j-cursor]= buffer[j];
			cursor += 4;
			unsigned long title_length = decode32(data_buf);
			for(int j = cursor; j<cursor+title_length; j++)
				title += buffer[j];
			cursor += title_length;
			for(int j = cursor; j<cursor+4; j++)
				data_buf[j-cursor]= buffer[j];	
			unsigned long timestamp_length = decode32(data_buf);
			cursor += (4+timestamp_length);
			for(int j = cursor; j<cursor+4; j++)
				data_buf[j-cursor]= buffer[j];
			cursor += 4;	
			unsigned long seq_nb = decode32(data_buf);
			for(int j = cursor; j<cursor+8; j++)
				big_data_buf[j-cursor] = buffer[j];
			cursor += 8;
			unsigned long residue_nb = decode64(big_data_buf);	
			for(int j = cursor; j<cursor+4; j++)
				data_buf[j-cursor] = buffer[j];
			cursor += 4;
			unsigned long max_seq = decode32(data_buf);
			int cursor_aux = 0;
			for(int j = cursor; j<cursor+4+(4*seq_nb); j++)
			{
				data_buf[cursor_aux] = buffer[j];
				cursor_aux++;
				if(cursor_aux >3)
				{
					cursor_aux = 0;
					header_offsets.push_back(decode32(data_buf));
				}
			}
			cursor += (4+4*seq_nb);
			for(int j = cursor; j<cursor+4+(4*seq_nb); j++)
			{
				data_buf[cursor_aux] = buffer[j];
				cursor_aux++;
				if(cursor_aux >3)
				{
					cursor_aux = 0;
					seq_offsets.push_back(decode32(data_buf));
				}
			}
			cursor += (4+4*seq_nb);

			
		}
		
	}
}		
