/******************************************************************************
 * array.h                                                                    *
 *                                                                            *
 * Purpose:                                                                   *
 *	Learn to use GitHub.											          *
 *                                                                            *
 * @author		Rasmus Östersjö												  *
 ******************************************************************************/

#ifndef ARRAY_H
#define ARRAY_H

// Libraries
#include <new>			// bad_alloc
#include <stdexcept>	// invalid_argument

/** Part of the Rasmus Ostersjo namespace.
 */
namespace raos {

	/**
	 * Implements a template array class.
	 *
	 * #include "array.h"
	 *
	 * [Longer description]
	 */
	template <class T>
	class array
	{
	public:
	// LIFESTYLE
		
		/** Default constructor.
		 */
		array(void);

		/** Constructor
		 *
		 * @param size		Size of array
		 */
		array(const int& size);

		/** Copy constructor
		 *
		 * @param from		Value to copy to this object.
		 */
		array(const array& from);

		/** Move constructor.
		 *
		 * @param from		Rvalue to write to this object.
		 */
		array(const array&& from);

		/** Destructor.
		 */ 
		~array(void);

	// OPERATORS
		
		/** Assignment operator.
		 *
		 * @param from		Value to assign to this object.
		 * @return			Constant reference to this object
		 */
		const array<T>& operator=(const array& from);

		/** Assignment operator (move version).
		 *
		 * @param from		Rvalue to assign to this object.
		 * @return			Constant referense to this object.
		 */
		const array<T>& operator=(const array&& from);

	// OPERATIONS
		
	// ACCESS

	// INQUIRY

	protected:

	private:

		T*       ptr;	// Pointer to dynamically allocated array
		unsigned n;		// Size of array
	};

////////////////////////////////  PUBLIC  /////////////////////////////////////

//=============================  LIFECYCLE  ===================================

	template<class T>
	array<T>::array(void)
		: ptr(nullptr), n(0)
	{
	}

	template<class T>
	array<T>::array(const int& size)
		: n(size)
	{
		if (size < 0)
			throw std::invalid_argument("array::array");

		ptr = new T[n];
	}

	template<class T>
	array<T>::array(const array<T>& from)
		: n(from.n)
	{
		ptr = new T[n];

		// Make deep copy
		for (int i = 0; i < n; i++)
			*(ptr + i) = *(from.ptr + i);
	}

	template<class T>
	array<T>::array(const array<T>&& from)
		: n(from.n)
	{
		if (*this != from) {
			ptr = new T[n];

			// Make a deep copy
			for (int i = 0; i < n; i++)
				*(ptr + i) = *(from.ptr + i);
		}
	}

	template<class T>
	array<T>::~array(void)
	{
		delete[] ptr;	
	}

//=============================  OPERTORS   ===================================

	template<class T>
	const array<T>& array<T>::operator=(const array<T>& from)
	{
		if (*this != from) {
			~array();
			n = from.n;
			ptr = new T[n];

			// Make a deep copy
			for (int i = 0; i < n; i++)
				*(ptr + i) = *(from.ptr + i);
		}
		return *this;
	}

	template<class T>
	const array<T>& array<T>::operator=(const array<T>&& from)
	{
		if (*this != from) {
			~array();
			n = from.n;

			// steal from's ptr
			ptr = from.ptr;
			from.ptr = nullptr;
		}
		return *this;
	}


//=============================  OPERATIONS ===================================
//=============================  ACESS      ===================================
//=============================  INQUIRY    ===================================
}

#endif // ARRAY_H
