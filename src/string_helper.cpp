
#include "string_helper.hpp"

/**
 * @brief Class for manipulating strings.
 * @author Lilith Ernst
 * @version 4-27-23
 */


/**
 * @brief Removes all whitespace from a string.
 * 
 * @param str The string to remove whitespace from.
 * @return std::string The string without whitespace.
 */
std::string string_helper::remove_whitespace(std::string str) {
    std::string formatted_string = "";

    for (char c : str) {
        if (!is_space(c)) {
            formatted_string += c;
        }
    }

    return formatted_string;
}

/**
 * @brief Splits a string into a vector of strings,
 * takes a delimiter to split the string by.
 * 
 * @param str The string to split.
 * @param delimiter The character to split the string by.
 * @return std::vector<std::string> The vector of strings.
 */
std::vector<std::string> string_helper::split_string(std::string str, char delimiter) {
    std::vector<std::string> split_string;
    std::string current_string = "";

    for (char c : str) {
        if (c == delimiter) {
            split_string.push_back(current_string);
            current_string = "";

        } else {
            current_string += c;
        }
    }

    split_string.push_back(current_string);
    return split_string;
}

/**
 * @brief Splits a string into a vector of strings,
 * defaults to splitting by whitespace.
 * 
 * @param str The string to split.
 * @return std::vector<std::string> The vector of strings. 
 */
std::vector<std::string> string_helper::split_string(std::string str) {
    std::vector<std::string> split_string;
    std::string current_string = "";

    for (char c : str) {
        if (is_space(c)) {
            split_string.push_back(current_string);
            current_string = "";

        } else {
            current_string += c;
        }
    }

    split_string.push_back(current_string);
    return split_string;
}


/**
 * @brief Checks if a character is whitespace.
 * 
 * @param c The character to check.
 * @return true If the character is whitespace.
 * @return false If the character is not whitespace.
 */
bool string_helper::is_space(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v';
}
