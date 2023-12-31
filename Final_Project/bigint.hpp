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
     * @brief Data is stored as a string; operations implemented character by character.
     *
     */
    string value;
};

// Default constructor.
big_int::big_int() {
    set_big_int("0");
}

// Constructor to convert signed 64-bit int to big_int.
big_int::big_int(const int64_t &_value) {
    set_big_int(to_string(_value));
}

// Constructor that takes big_int as a string.
big_int::big_int(const string &num_string) {
    set_big_int(num_string);
}

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

// Overload == operator to check if two big_int values are equal.
bool big_int::operator==(big_int& rhs) {
    // First consider the case of two negative numbers:
    if (value[0] == '-' && rhs.value[0] == '-') {
        // Pad the shorter string with leading zeros, so that the strings are of equal length.
        if (value.size() < rhs.value.size())
        {
            // If the string of the original value is shorter, add the difference in string length (in zeros).
            // Add the zeros after the negative sign!
            value = value.insert(1, (rhs.value.size() - value.size()), '0');
        }
        
        if (value.size() > rhs.value.size())
        {
            // If the string of the new value is shorter, add the difference in string length (in zeros).
            rhs.value = rhs.value.insert(1, (value.size() - rhs.value.size()), '0');
        }
    } else {
        // Do something similar for all other cases (two positives or one positive, one negative).
        if (value.size() < rhs.value.size())
        {
            // If the string of the original value is shorter, add the difference in string length (in zeros).
            value = value.insert(0, (rhs.value.size() - value.size()), '0');
        }
        else if (value.size() > rhs.value.size())
        {
            // If the string of the new value is shorter, add the difference in string length (in zeros).
            rhs.value = rhs.value.insert(0, (value.size() - rhs.value.size()), '0');
        }
    }

    // Compare each digit of the two numbers.
    // Stop at the first instance of the first number having a different value than the second number.
    for (size_t i = 0; i < value.size(); ++i)
    {
        if (value[i] != rhs.value[i])
        {
            return false;
        }
    }

    return true;
}

// Overload the != operator to check if two big_int values are not equal.
bool big_int::operator!=(big_int& rhs) {
    return !(value == rhs.value);
}

// Overload the < operator to check if one big_int value is less than another one.
bool big_int::operator<=(big_int &rhs) {
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
        if (value.size() < rhs.value.size())
        {
            // If the string of the original value is shorter, add the difference in string length (in zeros).
            value = value.insert(0, (rhs.value.size() - value.size()), '0');
        }
        
        if (value.size() > rhs.value.size())
        {
            // If the string of the new value is shorter, add the difference in string length (in zeros).
            rhs.value = rhs.value.insert(0, (value.size() - rhs.value.size()), '0');
        }

        // Compare each digit of the two numbers.
        // Stop at the first instance of the first number having a smaller digit than the second number.
        for (size_t i = 0; i < value.size(); ++i) {
            if (value[i] > rhs.value[i])
            {
                return false;
            } else if (value[i] < rhs.value[i]) {
                return true;
            }
        }

        return true;
    }
    // The case where both numbers are negative.
    else if (value[0] == '-' && rhs.value[0] == '-') {
        // First, let's pad the shorter string with leading zeros, so that the strings are of equal length.
        if (value.size() < rhs.value.size())
        {
            // If the string of the original value is shorter, add the difference in string length (in zeros).
            value = value.insert(1, (rhs.value.size() - value.size()), '0');
        }
        
        if (value.size() > rhs.value.size())
        {
            // If the string of the new value is shorter, add the difference in string length (in zeros).
            rhs.value = rhs.value.insert(1, (value.size() - rhs.value.size()), '0');
        }

        // Compare each digit of the two numbers.
        // Stop at the first instance of the first number having a greater digit than the second number.
        // Start at second index to avoid comparing negative signs.
        for (size_t i = 1; i < value.size(); ++i) {
            if (value[i] < rhs.value[i])
            {
                return false;
            }
            else if (value[i] > rhs.value[i])
            {
                return true;
            }
        }

        return true;
    }

    return false;
}

// Overload the <= operator to check if one big_int value is less than or equal to another one.
bool big_int::operator<(big_int& rhs) {
    if (*this <= rhs && *this != rhs)
        return true;
    return false;
}

// Overload the > operator to check if one big_int value is greater than another one.
bool big_int::operator>(big_int &rhs) {
    if (*this < rhs || *this == rhs)
        return false;
    return true;
}

// Overload the >= operator to check if one big_int value is greater than or equal to another one.
bool big_int::operator>=(big_int &rhs) {
    if (*this > rhs || *this == rhs)
        return true;
    return false;
}

// Overload the assignment operator (=) to assign one value of big_int to another big_int object.
big_int& big_int::operator=(const big_int &rhs) {
    // Assign the rhs value to the original object
    value = rhs.value;
    return *this;
}


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

// Overload the compound addition operator (+=):
big_int& big_int::operator+=(big_int &rhs){
    // First, let's define temporary variables temp_val and temp_rhs
    // We need to convert the original big_ints to absolute values to facilitate digit by digit addition.
    // But conditions for addition depend on the sign of the original big_ints.
    // So temporary variables are required to prevent the sum of two big_ints from always being the sum of the absolute value of the big_ints.

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

    // Initialize a variable to keep track of the difference of two digits at each iteration of the for loop.
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
        if (*this >= -rhs) {
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

// Overload addition operator (+):
big_int& big_int::operator+(big_int &rhs) {
    return *this += rhs;
}

// Overload compound subtraction operator (-=):
big_int &big_int::operator-=(big_int &rhs)
{
    // Add the negative of the new big_int.
    return *this += -rhs;
}

// Overload subtraction operator (-):
big_int &big_int::operator-(big_int &rhs)
{
    return *this -= rhs;
}

// Overload compound multiplication operator (*=):
big_int &big_int::operator*=(big_int &rhs)
{
    // First, let's define temporary variables temp_val and temp_rhs, as we did for addition.
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

    // Reverse the temporary strings in order to multiplication from least digit to greatest digit
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


        // We need a second for loop to multiplication by each digit column in temp_rhs
        for (size_t j = 0; j < temp_rhs.value.size(); j++) {
            digit_prod = (temp_val.value[i] - '0') * (temp_rhs.value[j] - '0') + carry_prod;

            // We must keep track of the digits that already exist.
            // If a number is already in that digit column, the product must be added to that column.
            if ((i + j) < prod_result.size()) {
                digit_prod += (prod_result[i + j] - '0');
                
                // The ones column of the digit product is then added to the existing column.
                // The tens column of the digit product is carried over to the next column.
                prod_result[i + j] = static_cast<char>(digit_prod % 10 + '0');
            }
            // If a number is not already in the digit column, it means that we are increasing the product by a factor of 10.
            // So we append the digit product to the back of the product result string.
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

    // Reverse the sum_result string, so that the sum can be read from left to right.
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

// Overload multiplication operator (*):
big_int &big_int::operator*(big_int &rhs)
{
    return *this *= rhs;
}

// Friend function to print the big_int value to an output stream.
ostream& operator<<(ostream& out, const big_int& x) {
    return out << x.value;
}