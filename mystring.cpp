/*******************************************************************************
 * AUTHOR        : Dillon Welsh
 * ASSIGNMENT2   : String Class
 * CLASS         : CS8
 * SECTION       : 33776
 * DUE DATE      : 03/18/2021
 ******************************************************************************/

#include "mystring.h"
/*******************************************************************************
 * MyString(const char str[] = "");
 * Constructor; Sets the MyString to the passed in char array.
 * Parameters: const char str[]
 * Return: none
 ******************************************************************************/
MyString::MyString(const char str[]) // IN - char array for string
{
    // PROCESSING - get length of passed in char array
    int i = 0;

    while(str[i] != '\0')
    {
        i++;
    }

    // PROECSSING - instantiate our dynamic char array to the len+1 for '\0'
    this->str = new char[i+1];
    this->allocated = i+1;

    // PROCESSING - copying passed in char array to instance variable
    int j = 0;

    for(j = 0; j < i; j++)
    {
        this->str[j] = str[j];
    }

    // PROCESSING - setting length of dynamic char
    this->current_length = j;
    // PROCESSING - addiing null char to end
    this->str[i] = '\0';
}

/*******************************************************************************
 * MyString(const char);
 * Constructor; Sets the MyString to the passed in char.
 * Parameters: const char
 * Return: none
 ******************************************************************************/
MyString::MyString(const char chr)  // IN - char for string
{
    // PROCESSING - initializing string to passed in char
    this->str = new char[2];
    this->str[0] = chr;
    this->str[1] = '\0';
    this->allocated = 2;
    this->current_length = 1;
}

/*******************************************************************************
 * MyString(MyString& source);
 * Copy Constructor; Sets the MyString to the passed in MyString.
 * Parameters: MyString& source
 * Return: none
 ******************************************************************************/
MyString::MyString(const MyString& source)  // IN - MyString for MyString
{
    // PROCESSING - set length and allocated from source
    this->allocated = source.allocated;
    this->current_length = source.current_length;
    this->str = new char[source.allocated];

    // PROCESSING - copy over from source
    for(int i = 0; i < int(this->current_length); i++)
    {
        this->str[i] = source.str[i];
    }
}

/*******************************************************************************
 * ~MyString();
 * Destructor; Deallocated memory.
 * Parameters: none
 * Return: none
 ******************************************************************************/
MyString::~MyString()
{
    delete[] this->str;
}

/*******************************************************************************
 * void reserve(size_t n);
 *
 * Mutator; Reserves more memory for the MyString
 * -----------------------------------------------------------------------------
 * Parameters: size_t n
 * -----------------------------------------------------------------------------
 * Return: none
 ******************************************************************************/
void MyString::reserve(size_t n)    // IN - size to allocate
{
    // PROCESSING - reallocate a larger array
    if(n > this->allocated)
    {
        char *temp = this->str;
        this->str = new char[n];
        this->allocated = n;
        for(int i = 0; i < int(this->length()); i++)
        {
            this->str[i] = temp[i];
        }
        delete [] temp;
    }
    // PROCESSING - if the length and allocated are different
    else if(n <= this->allocated && n > this->current_length)
    {
        char *temp = this->str;
        this->str = new char[n];
        this->allocated = n;
        for(int i = 0; i < int(this->length()); i++)
        {
            this->str[i] = temp[i];
        }
        delete [] temp;
    }
    else
        return;
}

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
MyString& MyString::erase (size_t pos,  // IN - position to start
                           size_t len)  // IN - length of deletion
{
    // PROCESSING - if out of range return the original string
    if(pos >= this->current_length || int(pos) < 0 || int(len) < 0) return *this;
    else if((pos + len) > this->current_length) return *this;
    else
    {
        // PROCESSING - reallocate the correct range
        char *temp = this->str;
        this->allocated -= len;
        this->str = new char[this->allocated];

        // PROCESSING - copy the first half

        int i = 0;
        for(i = 0; i < int(pos); i++)
        {
            this->str[i] = temp[i];
        }

        // PROCESSING - copy the second half
        int j = 0;
        int k = 0;
        for(j = int(pos + len), k = pos; j < int(this->current_length); j++, k++)
        {
            this->str[k] = temp[j];
        }

        // PROCESSING - clean up
        for(int l = k; l < j; l++)
        {
            this->str[l] = '\0';
        }


        this->current_length -= len;

        delete [] temp;
        return *this;
    }
}

