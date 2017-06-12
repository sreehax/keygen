#include <iostream>
#include "sha512.h"
#include <string>
#include <termios.h>
#include <unistd.h>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std; 
int main(int argc, char *argv[])
{
    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    cout << "Password: ";
    string input;
    cin >> input;
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    string output = sha512(input);
    ofstream out("/tmp/key");
    out << output;
    out.close();
    system("xxd -r -p /tmp/key > /tmp/keyfile");
    system("rm -rf /tmp/key");
    cout << "\n";
    return 0;
}
