#ifndef __LIST_H__
#define __LIST_H__

// Libraries
#include <stdexcept>    // invalid_argument
#include <iostream>

// My headers
#include "Node.h"

template<class T>
class List {
public:
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
    List(List<T>&& from);

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

    /** Not equal to operator
     * 
     * @param obj           List to compare with this object.
     * @return              true / false.
     */
    bool operator!=(const List<T>& obj);

    /** Greater than operator
     * 
     * @param obj           List to compare with this object.
     * @return              true / false.
     */
    bool operator>(const List<T>& obj);

    /** Greater than or equal operator
     * 
     * @param obj           List to compare with this object.
     * @return              true / false.
     */
    bool operator>=(const List<T>& obj);

    /** Less than operator
     * 
     * @param obj           List to compare with this object.
     * @return              true / false.
     */
    bool operator<(const List<T>& obj);

    /** Less than or equal operator
     * 
     * @param obj           List to compare with this object.
     * @return              true / false.
     */
    bool operator<=(const List<T>& obj);

// Operations

    /** Add new node by position
     * 
     * @param data          Data to store in the new node.
     * @param pos           List position to insert the new node.
     * @return              Reference to this object.
     *
     * @invalid_argument    An exception is generated if position is invalid.
     */
    List<T>& add(const int& pos, const T& data);

    /** Remove node by position
     * 
     * @param pos           List position to insert the new node.
     * @return              Data stored in the removed node.
     *
     * @invalid_argument    An exception is generated if invalid position.
     */
    T rm(const int& pos);

    /** Remove all nodes in the list
     *
     * @return              Reference to this object.
     */
    List<T>& clear(void);

    /** Reverse the list
     *
     * @return              Reference to this object.
     */
    List<T>& reverse(void);

    /** Merge lists
     *
     * @param with          List to merge to this object (steal).
     * @param pos           List position to do the merge.
     * @return              Reference to this object.
     *
     * @invalid_argument    An exception is generated if position is invalid or
     *                      if with is a reference to this object.
     */
    List<T>& merge(const int& pos, List<T>& with);

    /** Sort the list (merge sort)
     *
     * @return              Reference to this object.
     */
    List<T>& sort(void);

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

    /** Search node (traverses the list for matches)
     * 
     * @param key           Node to be searched for.
     * @return              List with all positions containing a match.
     */
    List<int> search(const T& key) const;

    /** Peek at position
     *
     * @param pos           Possition to peek at.
     * @return              Data stored in the specified position.
     *
     * @invalid_argument    An exception is generated.
     */
    const T& peek(const int& pos) const;    

    /** Prints the list
     *
     * @param start         Specifies position to start printing.
     * @param end           Specifies position (inclusive) to stop printing.
     * @return              Reference to this object.
     *
     * @invalid_argument    An exception is generated if start < end or if
     *                      start, end out of position.
     */
    const List<T>& print(void) const;

protected:

