# Documentation for the `big_int` class

## Introduction and overview of the class

This is the documentation for an arbitrary-precision integer class called `big_int`; the code for this class can be found in the file `"big_int.hpp"`. The class has three constructors: the default constructor that creates the integer `0`, a constructor that converts a signed 64-bit integer to an arbitrary precision integer, and a constructor that takes a string of digits and converts it to an arbitrary precision integer. In addition, the class overloads comparision operators such as `==`, `!=`, `<=`, `<`, `>=`, and `>`, as well as arithmetic operators, such as `+=`, `+`, `-=`, `-`, `*=`, and `*`. The `big_int` class also has the capability of overloading the unary negation operator `-`, the assignment operator `=`, and the insertion operator `<<`.

In the following section, I will describe the key algorithms and bits of code that form the constructors and all member functions associated with the `big_int` class. The final section will consist of a demo code (and associated explanation) that illustrates the full capability of this class, with several tests provided. Please consult the code below for a brief overview of the constructors, public member functions, and the one private member `value` (signifying the value of a `big_int object`). The code below will be explored in greater detail in the following section!

```cpp
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

/**
 * @brief A class for arbitrary-precision integers, called `big_int`. It takes signed 64-bit integers or
 * and strings of digits (with a possible negative sign at the beginning) as constructors, and has several
 * member functions that overload boolean and arithmetic operators. * 
 */
class big_int {
public:

    ///// CONSTRUCTORS /////

    /**
     * @brief Default constructor that creates the integer 0
     */
    big_int();

    /**
     * @brief Constructor that takes a signed 64-bit integer and converts it to big_int
     * 
     * @param _value The signed 64-bit integer, given as a constant reference.
     */
    big_int(const int64_t &_value);

    /**
     * @brief Constructor that takes a string of digits and converts it to big_int.
     *
     * @param num_string The input string, given as constant reference.
     */
    big_int(const string &num_string);

    /**
     * @brief Overload == operator to check for equivalence between big_int numbers.
     *
     * @param rhs The big_int object to compare our original big_int object to.
     * @return true if the two big_int numbers are equal.
     * @return false if the two big_int numbers are not equal.
     */
    bool operator==(big_int &rhs);

    /**
     * @brief Overload != operator to see if two big_int numbers are not equal.
     *
     * @param rhs The big_int object to compare our original big_int object to.
     * @return true if the two big_int numbers are not equal.
     * @return false if the two big_int numbers are equal.
     */
    bool operator!=(big_int &rhs);

    /**
     * @brief Overload <= operator to see if one big_int number is less than or equal to another big_int number.
     *
     * @param rhs The big_int object to compare our original big_int object to.
     * @return true if the initial big_int number is less than or equal to rhs.
     * @return false if the initial big_int number is greater than rhs.
     */
    bool operator<=(big_int &rhs);

    /**
     * @brief Overload < operator to see if one big_int number is less than another big_int number.
     *
     * @param rhs The big_int object to compare our original big_int object to.
     * @return true if the initial big_int number is less than rhs.
     * @return false if the initial big_int number is greater than or equal to rhs.
     */
    bool operator<(big_int &rhs);

    /**
     * @brief Overload > operator to see if one big_int number is greater than another big_int number.
     *
     * @param rhs The big_int object to compare our original big_int object to.
     * @return true if the initial big_int number is greater than rhs.
     * @return false if the initial big_int number is less than or equal to rhs.
     */
    bool operator>(big_int &rhs);

    /**
     * @brief Overload >= operator to see if one big_int number is greater than or equal to another big_int number.
     *
     * @param rhs The big_int object to compare our original big_int object to.
     * @return true if the initial big_int number is greater than or equal to rhs.
     * @return false if the initial big_int number is less than rhs.
     */
    bool operator>=(big_int &rhs);

    /**
     * @brief Overload the assignment operator (=) to assign one value of big_int to another big_int object.
     *
     * @param rhs The big_int object whose value will be assigned.
     * @return big_int& The big_int object to which the value of rhs will be assigned.
     */
    big_int& operator=(const big_int &rhs);

    /**
     * @brief Overload negation operator (-) to return the negative of a big_int number.
     *
     * @return big_int& The negative of a big_int number.
     */
    big_int& operator-();

    /**
     * @brief Overload compound addition operator (+=), thus adding a big_int number to an initial big_int number.
     *
     * @param rhs The big_int number that is to be added.
     * @return big_int& The sum of the initial big_int and rhs, updating the initial big_int value.
     */
    big_int& operator+=(big_int &rhs);

    /**
     * @brief Overload addition operator (+) to obtain the sum of two big_int numbers.
     *
     * @param rhs The second big_int number that is to be added.
     * @return big_int& The sum of the initial big_int and rhs.
     */
    big_int &operator+(big_int &rhs);

    /**
     * @brief Overload compound subtraction operator (-=), thus subtracting a big_int number from an initial 
     * big_int number.
     *
     * @param rhs The big_int number that is to be subtracted.
     * @return big_int& The difference between the initial big_int and rhs, updating the initial big_int value.
     */
    big_int &operator-=(big_int &rhs);

    /**
     * @brief Overload subtraction operator (-) to obtain the difference of two big_int numbers.
     *
     * @param rhs The big_int number that is to be subtracted.
     * @return big_int& The difference between the initial big_int and rhs.
     */
    big_int &operator-(big_int &rhs);

    /**
     * @brief Overload compound multiplication operator (*=), thus multiplying a big_int number with another 
     * big_int number.
     *
     * @param rhs The big_int number that is to be multiplied.
     * @return big_int& The product of the initial big_int and rhs, updating the initial big_int value.
     */
    big_int &operator*=(big_int &rhs);

    /**
     * @brief Overload multiplication operator (*) to obtain the product of two big_int numbers.
     *
     * @param rhs The second big_int number that is to be multiplied.
     * @return big_int& The product of the initial big_int and rhs.
     */
    big_int &operator*(big_int &rhs);

    /**
     * @brief Setter function to change or intialize the big_int string.
     * In addition, we ensure proper format of string using this function.
     *
     * @param num_string constant reference to string is accepted.
     */
    void set_big_int(const string &num_string);

    /**
     * @brief Friend function to print the big_int number to an output stream.
     *
     * @param out The stream to which the big_int object will be inserted.
     * @param x The big_int object.
     * @return ostream& Reference to the output stream.
     */
    friend ostream &operator<<(ostream &out, const big_int &x);

private:
    /**
     * @brief Arbitrary precision integer value of a big_int object. 
     * Data is stored as a string; operations implemented character by character.
     *
     */
    string value;
};
```

