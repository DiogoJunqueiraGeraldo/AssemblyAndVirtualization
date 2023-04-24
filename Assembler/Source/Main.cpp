#include <iostream>

#include "Application/Application.h"

int main(int argc, char* argv[])
{
    auto app = Assembler::Application(argc, argv);

    app.Assemble();

    return EXIT_SUCCESS;
}