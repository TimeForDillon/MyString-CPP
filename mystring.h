#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <cstring>

using namespace std;

class MyString
{ 
private:
    char *str;                  // IN - dynamic char array
    size_t allocated;           // IN - allocated space for array
    size_t current_length;      // IN - current length of array

public:
    /********************************
     ** CONSTRUCTORS & DESTRUCTORS **
     ********************************/
    MyString(const char str[] = "");    // Constructor
    MyString(const char);               // Constructor
    MyString(const MyString& source);   // Constructor
    ~MyString();                        // Destructor

    /***************
     ** ACCESSORS **
     ***************/
    size_t length() const { return this->current_length; };
    size_t allocatedSize() const {return this->allocated; };
    char operator [](size_t position) const;
    bool operator==(const MyString& str2) const;
    bool operator!=(const MyString& str2) const;
    bool operator>=(const MyString& str2) const;
    bool operator<=(const MyString& str2) const;
    bool operator<(const MyString& str2) const;
    bool operator>(const MyString& str2) const;
    size_t find (const MyString& str, size_t pos) const;
    size_t find (const char* s, size_t pos) const;
    size_t find (const char s) const;

    /**************
     ** MUTATORS **
     **************/
    MyString& insert (size_t pos, const MyString& str);
    MyString& erase (size_t pos, size_t len);
    MyString& replace (size_t pos, size_t len, const MyString& str);
    MyString& replace (size_t pos, size_t len, const char* s);
    MyString& replace (size_t pos, const char s);
    void operator +=(const MyString& addend);
    void operator +=(const char* addend);
    void operator +=(const char addend);
    void reserve(size_t n);
    MyString& operator =(const MyString& source);
    MyString operator +(const MyString& s);
    friend istream& operator>>(istream& ins, MyString& target);
    friend ostream& operator<<(ostream& outs, MyString& target);
    friend istream& getline(istream& ins, MyString& target, char delimiter);
};

#endif

/*******************************************************************************
 * MyString Class
 *  This class represents a string. This class is responsible for constructing
 *  a MyString with lenght and allocated size.
 ******************************************************************************/

/********************************
 ** CONSTRUCTORS & DESTRUCTORS **
 ********************************/

/*******************************************************************************
 * MyString(const char str[] = "");
 * Constructor; Sets the MyString to the passed in char array.
 * Parameters: const char str[]
 * Return: none
 ******************************************************************************/

/*******************************************************************************
 * MyString(const char);
 * Constructor; Sets the MyString to the passed in char.
 * Parameters: const char
 * Return: none
 ******************************************************************************/

/*******************************************************************************
 * MyString(MyString& source);
 * Copy Constructor; Sets the MyString to the passed in MyString.
 * Parameters: MyString& source
 * Return: none
 ******************************************************************************/

/*******************************************************************************
 * ~MyString();
 * Destructor; Deallocated memory.
 * Parameters: none
 * Return: none
 ******************************************************************************/

/***************
 ** ACCESSORS **
 ***************/

/*******************************************************************************
 * size_t length() const
 *
 * Accessor; Returns the current length.
 * -----------------------------------------------------------------------------
 * Parameters: none
 * -----------------------------------------------------------------------------
 * Return: size_t current_length
 ******************************************************************************/

/*******************************************************************************
 * size_t allocatedSize() const
 *
 * Accessor; Returns the allocated size.
 * -----------------------------------------------------------------------------
 * Parameters: none
 * -----------------------------------------------------------------------------
 * Return: size_t allocated
 ******************************************************************************/

/*******************************************************************************
 * char operator [](size_t position) const;
 *
 * Accessor; Returns the char at the specified position.
 * -----------------------------------------------------------------------------
 * Parameters: size_t position
 * -----------------------------------------------------------------------------
 * Return: char
 ******************************************************************************/

/*******************************************************************************
 * bool operator==(const MyString& str2) const;
 *
 * Accessor; compares the MyString for is equals.
 * -----------------------------------------------------------------------------
 * Parameters: const MyString& str2
 * -----------------------------------------------------------------------------
 * Return: bool
 ******************************************************************************/

/*******************************************************************************
 * bool operator!=(const MyString& str2) const;
 *
 * Accessor; compares the MyString for not equals.
 * -----------------------------------------------------------------------------
 * Parameters: const MyString& str2
 * -----------------------------------------------------------------------------
 * Return: bool
 ******************************************************************************/

/*******************************************************************************
 * bool operator>=(const MyString& str2) const;
 *
 * Accessor; compares the MyString for greater than or equals.
 * -----------------------------------------------------------------------------
 * Parameters: const MyString& str2
 * -----------------------------------------------------------------------------
 * Return: bool
 ******************************************************************************/

/*******************************************************************************
 * bool operator<=(const MyString& str2) const;
 *
 * Accessor; compares the MyString for less than or equals.
 * -----------------------------------------------------------------------------
 * Parameters: const MyString& str2
 * -----------------------------------------------------------------------------
 * Return: bool
 ******************************************************************************/

/*******************************************************************************
 * bool operator<(const MyString& str2) const;
 *
 * Accessor; compares the MyString for less than.
 * -----------------------------------------------------------------------------
 * Parameters: const MyString& str2
 * -----------------------------------------------------------------------------
 * Return: bool
 ******************************************************************************/

/*******************************************************************************
 * bool operator>(const MyString& str2) const;
 *
 * Accessor; compares the MyString for greater than.
 * -----------------------------------------------------------------------------
 * Parameters: const MyString& str2
 * -----------------------------------------------------------------------------
 * Return: bool
 ******************************************************************************/

