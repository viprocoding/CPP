#ifndef ARRAY_2_H
#define ARRAY_2_H

// Libraries
#include <new>          // bad alloc
#include <stdexcept>    // out_of_range
#include <iterator>
#include <cstddef>

/**
 * My notes:
 *  - This class doesn't support initializing or assigning arrays of diffrent
 *    sizes.
 */

template<class T, std::size_t N>
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

    /** Fills the entire array with a value.
     *
     * @param val       Value to fill the array with.
     */
    void fill(const T& val);

// Access
    
    /** Access element by index
     *
     * @param i         Index of an element in the array.
     * @return          Reference to the specified element.
     *
     * @out_of_range    Genererade if invalid index.
     */
    T& at(std::size_t i);

    /** Constant version of 'at'
     */
    const T& at(std::size_t i) const;

// Iterators
    
private:
    /** Ptr to array start
     */
    T* ptr;
};

///////////////////////////// Life Cycle ///////////////////////////////////////

template<class T, std::size_t N>
array<T, N>::array(void)
    : ptr(new T[N])
{
}

template<class T, std::size_t N>
array<T, N>::array(const array<T, N>& from)
{
    // todo
}

template<class T, std::size_t N>
array<T, N>::array(array<T, N>&& from)
{
    // todo
}

template<class T, std::size_t N>
array<T, N>::~array(void)
{
    delete[] ptr;
}

///////////////////////////// Operations ///////////////////////////////////////

template<class T, std::size_t N>
void array<T, N>::fill(const T& val)
{
    // todo
}


///////////////////////////// Access ///////////////////////////////////////////

template<class T, std::size_t N>
T& array<T, N>::at(std::size_t i)
{
    if (i >= N)
        throw std::out_of_range("array::at");

    return *(ptr + i);
}

template<class T, std::size_t N>
const T& array<T, N>::at(std::size_t i) const
{
    if (i >= N)
        throw std::out_of_range("array::at");

    return *(ptr + i);
}


#endif // ARRAY_2_H

