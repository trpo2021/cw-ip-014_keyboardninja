
SFML := lib/SFML
SFMLDEP := cmake-gui libpthread-stubs0-dev libgl1-mesa-dev libx11-dev libxrandr-dev libfreetype6-dev libglew1.5-dev libjpeg8-dev libsndfile1-dev libopenal-dev libudev-dev libgl1-mesa-dev xorg-dev 
SFMLLIB := $(SFML)/lib
LIBS=-lsfml-graphics -lsfml-window -lsfml-system
all: $(SFMLLIB)
	g++ -c main.cpp -I $(SFML)/include
	g++ main.o -L $(SFMLLIB) -o sfml-app $(LIBS)
$(SFMLLIB):
	git submodule update --init --recursive
	sudo apt-get install $(SFMLDEP)
	cmake $(SFML)/CMakeLists.txt
	make -C $(SFML)
run: all
	export LD_LIBRARY_PATH=$(SFMLLIB) && ./sfml-app