/*******************************************************************************
 * MyString& insert (size_t pos, const MyString& str);
 *
 * Mutator; Inserts the given MyString into the MyString at the given position.
 * -----------------------------------------------------------------------------
 * Parameters: size_t pos, const MyString& str
 * -----------------------------------------------------------------------------
 * Return: MyString&
 ******************************************************************************/
MyString& MyString::insert (size_t pos,             // IN - position to insert
                            const MyString& str)    // IN - MyString to insert
{
    if(int(pos) < 0 || pos > this->current_length) return *this;
    else
    {
        char *temp = this->str;
        this->allocated += str.current_length;
        this->str = new char[this->allocated];

        // PROCESSING - copy original go up to insertion point
        int i = 0;
        int j = 0;
        int counter = 0;

        for(i = 0; i < int(pos); i++, counter++)
        {
            this->str[i] = temp[i];
        }

        // PROCESSING - copy in new str
        for(j = 0; j < int(str.current_length); j++, i++)
        {
            this->str[i] = str.str[j];
        }

        // PROCESSING - copy in end of original
        int k = counter;
        for(j = 0; j < int(this->current_length - counter + 1); j++, i++, k++)
        {
            this->str[i] = temp[k];
        }

        this->current_length = i-1;

        delete[] temp;
        return *this;
    }
}

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
MyString& MyString::replace (size_t pos,            // IN - position to replace
                             size_t len,            // IN - length of replace
                             const MyString& str)   // IN - String to replace
{
    // PROCESSING - make sure within bounds
    if(pos >= this->current_length || int(pos) < 0 || int(len) < 0) return *this;
    else if((pos + len) > this->current_length) return *this;
    else
    {
        // PROCESSING - replace given string within
        for(int i = int(pos), j = 0; i < int(pos+len); i++, j++)
        {
            this->str[i] = str[j];
        }
        return *this;
    }
}

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
MyString& MyString::replace (size_t pos,            // IN - position to replace
                             size_t len,            // IN - length of replace
                             const char* s)         // IN - char array to replce
{
    // PROCESSING - make sure within bounds
    if(pos >= this->current_length || int(pos) < 0 || int(len) < 0) return *this;
    else if((pos + len) > this->current_length) return *this;
    else
    {
        // PROCESSING - replace given string within
        for(int i = int(pos), j = 0; i < int(pos+len); i++, j++)
        {
            this->str[i] = s[j];
        }
        return *this;
    }
}

/*******************************************************************************
 * MyString& replace (size_t pos, const char s);
 *
 * Mutator; Replaces a char in the MyString with the given char.
 * -----------------------------------------------------------------------------
 * Parameters: size_t pos, const char s
 * -----------------------------------------------------------------------------
 * Return: MyString&
 ******************************************************************************/
MyString& MyString::replace (size_t pos,    // IN - position to replace
                             const char s)  // IN - char to replace
{
    // PROCESSING - make sure within bounds
    if(int(pos) < 0 || pos > this->current_length) return *this;
    else
    {
        // PROCESSING - replace char
        this->str[pos] = s;
        return *this;
    }
}

/*******************************************************************************
 * size_t find (const MyString& str, size_t pos) const;
 *
 * Accessor; finds the specified MyString withing the MyString.
 * -----------------------------------------------------------------------------
 * Parameters: const MyString& str, size_t pos
 * -----------------------------------------------------------------------------
 * Return: size_t
 ******************************************************************************/
