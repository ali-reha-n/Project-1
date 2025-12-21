#include <iostream>
#include <windows.h>
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
    printNUSTEats();

    cout << "Random Food Recommendation\n\n";

    string cafe = "C1";
    string item = "Zinger Burger";
    int price = 420;

    cout << "Cafe  : " << cafe << endl;
    cout << "Item  : " << item << endl;
    cout << "Price : PKR " << price << endl;

    if (price > budget) {
        setColor(12, 7); // Red text on White
        cout << "\nWARNING: This item exceeds your budget!\n";
        setColor(0, 7);
    }
}

// ---------- Screen 3 (Personalized Results) ----------

void personalizedResults(int budget) {
    printNUSTEats();

    cout << "Personalized Recommendations\n\n";

    // Placeholder (my partner will add filtering logic)
    string cafe = "Retro";
    string item = "Chicken Shawarma";
    int price = 350;

    cout << "Cafe  : " << cafe << endl;
    cout << "Item  : " << item << endl;
    cout << "Price : PKR " << price << endl;

    if (price > budget) {
        setColor(12, 7); // Red warning
        cout << "\nWARNING: This item exceeds your budget!\n";
        setColor(0, 7);
    }
}

// ---------- Main Function ----------

int main() {
    int budget, choice;
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
        personalizedResults(budget);
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
