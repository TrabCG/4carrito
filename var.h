#include <GL/glut.h>
#include "tinyxml.h"
#include <string>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include "include/irrKlang.h"
#pragma comment(lib, "irrKlang.lib")


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
    float cosseno;
    float seno;
    float r;
}tiro;

std::vector<tiro> tiros;

std::vector<tiro> tiro_Inimigo1;
std::vector<tiro> tiro_Inimigo2;
std::vector<tiro> tiro_Inimigo3;


circ maior, menor, enm1, enm2, enm3, player;
car carrito;
quad rect;
int tocaintro=-1;
int tocajogo=-1;
int tocafim=-1;
int gamb=0;
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
float freqTiroEnemy;
float velTiroEnemy;
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
float passoEnm[3];
int xIni = 0;
int flagmalandro=0;
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
tiro novo_tiro_Inimigo2(void);
tiro novo_tiro_Inimigo1(void);
tiro novo_tiro_Inimigo3(void);
void cria_tiro_Inimigo1(void);
void cria_tiro_Inimigo2(void);
void cria_tiro_Inimigo3(void);
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
float distTiro(int oxPlayer, int oyPlayer);
void remove_tiroInimigo2(int i);
void remove_tiroInimigo3(int i);
void efeitosonoro(void);