/*******************************************************************************
 * size_t find (const MyString& str, size_t pos) const;
 *
 * Accessor; finds the specified MyString withing the MyString.
 * -----------------------------------------------------------------------------
 * Parameters: const MyString& str, size_t pos
 * -----------------------------------------------------------------------------
 * Return: size_t
 ******************************************************************************/

/*******************************************************************************
 * size_t find (const char* s, size_t pos) const;
 *
 * Accessor; finds the specified char array withing the MyString.
 * -----------------------------------------------------------------------------
 * Parameters: const char* s, size_t pos
 * -----------------------------------------------------------------------------
 * Return: size_t
 ******************************************************************************/

/*******************************************************************************
 * size_t find (const char s) const;
 *
 * Accessor; finds the specified char within the MyString.
 * -----------------------------------------------------------------------------
 * Parameters: const char s
 * -----------------------------------------------------------------------------
 * Return: size_t
 ******************************************************************************/

/**************
 ** MUTATORS **
 **************/

/*******************************************************************************
 * MyString& insert (size_t pos, const MyString& str);
 *
 * Mutator; Inserts the given MyString into the MyString at the given position.
 * -----------------------------------------------------------------------------
 * Parameters: size_t pos, const MyString& str
 * -----------------------------------------------------------------------------
 * Return: MyString&
 ******************************************************************************/

/*******************************************************************************
 * MyString& erase (size_t pos, size_t len);
 *
 * Mutator; Erases a portion of the string starting at the given position for
 * the given length.
 * -----------------------------------------------------------------------------
 * Parameters: size_t pos, size_t len
 * -----------------------------------------------------------------------------
 * Return: MyString&
 ******************************************************************************/

/*******************************************************************************
 * MyString& replace (size_t pos, size_t len, const MyString& str);
 *
 * Mutator; Replaces a portion of the string starting at the given position for
 * the given length with the given MyString.
 * -----------------------------------------------------------------------------
 * Parameters: size_t pos, size_t len, const MyString& str
 * -----------------------------------------------------------------------------
 * Return: MyString&
 ******************************************************************************/

/*******************************************************************************
 * MyString& replace (size_t pos, size_t len, const char* s);
 *
 * Mutator; Replaces a portion of the string starting at the given position for
 * the given length with the given char array.
 * -----------------------------------------------------------------------------
 * Parameters: size_t pos, size_t len, const char* s
 * -----------------------------------------------------------------------------
 * Return: MyString&
 ******************************************************************************/

/*******************************************************************************
 * MyString& replace (size_t pos, const char s);
 *
 * Mutator; Replaces a char in the MyString with the given char.
 * -----------------------------------------------------------------------------
 * Parameters: size_t pos, const char s
 * -----------------------------------------------------------------------------
 * Return: MyString&
 ******************************************************************************/

/*******************************************************************************
 * void operator +=(const MyString& addend);
 *
 * Mutator; Overridden += operator for MyString += MyString
 * -----------------------------------------------------------------------------
 * Parameters: const MyString& addend
 * -----------------------------------------------------------------------------
 * Return: none
 ******************************************************************************/

/*******************************************************************************
 * void operator +=(const char* addend);
 *
 * Mutator; Overridden += operator for MyString += char*
 * -----------------------------------------------------------------------------
 * Parameters: const char* addend
 * -----------------------------------------------------------------------------
 * Return: none
 ******************************************************************************/

/*******************************************************************************
 * void operator +=(const char addend);
 *
 * Mutator; Overridden += operator for MyString += char
 * -----------------------------------------------------------------------------
 * Parameters: const char addend
 * -----------------------------------------------------------------------------
 * Return: none
 ******************************************************************************/

/*******************************************************************************
 * void reserve(size_t n);
 *
 * Mutator; Reserves more memory for the MyString
 * -----------------------------------------------------------------------------
 * Parameters: size_t n
 * -----------------------------------------------------------------------------
 * Return: none
 ******************************************************************************/

/*******************************************************************************
 * MyString& operator =(const MyString& source);
 *
 * Mutator; Overridden = operator for MyString = MyString
 * -----------------------------------------------------------------------------
 * Parameters: const MyString& source
 * -----------------------------------------------------------------------------
 * Return: MyString&
 ******************************************************************************/

/*******************************************************************************
 * MyString operator +(const MyString& s);
 *
 * Mutator; Overridden + operator for MyString = MyString
 * -----------------------------------------------------------------------------
 * Parameters: const MyString& s
 * -----------------------------------------------------------------------------
 * Return: MyString
 ******************************************************************************/

/*******************************************************************************
 * friend istream& operator>>(istream& ins, MyString& target);
 *
 * Friend; Overridden >> operator for MyString
 * -----------------------------------------------------------------------------
 * Parameters: istream& ins, MyString& target
 * -----------------------------------------------------------------------------
 * Return: istream&
 ******************************************************************************/

/*******************************************************************************
 * friend ostream& operator<<(ostream& outs, MyString& target);
 *
 * Friend; Overridden << operator for MyString
 * -----------------------------------------------------------------------------
 * Parameters: istream& ins, MyString& target
 * -----------------------------------------------------------------------------
 * Return: istream&
 ******************************************************************************/

/*******************************************************************************
 * friend istream& getline(istream& ins, MyString& target, char delimiter);
 *
 * Friend; Overridden getline for MyString
 * -----------------------------------------------------------------------------
 * Parameters: istream& ins, MyString& target, char delimiter
 * -----------------------------------------------------------------------------
 * Return: istream&
 ******************************************************************************/
