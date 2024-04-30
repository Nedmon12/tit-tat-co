// #include <gtkmm/box.h>
// #include <gtkmm/button.h>
// #include <gtkmm/window.h>
#include <gtkmm.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>

class TicTac : public Gtk::Window {
  public:
    TicTac();
    ~TicTac() {}

    Gtk::Grid m_grid;

    Gtk::Box m_box;
    Gtk::Button m_1, m_2, m_3;
    Gtk::Button m_4, m_5, m_6;
    Gtk::Button m_7, m_8, m_9;
};

// TicTac::TicTac() : m_1(""), m_2("") {}

TicTac::TicTac()
    : m_1("-"), m_2("-"), m_3("-"), m_4("-"), m_5("-"), m_6("-"), m_7("-"),
      m_8("-"), m_9("-") {
    set_title("tic-tac-toe");
    // set_default(400, 400);

    m_grid.set_margin(12);
    set_child(m_grid);
    m_grid.attach(m_1, 0, 0);
    m_grid.attach(m_2, 1, 0);
    m_grid.attach(m_3, 2, 0);
    m_grid.attach(m_4, 0, 1);
    m_grid.attach(m_5, 1, 1);
    m_grid.attach(m_6, 2, 1);
    m_grid.attach(m_7, 0, 2);
    m_grid.attach(m_8, 1, 2);
    m_grid.attach(m_9, 2, 2);
}

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create("org.gtkmm.examples.base");
    return app->make_window_and_run<TicTac>(argc, argv);
}
