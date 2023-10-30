#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

int main(){
    string str;
    int count=0;
    regex twice(".*(\\w\\w).*\\1.*");
    regex repeat(".*(\\w)(\\w)\\1.*");
    ifstream ReadInput("input");

    while (getline(ReadInput,str)){
        if(regex_match(str,twice)&&regex_match(str,repeat)){
            count++;
        }
    }
    cout<<count;
    return 0;
}