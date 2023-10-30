#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

int main(){
    string str;
    int count=0;
    regex vowels("(.*[aieou]){3,}.*");
    regex repeat(".*(\\w)\\1.*");
    regex restrictions(".*((ab)|(cd)|(pq)|(xy)).*");
    ifstream ReadInput("input");

    while (getline(ReadInput,str)){
        if(regex_match(str,vowels)&&regex_match(str,repeat)&&!regex_match(str,restrictions)){
            count++;
        }
    }
    cout<<count;
    return 0;
}