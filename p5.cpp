#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    system("powershell -Command \"Invoke-WebRequest -Uri https://www.nike.com/in/ -OutFile page.html\"");

    ifstream file("page.html");
    if (!file) {
        cout << "Failed to open downloaded page.html. Make sure the URL is correct.\n";
        system("pause");
        return 1;
    }

    ofstream csv("output.csv");
    if (!csv) {
        cout << "Failed to create output.csv\n";
        system("pause");
        return 1;
    }

    csv << "LineContent\n";

    string line;
    bool wroteSomething = false;
    while (getline(file, line)) {
        if (line.find("title") != string::npos || line.find("price") != string::npos) {
            csv << "\"" << line << "\"\n";
            wroteSomething = true;
        }
    }

    if (!wroteSomething) {
        cout << "No matching lines found. Try changing the search keywords.\n";
    } else {
        cout << "Scraped lines saved to output.csv\n";
    }

    file.close();
    csv.close();
    system("pause");
    return 0;
}