size_t MyString::find (const MyString& str,      // IN - MyString to find
                       size_t pos) const         // IN - where to start looking
{
    // PROCESSING - make sure within bounds
    if(int(pos) < 0 || pos > this->current_length) return -1;
    else
    {
        // PROCESSING - set the length of passed in string
        int len = int(str.current_length);
        if(pos + len >= this->current_length) return -1;
        int count = 0;
        int location = -1;
        // PROCESSING - search for string
        for(int i = pos; i < int(this->current_length); i++)
        {
            if(this->str[i] == str.str[count])
            {
                count++;
            }
            else
            {
                count = 0;
            }
            // PROCESSING - return the location
            if(count == len)
            {
                location = i - len + 1;
                break;
            }
        }
        return location;
    }
}

/*******************************************************************************
 * size_t find (const char* s, size_t pos) const;
 *
 * Accessor; finds the specified char array withing the MyString.
 * -----------------------------------------------------------------------------
 * Parameters: const char* s, size_t pos
 * -----------------------------------------------------------------------------
 * Return: size_t
 ******************************************************************************/
size_t MyString::find (const char* s,       // IN - char array to find
                       size_t pos) const    // IN - where to start looking
{
    // PROCESSING - find length of char array
    int len = 0;
    while(s[len] != '\0')
    {
        len++;
    }

    // PROCESSING - make sure within bounds
    if(int(pos) < 0 || pos > this->current_length) return -1;
    else
    {

        if(pos + len >= this->current_length) return -1;
        int count = 0;
        int location = -1;
        // PROCESSING - start search
        for(int i = pos; i < int(this->current_length); i++)
        {
            if(this->str[i] == s[count])
            {
                count++;
            }
            else
            {
                count = 0;
            }
            // PROCESSING - return location
            if(count == len)
            {
                location = i - len + 1;
                break;
            }
        }
        return location;
    }
}

/*******************************************************************************
 * size_t find (const char s) const;
 *
 * Accessor; finds the specified char within the MyString.
 * -----------------------------------------------------------------------------
 * Parameters: const char s
 * -----------------------------------------------------------------------------
 * Return: size_t
 ******************************************************************************/
size_t MyString::find (const char s) const  // IN - char to find
{
    // PROCESSING - search for char
    int n = 0;
    while(this->str[n] != '\0')
    {
        if(this->str[n] == s) return n;
        n++;
    }
    return -1;
}

/*******************************************************************************
 * MyString& operator =(const MyString& source);
 *
 * Mutator; Overridden = operator for MyString = MyString
 * -----------------------------------------------------------------------------
 * Parameters: const MyString& source
 * -----------------------------------------------------------------------------
 * Return: MyString&
 ******************************************************************************/
MyString& MyString::operator=(const MyString &rhs) // IN - right hand side
{
    // PROCESSING - check for self assignment
    if(this == &rhs) return *this;

    // PROCESSING - copy over data
    this->allocated = rhs.allocated;
    this->current_length = rhs.current_length;

    // PROCESSING - copy over data
    for(int i = 0; i < int(this->current_length); i++)
    {
        this->str[i] = rhs.str[i];
    }

    return *this;
}

/*******************************************************************************
 * MyString operator +(const MyString& s);
 *
 * Mutator; Overridden + operator for MyString = MyString
 * -----------------------------------------------------------------------------
 * Parameters: const MyString& s
 * -----------------------------------------------------------------------------
 * Return: MyString
 ******************************************************************************/
MyString MyString::operator+(const MyString& source) // IN - right hand side
{
    // PROCESSING - add the right side with the left side
    *this += source;
    return *this;
}

/*******************************************************************************
 * void operator +=(const MyString& addend);
 *
 * Mutator; Overridden += operator for MyString += MyString
 * -----------------------------------------------------------------------------
 * Parameters: const MyString& addend
 * -----------------------------------------------------------------------------
 * Return: none
 ******************************************************************************/
void MyString::operator+=(const MyString& addend) // IN - right hand side
{
    // PROCESSING - find length of passed in
    int len = 0;
    while(addend[len] != '\0')
    {
        len++;
    }

    // PROCESSING - reallocate if necessary
    if(this->length() + len >= this->allocated)
    {
        char *temp = this->str;
        this->str = new char[this->allocated + len];
        this->allocated += len;
        // PROCESSING - add in original
        for(int i = 0; i < int(this->length()); i++)
        {
            this->str[i] = temp[i];
        }
        delete [] temp;
    }

    // PROCESSING - add in right hand side
    for(int i = this->length(), j=0; i <= int(this->allocated); i++, j++)
    {
        this->str[i] = addend[j];
    }

    this->current_length += len;
    this->str[this->current_length] = '\0';
}

