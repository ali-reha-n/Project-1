# NUSTEats – Food Recommendation System
**Project Overview**
- NUSTEats is a console-based food recommendation system developed in C++ for students of the National University of Sciences and Technology (NUST).
- The purpose of this project is to help students decide what to eat on campus by suggesting food options based on their budget and preferences, or by giving a random recommendation.
- The program follows a simple screen-by-screen workflow and provides a clean console interface for easy interaction.
  
**Objectives**
- The main objective of this project is to assist users in choosing food items that fit within their budget.
- Another objective is to provide two different recommendation modes so that users can either customize their choice or receive a quick random suggestion.
-  The project also aims to apply basic programming concepts such as functions, input/output handling, and conditional statements in C++.
  
**Features**
- **Personalized Mode:**
In personalized mode, the user first enters a budget and then selects a type of food and a café. Based on these choices, the system displays a food recommendation. If the price of the suggested item is higher than the entered budget, the system displays a warning message to inform the user.
- **Randomizer Mode:**
In randomizer mode, the user only needs to enter a budget. The system then directly shows a food recommendation along with the café name, item name, and price.

**User Manual**
- **Step 1:** Running the Program
When the program is run in a Windows console, the NUSTEats logo is displayed using a star pattern, followed by a welcome message.
- **Step 2:** Entering the Budget
The user is asked to enter their available budget in Pakistani Rupees. This value is used to check whether the recommended food item is affordable or not.
- **Step 3:** Selecting Recommendation Mode
The user is then asked to choose between Personalized mode and Randomizer mode by entering the corresponding number.
- **Step 4A:** Using Personalized Mode
If Personalized mode is selected, the user is prompted to choose a food category and a café. The program displays the selected cafe and kind of food in blue color. If the user wishes to deselect then he can enter the serial number of of the cafe and kind of food again, but if the user is certain in his choices, then he can proceed by entering 0 as input for both food and cafe after they have been selected. After the selections are made, the system displays a suitable food recommendation.
- **Step 4B:** Using Randomizer Mode
If Randomizer mode is selected, the system immediately displays a food recommendation without asking for further input.
- **Step 5:** Budget Warning
If the recommended food item costs more than the user’s budget, a warning message appears on the screen in red text to clearly indicate that the item is over budget.
- **Step 6:** Ending the Program
After displaying the recommendation, the program shows a closing message and ends when the user presses a key.
User Interface Design
The program uses a white background to keep the interface clean and easy to read. The NUSTeats logo is shown in dark blue to highlight the program name, while normal text appears in black. Warning messages are displayed in red so they are easily noticeable.

**Technologies Used**

This project is developed using the C++ programming language and runs in a Windows console environment. The iostream library is used for handling input and output, while windows.h is used for controlling console colors and clearing the screen. File handling has been used for the menu.

**Program Structure**

The program is divided into multiple functions, with each function handling a specific screen or task. This makes the code more organized, easier to understand, and simpler to modify in the future.

**Contributors**
- Ali Rehan
- Umayrah Masood Malik
  
**Future Improvements**

In the future, more cafés and food items can be added to the system. The overall layout and alignment of the console output can also be improved. Additional features such as allowing multiple searches in one run or improving the randomness of recommendations can further enhance the system.
