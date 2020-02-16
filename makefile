make:
	g++ -std=c++11 path.cpp pathMain.cpp myarea.cpp main.cpp -o DijkstraDemo `pkg-config gtkmm-3.0 --cflags --libs`