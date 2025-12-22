#include <iostream>
#include <windows.h>
#include <fstream>
#include <string> 
using namespace std;

struct filters {
    bool desi;
    bool fastfood;
    bool hotdrinks;
    bool cooldrinks;
    bool dessert;
    bool c1;
    bool c2;
    bool c3;
};

// ---------- Utility Functions ----------

void clearScreen() {
    system("CLS");
}

void setColor(int textColor, int bgColor) {
    SetConsoleTextAttribute(
        GetStdHandle(STD_OUTPUT_HANDLE),
        textColor + (bgColor * 16)
    );
}

// ---------- NUSTeats Star Pattern ----------

void printNUSTEats() {
    setColor(1, 7); // Dark Blue text on White background

    cout << "\n";
    cout << "  ***     **    **      **   *********   ***********                                      \n";
    cout << "  *****   **    **      **   *********   ***********                        **            \n";
    cout << "  ** ***  **    **      **   ****           ***      ********  *******   ********   ******\n";
    cout << "  **  *** **    **      **     ****         ***      **    **       ***     **       **    \n";
    cout << "  **   *****    **      **      ******      ***      ********   *******     **        **   \n";
    cout << "  **    ****    **********   *********      ***      **        *    ***     **         *** \n";
    cout << "  **     ***    **********   *********      ***      ********  **********   *******  ******\n";
    cout << "\n";

    setColor(0, 7); // Reset to black text on white
}

// ---------- Welcome Message ----------

void welcomeMessage() {
    setColor(0, 7); // Black on White
    cout << "                 Welcome to NUSTeats\n";
    cout << "       Where we help you fulfill all your cravings instantly!\n\n";
}

// ---------- Screen 1 ----------

void screen1(int& budget, int& choice) {
    printNUSTEats();
    welcomeMessage();


    do {
        if (budget < 0)cout << "Invalid! Try Again" << endl;

        cout << "Enter your budget (PKR): ";
        cin >> budget;
    } while (budget < 0);
    do {
        cout << "\nChoose Recommendation Mode:\n";
        cout << "1. Personalized\n";
        cout << "2. Randomizer\n";
        cout << "Enter choice (1 or 2): ";
        cin >> choice;
    } while (choice != 1 && choice != 2);
}

// ---------- Screen 2 (Personalized) ----------

