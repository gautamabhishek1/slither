slither: main.cpp food.cpp game.cpp snake.cpp ui.cpp constants.h
	g++ main.cpp food.cpp game.cpp snake.cpp ui.cpp -lncursesw -o slither && ./slither

clean: 
	rm -f ./slither