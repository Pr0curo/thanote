#pragma once
#include <gtkmm.h>
#include <sol/sol.hpp>

class MainWindow : public Gtk::Window
{
public:
    MainWindow();
    virtual ~MainWindow();

protected:
    //Signal handlers:
    void on_button_quit();
    
    //Child widgets:
    Gtk::Box m_VBox;
    Gtk::Button m_Button_Quit;

    sol::state _lua;

};