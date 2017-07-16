//#include "var.cpp"


irrklang::ISoundEngine* intro = irrklang::createIrrKlangDevice();
irrklang::ISoundEngine* jogo = irrklang::createIrrKlangDevice();
irrklang::ISoundEngine* tiroP = irrklang::createIrrKlangDevice();
irrklang::ISoundEngine* faleceu = irrklang::createIrrKlangDevice();
irrklang::ISoundEngine* explosao = irrklang::createIrrKlangDevice();
irrklang::ISoundEngine* ggwp = irrklang::createIrrKlangDevice();
irrklang::ISoundEngine* volta = irrklang::createIrrKlangDevice();
void init()
{
	float left = maior.xy[0]-maior.raio;

	float right = maior.xy[0]+maior.raio;

	float roof = maior.xy[1]-maior.raio;

	float ceiling = maior.xy[1]+maior.raio;
	printf("\n----------------------------------------------------------------------------\n");
	printf("\nTodos os comandos funcionam tanto para a tela inicial quanto dentro da arena\n");
	printf("\n--------------Para movimentar o Carrito é só usar W A S D-------------------\n");
	printf("\n--------Para atirar com o carrito é so clicar na direção desejada-----------\n");
	printf("\n----------------------------------------------------------------------------\n");
    //Selecionar cor de fundo preto
    	//glMatrixMode(GL_PROJECTION);
    	glClearColor( 1, 1, 1, 0.0 );
		//glLoadIdentity();
		//glMatrixMode(GL_MODELVIEW);
    	gluOrtho2D(left,right,roof,ceiling);//2
        for (int i =0;i<256;i++)
        	teclas[i]=0;
     	for (int i =0;i<3;i++)
        	flagEnemy[i]=0;
        
}


