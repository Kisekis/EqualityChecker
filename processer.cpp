#include "processer.h"
#include <random>
#include <fstream>
#include <iostream>

int processer::random_int(int a, int b)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(a, b);
    return dist(rng);
}
char processer::random_char()
{
    int offset = random_int(0, 25);
    int type = random_int(0, 1);
    return type == 0 ? char('a' + offset) : char('A' + offset);
}
std::string processer::random_string(int a, int b)
{
    int size = random_int(a, b);
    std::string s;
    while (size--)
    {
        s += random_char();
    }
    return s;
}

void processer::generate_random_input(std::vector<single_input_format> &input)
{
    for (auto &x : input)
    {
        switch (x.type)
        {
        case INT:
            x.ivalue = random_int(x.lsize, x.rsize);
            break;
        case CHAR:
            x.cvalue = random_char();
            break;
        case STRING:
            x.svalue = random_string(x.lsize, x.rsize);
            break;
        }
    }
}
bool processer::is_same_file(const std::string &path1, const std::string &path2)
{
    std::string cmd = "diff " + path1 + " " + path2;
    int result = system(cmd.c_str());
    if (result != 0)
    {
        return false;
    }
    return true;
}
void processer::process()
{
    std::string path1 = data->code1.path;
    std::string path2 = data->code2.path;
    if (is_same_file(path1, path2))
    {
        data->result = Same;
        return;
    }
    for (int i = 0; i < rounds; i++)
    {
        create_input_file();
        create_compiled_file(path1, path2);
        create_output_file(path1, path2);
        if (!is_same_file(path1 + ".output", path2 + ".output"))
        {
            data->result = Inequal;
            clear(path1, path2);
            return;
        }
        std::string rm_output1 = "rm " + path1 + ".output";
        std::string rm_output2 = "rm " + path2 + ".output";
        system(rm_output1.c_str());
        system(rm_output2.c_str());
    }
    data->result = Equal;
    clear(path1, path2);
}

void processer::clear(const std::string &path1, const std::string &path2)
{
    std::string rm1 = "rm " + path1 + ".out";
    std::string rm2 = "rm " + path2 + ".out";
    std::string rm3 = "rm " + path1 + ".output";
    std::string rm4 = "rm " + path2 + ".output";
    std::string rm_input = "rm data.input";
    
    system(rm1.c_str());
    system(rm2.c_str());
    system(rm3.c_str());
    system(rm4.c_str());
    system(rm_input.c_str());
}

void processer::create_input_file() {
    generate_random_input(data->input_formats);
    std::string rm_input = "rm data.input";
    system(rm_input.c_str());
    std::ofstream input;
    input.open("data.input");
    for (const auto &x : data->input_formats)
    {
        switch (x.type)
        {
        case INT:
            input << x.ivalue << ' ';
            break;
        case STRING:
            input << x.svalue << ' ';
            break;
        case CHAR:
            input << x.cvalue << ' ';
            break;
        }
    }
    input.close();
}
void processer::create_compiled_file(const std::string &path1, const std::string &path2)
{
    std::string compile1;
    if (data->code1.is_cpp)
    {
        compile1 = "g++ ";
    }
    else
    {
        compile1 = "gcc ";
    }
    compile1 += "-o " + path1 + ".out " + path1;
    system(compile1.c_str());

    std::string compile2;
    if (data->code2.is_cpp)
    {
        compile2 = "g++";
    }
    else
    {
        compile2 = "gcc";
    }
    compile2 += " -o " + path2 + ".out " + path2;
    system(compile2.c_str());
}

void processer::create_output_file(const std::string &path1, const std::string &path2) {
    std::string execute1 = "./" + path1 + ".out " + "<data.input> " + path1 + ".output";
    system(execute1.c_str());
    std::string execute2 = "./" + path2 + ".out " + "<data.input> " + path2 + ".output";
    system(execute2.c_str());
}
