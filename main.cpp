#include <iostream>
#include "controller.h"
int main(int argc, char **argv)
{
    controller& c = controller::instance();
    if (argc != 3)
    {
        std::cerr << "Wrong input" << std::endl;
        return -1;
    }
    char *input_path = argv[1];
    char *output_path = argv[2];
    c.set_input_path(input_path);
    c.set_output_path(output_path);
    c.start();
}
