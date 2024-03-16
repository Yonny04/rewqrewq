#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "Dictionary.h"
#include "WordPair.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"
#include "UnableToInsertException.h"

using std::cin;
using std::cout;
using std::ifstream;
using std::nothrow;
using std::endl;

void display(WordPair& anElement) {
    cout << anElement;
}

int main(int argc, char *argv[]) {
    // Check if a filename was provided as a command-line argument
    string filename = (argc > 1) ? argv[1] : "myDataFile.txt";

    // Instantiate a Dictionary object
    Dictionary * testing = new Dictionary();

    string aLine = "";
    string aWord = "";
    string englishW = "";
    string translationW = "";
    string filename = "";
    string delimiter = ":";
    size_t pos = 0;
    WordPair translated;

    // Open the file for reading
    ifstream myfile(filename);
    if (myfile.is_open()) {
        cout << "Reading from a file: " << filename << endl;

        // Read each line from the file
        while (getline(myfile, aLine)) {
            // Find the position of the delimiter
            pos = aLine.find(delimiter);

            // Extract English word and translation from the line
            string englishW = aLine.substr(0, pos);
            string translationW = aLine.substr(pos + delimiter.length());

            // Create a WordPair object
            WordPair aWordPair(englishW, translationW);

            // Insert the WordPair into the dictionary
            try {
                testing->put(aWordPair);
            } catch (ElementAlreadyExistsException &exc) {
                cout << "Duplicate!" << exc.what() << endl;
            } catch (UnableToInsertException &exc) {
                cout << "Unable to Insert " << exc.what() << endl;
            }
        }
        myfile.close();
    } else {
        cout << "Unable to open file" << endl;
        return 1; // Exit with error
    }

    // If user entered "display" at the command line, print the content of the dictionary
    if (argc > 1 && strcmp(argv[1], "display") == 0) {
        testing->displayContent(display);
    } else {
        // Read input from the user
        string userInput;
        while (getline(cin, userInput)) {
            // Check if user entered "display"
            if (userInput == "display") {
                testing->displayContent(display);
            } else {
               // Translate the English word using the Dictionary object
               WordPair aWP(userInput);
               try {
                   WordPair translation = testing->get(aWP);
                   cout << userInput << ":" << translation.getTranslation() << endl;
               } catch (ElementDoesNotExistException &exc) {
                   cout << "***Not Found!***" << endl;
               }
            }
        }
    }
    delete testing; // Free memory allocated for the Dictionary object
    return 0;
}