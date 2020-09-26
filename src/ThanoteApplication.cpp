#include "ThanoteApplication.h"
#include "MainWindow.h"

ThanoteApplication::ThanoteApplication() : 
						Gtk::Application("github.com.Pr0curo.thanote.pre_alpha")
{
  	Glib::set_application_name("Thanote");
}

Glib::RefPtr<ThanoteApplication> ThanoteApplication::create()
{
  return Glib::RefPtr<ThanoteApplication>(new ThanoteApplication());
}

void ThanoteApplication::on_quit()
{
    std::vector<Gtk::Window*> windows = get_windows();

    if (windows.size() > 0)
    {
		// iterate through all windows and hide them
		for( auto& win : windows )
        {
			win->hide();
		}
	}
}
void ThanoteApplication::on_startup()
{
  	//Call the base class's implementation:
  	Gtk::Application::on_startup();
   	add_action("beenden", sigc::mem_fun(*this, &ThanoteApplication::on_quit));

    _refBuilder = Gtk::Builder::create();

    Glib::ustring ui_info= R"(
    <interface>
        <menu id='menu-example'>
            <submenu>
                <attribute name='label' translatable='yes'>_Datei</attribute>
                <section>
                    <item>
                        <attribute name='label' translatable='yes'>Be_enden</attribute>
                        <attribute name='action'>app.beenden</attribute>
                    </item>
                 </section>
             </submenu>
        </menu>    
        
    </interface>
    )";

    try
    {
        _refBuilder->add_from_string(ui_info);
    }
    catch (const Glib::Error& ex)
    {
        std::cerr << "Building menus failed: " << ex.what();
    }

    auto object = _refBuilder->get_object("menu-example");
    auto gmenu = Glib::RefPtr<Gio::Menu>::cast_dynamic(object);

    if (!(gmenu)) 
	{
        g_warning("GMenu not found");
    }
    else
    {
        set_menubar(gmenu);
    }
}

void ThanoteApplication::on_activate()
{
  //std::cout << "debug1: " << G_STRFUNC << std::endl;
  // The application has been started, so let's show a window.
  // A real application might want to reuse this window in on_open(),
  // when asked to open a file, if no changes have been made yet.
  create_window();
}

void ThanoteApplication::create_window()
{
  	auto win = new MainWindow();

  	//Make sure that the application runs for as long this window is still open:
  	add_window(*win);

  	//Delete the window when it is hidden.
  	//That's enough for this simple example.
  	win->signal_hide().connect(sigc::bind<Gtk::Window*>(sigc::mem_fun(*this, &ThanoteApplication::on_window_hide), win));

  	win->show_all();
}

void ThanoteApplication::on_window_hide(Gtk::Window* window)
{
  	delete window;
}
