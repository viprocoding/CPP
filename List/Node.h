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
	Node(const T& Data, const Node<T>& Next = nullptr);

	/** Copy constructor
	 *
	 * @param from		Node to copy to this object (deep).
	 */
	Node(const Node<T>& from);

	/** Move constructor
	 *
	 * @param from		Node to initialize this node with (steal).
	 */
	Node(Node<T>&& from);

	/** Destructor
	 */
	~Node(void);

// Operators
	
	/** Assignment operator
	 *
	 * @param from		Node to assign to this node (deep).
	 */
	const Node<T>& operator==(const Node<T>& from);

	/** Assignment operator, move version
	 *
	 * @param from		Node to assign to this node (steal).
	 */
	const Node<T>& operator==(const Node<T>&& from);

// Operations
	
	/** Set data
	 * 
	 * @param Data		Value to write to this->data.
	 */
	void setData(const T& Data);

	/** Set next node
	 *
	 * @param Next		Pointer to a node that is to be assigned to this->next.
	 */
	void setNext(const Node<T>& Next);

// Access

	/** Get data
	 *
	 * @return			The data stored in this->data.
	 */
	const T& getData(void) const;

	/** Get next node
	 * 
	 * @return			A pointer to this->next.
	 */
	// const Node<T>* getNext(void) const;

protected:
	T data;			// Node data
	Node<T>* next;	// Ptr to next node

};

#endif // __NODE_H__
