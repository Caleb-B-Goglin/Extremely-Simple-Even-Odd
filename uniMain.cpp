#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main( int argc,  char *argv[] )
{
	//Varables
	int k = 0;
	bool track{false};
	char quote = '"';
	int number = stoi(argv[1]);

// Write the work file
	//Create the file
	ofstream file;
	file.open("work.cpp");

	//Write start of file
	file << "#include <iostream>\n";
	file << "using namespace std;\n\n";
	file << "int main() {\n";
	file << "	int x = 0;\n";
	file << "	while(x != -1){\n\n";
	file << "		cout << " << quote << "Enter a number (-1 to end):" << quote << ";\n";
	file << " 		cin >> x;\n\n";

	//The good stuff
	while(k<=number)
	{
		file << "		if( x == " << k << " ){\n";
		file << "			cout << x << " << quote << " is even!" << quote << " << endl;\n" ;
		file << "		}\n\n";
		k++;

		if( k <= number )
		{
			file << "		if( x == " << k << " ){\n";
			file << "			cout << x << " << quote << " is odd!" << quote << " << endl;\n" ;
			file << "		}\n\n";
			k++;
		}
	}

	//Finish File
	file << "	}\n";
	file << "}\n";

	//Close the file
	file.close();

	//Run the work file
	system("g++ work.cpp");
	system("./a.out");

	return 0;
}
