#include<stdio.h>
#include <math.h>
#include <GL/glut.h>

float x_rotation = 0.0f, y_rotation = 0.0f, tx = 0.0f, ty = 0.0f, tz = 0.0f;
float dx = 0.0f, dy = 0.0f;
int mouseClicked = 0;


void createCube(){													//Dimiourgia kivou
	glTranslatef(tx, ty, tz);

	glBegin(GL_QUADS);

	// Tertragwno orofis
	glColor3f(0.4f, 0.0f, 0.0f);									//Orizoume kokkino xrwma
	glVertex3f(-0.5f, 0.5f, 0.5f);									//Orizoume tis korifes kathe simeiou etsi oste i kathe pleura na exei mikos 1
	glVertex3f( 0.5f, 0.5f, 0.5f);
	glVertex3f( 0.5f, 0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);

	// Tetragwno basis
	glColor3f(0.4f, 0.4f, 0.0f);									//Orizoume prasino xrwma
	glVertex3f(-0.5f, -0.5f, 0.5f);	
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f( 0.5f, -0.5f, -0.5f);
	glVertex3f( 0.5f, -0.5f, 0.5f);

	// Mprostino tetragwno
	glColor3f(0.0f, 0.0f, 0.4f);									//Orizoume mple xrwma
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glVertex3f( 0.5f, -0.5f, 0.5f);
	glVertex3f( 0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);

	// Pisw tetragwno												//Orzioume mov xrwma
	glColor3f(0.4f, 0.0f, 0.4f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glVertex3f( 0.5f, 0.5f, -0.5f);
	glVertex3f( 0.5f, -0.5, -0.5f);

	// Deksi tetragwno			
	glColor3f(1.0f, 0.5f, 0.0f);									//Orizoume portokali xrwma
	glVertex3f( 0.5f, -0.5f, -0.5f);
	glVertex3f( 0.5f, 0.5f, -0.5f);
	glVertex3f( 0.5f, 0.5f, 0.5f);
	glVertex3f( 0.5f, -0.5f, 0.5f);

	// Aristero tetragwno
	glColor3f(1.0f, 1.0f, 0.0f);									//Orzioume kitrino xrwma
	glVertex3f(-0.5f, -0.5, 0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);

	glEnd();
}


int initialize(void){										
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);							//Arxikopoiisi background me aspro xrwma
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);									
	glClearDepth(1.0f);												//Epitrepontai mono oi times twn pixel poy den kseprnane tin timi 1
	return 1;
}



void mouseState(int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		mouseClicked = 1;											//Stin periptwsi pou ptithei to aristero oumpi tote enrgopoieitai i peristrofi 
		dx = x - y_rotation;
		dy = -y + x_rotation;
	}
	else mouseClicked = 0;
}


void mouseMotion(int x, int y){
	if (mouseClicked){												//Otan ginei i to click sto pontiki pairnei tis times kata tis opoies peristrefetai
		y_rotation = x - dx;										//kai dinei sima oti prepei na ginei redisplay
		x_rotation = y + dy;
		glutPostRedisplay();
	}
}


void perspective_projection(int w, int h){							// Provoli kivou me kanoniko perspective
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(50.0, w / h, 1.0, 100.0 * 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void cavalier_projection(int w, int h){								//Provoli kivou me cavalier
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();	
	glViewport(301, 0, w, h);
	double theta = 45.0;
    double cavalier[16] = {
            1.0                               , 0.0                               , 0.0, 0.0,
            0.0                               , 1.0                               , 0.0, 0.0,
            4.0 * cos((theta)/(180.0 / M_PI)) , 4.0 * sin((theta)/(180.0 / M_PI)) , 1.0, 0.0,
            0.0                               , 0.0                               , 0.0, 1.0};
    glMultMatrixd(cavalier);										//Xrisi pinaka cavalier
	glOrtho(-1.5,1.5,-1.5,1.5,-3.0,9.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void cabinet_projection(int w, int h){								//Provoli kivou me cabinet
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(601, 0, w, h);
	double theta = 63.0;
    double cabinet[16] = {
            1.0                               , 0.0                               , 0.0, 0.0,
            0.0                               , 1.0                               , 0.0, 0.0,
            2.0 * cos((theta)/(180.0 / M_PI)) , 2.0 * sin((theta)/(180.0 / M_PI)) , 1.0, 0.0,
            0.0                               , 0.0                               , 0.0, 1.0};
    glMultMatrixd(cabinet);											//Xrisi pinaka cabinet
	glOrtho(-1.5,1.5,-1.5,1.5,-3.0,9.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void displayCube(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glEnable(GL_SCISSOR_TEST);										//Xrisi tis scissor gia diaxwrismo othonis

glViewport(0, 0, 300, 300);                  						// Orismos viewPort gia ton prwto kivo
glScissor(0, 0, 300, 300);                   						// Diaxwrismos prwtou tmimatos tou parathirou
perspective_projection(300, 300);
gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);    // Orismos thesis twn kivwn  

	glRotatef(x_rotation, 1.0f, 0.0f, 0.0f);						//Peristrofi kivou
	glRotatef(y_rotation, 0.0f, 1.0f, 0.0f);
	createCube();

glViewport(301, 0, 300, 300);                  						// Orismos viewPort gia ton deutero kivo
glScissor(301, 0, 300, 300);                   						// Diaxwrismos deuterou tmimatos tou parathirou
cavalier_projection(300, 300);
gluLookAt(0.0f , 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);      


	glRotatef(x_rotation, 1.0f, 0.0f, 0.0f);
	glRotatef(y_rotation, 0.0f, 1.0f, 0.0f);
	createCube();

glViewport(601, 0, 300, 300);                  						// Orismos viewPort gia ton trito kivo
glScissor(601, 0, 300, 300);                   						// Diaxwrismos tritou tmimatos tou parathirou
cabinet_projection(300, 300);
gluLookAt(0.0f , 0.0f , 3.0f , 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);       


	glRotatef(x_rotation, 1.0f, 0.0f, 0.0f);
	glRotatef(y_rotation, 0.0f, 1.0f, 0.0f);
	createCube();

	glFlush();
	glDisable(GL_SCISSOR_TEST);
	glutSwapBuffers();
}


int main(int argc, char *argv[]){
	
	glutInit(&argc, argv);

	printf("Cube's projection:\nFirst cube --> Perspective Projection\nSecond Cube --> Cavalier Projection\nThird Cube --> Cabinet Projection\n");

	glutInitWindowPosition(500, 150);							//Dimiourgia parathirou
	glutInitWindowSize(900, 300);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("Different Cube Projections");
	
	glutDisplayFunc(displayCube);								//Display kai reshape me to perspective projection
	glutReshapeFunc(perspective_projection);
	

	glutDisplayFunc(displayCube);								//Display kai reshape me to cavalier projection
	glutReshapeFunc(cavalier_projection);
	

	glutDisplayFunc(displayCube);								//Display kai reshape me to cabinet projection
	glutReshapeFunc(cabinet_projection);

	glutMouseFunc(mouseState);
	glutMotionFunc(mouseMotion);
	
	if (!initialize())											//Elexos gia arxikopoiisi
		return 1;
	glutMainLoop();

	return 0;
}