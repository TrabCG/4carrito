//#include "var.cpp"



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
	printf("\n--Para testar as telas de GG ou de derrota é so manter pressionado G ou L---\n");
	printf("\n--------------------Para testar o placar é so presionar V-------------------\n");
	printf("\n----------------------------------------------------------------------------\n");
    //Selecionar cor de fundo preto
    	glMatrixMode(GL_PROJECTION);
    	glClearColor( 1, 1, 1, 0.0 );
		glLoadIdentity();
		glMatrixMode(GL_MODELVIEW);
    	gluOrtho2D(left,right,roof,ceiling);//2
        for (int i =0;i<256;i++)
        	teclas[i]=0;
     	for (int i =0;i<3;i++)
        	flagEnemy[i]=0;
}


void display(){

	glClear( GL_COLOR_BUFFER_BIT );
	keyOperations();
	teste();
	if (inicio ==0){
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glColor3f(1,1,1);
		glPushMatrix();	
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
		
		glColor3f(0,0,1);
		glPushMatrix();
		 // diminui o tamanho do fonte
		//glRotatef(15, 0,0,1); // rotaciona o texto
		//glRasterPos2f(menor.xy[0]-(1*menor.raio),maior.xy[1]-maior.raio+30); 
	    glTranslatef(menor.xy[0]-200,maior.xy[1]-maior.raio+30,0);
	    glScalef(0.2, 0.2, 0.2);
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,"Developed by Thayloso e Ipatinga");
		glPopMatrix();
		//desenhaCarrito();
		// Exibe o desenha na janela
		glPushMatrix();
			desenhaCarrito();
		glPopMatrix();
		cria_tiro();
		if(teclas[13]==true){
			inicio=1;
			reseta=0;
		}
		//glutSwapBuffers();
		glutPostRedisplay();
	}else if(fim==1){
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glColor3f(1,0,0);
		glPushMatrix();
		glTranslatef(menor.xy[0]-180,maior.xy[1],0);
	    glScalef(0.6, 0.6, 0.6);
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,"Se Fodeu!");
		glPopMatrix();
		fim=0;
	}else if(win==1){
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glColor3f(1,0,0);
		glPushMatrix();
		glTranslatef(menor.xy[0]-230,maior.xy[1],0);
	    glScalef(0.6, 0.6, 0.6);
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,"GGWP FION!");
		glPopMatrix();
		win=0;
	}else if(inicio !=0 && fim ==0 && win ==0){
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
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
	cria_tiro_Inimigo();
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

void teste(){
	if(teclas['i']==true)
		inicio=0;
	if(teclas['g']==true)
		win=1;
	if(teclas['l']==true)
		fim=1;		
	if(teclas['v']==true)
		numVoltas+=1;
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
		if (inicio==0){
		glPushMatrix();
			desenhaCirculo(0,0,360,player.raio,1,1,1);
		glPopMatrix();
		}else{
		glPushMatrix();
			circuloSemCor(0,0,360,player.raio);
		glPopMatrix();
		}
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
		if(distPlayer(player.xy[0]-6*dCos,player.xy[1]-6*dSin) > distMin && 
		distPlayer(player.xy[0]-6*dCos,player.xy[1]-6*dSin) < distMax) {
			if(flagEnemy[0]==1	&& enemyIsNear(enm2.xy[0],enm2.xy[1],player.xy[0]-6*dCos,player.xy[1]-6*dSin) > distEnemy
			&& enemyIsNear(enm3.xy[0],enm3.xy[1],player.xy[0]-6*dCos,player.xy[1]-6*dSin) > distEnemy){		
				dx-=6*dCos;
				dy-=6*dSin;
				if(angRoda > -90) angCarro+=5;
				if(angRoda < -90) angCarro-=5;
				frlR = 1;
				frlG = 1;
				frlB = 1;
			}else if(flagEnemy[1]==1 && enemyIsNear(enm1.xy[0],enm1.xy[1],player.xy[0]-6*dCos,player.xy[1]-6*dSin) > distEnemy
			&& enemyIsNear(enm3.xy[0],enm3.xy[1],player.xy[0]-6*dCos,player.xy[1]-6*dSin) > distEnemy){		
				dx-=6*dCos;
				dy-=6*dSin;
				if(angRoda > -90) angCarro+=5;
				if(angRoda < -90) angCarro-=5;
				frlR = 1;
				frlG = 1;
				frlB = 1;
			}else if(flagEnemy[2]==1 && enemyIsNear(enm1.xy[0],enm1.xy[1],player.xy[0]-6*dCos,player.xy[1]-6*dSin) > distEnemy
			&& enemyIsNear(enm2.xy[0],enm2.xy[1],player.xy[0]-6*dCos,player.xy[1]-6*dSin) > distEnemy){		
				dx-=6*dCos;
				dy-=6*dSin;
				if(angRoda > -90) angCarro+=5;
				if(angRoda < -90) angCarro-=5;
				frlR = 1;
				frlG = 1;
				frlB = 1;
			}else if((enemyIsNear(enm2.xy[0],enm2.xy[1],player.xy[0]-6*dCos,player.xy[1]-6*dSin) > distEnemy) 
				&& enemyIsNear(enm1.xy[0],enm1.xy[1],player.xy[0]-6*dCos,player.xy[1]-6*dSin) > distEnemy
				&& enemyIsNear(enm3.xy[0],enm3.xy[1],player.xy[0]-6*dCos,player.xy[1]-6*dSin) > distEnemy){		
				dx-=6*dCos;
				dy-=6*dSin;
				if(angRoda > -90) angCarro+=5;
				if(angRoda < -90) angCarro-=5;
				frlR = 1;
				frlG = 1;
				frlB = 1;
			}
		}
  }else if(teclas['s']==true || teclas['S']==true){
		if(distPlayer(player.xy[0]+2*dCos,player.xy[1]+2*dSin) > distMin && distPlayer(player.xy[0]+2*dCos,player.xy[1]+2*dSin) < distMax){
			if(flagEnemy[0]==1 && enemyIsNear(enm2.xy[0],enm2.xy[1],player.xy[0]+2*dCos,player.xy[1]+2*dSin) > distEnemy
			&& enemyIsNear(enm3.xy[0],enm3.xy[1],player.xy[0]+2*dCos,player.xy[1]+2*dSin) > distEnemy){
				dx+=2*dCos;
			  	dy+=2*dSin;
				if(angRoda < -90) angCarro+=3;
				if(angRoda > -90) angCarro-=3;
				frltR = 1;
				frltG = 0;
				frltB = 0;
			}else if(flagEnemy[1]==1 && enemyIsNear(enm1.xy[0],enm1.xy[1],player.xy[0]+2*dCos,player.xy[1]+2*dSin) > distEnemy
			&& enemyIsNear(enm3.xy[0],enm3.xy[1],player.xy[0]+2*dCos,player.xy[1]+2*dSin) > distEnemy){
				dx+=2*dCos;
			  	dy+=2*dSin;
				if(angRoda < -90) angCarro+=3;
				if(angRoda > -90) angCarro-=3;
				frltR = 1;
				frltG = 0;
				frltB = 0;
			}else if(flagEnemy[2]==1 && enemyIsNear(enm2.xy[0],enm2.xy[1],player.xy[0]+2*dCos,player.xy[1]+2*dSin) > distEnemy
			&& enemyIsNear(enm1.xy[0],enm1.xy[1],player.xy[0]+2*dCos,player.xy[1]+2*dSin) > distEnemy){
				dx+=2*dCos;
			  	dy+=2*dSin;
				if(angRoda < -90) angCarro+=3;
				if(angRoda > -90) angCarro-=3;
				frltR = 1;
				frltG = 0;
				frltB = 0;
			}else if(enemyIsNear(enm1.xy[0],enm1.xy[1],player.xy[0]+2*dCos,player.xy[1]+2*dSin) > distEnemy
				&& enemyIsNear(enm2.xy[0],enm2.xy[1],player.xy[0]+2*dCos,player.xy[1]+2*dSin) > distEnemy
				&& enemyIsNear(enm3.xy[0],enm3.xy[1],player.xy[0]+2*dCos,player.xy[1]+2*dSin) > distEnemy){
				dx+=2*dCos;
			  	dy+=2*dSin;
				if(angRoda < -90) angCarro+=3;
				if(angRoda > -90) angCarro-=3;
				frltR = 1;
				frltG = 0;
				frltB = 0;
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

tiro novo_tiro_Inimigo(void){
    tiro t;
	t.speed = 30;
	t.raio = player.raio*1/10;
	t.angulo = angCarro -220 ;
	//t.x = enm1.xy[0];
	//t.y = enm1.xy[1];
    t.x =  cos(angCarro*M_PI/180.0)*(carrito.chassi.altura/2) + cos((t.angulo)*M_PI/180.0);
    t.y =  sin(angCarro*M_PI/180.0)*(carrito.chassi.altura/2) + sin((t.angulo)*M_PI/180.0);
    return t;
}

void mouse(int botao, int estado, int x, int y)
{

	if(botao == GLUT_LEFT_BUTTON){
		switch(estado){
			case GLUT_DOWN:
				tiros.push_back(novo_tiro());
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

void cria_tiro_Inimigo(void){

    if(!tiro_Inimigo.empty()){
        for(int i = 0; i < tiro_Inimigo.size(); i++){
            glPushMatrix();
                glTranslatef(tiro_Inimigo[i].x, tiro_Inimigo[i].y, 0);
                desenhaCirculo(enm1.xy[0],enm1.xy[1],360,tiro_Inimigo[i].raio,0,1,0);
            glPopMatrix();
            //caminho que os tiros vao seguir
           	tiro_Inimigo[i].x += cos((tiro_Inimigo[i].angulo-angCarro) * M_PI / 180.0)*tiro_Inimigo[i].speed;
          	tiro_Inimigo[i].y += sin((tiro_Inimigo[i].angulo-angCarro) * M_PI / 180.0)*tiro_Inimigo[i].speed;
            
  			//remove_tiro(i);
        }
    }
    glutPostRedisplay();      
}

void remove_tiro(int i){

	float distMin = menor.raio + tiros[i].raio;
	float distMax = maior.raio - tiros[i].raio;
	float distEnemy = tiros[i].raio + enm1.raio;

	float dCos =cos((tiros[i].angulo*M_PI)/180.0);
	float dSin =sin((tiros[i].angulo*M_PI)/180.0);

	float tx = tiros[i].x+player.xy[0] -dx;
	float ty = tiros[i].y+player.xy[1]-dy;
	if(inicio!=0){
		if(distPlayer(tx,ty) < distMin || distPlayer(tx,ty) > distMax)
			tiros.erase(tiros.begin()+i);
		if(flagEnemy[0]==0)
			if(enemyIsNear(enm1.xy[0],enm1.xy[1],tx,ty) < distEnemy){
				tiros.erase(tiros.begin()+i);
				flagEnemy[0]=1;
		}
		if(flagEnemy[1]==0)
			if(enemyIsNear(enm2.xy[0],enm2.xy[1],tx,ty) < distEnemy){
				tiros.erase(tiros.begin()+i);
				flagEnemy[1]=1;
		}
		if(flagEnemy[2]==0)		
			if(enemyIsNear(enm3.xy[0],enm3.xy[1],tx,ty) < distEnemy){
				tiros.erase(tiros.begin()+i);
				flagEnemy[2]=1;
		}
	}
}
void contaVoltas(){
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
	//tiro_Inimigo.push_back(novo_tiro_Inimigo());
	if(enemyIsNear(enm1.xy[0],enm1.xy[1],player.xy[0]+2*dCos,player.xy[1]+2*dSin) >= distEnemy)
		flagEnemy[0]=0;
	if(enemyIsNear(enm2.xy[0],enm2.xy[1],player.xy[0]+2*dCos,player.xy[1]+2*dSin) >= distEnemy)
		flagEnemy[1]=0;
	if(enemyIsNear(enm3.xy[0],enm3.xy[1],player.xy[0]+2*dCos,player.xy[1]+2*dSin) >= distEnemy)
		flagEnemy[2]=0;
	glutPostRedisplay();
	glutTimerFunc(20000,Timer, 1);

}