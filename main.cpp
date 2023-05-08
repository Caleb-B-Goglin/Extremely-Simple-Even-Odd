#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	//Variable Declaration
	int number;
	char cmd[100];

	//Very important user prompt
	cout << "How many checks would you like?: ";
	cin >> number;

	//Unix based systems section
	#if defined(__unix__)
		sprintf(cmd, "./a.out %d", number);
		system("g++ uniMain.cpp");
		system(cmd);
	#endif


	//Windows based sectio (WIP)

	return 0;
}
