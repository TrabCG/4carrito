#include "var.h"

using namespace std;

#define TIXML_USE_STL
void parseXML(char* argv){
    strcat(argv,"config.xml");
    TiXmlDocument doc;
    const char* pathSVG;
    const char* nomeSVG;
    const char* tipoSVG;
    //verifica se o arquivo foi carregado

    if(!doc.LoadFile(argv)){
        return;
    }else{
        TiXmlElement* root = doc.FirstChildElement();
        TiXmlElement* Arena = root->FirstChildElement("arquivoDaArena");
        TiXmlElement* inimigo = Arena->FirstChildElement("arquivoDaArena");
        
        nomeSVG = Arena->Attribute("nome");
        pathSVG = Arena->Attribute("caminho");
        tipoSVG = Arena->Attribute("tipo");

		TiXmlElement* son = Arena->NextSiblingElement("carro");
		const char* attr;
		attr = son->Attribute("velTiro");
		velTiro = atof(attr);
        
//<inimigo freqTiro="0.0001" velInimigo="0.1" velTiro="0.3"></inimigo>

        TiXmlElement* Enemy = son->NextSiblingElement("inimigo");
        attr = Enemy->Attribute("freqTiro");
        freqTiroEnemy = atof(attr);
        attr = Enemy->Attribute("velInimigo");
        passoEnm[0] = atof(attr);
        passoEnm[1] = atof(attr);
        passoEnm[2] = atof(attr);
        attr = Enemy->Attribute("velTiro");
        velTiroEnemy = atof(attr);
                
        strcat(pathsvg, pathSVG);
        strcat(pathsvg, nomeSVG);
        strcat(pathsvg, ".");
        strcat(pathsvg, tipoSVG);
	printf("\n%s\n", pathsvg);

	parseSVG(pathsvg);

    }
}
void parseSVG(char* argv){

		int i =0;
		TiXmlDocument doc;

		if(!doc.LoadFile(pathsvg)){
		printf("\ndeu ruim\n");
		return;
}

		TiXmlElement* root = doc.FirstChildElement();



//------circulo externo-----


		TiXmlElement* son = root->FirstChildElement();//circle
        const char* attr;
				//x circulo externo
	    attr = son->Attribute("cx");
        maior.xy[0] = atof(attr);
        //y circulo externo
        attr = son->Attribute("cy");
        maior.xy[1] = atof(attr);
        //raio do externo
        attr = son->Attribute("r");
        maior.raio = atof(attr);
        //cor
        attr = son->Attribute("fill");
        corCirExt = attr;
        if (strcmp(corCirExt,"blue")==0){
            maior.rgb[0]=0;
            maior.rgb[1]=0;
            maior.rgb[2]=1;
        }

//--------circulo interno---------
        son = son->NextSiblingElement();//circle
				//x circulo externo
        attr = son->Attribute("cx");
        menor.xy[0] = atof(attr);
        //y circulo externo
        attr = son->Attribute("cy");
        menor.xy[1] = atof(attr);
        //raio do externo
        attr = son->Attribute("r");
        menor.raio = atof(attr);
        //cor
        attr = son->Attribute("fill");
        corCirInt = attr;
        if (strcmp(corCirInt,"white")==0){
            menor.rgb[0]=1;
            menor.rgb[1]=1;
            menor.rgb[2]=1;
        }

//------Largada-------
        son = son->NextSiblingElement();//rect
        //origem do x
        attr = son->Attribute("x");
        rect.xy[0] = atof(attr);
        //y origem
        attr = son->Attribute("y");
        rect.xy[1] = atof(attr);
        //largura
        attr = son->Attribute("width");
        rect.largura = atof(attr);
        //altura
        attr = son->Attribute("height");
        rect.altura = atof(attr);
        //cor
        attr = son->Attribute("fill");
        corLargada = attr;
        if (strcmp(corLargada,"black")==0){
            rect.rgb[0]=0;
            rect.rgb[1]=0;
            rect.rgb[2]=0;
        }

//--------inimigo1---------
				son = son->NextSiblingElement();//circle
				//x circulo enm1
        attr = son->Attribute("cx");
        enm1.xy[0] = atof(attr);
        //y circulo enm1
        attr = son->Attribute("cy");
        enm1.xy[1] = atof(attr);
        //raio do enm1
        attr = son->Attribute("r");
        enm1.raio = atof(attr);
        //cor
        attr = son->Attribute("fill");
        corEnm1 = attr;
        if (strcmp(corEnm1,"red")==0){
            enm1.rgb[0]=1;
            enm1.rgb[1]=0;
            enm1.rgb[2]=0;
        }

//--------inimigo2---------
				son = son->NextSiblingElement();//circle
        //x circulo canalha2
        attr = son->Attribute("cx");
        enm2.xy[0] = atof(attr);
        //y circulo canalha2
        attr = son->Attribute("cy");
        enm2.xy[1] = atof(attr);
        //raio do canalha2
        attr = son->Attribute("r");
        enm2.raio = atof(attr);
        //cor
        attr = son->Attribute("fill");
        corEnm2 = attr;
        if (strcmp(corEnm2,"red")==0){
            enm2.rgb[0]=1;
            enm2.rgb[1]=0;
            enm2.rgb[2]=0;
        }

//--------inimigo3---------
				son = son->NextSiblingElement();//circle
        //x circulo enemy3
        attr = son->Attribute("cx");
        enm3.xy[0] = atof(attr);
        //y circulo enemy3
        attr = son->Attribute("cy");
        enm3.xy[1] = atof(attr);
        //raio do inimigo3
        attr = son->Attribute("r");
        enm3.raio = atof(attr);
        //cor
        attr = son->Attribute("fill");
        corEnm3 = attr;
        if (strcmp(corEnm3,"red")==0){
            enm3.rgb[0]=1;
            enm3.rgb[1]=0;
            enm3.rgb[2]=0;
        }

//--------Le Wild Player---------
				son = son->NextSiblingElement();//circle
        //x player
        attr = son->Attribute("cx");
        player.xy[0] = atof(attr);
        //y player
        attr = son->Attribute("cy");
        player.xy[1] = atof(attr);
        //raio do player
        attr = son->Attribute("r");
        player.raio = atof(attr);

				carrito.chassi.altura = atof(attr)*4/3;
				carrito.chassi.largura = atof(attr)*2/3;
				carrito.canhao.altura = atof(attr)*1/3;
				carrito.canhao.largura = atof(attr)*4/30;
				for(i = 0; i<4; i++){
						carrito.rodas[i].altura = atof(attr)*1/2;
						carrito.rodas[i].largura = atof(attr)*1/3;

						carrito.farois[i].altura = atof(attr)*1/6;
						carrito.farois[i].largura = atof(attr)*1/5;
				}
				for(i = 0; i<2; i++){
						carrito.eixos[i].altura = atof(attr)*1/4;
						carrito.eixos[i].largura = atof(attr)*19/12;

				}

        //cor
        attr = son->Attribute("fill");
        corPlayer = attr;
        if (strcmp(corPlayer,"green")==0){
            player.rgb[0]=0;
            player.rgb[1]=1;
            player.rgb[2]=0;
        }

        doc.Clear();
}

