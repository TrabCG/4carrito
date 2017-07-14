#include <GL/glut.h>
#include "tinyxml.h"
#include <string>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <stdlib.h>


typedef struct{
        float xy[2];
        float rgb[3];
        float raio;
}circ;

typedef struct{
     float altura;
     float largura;
     float xy[2];
     float rgb[3];
}quad;

typedef struct{
        quad chassi;
        quad rodas[4];
		quad eixos[2];
        quad farois[4];
        quad canhao;
}car;

typedef struct{
	float x;
	float y;
	float angulo;
	float raio;
	float speed;
    float cosI;
    float senI;
}tiro;

std::vector<tiro> tiros;

std::vector<tiro> tiro_Inimigo;

circ maior, menor, enm1, enm2, enm3, player;
car carrito;
quad rect;


int flagEnemy[3];

int numVoltas = 0;
float frlR;
float frlG;
float frlB;

float frltR;
float frltG;
float frltB;

float velTiro;

char pathsvg[300];

const char *corCirExt, *corCirInt, *corPlayer, *corLargada, *corEnm1, *corEnm2, *corEnm3;

bool teclas[256];

float dx = player.xy[0];
float dy = player.xy[1];
int inicio =0;
int fim=0;
int win=0;
int sqm[3];
int angRoda = -90;
int angCarro = -90;
int angCan = -90;
int reseta =0;
int passo = 10;
int passoEnm[3] = {1,1,1};
int xIni = 0;

void init();
void display();
void desenhaEixo();
void desenhaQuadrilatero(int altura, int largura, float r, float g, float b);
void desenhaCirculo(int x, int y, int raio, int pontos, float r, float g, float b);
void circuloSemCor(GLint x, GLint y, int linhas, int raio);
void criaTiro(int linha, int raio, float r, float g, float b);
void parseXML(char* argv);
void parseSVG(char* argv);
void keyOperations (void);
void keyPressed (unsigned char key, int x, int y);
void keyUp (unsigned char key, int x, int y);
void passiveMotion(int x, int y);
void mouse(int botao, int estado, int x, int y);
tiro novo_tiro(void);
void cria_tiro(void);
void remove_tiro(int i);
void remove_tiroInimigo(int i);
tiro novo_tiro_Inimigo(void);
void cria_tiro_Inimigo(void);
void Timer(int value);
void placar(int altura, int largura, float r, float g, float b);
void contaVoltas(void);
void DesenhaTexto(void *font, char *string);
void DesenhaTextoStroke(void *font, char *string);
void desenhaCarrito(void);
void resetaPosCarrito(void);
void moveInimigo();
float distEnem(int ox, int oy);
float distEnem_Player(int ox, int oy);
void teste(void);
