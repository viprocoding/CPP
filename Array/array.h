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
#include <ostream>      // ostream
#include <iostream>     // cout

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
    // LIFECYCLE
        
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
        array(const array<T>& from);

        /** Move constructor.
         *
         * @param from      Rvalue to write to this object.
         */
        array(array<T>&& from);

        /** Destructor.
         */ 
        ~array(void);

    // OPERATORS
        
        /** Assignment operator.
         *
         * @param from      Value to assign to this object.
         * @return          Constant reference to this object
         */
        const array<T>& operator=(const array<T>& from);

        /** Assignment operator (move version).
         *
         * @param from      Rvalue to assign to this object.
         * @return          Constant referense to this object.
         */
        const array<T>& operator=(array<T>&& from);

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
        
        /** Addition assignment operator
         * 
         * @param obj       Object that is to be added to this object.
         * @return          Constant reference to this object.
         *
         * @invalid_argument    Throws an exception if sizes doesn't match.
         */
        const array<T>& operator+=(const array<T>& obj);

        /** Addition assignment operator
         * 
         * @param data      Value to att do this object.
         * @return          Constant reference to this object.
         */
        const array<T>& operator+=(const T& data);

        /** Addition operator
         * 
         * @param obj       Object that is to be added with this object
         * @return          A copy of the result.
         * 
         * @invalid_argument    Throws an exception if sizes doesn't match.
         */
        array<T> operator+(const array<T>& obj) const;

        /** Friend addition operator
         * 
         * @param data      Left operand.
         * @param obj       Right operand.
         * @return          A temporary object with the result of the addition.
         *
         * [Function defintion should be moved outside of the class, but havn't
         *  figured out how to make that compile yet]
         */
        friend array<T> operator+(const T& data, const array<T>& obj) {
            array<T> tmp(obj);
            tmp += obj;

            return tmp;
        }

        /** Subtraction assignment operator
         * 
         * @param obj       Object that is to be subctracted from this object.
         * @return          Constant reference to this object.
         *
         * @invalid_argument    Throws an exception if sizes donesn't match.
         */
        const array<T>& operator-=(const array<T>& obj);

        /** Subtraction assinment operator
         *
         * @param data      Data that is to be subtracted from this object
         * @return          Constant reference to this object.
         */
        const array<T>& operator-=(const T& obj);

        /** Subtraction operator
         * 
         * @param obj       Object that is to be subtracted with this object.
         * @return          A temporary object with the result.
         *
         * @invalid_argument    Throws an exception if sizes doesn't match.
         */
        array<T> operator-(const array<T>& obj) const;

        /** Friend subtraction operator
         * 
         * @param data      Left operand.
         * @param obj       Right operand.
         * @return          Temporary object with the result of the subtraction.
         *
         * [Function defintion should be moved outside of the class, but havn't
         *  figured out how to make that compile yet]
         */
        friend array<T> operator-(const T& data, const array<T>& obj) {
            array<T> tmp(obj);
            tmp -= obj;

            return tmp;
        }
        
        /** Multiplication assignment operator
         * 
         * @param obj       Object to multiply with this object.
         * @return          Constant reference to this object.
         *
         * @invalid_argument    Throws an exception if sizes donesn't match.
         */
        const array<T>& operator*=(const array<T>& obj);

        /** Multiplication assinment operator
         *
         * @param data      Data that is to be multiplied wit this object
         * @return          Constant reference to this object.
         */
        const array<T>& operator*=(const T& obj);

        /** Multiplication operator
         * 
         * @param obj       Object to multiply with this object.
         * @return          A temporary object with the result.
         *
         * @invalid_argument    Throws an exception if sizes doesn't match.
         */
        array<T> operator*(const array<T>& obj) const;

        /** Friend multiplication operator
         * 
         * @param data      Left operand.
         * @param obj       Right operand.
         * @return          Temporary object with the result of the multip.
         *
         * [Function defintion should be moved outside of the class, but havn't
         *  figured out how to make that compile yet]
         */
        friend array<T> operator*(const T& data, const array<T>& obj) {
            array<T> tmp(obj);
            tmp *= obj;

            return tmp;
        }

        /** Division assignment operator
         * 
         * @param obj       Object to divide with this object.
         * @return          Constant reference to this object.
         *
         * @invalid_argument    Throws an exception if sizes donesn't match.
         */
        const array<T>& operator/=(const array<T>& obj);

        /** Division assinment operator
         *
         * @param data      Data that is to be divided wit this object
         * @return          Constant reference to this object.
         */
        const array<T>& operator/=(const T& obj);

        /** Division operator
         * 
         * @param obj       Object to divide with this object.
         * @return          A temporary object with the result.
         *
         * @invalid_argument    Throws an exception if sizes doesn't match.
         */
        array<T> operator/(const array<T>& obj) const;

        /** Friend division operator
         * 
         * @param data      Left operand.
         * @param obj       Right operand.
         * @return          Temporary object with the result of the division.
         *
         * [Function defintion should be moved outside of the class, but havn't
         *  figured out how to make that compile yet]
         */
        friend array<T> operator/(const T& data, const array<T>& obj) {
            array<T> tmp(obj);
            tmp /= obj;

            return tmp;
        }

        /** Print operator
         * 
         * @param stream
         * @param obj
         * @return
         *
         * [Function defintion should be moved outside of the class, but havn't
         *  figured out how to make that compile yet]
         */
        friend std::ostream& operator<<(std::ostream& stream,
                                                  const array<T>& obj)
        {
            if (obj.n == 0)
                return stream;

            stream << "{";
            for (unsigned i = 0, n = obj.n - 1; i < n; i++)
                stream << obj[i] << ", ";
            stream << obj[obj.n - 1] << "}";

            return stream;

        }
    // OPERATIONS
        
        /** Reverse array
         *
         * @return      The entire array is reversed.
         */
        void reverse(void);

        /** Sort array (bubble sort)
         *
         * @param how       Flag, 'i' for increasing and 'd' for increasing.
         * @return          The entire array is sorted.
         */
        void sort(const bool& how = true);

    // ACCESS

        /** Size of array
         * 
         * @return      Constant reference to the arrays size.
         */
        const unsigned& size(void) const;

        /** Prints the array.
         *
         * @param start Index to start the pritning.
         * @param amt   Amount of elements to print.
         *
         * @invalid_argument    Throws exception if start + amt > n or amt < 1.
         */
        void print(const unsigned& start, const unsigned& amt) const;
        

    // INQUIRY

    protected:

    private:
        T*       ptr;   // Pointer to dynamically allocated array
        unsigned n;     // Size of array

    // HELPER FUNCTIONS
        
        /** Swaps the data pointed to by a, b.
         *
         * @param a     Reference to data.
         * @param b     Reference to data.
         * @return      true (a swap flag can be set when calling swap).
         */
        bool swap(T& a, T& b);

        /** Compares a and b.
         * 
         * @param a     Constant reference to data.
         * @param b     Constant reference to data.
         * @return      > 0 if a > b.
         */
        int cmpInc(const T& a, const T& b);

        /** Compares a and b.
         * 
         * @param a     Constant reference to data.
         * @param b     Constant reference to data.
         * @return      > 0 if b > a.
         */
        int cmpDec(const T& a, const T& b);
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

    template<class T>
    const array<T>& array<T>::operator-=(const array<T>& obj)
    {
        if (n != obj.n)
            throw std::invalid_argument("array::operator-=");

        for (int i = 0; i < n; i++)
            *(ptr + i) -= *(obj.ptr + i);

        return *this;
    }

    template<class T>
    const array<T>& array<T>::operator-=(const T& data)
    {
        for (int i = 0; i < n; i++)
            *(ptr + i) -= data; 

        return *this;
    }

    template<class T>
    array<T> array<T>::operator-(const array<T>& obj) const
    {
        array<T> tmp(*this);
        tmp -= obj;

        return tmp;
    }

    template<class T>
    const array<T>& array<T>::operator*=(const array<T>& obj)
    {
        if (n != obj.n)
            throw std::invalid_argument("array::operator-=");

        for (int i = 0; i < n; i++)
            *(ptr + i) *= *(obj.ptr + i);

        return *this;
    }

    template<class T>
    const array<T>& array<T>::operator*=(const T& data)
    {
        for (int i = 0; i < n; i++)
            *(ptr + i) *= data; 

        return *this;
    }

    template<class T>
    array<T> array<T>::operator*(const array<T>& obj) const
    {
        array<T> tmp(*this);
        tmp *= obj;

        return tmp;
    }

    template<class T>
    const array<T>& array<T>::operator/=(const array<T>& obj)
    {
        if (n != obj.n)
            throw std::invalid_argument("array::operator-=");

        for (int i = 0; i < n; i++)
            *(ptr + i) /= *(obj.ptr + i);

        return *this;
    }

    template<class T>
    const array<T>& array<T>::operator/=(const T& data)
    {
        for (int i = 0; i < n; i++)
            *(ptr + i) /= data; 

        return *this;
    }

    template<class T>
    array<T> array<T>::operator/(const array<T>& obj) const
    {
        array<T> tmp(*this);
        tmp /= obj;

        return tmp;
    }
