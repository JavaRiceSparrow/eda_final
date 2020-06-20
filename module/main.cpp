#include "object.h"
#include "InputParser.h"
#include "placer.h"
#include <thread>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    fstream input;
    string input_file_name = "../input/case";
    input_file_name += argv[1];
    input_file_name += ".txt";
    input.open(input_file_name, ios::in);
    Placer placer(input);

    cout << "initialize success !" << endl;
    return 0;
}