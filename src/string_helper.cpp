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
    static std::string remove_whitespace(std::string str) {
        std::string formatted_string = "";

        for (char c : str) {
            if (!is_space(c)) {
                formatted_string += c;
            }
        }

        return formatted_string;
    }

    /**
     * @brief Splits a string into a vector of strings.
     * 
     * @param str The string to split.
     * @param delimiter The character to split the string by.
     * @return std::vector<std::string> The vector of strings.
     */
    static std::vector<std::string> split_string(std::string str, char delimiter) {
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

    private:

    /**
     * @brief Checks if a character is whitespace.
     * 
     * @param c The character to check.
     * @return true If the character is whitespace.
     * @return false If the character is not whitespace.
     */
    static bool is_space(char c) {
        return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v';
    }
};