#include <string>
#include <iostream>
#include<fstream>
#include<time.h>
using namespace std;
bool isNumber(string s);
int isMode(string mode);
int isAlgorithm_name(string algorithm);
int isInput_order(string input);
bool chooseCommandType(int argc, char* argv[]);
bool writeArrayToFile(string filename, int* a, int n);
void writeArrayToFile_Command3(int* a, int n, int i);
int isOutput_parameters(string output);
bool Command_1(char* argv[]);
bool Command_2(char* argv[]);
bool Command_3(char* argv[]);
bool Command_4(char* argv[]);
bool Command_5(char* argv[]);
