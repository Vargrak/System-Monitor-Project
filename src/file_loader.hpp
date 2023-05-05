#pragma once
#ifndef FILE_LOADER_HPP
#define FILE_LOADER_HPP

#include <fstream>
#include <string>
#include <vector>

/**
 * @brief Utility class for loading a text file into a vector of strings.
 * @author Lilith Ernst
 * @version 4-17-23
 * 
 */
class file_loader {
    private:

        //File stored in class for working with.
        std::vector<std::string> loaded_file;

    public:

        /**
         * @brief Loads a file into a vector of strings. Static version that does not store the vector in
         * this class.
         * 
         * @param file_select File to load, stores each newline as a separate string.
         * @return std::vector<std::string> 
         */
        static std::vector<std::string> load_file(std::string file_select);

        /**
         * @brief Loads a file into a vector of strings. Static version that does not store the vector
         * in this class. Overload to set a delimiter for the file.
         * 
         * @param file_select File to load
         * @param delimiter Char to split the file on
         * @return std::vector<std::string> 
         */
        static std::vector<std::string> load_file(std::string file_select, char delimiter);

        /**
         * @brief Non-static version of load_file for loading a text file into a vector
         * of strings. Stores the vector in the class for later access.
         * 
         * @param file_select 
         * @return std::vector<std::string> 
         */
        std::vector<std::string> load_file_store(std::string file_select);

        /**
         * @brief Get the loaded file as a vector again.
         * 
         * @return std::vector<std::string> 
         */
        std::vector<std::string> get_loaded_file();

        /**
         * @brief Clears the vector storing the loaded file
         * 
         */
        void clear_loaded_file();
};

#endif