void personalizedOptions(int& foodType, int& cafeChoice , filters &filter) {

    while (foodType != 0 && cafeChoice != 0) {
        printNUSTEats();

        cout << "Choosing an option will select it as a filter and make highlighted. choose the option again to deselect it. To display output with respect to the filters, enter 0 as both options.\n";
        cout << "Choose Food Type:\n";
        if (filter.fastfood == 0) {
            cout << "1. Fast Food\n";
        }
        else {
            setColor(1, 7);
            cout << "1. Fast Food\n";
            setColor(0, 7);
        }
        if (filter.desi == 0) {
            cout << "2. Desi\n";
        }
        else {
            setColor(1, 7);
            cout << "2. Desi\n";
            setColor(0, 7);
        }
        if (filter.hotdrinks == 0) {
            cout << "3. Drinks(Hot)\n";
        }
        else {
            setColor(1, 7);
            cout << "3. Drinks(Hot)\n";
            setColor(0, 7);
        }
        if (filter.cooldrinks == 0) {
            cout << "4. Drinks(Cold)\n";
        }
        else {
            setColor(1, 7);
            cout << "4. Drinks(Cold)\n";
            setColor(0, 7);
        }
        if (filter.dessert == 0) {
            cout << "5. Dessert\n";
        }
        else {
            setColor(1, 7);
            cout << "5. Dessert\n";
            setColor(0, 7);
        }
        cout << "Enter choice: ";
        cin >> foodType;

        cout << "\nChoose Cafe:\n";
        if (filter.c1 == 0) {
            cout << "1. C1\n";
        }
        else {
            setColor(1, 7);
            cout << "1. C1\n";
            setColor(0, 7);
        }
        if (filter.c2 == 0) {
            cout << "2. C2\n";
        }else{
            setColor(1, 7);
            cout << "2. C2\n";
            setColor(0, 7);
        }
        if (filter.c3 == 0) {
            cout << "3. C3\n";
        }
        else {
            setColor(1, 7);
            cout << "3. C3\n";
            setColor(0, 7);
        }
        cout << "Enter choice: ";
        cin >> cafeChoice;


        //checks for invalid value of foodtype and updates the filter value according to value
        if (foodType == 1) {
            if (filter.fastfood == 0) {
                filter.fastfood = 1;
            }
            else {
                filter.fastfood = 0;
            }
        }
        else if (foodType == 2) {
            if (filter.desi == 0) {
                filter.desi = 1;
            }
            else {
                filter.desi = 0;
            }
        }
        else if (foodType == 3) {
            if (filter.hotdrinks == 0) {
                filter.hotdrinks = 1;
            }
            else {
                filter.hotdrinks = 0;
            }
        }
        else if (foodType == 4) {
            if (filter.cooldrinks == 0) {
                filter.cooldrinks = 1;
            }
            else {
                filter.cooldrinks = 0;
            }
        }
        else if (foodType == 5) {
            if (filter.dessert == 0) {
                filter.dessert = 1;
            }
            else {
                filter.dessert = 0;
            }
        }
        else if (foodType != 0) {
            cout << "Invalid Choice. Try Again!\n";
        }

        //checks for invalid value of cafechoice and updates the filter value according to value
        if (cafeChoice == 1) {
            if (filter.c1 == 1) {
                filter.c1 = 0;
            }
            else {
                filter.c1 = 1;
            }
        }
        else if (cafeChoice == 2) {
            if (filter.c2 == 1) {
                filter.c2 = 0;
            }
            else {
                filter.c2 = 1;
            }
        }
        else if (cafeChoice == 3) {
            if (filter.c3 == 1) {
                filter.c3 = 0;
            }
            else {
                filter.c3 = 1;
            }
        }
        else if (cafeChoice != 0) {
            cout << "Invalid Choice. Try Again!\n.";
        }
        clearScreen();
    }
}

// ---------- Screen 2 (Randomizer) ----------

void randomizerScreen(int budget) {
    fstream cafe;
    string line,price;
    int counter=0,choice;
    do {
        printNUSTEats();
        cafe.open("c1.txt", ios::in);
        cout << "\nC1: " << endl;
        if (cafe.is_open()) {
            while (getline(cafe, line)) {
                price.clear();
                for (int i = 0; i < line.size(); i++) {
                    if (isdigit(line[i])) {
                        price += line[i];
                    }
                }
                if (stoi(price) <= budget) {
                    if (rand() % 3 == 0) {
                        cout << "Name: ";
                        for (int i = 1; line[i] != '"'; i++) {
                            cout << line[i];
                        }
                        cout << endl;
                        cout << "Price: " << price << endl;
                        counter++;
                        if (counter == 3) {
                            break;
                        }
                    }
                }
            }
        }
        cafe.close();
        price.clear();
        counter = 0;

        cafe.open("c2.txt", ios::in);
        cout << "\nC2: " << endl;
        if (cafe.is_open()) {
            while (getline(cafe, line)) {
                price.clear();
                for (int i = 0; i < line.size(); i++) {
                    if (isdigit(line[i])) {
                        price += line[i];
                    }
                }
                if (stoi(price) <= budget) {
                    if (rand() % 3 == 0) {
                        cout << "Name: ";
                        for (int i = 1; line[i] != '"'; i++) {
                            cout << line[i];
                        }
                        cout << endl;
                        cout << "Price: " << price << endl;
                        counter++;
                        if (counter == 3) {
                            break;
                        }
                    }
                }
            }
        }
        cafe.close();
        price.clear();
        counter = 0;

        cafe.open("c3.txt", ios::in);
        cout << "\nC3: " << endl;
        if (cafe.is_open()) {
            while (getline(cafe, line)) {
                price.clear();
                for (int i = 0; i < line.size(); i++) {
                    if (isdigit(line[i])) {
                        price += line[i];
                    }
                }
                if (stoi(price) <= budget) {
                    if (rand() % 3 == 0) {
                        cout << "Name: ";
                        for (int i = 1; line[i] != '"'; i++) {
                            cout << line[i];
                        }
                        cout << endl;
                        cout << "Price: " << price << endl;
                        counter++;
                        if (counter == 3) {
                            break;
                        }
                    }
                }
            }
        }
        cafe.close();
        price.clear();
        counter = 0;

        cout << "\n1. Reshuffle" << endl;
        cout << "2. End" << endl;
        cin >> choice;
        if (choice == 1) {
            clearScreen();
            continue;
        }
        if (choice == 2) {
            return;
        }

    } while (choice!=1 || choice!=2);
}

