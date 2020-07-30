#include <iostream>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    std::cout << "hello world\n";
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    MainWindow mw;


    return app->run(mw);
}