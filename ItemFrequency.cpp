/*
 * Dat Nguyen
 * Module 7
 * Project 3: Corner Grocer
 * Purpose: This file implements the ItemFrequency class defined in ItemFrequency.h. The class is responsible for
 *          analyzing the frequency of items based on data read from a specified input file. It includes methods
 *          for calculating item frequencies, printing these frequencies to the console, generating a histogram,
 *          and retrieving the frequency of a specific item. This implementation handles file input/output operations
 *          and data processing to provide the necessary functionality for frequency analysis.
 */


#include "ItemFrequency.h"
#include <fstream>  // For file input/output operations
#include <iostream> // For console input/output operations

// Constructor: Initializes the ItemFrequency object with a specific input file name.
ItemFrequency::ItemFrequency(const std::string& inputFilename) : filename(inputFilename) {}

// Calculates the frequencies of each item listed in the input file.
void ItemFrequency::CalculateFrequencies() {
    std::ifstream inFile(filename); // Open the input file for reading.

    // Check if the file was successfully opened.
    if (!inFile) {
        std::cerr << std::endl << "Error opening file: " << filename << std::endl;
        return; // Exit the function if file cannot be opened.
    }

    std::string item; // Variable to hold each item read from the file.
    // Read items from the file one by one.
    while (inFile >> item) {
        frequencies[item]++; // Increment the frequency count for each item.
    }

    // Once all items are read, write the frequencies to a backup file.
    WriteFrequenciesToFile();
}

// Writes the calculated frequencies to a backup file named 'frequency.dat'.
void ItemFrequency::WriteFrequenciesToFile() const {
    std::ofstream outFile("frequency.dat"); // Open or create 'frequency.dat' for writing.

    // Check if the file was successfully opened/created.
    if (!outFile) {
        std::cerr << std::endl << "Error creating backup file." << std::endl;
        return; // Exit the function if file cannot be opened/created.
    }

    // Iterate over the frequencies map and write each item and its frequency to the file.
    for (const auto& pair : frequencies) {
        outFile << pair.first << " " << pair.second << std::endl;
    }
}

// Prints the frequencies of all items to the console.
void ItemFrequency::PrintFrequencies() const {
    std::cout << std::endl; // Print a newline for better readability.
    // Iterate over the frequencies map.
    for (const auto& pair : frequencies) {
        // Print each item and its frequency.
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

// Prints a histogram representing the frequencies of items.
void ItemFrequency::PrintHistogram() const {
    std::cout << std::endl; // Print a newline for better readability.
    // Iterate over the frequencies map.
    for (const auto& pair : frequencies) {
        std::cout << pair.first << " "; // Print the item name.
        PrintHistogramLine(pair.second); // Print the histogram line for this item.
        std::cout << std::endl; // Print a newline after each histogram line.
    }
}

// Helper function to print a single histogram line.
void ItemFrequency::PrintHistogramLine(int count) const {
    // Print 'count' number of asterisks.
    for (int i = 0; i < count; ++i) {
        std::cout << "*";
    }
}

// Returns the frequency of a specific item, given its name.
int ItemFrequency::GetFrequency(const std::string& itemName) const {
    // Find the item in the frequencies map.
    auto it = frequencies.find(itemName);
    // Return the frequency if the item is found, otherwise return 0.
    return it != frequencies.end() ? it->second : 0;
}
