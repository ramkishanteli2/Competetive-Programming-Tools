#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

  //Will create a ports.txt file where all the states of the ports will be stored
  system("ss > ports.txt");
  //Printing the file using ifstream class object
  ifstream MyFile("ports.txt");
  string myText;
  while (getline(MyFile, myText)){
    cout << myText << endl;
  }
  MyFile.close();
  return 0;
}
