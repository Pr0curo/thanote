#include <iostream>
#include "MainWindow.h"

#include <SQLiteCpp/SQLiteCpp.h>


int main(int argc, char *argv[])
{
    std::cout << "hello world\n";
    std::cout << "SQlite3 version " << SQLite::VERSION << " (" << SQLite::getLibVersion() << ")" << std::endl;
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    MainWindow mw;

    return app->run(mw);
}