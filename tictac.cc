// #include <gtkmm/box.h>
// #include <gtkmm/button.h>
// #include <gtkmm/window.h>
#include "glibmm/ustring.h"
#include "gtkmm/enums.h"
#include "sigc++/functors/mem_fun.h"
#include <cstdint>
#include <gtkmm.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <iostream>

class TicTac : public Gtk::Window {
  public:
    TicTac();
    ~TicTac() {}

    Gtk::Grid m_grid;

    Gtk::Box m_box;
    Gtk::Button m_1, m_2, m_3;
    Gtk::Button m_4, m_5, m_6;
    Gtk::Button m_7, m_8, m_9;

    Gtk::Label status;

    sigc::connection m1_conn;
    sigc::connection m2_conn;
    sigc::connection m3_conn;
    sigc::connection m4_conn;
    sigc::connection m5_conn;
    sigc::connection m6_conn;
    sigc::connection m7_conn;
    sigc::connection m8_conn;
    sigc::connection m9_conn;

    uint8_t counter;

    std::vector<int> xbuffer;
    std::vector<int> obuffer;
    void reinit() {
        m1_conn = m_1.signal_clicked().connect(
            sigc::bind(sigc::mem_fun(*this, &TicTac::button_action), 1));
        m2_conn = m_2.signal_clicked().connect(
            sigc::bind(sigc::mem_fun(*this, &TicTac::button_action), 2));

        m3_conn = m_3.signal_clicked().connect(
            sigc::bind(sigc::mem_fun(*this, &TicTac::button_action), 3));

        m4_conn = m_4.signal_clicked().connect(
            sigc::bind(sigc::mem_fun(*this, &TicTac::button_action), 4));
        m5_conn = m_5.signal_clicked().connect(
            sigc::bind(sigc::mem_fun(*this, &TicTac::button_action), 5));

        m6_conn = m_6.signal_clicked().connect(
            sigc::bind(sigc::mem_fun(*this, &TicTac::button_action), 6));
        m7_conn = m_7.signal_clicked().connect(
            sigc::bind(sigc::mem_fun(*this, &TicTac::button_action), 7));
        m8_conn = m_8.signal_clicked().connect(
            sigc::bind(sigc::mem_fun(*this, &TicTac::button_action), 8));
        m9_conn = m_9.signal_clicked().connect(
            sigc::bind(sigc::mem_fun(*this, &TicTac::button_action), 9));

        m_1.set_label("-");
        m_2.set_label("-");
        m_3.set_label("-");
        m_4.set_label("-");
        m_5.set_label("-");
        m_6.set_label("-");
        m_7.set_label("-");
        m_8.set_label("-");
        m_9.set_label("-");
    }
    void button_action(uint8_t button) {
        Glib::ustring turn;
        if (counter % 2 == 0) {
            turn = "X";
            counter++;
            xbuffer.push_back(button);
        } else {
            turn = "O";
            obuffer.push_back(button);
            counter++;
        }
        switch (button) {
        case 1:
            m_1.set_label(turn);
            if (m_2.get_label() == turn && m_3.get_label() == turn) {
                // std::cout << turn << "won";
                status.set_label(turn + " won");
                reinit();
            }
            if (m_4.get_label() == turn && m_7.get_label() == turn) {
                // std::cout << turn << "won";
                status.set_label(turn + " won");
                reinit();
            }
            if (m_5.get_label() == turn && m_9.get_label() == turn) {
                status.set_label(turn + " won");
                reinit();
            }

            m1_conn.disconnect();
            break;
        case 2:
            m_2.set_label(turn);
            if (m_1.get_label() == turn && m_3.get_label() == turn) {
                status.set_label(turn + " won");
                reinit();
            }
            if (m_5.get_label() == turn && m_8.get_label() == turn) {
                status.set_label(turn + " won");
                reinit();
            }
            m2_conn.disconnect();
            break;
        case 3:
            m_3.set_label(turn);
            if (m_2.get_label() == turn && m_1.get_label() == turn) {
                status.set_label(turn + " won");
                reinit();
            }
            if (m_6.get_label() == turn && m_9.get_label() == turn) {

                status.set_label(turn + " won");
                reinit();
            }
            if (m_5.get_label() == turn && m_7.get_label() == turn) {

                status.set_label(turn + " won");
                reinit();
            }
            m3_conn.disconnect();
            break;
        case 4:
            m_4.set_label(turn);
            if (m_1.get_label() == turn && m_7.get_label() == turn) {
                status.set_label(turn + " won");
                reinit();
            }
            if (m_5.get_label() == turn && m_6.get_label() == turn) {
                status.set_label(turn + " won");
                reinit();
            }
            m4_conn.disconnect();
            break;
        case 5:
            m_5.set_label(turn);
            if (m_1.get_label() == turn && m_9.get_label() == turn) {
                status.set_label(turn + " won");
                reinit();
            }
            if (m_2.get_label() == turn && m_8.get_label() == turn) {
                status.set_label(turn + " won");
                reinit();
            }
            if (m_3.get_label() == turn && m_7.get_label() == turn) {
                status.set_label(turn + " won");
                reinit();
            }
            if (m_4.get_label() == turn && m_6.get_label() == turn) {
                status.set_label(turn + " won");
                reinit();
            }
            m5_conn.disconnect();
            break;
        case 6:
            m_6.set_label(turn);
            if (m_4.get_label() == turn && m_5.get_label() == turn) {
                status.set_label(turn + " won");
                reinit();
            }
            if (m_3.get_label() == turn && m_9.get_label() == turn) {
                status.set_label(turn + " won");
                reinit();
            }
            m6_conn.disconnect();
            break;
        case 7:
            m_7.set_label(turn);
            if (m_1.get_label() == turn && m_7.get_label() == turn) {
                status.set_label(turn + " won");
                reinit();
            }
            if (m_8.get_label() == turn && m_9.get_label() == turn) {
                status.set_label(turn + " won");
                reinit();
            }
            if (m_3.get_label() == turn && m_5.get_label() == turn) {
                status.set_label(turn + " won");
                reinit();
            }
            m7_conn.disconnect();
            break;
        case 8:
            m_8.set_label(turn);
            if (m_2.get_label() == turn && m_5.get_label() == turn) {
                status.set_label(turn + " won");
                reinit();
            }
            if (m_7.get_label() == turn && m_9.get_label() == turn) {
                status.set_label(turn + " won");
                reinit();
            }
            m8_conn.disconnect();
            break;
        case 9:
            m_9.set_label(turn);
            if (m_3.get_label() == turn && m_6.get_label() == turn) {
                status.set_label(turn + " won");
                reinit();
            }
            if (m_7.get_label() == turn && m_8.get_label() == turn) {
                status.set_label(turn + " won");
                reinit();
            }
            if (m_1.get_label() == turn && m_5.get_label() == turn) {
                status.set_label(turn + " won");
                reinit();
            }
            m9_conn.disconnect();
            break;
        }
    }
};

