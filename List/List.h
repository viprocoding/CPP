#ifndef __LIST_H__
#define __LIST_H__

// Libraries
#include <utility>				// get all comparision operators

// My headers
#include "Node.h"

// namespaces
using namespace std::rel_ops;	// get all comparison operators

template<class T>
class List {
private:
// Life cycle
	
	/** Default constructor
	 */
	List(void);

	/** Copy constructor
	 * 
	 * @param from			This object is copied to this list (deep).
	 */
	List(const List<T>& from);

	/** Move constructor
	 *
	 * @param from			This object is copied to this list (stolen).
	 */
	List(const List<T>&& from);

	/** Destructor
	 */
	~List(void);

// Operators

	/** Assignment operator
	 * 
	 * @param from			This object is assigned to this list (deep).
	 * @return				This object.
	 */
	const List<T>& operator=(const List<T>& from);

	/** Move assignment operator
	 *
	 * @param from			This object is assigned to this list (stolen).
	 * @return				This object.
	 */
	const List<T>& operator=(const List<T>&& from);

	/** Equal to operator
	 * 
	 * @param obj			List to compare with this object.
	 * @return				true / false.
	 */
	bool operator==(const List<T>& obj);

	/** Greater than operator
	 * 
	 * @param obj			List to compare with this object.
	 * @return				true / false.
	 */
	bool operator>(const List<T>& obj);

// Operations

	/** Add new node by position
	 * 
	 * @param data			Data to store in the new node.
	 * @param pos			List position to insert the new node.
	 * @return 				Reference to this object.
	 *
	 * @invalid_argument	An exception is generated if position is invalid.
	 */
	List<T>& add(const int& pos);

	/** Add new node in head or tail
	 * 
	 * @param data			Data to store in the new node.
	 * @param mode			Control character (valid: 'h' or 't')
	 * @return				Reference to this object.
	 *
	 * @invalid argument	An exception is generated if mode was invalid.
	 */
	List<T>& add(const char& mode);

	/** Remove node by position
	 * 
	 * @param pos			List position to insert the new node.
	 * @return 				Data stored in the removed node.
	 *
	 * @invalid_argument	An exception is generated if position is invalid.
	 */
	T& rm(const int& pos);

	/** Remove node in head or tail
	 * 
	 * @param mode			Control character (valid: 'h' or 't')
	 * @return 				Data stored in the removed node.
	 *
	 * @invalid_argument	An exception is generated if position is invalid.
	 */
	T& rm(const char& pos);

	/** Remove all nodes in the list
	 *
	 * @return				Reference to this object.
	 */
	List<T>& clear(void);

	/** Reverse the list
	 *
	 * @return				Reference to this object.
	 */
	List<T>& reverese(void);

// Access

	/** Get size
	 *
	 * @return				Current size of the list.
	 */
	const int& size(void) const;

	/** Is list empty?
	 *
	 * @return				true or false.
	 */
	bool isEmpty(void) const;

	/** Search node
	 * 
	 * @param key			Node to be searched for.
	 * @return				Position in the list, less than 0 if no match.
	 *
	 * -- Maybe generate exception such as no_match, and switch all int to
	 *    unsigned. --
	 */
	int search(const T& key) const;

	/** Peek at position
	 *
	 * @param pos			Possition to peek at.
	 * @return				Data stored in the specified position.
	 *
	 * @invalid_argument	An exception is generated.
	 */
	const T& peek(const int& pos) const;	
	
	/** Peek head or tail.
	 *
	 * @param mode			Control character (valid: 'h' or 't').
	 * @return				Data stored in the specified position.
	 *
	 * @invalid_argument	An exception is generated.
	 */
	const T& peek(const char& mode) const;	

	/** Prints the list
	 *
	 * @param start			Specifies position to start printing.
	 * @param end			Specifies position (inclusive) to stop printing.
	 * @return				Reference to this object.
	 *
	 * @invalid_argument	An exception is generated if start < end or if
	 *						start, end out of position.
	 */
	List<T>& print(void) const;

	/** Sort the list (merge sort)
	 *
	 * @return 				Reference to this object.
	 */
	List<T>& sort(void) const;

protected:
	Node<T>* head;		// List head
	int n;				// List size

};

#endif // __LIST_H__
