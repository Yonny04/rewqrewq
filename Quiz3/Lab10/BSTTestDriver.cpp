#include "BST.h"
#include <iostream>

using namespace std;

int main() {
    // Create a binary search tree object
    BST bst;

    // Insert elements into the tree
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);
    bst.insert(90);

    // Print the elements of the tree in order
    cout << "In-order traversal of the BST: ";
    bst.printInOrder();
    cout << endl;

    // Get the number of elements in the tree
    cout << "Number of elements in the BST: " << bst.getElementCount() << endl;

    // Get the height of the tree
    cout << "Height of the BST: " << bst.height() << endl;

    // Get the number of nodes in the tree
    cout << "Number of nodes in the BST: " << bst.numberOfNodes() << endl;

    return 0;
}
