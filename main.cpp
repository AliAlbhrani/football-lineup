#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std; 

string usage(){
    return "Usage: ./main \n\texample:\n\tEnter your lineup(x-y-z): 4-3-3";
}
void print_row(int count, int total_width = 50, string icon = "●") {
    int spacing = (total_width - (count * 4)) / 2;  
    cout << setw(spacing) << "";  

    for (int i = 0; i < count; i++) {
        cout << " " << icon << " ";
    }
    cout << endl;
}
void welcome(const string& filename){
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

int main(){
    system("clear");
    int dash = 0;
    int total = 0;
    int lineupArr[3];
    string lineup = ""; 
    welcome("ascii.txt");
    cout << "Enter your lineup(x-y-z): ";
    cin >> lineup;
    system("clear");
    if(lineup.length() != 5){
        cout << "[ERROR] Invalid lineup" << endl;
        cout << usage() << endl;
        return 0;
    }
    for(int i = 0; i < lineup.length(); i++){
        if(lineup[i] == '-'){
            dash++;
        }else{
           total += (lineup[i] - '0');
            lineupArr[dash] = lineup[i] - '0';
        }
    }
    if(dash != 2){
        cout << "[ERROR] Invalid lineup you can't use more than two dashes" << endl;
        cout << usage() << endl;
        return 0;
    }
    if(total !=  10){
        cout << "[ERROR] You can't have more/less than 10 players" << endl;
        return 0;
    }
    for (int i = 2; i >= 0; i--) {
        print_row(lineupArr[i]);
        cout << endl;
    }
    print_row(1,50,"■");
    cout << endl;
    return 0;
}