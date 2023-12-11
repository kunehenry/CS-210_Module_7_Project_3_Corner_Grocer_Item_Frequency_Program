/*
 * Dat Nguyen
 * Module 7
 * Project 3: Corner Grocer
 * Purpose: This file implements the UserInterface class defined in UserInterface.h. It handles all aspects of
 *          user interaction for the application. The class provides a console-based interface for users to
 *          interact with the ItemFrequency class functionalities. This includes displaying a menu, processing
 *          user input, and executing actions such as calculating and displaying item frequencies, and
 *          generating histograms. This implementation is focused on providing a user-friendly and
 *          interactive experience for analyzing item frequencies.
 */


#include "UserInterface.h"
#include <iostream> // Include for standard input and output stream objects
#include <string>   // Include for using the std::string class
#include <limits>   // Include for std::numeric_limits

// Constructor: Initializes the UserInterface with a reference to an ItemFrequency object
UserInterface::UserInterface(const ItemFrequency& itemFreq) : itemFrequency(itemFreq) {}

// Prints the main menu options to the console
void UserInterface::PrintMenu() const {
    std::cout << "\nMENU\n"
              << "1. Get Frequency of a Specific Item\n"
              << "2. Print All Item Frequencies\n"
              << "3. Print Histogram\n"
              << "4. Exit\n"
              << "Enter your choice: ";
}

// Retrieves and validates the user's choice from the menu
int UserInterface::GetUserChoice() const {
    int choice;
    while (true) {
        if (std::cin >> choice) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the input buffer
            return choice;
        } else if (std::cin.eof()) {
            // Handle end-of-file condition (e.g., Ctrl+D)
            std::cerr << "End of input detected. Exiting program.\n";
            exit(EXIT_FAILURE);
        } else {
            // Handle invalid input
            std::cout << "Invalid input. Please enter a number between 1 and 4.\n";
            std::cin.clear(); // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the input buffer
        }
    }
}

// Manages the user's choice and calls the appropriate method based on the choice
void UserInterface::HandleUserChoice() {
    while (true) {
        PrintMenu();
        int choice = GetUserChoice();
        switch (choice) {
            case 1:
                HandleGetFrequency();
                break;
            case 2:
                HandlePrintFrequencies();
                break;
            case 3:
                HandlePrintHistogram();
                break;
            case 4:
                std::cout << "Exiting program.\n";
                return;
            default:
                std::cout << "Invalid option. Please try again.\n";
        }
    }
}

// Handles the functionality to get and display the frequency of a specific item
void UserInterface::HandleGetFrequency() const {
    std::string item;
    std::cout << "Enter item name: ";
    getline(std::cin, item); // Get the item name from user input
    std::cout << item << ": " << itemFrequency.GetFrequency(item) << "\n"; // Display the frequency of the item
}

// Calls ItemFrequency's method to print all item frequencies
void UserInterface::HandlePrintFrequencies() const {
    itemFrequency.PrintFrequencies();
}

// Calls ItemFrequency's method to print the histogram of item frequencies
void UserInterface::HandlePrintHistogram() const {
    itemFrequency.PrintHistogram();
}
