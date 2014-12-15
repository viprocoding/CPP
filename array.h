/******************************************************************************
 * array.h                                                                    *
 *                                                                            *
 * Purpose:                                                                   *
 *  Learn to use GitHub.                                                      *
 *                                                                            *
 * @author      Rasmus Östersjö                                               *
 ******************************************************************************/

#ifndef ARRAY_H
#define ARRAY_H

// Libraries
#include <new>          // bad_alloc
#include <stdexcept>    // invalid_argument
#include <utility>      // more comparison operators than ==, <=

using namespace std::rel_ops;

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
         * @param size      Size of array
         */
        array(const int& size);

        /** Copy constructor
         *
         * @param from      Value to copy to this object.
         */
        array(const array& from);

        /** Move constructor.
         *
         * @param from      Rvalue to write to this object.
         */
        array(array&& from);

        /** Destructor.
         */ 
        ~array(void);

    // OPERATORS
        
        /** Assignment operator.
         *
         * @param from      Value to assign to this object.
         * @return          Constant reference to this object
         */
        const array<T>& operator=(const array& from);

        /** Assignment operator (move version).
         *
         * @param from      Rvalue to assign to this object.
         * @return          Constant referense to this object.
         */
        const array<T>& operator=(array&& from);

        /** Index operator
         *
         * @param index     Index of the associated element in the array.
         * @return          Reference to the element indexed by index.
         */
        T& operator[](const int& index);

        /** Index operator
         *
         * @param index     Index of the associated element in the array.
         * @return          Copy of the element indexed by index.
         */
        T operator[](const int& index) const;

        /** Equal to operator
         *
         * @param obj       Object that is to be compared with this object.
         * @return          True if objects are equal.
         */
        bool operator==(const array<T>& obj) const;

        /** Less than or equal to operator
         *
         * @param obj       Object that is to be compared with this object.
         * @return          True if objects are equal.
         */
        bool operator<=(const array<T>& obj) const;
        
        /** Arithmetic operator
         * 
         * @param obj       Object that is to be added to this object.
         * @return          Constant reference to this object.
         *
         * @invalid_argument    Throws an exception if sizes doesn't match.
         */
        const array<T>& operator+=(const array<T>& obj);

        /** Arithmetic operator
         * 
         * @param data      Value to att do this object.
         * @return          Constant reference to this object.
         */
        const array<T>& operator+=(const T& data);

        /** Arithmetic operator
         * 
         * @param obj       Object that is to be added with this object
         * @return          A copy of the result.
         * 
         * @invalid_argument    Throws an exception if sixes doesn't match.
         */
        array<T> operator+(const array<T>& obj) const;

    // OPERATIONS
        
    // ACCESS

    // INQUIRY

    protected:

    private:

        T*       ptr;   // Pointer to dynamically allocated array
        unsigned n;     // Size of array
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
    array<T>::array(array<T>&& from)
        : n(from.n)
    {
        if (*this != from) {
            ptr = from.ptr;     // steal from's ptr
            from.ptr = nullptr;
        }
    }

    template<class T>
    array<T>::~array(void)
    {
        delete[] ptr;   
    }

//=============================  OPERATORS  ==================================

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
    const array<T>& array<T>::operator=(array<T>&& from)
    {
        if (*this != from) {
            delete[] ptr;   // clean up
            n = from.n;

            // steal from's ptr
            ptr = from.ptr;
            from.ptr = nullptr;
        }
        return *this;
    }

    template<class T>
    T& array<T>::operator[](const int& index)
    {
        return *(ptr + index);
    }

    template<class T>
    T array<T>::operator[](const int& index) const
    {
        return *(ptr + index);
    }

    template<class T>
    bool array<T>::operator==(const array<T>& obj) const
    {
        if (n != obj.n)
            return false;

        // *this and obj size matched, proceed to compare elements
        for (int i = 0, nMin = n < obj.n ? n : obj.n; i < nMin; i++)
            if (*(ptr + i) != *(obj.ptr + i))
                return false;
        return true;
    }

    template<class T>
    bool array<T>::operator<=(const array<T>& obj) const
    {
        for (int i = 0, nMin = n < obj.n ? n : obj.n; i < nMin; i++)
            if (*(ptr + i) > *(obj.ptr + i))
                return false;
        return n <= obj.n;
    }

    template<class T>
    const array<T>& array<T>::operator+=(const array<T>& obj)
    {
        if (n != obj.n) // operation is undefined
            throw std::invalid_argument("array<T>::operator+=");

        for (int i = 0; i < n; i++)
            *(ptr + i) += *(obj.ptr + i);

        return *this;
    }

    template<class T>
    const array<T>& array<T>::operator+=(const T& data)
    {
        for (int i = 0; i < n; i++)
            *(ptr + i) += data;

        return *this;
    }

    template<class T>
    array<T> array<T>::operator+(const array<T>& obj) const
    {
        array<T> tmp(*this);
        tmp += obj;
        
        return tmp;
    }

//=============================  OPERATIONS ===================================
    
//=============================  ACESS      ===================================
//=============================  INQUIRY    ===================================
}

#endif // ARRAY_H
