FLAGS=-std=c++11 -Wall -Wextra -Wpedantic
DESTDIR=$
CCP=g++

prog: main.o packagemanager.o utils.o
	$(CCP) $(FLAGS) -o build/nvs build/main.o build/packagemanager.o build/utils.o

main.o: src/main.cpp
	mkdir -p build
	$(CCP) $(FLAGS) -c src/main.cpp -o build/main.o

packagemanager.o: src/packagemanager.hpp src/packagemanager.cpp
	mkdir -p build
	$(CCP) $(FLAGS) -c src/packagemanager.cpp -o build/packagemanager.o

utils.o: src/utils.hpp src/utils.cpp
	mkdir -p build
	$(CCP) $(FLAGS) -c src/utils.cpp -o build/utils.o

install:
	mkdir -p $(DESTDIR)/usr/local/bin/
	cp build/nvs $(DESTDIR)/usr/local/bin/
	mkdir -p $(DESTDIR)/usr/local/etc/nvs
	mkdir -p $(DESTDIR)/usr/local/etc/bash_completion.d/nvs
	cp contrib/nvs.bash-completion $(DESTDIR)/usr/local/etc/bash_completion.d/nvs

clean:
	rm -rf build