/*******************************************************************************
 * void operator +=(const char* addend);
 *
 * Mutator; Overridden += operator for MyString += char*
 * -----------------------------------------------------------------------------
 * Parameters: const char* addend
 * -----------------------------------------------------------------------------
 * Return: none
 ******************************************************************************/
void MyString::operator+=(const char* addend) // IN - right hand side
{
    // PROCESSING - find length of passed in
    int len = 0;
    while(addend[len] != '\0')
    {
        len++;
    }
    // PROCESSING - reallocate if necessary
    if(this->length()+len >= this->allocated)
    {
        char *temp = this->str;
        this->str = new char[this->allocated + len];
        this->allocated += len;
        // PROCESSING - add in original
        for(int i = 0; i < int(this->length()); i++)
        {
            this->str[i] = temp[i];
        }
        delete [] temp;
    }

    // PROCESSING - add in right hand side
    for(int i = this->length(), j=0; i <= int(this->allocated); i++, j++)
    {
        this->str[i] = addend[j];
    }

    this->current_length += len;
}

/*******************************************************************************
 * void operator +=(const char addend);
 *
 * Mutator; Overridden += operator for MyString += char
 * -----------------------------------------------------------------------------
 * Parameters: const char addend
 * -----------------------------------------------------------------------------
 * Return: none
 ******************************************************************************/
void MyString::operator+=(const char addend)    // IN - right hand side
{

    // PROCESSING - reallocate if necessary
    if(this->length()+1 >= this->allocated)
    {
        char *temp = this->str;
        this->allocated++;
        this->str = new char[this->allocated];

        // PROCESSING - add in original
        for(int i = 0; i < int(this->length()); i++)
        {
            this->str[i] = temp[i];
        }
        // PROCESSING - add in right hand side
        this->str[this->length()] = addend;
        this->current_length++;
        this->str[this->length()] = '\0';
        delete [] temp;
    }
    else
    {
        // PROCESSING - add in right hand side
        this->str[this->length()] = addend;
        this->current_length++;
        this->str[this->length()] = '\0';
    }
}

/*******************************************************************************
 * bool operator==(const MyString& str2) const;
 *
 * Accessor; compares the MyString for is equals.
 * -----------------------------------------------------------------------------
 * Parameters: const MyString& str2
 * -----------------------------------------------------------------------------
 * Return: bool
 ******************************************************************************/
bool MyString::operator==(const MyString& str2) const // IN - right hand side
{
    // PROCESSING - chech if lengths are equal otherwise false
    if(this->current_length == str2.length())
    {
        // PROCESSING - if chars are equal incriment
        int count = 0;
        for(int i = 0; i < int(this->current_length); i++)
        {
            if(this->str[i] == str2.str[i]) count++;
        }

        // PROCESSING - the count is lenght if equal
        if(count == int(this->current_length)) return true;
        else return false;
    }
    else return false;
}

/*******************************************************************************
 * bool operator!=(const MyString& str2) const;
 *
 * Accessor; compares the MyString for not equals.
 * -----------------------------------------------------------------------------
 * Parameters: const MyString& str2
 * -----------------------------------------------------------------------------
 * Return: bool
 ******************************************************************************/
bool MyString::operator!=(const MyString& str2) const // IN - right hand side
{
    // PROCESSING - return the opposite of equal
    bool isEqual;
    isEqual = *this == str2;
    return !isEqual;
}

/*******************************************************************************
 * bool operator>=(const MyString& str2) const;
 *
 * Accessor; compares the MyString for greater than or equals.
 * -----------------------------------------------------------------------------
 * Parameters: const MyString& str2
 * -----------------------------------------------------------------------------
 * Return: bool
 ******************************************************************************/
