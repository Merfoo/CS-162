#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        cout << "No onid username specified!" << endl;
        return -1;
    }

	time_t t = time(0);
	struct tm* timeNow = localtime(&t);

	string months[] =
	{
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};

	string readableTime = "";
	readableTime += std::to_string((long long)timeNow->tm_mday);
	readableTime += months[timeNow->tm_mon];
	readableTime += std::to_string((long long)timeNow->tm_year + 1900);
	
	string filename = string(argv[1]) + '_' + readableTime + ".log";
	ofstream file(filename);

	cout << "Created file: " << filename << endl;

    file << readableTime << endl;

	while (true)
	{
		cout << "Enter text, (~) to quit: ";
		string input;
		getline(cin, input);

		if (input == "~")
			break;

		file << input;
	}
	
	file.close();

	return 0;
}
