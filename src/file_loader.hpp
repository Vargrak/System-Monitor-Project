#ifndef file_loader_hpp
#define file_loader_hpp

#include <fstream>
#include <string>
#include <vector>

class file_loader
{
    public:
        std::vector<std::string> load_file(std::string file_select);
        std::vector<std::string> load_file_store(std::string file_select);
        std::vector<std::string> get_loaded_file();
        void clear_loaded_file();
};

#endif 