// ---------- Screen 3 (Personalized Results) ----------

void personalizedResults(int budget , filters& filter) {
    fstream cafe;
    string line,price;

    printNUSTEats();

    cout << "Personalized Recommendations\n\n";

    if (filter.c1 == 1) {
        cout << "C1: " << endl;
        cafe.open("c1.txt", ios::in);
        if (cafe.is_open()) {
            string line;
            while (getline(cafe, line)) {
                for (int i = 0; i < line.size(); i++) {
                    if (isdigit(line[i])) {
                        price += line[i];
                    }
                }
                if (stoi(price) <= budget) {
                    if (filter.fastfood == 1) {
                        if (line.find("fastfood") != string::npos) {
                            cout << "Name: ";
                            for (int i = 1; line[i] != '"'; i++) {
                                cout << line[i];
                            }
                            cout << endl;
                            cout << "Price: " << price << endl;
                        }
                    }
                    if (filter.desi == 1) {
                        if (line.find("desi") != string::npos) {
                            cout << "Name: ";
                            for (int i = 1; line[i] != '"'; i++) {
                                cout << line[i];
                            }
                            cout << endl;
                            cout << "Price: " << price << endl;
                        }
                    }
                    if (filter.hotdrinks == 1) {
                        if (line.find("drink hot") != string::npos) {
                            cout << "Name: ";
                            for (int i = 1; line[i] != '"'; i++) {
                                cout << line[i];
                            }
                            cout << endl;
                            cout << "Price: " << price << endl;
                        }
                    }
                    if (filter.cooldrinks == 1) {
                        if (line.find("drink cold") != string::npos) {
                            cout << "Name: ";
                            for (int i = 1; line[i] != '"'; i++) {
                                cout << line[i];
                            }
                            cout << endl;
                            cout << "Price: " << price << endl;
                        }
                    }
                    if (filter.dessert == 1) {
                        if (line.find("dessert") != string::npos) {
                            cout << "Name: ";
                            for (int i = 1; line[i] != '"'; i++) {
                                cout << line[i];
                            }
                            cout << endl;
                            cout << "Price: " << price << endl;
                        }
                    }
                }
                price.clear();
            }
            cafe.close();
        }
    }

    if (filter.c2 == 1) {
        cout << "\nC2:" << endl;
        cafe.open("c2.txt", ios::in);
        if (cafe.is_open()) {
            string line;
            while (getline(cafe, line)) {
                for (int i = 0; i < line.size(); i++) {
                    if (isdigit(line[i])) {
                        price += line[i];
                    }
                }
                if (stoi(price) <= budget) {
                    if (filter.fastfood == 1) {
                        if (line.find("fastfood") != string::npos) {
                            cout << "Name: ";
                            for (int i = 1; line[i] != '"'; i++) {
                                cout << line[i];
                            }
                            cout << endl;
                            cout << "Price: " << price << endl;
                        }
                    }
                    if (filter.desi == 1) {
                        if (line.find("desi") != string::npos) {
                            cout << "Name: ";
                            for (int i = 1; line[i] != '"'; i++) {
                                cout << line[i];
                            }
                            cout << endl;
                            cout << "Price: " << price << endl;
                        }
                    }
                    if (filter.hotdrinks == 1) {
                        if (line.find("drink hot") != string::npos) {
                            cout << "Name: ";
                            for (int i = 1; line[i] != '"'; i++) {
                                cout << line[i];
                            }
                            cout << endl;
                            cout << "Price: " << price << endl;
                        }
                    }
                    if (filter.cooldrinks == 1) {
                        if (line.find("drink cold") != string::npos) {
                            cout << "Name: ";
                            for (int i = 1; line[i] != '"'; i++) {
                                cout << line[i];
                            }
                            cout << endl;
                            cout << "Price: " << price << endl;
                        }
                    }
                    if (filter.dessert == 1) {
                        if (line.find("dessert") != string::npos) {
                            cout << "Name: ";
                            for (int i = 1; line[i] != '"'; i++) {
                                cout << line[i];
                            }
                            cout << endl;
                            cout << "Price: " << price << endl;
                        }
                    }
                }
                price.clear();
            }
            cafe.close();
        }
    }

    if (filter.c3 == 1) {
        cout << "\nC3:" <<endl;
        cafe.open("c3.txt", ios::in);
        if (cafe.is_open()) {
            string line;
            while (getline(cafe, line)) {
                for (int i = 0; i < line.size(); i++) {
                    if (isdigit(line[i])) {
                        price += line[i];
                    }
                }
                if (stoi(price) <= budget) {
                    if (filter.fastfood == 1) {
                        if (line.find("fastfood") != string::npos) {
                            cout << "Name: ";
                            for (int i = 1; line[i] != '"'; i++) {
                                cout << line[i];
                            }
                            cout << endl;
                            cout << "Price: " << price << endl;
                        }
                    }
                    if (filter.desi == 1) {
                        if (line.find("desi") != string::npos) {
                            cout << "Name: ";
                            for (int i = 1; line[i] != '"'; i++) {
                                cout << line[i];
                            }
                            cout << endl;
                            cout << "Price: " << price << endl;
                        }
                    }
                    if (filter.hotdrinks == 1) {
                        if (line.find("drink hot") != string::npos) {
                            cout << "Name: ";
                            for (int i = 1; line[i] != '"'; i++) {
                                cout << line[i];
                            }
                            cout << endl;
                            cout << "Price: " << price << endl;
                        }
                    }
                    if (filter.cooldrinks == 1) {
                        if (line.find("drink cold") != string::npos) {
                            cout << "Name: ";
                            for (int i = 1; line[i] != '"'; i++) {
                                cout << line[i];
                            }
                            cout << endl;
                            cout << "Price: " << price << endl;
                        }
                    }
                    if (filter.dessert == 1) {
                        if (line.find("dessert") != string::npos) {
                            cout << "Name: ";
                            for (int i = 1; line[i] != '"'; i++) {
                                cout << line[i];
                            }
                            cout << endl;
                            cout << "Price: " << price << endl;
                        }
                    }
                }
                price.clear();
            }
            cafe.close();
        }
    }


    
}

// ---------- Main Function ----------

int main() {
    int budget=0, choice;
    int foodType=-1, cafeChoice=-1;
    filters filter = { 0,0,0,0,0,0,0,0 };

    setColor(0, 7); // Black text, White background
    clearScreen();

    // Screen 1
    screen1(budget, choice);
    clearScreen();

    // Screen flow
    if (choice == 1) {
        personalizedOptions(foodType, cafeChoice, filter);
        clearScreen();
        personalizedResults(budget , filter);
    }
    else if (choice == 2) {
        randomizerScreen(budget);
    }
    else {
        cout << "Invalid choice!";
    }

    cout << "\n\nThank you for using NUSTeats!\n";
    system("pause");
    return 0;
}
