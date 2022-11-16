#include "csv_writer.h"
#include <iostream>
#include <fstream>


static std::string to_string(const source_code_pair& entry) {
    return entry.code1.path+','+entry.code2.path+ ",\n";
}

void csv_writer::write() {
    std::ofstream equal;
    equal.open (output_path + "equal.csv");
    std::ofstream inequal;
    inequal.open(output_path + "inequal.csv");
    std::ofstream same;
    same.open(output_path + "same.csv");
    
    equal<<"file1,file2,\n";
    inequal<<"file1,file2,\n";
    same<< "file1,file2,\n";
    for(auto& entry : data) {
        switch (entry.result) {
            case Same:
                same<< to_string(entry);
                break;
            case Equal:
                equal<<to_string(entry);
                break;
            case Inequal:
                inequal<<to_string(entry);
                break;
            case Preparing:
                break;
        }
    }
    equal.close();
    inequal.close();
    same.close();
}