void display(){

	glClear( GL_COLOR_BUFFER_BIT );
	keyOperations();
	if (inicio ==0){
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		//glPushMatrix();
			desenhaCarrito();
		//glPopMatrix();
		glPushMatrix();	
			glColor3f(1,1,1);
			glTranslatef(menor.xy[0]-(1.7*menor.raio),menor.xy[1]+menor.raio,0);
			glScalef(0.3, 0.3, 0.3); // diminui o tamanho do fonte
			//glRotatef(15, 0,0,1); // rotaciona o texto
			glLineWidth(2); // define a espessura da linha
			DesenhaTextoStroke(GLUT_STROKE_ROMAN,"Bem Vindo ao jogo do ");
		glPopMatrix();
		glPushMatrix();
			glTranslatef(menor.xy[0]-80,menor.xy[1],0);
			glScalef(0.3, 0.3, 0.3);
			DesenhaTextoStroke(GLUT_STROKE_ROMAN,"CARRITO");
			glPopMatrix();
			glPushMatrix();
			glColor3f(1,0,0);
			glTranslatef(menor.xy[0]-(1.5*menor.raio),maior.xy[1]-menor.raio,0);
			glScalef(0.3, 0.3, 0.3);
			DesenhaTextoStroke(GLUT_STROKE_ROMAN,"Press ENTER to start!");
		glPopMatrix();

		// Posição no universo onde o texto bitmap será colocado 
		
		glPushMatrix();
			glColor3f(0,0,1);
			 // diminui o tamanho do fonte
			//glRotatef(15, 0,0,1); // rotaciona o texto
			//glRasterPos2f(menor.xy[0]-(1*menor.raio),maior.xy[1]-maior.raio+30); 
		    glTranslatef(menor.xy[0]-200,maior.xy[1]-maior.raio+30,0);
		    glScalef(0.2, 0.2, 0.2);
			DesenhaTextoStroke(GLUT_STROKE_ROMAN,"Developed by Thayloso e Ipatinga");
		glPopMatrix();
		//desenhaCarrito();
		// Exibe o desenha na janela
		if (tocaintro==-1){
				intro->play2D("audio/TopGearIntro.mp3", true);
				tocaintro=0;
			}
		cria_tiro();
		if(teclas[13]==true){
			inicio=1;
			reseta=0;
			tocaintro=1;
			efeitosonoro();
		}
		//glutSwapBuffers();
		//glutPostRedisplay();
	}else if(fim==1){
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		tocajogo=1;
		if(gamb==0){
			efeitosonoro();
			gamb=1;
		}
		glColor3f(1,0,0);
		glPushMatrix();
		glTranslatef(menor.xy[0]-70,maior.xy[1],0);
	    glScalef(0.6, 0.6, 0.6);
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,"R.I.P");
		glPopMatrix();
		if (tocafim==-1){
			faleceu->play2D("audio/darkness.mp3",true);
			tocafim=0;
		}
		//fim=0;
	}else if(win==1){
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glColor3f(1,0,0);
		glPushMatrix();
		glTranslatef(menor.xy[0]-230,maior.xy[1],0);
	    glScalef(0.6, 0.6, 0.6);
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,"GGWP FION!");
		glPopMatrix();
		glPushMatrix();
			glColor3f(1,0,0);
			 // diminui o tamanho do fonte
			//glRotatef(15, 0,0,1); // rotaciona o texto
			//glRasterPos2f(menor.xy[0]-(1*menor.raio),maior.xy[1]-maior.raio+30); 
		    glTranslatef(menor.xy[0]-180,maior.xy[1]-maior.raio+30,0);
		    glScalef(0.2, 0.2, 0.2);
			DesenhaTextoStroke(GLUT_STROKE_ROMAN,"Aperte ENTER para sair !");
		glPopMatrix();
		if(teclas[13]==true)
			exit(0);
		
		//win=0;
	}else if(inicio !=0 && fim ==0 && win ==0){
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	if (tocajogo==-1){
			jogo->play2D("audio/topgear1.mp3", true);
			tocajogo=0;
		}
	//placar que marca a quantidade de voltas que o fodendo player deu
	glPushMatrix();
			glTranslatef((maior.xy[0]-maior.raio)+20,(maior.xy[1]+maior.raio)-40,0);
			if(numVoltas<1)
				placar( 20, 20, 0, 0, 0);
			else 
				desenhaQuadrilatero( 20, 20, 0, 0, 0);
	glPopMatrix();
	glPushMatrix();
			glTranslatef((maior.xy[0]-maior.raio)+50,(maior.xy[1]+maior.raio)-40,0);
			if(numVoltas<2)
				placar( 20, 20, 0, 0, 0);
			else 
				desenhaQuadrilatero( 20, 20, 0, 0, 0);
	glPopMatrix();
	glPushMatrix();
			glTranslatef((maior.xy[0]-maior.raio)+80,(maior.xy[1]+maior.raio)-40,0);
			if(numVoltas<3)
				placar( 20, 20, 0, 0, 0);
			else 
				desenhaQuadrilatero( 20, 20, 0, 0, 0);
	glPopMatrix();
	glPushMatrix();
			glTranslatef((maior.xy[0]-maior.raio)+110,(maior.xy[1]+maior.raio)-40,0);
			if(numVoltas<4)
				placar( 20, 20, 0, 0, 0);
			else 
				desenhaQuadrilatero( 20, 20, 0, 0, 0);
	glPopMatrix();
	glPushMatrix();
			glTranslatef((maior.xy[0]-maior.raio)+140,(maior.xy[1]+maior.raio)-40,0);
			if(numVoltas<5)
				placar( 20, 20, 0, 0, 0);
			else 
				desenhaQuadrilatero( 20, 20, 0, 0, 0);
	glPopMatrix();
////////circuito
	desenhaCirculo(maior.xy[0],maior.xy[1],360,maior.raio,maior.rgb[0],maior.rgb[1],maior.rgb[2]);
	desenhaCirculo(menor.xy[0],menor.xy[1],360,menor.raio,menor.rgb[0],menor.rgb[1],menor.rgb[2]);

//// fodendo gamb pra contar voltas
/*
	glPushMatrix();
			glTranslatef(menor.xy[0],menor.raio+menor.xy[1],0);
			desenhaQuadrilatero(maior.raio-menor.raio,5,0,1,0);
	glPopMatrix();
	glPushMatrix();
			glTranslatef(menor.xy[0]-(1.67*menor.raio),menor.xy[1],0);
			desenhaQuadrilatero(5,maior.raio-menor.raio,0,1,0);
	glPopMatrix();
	glPushMatrix();
			glTranslatef(menor.xy[0],menor.xy[1]-(2.33*menor.raio),0);
			desenhaQuadrilatero(maior.raio-menor.raio,5,0,1,0);
	glPopMatrix();
*/
////////linha de largada
	glPushMatrix();
		glTranslatef(rect.xy[0] + rect.largura/2,rect.xy[1],0 );
		desenhaQuadrilatero(rect.altura,rect.largura,rect.rgb[0],rect.rgb[1],rect.rgb[2]);
	glPopMatrix();
	if(reseta==0){
		resetaPosCarrito();
		angCarro=-90;
		reseta=1;
	}
	desenhaCarrito();

	glPopMatrix();
	cria_tiro();
	//cria_tiro_Inimigo1();
	//cria_tiro_Inimigo2();
	//cria_tiro_Inimigo3();
////////"inimigos"
	if (flagEnemy[0]==0)
		desenhaCirculo(enm1.xy[0],enm1.xy[1],360,enm1.raio,enm1.rgb[0],enm1.rgb[1],enm1.rgb[2]);
	if (flagEnemy[1]==0)
		desenhaCirculo(enm2.xy[0],enm2.xy[1],360,enm2.raio,enm2.rgb[0],enm2.rgb[1],enm2.rgb[2]);
	if (flagEnemy[2]==0)
		desenhaCirculo(enm3.xy[0],enm3.xy[1],360,enm3.raio,enm3.rgb[0],enm3.rgb[1],enm3.rgb[2]);
}	

	glutSwapBuffers();
}

void efeitosonoro(){
	if (tocaintro==1)
		intro->drop();
	if (tocajogo==1)
		jogo->drop();
}
void resetaPosCarrito(){
	 dx = 0;
	 dy = 0;
}

