#ifndef EQUALITYCHECKER_CONTROLLER_H
#define EQUALITYCHECKER_CONTROLLER_H
#include "processer.h"
#include "csv_writer.h"
#include "source_code.h"
#include "source_code_reader.h"
#include <vector>
class controller {
public:
    static controller& instance();
    controller(const controller&) = delete;
    controller operator=(const controller&) = delete;
private:
    controller() = default;
    ~controller() = default;
private:
    std::string input_path;
    std::string output_path;
    std::vector<source_code_pair> data;
    std::vector<processer> processers;
private:
    void read_file();//读取程序对
    void process();//运行
    void write_csv();//写如csv
public:
    void start();
    void set_input_path(const std::string &input_path){
        this->input_path = input_path;
    };
    void set_output_path(const std::string &output_path){
        this->output_path = output_path;
    };
};


#endif //EQUALITYCHECKER_CONTROLLER_H