    Node<T>* head;      // List head
    int n;              // List size

private:
    // Helper functions
    void sort_r(Node<T>** head);
    void split(Node<T>* head, Node<T>** left, Node<T>** right);
    Node<T>* merge(Node<T>* left, Node<T>* right);

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
List<T>::List( List<T>&& from)
    : head(from.head), n(from.n)
{
    from.head = nullptr;
    from.n    = 0;
}

template<class T>
List<T>::~List(void)
{
    for (Node<T>* curr = head, *nextNode; curr != nullptr; curr = nextNode) {
        nextNode = curr->getNext();
        delete curr;
    }
    this->head = nullptr;
    this->n    = 0;
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

template<class T>
bool List<T>::operator==(const List<T>& obj)
{
    if (this->n != obj.n)
        return false;

    // sizes match, compare element by element
    for (Node<T>* curr_this = head, *curr_obj = obj.head; curr_this != nullptr;
         curr_this = curr_this->getNext(), curr_obj = curr_obj->getNext())
        if (curr_this->getData() != curr_obj->getData())
            return false;
    return true;
}

template<class T>
bool List<T>::operator!=(const List<T>& obj)
{
    return !(*this == obj);
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

template<class T>
bool List<T>::operator>=(const List<T>& obj)
{
    return *this == obj || *this > obj;
}

template<class T>
bool List<T>::operator<(const List<T>& obj)
{
    return !(*this >= obj); 
}

template<class T>
bool List<T>::operator<=(const List<T>& obj)
{
    return *this == obj || *this < obj;
}

// ****************************** Operations ***********************************

template<class T>
List<T>& List<T>::add(const int& pos, const T& data)
{
    if (pos < 0 || pos > n)
        throw std::invalid_argument("List<T>::add");

    // Get in position to insert node
    Node<T>** curr = &head;
    for (int i = 0; i < pos; i++)
        curr = (*curr)->nextAdr();

    // Insert node
    *curr = new Node<T>(data, *curr); this->n++;

    return *this;
}

template<class T>
T List<T>::rm(const int& pos)
{
    if (pos < 0 || pos >= this->n)
        throw std::invalid_argument("List<T>::rm"); 

    // Get in position to remove node
    Node<T>** curr = &this->head;
    for (int i = 0; i < pos; i++)
        curr = (*curr)->nextAdr();

    // Remove node
    Node<T>* tmp    = *curr;                // don't lose node, need clean
    T        rmData = tmp->getData();       // don't lose data, need return
    *curr           = (*curr)->getNext();
    delete tmp;

    return rmData;
}

template<class T>
List<T>& List<T>::clear(void)
{
    List::~List();
    return *this;
}

template<class T>
List<T>& List<T>::reverse(void)
{
    // reverse list
    Node<T>* newHead = nullptr;
    for (Node<T>* curr = this->head, *next; curr != nullptr; curr = next) {
        next = curr->getNext();             // dont lose next node
        newHead = &curr->setNext(newHead);  // place latest node in the front
    }
    this->head = newHead;   // complete the switch

    return *this;
}

template<class T>
List<T>& List<T>::merge(const int& pos, List<T>& with)
{
    if (pos < 0 || pos > n || *this == with)
        throw std::invalid_argument("List<T>::merge");

    // Get in position to do the merge
    Node<T>** curr = &this->head;
    for (int i = 0; i < pos; i++)
        curr = (*curr)->nextAdr();

    // Merge lists
    Node<T>* tmp = *curr;   // this node has to be appened to end of 'with'
    *curr = with.head;      // append 'with' to current position in *this
    while (*curr != nullptr)
        curr = (*curr)->nextAdr();
    (*curr) = tmp;          // complete the merge
    this->n += with.n;      // uppdate size

    // Clean up 'with'
    with.head = nullptr;
    with.n    = 0;

    return *this;
}

template<class T>
List<T>& List<T>::sort(void)
{
    sort_r(&this->head);
    return *this;
}

// ****************************** Access ***************************************

template<class T>
const int& List<T>::size(void) const
{
    return this->n;
}

template<class T>
bool List<T>::isEmpty(void) const
{
    return this->n <= 0;
}

template<class T>
List<int> List<T>::search(const T& data) const
{
    List<int> matches;
    Node<T>* curr = this->head;

    // Find all matches
    for (int i = 0; i < this->n; i++) {
        if (curr->getData() == data)
            matches.add(0, i);
        curr = curr->getNext();
    }

    return matches;
}

template<class T>
const T& List<T>::peek(const int& pos) const
{
    if (pos < 0 || pos >= this->n)
        throw std::invalid_argument("List<T>::peek");

    Node<T>* curr = this->head;
    for (int i = 0; i < pos; i++)
        curr = curr->getNext();

    return curr->getData();
}

template<class T>
const List<T>& List<T>::print(void) const
{
    for (Node<T>* curr = this->head; curr != nullptr; curr = curr->getNext())
        std::cout << curr->getData() << " ";
    std::cout << std::endl;

    return *this;
}

// ****************************** Private **************************************

template<class T>
void List<T>::sort_r(Node<T>** head)
{
    // base case
    if (*head == nullptr || (*head)->getNext() == nullptr)
        return;

    // Divide list into two halves
    Node<T>* leftSide;
    Node<T>* rightSide;
    split(*head, &leftSide, &rightSide);

    sort_r(&leftSide);
    sort_r(&rightSide);
    *head = merge(leftSide, rightSide);
}

template<class T>
void List<T>::split(Node<T>* head, Node<T>** l, Node<T>** r)
{
    Node<T>* fast;
    Node<T>* slow;

    slow = head;
    fast = head->getNext();
    while (fast != nullptr) {
        fast = fast->getNext();
        if (fast != nullptr) {
            slow = slow->getNext();
            fast = fast->getNext();
        }
    }

    *l = head;
    *r = slow->getNext();
    slow->setNext(nullptr);
}

template<class T>
Node<T>* List<T>::merge(Node<T>* l, Node<T>* r)
{
    // Base cases
    if (l == nullptr)
        return r;
    if (r == nullptr)
        return l;

    Node<T>* subHead;
    if (l->getData() > r->getData()) {
        subHead = r;
        r->setNext(merge(l, r->getNext()));
    }
    else {
        subHead = l;
        l->setNext(merge(l->getNext(), r));
    }

    return subHead;
}

#endif // __LIST_H__
