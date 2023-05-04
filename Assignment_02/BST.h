#ifndef BST_H
#define BST_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/**
   * @class BST
   * @brief BST is a template class that manage all the data structure function about Binary Search Tree
   * @author Tan Hong Rui Freeman
   * @version 01
   * @date 21/11/2022 Freeman Tan, Started
   *
   */

template <class elemType>
struct NodeType
{
    elemType info;
    NodeType * lLink;
    NodeType * rLink;
};

template <class elemType>
class BST
{
public:
    BST();
    /**
    * @brief Default Constructor of BST
    * @param This function will set the root to nullptr
    * @return none
    */

    ~BST();
    /**
    * @brief Destructor of BST
    * @param This function will destroy the BST
    * @return none
    */

    /*bool SearchItem(const elemType& newNode) const;
    /**
    * @brief an public function to call the private function of Search() method
    * @brief on the BST template
    * @brief Search the tree for the item/newNode
    * @brief newNode - item to be search in the BST.
    * @return boolean - return true if item is found.
    */

    bool Search(const elemType searchTree) const;
    /**
    * @brief an public function to search for an element in the BST
    * @param searchTree - element of elemType
    * @return boolean - If true it will return the searchTree item was found in the BST
    */

    void Insert (const elemType insertItem);
    /**
    * @brief an public function to add or insert a new element into the BST
    * @param insertItem - element of elemType
    * @return void
    * @post The BST is the old BST plus the insertItem
    */

    /*void InsertItem(const elemType& insertItem);
    /**
    * @brief an public function to call the private function of Insert() method
    * @brief on the BST template
    * @param Insert the given/request item into the tree
    * @param insertItem - item to be inserted into the tree.
    */

    void Delete(NodeType<elemType> * &p);
    /**
    * @brief an public function to destroy the node in the BST
    * @param deallocate memory of all the node in the tree
    * @param p - node to be deallocate memory
    * @return void
    */

    void InOrderTraversal(void (*visit)(elemType&)) const;
    /**
    * @brief an public function to call the private function to do in-order traversal
    * @param The visit pointer will point to the void function that take elemType& as the parameter
    * @return void
    */

    void PreOrderTraversal(void (*visit) (elemType&)) const;
    /**
    * @brief an public function to call the private function to do pre-order traversal
    * @param The visit pointer will point to the void function that take elemType& as the parameter
    * @return void
    */

    void PostOrderTraversal(void (*visit) (elemType&)) const;
    /**
    * @brief an public function to call the private function to do post-order traversal
    * @param The visit pointer will point to the void function that take elemType& as the parameter
    * @return void
    */

    const BST<elemType>& operator =(const BST<elemType>&);
    /**
    * @brief an public function to the = operator function using the Copy Constructor Method
    * @param This is mostly for the deep copying of the BST using both Copy Constructor method and = operator
    * @return void
    */

    elemType MinValue();
    /**
     * @brief Finds the minimum value in the BST
     * @return elemType
     */

    elemType MaxValue();
    /**
     * @brief Finds the maxi
     * @return elemType
     */

private:
    typedef NodeType<elemType> BSTNode;

    BSTNode *root;
    /**
    * @brief The root of the tree
    */

    void InOrder(NodeType<elemType> *p, void(*visit) (elemType&)) const;
    /**
    * @brief an private function to do in-order traversal with function pointer
    * @param The visit pointer will point to the void function and take elemType& as parameter,
    * @param p-pointer is the tree node
    * @return void
    */

    void PreOrder(NodeType<elemType> *p, void(*visit)(elemType&)) const;
    /**
    * @brief an private function to do pre-order traversal with function pointer
    * @param The visit pointer will point to the void function and take elemType& as parameter,
    * @param p-pointer is the tree node
    * @return void
    */

    void PostOrder(NodeType<elemType> *p, void(*visit)(elemType&)) const;
    /**
    * @brief an private function to do post-order traversal with function pointer
    * @param The visit pointer will point to the void function and take elemType& as parameter,
    * @param p-pointer is the tree node
    * @return void
    */

    // Recursive Search
    /*bool Search(const elemType& newNode, BSTNode* current) const;
    /**
    *@brief an private function to Search the tree for the item
    *@param Search the BST for a specific/given item.
    *@param If the item is found in the BST it will return true if not it will return false.
    *@param newNode is the item to be search in the tree
    *@return boolean if newNode is found it will return true else return false.
    */

    // Recursive Insert
    /*BSTNode* Insert(BSTNode* newNode, BSTNode* current);
    /**
    *@brief an private function to Insert the node into the tree
    *@param Insert the given node into the tree
    *@param If the item is found/exist in the BST it will return false
    *@param it will returns true if the item is inserted into the tree.
    *@param newNode - item to be added into the tree
    *@param current - current node
    *@return BSTNode
    */

    void CopyNodes(BSTNode* &current, BSTNode* otherItems);
    /**
    *@brief an private method for the copy constructor
    *@param Copy constructor will copy the current item to the other items
    *@param if current item is empty it will return nullptr value if not it will do the Copy Constructor
    *@param current item element has copy into otherItems
    *@return both current item and otherItems element
    */
};

template <class elemType>
BST<elemType>::BST()
{
    root = nullptr;
}

template <class elemType>
bool BST<elemType>::Search(const elemType searchTree) const
{
    NodeType<elemType> * current;
    bool found = false;
    if(root == nullptr)
    {
        cout << "Cannot search on a empty tree !!" << endl;
    }
    else
    {
        current = root;
        while(current != nullptr && !found)
        {
            if(searchTree == current->info)
            {
                found = true;
            }
            else if(searchTree < current->info)
            {
                current = current -> lLink;
            }
            else
            {
                current = current ->rLink;
            }
        }
    }
    // cout << "Found:" << found << endl;
    // cout << "Found:" << searchTree << endl;
    return found;
}

