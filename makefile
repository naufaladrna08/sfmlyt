obj := main.o Character.o

%.o: %.cpp
	g++ -c $^ -o $@ -I.

game: $(obj)
	g++ -o $@ $^ -lsfml-window -lsfml-graphics -lsfml-system
