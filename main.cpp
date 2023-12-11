/*
 * Dat Nguyen
 * Module 7
 * Project 3: Corner Grocer
 * Purpose: This is the main entry point for a frequency analysis application designed for the Corner Grocer.
 *          The program uses the ItemFrequency and UserInterface classes to analyze item frequencies from
 *          a given input file and interact with the user. The program reads item data from "CS210_Project_Three_Input_File.txt",
 *          calculates the frequency of each item, and provides a user interface for displaying this data.
 *          Users can view item frequencies, a histogram of these frequencies, or the frequency of a specific item.
 *          The UserInterface class handles all user interactions, while the ItemFrequency class handles the
 *          data processing and analysis.
 */


// Include the necessary header files for the ItemFrequency and UserInterface classes.
#include "ItemFrequency.h"
#include "UserInterface.h"

// The main function - entry point of the program.
int main() {
    // Define a string variable to hold the name of the input file.
    std::string inputFilename = "CS210_Project_Three_Input_File.txt";

    // Create an instance of ItemFrequency, initializing it with the input file name.
    ItemFrequency itemFreq(inputFilename);

    // Call the method to calculate the frequencies of items from the input file.
    itemFreq.CalculateFrequencies();

    // Create an instance of UserInterface, passing the ItemFrequency instance to it.
    // This allows the UserInterface to use the functionalities of ItemFrequency.
    UserInterface ui(itemFreq);

    // Call the method to handle the user's choices and interact with the user
    // based on those choices. This is the main loop for user interaction.
    ui.HandleUserChoice();

    // Return 0 to indicate successful execution of the program.
    return 0;
}