void desenhaCarrito(){
	////////jogador
	glPushMatrix();

		glTranslatef(dx,dy,0);

		glTranslatef(player.xy[0],player.xy[1],0);

///////////colisao
		if (inicio==0)desenhaCirculo(0,0,360,player.raio,1,1,1);
		else circuloSemCor(0,0,360,player.raio);

		glRotatef(angCarro,0,0,1);
		glRotatef(90,0,0,1);

//////////eixos

		glTranslatef(0,-player.raio/1.5,0);
		glPushMatrix();
			glTranslatef(0,carrito.chassi.altura*3/4,0);
			glTranslatef(0,-carrito.chassi.altura*1/8,0);
			desenhaQuadrilatero(carrito.eixos[0].altura,carrito.eixos[0].largura,0.3,0,0);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0,carrito.chassi.altura*1/4,0);
			glTranslatef(0,-carrito.chassi.altura*1/8,0);
			desenhaQuadrilatero(carrito.eixos[1].altura,carrito.eixos[1].largura,0.3,0,0);
		glPopMatrix();

//////////farois

		glPushMatrix();
			glTranslatef(-player.raio/5,carrito.chassi.altura*15/16,0);
			desenhaQuadrilatero(carrito.farois[0].altura,carrito.farois[0].largura,frlR,frlG,frlB);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(player.raio/5,carrito.chassi.altura*15/16,0);
			desenhaQuadrilatero(carrito.farois[1].altura,carrito.farois[1].largura,frlR,frlG,frlB);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-player.raio/5,-carrito.chassi.altura*1/16,0);
			desenhaQuadrilatero(carrito.farois[2].altura,carrito.farois[2].largura,frltR,frltG,frltB);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(player.raio/5,-carrito.chassi.altura*1/16,0);
			desenhaQuadrilatero(carrito.farois[3].altura,carrito.farois[3].largura,frltR,frltG,frltB);
		glPopMatrix();

//////////rodas
		glPushMatrix();
			glTranslatef(player.raio*2/3,carrito.chassi.altura*3/4,0);
			glRotatef(angRoda,0,0,1);
			glRotatef(90,0,0,1);
			glTranslatef(0,-carrito.rodas[0].altura/2,0);
			desenhaQuadrilatero(carrito.rodas[0].altura,carrito.rodas[0].largura,0.1,0.1,0.1);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-player.raio*2/3,carrito.chassi.altura*3/4,0);
			glRotatef(angRoda,0,0,1);
			glRotatef(90,0,0,1);
			glTranslatef(0,-carrito.rodas[1].altura/2,0);
			desenhaQuadrilatero(carrito.rodas[1].altura,carrito.rodas[1].largura,0.1,0.1,0.1);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(player.raio*2/3,carrito.chassi.altura*1/4,0);
			glTranslatef(0,-carrito.rodas[2].altura/2,0);
			desenhaQuadrilatero(carrito.rodas[2].altura,carrito.rodas[2].largura,0.1,0.1,0.1);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-player.raio*2/3,carrito.chassi.altura*1/4,0);
			glTranslatef(0,-carrito.rodas[3].altura/2,0);
			desenhaQuadrilatero(carrito.rodas[3].altura,carrito.rodas[3].largura,0.1,0.1,0.1);
		glPopMatrix();

//////////canhao
		glPushMatrix();
			glTranslatef(0,carrito.chassi.altura*0.9,0);
			glRotatef(angCan,0,0,1);
			glRotatef(90,0,0,1);
			desenhaQuadrilatero( carrito.canhao.altura, carrito.canhao.largura, 0.4, 0.4, 0.4);
		glPopMatrix();

///////////chassi
		glPushMatrix();
			desenhaQuadrilatero( carrito.chassi.altura, carrito.chassi.largura, 0, 1, 0);
		glPopMatrix();

//////////listra
		
		glPushMatrix();
			desenhaQuadrilatero( carrito.chassi.altura, carrito.chassi.largura/2, 0, 0, 0);
		glPopMatrix();
glPopMatrix();
}

void desenhaCirculo(GLint x, GLint y, int linhas, int raio, float r, float g, float b){
	int i = 0;
		glColor3f(r,g,b);
	float angulo;
	glBegin(GL_POLYGON);
		for(i=0;i<linhas;i++){
			angulo = 2*M_PI*i/linhas;
			glVertex2f(x + (cos(angulo)*raio),y + (sin(angulo)*raio));
		}
	glEnd();
}

void desenhaQuadrilatero(int altura, int largura, float r, float g, float b){

	glColor3f(r,g,b);
	glBegin( GL_QUADS );
		glVertex2f ( largura/2, 0 );
		glVertex2f ( -(largura/2), 0 );
		glVertex2f ( -(largura/2), altura );
		glVertex2f ( largura/2, altura );
	glEnd();

}
void placar(int altura, int largura, float r, float g, float b){

	glColor3f(r,g,b);
	glBegin( GL_LINE_LOOP );
		glVertex2f ( largura/2, 0 );
		glVertex2f ( -(largura/2), 0 );
		glVertex2f ( -(largura/2), altura );
		glVertex2f ( largura/2, altura );
	glEnd();

}

void circuloSemCor(GLint x, GLint y, int linhas, int raio){
	int i = 0;
	float angulo;
	glBegin(GL_LINE);
		for(i=0;i<linhas;i++){
			angulo = 2*M_PI*i/linhas;
			glVertex2f(x + (cos(angulo)*raio),y + (sin(angulo)*raio));
		}
	glEnd();
}



float distPlayer(int oxPlayer, int oyPlayer){
	return sqrt( (maior.xy[0] - (oxPlayer + dx))*(maior.xy[0] - (oxPlayer + dx)) + (maior.xy[1] - (oyPlayer+ dy))*(maior.xy[1] - (oyPlayer  + dy)) );
}

