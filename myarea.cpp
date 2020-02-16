#include "myarea.h"
#include <iostream>

#include <cairomm/context.h>
#include <cmath>
#include "path.h"

MyArea::MyArea()
{
}

MyArea::~MyArea()
{
}

bool MyArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  // This is where we draw on the window
  Gtk::Allocation allocation = get_allocation();
  const int width = 920;
  const int height = 768;
  const int lesser = MIN(width, height);

  // coordinates for the center of the window
  int xc, yc;
  xc = width / 2;
  yc = height / 2;

  cr->set_line_width(lesser * 0.001);  // outline thickness changes
                                      // with window size

  // first draw a simple unclosed arc
  
  // cr->save();
  // cr->arc(width / 3.0, height / 4.0, lesser / 4.0, -(M_PI / 5.0), M_PI);
  // cr->close_path();   // line back to start point
  // cr->set_source_rgb(0.0, 0.8, 0.0);
  // cr->fill_preserve();
  // cr->restore();  // back to opaque black
  // cr->stroke();   // outline it

  for(int i = 0; i < intersections.size(); i++){
    for(int j = i + 1; j < intersections.size(); j++){
      if(streets[i][j].time != -1){
        cr->save();
        cr->set_source_rgba(0.0, 0.0, 0.0, 1.0);
        cr->move_to(intersections[streets[i][j].from].x, intersections[streets[i][j].from].y);
        cr->line_to(intersections[streets[i][j].to].x, intersections[streets[i][j].to].y);
        cr->restore();  // back to opaque black
        cr->stroke();
      }
    }
  }

  // now draw a circle
  for(int i = 0; i < intersections.size(); i++){
    cr->save();
    cr->stroke();
    cr->arc(intersections[i].x, intersections[i].y, lesser / 100.0, 0.0, 2.0 * M_PI); // full circle
    
    
    if(intersections[i].isVisited){
      cr->set_source_rgba(0.0, 0.0, 0.0, 0.8);
    }else if(intersections[i].isInQueue){
      cr->set_source_rgba(0.6, 0.0, 0.0, 0.8);
    }else if(intersections[i].isDest){
      cr->set_source_rgba(0.0, 0.6, 0.0, 1);
    }else if(intersections[i].isSrc){
      cr->set_source_rgba(1.0, 0.0, 0.0, 1);
    }else{
      cr->set_source_rgba(0.0, 0.0, 0.6, 0.8);
    }
    cr->fill_preserve();
    cr->restore();  // back to opaque black
    // cr->stroke();

    // draw text
    cr->set_source_rgb(0.0, 0.0, 0.0);

    int text_width;
    int text_height;

    auto layout = create_pango_layout(std::to_string(intersections[i].time) + "\t" + std::to_string(i));
    if(intersections[i].time == INT32_MAX){
        layout = create_pango_layout("-1\t" + std::to_string(i));
    }
    layout->get_pixel_size(text_width, text_height);
    cr->move_to(intersections[i].x - text_width/2, intersections[i].y - 2 * text_height);
    layout->show_in_cairo_context(cr);

    // cr->restore();
  }

  // draw red lines out from the center of the window
  
  

  // and finally an ellipse
  // double ex, ey, ew, eh;
  // // center of ellipse
  // ex = xc;
  // ey = 3.0 * height / 4.0;
  // // ellipse dimensions
  // ew = 3.0 * width / 4.0;
  // eh = height / 3.0;

  // cr->save();

  // cr->translate(ex, ey);  // make (ex, ey) == (0, 0)
  // cr->scale(ew / 2.0, eh / 2.0);  // for width: ew / 2.0 == 1.0
  //                                 // for height: eh / 2.0 == 1.0

  // cr->arc(0.0, 0.0, 1.0, 0.0, 2 * M_PI);  // 'circle' centered at (0, 0)
  //                                         // with 'radius' of 1.0

  // cr->set_source_rgba(0.8, 0.0, 0.0, 0.7);
  // cr->fill_preserve();
  // cr->restore();  // back to opaque black
  // cr->stroke();

  return true;
}