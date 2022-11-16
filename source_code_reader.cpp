#include "source_code_reader.h"
#include <filesystem>
#include <fstream>
#include <iostream>
namespace fs = std::filesystem;

void source_code_reader::read(std::vector<source_code_pair> &data) {
    std::vector<source_code> raw_data;
    std::string format;
    for (const auto & entry : fs::directory_iterator(folder_path)) {
        auto ext = entry.path().extension().string();
        if (ext == ".cpp") {
            raw_data.push_back({entry.path().string(),count,true});
            count++;
        }else if(ext == ".c") {
            raw_data.push_back({entry.path().string(),count,false});
            count++;
        }else if(ext == ".txt") {
            format = entry.path().string();
        }
    }
    auto input = parse_input_format(format);
    for(int i = 0;i<count-1;i++) {
        for(int j =i+1;j<count;j++) {
            data.emplace_back(raw_data[i],raw_data[j],Preparing,input);
        }
    }
}
single_input_format source_code_reader::parse_single_input_format(std::string input) {
    if(input == "char") {
        return {CHAR};
    }else {
        auto pos = input.find('(');
        auto type = input.substr(0,pos);
        auto pos_c = input.find(',');
        auto left = std::stoi(input.substr(pos+1,pos_c-pos-1));
        auto right = std::stoi(input.substr(pos_c+1,input.size()-1-pos_c));
        if(type == "int") {
            return {INT,left,right};
        }else if(type == "string") {
            return {STRING,left,right};
        }else {
            std::cerr << "Error: Input format wrong" << std::endl;
            exit(1);
        }
    }
}


std::vector<single_input_format> source_code_reader::parse_input_format(const std::string &format_path) {
    std::ifstream format;
    format.open(format_path);
    if(!format) {
        std::cerr << "Error: file could not be opened" << std::endl;
        exit(1);
    }
    std::stringstream ss;
    ss << format.rdbuf();
    std::vector<std::string> tokens;
    std::string buf;
    while (ss >> buf) {
        tokens.push_back(buf);
    }
    std::vector<single_input_format> ret;
    for(const auto &x : tokens) {
        ret.push_back(parse_single_input_format(x));
    }
    return ret;
}