## Implementation of `big_int` class (through header file `bigint.hpp`)

### Setter function (`set_big_int`)

In order to introduce class invariants and preserve encapsulation, we introduce the setter function `set_big_int()`. The function will enable proper initialization of arbitrary-precision integers through the aforementioned constructors. It accepts the constant string parameter `num_string` as a reference, and will ensure that the parameter satisfies certain criteria to be accepted as valid data for the `big_int` class.

The setter function first checks to see if the user inputted an empty string, which is not a valid numeric input. If this is the case, the following exception is thrown (using the `<stdexcept>` header): `"Error: An empty string cannot be an input!"`. The next invalid input that `set_big_int()` looks for is a sole negative sign that is not followed by any numbers. If this is the case, the exception `"Error: A string cannot only contain a negative sign! It must be followed by at least one digit."` is thrown. Lastly, the setter function determines if non-numeric characters exist in the string, excluding a possible initial negative sign. If the `find_first_not_of()` method finds any character other than a digit from 0 to 9 among the non-negative sign characters, the following exception is thrown: `"Error: String contains characters other than numeric digits, or a possible leading negative sign!"`.

If all invariants are respected, the setter function assigns the input parameter `num_string` to the private data member `value`. This is to say, the value of the arbitrary-precision integer will be equal to the inputted string if all invariants are preserved. The code for `set_big_int()` is provided below.

```cpp
// Setter function to check for valid string inputs:
void big_int::set_big_int(const string &num_string){
    // First check to see if string is empty.
    if (num_string.empty())
        throw invalid_argument("Error: An empty string cannot be an input!");

    // Then check the condition that the user inputted only a negative sign.
    if (num_string[0] == '-' && num_string.size() == 1)
        throw invalid_argument("Error: A string cannot only contain a negative sign! It must be followed by at least one digit.");

    // Then check if there are non-numeric characters in the string of length two or greater.
    // NOTE: The first character is permitted to be a negative sign ('-').
    
    // First, let's quickly determine the starting index.
    // This will tell the function `find_first_not_of()` where to begin looking for non-numeric characters.

    size_t starting_index = 0;

    if (num_string[0] == '-')
        starting_index = 1;

    // Now check for non-numeric characters after a potential negative sign.
    if (num_string.find_first_not_of("0123456789", starting_index) != string::npos)
        throw invalid_argument("Error: String contains characters other than numeric digits, or a possible leading negative sign!");

    value = num_string;
}
```

### Constructors

Now that we have expored the setter function, we can discuss the three constructors for the `big_int` class. The constructors are a fundamental aspect of encapsulation; by forcing the user to utilize the constructors instead of giving them the ability to manually modify `big_int` values, we ensure that the class invariants are preserved. This is because of each of our three constructs sets the arbitrary-precision integer using the `set_big_int()` member function. The first constructor is a default constructor that creates the arbitrary-precision integer zero:

```cpp
// Default constructor.
big_int::big_int() {
    set_big_int("0");
}
```

The second constructor takes a signed 64-bit integer and converts it to an arbitrary precision integer. It takes a constant reference to a signed 64-bit integer `_value` as its sole parameter, and converts it to a string using the `to_string()` method.

```cpp
// Constructor to convert signed 64-bit int to big_int.
big_int::big_int(const int64_t &_value) {
    set_big_int(to_string(_value));
}
```

The last of the three constructors takes a string of digits and converts it to an arbitrary precision integer. It takes a constant reference to a string `num_string` as its sole parameter.

```cpp
// Constructor that takes big_int as a string.
big_int::big_int(const string &num_string) {
    set_big_int(num_string);
}
```

### Overloading the assignment operator `=`

First, we overload the assignment operator `=`, thus taking the value of one `big_int` member and assigning it to another `big_int` member. The function takes a *constant* reference to a `big_int` object `rhs` as its sole parameter, since there is no need for ever modifying `rhs` during the assignment process. The operator then overloads `=` by assigning the private member `value` the value of the `rhs` object, and then returning the new value of the original ("left hand side") object.

```cpp
// Overload the assignment operator (=) to assign one value of big_int to another big_int object.
big_int& big_int::operator=(const big_int &rhs) {
    // Assign the rhs value to the original object
    value = rhs.value;
    return *this;
}
```

### Comparison operators: overloading the `==` and `!=` operators

