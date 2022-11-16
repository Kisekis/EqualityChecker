#ifndef EQUALITYCHECKER_SOURCE_CODE_H
#define EQUALITYCHECKER_SOURCE_CODE_H
#include <string>
#include <vector>
enum result_type{
    Preparing,
    Same,
    Equal,
    Inequal,
};
enum TYPE {
    INT,
    CHAR,
    STRING
};
struct source_code{
    std::string path;
    int id;
    bool is_cpp;
};

struct single_input_format{
    TYPE type;
    int lsize;
    int rsize;

    int ivalue;
    std::string svalue;
    char cvalue;
};

struct source_code_pair{
    source_code code1;
    source_code code2;
    result_type result;
    std::vector<single_input_format> input_formats;
    source_code_pair(source_code code1_, source_code code2_,std::vector<single_input_format> &inputs_):
            code1(code1_), code2(code2_), result(Preparing), input_formats(inputs_){}
    source_code_pair(source_code code1_, source_code code2_, result_type result_,std::vector<single_input_format> &inputs_):
            code1(code1_), code2(code2_), result(result_), input_formats(inputs_){}
};


#endif //EQUALITYCHECKER_SOURCE_CODE_H
