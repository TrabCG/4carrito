all:
	g++ final.cpp tinyxml.cpp tinystr.cpp tinyxmlparser.cpp tinyxmlerror.cpp -o trabalhocg -lGLU -lGL -lglut && ./trabalhocg /home/gabriel/Área\ de\ Trabalho/cg/4trab/

clear:
	rm trabalhocg