We now begin the process of overloading various comparison operators as member functions, beginning with the equivalence comparison operators `==` and `!=`. Both operators take a reference to a `big_int` object `rhs` as their sole parameter. In the case of `==`, the overloaded operator returns a value of `1` (i.e. `true`) if two arbitrary-precision integers are equal and `0` (i.e. `false`) if they are not equal. The opposite holds for the `!=` operator. Note that we are choosing to deal with non-constant references (and will do so henceforth, unless stated otherwise), as the inputted strings might need to be modified to facilitate comparison between inputs that contain leading zeros. For example, we must modify the number `"123"` in our function to compare it to an input of `"00000123"`, and to correctly return a value of `1` if comparing the two using the overloaded `==` operator (since `"123"` and `"00000123"` are equivalent expressions of the same integer).

In the function that overloads the `==` operator, we first create temporary objects using the overloaded assignment operator `=`, so as to not modify original objects. Then, we consider the case of two negative integers (i.e. strings that begin with the `-` character). We pad the shorter string with zeros to facilitate comparison of the two numbers, inserting the zeros *after* the negative sign using the `insert()` method. The case where both numbers are non-negative or the two numbers have different signs is handled similarly, but we do not care about the presence of a possible negative sign in the latter case, since the comparison will fail immediately and return `false`. For all cases, the number of zeros that are padded before the first digit of the shorter string is equal to the difference in size/length between the two strings, so that the two strings that are to be compared have equal size.

We then use a `for` loop to compare each digit of the two numbers. The algorithm stops at the first index where the two arbitrary-precision integers have different characters, and consequently return `false`. If the two strings are identical (same characters at each and every index), the function returns `true`. The code for the overloaded `==` operator is provided below:

```cpp
// Overload == operator to check if two big_int values are equal.
bool big_int::operator==(big_int& rhs) {
    // Create temporary objects so as to not modify original objects.
    big_int temp_val = value;
    big_int temp_rhs = rhs.value;

    // First consider the case of two negative numbers:
    if (value[0] == '-' && rhs.value[0] == '-') {
        // Pad the shorter string with leading zeros, so that the strings are of equal length.
        if (temp_val.value.size() < temp_rhs.value.size())
        {
            // If the string of the original value is shorter, add the difference in string length (in zeros).
            // Add the zeros after the negative sign!
            temp_val.value = temp_val.value.insert(1, (temp_rhs.value.size() - temp_val.value.size()), '0');
        }
        
        if (temp_val.value.size() > temp_rhs.value.size())
        {
            // If the string of the new value is shorter, add the difference in string length (in zeros).
            temp_rhs.value = temp_rhs.value.insert(1, (temp_val.value.size() - temp_rhs.value.size()), '0');
        }
    } else {
        // Do something similar for all other cases (two positives or one positive, one negative).
        if (temp_val.value.size() < temp_rhs.value.size())
        {
            // If the string of the original value is shorter, add the difference in string length (in zeros).
            temp_val.value = temp_val.value.insert(0, (temp_rhs.value.size() - temp_val.value.size()), '0');
        }
        else if (temp_val.value.size() > temp_rhs.value.size())
        {
            // If the string of the new value is shorter, add the difference in string length (in zeros).
            temp_rhs.value = temp_rhs.value.insert(0, (temp_val.value.size() - temp_rhs.value.size()), '0');
        }
    }

    // Compare each digit of the two numbers.
    // Stop at the first instance of the first number having a different value than the second number.
    for (size_t i = 0; i < temp_val.value.size(); ++i)
    {
        if (temp_val.value[i] != temp_rhs.value[i])
        {
            return false;
        }
    }

    return true;
}
```

We then use the overloaded `==` operator when overloading the `!=` operator to check if two arbitrary-precision integers are *not* equal. The function checks if two arbitary-precision integers are equal, and then returns the *opposite*.

```cpp
// Overload the != operator to check if two big_int values are not equal.
bool big_int::operator!=(big_int& rhs) {
    return !(value == rhs.value);
}
```

### Comparison operators: overloading the `<=` operator

Turning our attention to the `<=` operator, we are now interested in determining if one arbitrary-precision integer is less than another one. As was the case for the `==` operator, the overloaded `<=` operator takes a reference to a `big_int` object `rhs` as its sole parameter, returning a value of `1` (i.e. `true`) if the "left" arbitrary-precision integer is less than or equal to the "right" number, and `0` (i.e. `false`) if it is greater.

The function begins by creating temporary objects using the overloaded assignment operator `=`, so as to not modify the original objects. Then, we check if the two arbitrary-precision integers are equal, using the previously overloaded `==` operator. If this is the case, a value of `1` is returned. Then, the function considers the signs of the two numbers. If the first string begins with a negative sign `-` and the second one does not, then we know that the first number is negative while the second is non-negative. Consequently, the first arbitrary-precision integer is smaller than the second, and a value of `1` is returned. Alternatively, if the first string does not start with a negative sign but the second one does, then we know that the first number is larger than the second, and a value of `0` is thus returned.

If both numbers are *non-negative* or both numbers are *negative*, we first pad the shorter string with zeros in the manner described earlier (when overloading the `==` operator), so that the strings are of equal length. Using a `for` loop, we then iterate through each of the indices in the strings, comparing their digits. If both numbers are non-negative, the function returns `0` at the first instance of the "left" digit being *greater than* the "right" digit, since this would imply that the first arbitrary-precision integer is greater than the second one. Alternatively, the function returns `1` at the first instance of the "left" digit being *less than* the "right" digit, since this implies that the first arbitrary-precision integer is less than the second one. 

The loop is similar if both numbers are negative, except for a switch in conditions. A value of `0` is returned at the first instance of the "left" digit being *less than* the "right" digit, since that implies that the first arbitrary-precision integer is less negative than (and thus greater than) the second one. Alternatively, a value of `1` is returned as soon as the "left" digit is *less than* the "right" digit, since that implies that the first arbitrary-precision integer is *more* negative than (and thus less than) the second one. In both cases (two non-negative arbitrary-precision integers or two negative ones), if there is never an instance where the "left" digit differs from the "right" digit, then we know that the two numbers are equal, and a value of `1` is thus returned.

