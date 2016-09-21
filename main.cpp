/** \mainpage Summary
\brief Doubly-linked list solution with sorting options.
*
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
    int val;                /**< This is the value that the node holds. */
    shared_ptr<Node> prev; /**< This is a pointer to the previous node. */
    shared_ptr<Node> next; /**< This is a pointer to the next node. */

    /** \brief Constructor
    * Receives no arguments - initializes prev and next to nullptr.
    */
    Node():val(0),prev(nullptr),next(nullptr){};

    /** \brief Constructor w/ args
    * Receives value as an argument - initializes prev and next to nullptr.
    * \param value Value to be assigned.
    */
    Node(const int &value):val(value),prev(this),next(this){};
};

typedef shared_ptr<Node> Smart_Ptr; /**< Allow for shared_ptr<Node> to be referenced easier */

/** \brief DoublyLinkedList class allows for a uh.. a doubly linked list.
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
    Smart_Ptr m_head; /**< This is the head of the linked list. */
    int m_size;     /**< This is the size of the linked list. */
};

/** \brief Constructor for DoublyLinkedList
** Initializes the class members.
*/
DoublyLinkedList::DoublyLinkedList():m_head(nullptr),m_size(0){}
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
    Smart_Ptr node = make_shared<Node>(Node(val));
    Smart_Ptr it;

    if(m_size == 0)
    {
        m_head = node;
        m_head->next = m_head;
        m_head->prev = m_head;
    }

    else if (loc > m_size)
    {
        cerr<<"Location " << loc << " received, max size = " << m_size <<". No action taken.\n";
    }
    else
    {
        it = m_head;

        for(int i = 0; i < loc-1; i++)
            it = it->next;

        node->next = it->next;
        node->prev = it;
        it->next = node;
        m_head->prev = node;
    }

    cout<<node->val<<"\t"<<node->next<<'\t'<<node<<"\t"<<node->prev<<"\n";
    m_size++;
}

/** \brief Push a value onto the list
* \param val Integer to be 'pushed' onto the list
* This function behaves similarly to a stack,
* in which value is inserted prior to the head.
*/
void DoublyLinkedList::Push(const int &val)
{
    Add(val,m_size);
}

/** \brief Remove a specific location from the list
* This function will locate a specific location in the list
* and remove it. If the location exceeds the length of the list,
* it will fail to remove anything and prompt the user.
*/
void DoublyLinkedList::Remove(const int &loc)
{
    Smart_Ptr it = m_head;

    if(m_size == 0 || loc >= m_size)
    {
        cerr<<"Location requested: " << loc << ", max size: " << m_size << "\n";
        cerr<<"No action performed.\n";
    }

    //If in the first half...
    if(loc < m_size/2)
    {
        for(int i = 0; i < loc; i++)
            it = it->next;
    }
    //Else, the second half..
    else
    {
        for(int i = m_size; i > loc; i--)
            it = it->prev;
    }

    (it->prev)->next = it->next;
    (it->next)->prev = it->prev;

    m_size--;
}

/** \brief Pop off the last element in the list
* This functions similar to a stack in which the last
* element can be popped off. This keys off of the last element.
*/
void DoublyLinkedList::Pop()
{
    Remove(m_size-1);
}

/** \brief Display list in forward order
*
*  This function will display the linked listed in forward order,
* keying off of the next pointer.
*/
void DoublyLinkedList::Display() const
{
    Smart_Ptr node = m_head;

    for(int pos = 0; pos < m_size; pos++, node = node->next)
    {
        cout<<"Index: "<<pos<<", Value: "<<node->val<<"\t\t"<<node->next<<"\t"<<node<<'\t'<<node->prev<<"\n";
    }
}

/** \brief Display list in reverse order
*
*  This function will display the linked listed in reverse order,
* keying off of the previous pointer.
*/
void DoublyLinkedList::RDisplay() const
{
    Smart_Ptr node = m_head;

    for(int pos = m_size-1; pos >= 0; pos--, node = node->prev)
    {
        cout<<"Index: "<<pos<<", Value: "<<node->val<<"\t\t"<<node->next<<"\t"<<node<<'\t'<<node->prev<<"\n";
    }
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

    try{
        for(int i = 0; i < 12; i++)
            mylist.Push(i);

        mylist.Display();
        mylist.RDisplay();

        mylist.Pop();
        mylist.Pop();

        mylist.Display();
    }
    catch(...)
    {
        cerr<<"An unhandled exception occurred.\n";
    }

    return 0;
}