//=============================  OPERATIONS ===================================
    
    template<class T>
    void array<T>::reverse(void)
    {
        for (T* head = ptr, *tail = ptr + n - 1; tail > head; head++, tail--)
            swap(*head, *tail);
    }

    template<class T>
    void array<T>::sort(const bool& how)
    {
        bool swapped = true;
        int (array::*cmp)(const T& a, const T& b);
        
        cmp = how == true ? &array::cmpInc : &array::cmpDec;    // decide how to sort
        for (int i = 1; i < n && swapped; i++)
            for (int j = 0; j < n - i; j++)
                if ((this->*cmp)(*(ptr + j), *(ptr + j + 1)) > 0)
                    swapped = swap(*(ptr + j), *(ptr + j + 1));
    }
    
//=============================  ACESS      ===================================

    template<class T>
    const unsigned& array<T>::size(void) const
    {
        return n;
    }

    template<class T>
    void array<T>::print(const unsigned& start, const unsigned& amt) const
    {
        if (start + amt > n || amt < 1)
            throw std::invalid_argument("array::print");

        for (unsigned i = start, n = start + amt; i < n; i++)
            std::cout << ptr[i] << " ";
        std::cout << std::endl;
    }

//=============================  INQUIRY    ===================================

//=============================  PRIVATE    ===================================
    
    template<class T>
    bool array<T>::swap(T& a, T& b)
    {
        T tmp = a;
        a     = b;
        b     = tmp;

        return true;
    }

    template<class T>
    int array<T>::cmpInc(const T& a, const T& b)
    {
        return a - b;
    }

    template<class T>
    int array<T>::cmpDec(const T& a, const T& b)
    {
        return b - a;
    }
}

#endif // ARRAY_H