This is all captured in the code below!

```cpp
// Overload the <= operator to check if one big_int value is less than or equal to another one.
bool big_int::operator<=(big_int &rhs) {
    // Create temporary objects so as to not modify original objects.
    big_int temp_val = value;
    big_int temp_rhs = rhs.value;
    
    // The case where they are equal.
    if (value == rhs.value) {
        return true;
    }
    // The case where the first number is negative and the second is non-negative.
    else if (value[0] == '-' && rhs.value[0] != '-') {
        return true;
    }
    // The case where the first number is non-negative and the second is negative.
    else if (value[0] != '-' && rhs.value[0] == '-') {
        return false;
    }
    // The case where both numbers are non-negative.
    else if (value[0] != '-' && rhs.value[0] != '-') {
        // First, let's pad the shorter string with leading zeros, so that the strings are of equal length.
        if (temp_val.value.size() < temp_rhs.value.size())
        {
            // If the string of the original value is shorter, add the difference in string length (in zeros).
            temp_val.value = temp_val.value.insert(0, (temp_rhs.value.size() - temp_val.value.size()), '0');
        }
        
        if (temp_val.value.size() > temp_rhs.value.size())
        {
            // If the string of the new value is shorter, add the difference in string length (in zeros).
            temp_rhs.value = temp_rhs.value.insert(0, (temp_val.value.size() - temp_rhs.value.size()), '0');
        }

        // Compare each digit of the two numbers.
        // Stop at the first instance of the first number having a smaller digit than the second number.
        for (size_t i = 0; i < temp_val.value.size(); ++i) {
            if (temp_val.value[i] > temp_rhs.value[i])
            {
                return false;
            } else if (temp_val.value[i] < temp_rhs.value[i]) {
                return true;
            }
        }

        return true;
    }
    // The case where both numbers are negative.
    else if (value[0] == '-' && rhs.value[0] == '-') {
        // First, let's pad the shorter string with leading zeros, so that the strings are of equal length.
        if (temp_val.value.size() < temp_rhs.value.size())
        {
            // If the string of the original value is shorter, add the difference in string length (in zeros).
            temp_val.value = temp_val.value.insert(1, (temp_rhs.value.size() - temp_val.value.size()), '0');
        }
        
        if (temp_val.value.size() > temp_rhs.value.size())
        {
            // If the string of the new value is shorter, add the difference in string length (in zeros).
            temp_rhs.value = temp_rhs.value.insert(1, (temp_val.value.size() - temp_rhs.value.size()), '0');
        }

        // Compare each digit of the two numbers.
        // Stop at the first instance of the first number having a greater digit than the second number.
        // Start at second index to avoid comparing negative signs.
        for (size_t i = 1; i < temp_val.value.size(); ++i) {
            if (temp_val.value[i] < temp_rhs.value[i])
            {
                return false;
            }
            else if (temp_val.value[i] > temp_rhs.value[i])
            {
                return true;
            }
        }

        return true;
    }

    return false;
}
```

### Comparison operators: overloading the `<`, `>`, and `>=` operators

We continue our technique of using previously overloaded operators to overload new operators. The `<`, `>`, and `>=` operators all take a non-constant reference to a `big_int` object `rhs` as its sole parameter. The overloaded `<` operator returns a value of `1` (i.e. `true`) if the "left" arbitrary-precision integer is strictly less than the "right" arbitrary-precision integer, and `0` (i.e. `false`) if it is greater. In other words, it checks if the initial number is less than `rhs` *and* *not* equal to it (using the previously overloaded `<=` and `!=` operators, respectively), returning `1` if that is indeed the case, and `0` otherwise.

```cpp
// Overload the < operator to check if one big_int value is less than another one.
bool big_int::operator<(big_int& rhs) {
    if (*this <= rhs && *this != rhs)
        return true;
    return false;
}
```

Alternatively, the overloaded `>` operator returns a value of `1` if the "left" arbitrary-precision integer is strictly greater than the "right" arbitrary-precision integer, and `0` if it is less than or equal to the "right" number. In other words, it checks if the initial number is less than `rhs` *or* equal to it (using the previously overloaded `<` and `==` operators, respectively), returning `0` if that is the case, and `1` otherwise.

```cpp
// Overload the > operator to check if one big_int value is greater than another one.
bool big_int::operator>(big_int &rhs) {
    if (*this < rhs || *this == rhs)
        return false;
    return true;
}
```

Lastly, the overloaded `>=` operator returns a value of `1` if the "left" arbitrary-precision integer is greater than or equal to the "right" arbitrary-precision integer, and `0` if it is strictly less than the "right" integer. In other words, it checks if the initial number is greater than `rhs` *or* equal to it (using the previously overloaded `>` and `==` operators, respectively), returning `1` if that is the case, and `0` otherwise.

```cpp
// Overload the >= operator to check if one big_int value is greater than or equal to another one.
bool big_int::operator>=(big_int &rhs) {
    if (*this > rhs || *this == rhs)
        return true;
    return false;
}
```

### Overloading the unary negation operator `-`

When overloading the unary negation operator `-`, we immediately notice that the function takes no parameters. This is because no new objects are introduced in the process of negating an arbitrary-precision integer! The function first considers the case of a negative arbitrary-precision integer, which is subsequently negated by removing its negative sign using the `erase()` method. Next, the function considers the case of a positive number, which is negated by inserting a negative sign at the beginning of the string using the `insert()` method. The negated number is then returned.

