#pragma once

#include <gtkmm.h>


class ThanoteApplication : public Gtk::Application
{
public:
    static Glib::RefPtr<ThanoteApplication> create();

protected:
    ThanoteApplication();
protected:
    //Overrides of default signal handlers:
    void on_startup() override;
    void on_activate() override;

    void on_quit();

private:
    void create_window();    
    void on_window_hide(Gtk::Window* window);

    Glib::RefPtr<Gtk::Builder> _refBuilder;

};