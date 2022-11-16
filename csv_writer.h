#ifndef EQUALITYCHECKER_CSV_WRITER_H
#define EQUALITYCHECKER_CSV_WRITER_H
#include <string>
#include <vector>
#include "source_code.h"
class csv_writer {
private:
    std::string output_path;
    const std::vector<source_code_pair>& data;
public:
    csv_writer(std::string output_path_,const std::vector<source_code_pair>& data_) :
    output_path(output_path_),data(data_){}

    void write();

    const std::string &getOutputPath() const {
        return output_path;
    }
    void setOutputPath(const std::string &outputPath) {
        output_path = outputPath;
    }
};


#endif //EQUALITYCHECKER_CSV_WRITER_H
