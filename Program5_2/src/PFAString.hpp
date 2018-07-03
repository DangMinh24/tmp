#ifndef PFASTRING_HPP
#define PFASTRING_HPP

#include <string>
#include <iomanip>
/*
 * NOTES:
 * - Copy constructor shall construct a new object with capacity equal to the size of the object being copied
 * - Copy assignment shall have the same behavior
 * - Resize must behave similarly to that found on cplusplus.com for the vector class. HOWEVER, we will do it with a 
 * single function (Using an overload as they have, requires knowledge of templates). This means that we will use the
 * C++98 version of this function as our basis
 * - For the comparison operators, you are comparing entire arrays, which requires comparing individual elements. We are
 * trusting the results of element to element comparisons, and writing code that will lexicographically compare entire 
 * arrays
 * - You may NOT use the lexicographical_compare() algorithm
 * - When overloading [ ], use pointer arithmetic to emulate the expected behavior
 * 	- Meaning, [ ] will allow you to go out of bounds and into memory that is not part of the array
 */

class PFAString {
public:
    typedef std::string::size_type size_type;
    PFAString();    //Default constructor 
    PFAString(unsigned int icapacity, std::string istring = std::string());   //Constructor that sets capacity and initializes all elements to a specific string    // If no string is provided, then a null string will be used. This is a single constructor (no overloads for this case)
    PFAString(const PFAString &rhs);// Copy Constructor            // 1st type only under C++11 (This refers to list of vector constructors on cplusplus.com)
    PFAString(PFAString &&rhs);// Move Constructor            // 1st type only under C++11 (This refers to list of vector constructors on cplusplus.com
    ~PFAString();// Destructor
    unsigned int capacity() const;//function capacity
    unsigned int size() const;//function size
    void push_back(const std::string& strVal);// function push_back          // Places a string at the back of the array, l-value reference version only
    void pop_back();    // function pop_back           // Sets final active element to null string, behaves as if destroyed
    void resize(size_type n,const std::string& value= std::string());//function resize             // Grows or shrinks array accordingly, must behave like vector resize() function (C++98 version)
    void empty_array();// function empty_array        // Sets the size to zero (That's it)
    std::string& operator[](unsigned int iter);// overload operator []        // Needs to work as l-value
    const std::string& operator[](unsigned int iter) const;// overload operator []        // const overload (Refer to vector overload on cplusplus.com for both of these)
    
    PFAString& operator=(const PFAString& rhs);// overload copy operator =
    PFAString& operator=(PFAString&& rhs);// overload move operator =
    
    bool operator<(const PFAString& rhs) const;// overload operator <
    bool operator<=(const PFAString& rhs) const;// overload operator <=
    bool operator>(const PFAString& rhs) const;// overload operator >
    bool operator>=(const PFAString& rhs) const;// overload operator >=
    
    bool operator==(const PFAString& rhs) const;// overload operator ==
    bool operator!=(const PFAString& rhs) const;// overload operator !=


    void reallocate();  //Additional function
private:
    std::string *arr;
    unsigned int _capacity;               // Capacity and size are two different things
    unsigned int _size;
};

void printVector(const PFAString& lhs);
#endif
