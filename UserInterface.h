/*
 * Dat Nguyen
 * Module 7
 * Project 3: Corner Grocer
 * Purpose: This file defines the UserInterface class, which handles all the user interactions in the application.
 *          The class provides a console-based interface for interacting with the ItemFrequency class. It includes
 *          methods for displaying a menu, handling user input, and executing actions based on user choices.
 *          UserInterface acts as the front-end for the frequency analysis functionalities provided by ItemFrequency,
 *          allowing users to retrieve and view data in an easy and interactive manner.
 */


// Header guards to prevent multiple inclusions of this header file.
#ifndef USERINTERFACE_H
#define USERINTERFACE_H

// Including the ItemFrequency class to use its functionalities.
#include "ItemFrequency.h"

// The UserInterface class handles all user interactions for the application.
class UserInterface {
public:
    // Constructor: Initializes UserInterface with a reference to an ItemFrequency object.
    // The explicit keyword prevents implicit conversions of the parameter to a UserInterface object.
    explicit UserInterface(const ItemFrequency& itemFreq);

    // Displays the main menu to the user in the console.
    void PrintMenu() const;

    // Retrieves the user's choice from the menu. It validates the input to ensure it's an integer.
    int GetUserChoice() const;

    // Processes the user's choice from the menu and calls the appropriate handling method.
    void HandleUserChoice();

private:
    // Handles the functionality when the user chooses to get the frequency of a specific item.
    // It prompts the user for the item name and displays its frequency.
    void HandleGetFrequency() const;

    // Handles the functionality when the user chooses to display frequencies of all items.
    // It invokes ItemFrequency's method to print all item frequencies.
    void HandlePrintFrequencies() const;

    // Handles the functionality when the user chooses to display the histogram of item frequencies.
    // It invokes ItemFrequency's method to print the histogram.
    void HandlePrintHistogram() const;

    // A reference to an ItemFrequency object to access its methods for frequency analysis.
    const ItemFrequency& itemFrequency;
};

// End of the header guard.
#endif // USERINTERFACE_H
