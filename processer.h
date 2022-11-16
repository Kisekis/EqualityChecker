#ifndef EQUALITYCHECKER_PROCESSER_H
#define EQUALITYCHECKER_PROCESSER_H
#include "source_code.h"

class processer {
private:
    enum {rounds = 5};
    source_code_pair* data;
public:
    explicit processer(source_code_pair* data_):data(data_){};
    void process();
    void create_input_file();
    void create_compiled_file(const std::string &path1, const std::string &path2);
    void create_output_file(const std::string &path1, const std::string &path2);
    void clear(const std::string &path1, const std::string &path2);
};


#endif //EQUALITYCHECKER_PROCESSER_H
