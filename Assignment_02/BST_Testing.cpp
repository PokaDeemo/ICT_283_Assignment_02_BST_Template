#include "BST.h"
#include <iostream>

using namespace std;

// Printing the BST
template <class elemType>
void print (elemType& nodeType)
{
    cout << nodeType << endl;
}

int main()
{
    BST<int> tree;

    cout <<" --- BST Testing --- "<< endl;
    cout << endl;

    tree.Insert(1);
    tree.Insert(2);
    tree.Insert(50);
    //tree.~BST(); // Testing for Delete BST.
    tree.Insert(10);
    tree.Insert(49);
    tree.Insert(55);
    tree.Insert(83);
    tree.Insert(9);


    cout << "Tree populated." << endl;

    cout << endl;

    cout << " --- BST Search --- " << endl;
    if(tree.Search(53) == true)
    {
        cout << "53 is true" << endl;
    }
    else
    {
        cout << "53 is false" << endl;
    }
    if (tree.Search(83) == true)
    {
        cout << "83 is true" << endl;
    }
    else
    {
        cout << "83 is false" << endl;
    }
    if (tree.Search(50) == true)
    {
        cout << "50 is true" << endl;
    }
    else
    {
        cout << "50 is false" << endl;
    }

    cout << endl;
    cout << "-----------------------------------------------------" << endl;
    cout <<" (tree1) In-order Traversal Test "<<endl;
    tree.InOrderTraversal(print);
    cout << endl;
    cout << "-----------------------------------------------------" << endl;
    cout <<" (tree1) Pre-order Traversal Test "<<endl;
    tree.PreOrderTraversal(print);
    cout << endl;
    cout << "-----------------------------------------------------" << endl;
    cout <<" (tree1) Post-order Traversal Test "<<endl;
    tree.PostOrderTraversal(print);
    cout << endl;
    // Copy Constructor
    cout << "-----------------------------------------------------" << endl;
    cout << "(tree2) Copy Constructor and = Operator Test (Print In-order)" << endl;
    BST<int> tree2(tree);
    // to tree = tree2;
    tree2.InOrderTraversal(print);
    return 0;
}

