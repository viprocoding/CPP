#ifndef __LIST_H__
#define __LIST_H__

// Libraries
#include <utility>              // get all comparision operators

// My headers
#include "Node.h"

// namespaces
using namespace std::rel_ops;   // get all comparison operators

template<class T>
class List {
private:
// Life cycle
    
    /** Default constructor
     */
    List(void);

    /** Copy constructor
     * 
     * @param from          This object is copied to this list (deep).
     */
    List(const List<T>& from);

    /** Move constructor
     *
     * @param from          This object is copied to this list (stolen).
     */
    List(const List<T>&& from);

    /** Destructor
     */
    ~List(void);

// Operators

    /** Assignment operator
     * 
     * @param from          This object is assigned to this list (deep).
     * @return              This object.
     */
    const List<T>& operator=(const List<T>& from);

    /** Move assignment operator
     *
     * @param from          This object is assigned to this list (stolen).
     * @return              This object.
     */
    const List<T>& operator=(const List<T>&& from);

    /** Equal to operator
     * 
     * @param obj           List to compare with this object.
     * @return              true / false.
     */
    bool operator==(const List<T>& obj);

    /** Greater than operator
     * 
     * @param obj           List to compare with this object.
     * @return              true / false.
     */
    bool operator>(const List<T>& obj);

// Operations

    /** Add new node by position
     * 
     * @param data          Data to store in the new node.
     * @param pos           List position to insert the new node.
     * @return              Reference to this object.
     *
     * @invalid_argument    An exception is generated if position is invalid.
     */
    List<T>& add(const int& pos);

    /** Add new node in head or tail
     * 
     * @param data          Data to store in the new node.
     * @param mode          Control character (valid: 'h' or 't')
     * @return              Reference to this object.
     *
     * @invalid argument    An exception is generated if mode was invalid.
     */
    List<T>& add(const char& mode);

    /** Remove node by position
     * 
     * @param pos           List position to insert the new node.
     * @return              Data stored in the removed node.
     *
     * @invalid_argument    An exception is generated if position is invalid.
     */
    T& rm(const int& pos);

    /** Remove node in head or tail
     * 
     * @param mode          Control character (valid: 'h' or 't')
     * @return              Data stored in the removed node.
     *
     * @invalid_argument    An exception is generated if position is invalid.
     */
    T& rm(const char& pos);

    /** Remove all nodes in the list
     *
     * @return              Reference to this object.
     */
    List<T>& clear(void);

    /** Reverse the list
     *
     * @return              Reference to this object.
     */
    List<T>& reverese(void);

    /** Merge lists
     *
     * @param with          List to merge to this object (steal).
     * @param pos           List position to do the merge.
     * @return              Reference to this object.
     *
     * @invalid_argument    An exception is generated if position is invalid.
     */
    List<T>& merge(const int& pos, List<T>& with);

    /** Merge lists in head or tail
     *
     * @param with          List to merge to this object (steal).
     * @param mode          Mode how to merge (valid: 'h' or 't').
     * @return              Reference to this object.
     *
     * @invalid_argument    An exception is generated if position is invalid.
     */
    List<T>& merge(const char &mode, List<T>& with);


// Access

    /** Get size
     *
     * @return              Current size of the list.
     */
    const int& size(void) const;

    /** Is list empty?
     *
     * @return              true or false.
     */
    bool isEmpty(void) const;

    /** Search node
     * 
     * @param key           Node to be searched for.
     * @return              Position in the list, less than 0 if no match.
     *
     * -- Maybe generate exception such as no_match, and switch all int to
     *    unsigned. --
     */
    int search(const T& key) const;

    /** Peek at position
     *
     * @param pos           Possition to peek at.
     * @return              Data stored in the specified position.
     *
     * @invalid_argument    An exception is generated.
     */
    const T& peek(const int& pos) const;    
    
    /** Peek head or tail.
     *
     * @param mode          Control character (valid: 'h' or 't').
     * @return              Data stored in the specified position.
     *
     * @invalid_argument    An exception is generated.
     */
    const T& peek(const char& mode) const;  

    /** Prints the list
     *
     * @param start         Specifies position to start printing.
     * @param end           Specifies position (inclusive) to stop printing.
     * @return              Reference to this object.
     *
     * @invalid_argument    An exception is generated if start < end or if
     *                      start, end out of position.
     */
    List<T>& print(void) const;

    /** Sort the list (merge sort)
     *
     * @return              Reference to this object.
     */
    List<T>& sort(void) const;

protected:
    Node<T>* head;      // List head
    int n;              // List size

};

// ****************************** Life cycle ***********************************

template<class T>
List<T>::List(void)
    : head(nullptr), n(0)
{
}

template<class T>
List<T>::List(const List<T>& from)
    : n(from.n)
{
    head->setData(from->getData());
    for (Node<T>* to = head, fr = from.head; fr->getNext() != nullptr;
         to = to->getNext(), fr = fr->getNext())
        to->setNext(new Node<T>(fr->getNext()->getData()));
}

template<class T>
List<T>::List(const List<T>&& from)
    : head(from.head), n(from.n)
{
    from.head = nullptr;
    from.n    = 0;
}

template<class T>
List<T>::~List(void)
{
    for (Node<T>* curr = head, nextNode; curr != nullptr; curr = nextNode) {
        nextNode = curr->getNext();
        delete curr;
    }
}

// ****************************** Operators  ***********************************

template<class T>
const List<T>& List<T>::operator=(const List<T>& from)
{
    List::List(from); // call copy constructor
    return *this;
}

template<class T>
const List<T>& List<T>::operator=(const List<T>&& from)
{
    List::List(from); // call move constructor
    return *this;
}

// ****************************** Operations ***********************************

template<class T>
bool List<T>::operator==(const List<T>& obj)
{
    if (this->n != obj.n)
        return false;

    // sizes match, compare element by element
    for (Node<T>* curr_this = head, curr_obj = obj.head; curr_this != nullptr;
         curr_this = curr_this->getNext(), curr_obj = curr_obj->getNext())
        if (curr_this->getData != curr_obj->getData())
            return false;
    return true;
}

template<class T>
bool List<T>::operator>(const List<T>& obj)
{
    Node<T>* curr_this = head;
    Node<T>* curr_obj  = obj.head;

    // compare element by element
    for (int n = this->n > obj.n ? this->n : obj.n, i = 0; i < n; i++,
         curr_this = curr_this->getNext(), curr_obj = curr_obj->getNext())
        if (curr_this->getData() <= curr_obj->getData())
            return false;
    return this->n > obj.n;
}

// ****************************** Access ***************************************

#endif // __LIST_H__
