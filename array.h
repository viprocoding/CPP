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
	// LIFE STYLE
		
		/** Default constructor.
		 */
		array(void);

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
		 */
		array& operator=(const array& from);

	// OPERATIONS
		
	// ACCESS

	// INQUIRY

	protected:

	private:

		T*       ptr;	// Pointer to dynamically allocated array
		unsigned n;		// Size of array
	};
}


#endif // ARRAY_H
