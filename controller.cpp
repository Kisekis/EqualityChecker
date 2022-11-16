#include "controller.h"

controller& controller::instance() {
    static controller instance;
    return instance;
}

void controller::read_file() {
    source_code_reader reader(this->input_path);
    reader.read(this->data);
}

void controller::process() {
    for(auto& x : this->data) {
        processer p(&x);
        p.process();
    }
}

void controller::write_csv() {
    csv_writer writer(this->output_path,data);
    writer.write();
}

void controller::start() {
    read_file();
    process();
    write_csv();
};