float enemyIsNear (int xInimigo, int yInimigo, int oxPlayer, int oyPlayer){
	return sqrt( (oxPlayer + dx - xInimigo )*(oxPlayer + dx - xInimigo ) +
                (oyPlayer + dy - yInimigo)*(oyPlayer + dy - yInimigo) );
}

//funcoes que alteram o flag no vetor de teclas
void keyPressed (unsigned char key, int x, int y) {
    teclas[key] = true; // altera pra true a posicao da tecla pressionada
    }
void keyUp (unsigned char key, int x, int y){
    teclas[key] = false;// altera pra false a posicao da tecla pressionada

}

void keyOperations (void) {

	float distMin = menor.raio + player.raio;
	float distMax = maior.raio - player.raio;
	float distEnemy = player.raio + enm1.raio;

	float dCos =cos(((angCarro*M_PI)/180.0));
	float dSin =sin(((angCarro*M_PI)/180.0));
	if(teclas['v']==true)
		numVoltas++;
	if(inicio==0){
		if (teclas['w']==true || teclas['W']==true){
			dx-=6*dCos;
				dy-=6*dSin;
				if(angRoda > -90) angCarro+=5;
				if(angRoda < -90) angCarro-=5;
				frlR = 1;
				frlG = 1;
				frlB = 1;
			}else if(teclas['s']==true || teclas['S']==true){
				dx+=2*dCos;
			  	dy+=2*dSin;
				if(angRoda < -90) angCarro+=3;
				if(angRoda > -90) angCarro-=3;
				frltR = 1;
				frltG = 0;
				frltB = 0;
			}
	
	}else{
	if (teclas['w']==true || teclas['W']==true){
		frlR = 1;
		frlG = 1;
		frlB = 1;
		if(distPlayer(player.xy[0]-6*dCos,player.xy[1]-6*dSin) > distMin && 
		distPlayer(player.xy[0]-6*dCos,player.xy[1]-6*dSin) < distMax) {
			if(flagEnemy[0]==1	&& enemyIsNear(enm2.xy[0],enm2.xy[1],player.xy[0]-6*dCos,player.xy[1]-6*dSin) > distEnemy
			&& enemyIsNear(enm3.xy[0],enm3.xy[1],player.xy[0]-6*dCos,player.xy[1]-6*dSin) > distEnemy){		
				dx-=6*dCos;
				dy-=6*dSin;
				contaVoltas();
				if(angRoda > -90) angCarro+=5;
				if(angRoda < -90) angCarro-=5;
			}else if(flagEnemy[1]==1 && enemyIsNear(enm1.xy[0],enm1.xy[1],player.xy[0]-6*dCos,player.xy[1]-6*dSin) > distEnemy
			&& enemyIsNear(enm3.xy[0],enm3.xy[1],player.xy[0]-6*dCos,player.xy[1]-6*dSin) > distEnemy){		
				dx-=6*dCos;
				dy-=6*dSin;
				contaVoltas();
				if(angRoda > -90) angCarro+=5;
				if(angRoda < -90) angCarro-=5;
			}else if(flagEnemy[2]==1 && enemyIsNear(enm1.xy[0],enm1.xy[1],player.xy[0]-6*dCos,player.xy[1]-6*dSin) > distEnemy
			&& enemyIsNear(enm2.xy[0],enm2.xy[1],player.xy[0]-6*dCos,player.xy[1]-6*dSin) > distEnemy){		
				dx-=6*dCos;
				dy-=6*dSin;
				contaVoltas();
				if(angRoda > -90) angCarro+=5;
				if(angRoda < -90) angCarro-=5;
			}else if((enemyIsNear(enm2.xy[0],enm2.xy[1],player.xy[0]-6*dCos,player.xy[1]-6*dSin) > distEnemy) 
				&& enemyIsNear(enm1.xy[0],enm1.xy[1],player.xy[0]-6*dCos,player.xy[1]-6*dSin) > distEnemy
				&& enemyIsNear(enm3.xy[0],enm3.xy[1],player.xy[0]-6*dCos,player.xy[1]-6*dSin) > distEnemy){		
				dx-=6*dCos;
				dy-=6*dSin;
				contaVoltas();
				if(angRoda > -90) angCarro+=5;
				if(angRoda < -90) angCarro-=5;
			}
		}
  }else if(teclas['s']==true || teclas['S']==true){
		frltR = 1;
		frltG = 0;
		frltB = 0;
		if(distPlayer(player.xy[0]+2*dCos,player.xy[1]+2*dSin) > distMin && distPlayer(player.xy[0]+2*dCos,player.xy[1]+2*dSin) < distMax){
			if(flagEnemy[0]==1 && enemyIsNear(enm2.xy[0],enm2.xy[1],player.xy[0]+2*dCos,player.xy[1]+2*dSin) > distEnemy
			&& enemyIsNear(enm3.xy[0],enm3.xy[1],player.xy[0]+2*dCos,player.xy[1]+2*dSin) > distEnemy){
				dx+=2*dCos;
			  	dy+=2*dSin;
			  	contaVoltas();
				if(angRoda < -90) angCarro+=3;
				if(angRoda > -90) angCarro-=3;
			}else if(flagEnemy[1]==1 && enemyIsNear(enm1.xy[0],enm1.xy[1],player.xy[0]+2*dCos,player.xy[1]+2*dSin) > distEnemy
			&& enemyIsNear(enm3.xy[0],enm3.xy[1],player.xy[0]+2*dCos,player.xy[1]+2*dSin) > distEnemy){
				dx+=2*dCos;
			  	dy+=2*dSin;
			  	contaVoltas();
				if(angRoda < -90) angCarro+=3;
				if(angRoda > -90) angCarro-=3;
			}else if(flagEnemy[2]==1 && enemyIsNear(enm2.xy[0],enm2.xy[1],player.xy[0]+2*dCos,player.xy[1]+2*dSin) > distEnemy
			&& enemyIsNear(enm1.xy[0],enm1.xy[1],player.xy[0]+2*dCos,player.xy[1]+2*dSin) > distEnemy){
				dx+=2*dCos;
			  	dy+=2*dSin;
			  	contaVoltas();
				if(angRoda < -90) angCarro+=3;
				if(angRoda > -90) angCarro-=3;
			}else if(enemyIsNear(enm1.xy[0],enm1.xy[1],player.xy[0]+2*dCos,player.xy[1]+2*dSin) > distEnemy
				&& enemyIsNear(enm2.xy[0],enm2.xy[1],player.xy[0]+2*dCos,player.xy[1]+2*dSin) > distEnemy
				&& enemyIsNear(enm3.xy[0],enm3.xy[1],player.xy[0]+2*dCos,player.xy[1]+2*dSin) > distEnemy){
				dx+=2*dCos;
			  	dy+=2*dSin;
			  	contaVoltas();
				if(angRoda < -90) angCarro+=3;
				if(angRoda > -90) angCarro-=3;
			}
		}
  }
}
	if(teclas['a']==true || teclas['A']==true){
		if(angRoda+passo < -45) angRoda+=passo;
		if(angRoda+passo >-45) angRoda = -45;
	}
	if(teclas['d']==true || teclas['D']==true){
		if(angRoda-passo > -135) angRoda-=passo;
		if(angRoda+passo <-135) angRoda = -135;
	}
	if((teclas['a']==false && teclas['A']==false)  && (teclas['d']==false && teclas['D']==false)) angRoda = -90;
	glutPostRedisplay();
	if(teclas['w'] == false && teclas['W'] == false){

			frlR = 0.7;
			frlG = 0.7;
			frlB = 0.7;
	}
	if(teclas['s'] == false && teclas['S'] == false){

			frltR = 0.7;
			frltG = 0.7;
			frltB = 0.7;
	}
	if(angCarro > 270) angCarro = -90;
	else if(angCarro > 360 || angCarro < -360) angCarro =0;}


