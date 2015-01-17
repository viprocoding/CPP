#ifndef ARRAY_2_H
#define ARRAY_2_H

// Libraries
#include <new>          // bad alloc
#include <stdexcept>    // out_of_range
//#include <iterator>
#include <cstddef>

/**
 * My notes:
 *  - This class doesn't support initializing or assigning arrays of diffrent
 *    sizes.
 */


template<class T>
class RandomAccessIterator
    : public std::iterator<std::random_access_iterator_tag, T*> {
public:
// Life Cycle

    /** Default constructor
     */
    RandomAccessIterator(void)
        : ptr(nullptr)
    {
    }

    /** Constructor
     *
     * @param ptr_      Pointer to a container elemenet.
     */
    RandomAccessIterator(T* ptr_)
        : ptr(ptr_)
    {
    }

    /** Copy constructor
     *
     * @param from      Iterator that is to be copied.
     */
    RandomAccessIterator(const RandomAccessIterator& from)
        : ptr(from.ptr)
    {
    }

// Operators
    
    /** Assignment operator
     *
     * @param from      Iterator that is to be assigned from.
     */
    const RandomAccessIterator& operator=(const RandomAccessIterator& from)
    {
        this->ptr = from.ptr;
    }

    /** Equal to operator
     *
     * @param that      Iterator to compare this object with.
     */
    bool operator==(const RandomAccessIterator& that)
    {
        return this->ptr == that.ptr;
    }

    /** Not equal to operator
     *
     * @param that      Iterator to compare this object with.
     */
    bool operator!=(const RandomAccessIterator& that)
    {
        return this->ptr != that.ptr;
    }

    /** Larger than operator
     *
     * @param that      Iterator to compare this object with.
     */
    bool operator>(const RandomAccessIterator& that)
    {
        return this->ptr > that.ptr;
    }

    /** Larger than or equal to operator
     *
     * @param that      Iterator to compare this object with.
     */
    bool operator>=(const RandomAccessIterator& that)
    {
        return this->ptr >= that.ptr;
    }

    /** Less than operator
     *
     * @param that      Iterator to compare this object with.
     */
    bool operator<(const RandomAccessIterator& that)
    {
        return this->ptr < that.ptr;
    }

    /** Less than or equal to operator
     *
     * @param that      Iterator to compare this object with.
     */
    bool operator <=(const RandomAccessIterator& that)
    {
        return this->ptr <= that.ptr;
    }

// Operations

    /** Prefix increment operator
     *
     * @return          Reference to this object.
     */
    RandomAccessIterator& operator++(void)
    {
        ++this->ptr;
        return *this;
    }

    /** Postfix increment operator
     *
     * @return          Rvalue object with post decrement data.
     */
    RandomAccessIterator operator++(int)
    {
        RandomAccessIterator<T> tmp(*this);
        ++this->ptr;
        return tmp;
    }

    /** Prefix decrement operator
     *
     * @return          Reference to this object.
     */
    RandomAccessIterator& operator--(void)
    {
        ++this->ptr;
        return *this;
    }

    /** Postfix decrement operator
     *
     * @return          Rvalue object with post decrement data.
     */
    RandomAccessIterator operator--(int)
    {
        RandomAccessIterator<T> tmp(*this);
        ++this->ptr;
        return tmp;
    }

    /** Addition operator (iterator version)
     *
     * @param that      Iterator to add with this object.
     * @return          Rvalue object with result.
     */
    RandomAccessIterator operator+(const RandomAccessIterator& that)
    {
        RandomAccessIterator<T> tmp(*this);
        tmp.ptr += tmp.ptr + that.ptr;
        return tmp;
    }

    /** Subtraction  operator (iterator version)
     *
     * @param that      Iterator to subtract with this object.
     * @return          Rvalue object with result.
     */
    RandomAccessIterator operator-(const RandomAccessIterator& that)
    {
        RandomAccessIterator<T> tmp(*this);
        tmp.ptr -= (tmp.ptr - that.ptr);
        return tmp;
    }

    /** Addition operator (integer version)
     *
     * @param i         Amount of incremenets from current iterator positition.
     * @return          Rvalue object with result.
     */
    RandomAccessIterator operator+(int i)
    {
        RandomAccessIterator<T> tmp(*this);
        tmp.ptr += i;
        return tmp;
    }

    /** Subtraction operator (integer versino)
     *
     * @param i         Amount of decrements from current iterator position.
     * @return          Rvalue object with result.
     */
    RandomAccessIterator operator-(int i)
    {
        RandomAccessIterator<T> tmp(*this);
        tmp.ptr -= i; 
        return tmp;
    }

    /** Addition assignment with integer
     *
     * @param i         Amount of incremenets from current iterator position.
     * @return          Reference to this object.
     */
    RandomAccessIterator& operator+=(int i)
    {
        this->ptr += i;
        return *this;
    }

    /** Subtraction assignment with integer
     *
     * @param i         Amount of decrements from current iterator position.
     * @return          Reference to this object.
     */
    RandomAccessIterator& operator-=(int i)
    {
        this->ptr -= i;
        return *this;
    }

    /** Swaps lvalues a and b
     *
     * @param a         Reference to an lvalue.
     * @param b         Reference to an lvalue.
     */
    void swap(T& a, T&b)
    {
        T tmp = a;
        a     = b;
        b     = tmp;
    }

// Access

    /** Dereference operator
     *
     * @return          Reference to the iterators current element.
     */
    T& operator*(void)
    {
        return *this->ptr;
    }

    /** Dereference operator (constant version)
     *
     * @return          Constant reference to the iterators current element.
     */
    const T& operator*(void) const
    {
        return *this->ptr;
    }

    // -> operator ?

    /** Offset dereference operator
     *
     * @return          Reference to the indexed elemenet.
     */
    T& operator[](int i)
    {
        return *(this->ptr + i);
    }

    /** Offset dereference operator (constant version)
     *
     * @return          Constant reference to the indexed element.
     */
    const T& operator[](int i) const
    {
        return *(this->ptr + i);
    }

private:
    
    /** Pointer to iterators current element.
     */
    T* ptr;

};


template<class T, std::size_t N>
class array {
public:
    typedef RandomAccessIterator<T> iterator;

    iterator begin(void) { return iterator(ptr); }
    iterator end(void) { return iterator(ptr + N); }

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

