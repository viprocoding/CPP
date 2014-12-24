#ifndef __NODE_H__
#define __NODE_H__

template<class T>
class Node {
public:
// Life cycle

	/** Default constructor
	 */
	Node(void);

	/** Constructor
	 *
	 * @param Data		Data to initialize the node with.
	 * @param Next		Pointer to next node, NULL if not specified.
	 */
	Node(const T& Data, Node<T>* Next = nullptr);

	/** Copy constructor
	 *
	 * @param from		Node to copy to this node with. Here, from.data is
	 *					written to this->data, and this->next is set to nullptr.
	 */
	Node(const Node<T>& from);

	/** Copy constructor (move version)
	 *
	 * There's no use for a move constructor here. Uncomment this if it's needed
	 * in the future.
	 */
	//Node(const Node<T>&& from);

	/** Destructor
	 * 
	 * A destructor is not necessary here.  Uncomment this if it's nedded in the
	 * future.
	 */
	//~Node(void);

// Operators
	
	/** Assignment operator
	 *
	 * @param from		Node to assign to this node. Here, from.data is written
	 *					to this->data, and next is left unchanged.
	 */
	const Node<T>& operator=(const Node<T>& from);

	/** Assignment operator (move version)
	 *
	 * A move version of the assignment operator is not necessary here.
	 * Uncomment this if it's needed in the future.
	 */
	//const Node<T>& operator=(const Node<T>&& from);

// Operations
	
	/** Set data
	 * 
	 * @param Data		Value to write to this->data.
	 * @return			Reference to this node.
	 */
	Node<T>& setData(const T& Data);

	/** Set next node
	 *
	 * @param Next		Pointer to a node that is to be assigned to this->next.
	 * @return			Reference to this node.
	 */
	Node<T>& setNext(const Node<T>& Next);

// Access

	/** Get data
	 *
	 * @return			The data stored in this->data.
	 */
	const T& getData(void) const;

	/** Get next node
	 * 
	 * @return			Pointer to the next node.	
	 */
	Node<T>* getNext(void) const;

	/** Get this node
	 *
	 * @return			Pointer to this node.
	 */
	Node<T>* getThis(void) const;


protected:
	T data;			// Node data
	Node<T>* next;	// Ptr to next node

};

template<class T>
Node<T>::Node(void)
	: next(nullptr)
{
}

template<class T>
Node<T>::Node(const T& Data, Node<T>* Next)
	: data(Data), next(Next)
{
}

template<class T>
Node<T>::Node(const Node<T>& from)
	: data(from.data), next(nullptr)
{
}

template<class T>
const Node<T>& Node<T>::operator=(const Node<T>& from)
{
	data = from.data;
	return *this;
}

template<class T>
Node<T>& Node<T>::setData(const T& Data)
{
	data = Data;
	return *this;
}

template<class T>
Node<T>& Node<T>::setNext(const Node<T>& Next)
{
	next = &Next;
}

template<class T>
const T& Node<T>::getData(void) const
{
	return data;
}

template<class T>
Node<T>* Node<T>::getNext(void) const
{
	return next;
}

template<class T>
Node<T>* Node<T>::getThis(void) const
{
	return this;
}

#endif // __NODE_H__