void passiveMotion(int x, int y){

	if(angCarro<0 && angCarro>-180){
		if(x<xIni){
			if(angCan < -45)angCan+=passo/5;
			if(angCan > -45)angCan = -45;
			xIni = x;
		}else{
			if(angCan > -135)angCan-=passo/5;
			if(angCan < -135)angCan = -135;
			xIni = x;
		}
	}
	else{
		if(x>xIni){
			if(angCan < -45)angCan+=2;
			if(angCan > -45)angCan = -45;
			xIni = x;
		}else{
			if(angCan > -135)angCan-=2;
			if(angCan < -135)angCan = -135;
			xIni = x;
		}
	}

	glutPostRedisplay();
}

tiro novo_tiro(void){
    tiro t;
	t.speed = velTiro;
	t.raio = player.raio*1/10;
    t.angulo = angCarro + (angCan)+270;
    t.x = dx - cos(angCarro*M_PI/180.0)*(carrito.chassi.altura/2) + cos((t.angulo)*M_PI/180.0)*carrito.canhao.altura;
    t.y = dy - sin(angCarro*M_PI/180.0)*(carrito.chassi.altura/2) + sin((t.angulo)*M_PI/180.0)*carrito.canhao.altura;
    return t;
}


float distEnem_Player(int ox, int oy){
	return sqrt( pow( (player.xy[0]+dx) - ox,2) + pow( (player.xy[1]+dy) - oy,2) );
}
tiro novo_tiro_Inimigo1(void){
    tiro t;
	t.speed = velTiroEnemy;
	t.raio = player.raio*1/10;
	t.r = distEnem_Player(enm1.xy[0],enm1.xy[1]);
	t.cosseno = ((player.xy[0]+dx) - enm1.xy[0]) / t.r;
	t.seno = ((player.xy[1]+dy) - enm1.xy[1]) / t.r;
    return t;
}
tiro novo_tiro_Inimigo2(void){
    tiro t;
	t.speed = velTiroEnemy;
	t.raio = player.raio*1/10;
	t.r = distEnem_Player(enm2.xy[0],enm2.xy[1]);
	t.cosseno = ((player.xy[0]+dx) - enm2.xy[0]) / t.r;
	t.seno = ((player.xy[1]+dy) - enm2.xy[1]) / t.r;
    return t;
}
tiro novo_tiro_Inimigo3(void){
    tiro t;
	t.speed = velTiroEnemy;
	t.raio = player.raio*1/10;
	t.r = distEnem_Player(enm3.xy[0],enm3.xy[1]);
	t.cosseno = ((player.xy[0]+dx) - enm3.xy[0]) / t.r;
	t.seno = ((player.xy[1]+dy) - enm3.xy[1]) / t.r;
    return t;
}