bool MyString::operator>=(const MyString& str2) const // IN - right hand side
{
    // PROCESSING - comparing lengths
    if(this->current_length >= str2.current_length) return true;
    else return false;
}

/*******************************************************************************
 * bool operator<=(const MyString& str2) const;
 *
 * Accessor; compares the MyString for less than or equals.
 * -----------------------------------------------------------------------------
 * Parameters: const MyString& str2
 * -----------------------------------------------------------------------------
 * Return: bool
 ******************************************************************************/
bool MyString::operator<=(const MyString& str2) const // IN - right hand side
{
    // PROCESSING - comparing lengths
    if(this->current_length <= str2.current_length) return true;
    else return false;
}

/*******************************************************************************
 * bool operator<(const MyString& str2) const;
 *
 * Accessor; compares the MyString for less than.
 * -----------------------------------------------------------------------------
 * Parameters: const MyString& str2
 * -----------------------------------------------------------------------------
 * Return: bool
 ******************************************************************************/
bool MyString::operator<(const MyString& str2) const // IN - right hand side
{
    // PROCESSING - comparing lengths
    if(this->current_length < str2.current_length) return true;
    else return false;
}

/*******************************************************************************
 * bool operator>(const MyString& str2) const;
 *
 * Accessor; compares the MyString for greater than.
 * -----------------------------------------------------------------------------
 * Parameters: const MyString& str2
 * -----------------------------------------------------------------------------
 * Return: bool
 ******************************************************************************/
bool MyString::operator>(const MyString& str2) const // IN - right hand side
{
    // PROCESSING - comparing lengths
    if(this->current_length > str2.current_length) return true;
    else return false;
}

/*******************************************************************************
 * char operator [](size_t position) const;
 *
 * Accessor; Returns the char at the specified position.
 * -----------------------------------------------------------------------------
 * Parameters: size_t position
 * -----------------------------------------------------------------------------
 * Return: char
 ******************************************************************************/
char MyString::operator[](size_t position) const  // IN - position of char
{
    return this->str[position];
}

/*******************************************************************************
 * friend ostream& operator<<(ostream& outs, MyString& target);
 *
 * Friend; Overridden << operator for MyString
 * -----------------------------------------------------------------------------
 * Parameters: istream& ins, MyString& target
 * -----------------------------------------------------------------------------
 * Return: istream&
 ******************************************************************************/
ostream& operator<<(ostream& outs,      // IN - outstream
                    MyString& target)   // IN - MyString
{
    outs << target.str;
    return outs;
}

/*******************************************************************************
 * friend istream& operator>>(istream& ins, MyString& target);
 *
 * Friend; Overridden >> operator for MyString
 * -----------------------------------------------------------------------------
 * Parameters: istream& ins, MyString& target
 * -----------------------------------------------------------------------------
 * Return: istream&
 ******************************************************************************/
istream& operator>>(istream& ins,       // IN - instream
                    MyString& target)   // IN - MyString
{
    // PROCESSING - assignment
    ins >> target.str;

    // PROCESSING - keeping count of chars
    int i = 0;
    while(target.str[i] != '\0')
    {
        i++;
    }

    target.current_length = i;
    target.allocated = i+1;
    target.str[target.current_length] = '\0';

    return ins;
}

/*******************************************************************************
 * friend istream& getline(istream& ins, MyString& target, char delimiter);
 *
 * Friend; Overridden getline for MyString
 * -----------------------------------------------------------------------------
 * Parameters: istream& ins, MyString& target, char delimiter
 * -----------------------------------------------------------------------------
 * Return: istream&
 ******************************************************************************/
istream& getline(istream& ins,          // IN - instream
                 MyString& target,      // IN - MyString
                 char delimiter = '\n') // IN - delimiter
{
    // PROCESSING - assign one my one looking for the end line character
    MyString tempstring;
    int i = 0;
    char ch;
    ins.get(ch);
    // PROCESSING - stop at end line
    while (ch!=delimiter)
    {
        i++;
        tempstring+=ch;
        ins.get(ch);
    }
    target=tempstring;

    target.current_length = i;
    target.allocated = i+1;
    target.str[target.current_length] = '\0';

    return ins;
}


