#include <iostream>
#include "MainWindow.h"

#include <SQLiteCpp/SQLiteCpp.h>


int main(int argc, char *argv[])
{
    std::cout << "hello world, oder lass es, oder liebe es\n";
    std::cout << "SQlite3 version " << SQLite::VERSION << " (" << SQLite::getLibVersion() << ")" << std::endl;
    std::cout << "SQliteC++ version " << SQLITECPP_VERSION << std::endl;
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
    int a = 17;
    a++;
    MainWindow mw;

    return app->run(mw);
}