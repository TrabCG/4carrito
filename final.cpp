#include "parser.cpp"
#include "funcs.h"


int main(int argc, char *argv[])
{

        parseXML(argv[1]);
        glutInit( &argc, argv );
    	glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB );
    	glutInitWindowSize( menor.raio*2, menor.raio*2 );
    	glutInitWindowPosition( 70, 75 );
    	glutCreateWindow("circuito");

    	init();
  		glutKeyboardFunc(keyPressed);
        glutKeyboardUpFunc(keyUp);
        glutDisplayFunc( display );
        glutPassiveMotionFunc( passiveMotion );
        glutTimerFunc(800,Timer,1);
        glutMouseFunc( mouse );

    	glutMainLoop();
    	return 0;
}



