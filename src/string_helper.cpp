#include <string>

/**
 * @brief Class for manipulating strings.
 * 
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