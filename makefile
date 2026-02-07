win-mingw:
	g++ src/*.cpp -o main.exe -Iinclude -Ilib/SFML-3.0.2/include -Llib/SFML-3.0.2/lib -lsfml-window -lsfml-graphics -lsfml-system -std=c++17 -w

win-mingw-production:
	g++ src/*.cpp -o main.exe -Iinclude -Ilib/SFML-3.0.2/include -Llib/SFML-3.0.2/lib -lsfml-window -lsfml-graphics -lsfml-system -std=c++17 -w -mwindows

mac:
	g++ src/*.cpp -o main.out -Iinclude -Ilib/SFML-3.0.2/include -Llib/SFML-3.0.2/lib -Wl,-rpath,lib/SFML-3.0.2/lib -lsfml-window -lsfml-graphics -lsfml-system -std=c++17 -w