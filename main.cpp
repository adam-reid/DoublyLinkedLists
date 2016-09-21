/** \mainpage Summary
\brief Doubly-linked list solution with options
* This is an implementation of a doubly-linked list that
* also allows for 3 different types of sorting algorithms.
*/

#include <iostream>
#include <random>
#include <ctime>
#include <memory>
#include <fstream>

/** \file main.cpp
\brief Only one file. main.
* Didn't see the need for more files. So, here's one.
*/

using namespace std;

/** \brief This is the node.
* This houses a doubly-linked list, previous and next nodes, and a value.
*/
struct Node{
    int val;
    shared_ptr<Node> prev; /**< This is a pointer to the previous node */
    shared_ptr<Node> next; /**< This is a pointer to the next node */

    /** \brief Constructor
    * Receives no arguments - initializes prev and next to nullptr.
    */
    Node():val(0),prev(nullptr),next(nullptr){};
};

typedef shared_ptr<Node> Smart_Ptr; /**< Allow for shared_ptr<Node> to be referenced easier */

/** \brief DoublyLinkedList class allows for .. a doubly linked list.
*/
class DoublyLinkedList
{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    //Inserters
    void Add(const int&, const int&);
    void Push(const int&);

    //Removers
    void Remove(const int&);
    void Pop();

    //Displayers
    void Display() const;
    void RDisplay() const;

    //Sorters
    void InsertionSort();
    void MergeSort();
    void BubbleSort();
private:
    Smart_Ptr m_head;
};

/** \brief Constructor for DoublyLinkedList
*/
DoublyLinkedList::DoublyLinkedList():m_head(nullptr){}
/** \brief Deconstructor for DoublyLinkedList
*/
DoublyLinkedList::~DoublyLinkedList(){}

/** \brief Adds the integer value to the node.
* \param val Integer value to be inserted into the list.
* \param loc Integer location in the list to be inserted.
* This function adds a value to a specific location. If the
* location exceeds the length of the list, the value is not
* added to the list and the user is notified.
*/
void DoublyLinkedList::Add(const int &val, const int &loc)
{
    Smart_Ptr node;

    node->val = val;

    if(m_head->next == nullptr && m_head->prev == nullptr)
    {
        m_head = node;

        /*m_head->val = val;
        m_head->next = this;
        m_head->prev = this;*/
    }

}

/** \brief Push a value onto the list
* \param val Integer to be 'pushed' onto the list
* This function behaves similarly to a stack,
* in which value is inserted prior to the head.
*/
void DoublyLinkedList::Push(const int &val)
{

}

/** \brief Remove a specific location from the list
* This function will locate a specific location in the list
* and remove it. If the location exceeds the length of the list,
* it will fail to remove anything and prompt the user.
*/
void DoublyLinkedList::Remove(const int &loc)
{

}

/** \brief Pop off the last element in the list
* This functions similar to a stack in which the last
* element can be popped off. This keys off of the last element.
*/
void DoublyLinkedList::Pop()
{

}

/** \brief Display list in forward order
*
*  This function will display the linked listed in forward order,
* keying off of the next pointer.
*/
void DoublyLinkedList::Display() const
{

}

/** \brief Display list in reverse order
*
*  This function will display the linked listed in reverse order,
* keying off of the previous pointer.
*/
void DoublyLinkedList::RDisplay() const
{

}

/** \brief Sorts via insertion sort (log n)
*/
void DoublyLinkedList::InsertionSort()
{

}

/** \brief Sorts via merge sort (some other notation)
*/
void DoublyLinkedList::MergeSort()
{

}

/** \brief Sorts via bubble sort (n^2)
*/
void DoublyLinkedList::BubbleSort()
{

}

/** \brief Main insertion point into the program
*
* Main creates a doubly-linked list and then allows
* values to be added in and displayed.
* \todo Test Add()
* \todo Test Push()
* \todo Test Remove()
* \todo Test Pop()
* \todo Test Display()
* \todo Test RDisplay()
* \todo Implement InsertionSort()
* \todo Confirm InsertionSort()
* \todo Implement BubbleSort()
* \todo Confirm BubbleSort()
* \todo Implement MergeSort()
* \todo Confirm MergeSort()
* \todo Implement Randomizer(int length)
* \todo Implement timer for sort functions.

*/
int main()
{
    DoublyLinkedList mylist; /**< This is the main object that does the heavy lifting. */

    mylist.Push(10);
    mylist.Display();

    return 0;
}