void cria_tiro_Inimigo1(void){

    if(!tiro_Inimigo1.empty()){
        for(int i = 0; i < tiro_Inimigo1.size(); i++){
            glPushMatrix();
                glTranslatef(tiro_Inimigo1[i].x, tiro_Inimigo1[i].y, 0);
                desenhaCirculo(enm1.xy[0],enm1.xy[1],360,tiro_Inimigo1[i].raio,0,1,0);
                //desenhaCirculo(enm1.xy[0],enm1.xy[1],360,tiro_Inimigo[i].raio,0,1,0);
            glPopMatrix();
            //caminho que os tiros vao seguir
           	tiro_Inimigo1[i].x += tiro_Inimigo1[i].speed*(tiro_Inimigo1[i].cosseno);
          	tiro_Inimigo1[i].y += tiro_Inimigo1[i].speed*(tiro_Inimigo1[i].seno);
          	//tiro_Inimigo[i].x += cos((tiro_Inimigo[i].cosseno) * M_PI / 180.0)*tiro_Inimigo[i].speed;
          	//tiro_Inimigo[i].y += sin((tiro_Inimigo[i].seno) * M_PI / 180.0)*tiro_Inimigo[i].speed;
          	//printf("caminnho em x do tiro %i =%f\n",i,tiro_Inimigo[i].x);
          	//printf("caminnho em y do tiro %i =%f\n",i,tiro_Inimigo[i].y);

  			remove_tiroInimigo(i);
        }
    }
    glutPostRedisplay();      
}
void cria_tiro_Inimigo2(void){

    if(!tiro_Inimigo2.empty()){
        for(int i = 0; i < tiro_Inimigo2.size(); i++){
            glPushMatrix();
                glTranslatef(tiro_Inimigo2[i].x, tiro_Inimigo2[i].y, 0);
                desenhaCirculo(enm2.xy[0],enm2.xy[1],360,tiro_Inimigo2[i].raio,0,1,0);
                //desenhaCirculo(enm1.xy[0],enm1.xy[1],360,tiro_Inimigo2[i].raio,0,1,0);
            glPopMatrix();
            //caminho que os tiros vao seguir
           	tiro_Inimigo2[i].x += tiro_Inimigo2[i].speed*(tiro_Inimigo2[i].cosseno);
          	tiro_Inimigo2[i].y += tiro_Inimigo2[i].speed*(tiro_Inimigo2[i].seno);
          	//tiro_Inimigo[i].x += cos((tiro_Inimigo[i].cosseno) * M_PI / 180.0)*tiro_Inimigo[i].speed;
          	//tiro_Inimigo[i].y += sin((tiro_Inimigo[i].seno) * M_PI / 180.0)*tiro_Inimigo[i].speed;
          	//printf("caminnho em x do tiro %i =%f\n",i,tiro_Inimigo[i].x);
          	//printf("caminnho em y do tiro %i =%f\n",i,tiro_Inimigo[i].y);

  			remove_tiroInimigo2(i);
        }
    }
    glutPostRedisplay();      
}
void cria_tiro_Inimigo3(void){

    if(!tiro_Inimigo3.empty()){
        for(int i = 0; i < tiro_Inimigo3.size(); i++){
            glPushMatrix();
                glTranslatef(tiro_Inimigo3[i].x, tiro_Inimigo3[i].y, 0);
                desenhaCirculo(enm3.xy[0],enm3.xy[1],360,tiro_Inimigo3[i].raio,0,1,0);
                //desenhaCirculo(enm1.xy[0],enm1.xy[1],360,tiro_Inimigo3[i].raio,0,1,0);
            glPopMatrix();
            //caminho que os tiros vao seguir
           	tiro_Inimigo3[i].x += tiro_Inimigo3[i].speed*(tiro_Inimigo3[i].cosseno);
          	tiro_Inimigo3[i].y += tiro_Inimigo3[i].speed*(tiro_Inimigo3[i].seno);

  			remove_tiroInimigo3(i);
        }
    }
    glutPostRedisplay();      
}

void mouse(int botao, int estado, int x, int y)
{

	if(botao == GLUT_LEFT_BUTTON){
		switch(estado){
			case GLUT_DOWN:
				tiros.push_back(novo_tiro());
				tiroP->play2D("audio/canhao.mp3");
				break;
		}
	}
}

void cria_tiro(void){

    if(!tiros.empty()){
        for(int i = 0; i < tiros.size(); i++){
            glPushMatrix();
                glTranslatef(tiros[i].x, tiros[i].y, 0);
                desenhaCirculo(player.xy[0],player.xy[1],360,tiros[i].raio,0,1,0);
            glPopMatrix();
            //caminho que os tiros vao seguir
          	tiros[i].x += cos((tiros[i].angulo) * M_PI / 180.0)*tiros[i].speed;
          	tiros[i].y += sin((tiros[i].angulo) * M_PI / 180.0)*tiros[i].speed;
          	
			remove_tiro(i);
        }
    }
    glutPostRedisplay();      
}
float distTiro(int oxPlayer, int oyPlayer){
	return sqrt( (maior.xy[0] - (oxPlayer ))*(maior.xy[0] - (oxPlayer)) + 
   (maior.xy[1] - (oyPlayer))*(maior.xy[1] - (oyPlayer  ) ));
}

