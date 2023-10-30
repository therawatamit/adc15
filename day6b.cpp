#include <iostream>
#include <string>
#include <regex>
#include <fstream>

using namespace std;

int main()
{
    int lights[1000][1000]={0};
    string str;
    regex coords("(\\w{1,}\\s{0,1}\\w{0,})\\s(\\d+),(\\d+)\\s\\w+\\s(\\d+),(\\d+)");
    smatch match;
    ifstream ReadInput("input");
        while (getline(ReadInput,str)){
            if(regex_search(str,match,coords)){
                if(match[1] == "turn on"){
                    for(int i = stoi(match[2]);i<=stoi(match[4]); i++){
                        for(int j = stoi(match[3]);j<=stoi(match[5]);j++){
                            lights[i][j]++;
                        }
                    }
                }
                else if(match[1] == "turn off"){
                    for(int i = stoi(match[2]);i<=stoi(match[4]); i++){
                        for(int j = stoi(match[3]);j<=stoi(match[5]);j++){
                            if(lights[i][j]<=0){
                                lights[i][j]=0;
                            }
                            else{
                                lights[i][j]--;
                            }
                        }
                    }
                }
                else if(match[1] == "toggle"){
                    for(int i = stoi(match[2]);i<=stoi(match[4]); i++){
                        for(int j = stoi(match[3]);j<=stoi(match[5]);j++){
                            lights[i][j]+=2;
                        }
                    }
                }
            }
        }
    int count = 0;
    for(int i = 0;i<1000; i++){
                        for(int j = 0;j<1000;j++){
                            
                                count+=lights[i][j];
                            
                        }
                    }
                    cout<<count;
    return 0;
}