#ifndef EQUALITYCHECKER_PROCESSER_H
#define EQUALITYCHECKER_PROCESSER_H
#include "source_code.h"

class processer {
private:
    enum {rounds = 5};//轮数
    source_code_pair* data;
public:
    explicit processer(source_code_pair* data_):data(data_){};
    void process();

    void create_input_file();//创建程序输入
    void create_compiled_file(const std::string &path1, const std::string &path2);//编译程序
    void create_output_file(const std::string &path1, const std::string &path2);//运行得到程序输出
    void clear(const std::string &path1, const std::string &path2);//清除中间文件

    static void generate_random_input(std::vector<single_input_format> &input);//用于生成特定格式的输入
    static std::string processer::random_string(int a, int b);
    static char random_char();
    static int random_int(int a, int b);

    static bool is_same_file(const std::string &path1, const std::string &path2);//用于判断程序是否相同
};


#endif //EQUALITYCHECKER_PROCESSER_H
