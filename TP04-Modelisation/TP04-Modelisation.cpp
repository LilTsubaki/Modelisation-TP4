#include "stdafx.h"
#include <stdio.h>      
#include <stdlib.h>     
#include <math.h>
#include "glut.h" 
#include "Maillage.h"

#define WIDTH  480
#define HEIGHT 480
 
#define RED   0
#define GREEN 0
#define BLUE  0
#define ALPHA 1
#define PI 3.14159
 
#define KEY_ESC 27
 
void init_scene();
void render_scene();
GLvoid initGL();
GLvoid window_display();
GLvoid window_reshape(GLsizei width, GLsizei height); 
GLvoid window_key(unsigned char key, int x, int y); 
GLvoid window_idle(); 
 
static double zRotate = 0.5;
static double facteur = 0.5;
static Maillage maille;

int main(int argc, char **argv) 
{  
  // initialisation  des param�tres de GLUT en fonction
  // des arguments sur la ligne de commande

	

  glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
 
	 maille = Maillage::lectureOff("C:/Users/etu/Desktop/bunny.off");
	 maille.calculNormalTriangle();
    //bunny.Ecriture("bunny.obj");


  // d�finition et cr�ation de la fen�tre graphique
  glutInitWindowSize(WIDTH, HEIGHT);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Primitives graphiques");
 
  // initialisation de OpenGL et de la sc�ne
  initGL();  
  init_scene();
 
  // choix des proc�dures de callback pour 
  // le trac� graphique
  glutDisplayFunc(&window_display);
  // le redimensionnement de la fen�tre
  glutReshapeFunc(&window_reshape);
  // la gestion des �v�nements clavier
  glutKeyboardFunc(&window_key);
  glutIdleFunc(&window_idle);
  // la boucle prinicipale de gestion des �v�nements utilisateur
  glutMainLoop();  
 
  return 1;
}
 
GLvoid afficheMaille()
{
	Vector3D a;
	Vector3D b;
	Vector3D c;
	std::cout << maille.getTopo().size() << std::endl;
	for(int i =0; i < maille.getTopo().size(); i+=3)
	{
		a = maille.getGeom().at(maille.getTopo().at(i));
		b = maille.getGeom().at(maille.getTopo().at(i+1));
		c = maille.getGeom().at(maille.getTopo().at(i+2));


		glBegin(GL_LINE_LOOP);
			glVertex3f (a.x(), a.y(), a.z());
			glVertex3f (b.x(), b.y(), b.z());
			glVertex3f (c.x(), c.y(), c.z());
	   glEnd();
	}

	std::cout << "endload" << std::endl;
}


// initialisation du fond de la fen�tre graphique : noir opaque
 
GLvoid initGL() 
{
        glShadeModel(GL_SMOOTH);
    glClearColor(RED, GREEN, BLUE, ALPHA);
        glEnable(GL_DEPTH_TEST);
}
 
void init_scene()
{
}
 



// fonction de call-back pour l�affichage dans la fen�tre
GLvoid window_display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
  render_scene();
  afficheMaille();
  // trace la sc�ne grapnique qui vient juste d'�tre d�finie
  glFlush();
  glutSwapBuffers();
  
}
 
// fonction de call-back pour le redimensionnement de la fen�tre
 
GLvoid window_reshape(GLsizei width, GLsizei height)
{  
  glViewport(0, 0, width, height);
 
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-15.0, 15.0, -15.0, 15.0, -15.0, 15.0);
 
  // toutes les transformations suivantes s�appliquent au mod�le de vue 
  glMatrixMode(GL_MODELVIEW);
}
 
// fonction de call-back pour la gestion des �v�nements clavier
 
GLvoid window_key(unsigned char key, int x, int y) 
{  
  switch (key) {    
  case KEY_ESC:  
    exit(1);                    
    break;
     

  default:
    printf ("La touche %d n�est pas active.\n", key);
    break;
  }     
}
 
GLvoid window_idle() 
{  
	/*zRotate+=facteur;
	glutPostRedisplay();*/
}
 
 
void render_scene()
{
//c'est ici qu'on dessine
    //glLoadIdentity();
 
 
 }