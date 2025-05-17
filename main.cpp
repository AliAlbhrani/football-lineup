#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std; 

string usage(){
    return "Usage: ./main \n\texample:\n\tEnter your lineup(x-y-z): 4-3-3";
}
void print_row(int count, int total_width = 50, string icon = "*") {
    int spacing = (total_width - (count * 4)) / 2;  
    cout << setw(spacing) << "";  

    for (int i = 0; i < count; i++) {
        cout << " " << icon << " ";
    }
    cout << endl;
}
void welcome(){
    cout << "   ___               __    __                ___    ___      " << endl;
    cout << " /'___\\             /\\ \\__/\\ \\              /\\_ \\  /\\_ \\     " << endl;
    cout << "/\\ \\__/  ___     ___\\ \\ ,_\\ \\ \\____     __  \\\\ /\\ \\ \\\\/\\ \\    " << endl;
    cout << "\\ \\ ,__/\\/ __`\\  / __`\\ \\ \\/\\ \\ '__`\\  /'__`\\  \\ \\ \\  \\ \\ \\   " << endl;
    cout << " \\ \\ \\_/\\ \\L\\ \\/\\ \\L\\ \\ \\ \\_\\ \\ \\L\\ \\/\\ \\L\\.\\_ \\_\\ \\_ \\_\\ \\_ " << endl;
    cout << "  \\ \\_\\\\ \\____/\\ \\____/\\ \\__\\\\ \\_,__/\\ \\__/.\\_\\/\\____\\/\\____\\ " << endl;
    cout << " __\\/_/ \\/___/  \\/___/  \\/__/ \\/___/  \\/__/\\/_/\\/____/\\/____/ " << endl;
    cout << "/\\_ \\    __                                                  " << endl;
    cout << "\\/\\ \\  /\\_\\    ___      __   __  __  _____                  " << endl;
    cout << "  \\ \\ \\ \\/\\ \\ /' _ `\\  /'__`\\/\\ \\/\\ \\/\\ '__`\\                " << endl;
    cout << "   \\_\\ \\_\\ \\ \\/\\ \\/\\ \\/\\  __/\\ \\ \\_\\ \\ \\ \\L\\ \\               " << endl;
    cout << "   /\\____\\\\ \\_\\ \\_\\ \\_\\ \\____\\\\ \\____/\\ \\ ,__/               " << endl;
    cout << "   \\/____/ \\/_/\\/_/\\/_/\\/____/ \\/___/  \\ \\ \\/                " << endl;
    cout << "                                        \\ \\_\\                " << endl;
    cout << "                                         \\/_/                " << endl;
    cout << "======================================================================" << endl;
    cout << "  CLI to visualise football lineup when user inputs a lineup format   " << endl;
    cout << "======================================================================" << endl;
    cout << "  By: Group A (Ali Ammar, Aymen Ahmed, Amjed Mahmoud, Wisam Hisham)   " << endl;
    cout << "======================================================================" << endl;
}


void loop(){
    int dash = 0;
    int total = 0;
    int lineupArr[3];
    string lineup = ""; 
    welcome();
    cout << "Enter your lineup(x-y-z): ";
    cin >> lineup;
    if(lineup.length() != 5){
        cout << "[ERROR] Invalid lineup" << endl;
        cout << usage() << endl;
        return;
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
        return;
    }
    if(total !=  10){
        cout << "[ERROR] You can't have more/less than 10 players" << endl;
        return;
    }
    for (int i = 2; i >= 0; i--) {
        print_row(lineupArr[i]);
        cout << endl;
    }
    print_row(1,50,"0");
    cout << endl;
    return;
}

int main(){
    bool keepAlive = true;
    while (keepAlive){
        loop();
        cout << "Do you want to continue? (y/n): ";
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y'){
            keepAlive = true;
        }else if (choice == 'n' || choice == 'N'){
            keepAlive = false;
        }
    }
    return 0;
}