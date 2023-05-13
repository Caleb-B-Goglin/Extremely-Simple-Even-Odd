#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	//Varables
	int number, k = 0;
	bool track{false};
	char quote = '"';
	char cmd[100];

//Number to check
	cout << "Which number would you like to check?: ";
	cin >> number;

	sprintf(cmd, "./a.out %d", number);

// Write the work file
	//Create the file
	ofstream file;
	file.open("work.cpp");

	//Write start of file
	file << "#include <iostream>\n";
	file << "#include <string>\n";
	file << "using namespace std;\n\n";
	file << "int main( int argc, char* argv[] ) {\n";
	file << "	int x = stoi(argv[1]);\n";

	//The good stuff
	while(k<=number)
	{
		file << "	if( x == " << k << " ){\n";
		file << "		cout << x << " << quote << " is even!" << quote << " << endl;\n" ;
		file << "	}\n\n";
		k++;

		if( k <= number )
		{
			file << "	if( x == " << k << " ){\n";
			file << "		cout << x << " << quote << " is odd!" << quote << " << endl;\n" ;
			file << "	}\n\n";
			k++;
		}
	}

	//Finish File
	file << "}\n";

	//Close the file
	file.close();

	//Run the work file
	system("g++ work.cpp");
	system(cmd);

	return 0;
}
