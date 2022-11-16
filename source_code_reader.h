#ifndef EQUALITYCHECKER_SOURCE_CODE_READER_H
#define EQUALITYCHECKER_SOURCE_CODE_READER_H
#include <string>
#include <vector>
#include "source_code.h"
class source_code_reader {
private:
    std::string folder_path;
    int count;
public:
    explicit source_code_reader(std::string folder_path_) : folder_path(folder_path_), count(0){}
    void read(std::vector<source_code_pair>& data);
    const std::string &getFolderPath() const {//getter
        return folder_path;
    }
    void setFolderPath(const std::string &folderPath) {//setter
        folder_path = folderPath;
    }
    static single_input_format parse_single_input_format(std::string input);
    static std::vector<single_input_format> parse_input_format(const std::string& format_path);
};


#endif //EQUALITYCHECKER_SOURCE_CODE_READER_H
