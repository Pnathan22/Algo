#include <string>

using namespace std;

class Sequence
{
private:
	string name;
	int lenght;
	string description;

public:
	Sequence(string name, int lenght, string description);
	string getName();
	int getLenght();
	string getDescription();
};