// Recursive Search from Lab 9 B and Lab 10 D BST
/*
template <class elemType>
bool BST<elemType>::Search(const elemType& newNode, BSTNode* current) const
{
    if(current != nullptr)
    {
        if(current->info == newNode)
        {
            return true;
        }
        else if(current-> info > newNode)
        {
            return Search(newNode, current->lLink);
        }
        else
        {
            return Search(newNode, current->rLink);
        }
    }
    return false;
}

template <class elemType>
bool BST<elemType>::SearchItem(const elemType& newNode)const
{
    return Search(newNode, root);
}*/

//Iterative Insert
template <class elemType>
void BST <elemType>::Insert (const elemType insertTree)
{
    NodeType<elemType> *current;
    NodeType<elemType> *trailCurrent = nullptr;
    NodeType<elemType> *newNode;

    newNode = new NodeType<elemType>;
    newNode -> info = insertTree;
    newNode -> lLink = nullptr;
    newNode -> rLink = nullptr;
    if(root == nullptr)
    {
        root = newNode;
    }
    else
    {
        current = root;
        while(current != nullptr)
        {
            trailCurrent = current;
            if(insertTree == current -> info)
            {
                return;
            }
            else
            {
                if(insertTree < current -> info)
                {
                    current = current -> lLink;
                }
                else
                {
                    current = current -> rLink;
                }
            }
        }
        if(insertTree < trailCurrent -> info)
        {
            trailCurrent -> lLink = newNode;
        }
        else
        {
            trailCurrent -> rLink = newNode;
        }
    }
    // cout << "Insert Testing: " << insertTree << endl;
}

// Recursive Insert (Lab 10 D and Lab 9 B BST)
/*
template <class elemType>
NodeType<elemType>* BST<elemType>::Insert(BSTNode* newNode, BSTNode* current)
{
    if(current == nullptr)
    {
        current = newNode;
    }
    else if(current->info > newNode->info)
    {
        current->lLink = Insert(newNode, current->lLink);
    }
    else
    {
        current->rLink = Insert(newNode, current->rLink);
    }
    return current;
}

template <class elemType>
void BST<elemType>::InsertItem(const elemType& insertItem)
{
    BSTNode *newNode = new BSTNode;
    newNode->info = insertItem;
    newNode->lLink = nullptr;
    newNode->rLink = nullptr;
    root = Insert(newNode, root);
}*/

template <class elemType>
void BST<elemType>::Delete(NodeType<elemType>* &p)
{
    if(p == nullptr)
    {
        return;
    }
    else
    {
        Delete(p->lLink);
        Delete(p->rLink);
        delete p;
        p = nullptr;
    }
}

template <class elemType>
BST<elemType>::~BST()
{
    if(root)
    {
        Delete(root);
    }
}

template <class elemType>
void BST<elemType>::InOrderTraversal(void (*visit) (elemType& item)) const
{
    InOrder(root, *visit);
}

template <class elemType>
void BST<elemType>::PreOrderTraversal(void (*visit) (elemType& item)) const
{
    PreOrder(root, *visit);
}

template <class elemType>
void BST<elemType>::PostOrderTraversal(void (*visit) (elemType& item)) const
{
    PostOrder(root, *visit);
}

template <class elemType>
void BST <elemType>::InOrder(NodeType<elemType>* p, void(*visit) (elemType&)) const
{
    if(p != NULL)
    {
        InOrder(p->lLink, *visit);
        (*visit)(p->info);
        InOrder(p->rLink, *visit);
    }
}

template <class elemType>
void BST<elemType>::PreOrder(NodeType<elemType>* p, void(*visit) (elemType&)) const
{
    if(p != NULL)
    {
        (*visit)(p->info);
        PreOrder(p->lLink, *visit);
        PreOrder(p->rLink, *visit);
    }
}

template <class elemType>
void BST<elemType>::PostOrder(NodeType<elemType>* p, void(*visit) (elemType&)) const
{
    if(p != NULL)
    {
        PostOrder(p->lLink, *visit);
        PostOrder(p->rLink, *visit);
        (*visit)(p->info);
    }
}

template <class elemType>
void BST<elemType>::CopyNodes(BSTNode* &current, BSTNode* otherItems)
{
    if (otherItems == nullptr)
    {
        current = nullptr;
    }
    else
    {
        current = new BSTNode;
        current->info = otherItems->info;
        CopyNodes(current->lLink, otherItems->lLink);
        CopyNodes(current->rLink, otherItems->rLink);
    }
}

template <class elemType>
const BST<elemType>& BST<elemType>::operator =(const BST<elemType>& otherItems)
{
    if (this != &otherItems)
    {
        if (root != nullptr)
        {
            Delete(root);
        }
        if (otherItems.root == nullptr)
        {
            root = nullptr;
        }
        else
        {
            CopyNodes(root, otherItems.root);
        }
    }
    return * this;
}

template <class elemType>
elemType BST<elemType>::MinValue()
{
    NodeType<elemType> *current = root;
    while( current->lLink != NULL )
    {
        current = current->lLink;
    }

    return ( current->info);
}

template <class elemType>
elemType BST<elemType>::MaxValue()
{
    NodeType<elemType> *current = root;
    while( current->rLink != NULL )
    {
        current = current->rLink;
    }

    return ( current->info);
}
#endif // BST_H
