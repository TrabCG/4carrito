all:
	g++ final.cpp tinyxml.cpp tinystr.cpp tinyxmlparser.cpp tinyxmlerror.cpp -o trabalhocg -lGLU -lGL -lglut && ./trabalhocg /home/thaylo/git-repos/4carrito/

clear:
	rm trabalhocg