// TicTac::TicTac() : m_1(""), m_2("") {}

TicTac::TicTac()
    : m_1("-"), m_2("-"), m_3("-"), m_4("-"), m_5("-"), m_6("-"), m_7("-"),
      m_8("-"), m_9("-"), status("in progress") {
    counter = 0;
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
    m_grid.attach_next_to(status, m_8, Gtk::PositionType::BOTTOM, 3, 1);

    m1_conn = m_1.signal_clicked().connect(
        sigc::bind(sigc::mem_fun(*this, &TicTac::button_action), 1));
    m2_conn = m_2.signal_clicked().connect(
        sigc::bind(sigc::mem_fun(*this, &TicTac::button_action), 2));

    m3_conn = m_3.signal_clicked().connect(
        sigc::bind(sigc::mem_fun(*this, &TicTac::button_action), 3));

    m4_conn = m_4.signal_clicked().connect(
        sigc::bind(sigc::mem_fun(*this, &TicTac::button_action), 4));
    m5_conn = m_5.signal_clicked().connect(
        sigc::bind(sigc::mem_fun(*this, &TicTac::button_action), 5));

    m6_conn = m_6.signal_clicked().connect(
        sigc::bind(sigc::mem_fun(*this, &TicTac::button_action), 6));
    m7_conn = m_7.signal_clicked().connect(
        sigc::bind(sigc::mem_fun(*this, &TicTac::button_action), 7));
    m8_conn = m_8.signal_clicked().connect(
        sigc::bind(sigc::mem_fun(*this, &TicTac::button_action), 8));
    m9_conn = m_9.signal_clicked().connect(
        sigc::bind(sigc::mem_fun(*this, &TicTac::button_action), 9));

    // m_9.signal_clicked().connect(sigc::mem_fun(*this,
    // &TicTac::button_action));
}

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create("org.gtkmm.examples.base");
    return app->make_window_and_run<TicTac>(argc, argv);
}
