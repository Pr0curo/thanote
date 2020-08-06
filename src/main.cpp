#include <iostream>
#include <plog/log.h>
#include <SQLiteCpp/SQLiteCpp.h>

#include "MainWindow.h"

int main(int argc, char *argv[])
{
    plog::init(plog::debug, "log.txt");

    PLOGD << "starting thanote";
    PLOGD << "SQlite3 version " << SQLite::VERSION << " (" << SQLite::getLibVersion() << ")" << std::endl;
    PLOGD << "SQliteC++ version " << SQLITECPP_VERSION << std::endl;

    std::cout << "hello world, oder lass es, oder liebe es\n";
    
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
    int a = 17;
    a++;
    MainWindow mw;

    return app->run(mw);
}