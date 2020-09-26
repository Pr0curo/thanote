#include <iostream>
#include <plog/Log.h>
#include <SQLiteCpp/SQLiteCpp.h>

#include "ThanoteApplication.h"

#include "pecc.h"

int main(int argc, char *argv[])
{
    std::string test;
    peccer(test);
    std::cout << test;


    plog::init(plog::debug, "thanote.log");

    PLOGD << "========================== starting thanote ==========================";
    PLOGD << "SQlite3 version " << SQLite::VERSION << " (" << SQLite::getLibVersion() << ")";
    PLOGD << "SQliteC++ version " << SQLITECPP_VERSION;
    
    auto app = ThanoteApplication::create();
    int return_code = app->run();

    PLOGD << "ending thanote";
    return return_code;
}