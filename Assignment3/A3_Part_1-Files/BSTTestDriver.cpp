/*
 * BSTTestDriver.cpp
 * 
 * Description: Drives the testing of the BST ADT class. 
 *
 * Author: AL
 * Last Modification Date: Feb. 2024
 */

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "BST.h"
#include "WordPair.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"
#include "UnableToInsertException.h"

using std::cin;
using std::cout;
using std::ifstream;
using std::nothrow;


void display(WordPair& anElement) {
  cout << anElement;
} 


// As you discover what main() does, record your understanding of the code by commenting it.
// If you do not like this main(), feel free to write your own.
// Remember, this is a test driver. Feel free to modify it as you wish!
// ... (previous includes and definitions)

int main(int argc, char *argv[]) {

    BST *testing = new (nothrow) BST();
    if (testing != nullptr) {

        string aLine = "";
        string englishW = "";
        string translationW = "";
        string filename = "";
        string delimiter = ":";
        size_t pos = 0;

        // Expecting at least a filename on the command line.
        if ((argc > 1)) {
            filename = argv[1];

            ifstream myfile(filename);
            if (myfile.is_open()) {
                cout << "Reading from a file:" << endl;  // For debugging purposes
                while (getline(myfile, aLine)) {
                    // Parse the line into English and translation using the delimiter ":"
                    pos = aLine.find(delimiter);
                    englishW = aLine.substr(0, pos);
                    aLine.erase(0, pos + delimiter.length());
                    translationW = aLine;

                    // Create a WordPair from parsed values
                    WordPair aWordPair(englishW, translationW);

                    try {
                        // Insert aWordPair into "testing" using a try/catch block
                        testing->insert(aWordPair);
                        cout << "Inserted: " << aWordPair << endl;
                    } catch (const ElementAlreadyExistsException &e) {
                        cout << "Error: " << e.what() << endl;
                    } catch (const UnableToInsertException &e) {
                        cout << "Error: " << e.what() << endl;
                    }
                    
                    try{
                    	cout << "Retrieving "<< testing -> retrieve(aWordPair)<<endl;
                    	
                    }
                    catch (const ElementDoesNotExistException &e) {
                        cout << "Error: " << e.what() << endl;
                    } catch (const EmptyDataCollectionException &e) {
                        cout << "Error: " << e.what() << endl;
                    }
                }
                WordPair aWordPair("DNE", "DNE");
                try{
                    	cout << "Retrieving"<< testing -> retrieve(aWordPair)<<endl;
                    	
                    }
                    catch (const ElementDoesNotExistException &e) {
                        cout << "Error: " << e.what() << endl;
                    } catch (const EmptyDataCollectionException &e) {
                        cout << "Error: " << e.what() << endl;
                    }
                
                myfile.close();

                // More BST testing happening here!
                cout << "Number of elements in the BST: " << testing->getElementCount() << endl;

                // Traversing and displaying elements in order
                cout << "In-order traversal of the BST:" << endl;
                testing->traverseInOrder(display);
                cout << endl;
                BST* testing_copy = new BST(*testing); 
                cout<< endl;
                cout<< "now traverse copy"<<endl;
                testing_copy->traverseInOrder(display);
                cout<< endl;
                delete testing;
                 cout<< endl;
                cout<< "now traverse copy after"<<endl;
                testing_copy->traverseInOrder(display);
                cout<< endl;
                testing->traverseInOrder(display);

            } else
                cout << "Unable to open file" << endl;
        } else
            cout << "Missing the data filename!" << endl;

        // Clean up allocated memory
        //delete testing;
    } else
        cout << "new failed!" << endl;

    return 0;
}