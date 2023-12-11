/*
 * Dat Nguyen
 * Module 7
 * Project 3: Corner Grocer
 * Purpose: This file defines the ItemFrequency class, which is responsible for analyzing and reporting
 *          the frequency of items based on data read from an input file. The class provides functionality
 *          to read item data from a specified file, calculate the frequency of each item, and display
 *          this information in various formats. It includes methods to print the calculated frequencies,
 *          generate a histogram visualization, and retrieve the frequency of a specific item.
 */


// Header guards to prevent multiple inclusion of this header file.
#ifndef CORNER_GROCER_ITEMFREQUENCY_H
#define CORNER_GROCER_ITEMFREQUENCY_H

// Including necessary standard libraries.
#include <string> // For using std::string.
#include <map>    // For using std::map.

// Definition of the ItemFrequency class.
class ItemFrequency {
public:
    // Constructor with explicit keyword to prevent implicit conversions.
    // Takes a string representing the filename to read data from.
    explicit ItemFrequency(const std::string& inputFilename);

    // Calculates the frequencies of each item in the input file.
    void CalculateFrequencies();

    // Prints the frequency of each item to the console.
    void PrintFrequencies() const;

    // Prints a histogram representing the frequency of each item.
    void PrintHistogram() const;

    // Returns the frequency of a specific item given its name.
    // Takes a string (item name) and returns an integer (frequency).
    int GetFrequency(const std::string& itemName) const;

private:
    // Writes the calculated frequencies to a backup file.
    // This method is private as it's an internal utility function.
    void WriteFrequenciesToFile() const;

    // Helper function to print a single line of the histogram.
    // Takes an integer count and prints that many asterisks.
    // This method is private as it's used internally by PrintHistogram.
    void PrintHistogramLine(int count) const;

    // Map to store the frequency of each item.
    // Key: item name (string), Value: frequency (int).
    std::map<std::string, int> frequencies;

    // String to store the name of the file containing the item data.
    std::string filename;
};

// End of the header guard.
#endif // CORNER_GROCER_ITEMFREQUENCY_H
