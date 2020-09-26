#pragma once
#include <gtkmm.h>
#include <sol/sol.hpp>



class MainWindow : public Gtk::ApplicationWindow
{
public:
    MainWindow();
    virtual ~MainWindow();

protected:
    //Signal handlers:
    void on_button_quit();
    void on_button_add_item();

    //Child widgets:
    Gtk::Box m_VBox;
    Gtk::Button m_Button_Quit;
    Gtk::Button m_btn_add_item;

    sol::state _lua;

};