```cpp
// Overload the negation operator (-) to return the negative of a big_int value.
big_int& big_int::operator-() {
    // First consider the case of converting a negative number to a positive number:
    if (value < "0") {
        // Remove the negative sign.
        value = value.erase(0, 1);
    } else if (value > "0") {
        // Insert a negative sign
        value = value.insert(0, "-");
    }

    return *this;
}
```

### Arithmetic operators: overloading the `+=`, `+`, `-=`, and `-` operators

Let us first consider the compound addition-and-assignment operator `+=`. Like the comparison operators, it takes a non-constant reference to a `big_int` object `rhs` as its sole parameter. The overloaded `+=` operator will return the sum of an arbitrary-precision integer with `rhs`, and assign the summed value as the new value of the initial `big_int` object. 

The function begins by defining temporary objects `temp_val` and `temp_rhs`. We use the overloaded assignment operator `=` to define these temporary objects because otherwise, we would have to convert the original `big_int` objects to absolute values in order to facilitate digit by digit addition. The conditions for addition depend on the sign of the original `big_int` objects, and modifying them would change the final sum! That is why our two temporary objects are required. After we have introduced `temp_val` and `temp_rhs`, we take the absolute value of these two arbitrary-precision integers, by negating them using the overloaded unary `-` operator if either (or both) are negative! We then pad the shorter string with leading zeros (as explained earlier), in order to facilitate digit by digit addition. 

Two cases are then considered: (1) the addition of two arbitrary-precision integers with the *same* sign (either both non-negative or both negative), and (2) the addition of two arbitrary-precision integers with *different* signs (one non-negative and the other negative). Let us begin with the first case, and define a `string` variable `sum_result` to store the resulting sum, an `int` variable `digit_sum` to keep track of the sum of two digits at each iteration of the `for` loop, and an `int` variable `carry_sum` to keep track of the carry, should the sum of two digits be greater than or equal to 10. We then use a `for` loop to add the two strings together, digit by digit, from left to right. Once again, we only consider the cases where the both signs are the same (two non-negative or two negative numbers). In the case of two negative numbers, we can think of the sum of the two as the negation of the sum of their positive counterparts. We then reverse both strings using the `reverse()` method (from the `<algorithm>` header), so that we can perform addition from left to right (i.e. from the ones column onwards).

Inside the `for` loop, we add each digit of the two strings, accounting for a possible carry. The ones column of the resulting digit sum is then pushed to the back of the `sum_result` string, making sure to first convert the `int` to a `char`. The carry is then calculated using floor division. If the digit sum is greater than or equal to 10, the carry will be 1; if it is less than 10, the carry will be 0. If there is a remaining carry once all indices of the two strings have been added, the `1` is converted from an `int` to a `char`, and appended to the back of `sum_result`. The resulting string is then reversed, so that the sum can be read from left to right.

