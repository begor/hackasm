#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> read(string file) {
    vector<string> lines;
    string line;
    ifstream myfile(file);
    
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            cout << line << endl;
            lines.push_back(line);
        }
    
        myfile.close();
    } else {
        cout << "Unable to open file"; 
    }

  return lines;
}


int main () {
  read("hello.txt");
  return 0;
}