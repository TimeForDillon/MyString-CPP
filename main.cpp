/*******************************************************************************
 * AUTHOR        : Dillon Welsh
 * ASSIGNMENT2   : String Class
 * CLASS         : CS8
 * SECTION       : 33776
 * DUE DATE      : 03/18/2021
 ******************************************************************************/

#include "mystring.h"
#include <iostream>

using namespace std;

/*******************************************************************************
 * This test tests the char array constructor, the lenght function, the
 * allocatedSize function, and the [] operator.
 ******************************************************************************/
void test1()
{
    cout << "***************************************************************\n";
    cout << "TEST1" << endl;
    cout << "***************************************************************\n";
    cout << "Starting..." << endl;
    cout << "Filling String1 with the word: \"Hello\"" << endl;
    char myWord[] = "Hello";
    MyString str = MyString(myWord);
    cout << "Done..." << endl << endl;

    cout << "Testing the << operator to output String1..." << endl;
    cout << "Output: " << str << endl << endl;

    cout << "Testing the length() member function..." << endl;
    cout << "Length: " << str.length() << endl << endl;

    cout << "Testing the allocatedLength() member function..." << endl;
    cout << "Allocated: " << str.allocatedSize() << endl << endl;

    cout << "Testing the [] operator to output the 3rd character..." << endl;
    cout << "Char: " << str[2] << endl << endl;
}

/*******************************************************************************
 * This test tests the char constructor, the char* constructor, the += operator,
 * the = operator, and the + operator.
 ******************************************************************************/
void test2()
{
    char myWord[] = "Hello";
    MyString str = MyString(myWord);

    cout << "***************************************************************\n";
    cout << "TEST2" << endl;
    cout << "***************************************************************\n";

    cout << "Filling String2 with the word: \" World\"" << endl;
    char myWordTwo[] = " World";
    MyString strTwo = MyString(myWordTwo);
    cout << "Done..." << endl << endl;

    cout << "Testing the += (MyString) operator with String1 and String2..." << endl;
    str += strTwo;
    cout << "String1 += String2: " << str << endl;
    cout << "New Length: " << str.length() << endl;
    cout << "Allocated Size: " << str.allocatedSize() << endl << endl;

    cout << "Testing the += (char) operator with String1 and a char..." << endl;
    MyString strChar = MyString('!');
    str += strChar;
    cout << "String1 += char: " << str << endl;
    cout << "New Length: " << str.length() << endl;
    cout << "Allocated Size: " << str.allocatedSize() << endl << endl;

    cout << "Filling String3 with the word: \" Goodbye!\"" << endl;
    char myWordThree[] = " Goodbye!";
    char * ptr;
    ptr = myWordThree;
    cout << "Testing the += (char *) operator with String1 and String3..." << endl;
    str = str + ptr;

    cout << "String1 += String3: " << str << endl;
    cout << "New Length: " << str.length() << endl;
    cout << "Allocated Size: " << str.allocatedSize() << endl << endl;
}

/*******************************************************************************
 * This test tests the copy constructor, the assignment operator, and the
 * comparison operators.
 ******************************************************************************/
void test3()
{
    char myWord[] = "Hello";
    MyString str = MyString(myWord);
    char myWordTwo[] = " World";
    MyString strTwo = MyString(myWordTwo);
    str += strTwo;
    MyString strChar = MyString('!');
    str += strChar;
    char myWordThree[] = " Goodbye!";
    char * ptr;
    ptr = myWordThree;
    str = str + ptr;

    cout << "***************************************************************\n";
    cout << "TEST3" << endl;
    cout << "***************************************************************\n";

    cout << "Testing the copy constructor with String1..." << endl;
    MyString copyCon = MyString(str);
    cout << "Copied String: " << copyCon << endl << endl;

    cout << "Testing the assignment operator (=)..." << endl;
    cout << "Setting String2 as String1..." << endl;
    strTwo = copyCon;
    cout << "String2 = String1: " << strTwo << endl;
    cout << "New Length: " << strTwo.length() << endl;
    cout << "Allocated Size: " << strTwo.allocatedSize() << endl << endl;

    cout << "Testing the == operator between String2 and String3..." << endl;
    cout << "String2 == String3: ";
    if(strTwo == ptr) cout << "TRUE" << endl << endl;
    else cout << "FALSE" << endl << endl;

    cout << "Testing the != operator between String2 and String3..." << endl;
    cout << "String2 != String3: ";
    if(strTwo != ptr) cout << "TRUE" << endl << endl;
    else cout << "FALSE" << endl << endl;

    cout << "Testing the >= operator between String2 and String3..." << endl;
    cout << "String2 >= String3: ";
    if(strTwo >= ptr) cout << "TRUE" << endl << endl;
    else cout << "FALSE" << endl << endl;

    cout << "Testing the > operator between String2 and String3..." << endl;
    cout << "String2 > String3: ";
    if(strTwo > ptr) cout << "TRUE" << endl << endl;
    else cout << "FALSE" << endl << endl;

    cout << "Testing the <= operator between String2 and String3..." << endl;
    cout << "String2 <= String3: ";
    if(strTwo <= ptr) cout << "TRUE" << endl << endl;
    else cout << "FALSE" << endl << endl;

    cout << "Testing the < operator between String2 and String3..." << endl;
    cout << "String2 < String3: ";
    if(strTwo < ptr) cout << "TRUE" << endl << endl;
    else cout << "FALSE" << endl << endl;
}

