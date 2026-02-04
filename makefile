win-mingw:
	g++ src/*.cpp -o main.exe -Iinclude -Ilib/SFML-3.0.2/include -Llib/SFML-3.0.2/lib -lsfml-window -lsfml-graphics -lsfml-system -std=c++17 -w -mwindows