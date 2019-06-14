FLAGS=-std=c++11 -Wall -Wextra -Wpedantic
DESTDIR=$
CCP=g++

prog: main.o packagemanager.o utils.o
	$(CCP) $(FLAGS) -o nvs main.o packagemanager.o utils.o

main.o: src/main.cpp
	$(CCP) $(FLAGS) -c src/main.cpp

packagemanager.o: src/packagemanager.hpp src/packagemanager.cpp
	$(CCP) $(FLAGS) -c src/packagemanager.hpp src/packagemanager.cpp

utils.o: src/utils.hpp src/utils.cpp
	$(CCP) $(FLAGS) -c src/utils.hpp src/utils.cpp

install:
	mkdir -p $(DESTDIR)/usr/local/bin/
	cp nvs $(DESTDIR)/usr/local/bin/
	mkdir -p $(DESTDIR)/usr/local/man/man8
	mkdir -p $(DESTDIR)/usr/local/etc/nvs
	mkdir -p $(DESTDIR)/usr/local/etc/bash_completion.d/nvs
	cp additional_resources/nvs $(DESTDIR)/usr/local/etc/nvs/nvs
	cp contrib/nvs.bash-completion $(DESTDIR)/usr/local/etc/bash_completion.d/nvs

uninstall:
	rm -rf /usr/local/bin/nvs
	rm -rf /etc/bash_completion.d/nvs

clean:
	rm -rf *.o src/*.gch
	rm -rf nvs
