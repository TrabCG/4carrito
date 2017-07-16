CPP = g++
OPTS = -lGL -lGLU -lglut -I"/include" -L"/lib" lib/libIrrKlang.so -pthread
GAMB = && ./trabalhocg /home/gabriel/Área\ de\ Trabalho/cg/4trab/
all:
	$(CPP) final.cpp tinyxml.cpp tinystr.cpp tinyxmlparser.cpp tinyxmlerror.cpp -m32 -o trabalhocg $(OPTS) $(GAMB)
clean:
	rm trabalhocg