/*float enemyIsNear (int xInimigo, int yInimigo, int oxPlayer, int oyPlayer){
	return sqrt( (oxPlayer + dx - xInimigo )*(oxPlayer + dx - xInimigo ) +
                (oyPlayer + dy - yInimigo)*(oyPlayer + dy - yInimigo) );
}*/
void remove_tiroInimigo(int i){

	float distMin1 = menor.raio + tiro_Inimigo1[i].raio;
	float distMax1 = maior.raio - tiro_Inimigo1[i].raio;

	float tx1 = tiro_Inimigo1[i].x+enm1.xy[0];
	float ty1 = tiro_Inimigo1[i].y+enm1.xy[1];
	float distPlayer = tiro_Inimigo1[i].raio + player.raio;
	if(inicio!=0){
		if(distTiro(tx1,ty1) < distMin1 || distTiro(tx1,ty1) > distMax1)
			tiro_Inimigo1.erase(tiro_Inimigo1.begin()+i);
		if(distEnem_Player(tx1,ty1)<distPlayer){
			tiro_Inimigo1.erase(tiro_Inimigo1.begin()+i);
			explosao->play2D("audio/Carroexplode.wav");
			fim=1;		
		}
	}	
}
void remove_tiroInimigo2(int i){

	float distMin2 = menor.raio + tiro_Inimigo2[i].raio;
	float distMax2 = maior.raio - tiro_Inimigo2[i].raio;

	float tx2 = tiro_Inimigo2[i].x+enm2.xy[0];
	float ty2 = tiro_Inimigo2[i].y+enm2.xy[1];
	float distPlayer = tiro_Inimigo1[i].raio + player.raio;
	
	if(inicio!=0){
		if(distTiro(tx2,ty2) < distMin2 || distTiro(tx2,ty2) > distMax2)
			tiro_Inimigo2.erase(tiro_Inimigo2.begin()+i);
		if(distEnem_Player(tx2,ty2)<distPlayer){
			tiro_Inimigo2.erase(tiro_Inimigo2.begin()+i);
			explosao->play2D("audio/Carroexplode.wav");
			fim=1;		
		}
	
	}	
}
void remove_tiroInimigo3(int i){

	float distMin3 = menor.raio + tiro_Inimigo3[i].raio;
	float distMax3 = maior.raio - tiro_Inimigo3[i].raio;

	float tx3 = tiro_Inimigo3[i].x+enm3.xy[0];
	float ty3 = tiro_Inimigo3[i].y+enm3.xy[1];
	float distPlayer = tiro_Inimigo1[i].raio + player.raio;
	if(inicio!=0){
		if(distTiro(tx3,ty3) < distMin3 || distTiro(tx3,ty3) > distMax3)
			tiro_Inimigo3.erase(tiro_Inimigo3.begin()+i);
		if(distEnem_Player(tx3,ty3)<distPlayer){
			tiro_Inimigo3.erase(tiro_Inimigo3.begin()+i);
			explosao->play2D("audio/Carroexplode.wav");
			fim=1;		
		}
	}	
}
void remove_tiro(int i){

	float distMin = menor.raio + tiros[i].raio;
	float distMax = maior.raio - tiros[i].raio;
	float distEnemy = tiros[i].raio + enm1.raio;

	float tx = tiros[i].x+player.xy[0]-dx;
	float ty = tiros[i].y+player.xy[1]-dy;
	if(inicio!=0){
		if(distPlayer(tx,ty) < distMin || distPlayer(tx,ty) > distMax)
			tiros.erase(tiros.begin()+i);
		if(flagEnemy[0]==0)
			if(enemyIsNear(enm1.xy[0],enm1.xy[1],tx,ty) < distEnemy){
				tiros.erase(tiros.begin()+i);
				explosao->play2D("audio/Carroexplode.wav");
				flagEnemy[0]=1;
		}
		if(flagEnemy[1]==0)
			if(enemyIsNear(enm2.xy[0],enm2.xy[1],tx,ty) < distEnemy){
				tiros.erase(tiros.begin()+i);
				explosao->play2D("audio/Carroexplode.wav");
				flagEnemy[1]=1;
		}
		if(flagEnemy[2]==0)		
			if(enemyIsNear(enm3.xy[0],enm3.xy[1],tx,ty) < distEnemy){
				tiros.erase(tiros.begin()+i);
				explosao->play2D("audio/Carroexplode.wav");
				flagEnemy[2]=1;
		}
	}
}

