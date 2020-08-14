// #include <gtest/gtest.h>
#include <plog/Log.h>
#include <sol/sol.hpp>

#include "MainWindow.h"

MainWindow::MainWindow()
        : m_VBox(Gtk::ORIENTATION_VERTICAL),
          m_Button_Quit("Quit"),
          m_Menu(nullptr)
{
    set_title("MainWindow - Example");
    set_border_width(5);
    set_default_size(400, 200);

    add(m_VBox);
    m_VBox.pack_start(m_Button_Quit, Gtk::PACK_SHRINK);

    m_Button_Quit.signal_clicked().connect( sigc::mem_fun(*this, &MainWindow::on_button_quit) );

    this->show_all_children();

    this->set_position(Gtk::WIN_POS_CENTER);

    _lua.open_libraries(sol::lib::base);
    _lua["position"] = Gtk::WIN_POS_CENTER;

    _lua.script(R"(
        print("Window Position ist set to '", position, "'")
    )");

    auto action_group = Gio::SimpleActionGroup::create();
    action_group->add_action("ende", sigc::mem_fun(*this, &MainWindow::on_button_quit));

    insert_action_group("examplepopup", action_group);

}



MainWindow::~MainWindow()
{
}

void MainWindow::on_button_quit()
{
    PLOGD << "Quit button clicked";
    hide();
}


