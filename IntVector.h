#ifndef _INTVECTOR_H_
#define _INTVECTOR_H_

#include <iostream>

using namespace std;

class IntVector {
    public:
    //set both size and capacity of IntVector to 0 and won't allocate any memory to store integers.
    IntVector();
    //Sets both the size and capacity of the IntVector to the value of the parameter passed in and 
    //dynamically allocates an array of that size as well. This function should initialize all elements of the array to the value of the 2nd parameter.
    IntVector(unsigned size, int value = 0);
    //The destructor is used to clean up (delete) any remaining dynamically-allocated memory. For this class, that will be the array pointed to by the int pointer called data
    ~IntVector();
    //This function returns the current size (not the capacity) of the IntVector object, which is the values stored in the sz data field.
    unsigned size() const;
    //This function returns the current capacity (not the size) of the IntVector object, which is the value stored in the cap data field.
    unsigned capacity() const;
    //Returns whether the IntVector is empty (the sz field is 0).
    bool empty() const;
    //This function will return the value stored in the element at the passed in index position. Your function should throw an outofrange exception if an invalid index is passed in. An invalid index is an index greater than or equal to the size.
    const int &at(unsigned index) const;
    //does exactly the same thing the accessor (const) version of at does
    int & at(unsigned index);
    //inserts data at position index. To do this, all values currently at position index and greater are shifted to the right by 1 (to the element right after its current position)
    //Size will be increased by 1. However, If size will become larger than capacity, this function needs to first double the capacity. In other words, if capacity and size are both 20 when this function is called, this function must first increase the capacity to 40 and then it will be able to increase the size to 21
    //Since other functions will also potentially need to expand (double) the capacity, call the private helper function named expand (see above) to do this for you
    void insert(unsigned index, int value);
    //removes the value at position index and shifts all of the values at positions greater than index to the left by one (to the element right before its current position)
    //Size is decreased by 1
    void erase(unsigned index);
    //This function will return the value stored in the first element.
    const int &front() const;
    // does exactly the same thing the accessor (const) version of front does
    int & front();
    //This function will return the value stored in the last element.
    const int &back() const;
    // does exactly the same thing the accessor (const) version of back does
    int & back();
    //Assigns new content to the vector object, dropping all the elements contained in the vector before the call and replacing them by those specified by the parameters. The new value of size will be n and all values stored in the vector will have the value of the 2nd parameter.
    //If the new value of size will be larger than capacity, then this function must first expand capacity by either double (expand()) or by increasing the capacity by a specific amount (expand(n - cap)), whichever results in the largest capacity.
    void assign(unsigned n, int value);
    //This function inserts a value at the back end of the array.
    //Size will be increased by 1. However, If size will become larger than capacity, this function needs to first increase the capacity. In other words, if capacity and size are both 20 when this function is called, capacity must first be increased to 40 and then size can be increased to 21
    void push_back(int value);
    //This function just needs to decrease size by 1.
    //This function will never thrown an exception. Calling pop_back on an empty vector will cause undefined behavior
    void pop_back();
    //This function reduces the size of the vector to 0.
    void clear();
    //This function resizes the vector to contain size elements
    //If size is smaller than the current size(sz), this function just reduces the value of sz to size.
    //If size is greater than the current size(sz), then the appropriate number of elements are inserted at the end of the vector, giving all of the new elements the value passed in through the 2nd parameter (value)
    //If the new value of size will be larger than capacity, then the capacity must first be expanded by either doubling (expand()) or by increasing the capacity by a specific amount (expand(size - cap)), whichever results in the largest capacity. Then, this function can then increase the size appropriately
    void resize(unsigned size, int value = 0);
    //This function requests that the capacity (the size of the dynamically allocated array) be set to n at minimum. This informs the vector of a planned increase in size.
    //This function should NOT ever reduce the size of the vector. If n is larger than the current capacity then the capacity should be expanded to n.
    //A call to this function never affects the elements contained in the vector, nor the vector's size.
    void reserve(unsigned n);

    private:
    //stores size of the IntVector (the number of elements currently being used)
    unsigned int sz;
    //store size of array;
    unsigned int cap;
    //stores the address of the dynamically-allocated array of integers
    int *data;
    //double the capacity of the vector. This function should reallocate memory for the dynamically allocated array and update the value of capacity. Make sure your expand() function properly handles the case when capacity is 0 before calling expand(). This will be a special case within the expand() function
    void expand();
    //expand the capacity of the vector by the amount passed in. This function should reallocate memory for the dynamically allocated array and update the value of capacity.
    void expand(unsigned amount);

};
#endif