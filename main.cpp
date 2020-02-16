#include <iostream>
#include <stdlib.h>
#include <string>

#include "myarea.h"
#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/grid.h>

#include "pathMain.h"

MyArea* globalArea;

void on_button1_clicked()
{
   initializeDijkstra();
   DijkstraStart(0, 9);
   (*globalArea).queue_draw();
}

void on_button2_clicked()
{
   std::cout << "Hello World" << std::endl;
   oneStepDijkstra();
   (*globalArea).queue_draw();
}

int main(int argc, char** argv)
{
   initializedataStructure();
   auto app = Gtk::Application::create(argc, argv, "siwei");

   Gtk::Window win;
   win.resize(1024,768);
   win.set_title("DrawingArea");

   Gtk::Grid m_Grid;
   win.add(m_Grid);
   m_Grid.set_size_request(1024, 768);
   m_Grid.set_row_homogeneous(true);
   m_Grid.set_column_homogeneous(true);

   // Create a drawing area
   MyArea area;
   globalArea = &area;
   // m_Grid.add(area);

   // Create a new button
   Gtk::Button *button1 = new Gtk::Button("Init Dijkstra", "Run once");
   button1->signal_clicked().connect(sigc::ptr_fun(&on_button1_clicked));
   Gtk::Button *button2 = new Gtk::Button("OneStep", "Run once");
   button2->signal_clicked().connect(sigc::ptr_fun(&on_button2_clicked));
   // m_Grid.add(*button);

   m_Grid.attach(area, 0, 0, 9, 9);
   m_Grid.attach(*button1, 9, 0, 1, 1);
   m_Grid.attach(*button2, 9, 1, 1, 1);

   m_Grid.show();
   area.show();
   button1->show();
   button2->show();
   // win.show_all_children();
   return app->run(win);
}