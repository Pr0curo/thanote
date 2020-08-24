#include <iostream>
#include <plog/Log.h>
#include <SQLiteCpp/SQLiteCpp.h>

#include "MainWindow.h"

int main(int argc, char *argv[])
{
    plog::init(plog::debug, "thanote.log");

    PLOGD << "========================== starting thanote ==========================";
    PLOGD << "SQlite3 version " << SQLite::VERSION << " (" << SQLite::getLibVersion() << ")";
    PLOGD << "SQliteC++ version " << SQLITECPP_VERSION;
    
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
    MainWindow mw;
    int return_code = app->run(mw);

    int x = 17;

    PLOGD << "ending thanote";
    return return_code;
}