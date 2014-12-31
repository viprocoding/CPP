#ifndef ARRAY_2_H
#define ARRAY_2_H

// Libraries
#include <new>      // bad alloc

/**
 * My notes:
 *  - This class doesn't support initializing or assigning arrays of diffrent
 *    sizes.
 */

template<class T, size_t N>
class array {
public:
// Life Cycle
    
    /** Constructor
     * 
     * @bad_alloc       Generated if new failed.
     */
    array(void);

    /** Copy constructor
     *
     * @param from      Constant reference to an object to copy.
     */
    array(const array<T, N>& from);

    /** Move constructor
     *
     * @param from      Rvalue reference to an object to steal.
     */
    array(array<T, N>&& from);

    /** Destructor
     */
    ~array(void);

// Operators

// Operations

// Access

// Iterators
private:
    /** Ptr to array start
     */
    T* ptr;
};

///////////////////////////// Life Cycle ///////////////////////////////////////

template<class T, size_t N>
array<T, N>::array(void)
    : ptr(new T[N])
{
}

template<class T, size_t N>
array<T, N>::array(const array<T, N>& from)
{
    // todo
}

template<class T, size_t N>
array<T, N>::array(array<T, N>&& from)
{
    // todo
}

template<class T, size_t N>
array<T, N>::~array(void)
{
    delete[] ptr;
}

#endif // ARRAY_2_H