void contaVoltas(){
	if((player.xy[1]+dy > maior.xy[1]) && ( (player.xy[0]+dx > (maior.xy[0]))&& (player.xy[0]+dx < maior.xy[0]+5) )){
		flagmalandro=1;
		printf("%i\n Glu Glu yeh yeh\n",flagmalandro);
	}
	else if( (player.xy[1]+dy > maior.xy[1]) && (player.xy[0]+dx < maior.xy[0]) && sqm[0]==0 && flagmalandro==1){
		sqm[0]=1;
		printf("\n flag 0 ativo com %i \n",sqm[0]);
	}else if ( (player.xy[1]+dy < maior.xy[1])  &&  (player.xy[0]+dx < maior.xy[0]) && sqm[0]==1 && sqm[1]==0){
		sqm[1]=1;
		printf("\n flag 1 ativo com %i \n",sqm[1]);
	}else if ( (player.xy[1]+dy < maior.xy[1])  &&  (player.xy[0]+dx > maior.xy[0]) && sqm[0]==1 && sqm[1]==1 && sqm[2]==0){
		sqm[2]=1;
		printf("\n flag 2 ativo com %i \n",sqm[2]);
	}else if ( (player.xy[1]+dy > maior.xy[1])  &&  (player.xy[0]+dx > maior.xy[0]) && sqm[0]==1 && sqm[1]==1 && sqm[2]==1){
		numVoltas+=1;
		volta->play2D("audio/aplauso.wav");
		if(numVoltas>=5){
			win=1;
			ggwp->play2D("audio/ggwp.mp3");
			tocajogo=1;
			efeitosonoro();
		}
		for(int i=0;i<3;i++)
				sqm[i]=0;
	}else if ( (player.xy[1]+dy > maior.xy[1])  &&  (player.xy[0]+dx > maior.xy[0]) && (sqm[0]==1 || sqm[1]==1 || sqm[2]==1) ){
		flagmalandro=0;
		for(int i=0;i<3;i++)
				sqm[i]=0;
		printf("\n Valor do Flag 0 resetado pra %i \n",sqm[0]);
		printf("\n Valor do Flag 1 resetado pra %i \n",sqm[1]);
		printf("\n Valor do Flag 2 resetado pra %i \n",sqm[2]);
	}



/*	if(se o carrito passar dentro do ret verde && sqm[0]==0)
		sqm[0]=1;
	else sqm[0]=0;
	if(carrito passando dentro do ret2 && sqm[0]==1)
		if(sqm[0]==1)
			sqm[1]=0;
	if(carrito passando no ret3)
		if(sqm[0]==1 && sqm[1]==1)
			sqm[2]==1;
	if(carrito passando na linha de chegada)
		if(sqm[0]==1 && sqm[1]==1 && sqm[2]==1){
			numVoltas++;
			for(int i=0;i<3;i++)
				sqm[i]=0;
		}*/
}
void DesenhaTexto(void *font, char *string) 
{
	// Exibe caractere a caractere
	while(*string)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,*string++); 
}

// Função que recebe a fonte e um texto por parâmetro para ser exibido na 
// tela usando fonte de linhas
void DesenhaTextoStroke(void *font, char *string) 
{  
	// Exibe caractere a caractere
	while(*string)
		glutStrokeCharacter(GLUT_STROKE_ROMAN,*string++); 
}
void Timer(int value)
{	
	float distMin = menor.raio + player.raio;
	float distMax = maior.raio - player.raio;
	float distEnemy = player.raio + enm1.raio;

	float dCos =cos(((angCarro*M_PI)/180.0));
	float dSin =sin(((angCarro*M_PI)/180.0));
	if(value == 1){
		if(enemyIsNear(enm1.xy[0],enm1.xy[1],player.xy[0]+2*dCos,player.xy[1]+2*dSin) >= distEnemy)
			flagEnemy[0]=0;
		if(enemyIsNear(enm2.xy[0],enm2.xy[1],player.xy[0]+2*dCos,player.xy[1]+2*dSin) >= distEnemy)
			flagEnemy[1]=0;
		if(enemyIsNear(enm3.xy[0],enm3.xy[1],player.xy[0]+2*dCos,player.xy[1]+2*dSin) >= distEnemy)
			flagEnemy[2]=0;	
		glutPostRedisplay();
		glutTimerFunc(20000,Timer, 1);
	}
	if(value == 2){

		if(flagEnemy[0] ==0) tiro_Inimigo1.push_back(novo_tiro_Inimigo1());
		if(flagEnemy[1] ==0) tiro_Inimigo2.push_back(novo_tiro_Inimigo2());
		if(flagEnemy[2] ==0) tiro_Inimigo3.push_back(novo_tiro_Inimigo3());
		glutPostRedisplay();
		glutTimerFunc(freqTiroEnemy,Timer, 2);
	}
	if(value == 3){
		moveInimigo();
		glutPostRedisplay();
		glutTimerFunc(10,Timer,3);
	}
	
}

float distEnem(int ox, int oy){
	return sqrt( (maior.xy[0] - ox )*(maior.xy[0] - ox ) + (maior.xy[1] - oy)*(maior.xy[1] - oy ) );
}


void moveInimigo(){

	float distMin = menor.raio + enm1.raio;
	float distMax = maior.raio - enm1.raio;
	float distEnemy = player.raio + enm1.raio;

	if(distEnem(enm1.xy[0],enm1.xy[1]+1) < distMin || distEnem(enm1.xy[0],enm1.xy[1]-1) > distMax){
		passoEnm[0]= - passoEnm[0];}
	else if(distEnem(enm2.xy[0]+1,enm2.xy[1]) < distMin || distEnem(enm2.xy[0]-1,enm2.xy[1]) > distMax){
		passoEnm[1]= - passoEnm[1];}
	else if(distEnem(enm3.xy[0],enm3.xy[1]+1) < distMin || distEnem(enm3.xy[0],enm3.xy[1]-1) > distMax){
		passoEnm[2]= - passoEnm[2];}

		enm1.xy[1] += passoEnm[0];
		enm2.xy[0] += passoEnm[1];
		enm3.xy[1] += passoEnm[2];
}