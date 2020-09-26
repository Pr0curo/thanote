// #include <gtest/gtest.h>
#include <plog/Log.h>
#include <sol/sol.hpp>

#include "MainWindow.h"

MainWindow::MainWindow()
        : m_VBox(Gtk::ORIENTATION_VERTICAL),
          m_Button_Quit("Quit"),
          m_btn_add_item("Add Item")
{
    set_title("MainWindow - Example");
    // g_set_application_name("thanote");
    set_border_width(5);
    set_default_size(400, 200);

    add(m_VBox);
    m_VBox.pack_start(m_Button_Quit, Gtk::PACK_SHRINK);
    m_VBox.pack_start(m_btn_add_item, Gtk::PACK_SHRINK);

    m_Button_Quit.signal_clicked().connect( sigc::mem_fun(*this, &MainWindow::on_button_quit) );
    m_btn_add_item.signal_clicked().connect( sigc::mem_fun(*this, &MainWindow::on_button_add_item) );

    this->show_all_children();


    _lua.open_libraries(sol::lib::base);
    _lua["position"] = Gtk::WIN_POS_CENTER;
    PLOGD << "MainWindow->set_position(" << "Gtk::WIN_POS_CENTER" << "); // (is an enum)";
    
    _lua.script(R"(
        print("Window Position ist set to '", position, "'")
    )");

    this->set_position(_lua["position"]);

    this->SetupMenu();
}

// void MainWindow::on_startup()
// {
//     // call original signal handler
//     ApplicationWindow::on_startup();
// }

void MainWindow::SetupMenu()
{
 
}


MainWindow::~MainWindow()
{
}

void MainWindow::on_button_quit()
{
    PLOGD << "[Quit button] clicked";
    hide();
}

void MainWindow::on_button_add_item()
{
    PLOGD << "[Add Item button] clicked";
    
    Gtk::MessageDialog dialog(*this, "This is an INFO MessageDialog");
    dialog.set_secondary_text("And this is the secondary text that explains things.");

    dialog.run();
}