/*******************************************************************************
 * This test tests the erase function, the insert functions, replace functions,
 * find functions, >> and getline
 ******************************************************************************/
void test4()
{
    char myWord[] = "Hello";
    MyString str = MyString(myWord);
    char myWordTwo[] = " World";
    MyString strTwo = MyString(myWordTwo);
    str += strTwo;
    MyString strChar = MyString('!');
    str += strChar;
    char myWordThree[] = " Goodbye!";
    char * ptr;
    ptr = myWordThree;
    str = str + ptr;

    cout << "***************************************************************\n";
    cout << "TEST4" << endl;
    cout << "***************************************************************\n";

    cout << "Testing the erase member function on String1..." << endl;
    cout << "String1: " << str << endl;
    cout << "Erasing 6 characters starting at position 5..." << endl;
    str = str.erase(5,6);
    cout << "String1: " << str << endl;
    cout << "New Length: " << str.length() << endl;
    cout << "Allocated Size: " << str.allocatedSize() << endl << endl;

    cout << "Testing the insert member function on String1..." << endl;
    cout << "String1: " << str << endl;
    cout << "Inserting \" World\" after \"Hello\" and before \"!\"..." << endl;
    MyString insStr = MyString(myWordTwo);
    str.insert(5, insStr);
    cout << "String1: " << str << endl;
    cout << "New Length: " << str.length() << endl;
    cout << "Allocated Size: " << str.allocatedSize() << endl << endl;

    cout << "Testing the == operator between String1 and String2..." << endl;
    cout << "String2 == String3: ";
    if(strTwo == str) cout << "TRUE" << endl << endl;
    else cout << "FALSE" << endl << endl;

    cout << "Testing the replace (MyString) method with String1..." << endl;
    cout << "String1: " << str << endl;
    cout << "Replacing \"Hello\" with \"Howdy\"..." << endl;
    MyString myStr = MyString("Howdy");
    str.replace(0, 5, myStr);
    cout << "String1: " << str << endl << endl;

    cout << "Testing the replace (c-str) method with String1..." << endl;
    cout << "String1: " << str << endl;
    cout << "Replacing \"Howdy\" with \"Hello\"..." << endl;
    str.replace(0, 5, myWord);
    cout << "String1: " << str << endl << endl;

    cout << "Testing the replace (char) method with String1..." << endl;
    cout << "String1: " << str << endl;
    cout << "Replacing \"!\" with \"?\"..." << endl;
    str.replace(11,'?');
    str.replace(20,'?');
    cout << "String1: " << str << endl << endl;

    cout << "Testing the find function (char) with String1..." << endl;
    cout << "String1: " << str << endl;
    cout << "Finding the first \"?\"..." << endl;
    cout << "Position: " << str.find('?') << endl << endl;

    cout << "Testing the find function (MyString) with String1..." << endl;
    cout << "String1: " << str << endl;
    cout << "Finding the first instance of \"bye\"..." << endl;
    MyString myStrTwo = MyString("bye");
    cout << "Position: " << str.find(myStrTwo, 0) << endl << endl;

    cout << "Testing the find function (char) with String1..." << endl;
    cout << "String1: " << str << endl;
    cout << "Finding the first instance of \"bye\"..." << endl;
    char myWordFour[] = "bye";
    cout << "Position: " << str.find(myWordFour, 0) << endl << endl;

    cout << "Testing the getline operator with String2..." << endl;
    cout << "String2: " << strTwo << endl;
    cout << "Length: " << strTwo.length() << endl;
    cout << "Allocated Size: " << strTwo.allocatedSize() << endl;
    cout << "Enter a string: ";
    getline(cin, strTwo, '\n');
    cout << "String2: " << strTwo << endl;
    cout << "New Length: " << strTwo.length() << endl;
    cout << "Allocated Size: " << strTwo.allocatedSize() << endl << endl;

    cout << "Testing the << operator with String2..." << endl;
    cout << "String2: " << strTwo << endl;
    cout << "Length: " << strTwo.length() << endl;
    cout << "Allocated Size: " << strTwo.allocatedSize() << endl;
    cout << "Enter a string: ";
    cin >> strTwo;
    cout << "String2: " << strTwo << endl;
    cout << "New Length: " << strTwo.length() << endl;
    cout << "Allocated Size: " << strTwo.allocatedSize() << endl << endl;
}

int main()
{
    test1();
    test2();
    test3();
    test4();

    return 0;
}
