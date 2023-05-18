#pragma once
#ifndef STRING_HELPER_HPP
#define STRING_HELPER_HPP

#include <string>
#include <vector>

/**
 * @brief Class for manipulating strings.
 * @author Lilith Ernst
 * @version 4-27-23
 */
class string_helper {
    public:

    /**
     * @brief Removes all whitespace from a string.
     * 
     * @param str The string to remove whitespace from.
     * @return std::string The string without whitespace.
     */
    static std::string remove_whitespace(std::string str);

    /**
     * @brief Splits a string into a vector of strings,
     * takes a delimiter to split the string by.
     * 
     * @param str The string to split.
     * @param delimiter The character to split the string by.
     * @return std::vector<std::string> The vector of strings.
     */
    static std::vector<std::string> split_string(std::string str, char delimiter);

    /**
     * @brief Splits a string into a vector of strings,
     * defaults to splitting by whitespace.
     * 
     * @param str The string to split.
     * @return std::vector<std::string> The vector of strings. 
     */
    static std::vector<std::string> split_string(std::string str);

    /**
     * @brief Removes all empty strings from a vector of strings.
     * 
     * @param str The vector of strings to remove empty strings from.
     * @return std::vector<std::string> The vector of strings without empty strings.
     */
    static std::vector<std::string> remove_empty_strings(std::vector<std::string> str);

    private:

    /**
     * @brief Checks if a character is whitespace.
     * 
     * @param c The character to check.
     * @return true If the character is whitespace.
     * @return false If the character is not whitespace.
     */
    static bool is_space(char c);
};

#endif