Let us now consider the second case, where addition is performed between two arbitrary-precision integers of *different* signs. This is tantamount to subtraction; as a consequence, the order in which one number is subtracted from another is highly important! We initialize a `string` variable `diff_result` to store the resulting difference, an `int` variable `digit_diff` to keep track of the difference between two digits at each iteration of the `for` loop, and an `int` variable `borrow` to keep track of the borrow, should the difference between two digits be less than 0. While it could be possible to perform the subtraction using `if` and `else` conditions (depending on the sign of the original arbitrary-precision integers), we simplify the process by following the first step of the algorithm displayed [here](https://www.geeksforgeeks.org/difference-of-two-large-numbers/). We ensure that the larger number is always the "first" number using the `swap()` method, before reversing the two strings to facilitate left-to-right subtraction. 

Inside the `for` loop, we subtract the digit of the second string *from* the corresponding digit of the first string at each index, accounting for a possible borrow. If the digit difference is less than zero, we add 10 to the digit difference and assign a value of `-1` for the borrow; otherwise, the digit difference is not modified and the borrow remains equal to 0. The digit difference (converted to a `char`) is then appended to the back of the `diff_result` string, and the resulting string is reversed once all indices have been completed in the `for` loop.

In order to determine whether the final sum of two arbitrary-precision integers requires a negative sign, we first reverse the temporary strings, since they were initially reversed to facilitate digit-by-digit addition or subtraction. We initialize a `string` variable called `final_result`, which will consider taking the negative of a value, based on the sign of the inputs. If both arbitrary-precision integers are non-negative, the `final_result` is equivalent to `sum_result`. If both arbitrary-precision integers are negative, the `final_result` is the negative of the `sum_result` (i.e. a negative sign `-` is appended to the beginning of `sum_result`, using the `insert()` method).

If the arbitrary-precision integers have different signs, then the absolute values of the integers must be considered. If the first number is negative and the second number is non-negative, and the absolute value of the first number is *less than or equal to* that of the second number, then the `final_result` is equivalent to the `diff_result`. If the first number is negative and the second number is non-negative, and the absolute value of the first number is *greater than* that of the second number, then `final_result` is the negative of `diff_result`.

Similarly, if the second number is negative and the first number is non-negative, and the absolute value of the second number is *less than or equal to* that of the first number, then `final_result` is equivalent to `diff_result`. If the second number is negative and the first number is non-negative, and the absolute value of the second number is *greater than* that of the first number, then the `final_result` is the negative of `diff_result`. The function concludes by assigning the `final_result` to the `value` of the original `big_int` object, and returning the modified `value`!

The code for overloading the `+=` operator is provided below.

```cpp
// Overload the compound addition operator (+=):
big_int& big_int::operator+=(big_int &rhs){
    // First, let's define temporary objects temp_val and temp_rhs
    // We need to convert the original big_ints to absolute values to facilitate digit by digit addition.
    // But conditions for addition depend on the sign of the original big_ints.
    // So temporary objects are required to prevent the sum of two big_ints from always being the sum of the absolute value of the big_ints.

    big_int temp_val = value;
    big_int temp_rhs = rhs.value;

    // Ensure that we are dealing with the absolute values of the big_int numbers.
    // We will deal with signs at the end.

    // If the original big_int is negative, convert to a positive using the overloaded negation operator.
    if (value[0] == '-') {
        temp_val = -temp_val;
    } else {
        temp_val = temp_val;
    }

    // If the big_int "rhs" is negative, similarly convert to a positive value.
    if (rhs.value[0] == '-') {
        temp_rhs = -temp_rhs;
    } else {
        temp_rhs = temp_rhs;
    }

    // Next, let's pad the shorter string with leading zeros, so that the strings are of equal length.
    if (temp_rhs.value.size() > temp_val.value.size()) {
        // If the string of the original value is shorter, add the difference in string length (in zeros).
        temp_val = temp_val.value.insert(0, (temp_rhs.value.size() - temp_val.value.size()), '0');
    } 
    
    if (temp_val.value.size() > temp_rhs.value.size()) {
        // If the string of the new value is shorter, add the difference in string length (in zeros).
        temp_rhs = temp_rhs.value.insert(0, (temp_val.value.size() - temp_rhs.value.size()), '0');
    }

    ///// ADDING TWO POSITIVE NUMBERS OR TWO NEGATIVE NUMBERS /////

    // Initialize a string to which we will append each of the summed digits:
    string sum_result = "";

    // Initialize a variable to keep track of the sum of two digits at each iteration of the for loop.
    int digit_sum = 0;

    // Initialize a variable to keep track of the carry, should the sum of two digits be greater than or equal to 10.
    int carry_sum = 0;

    // Use a for loop to add the two strings together, digit by digit, from left to right.
    // Only consider the cases where the both signs are the same (two positive or two negative numbers)
    if ((value[0] != '-' && rhs.value[0] != '-') || (value[0] == '-' && rhs.value[0] == '-')) {
        
        // First reverse both strings, so that we can perform addition from left to right, not right to left.
        reverse(temp_val.value.begin(), temp_val.value.end());
        reverse(temp_rhs.value.begin(), temp_rhs.value.end());

        for (size_t i = 0; i < temp_val.value.size(); i++)
        {
            // Add each digit of the big_ints, from left to right.
            // For the case where both numbers are negative, we will take the negative at the end.
            digit_sum = (temp_val.value[i] - '0') + (temp_rhs.value[i] - '0') + carry_sum;

            // Take the digit sum, and push the ones column to the back of the sum_result string.
            // The ones column is just the digit sum mod 10.
            // Be sure to convert the ones digit from an int to a char.
            sum_result.push_back(static_cast<char>(digit_sum % 10 + '0'));

            // Redefine the carry. Since carry is an int, floor division will be performed.
            // If the digit sum is greater than or equal to 10, the carry will be 1.
            // If the digit sum is less than 10, the carry will be 0.
            carry_sum = digit_sum / 10;
        }
    }

    // If there is a remaining 1 to carry over, add the 1 to the back of the sum_result string.
    // Make sure to convert the 1 to a character.
    if (carry_sum == 1) {
        sum_result.push_back(static_cast<char>(carry_sum + '0'));
    }

    // Reverse the sum_result string, so that the sum can be read from left to right.
    reverse(sum_result.begin(), sum_result.end());

    ///// ADDING A POSITIVE AND A NEGATIVE NUMBER (I.E. SUBTRACTING) /////

    // Initialize a string to which we will append each of the subtracted digits:
    string diff_result = "";

    // Initialize a variable to keep track of the difference between two digits at each iteration of the for loop.
    int digit_diff = 0;

    // Initialize a variable to keep track of the borrow
    // (If the difference of two digits is less than 0.)
    int borrow = 0;

    // This occurs when one number is positive and the other is negative.
    if ((value[0] == '-' and rhs.value[0] != '-') || (value[0] != '-' and rhs.value[0] == '-')) {
        // First make sure that the larger number (in absolute value) is the first number (i.e. on top):
        if (temp_val.value < temp_rhs.value) {
            swap(temp_val, temp_rhs);
        }

        // Reverse both strings, so that we can perform addition from left to right, not right to left.
        reverse(temp_val.value.begin(), temp_val.value.end());
        reverse(temp_rhs.value.begin(), temp_rhs.value.end());

        // Use for loop to add digit by digit, taking the negative digit if the big_int input is negative.
        for (size_t i = 0; i < temp_val.value.size(); i++)
        {
            // Perform subtraction
            digit_diff = (temp_val.value[i] - '0') - (temp_rhs.value[i] - '0') - borrow;

            // If the difference in digits is less than 0
            // Add 10 to the difference and update the borrow (i.e. borrow = 1)
            // Otherwise, leave the difference in digits alone, and keep the borrow at 0
            if (digit_diff < 0) {
                digit_diff += 10;
                borrow = 1;
            } else {
                digit_diff = digit_diff;
                borrow = 0;
            }
            
            // Append the difference of digits to the back of the diff_result string.
            diff_result.push_back(static_cast<char>(digit_diff + '0'));
        }
    }

    // Reverse the diff_result string, so that the difference can be read from left to right.
    reverse(diff_result.begin(), diff_result.end());

    // Reverse both temporary strings, so that we can compare absolute values.
    // This will help us determine signs for the final result.
    // We must do this because we reversed the temporary strings while calculating the difference.
    reverse(temp_val.value.begin(), temp_val.value.end());
    reverse(temp_rhs.value.begin(), temp_rhs.value.end());

    // Initialize a final result string.
    // This will consider taking the negative of a value, based on the sign of the inputs.
    string final_result;

    // Now consider the different cases (positive or negative) of our two big_ints.
    // This will determine whether to introduce a negative sign to our final answer.

    // If both big_ints are non-negative, then do not take the negative of the result.
    if (value[0] != '-' && rhs.value[0] != '-')
    {
        final_result = sum_result;
    }
    // If both big_ints are negative, then take the negative of the result.
    else if (value[0] == '-' && rhs.value[0] == '-')
    {
        final_result = sum_result.insert(0, "-");
    }
    // If big_ints are different signs, then consider the absolute values of numbers.
    // If the first number is negative and the second number is non-negative:
    else if (value[0] == '-' && rhs.value[0] != '-')
    {
        // Consider the case where the absolute value of the first number is smaller (or the two are equal)
        if (-(*this) <= rhs) {
            final_result = diff_result;
        } else {
            // Case where the absolute value of the first number is larger
            final_result = diff_result.insert(0, "-");
        }
    }
    // If the first number is non-negative and the second number is negative:
    else if (value[0] != '-' && rhs.value[0] == '-') {
        // Consider the case where the absolute value of the second number is smaller (or the two are equal)
        if (-(*this) <= rhs) {
            final_result = diff_result;
        } else {
            // Case where the absolute value of the second number is larger
            final_result = diff_result.insert(0, "-");
        }
    }

    // Set the original big_int equal to the final_result string, and return the original, modified big_int value!
    value = final_result;
    return *this;
}
```

When considering the `+`, `-=`, and `-` arithmetic operators, it is important to note that each of the three functions take a non-constant reference to a `big_int` object `rhs` as their sole parameter. The addition operator `+` returns the sum of two arbitrary-precision integers, adding `rhs` to the `value` of the original `big_int` object using the overloaded `+=` operator.

```cpp
// Overload addition operator (+):
big_int& big_int::operator+(big_int &rhs) {
    return *this += rhs;
}
```

The compound subtraction-and-assignment operator `-=` returns the difference of two arbitrary-precision integers, assigning this difference value to the initial `big_int` object. It initializes a temporary `big_int` object by using the overloaded assignment operator `=`. It then utilizes the overloaded `+=` and (unary) `-` operators by adding the negative of `temp` (i.e. the negative of `rhs.value`) to the `value` of the original `big_int` object, and assigning the difference to the `value` of the initial `big_int` object.

```cpp
// Overload compound subtraction operator (-=):
big_int &big_int::operator-=(big_int &rhs)
{
    // Create a temporary big_int object to store rhs
    big_int temp = rhs.value;
    // Add the negative of the new big_int.
    return *this += -temp;
}
```

The subtraction operator `-` returns the difference of two arbitrary-precision integers, subtracting `rhs` from the `value` of the original `big_int` object using the overloaded `-=` operator.

```cpp
// Overload subtraction operator (-):
big_int &big_int::operator-(big_int &rhs)
{
    return *this -= rhs;
}
```

**NOTE** While writing the documentation, I noticed that by defining the operator overloads `+`, `-`, and `*` as member functions, I am accidentally modifying/re-assigining the original value, and effectively making the three overloads equivalent to `+=`, `-=`, and `*=`, respectively. I tried to fix my mistake but ran out of time, and will accept the corresponding point deduction. My apologies.

### Arithmetic operators: overloading the `*=` and `*` operators

The compound multiplication-and-assignment operator `*=` takes a non-constant reference to a `big_int` object `rhs` as its sole parameter. The overloaded `*=` operator will return the product of an arbitrary-precision integer with `rhs`, and assign the resulting product as the new `value` of the initial `big_int` object.

As was the case for `+=`, the function for overloading the `*=` operator begins by defining temporary objects `temp_val` and `temp_rhs`, using the overloaded assignment operator `=` to define these temporary objects. After we have introduced `temp_val` and `temp_rhs`, we take the absolute value of these two arbitrary-precision integers, by negating them using the overloaded unary `-` operator if either (or both) are negative. We then pad the shorter string with leading zeros (as explained earlier), in order to facilitate digit by digit multiplication. 

Afterwards, we reverse the temporary strings in order to perform multiplication from least digit to greatest digit (i.e. from the ones column onwards), before initializing a `string` variable `prod_result` to store the each of the multiplied digits, and an `int` variable `digit_prod` to keep track of the product of two digits at each iteration of the `for` loops. Inside the first `for` loop, we intialize an `int` variable called `carry_prod` to account for the carry in the next digit column. This is done inside the first `for` loop but outside the second `for` loop; we do this to reset the carry (to 0) after one digit column in the first string has been multiplied by ALL digits in the second string.

Inside the second `for` loop, we cyclically multiply the `i`-th digit of the first arbitrary-precision integer by each of the digits in the second arbitrary-precision integer, accounting for a possible carry. One should think of the first string as the bottom number in grade-school multiplication, and the second string as the top number. Unlike addition or subtraction, we must keep track of the digit placeholders that already exist. If a number is already in a particular digit column, the *ones column of the product* must be added to that column, while the tens column of the digit product must be carried over to the next column. If a number is not already in a particular digit placeholder, then we append the ones column of the digit product to the back of the `prod_result` string (after converting it to a `char`). Regardless of whether a digit placeholder is occupied by a number, the last step of the interior `for` loop calculates the carry at each iteration.

Once a single digit in the first string (bottom number), has been multiplied by all of the digits in the second string (top number), any remaining carry is converted to a `char` and appended to the back of the `prod_result` string. Once the exterior loop is complete, we reverse the `prod_result` string using the `reverse()` method, so that the product can be read from left to right. As we did for the `+=` case, we then initialize a `string` variable called `final_result` to account for the initial signs of the arbitrary-precision integers, and to negate the final product if need be. If both arbitrary-precision integers have the same sign, then `final_result` is simply `prod_result`. Alternatively, if the numbers have different signs, then we negate `prod_result` by inserting a negative sign `-` at the beginning of its string (using the `insert()` method), before assigning the negated string to `final_result`.

The function concludes by assigning the `final_result` to the `value` of the original `big_int` object, and returning the modified `value`! The code for overloading the `*=` operator is loosely based on the work done [here](https://www.geeksforgeeks.org/multiply-large-numbers-represented-as-strings/), and is shown below.

```cpp
// Overload compound multiplication operator (*=):
big_int &big_int::operator*=(big_int &rhs)
{
    // First, let's define temporary objects temp_val and temp_rhs, as we did for addition.
    big_int temp_val = value;
    big_int temp_rhs = rhs.value;

    // Ensure that we are dealing with the absolute values of the big_int numbers.
    // We will deal with signs at the end.

    // If the original big_int is negative, convert to a positive using the overloaded negation operator.
    if (value[0] == '-')
    {
        temp_val = -temp_val;
    }
    else
    {
        temp_val = temp_val;
    }

    // If the big_int "rhs" is negative, similarly convert to a positive value.
    if (rhs.value[0] == '-')
    {
        temp_rhs = -temp_rhs;
    }
    else
    {
        temp_rhs = temp_rhs;
    }

    // Reverse the temporary strings in order to perform multiplication from least digit to greatest digit
    // i.e. from ones column. to tens column, to hundreds column, and so on...
    reverse(temp_val.value.begin(), temp_val.value.end());
    reverse(temp_rhs.value.begin(), temp_rhs.value.end());

    // Initialize a string to which we will append each of the multiplied digits:
    string prod_result = "";

    // Initialize a variable to keep track of the product of two digits at each iteration of the for loop.
    int digit_prod = 0;

    // First we initialize a for loop to perform multiplication by each digit column in temp_val
    for (size_t i = 0; i < temp_val.value.size(); i++) {
        // Initialize a variable to keep track of the carry to the next digit column
        // This is done inside the first for loop but outside the second for loop.
        // We do this to reset the carry after one digit column in the first big_int has been multiplied by ALL digits
        // in the second big_int. This resets the carry back to 0.
        int carry_prod = 0;


        // We need a second for loop for multiplication by each digit column in temp_rhs
        for (size_t j = 0; j < temp_rhs.value.size(); j++) {
            digit_prod = (temp_val.value[i] - '0') * (temp_rhs.value[j] - '0') + carry_prod;

            // We must keep track of the digits that already exist.
            // If a number is already in that digit column, the ones column of the product must be added to that column.
            if ((i + j) < prod_result.size()) {
                digit_prod += (prod_result[i + j] - '0');
                
                // The ones column of the digit product is then added to the existing column.
                // The tens column of the digit product is carried over to the next column.
                prod_result[i + j] = static_cast<char>(digit_prod % 10 + '0');
            }
            // If a number is not already in the digit column, 
            // Then append the ones column of the digit product to the back of the product result string.
            else {
                prod_result.push_back(static_cast<char>(digit_prod % 10 + '0'));
            }

            // We then update the carry (the tens column of the digit product).
            carry_prod = digit_prod / 10;
        }

        // If there is a carry left over after the final digit multiplication,
        // Then it is appended to the back of the product result string.
        if (carry_prod > 0) {
            prod_result.push_back(static_cast<char>(carry_prod + '0'));
        }
    }

    // Reverse the prod_result string, so that the sum can be read from left to right.
    reverse(prod_result.begin(), prod_result.end());

    // Initialize a final result string.
    // This will consider taking the negative of a value, based on the sign of the inputs.
    string final_result;

    // Now consider the different cases (positive or negative) of our two big_ints.
    // This will determine whether to introduce a negative sign to our final answer.

    // If both big_ints are positive, or both big_ints are negative, then take the positive of the result.
    if ((value[0] != '-' && rhs.value[0] != '-') || (value[0] == '-' && rhs.value[0] == '-'))
    {
        final_result = prod_result;
    }
    // If the big_ints have different signs, then take the negative of the result. 
    else {
        final_result = prod_result.insert(0, "-");
    }

    // Set the original big_int equal to the final_result string, and return the original, modified big_int value!
    value = final_result;
    return *this;
}
```

The multiplication operator `*` takes a non-constant reference to a `big_int` object `rhs` as its sole parameter, and returns the product of two arbitrary-precision integers, multiplying `rhs` to the `value` of the original `big_int` object using the overloaded `*=` operator.

```cpp
// Overload multiplication operator (*):
big_int &big_int::operator*(big_int &rhs)
{
    return *this *= rhs;
}
```

### Overloading the insertion operator `<<`

In order to overload the insertion operator `<<`, we introduce a friend function that prints an arbitrary-precision integer to an output stream. The function takes an `ostream` object `out` as a parameter, and also takes a `big_int` object `x` as a parameter. It returns a reference to the output stream.

```cpp
// Friend function to print the big_int value to an output stream.
ostream& operator<<(ostream& out, const big_int& x) {
    return out << x.value;
}
```

## Demonstration of the capabilities of the `big_int` class

Consulting the demo file `"demo.cpp"`, we can observe and test the full capabilities of the `big_int` class.