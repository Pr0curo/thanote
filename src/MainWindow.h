#pragma once
#include <gtkmm.h>


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wincompatible-ms-struct"
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

};
#pragma clang diagnostic pop