#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        cout << "No onid username specified!" << endl;
        return -1;
    }
    
    string input;
    string date = "";
    
    cout << "Day of month, ex 1: ";
    getline(cin, input);
    date += input;

    cout << "Month of the year, ex March: ";
    getline(cin, input);
    date+= input;

    cout << "Year, ex 2016: ";
    getline(cin, input);
    date += input;

    string filename = string(argv[1]) + '_' + date + ".log";
    cout << "Opening file: " << filename << endl;
    ifstream file(filename);

    if(!file.is_open())
    {
        cout << "File did not open!" << endl;
        return -1;
    }

    while(true)
    {
        cout << "Display or Exit [d][e]: ";
        getline(cin, input);

        if(input == "e")
            break;

        file.clear();
        file.seekg(0);

        while(getline(file, input))
            cout << input << endl;
    }

    file.close();

	return 0;
}
