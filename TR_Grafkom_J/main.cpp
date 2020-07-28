#include <windows.h>
#include <GL/glut.h>
#include <math.h>

///w >> perbesar
///s >> perkecil
///d >> geser kanan
///a >> geser kiri
///1 >> menampilkan bagian dalam
///2 >> bergerak keatas
///3 >> bergerak kebawah
///4 >> putar kebawah
///5 >> putar keatas
///6 >> putar kanan
///7 >> putar kiri
///8 >> putar samping kiri
///9 >> putar samping kanan

GLfloat biru  [] = {0, 0, 1};
GLfloat pink  [] = {1,0.5,1};

bool pattern1 = true;  /// pink
bool pattern2 = false; /// biru

void init(void);
void hasil(void);
void keyboard(unsigned char, int, int);
void mouse(int button, int state, int x, int y);
void ukuran(int, int);
void mouseMotion(int x, int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

void warna(int)
{
    if (pattern1) {
		pattern1 = false;
		pattern2 = true;
	}else if (pattern2) {
		pattern1 = true;
		pattern2 = false;
	}
	glutTimerFunc(700, warna, 0);
	glutPostRedisplay();
}

void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(6.0);
    glLineWidth(3.0f);
}

void gedungdalam(){
    ///gedungdalam1
    glBegin(GL_QUADS);
    glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
    glVertex3f(-45.0,-35.0,5.0);
    glVertex3f(-45.0,-19.0,5.0);
    glVertex3f(-10.0,-19.0,5.0);
    glVertex3f(-10.0,-35.0,5.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-26.0,-35.0,5.5);
    glVertex3f(-26.0,-21.0,5.5);
    glVertex3f(-14.0,-21.0,5.5);
    glVertex3f(-14.0,-35.0,5.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-20.0,-21.0,6.0);
    glVertex3f(-20.0,-35.0,6.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
    glVertex3f(-10.0,-19.0,5.0);
    glVertex3f(-10.0,-19.0,-40.0);
    glVertex3f(-10.0,-35.0,-40.0);
    glVertex3f(-10.0,-35.0,5.0);
    glEnd();
    
    ///gedungkecil
    glBegin(GL_QUADS);
    glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
    glVertex3f(25.0,-19.0,0.0);
    glVertex3f(25.0,-19.0,-35.0);
    glVertex3f(25.0,-35.0,-35.0);
    glVertex3f(25.0,-35.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
    glVertex3f(-10.0,-19.0,0.0);
    glVertex3f(25.0,-19.0,0.0);
    glVertex3f(25.0,-35.0,0.0);
    glVertex3f(-10.0,-35.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
    glVertex3f(-10.0,-19.0,-35.0);
    glVertex3f(25.0,-19.0,-35.0);
    glVertex3f(25.0,-35.0,-35.0);
    glVertex3f(-10.0,-35.0,-35.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
    glVertex3f(-10.0,-19.0,-35.0);
    glVertex3f(25.0,-19.0,-35.0);
    glVertex3f(25.0,-19.0,0.0);
    glVertex3f(-10.0,-19.0,0.0);
    glEnd();

    ///kaca depan

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-62.0,-19.0,5.0);
    glVertex3f(-10.0,-19.0,5.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-62.0,-20.0,5.0);
    glVertex3f(-10.0,-20.0,5.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-62.0,-24.0,5.0);
    glVertex3f(-10.0,-24.0,5.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-62.0,-27.0,5.0);
    glVertex3f(-10.0,-27.0,5.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-62.0,-30.0,5.0);
    glVertex3f(-10.0,-30.0,5.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-62.0,-33.0,5.0);
    glVertex3f(-10.0,-33.0,5.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-60.0,-20.0,5.0);
    glVertex3f(-60.0,-35.0,5.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-55.0,-20.0,5.0);
    glVertex3f(-55.0,-35.0,5.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-50.0,-20.0,5.0);
    glVertex3f(-50.0,-35.0,5.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-45.0,-20.0,5.0);
    glVertex3f(-45.0,-35.0,5.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-40.0,-20.0,5.0);
    glVertex3f(-40.0,-35.0,5.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-30.0,-20.0,5.0);
    glVertex3f(-30.0,-35.0,5.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-25.0,-20.0,5.0);
    glVertex3f(-25.0,-35.0,5.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-20.0,-20.0,5.0);
    glVertex3f(-20.0,-35.0,5.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-15.0,-20.0,5.0);
    glVertex3f(-15.0,-35.0,5.0);
    glEnd();

    ///kaca samping kanan
    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-10.0,-19.0,5.0);
    glVertex3f(-10.0,-19.0,-40.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-10.0,-21.0,5.0);
    glVertex3f(-10.0,-21.0,-40.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-10.0,-24.0,5.0);
    glVertex3f(-10.0,-24.0,-40.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-10.0,-27.0,5.0);
    glVertex3f(-10.0,-27.0,-40.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-10.0,-30.0,5.0);
    glVertex3f(-10.0,-30.0,-40.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-10.0,-33.0,5.0);
    glVertex3f(-10.0,-33.0,-40.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-10.0,-20.0,5.0);
    glVertex3f(-10.0,-35.0,5.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-10.0,-20.0,2.5);
    glVertex3f(-10.0,-35.0,2.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-10.0,-20.0,-37.5);
    glVertex3f(-10.0,-35.0,-37.5);
    glEnd();

    ///kacagdgkecildepan
    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-10.0,-19.0,0);
    glVertex3f(25.0,-19.0,0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-10.0,-21.0,0);
    glVertex3f(25.0,-21.0,0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-10.0,-24.0,0);
    glVertex3f(25.0,-24.0,0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-10.0,-27.0,0);
    glVertex3f(25.0,-27.0,0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-10.0,-30.0,0);
    glVertex3f(25.0,-30.0,0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-10.0,-33.0,0);
    glVertex3f(25.0,-33.0,0);
    glEnd();

    ///vertical
    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-8.0,-19.0,0);
    glVertex3f(-8.0,-35.0,0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-3.0,-19.0,0);
    glVertex3f(-3.0,-35.0,0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(2.0,-19.0,0);
    glVertex3f(2.0,-35.0,0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(7.0,-19.0,0);
    glVertex3f(7.0,-35.0,0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(12.0,-19.0,0);
    glVertex3f(12.0,-35.0,0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(17.0,-19.0,0);
    glVertex3f(17.0,-35.0,0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(25.0,-19.0,0);
    glVertex3f(25.0,-35.0,0);
    glEnd();

    ///kacakecilkananV
    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(25.0,-19.0,-5.0);
    glVertex3f(25.0,-35.0,-5.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(25.0,-19.0,-10.0);
    glVertex3f(25.0,-35.0,-10.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(25.0,-19.0,-15.0);
    glVertex3f(25.0,-35.0,-15.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(25.0,-19.0,-20.0);
    glVertex3f(25.0,-35.0,-20.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(25.0,-19.0,-25.0);
    glVertex3f(25.0,-35.0,-25.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(25.0,-19.0,-30.0);
    glVertex3f(25.0,-35.0,-30.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(25.0,-19.0,-35.0);
    glVertex3f(25.0,-35.0,-35.0);
    glEnd();

    ///kacakecilkananH
    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(25.0,-19.0,-35.0);
    glVertex3f(25.0,-19.0,0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(25.0,-21.0,-35.0);
    glVertex3f(25.0,-21.0,0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(25.0,-24.0,-35.0);
    glVertex3f(25.0,-24.0,0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(25.0,-27.0,-35.0);
    glVertex3f(25.0,-27.0,0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(25.0,-30.0,-35.0);
    glVertex3f(25.0,-30.0,0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(25.0,-33.0,-35.0);
    glVertex3f(25.0,-33.0,0.0);
    glEnd();

    ///kacakecilblkngH
    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-10.0,-19.0,-35.0);
    glVertex3f(25.0,-19.0,-35.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-10.0,-21.0,-35.0);
    glVertex3f(25.0,-21.0,-35.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-10.0,-24.0,-35.0);
    glVertex3f(25.0,-24.0,-35.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-10.0,-27.0,-35.0);
    glVertex3f(25.0,-27.0,-35.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-10.0,-30.0,-35.0);
    glVertex3f(25.0,-30.0,-35.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-10.0,-33.0,-35.0);
    glVertex3f(25.0,-33.0,-35.0);
    glEnd();

    ///kacakecilblkngV
    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-8.0,-19.0,-35.0);
    glVertex3f(-8.0,-35.0,-35.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-3.0,-19.0,-35.0);
    glVertex3f(-3.0,-35.0,-35.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(2.0,-19.0,-35.0);
    glVertex3f(2.0,-35.0,-35.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(7.0,-19.0,-35.0);
    glVertex3f(7.0,-35.0,-35.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(12.0,-19.0,-35.0);
    glVertex3f(12.0,-35.0,-35.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(17.0,-19.0,-35.0);
    glVertex3f(17.0,-35.0,-35.0);
    glEnd();

    //kacaatas
    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-8.0,-19.0,0.0);
    glVertex3f(-8.0,-19.0,-35.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-3.0,-19.0,0.0);
    glVertex3f(-3.0,-19.0,-35.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(2.0,-19.0,0.0);
    glVertex3f(2.0,-19.0,-35.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(7.0,-19.0,0.0);
    glVertex3f(7.0,-19.0,-35.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(12.0,-19.0,0.0);
    glVertex3f(12.0,-19.0,-35.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(17.0,-19.0,0.0);
    glVertex3f(17.0,-19.0,-35.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-10.0,-19.0,-5.0);
    glVertex3f(25.0,-19.0,-5.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-10.0,-19.0,-10.0);
    glVertex3f(25.0,-19.0,-10.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-10.0,-19.0,-15.0);
    glVertex3f(25.0,-19.0,-15.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-10.0,-19.0,-20.0);
    glVertex3f(25.0,-19.0,-20.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-10.0,-19.0,-25.0);
    glVertex3f(25.0,-19.0,-25.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-10.0,-19.0,-30.0);
    glVertex3f(25.0,-19.0,-30.0);
    glEnd();

    //pintu
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(25.5,-21.5,-13.0);
    glVertex3f(25.5,-21.5,-22.0);
    glVertex3f(25.5,-35.0,-22.0);
    glVertex3f(25.5,-35.0,-13.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f(26.0,-21.5,-17.5);
    glVertex3f(26.0,-35.0,-17.5);
    glEnd();
}

void garisdepan(){
    int a = 0;
    for(int i=0; i<20; i++){
        glBegin(GL_LINES);
        glColor3f(0.5f, 0.5f, 0.5f);
        glVertex3f(-44.5+a, -10.5, 10.0);
        glVertex3f(-44.5+a, -5.0, 10.0);

        glVertex3f(-44.5+a, -17.5, 10.0);
        glVertex3f(-44.5+a, -12.0, 10.0);
        glEnd();
        a+=1;
    }
}

void depan(){
    glBegin(GL_QUADS);
    ///dindingluar
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-62.0, 40.0, 10.0);
    glVertex3f(-62.0, 39.0, 10.0);
    glVertex3f(-10.0, 39.0, 10.0);
    glVertex3f(-10.0, 40.0, 10.0);
    glEnd();

    int a = 0;
    for(int i=0; i<15; i++){
        glBegin(GL_LINES);
        glColor3f(0.5f, 0.5f, 0.5f);
        ///kiri
        glVertex3f(-59.3+a, -32.0, 10.0);
        glVertex3f(-59.3+a, 33.0, 10.0);

        ///kanan
        glVertex3f(-24.3+a, -19.0, 10.0);
        glVertex3f(-24.3+a, 33.0, 10.0);
        glEnd();
        a+=1;
    }

    ///tengah atas
    int b = 0;
    for(int i=0; i<20; i++) {
        glBegin(GL_LINES);
        glColor3f(0.5f, 0.5f, 0.5f);
        glVertex3f(-44.3+b, 26.5, 10.0);
        glVertex3f(-44.3+b, 33.0, 10.0);
        glEnd();
        b+=1;
    }

    ///batas vertikal
    ///tengah atas
    int c = 0;
    for(int i=0; i<3; i++) {
        glBegin(GL_QUADS);
        glColor3f(0.5f, 0.5f, 0.5f);
        glVertex3f(-41.5+c, 26.5, 10.0);
        glVertex3f(-41.5+c, 33.0, 10.0);
        glVertex3f(-40.0+c, 33.0, 10.0);
        glVertex3f(-40.0+c, 26.5, 10.0);
        glEnd();
        c+=5;
    }

    ///kiri
    glBegin(GL_QUADS);
    glVertex3f(-60.0, 33.0, 10.0);
    glVertex3f(-60.0, -32.0, 10.0);
    glVertex3f(-62.0, -32.0, 10.0);
    glVertex3f(-62.0, 33.0, 10.0);
    glEnd();

    int d = 0;
    for(int i=0; i<3; i++) {
        glBegin(GL_QUADS);
        glColor3f(0.5f, 0.5f, 0.5f);
        glVertex3f(-56.5+d, -32.0, 10.0);
        glVertex3f(-56.5+d, 33.0, 10.0);
        glVertex3f(-55.0+d, 33.0, 10.0);
        glVertex3f(-55.0+d, -32.0, 10.0);
        glEnd();
        d+=5;
    }

    ///kanan
    glBegin(GL_QUADS);
    glVertex3f(-12.0, 33.0, 10.0);
    glVertex3f(-12.0, -19.0, 10.0);
    glVertex3f(-10.0, -19.0, 10.0);
    glVertex3f(-10.0, 33.0, 10.0);
    glEnd();


    int e = 0;
    for(int i=0; i<3; i++) {
        glBegin(GL_QUADS);
        glColor3f(0.5f, 0.5f, 0.5f);
        glVertex3f(-25.0+e, -19.0, 10.0);
        glVertex3f(-25.0+e, 33.0, 10.0);
        glVertex3f(-26.5+e, 33.0, 10.0);
        glVertex3f(-26.5+e, -19.0, 10.0);
        glEnd();
        e+=5;
    }

    ///batas horizontal
    ///bawah
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-62.0, -32.0, 10.0);
    glVertex3f(-62.0, -35.0, 10.0);
    glVertex3f(-45.0, -35.0, 10.0);
    glVertex3f(-45.0, -32.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
    ///atas
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-62.0, 40.0, 10.0);
    glVertex3f(-62.0, 33.0, 10.0);
    glVertex3f(-10.0, 33.0, 10.0);
    glVertex3f(-10.0, 40.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
    ///kiri
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-11.5, 26.5, 10.0);
    glVertex3f(-11.5, 25.0, 10.0);
    glVertex3f(-60.0, 25.0, 10.0);
    glVertex3f(-60.0, 26.5, 10.0);
    glEnd();

    int f = 0;
    for(int i=0; i<3; i++) {
        glBegin(GL_QUADS);
        glColor3f(0.5f, 0.5f, 0.5f);
        glVertex3f(-46.0, 18.5-f, 10.0);
        glVertex3f(-46.0, 17.0-f, 10.0);
        glVertex3f(-60.0, 17.0-f, 10.0);
        glVertex3f(-60.0, 18.5-f, 10.0);
        glEnd();
        f+=7;
    }

    int g = 0;
    for(int i=0; i<3; i++) {
        glBegin(GL_QUADS);
        glVertex3f(-11.5, -3.5-g, 10.0);
        glVertex3f(-11.5, -5.0-g, 10.0);
        glVertex3f(-60.0, -5.0-g, 10.0);
        glVertex3f(-60.0, -3.5-g, 10.0);
        glEnd();
        g+=7;
    }

    glBegin(GL_QUADS);
    glVertex3f(-46.0, -24.5, 10.0);
    glVertex3f(-46.0, -26.0, 10.0);
    glVertex3f(-60.0, -26.0, 10.0);
    glVertex3f(-60.0, -24.5, 10.0);
    glEnd();

    int h = 0;
    for(int i=0; i<3; i++) {
        glBegin(GL_QUADS);
        glVertex3f(-26.0, 18.5-h, 10.0);
        glVertex3f(-26.0, 17.0-h, 10.0);
        glVertex3f(-11.5, 17.0-h, 10.0);
        glVertex3f(-11.5, 18.5-h, 10.0);
        glEnd();
        h+=7;
    }

    ///jendela
    int j = 0;
    for(int i=0; i<4; i++) {
        glBegin(GL_QUADS);
        glColor3f(0.0, 1.0, 1.0);
        glVertex3f(-45.0, 25.0-j, 7.0);
        glVertex3f(-45.0, 20.0-j, 7.0);
        glVertex3f(-45.0, 20.0-j, 2.5);
        glVertex3f(-45.0, 25.0-j, 2.5);
        glEnd();
        j+=7;
    }

    int k = 0;
    for(int i=0; i<4; i++) {
        glBegin(GL_QUADS);
        glColor3f(0.5f, 0.5f, 0.5f);
        glVertex3f(-45.0, 25.0-k, 0.0);
        glVertex3f(-45.0, 20.0-k, 0.0);
        glVertex3f(-45.0, 20.0-k, 1.8);
        glVertex3f(-45.0, 25.0-k, 1.8);
        glEnd();
        k+=7;
    }

    glBegin(GL_QUADS);
    ///bolongantengah
    glColor3f(0.5, 0.5, 1.0);
    ///dindingkiri
    glVertex3f(-45.0, 25.0, 10.0);
    glVertex3f(-45.0, -3.5, 10.0);
    glVertex3f(-45.0, -3.5, 0.0);
    glVertex3f(-45.0, 25.0, 0.0);
    ///dindingkanan
    glVertex3f(-27.0, 25.0, 10.0);
    glVertex3f(-27.0, -3.5, 10.0);
    glVertex3f(-27.0, -3.5, 0.0);
    glVertex3f(-27.0, 25.0, 0.0);
    ///dindingatas
    glVertex3f(-45.0, 25.0, 10.0);
    glVertex3f(-27.0, 25.0, 10.0);
    glVertex3f(-27.0, 25.0, 0.0);
    glVertex3f(-45.0, 25.0, 0.0);
    ///dindingbawah
    glVertex3f(-45.0, -3.5, 10.0);
    glVertex3f(-27.0, -3.5, 10.0);
    glVertex3f(-27.0, -3.5, 0.0);
    glVertex3f(-45.0, -3.5, 0.0);

    ///bolonganbawah
    ///kiri
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-45.0, -35.0, 10.0);
    glVertex3f(-45.0, -19.0, 10.0);
    glVertex3f(-45.0, -19.0, 5.0);
    glVertex3f(-45.0, -35.0, 5.0);

    ///atas
    glVertex3f(-45.0, -19.0, 10.0);
    glVertex3f(-15.0, -19.0, 10.0);
    glVertex3f(-15.0, -19.0, 5.0);
    glVertex3f(-45.0, -19.0, 5.0);
    glEnd();

    ///dindingdalam
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    ///kiri
    glVertex3f(-45.0, 35.0, 5.0);
    glVertex3f(-45.0, -35.0, 5.0);
    glVertex3f(-62.0, -35.0, 5.0);
    glVertex3f(-62.0, 35.0, 5.0);

    ///tengahatas
    glVertex3f(-45.0, 35.0, 5.0);
    glVertex3f(-45.0, 26.0, 5.0);
    glVertex3f(-26.5, 26.0, 5.0);
    glVertex3f(-26.5, 35.0, 5.0);

    ///tengahbawah
    glVertex3f(-45.0, -19.0, 5.0);
    glVertex3f(-45.0, -4.0, 5.0);
    glVertex3f(-26.5, -4.0, 5.0);
    glVertex3f(-26.5, -19.0, 5.0);

    ///kanan
    glVertex3f(-10.0, 35.0, 5.0);
    glVertex3f(-10.0, -19.0, 5.0);
    glVertex3f(-26.5, -19.0, 5.0);
    glVertex3f(-26.5, 35.0, 5.0);
    glEnd();
}

void sampingkanan(){
     glBegin(GL_QUADS);
    ///dindingluar
    glColor3f(1.0,10.0, 1.0);
    glVertex3f(-10.0, 40.0, 10.0);
    glVertex3f(-10.0, 39.0, 10.0);
    glVertex3f(-10.0, 39.0, -45.5);
    glVertex3f(-10.0, 40.0, -45.5);
    glEnd();

    ///bolongan
    glBegin(GL_LINES);
    ///kiri
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-10.0, -19.0, 7.3);
    glVertex3f(-10.0, 33.0, 7.3);
    glVertex3f(-10.0, -19.0, 6.4);
    glVertex3f(-10.0, 33.0, 6.4);
    glVertex3f(-10.0, -19.0, 5.4);
    glVertex3f(-10.0, 33.0, 5.4);

    ///atas1
    glVertex3f(-10.0, 26.5, 3.0);
    glVertex3f(-10.0, 33.0, 3.0);
    glVertex3f(-10.0, 26.5, 2.0);
    glVertex3f(-10.0, 33.0, 2.0);
    glVertex3f(-10.0, 26.5, 1.0);
    glVertex3f(-10.0, 33.0, 1.0);

    glVertex3f(-10.0, 26.5, -2.5);
    glVertex3f(-10.0, 33.0, -2.5);
    glVertex3f(-10.0, 26.5, -3.5);
    glVertex3f(-10.0, 33.0, -3.5);
    glVertex3f(-10.0, 26.5, -4.5);
    glVertex3f(-10.0, 33.0, -4.5);

    glVertex3f(-10.0, 26.5, -7.5);
    glVertex3f(-10.0, 33.0, -7.5);
    glVertex3f(-10.0, 26.5, -8.5);
    glVertex3f(-10.0, 33.0, -8.5);
    glVertex3f(-10.0, 26.5, -9.5);
    glVertex3f(-10.0, 33.0, -9.5);

    ///bawah1
    glVertex3f(-10.0, 10.0, 3.0);
    glVertex3f(-10.0, -19.0, 3.0);
    glVertex3f(-10.0, 10.0, 2.0);
    glVertex3f(-10.0, -19.0, 2.0);
    glVertex3f(-10.0, 10.0, 1.0);
    glVertex3f(-10.0, -19.0, 1.0);

    glVertex3f(-10.0, 10.0, -2.5);
    glVertex3f(-10.0, -19.0, -2.5);
    glVertex3f(-10.0, 10.0, -3.5);
    glVertex3f(-10.0, -19.0, -3.5);
    glVertex3f(-10.0, 10.0, -4.5);
    glVertex3f(-10.0, -19.0, -4.5);

    glVertex3f(-10.0, 10.0, -7.5);
    glVertex3f(-10.0, -19.0, -7.5);
    glVertex3f(-10.0, 10.0, -8.5);
    glVertex3f(-10.0, -19.0, -8.5);
    glVertex3f(-10.0, 10.0, -9.5);
    glVertex3f(-10.0, -19.0, -9.5);

    ///tengah
    glVertex3f(-10.0, -19.0, -12.5);
    glVertex3f(-10.0, 33.0, -12.5);
    glVertex3f(-10.0, -19.0, -13.5);
    glVertex3f(-10.0, 33.0, -13.5);
    glVertex3f(-10.0, -19.0, -14.5);
    glVertex3f(-10.0, 33.0, -14.5);

    glVertex3f(-10.0, -19.0, -17.5);
    glVertex3f(-10.0, 33.0, -17.5);
    glVertex3f(-10.0, -19.0, -18.5);
    glVertex3f(-10.0, 33.0, -18.5);
    glVertex3f(-10.0, -19.0, -19.5);
    glVertex3f(-10.0, 33.0, -19.5);

    glVertex3f(-10.0, -19.0, -22.5);
    glVertex3f(-10.0, 33.0, -22.5);
    glVertex3f(-10.0, -19.0, -23.5);
    glVertex3f(-10.0, 33.0, -23.5);
    glVertex3f(-10.0, -19.0, -24.5);
    glVertex3f(-10.0, 33.0, -24.5);

    glVertex3f(-10.0, -19.0, -27.5);
    glVertex3f(-10.0, 33.0, -27.5);
    glVertex3f(-10.0, -19.0, -28.5);
    glVertex3f(-10.0, 33.0, -28.5);
    glVertex3f(-10.0, -19.0, -29.5);
    glVertex3f(-10.0, 33.0, -29.5);

    ///kanan
    glVertex3f(-10.0, 26.5, -32.5);
    glVertex3f(-10.0, 33.0, -32.5);
    glVertex3f(-10.0, 26.5, -33.5);
    glVertex3f(-10.0, 33.0, -33.5);
    glVertex3f(-10.0, 26.5, -34.5);
    glVertex3f(-10.0, 33.0, -34.5);

    glVertex3f(-10.0, 26.5, -37.5);
    glVertex3f(-10.0, 33.0, -37.5);
    glVertex3f(-10.0, 26.5, -38.5);
    glVertex3f(-10.0, 33.0, -38.5);
    glVertex3f(-10.0, 26.5, -39.5);
    glVertex3f(-10.0, 33.0, -39.5);

    glVertex3f(-10.0, 26.5, -37.5);
    glVertex3f(-10.0, 33.0, -37.5);
    glVertex3f(-10.0, 26.5, -38.5);
    glVertex3f(-10.0, 33.0, -38.5);
    glVertex3f(-10.0, 26.5, -39.5);
    glVertex3f(-10.0, 33.0, -39.5);

    glVertex3f(-10.0, -35.0, -42.0);
    glVertex3f(-10.0, 33.0, -42.0);
    glVertex3f(-10.0, -35.0, -43.0);
    glVertex3f(-10.0, 33.0, -43.0);
    glVertex3f(-10.0, -35.0, -44.0);
    glVertex3f(-10.0, 33.0, -44.0);
    glEnd();

    ///vertikal
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    ///kiri
    glVertex3f(-10.0, 33.0, 10.0);
    glVertex3f(-10.0, -19.0, 10.0);
    glVertex3f(-10.0, -19.0, 8.0);
    glVertex3f(-10.0, 33.0, 8.0);

    glVertex3f(-10.0, 33.0, 4.8);
    glVertex3f(-10.0, -19.0, 4.8);
    glVertex3f(-10.0, -19.0, 3.5);
    glVertex3f(-10.0, 33.0, 3.5);

    ///atas1
    glVertex3f(-10.0, 33.0, 0.0);
    glVertex3f(-10.0, 26.5, 0.0);
    glVertex3f(-10.0, 26.5, -1.5);
    glVertex3f(-10.0, 33.0, -1.5);

    glVertex3f(-10.0, 33.0, -5.5);
    glVertex3f(-10.0, 26.5, -5.5);
    glVertex3f(-10.0, 26.5, -6.5);
    glVertex3f(-10.0, 33.0, -6.5);

    ///bawah1
    glVertex3f(-10.0, 10.0, 0.0);
    glVertex3f(-10.0, -19.0, 0.0);
    glVertex3f(-10.0, -19.0, -1.5);
    glVertex3f(-10.0, 10.0, -1.5);

    glVertex3f(-10.0, 10.0, -5.5);
    glVertex3f(-10.0, -19.0, -5.5);
    glVertex3f(-10.0, -19.0, -6.5);
    glVertex3f(-10.0, 10.0, -6.5);

    ///tengah
    glVertex3f(-10.0, 33.0, -10.5);
    glVertex3f(-10.0, -19.0, -10.5);
    glVertex3f(-10.0, -19.0, -11.5);
    glVertex3f(-10.0, 33.0, -11.5);

    glVertex3f(-10.0, 33.0, -15.5);
    glVertex3f(-10.0, -19.0, -15.5);
    glVertex3f(-10.0, -19.0, -16.5);
    glVertex3f(-10.0, 33.0, -16.5);

    glVertex3f(-10.0, 33.0, -20.5);
    glVertex3f(-10.0, -19.0, -20.5);
    glVertex3f(-10.0, -19.0, -21.5);
    glVertex3f(-10.0, 33.0, -21.5);

    glVertex3f(-10.0, 33.0, -25.5);
    glVertex3f(-10.0, -19.0, -25.5);
    glVertex3f(-10.0, -19.0, -26.5);
    glVertex3f(-10.0, 33.0, -26.5);

    glVertex3f(-10.0, 33.0, -30.5);
    glVertex3f(-10.0, -19.0, -30.5);
    glVertex3f(-10.0, -19.0, -31.5);
    glVertex3f(-10.0, 33.0, -31.5);

    ///kanan
    glVertex3f(-10.0, 33.0, -35.5);
    glVertex3f(-10.0, 26.5, -35.5);
    glVertex3f(-10.0, 26.5, -36.5);
    glVertex3f(-10.0, 33.0, -36.5);

    glVertex3f(-10.0, 33.0, -41.5);
    glVertex3f(-10.0, -35.0, -41.5);
    glVertex3f(-10.0, -35.0, -40.5);
    glVertex3f(-10.0, 33.0, -40.5);

    glVertex3f(-10.0, 33.0, -44.5);
    glVertex3f(-10.0, -35.0, -44.5);
    glVertex3f(-10.0, -35.0, -45.5);
    glVertex3f(-10.0, 33.0, -45.5);
    glEnd();

    ///horizontal
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    ///atas
    glVertex3f(-10.0, 40.0, 10.0);
    glVertex3f(-10.0, 33.0, 10.0);
    glVertex3f(-10.0, 33.0, -45.5);
    glVertex3f(-10.0, 40.0, -45.5);

    ///kiri
    glVertex3f(-10.5, 26.5, 10.0);
    glVertex3f(-10.5, 25.0, 10.0);
    glVertex3f(-10.0, 25.0, -45.5);
    glVertex3f(-10.0, 26.5, -45.5);

    glVertex3f(-10.0, 18.5, 10.0);
    glVertex3f(-10.0, 17.0, 10.0);
    glVertex3f(-10.0, 17.0, 3.5);
    glVertex3f(-10.0, 18.5, 3.5);

    glVertex3f(-10.0, 11.5, 10.0);
    glVertex3f(-10.0, 10.0, 10.0);
    glVertex3f(-10.0, 10.0, -31.5);
    glVertex3f(-10.0, 11.5, -31.5);

    glVertex3f(-10.0, 4.5, 10.0);
    glVertex3f(-10.0, 3.0, 10.0);
    glVertex3f(-10.0, 3.0, -31.5);
    glVertex3f(-10.0, 4.5, -31.5);

    glVertex3f(-10.0, -3.5, 10.0);
    glVertex3f(-10.0, -5.0, 10.0);
    glVertex3f(-10.0, -5.0, -31.5);
    glVertex3f(-10.0, -3.5, -31.5);

    glVertex3f(-10.0, -10.5, 10.0);
    glVertex3f(-10.0, -12.0, 10.0);
    glVertex3f(-10.0, -12.0, -31.5);
    glVertex3f(-10.0, -10.5, -31.5);

    glVertex3f(-10.0, -17.5, 10.0);
    glVertex3f(-10.0, -19.0, 10.0);
    glVertex3f(-10.0, -19.0, -31.5);
    glVertex3f(-10.0, -17.5, -31.5);

    ///tengah
    glVertex3f(-10.0, 18.5, -10.5);
    glVertex3f(-10.0, 17.0, -10.5);
    glVertex3f(-10.0, 17.0, -31.5);
    glVertex3f(-10.0, 18.5, -31.5);

    ///kanan
    glVertex3f(-10.0, 18.5, -40.5);
    glVertex3f(-10.0, 17.0, -40.5);
    glVertex3f(-10.0, 17.0, -45.5);
    glVertex3f(-10.0, 18.5, -45.5);

    glVertex3f(-10.0, 11.5, -40.5);
    glVertex3f(-10.0, 10.0, -40.5);
    glVertex3f(-10.0, 10.0, -45.5);
    glVertex3f(-10.0, 11.5, -45.5);

    glVertex3f(-10.0, 4.5, -40.5);
    glVertex3f(-10.0, 3.0, -40.5);
    glVertex3f(-10.0, 3.0, -45.5);
    glVertex3f(-10.0, 4.5, -45.5);

    glVertex3f(-10.0, -3.5, -40.5);
    glVertex3f(-10.0, -5.0, -40.5);
    glVertex3f(-10.0, -5.0, -45.5);
    glVertex3f(-10.0, -3.5, -45.5);

    glVertex3f(-10.0, -10.5, -40.5);
    glVertex3f(-10.0, -12.0, -40.5);
    glVertex3f(-10.0, -12.0, -45.5);
    glVertex3f(-10.0, -10.5, -45.5);

    glVertex3f(-10.0, -17.5, -40.5);
    glVertex3f(-10.0, -19.0, -40.5);
    glVertex3f(-10.0, -19.0, -45.5);
    glVertex3f(-10.0, -17.5, -45.5);

    glVertex3f(-10.0, -24.5, -40.5);
    glVertex3f(-10.0, -26.0, -40.5);
    glVertex3f(-10.0, -26.0, -45.5);
    glVertex3f(-10.0, -24.5, -45.5);

    glVertex3f(-10.0, -32.0, -40.5);
    glVertex3f(-10.0, -35.0, -40.5);
    glVertex3f(-10.0, -35.0, -45.5);
    glVertex3f(-10.0, -32.0, -45.5);
    glEnd();


    ///dindingdalam
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    ///kiri
    glVertex3f(-15.0, 35.0, 3.5);
    glVertex3f(-15.0, -19.0, 3.5);
    glVertex3f(-15.0, -19.0, 10.0);
    glVertex3f(-15.0, 35.0, 10.0);

    glVertex3f(-15.0, 35.0, 3.5);
    glVertex3f(-15.0, 26.5, 3.5);
    glVertex3f(-15.0, 26.5, -10.5);
    glVertex3f(-15.0, 35.0, -10.5);

    glVertex3f(-15.0, 35.0, -10.5);
    glVertex3f(-15.0, -19.0, -10.5);
    glVertex3f(-15.0, -19.0, -31.5);
    glVertex3f(-15.0, 35.0, -31.5);

    glVertex3f(-15.0, 10.0, -10.5);
    glVertex3f(-15.0, -19.0, -10.5);
    glVertex3f(-15.0, -19.0, 3.5);
    glVertex3f(-15.0, 10.0, 3.5);

    glVertex3f(-15.0, 35.0, -40.5);
    glVertex3f(-15.0, 26.5, -40.5);
    glVertex3f(-15.0, 26.5, -31.5);
    glVertex3f(-15.0, 35.0, -31.5);

    glVertex3f(-15.0, 35.0, -40.5);
    glVertex3f(-15.0, -35.5, -40.5);
    glVertex3f(-15.0, -35.5, -45.5);
    glVertex3f(-15.0, 35.0, -45.5);
    glEnd();
}

void belakang(){
    glBegin(GL_QUADS);
    ///dindingluar
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-62.0, 40.0, -45.5);
    glVertex3f(-62.0, 39.0, -45.5);
    glVertex3f(-10.0, 39.0, -45.5);
    glVertex3f(-10.0, 40.0, -45.5);
    glEnd();

    ///bolongan
    glBegin(GL_LINES);
    ///kiri
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-59.3, -19.0, -45.5);
    glVertex3f(-59.3, 33.0, -45.5);
    glVertex3f(-58.4, -19.0, -45.5);
    glVertex3f(-58.4, 33.0, -45.5);
    glVertex3f(-57.4, -19.0, -45.5);
    glVertex3f(-57.4, 33.0, -45.5);

    glVertex3f(-54.3, -19.0, -45.5);
    glVertex3f(-54.3, 33.0, -45.5);
    glVertex3f(-53.4, -19.0, -45.5);
    glVertex3f(-53.4, 33.0, -45.5);
    glVertex3f(-52.3, -19.0, -45.5);
    glVertex3f(-52.3, 33.0, -45.5);

    glVertex3f(-49.3, -19.0, -45.5);
    glVertex3f(-49.3, 33.0, -45.5);
    glVertex3f(-48.3, -19.0, -45.5);
    glVertex3f(-48.3, 33.0, -45.5);
    glVertex3f(-47.3, -19.0, -45.5);
    glVertex3f(-47.3, 33.0, -45.5);

    ///kanan
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-24.3, -32.0, -45.5);
    glVertex3f(-24.3, 33.0, -45.5);
    glVertex3f(-23.4, -32.0, -45.5);
    glVertex3f(-23.4, 33.0, -45.5);
    glVertex3f(-22.4, -32.0, -45.5);
    glVertex3f(-22.4, 33.0, -45.5);

    glVertex3f(-19.3, -32.0, -45.5);
    glVertex3f(-19.3, 33.0, -45.5);
    glVertex3f(-18.3, -32.0, -45.5);
    glVertex3f(-18.3, 33.0, -45.5);
    glVertex3f(-17.3, -32.0, -45.5);
    glVertex3f(-17.3, 33.0,-45.5);

    glVertex3f(-14.3, -32.0, -45.5);
    glVertex3f(-14.3, 33.0, -45.5);
    glVertex3f(-13.3, -32.0, -45.5);
    glVertex3f(-13.3, 33.0, -45.5);
    glVertex3f(-12.3, -32.0, -45.5);
    glVertex3f(-12.3, 33.0, -45.5);
    glEnd();

    ///bolongan tengah atas
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-44.3, 26.5, -45.5);
    glVertex3f(-44.3, 33.0, -45.5);
    glVertex3f(-43.4, 26.5, -45.5);
    glVertex3f(-43.4, 33.0, -45.5);
    glVertex3f(-42.3, 26.5, -45.5);
    glVertex3f(-42.3, 33.0, -45.5);

    glVertex3f(-39.3, 26.5, -45.5);
    glVertex3f(-39.3, 33.0, -45.5);
    glVertex3f(-38.3, 26.5, -45.5);
    glVertex3f(-38.3, 33.0, -45.5);
    glVertex3f(-37.3, 26.5, -45.5);
    glVertex3f(-37.3, 33.0, -45.5);

    glVertex3f(-34.3, 26.5, -45.5);
    glVertex3f(-34.3, 33.0, -45.5);
    glVertex3f(-33.3, 26.5, -45.5);
    glVertex3f(-33.3, 33.0, -45.5);
    glVertex3f(-32.3, 26.5, -45.5);
    glVertex3f(-32.3, 33.0, -45.5);

    glVertex3f(-29.3, 26.5, -45.5);
    glVertex3f(-29.3, 33.0, -45.5);
    glVertex3f(-28.4, 26.5, -45.5);
    glVertex3f(-28.4, 33.0, -45.5);
    glVertex3f(-27.5, 26.5, -45.5);
    glVertex3f(-27.5, 33.0, -45.5);

    ///bolongan tengah bawah
    glVertex3f(-44.3, -19.0, -45.5);
    glVertex3f(-44.3, -4.5, -45.5);
    glVertex3f(-43.4, -19.0, -45.5);
    glVertex3f(-43.4, -4.5, -45.5);
    glVertex3f(-42.3, -19.0, -45.5);
    glVertex3f(-42.3, -4.5, -45.5);

    glVertex3f(-39.3, -19.0, -45.5);
    glVertex3f(-39.3, -4.5, -45.5);
    glVertex3f(-38.3, -19.0, -45.5);
    glVertex3f(-38.3, -4.5, -45.5);
    glVertex3f(-37.3, -19.0, -45.5);
    glVertex3f(-37.3, -4.5, -45.5);

    glVertex3f(-34.3, -19.0, -45.5);
    glVertex3f(-34.3, -4.5, -45.5);
    glVertex3f(-33.3, -19.0, -45.5);
    glVertex3f(-33.3, -4.5, -45.5);
    glVertex3f(-32.3, -19.0, -45.5);
    glVertex3f(-32.3, -4.5, -45.5);

    glVertex3f(-29.3, -19.0, -45.5);
    glVertex3f(-29.3, -4.5, -45.5);
    glVertex3f(-28.4,-19.0, -45.5);
    glVertex3f(-28.4, -4.5, -45.5);
    glVertex3f(-27.5, -19.0, -45.5);
    glVertex3f(-27.5, -4.5, -45.5);
    glEnd();

    ///batas vertikal
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    ///tengah atas
    glVertex3f(-41.5, 26.5, -45.5);
    glVertex3f(-41.5, 33.0, -45.5);
    glVertex3f(-40.0, 33.0, -45.5);
    glVertex3f(-40.0, 26.5, -45.5);

    glVertex3f(-36.5, 26.5, -45.5);
    glVertex3f(-36.5, 33.0, -45.5);
    glVertex3f(-35.0, 33.0, -45.5);
    glVertex3f(-35.0, 26.5, -45.5);

    glVertex3f(-31.5, 26.5, -45.5);
    glVertex3f(-31.5, 33.0, -45.5);
    glVertex3f(-30.0, 33.0, -45.5);
    glVertex3f(-30.0, 26.5, -45.5);

    ///tengahbawah
    glVertex3f(-41.5, -19.0, -45.5);
    glVertex3f(-41.5, -4.5, -45.5);
    glVertex3f(-40.0, -4.5, -45.5);
    glVertex3f(-40.0, -19.0, -45.5);

    glVertex3f(-36.5, -19.0, -45.5);
    glVertex3f(-36.5, -4.5, -45.5);
    glVertex3f(-35.0, -4.5, -45.5);
    glVertex3f(-35.0, -19.0, -45.5);

    glVertex3f(-31.5, -19.0, -45.5);
    glVertex3f(-31.5, -4.5, -45.5);
    glVertex3f(-30.0, -4.5, -45.5);
    glVertex3f(-30.0, -19.0, -45.5);

    ///kiri
    glVertex3f(-60.0, 33.0, -45.5);
    glVertex3f(-60.0, -19.0, -45.5);
    glVertex3f(-62.0,-19.0, -45.5);
    glVertex3f(-62.0, 33.0, -45.5);

    glVertex3f(-56.5, -19.0, -45.5);
    glVertex3f(-56.5, 33.0, -45.5);
    glVertex3f(-55.0, 33.0, -45.5);
    glVertex3f(-55.0, -19.0, -45.5);

    glVertex3f(-51.5, -19.0, -45.5);
    glVertex3f(-51.5, 33.0, -45.5);
    glVertex3f(-50.0, 33.0, -45.5);
    glVertex3f(-50.0, -19.0, -45.5);

    glVertex3f(-45.0, 33.0, -45.5);
    glVertex3f(-45.0, -19.0, -45.5);
    glVertex3f(-46.5, -19.0, -45.5);
    glVertex3f(-46.5, 33.0, -45.5);

    ///kanan
    glVertex3f(-25.0, 40.0, -45.5);
    glVertex3f(-25.0, -32.0, -45.5);
    glVertex3f(-27.0, -32.0, -45.5);
    glVertex3f(-27.0, 40.0, -45.5);

    glVertex3f(-21.5, -32.0, -45.5);
    glVertex3f(-21.5, 33.0, -45.5);
    glVertex3f(-20.0, 33.0, -45.5);
    glVertex3f(-20.0, -32.0, -45.5);

    glVertex3f(-16.5, -32.0, -45.5);
    glVertex3f(-16.5, 33.0, -45.5);
    glVertex3f(-15.0, 33.0, -45.5);
    glVertex3f(-15.0, -32.0, -45.5);

    glVertex3f(-11.5, -33.0, -45.5);
    glVertex3f(-11.5, 33.0, -45.5);
    glVertex3f(-10.0, 33.0, -45.5);
    glVertex3f(-10.0, -32.0, -45.5);
    glEnd();

    ///batas horizontal
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    ///atas
    glVertex3f(-62.0, 40.0, -45.5);
    glVertex3f(-62.0, 33.0, -45.5);
    glVertex3f(-10.0, 33.0, -45.5);
    glVertex3f(-10.0, 40.0, -45.5);

    ///kiri
    glVertex3f(-11.5, 26.5, -45.5);
    glVertex3f(-11.5, 25.0, -45.5);
    glVertex3f(-60.0, 25.0, -45.5);
    glVertex3f(-60.0, 26.5, -45.5);

    glVertex3f(-46.0, 18.5, -45.5);
    glVertex3f(-46.0, 17.0, -45.5);
    glVertex3f(-60.0, 17.0, -45.5);
    glVertex3f(-60.0, 18.5, -45.5);

    glVertex3f(-46.0, 11.5, -45.5);
    glVertex3f(-46.0, 10.0, -45.5);
    glVertex3f(-60.0, 10.0, -45.5);
    glVertex3f(-60.0, 11.5, -45.5);

    glVertex3f(-46.0, 4.5, -45.5);
    glVertex3f(-46.0, 3.0, -45.5);
    glVertex3f(-60.0, 3.0, -45.5);
    glVertex3f(-60.0, 4.5, -45.5);

    glVertex3f(-11.5, -3.5, -45.5);
    glVertex3f(-11.5, -5.0, -45.5);
    glVertex3f(-60.0, -5.0, -45.5);
    glVertex3f(-60.0, -3.5, -45.5);

    glVertex3f(-11.5, -10.5, -45.5);
    glVertex3f(-11.5, -12.0, -45.5);
    glVertex3f(-60.0, -12.0, -45.5);
    glVertex3f(-60.0, -10.5, -45.5);

    glVertex3f(-11.5, -17.5, -45.5);
    glVertex3f(-11.5, -19.0, -45.5);
    glVertex3f(-60.0, -19.0, -45.5);
    glVertex3f(-60.0, -17.5, -45.5);

    glVertex3f(-26.0, -24.5, -45.5);
    glVertex3f(-26.0, -26.0, -45.5);
    glVertex3f(-11.5, -26.0, -45.5);
    glVertex3f(-11.5, -24.5, -45.5);

    ///kanan
    glVertex3f(-26.0, 18.5, -45.5);
    glVertex3f(-26.0, 17.0, -45.5);
    glVertex3f(-11.5, 17.0, -45.5);
    glVertex3f(-11.5, 18.5, -45.5);

    glVertex3f(-26.0, 11.5, -45.5);
    glVertex3f(-26.0, 10.0, -45.5);
    glVertex3f(-11.5, 10.0, -45.5);
    glVertex3f(-11.5, 11.5, -45.5);

    glVertex3f(-26.0, 4.5, -45.5);
    glVertex3f(-26.0, 3.0, -45.5);
    glVertex3f(-11.5, 3.0, -45.5);
    glVertex3f(-11.5, 4.5, -45.5);

    ///bawah
    glVertex3f(-27.0, -32.0, -45.5);
    glVertex3f(-27.0, -35.0, -45.5);
    glVertex3f(-10.0, -35.0, -45.5);
    glVertex3f(-10.0, -32.0, -45.5);
    glEnd();

    ///dindingdalam
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    ///kiri
    glVertex3f(-45.0, 35.0, -40.5);
    glVertex3f(-45.0, -19.0, -40.5);
    glVertex3f(-62.0, -19.0, -40.5);
    glVertex3f(-62.0, 35.0, -40.5);

    ///tengahatas
    glVertex3f(-45.0, 35.0, -40.5);
    glVertex3f(-45.0, 26.0, -40.5);
    glVertex3f(-26.5, 26.0, -40.5);
    glVertex3f(-26.5, 35.0, -40.5);

    ///tengahbawah
    glVertex3f(-45.0, -19.0, -40.5);
    glVertex3f(-45.0, -4.0, -40.5);
    glVertex3f(-26.5, -4.0, -40.5);
    glVertex3f(-26.5, -19.0, -40.5);

    ///kanan
    glVertex3f(-10.0, 35.0, -40.5);
    glVertex3f(-10.0, -35.0, -40.5);
    glVertex3f(-26.5, -35.0, -40.5);
    glVertex3f(-26.5, 35.0, -40.5);
    glEnd();
}

void sampingkiri(){
    glBegin(GL_QUADS);
    ///dindingluar
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-62.0, 40.0, 10.0);
    glVertex3f(-62.0, 39.0, 10.0);
    glVertex3f(-62.0, 39.0, -45.5);
    glVertex3f(-62.0, 40.0, -45.5);
    glEnd();

    ///bolongan
    glBegin(GL_LINES);
    ///kiri
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-62.0, -32.0, 7.3);
    glVertex3f(-62.0, 33.0, 7.3);
    glVertex3f(-62.0, -32.0, 6.4);
    glVertex3f(-62.0, 33.0, 6.4);
    glVertex3f(-62.0, -32.0, 5.4);
    glVertex3f(-62.0, 33.0, 5.4);

    glVertex3f(-62.0, 33.0, 3.0);
    glVertex3f(-62.0, -35.0, 3.0);
    glVertex3f(-62.0, 33.0, 2.0);
    glVertex3f(-62.0, -35.0, 2.0);
    glVertex3f(-62.0, 33.0, 1.0);
    glVertex3f(-62.0, -35.0, 1.0);

    glVertex3f(-62.0, 33.0, -2.5);
    glVertex3f(-62.0, -35.0, -2.5);
    glVertex3f(-62.0, 33.0, -3.5);
    glVertex3f(-62.0, -35.0, -3.5);
    glVertex3f(-62.0, 33.0, -4.5);
    glVertex3f(-62.0, -35.0, -4.5);

    glVertex3f(-62.0, 33.0, -7.5);
    glVertex3f(-62.0, -35.0, -7.5);
    glVertex3f(-62.0, 33.0, -8.5);
    glVertex3f(-62.0, -35.0, -8.5);
    glVertex3f(-62.0, 33.0, -9.5);
    glVertex3f(-62.0, -35.0, -9.5);

    ///tengah
    glVertex3f(-62.0, 26.5, -12.5);
    glVertex3f(-62.0, 33.0, -12.5);
    glVertex3f(-62.0, 26.5, -13.5);
    glVertex3f(-62.0, 33.0, -13.5);
    glVertex3f(-62.0, 26.5, -14.5);
    glVertex3f(-62.0, 33.0, -14.5);

    glVertex3f(-62.0, -19.0, -12.5);
    glVertex3f(-62.0, 3.0, -12.5);
    glVertex3f(-62.0, -19.0, -13.5);
    glVertex3f(-62.0, 3.0, -13.5);
    glVertex3f(-62.0, -19.0, -14.5);
    glVertex3f(-62.0, 3.0, -14.5);

    glVertex3f(-62.0, 26.5, -17.5);
    glVertex3f(-62.0, 33.0, -17.5);
    glVertex3f(-62.0, 26.5, -18.5);
    glVertex3f(-62.0, 33.0, -18.5);
    glVertex3f(-62.0, 26.5, -19.5);
    glVertex3f(-62.0, 33.0, -19.5);

    glVertex3f(-62.0, -19.0, -17.5);
    glVertex3f(-62.0, 3.0, -17.5);
    glVertex3f(-62.0, -19.0, -18.5);
    glVertex3f(-62.0, 3.0, -18.5);
    glVertex3f(-62.0, -19.0, -19.5);
    glVertex3f(-62.0, 3.0, -19.5);

    glVertex3f(-62.0, 26.5, -22.5);
    glVertex3f(-62.0, 33.0, -22.5);
    glVertex3f(-62.0, 26.5, -23.5);
    glVertex3f(-62.0, 33.0, -23.5);
    glVertex3f(-62.0, 26.5, -24.5);
    glVertex3f(-62.0, 33.0, -24.5);

    glVertex3f(-62.0, -19.0, -22.5);
    glVertex3f(-62.0, 3.0, -22.5);
    glVertex3f(-62.0, -19.0, -23.5);
    glVertex3f(-62.0, 3.0, -23.5);
    glVertex3f(-62.0, -19.0, -24.5);
    glVertex3f(-62.0, 3.0, -24.5);

    glVertex3f(-62.0, 26.5, -27.5);
    glVertex3f(-62.0, 33.0, -27.5);
    glVertex3f(-62.0, 26.5, -28.5);
    glVertex3f(-62.0, 33.0, -28.5);
    glVertex3f(-62.0, 26.5, -29.5);
    glVertex3f(-62.0, 33.0, -29.5);

    glVertex3f(-62.0, -19.0, -27.5);
    glVertex3f(-62.0, 3.0, -27.5);
    glVertex3f(-62.0, -19.0, -28.5);
    glVertex3f(-62.0, 3.0, -28.5);
    glVertex3f(-62.0, -19.0, -29.5);
    glVertex3f(-62.0, 3.0, -29.5);

    ///kanan
    glVertex3f(-62.0, -19.0, -32.5);
    glVertex3f(-62.0, 33.0, -32.5);
    glVertex3f(-62.0, -19.0, -33.5);
    glVertex3f(-62.0, 33.0, -33.5);
    glVertex3f(-62.0, -19.0, -34.5);
    glVertex3f(-62.0, 33.0, -34.5);

    glVertex3f(-62.0, -19.0, -37.5);
    glVertex3f(-62.0, 33.0, -37.5);
    glVertex3f(-62.0, -19.0, -38.5);
    glVertex3f(-62.0, 33.0, -38.5);
    glVertex3f(-62.0, -19.0, -39.5);
    glVertex3f(-62.0, 33.0, -39.5);

    glVertex3f(-62.0, -19.0, -37.5);
    glVertex3f(-62.0, 33.0, -37.5);
    glVertex3f(-62.0, -19.0, -38.5);
    glVertex3f(-62.0, 33.0, -38.5);
    glVertex3f(-62.0, -19.0, -39.5);
    glVertex3f(-62.0, 33.0, -39.5);

    glVertex3f(-62.0, -19.0, -42.0);
    glVertex3f(-62.0, 33.0, -42.0);
    glVertex3f(-62.0, -19.0, -43.0);
    glVertex3f(-62.0, 33.0, -43.0);
    glVertex3f(-62.0, -19.0, -44.0);
    glVertex3f(-62.0, 33.0, -44.0);
    glEnd();

    ///vertikal
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    ///kiri
    glVertex3f(-62.0, 33.0, 10.0);
    glVertex3f(-62.0, -32.0, 10.0);
    glVertex3f(-62.0, -32.0, 8.0);
    glVertex3f(-62.0, 33.0, 8.0);

    glVertex3f(-62.0, 33.0, 4.8);
    glVertex3f(-62.0, -32.0, 4.8);
    glVertex3f(-62.0, -32.0, 3.5);
    glVertex3f(-62.0, 33.0, 3.5);

    glVertex3f(-62.0, 33.0, 0.0);
    glVertex3f(-62.0, -35.0, 0.0);
    glVertex3f(-62.0, -35.0, -1.5);
    glVertex3f(-62.0, 33.0, -1.5);

    glVertex3f(-62.0, 33.0, -5.5);
    glVertex3f(-62.0, -35.0, -5.5);
    glVertex3f(-62.0, -35.0, -6.5);
    glVertex3f(-62.0, 33.0, -6.5);

    ///tengah
    glVertex3f(-62.0, 33.0, -10.5);
    glVertex3f(-62.0, -35.0, -10.5);
    glVertex3f(-62.0, -35.0, -11.5);
    glVertex3f(-62.0, 33.0, -11.5);

    glVertex3f(-62.0, 33.0, -15.5);
    glVertex3f(-62.0, 26.5, -15.5);
    glVertex3f(-62.0, 26.5, -16.5);
    glVertex3f(-62.0, 33.0, -16.5);

    glVertex3f(-62.0, 3.0, -15.5);
    glVertex3f(-62.0, -19.0, -15.5);
    glVertex3f(-62.0, -19.0, -16.5);
    glVertex3f(-62.0, 3.0, -16.5);

    glVertex3f(-62.0, 33.0, -20.5);
    glVertex3f(-62.0, 26.5, -20.5);
    glVertex3f(-62.0, 26.5, -21.5);
    glVertex3f(-62.0, 33.0, -21.5);

    glVertex3f(-62.0, 3.0, -20.5);
    glVertex3f(-62.0, -19.0, -20.5);
    glVertex3f(-62.0, -19.0, -21.5);
    glVertex3f(-62.0, 3.0, -21.5);

    glVertex3f(-62.0, 33.0, -25.5);
    glVertex3f(-62.0, 26.5, -25.5);
    glVertex3f(-62.0, 26.5, -26.5);
    glVertex3f(-62.0, 33.0, -26.5);

    glVertex3f(-62.0, 3.0, -25.5);
    glVertex3f(-62.0, -19.0, -25.5);
    glVertex3f(-62.0, -19.0, -26.5);
    glVertex3f(-62.0, 3.0, -26.5);

    glVertex3f(-62.0, 33.0, -30.5);
    glVertex3f(-62.0, -19.0, -30.5);
    glVertex3f(-62.0, -19.0, -31.5);
    glVertex3f(-62.0, 33.0, -31.5);

    ///kanan
    glVertex3f(-62.0, 33.0, -35.5);
    glVertex3f(-62.0, -19.0, -35.5);
    glVertex3f(-62.0, -19.0, -36.5);
    glVertex3f(-62.0, 33.0, -36.5);

    glVertex3f(-62.0, 33.0, -41.5);
    glVertex3f(-62.0, -19.0, -41.5);
    glVertex3f(-62.0, -19.0, -40.5);
    glVertex3f(-62.0, 33.0, -40.5);

    glVertex3f(-62.0, 33.0, -44.5);
    glVertex3f(-62.0, -19.0, -44.5);
    glVertex3f(-62.0, -19.0, -45.5);
    glVertex3f(-62.0, 33.0, -45.5);
    glEnd();

    ///horizontal
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    ///atas
    glVertex3f(-62.0, 40.0, 10.0);
    glVertex3f(-62.0, 33.0, 10.0);
    glVertex3f(-62.0, 33.0, -45.5);
    glVertex3f(-62.0, 40.0, -45.5);

    ///kiri
    glVertex3f(-62.5, 26.5, 9.0);
    glVertex3f(-62.5, 25.0, 9.0);
    glVertex3f(-62.0, 25.0, -45.5);
    glVertex3f(-62.0, 26.5, -45.5);

    glVertex3f(-62.0, 18.5, 10.0);
    glVertex3f(-62.0, 17.0, 10.0);
    glVertex3f(-62.0, 17.0, -11.5);
    glVertex3f(-62.0, 18.5, -11.5);

    glVertex3f(-62.0, 18.5, -31.5);
    glVertex3f(-62.0, 17.0, -31.5);
    glVertex3f(-62.0, 17.0, -45.5);
    glVertex3f(-62.0, 18.5, -45.5);

    glVertex3f(-62.0, 11.5, 10.0);
    glVertex3f(-62.0, 10.0, 10.0);
    glVertex3f(-62.0, 10.0, -11.5);
    glVertex3f(-62.0, 11.5, -11.5);

    glVertex3f(-62.0, 11.5, -31.5);
    glVertex3f(-62.0, 10.0, -31.5);
    glVertex3f(-62.0, 10.0, -45.5);
    glVertex3f(-62.0, 11.5, -45.5);

    glVertex3f(-62.0, 4.5, 10.0);
    glVertex3f(-62.0, 3.0, 10.0);
    glVertex3f(-62.0, 3.0, -45.5);
    glVertex3f(-62.0, 4.5, -45.5);

    glVertex3f(-62.0, -3.5, 10.0);
    glVertex3f(-62.0, -5.0, 10.0);
    glVertex3f(-62.0, -5.0, -45.5);
    glVertex3f(-62.0, -3.5, -45.5);

    glVertex3f(-62.0, -10.5, 10.0);
    glVertex3f(-62.0, -12.0, 10.0);
    glVertex3f(-62.0, -12.0, -45.5);
    glVertex3f(-62.0, -10.5, -45.5);

    glVertex3f(-62.0, -17.5, 10.0);
    glVertex3f(-62.0, -19.0, 10.0);
    glVertex3f(-62.0, -19.0, -45.5);
    glVertex3f(-62.0, -17.5, -45.5);

    ///kanan
    glVertex3f(-62.0, -24.5, 10.0);
    glVertex3f(-62.0, -26.0, 10.0);
    glVertex3f(-62.0, -26.0, -11.5);
    glVertex3f(-62.0, -24.5, -11.5);

    glVertex3f(-62.0, -32.0, 10.0);
    glVertex3f(-62.0, -35.0, 10.0);
    glVertex3f(-62.0, -35.0, -11.5);
    glVertex3f(-62.0, -32.0, -11.5);
    glEnd();

    ///dindingdalam
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    ///kiri
    glVertex3f(-57.0, 35.0, -11.5);
    glVertex3f(-57.0, -35.0, -11.5);
    glVertex3f(-57.0, -35.0, 10.0);
    glVertex3f(-57.0, 35.0, 10.0);

    ///tengahatas
    glVertex3f(-57.0, 35.0, -11.5);
    glVertex3f(-57.0, 26.0, -11.5);
    glVertex3f(-57.5, 26.0, -31.5);
    glVertex3f(-57.5, 35.0, -31.5);

    ///tengahbawah
    glVertex3f(-57.0, -19.0, -11.5);
    glVertex3f(-57.0, 4.0, -11.5);
    glVertex3f(-57.5, 4.0, -31.5);
    glVertex3f(-57.5, -19.0, -31.5);

    ///kanan
    glVertex3f(-57.0, 35.0, -31.5);
    glVertex3f(-57.0, -19.0, -31.5);
    glVertex3f(-57.5, -19.0, -45.5);
    glVertex3f(-57.5, 35.0,-45.5);
    glEnd();
}

void belakangbawah(){
    glBegin(GL_LINES);
    ///vertikal
    ///depan
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-56.0, -20.0, -11.5);
    glVertex3f(-56.0, -34.0, -11.5);
    glVertex3f(-54.0, -20.0, -11.5);
    glVertex3f(-54.0, -34.0, -11.5);
    glVertex3f(-52.0, -20.0, -11.5);
    glVertex3f(-52.0, -34.0, -11.5);
    glVertex3f(-50.0, -20.0, -11.5);
    glVertex3f(-50.0, -34.0, -11.5);
    glVertex3f(-48.0, -20.0, -11.5);
    glVertex3f(-48.0, -34.0, -11.5);
    glVertex3f(-46.0, -20.0, -11.5);
    glVertex3f(-46.0, -34.0, -11.5);
    glVertex3f(-44.0, -20.0, -11.5);
    glVertex3f(-44.0, -34.0, -11.5);
    glVertex3f(-42.0, -20.0, -11.5);
    glVertex3f(-42.0, -34.0, -11.5);

    ///samping
    glVertex3f(-26.5, -20.0, -18.0);
    glVertex3f(-26.5, -34.0, -18.0);
    glVertex3f(-26.5, -20.0, -20.0);
    glVertex3f(-26.5, -34.0, -20.0);
    glVertex3f(-26.5, -20.0, -22.0);
    glVertex3f(-26.5, -34.0, -22.0);
    glVertex3f(-26.5, -20.0, -24.0);
    glVertex3f(-26.5, -34.0, -24.0);
    glVertex3f(-26.5, -20.0, -26.0);
    glVertex3f(-26.5, -34.0, -26.0);
    glVertex3f(-26.5, -20.0, -28.0);
    glVertex3f(-26.5, -34.0, -28.0);
    glVertex3f(-26.5, -20.0, -30.0);
    glVertex3f(-26.5, -34.0, -30.0);
    glVertex3f(-26.5, -20.0, -32.0);
    glVertex3f(-26.5, -34.0, -32.0);
    glVertex3f(-26.5, -20.0, -34.0);
    glVertex3f(-26.5, -34.0, -34.0);
    glEnd();

    int y = 0;
    ///atas
    for(int a=0; a<4; a++){
        glBegin(GL_QUADS);
        glColor3f(0.5f, 0.5f, 0.5f);
        glVertex3f(-62.0, -19.1+y, 0.0);
        glVertex3f(-10.0, -19.1+y, 0.0);
        glVertex3f(-10.0, -19.1+y, -45.5);
        glVertex3f(-62.0, -19.1+y, -45.5);
        glEnd();
        y+=15;
    }

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    ///depan
    ///horizontal
    glVertex3f(-36.0, -19.0, -11.5);
    glVertex3f(-36.0, -20.0, -11.5);
    glVertex3f(-62.0, -20.0, -11.5);
    glVertex3f(-62.0, -19.0, -11.5);

    glVertex3f(-36.0, -26.0, -11.5);
    glVertex3f(-36.0, -28.0, -11.5);
    glVertex3f(-62.0, -28.0, -11.5);
    glVertex3f(-62.0, -26.0, -11.5);

    glVertex3f(-36.0, -35.0, -11.5);
    glVertex3f(-36.0, -34.0, -11.5);
    glVertex3f(-62.0, -34.0, -11.5);
    glVertex3f(-62.0, -35.0, -11.5);

    glVertex3f(-42.0, -19.0, -11.5);
    glVertex3f(-42.0, -35.0, -11.5);
    glVertex3f(-36.0, -35.0, -11.5);
    glVertex3f(-36.0, -19.0, -11.5);

    glVertex3f(-62.0, -19.0, -11.5);
    glVertex3f(-62.0, -35.0, -11.5);
    glVertex3f(-56.0, -35.0, -11.5);
    glVertex3f(-56.0, -19.0, -11.5);

    ///kaca
    glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
    glVertex3f(-42.0, -20.0, -11.5);
    glVertex3f(-42.0, -26.0, -11.5);
    glVertex3f(-56.0, -26.0, -11.5);
    glVertex3f(-56.0, -20.0, -11.5);

    glVertex3f(-42.0, -28.0, -11.5);
    glVertex3f(-42.0, -34.0, -11.5);
    glVertex3f(-56.0, -34.0, -11.5);
    glVertex3f(-56.0, -28.0, -11.5);

    ///samping
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-26.5, -34.0, -18.0);
    glVertex3f(-26.5, -35.0, -18.0);
    glVertex3f(-26.5, -35.0, -34.0);
    glVertex3f(-26.5, -34.0, -34.0);

    glVertex3f(-26.5, -26.0, -18.0);
    glVertex3f(-26.5, -28.0, -18.0);
    glVertex3f(-26.5, -28.0, -34.0);
    glVertex3f(-26.5, -26.0, -34.0);

    glVertex3f(-26.5, -19.0, -18.0);
    glVertex3f(-26.5, -20.0, -18.0);
    glVertex3f(-26.5, -20.0, -34.0);
    glVertex3f(-26.5, -19.0, -34.0);

    glVertex3f(-26.5, -19.0, -34.0);
    glVertex3f(-26.5, -35.0, -34.0);
    glVertex3f(-26.5, -35.0, -45.5);
    glVertex3f(-26.5, -19.0, -45.5);

    glVertex3f(-26.5, -19.0, -18.0);
    glVertex3f(-26.5, -35.0, -18.0);
    glVertex3f(-26.5, -35.0, -11.5);
    glVertex3f(-26.5, -19.0, -11.5);

    ///kaca
    glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
    glVertex3f(-26.5, -20.0, -18.0);
    glVertex3f(-26.5, -26.0, -18.0);
    glVertex3f(-26.5, -26.0, -34.0);
    glVertex3f(-26.5, -20.0, -34.0);

    glVertex3f(-26.5, -28.0, -18.0);
    glVertex3f(-26.5, -34.0, -18.0);
    glVertex3f(-26.5, -34.0, -34.5);
    glVertex3f(-26.5, -28.0, -34.5);
    glEnd();

    ///pintu
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-31.5, -19.0, -11.5);
    glVertex3f(-31.5, -35.0, -11.5);
    glVertex3f(-36.0, -35.0, -11.5);
    glVertex3f(-36.0, -19.0, -11.5);

    glVertex3f(-31.0, -19.0, -11.5);
    glVertex3f(-31.0, -35.0, -11.5);
    glVertex3f(-26.5, -35.0, -11.5);
    glVertex3f(-26.5, -19.0, -11.5);

    glColor3f(1.0, 1.0, 1.0);;
    glVertex3f(-31.0, -19.0, -11.5);
    glVertex3f(-31.0, -35.0, -11.5);
    glVertex3f(-31.5, -35.0, -11.5);
    glVertex3f(-31.5, -19.0, -11.5);
    glEnd();

    ///pilar
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.0f, 0.0f);
    ///tengah
    glVertex3f(-60.0, -19.0, -45.5);
    glVertex3f(-60.0, -35.0, -45.5);
    glVertex3f(-62.0, -35.0, -45.5);
    glVertex3f(-62.0, -19.0, -45.5);

    glVertex3f(-60.0, -19.0, -43.5);
    glVertex3f(-60.0, -35.0, -43.5);
    glVertex3f(-62.0, -35.0, -43.5);
    glVertex3f(-62.0, -19.0, -43.5);

    glVertex3f(-60.0, -19.0, -43.5);
    glVertex3f(-60.0, -35.0, -43.5);
    glVertex3f(-60.0, -35.0, -45.5);
    glVertex3f(-60.0, -19.0, -45.5);

    glVertex3f(-62.0, -19.0, -43.5);
    glVertex3f(-62.0, -35.0, -43.5);
    glVertex3f(-62.0, -35.0, -45.5);
    glVertex3f(-62.0, -19.0, -45.5);

    ///belakang
    glVertex3f(-47.0, -19.0, -45.5);
    glVertex3f(-47.0, -35.0, -45.5);
    glVertex3f(-49.0, -35.0, -45.5);
    glVertex3f(-49.0, -19.0, -45.5);

    glVertex3f(-47.0, -19.0, -43.5);
    glVertex3f(-47.0, -35.0, -43.5);
    glVertex3f(-49.0, -35.0, -43.5);
    glVertex3f(-49.0, -19.0, -43.5);

    glVertex3f(-47.0, -19.0, -43.5);
    glVertex3f(-47.0, -35.0, -43.5);
    glVertex3f(-47.0, -35.0, -45.5);
    glVertex3f(-47.0, -19.0, -45.5);

    glVertex3f(-49.0, -19.0, -43.5);
    glVertex3f(-49.0, -35.0, -43.5);
    glVertex3f(-49.0, -35.0, -45.5);
    glVertex3f(-49.0, -19.0, -45.5);

    ///
    glVertex3f(-33.0, -19.0, -45.5);
    glVertex3f(-33.0, -35.0, -45.5);
    glVertex3f(-35.0, -35.0, -45.5);
    glVertex3f(-35.0, -19.0, -45.5);

    glVertex3f(-33.0, -19.0, -43.5);
    glVertex3f(-33.0, -35.0, -43.5);
    glVertex3f(-35.0, -35.0, -43.5);
    glVertex3f(-35.0, -19.0, -43.5);

    glVertex3f(-33.0, -19.0, -43.5);
    glVertex3f(-33.0, -35.0, -43.5);
    glVertex3f(-33.0, -35.0, -45.5);
    glVertex3f(-33.0, -19.0, -45.5);

    glVertex3f(-35.0, -19.0, -43.5);
    glVertex3f(-35.0, -35.0, -43.5);
    glVertex3f(-35.0, -35.0, -45.5);
    glVertex3f(-35.0, -19.0, -45.5);

    ///samping
    glVertex3f(-62.0, -19.0, -32.0);
    glVertex3f(-62.0, -35.0, -32.0);
    glVertex3f(-62.0, -35.0, -34.0);
    glVertex3f(-62.0, -19.0, -34.0);

    glVertex3f(-60.0, -19.0, -32.0);
    glVertex3f(-60.0, -35.0, -32.0);
    glVertex3f(-60.0, -35.0, -34.0);
    glVertex3f(-60.0, -19.0, -34.0);

    glVertex3f(-60.0, -19.0, -32.0);
    glVertex3f(-60.0, -35.0, -32.0);
    glVertex3f(-62.0, -35.0, -32.0);
    glVertex3f(-62.0, -19.0, -32.0);

    glVertex3f(-60.0, -19.0, -34.0);
    glVertex3f(-60.0, -35.0, -34.0);
    glVertex3f(-62.0, -35.0, -34.0);
    glVertex3f(-62.0, -19.0, -34.0);

    ///
    glVertex3f(-62.0, -19.0, -22.0);
    glVertex3f(-62.0, -35.0, -22.0);
    glVertex3f(-62.0, -35.0, -20.0);
    glVertex3f(-62.0, -19.0, -20.0);

    glVertex3f(-60.0, -19.0, -22.0);
    glVertex3f(-60.0, -35.0, -22.0);
    glVertex3f(-60.0, -35.0, -20.0);
    glVertex3f(-60.0, -19.0, -20.0);

    glVertex3f(-60.0, -19.0, -22.0);
    glVertex3f(-60.0, -35.0, -22.0);
    glVertex3f(-62.0, -35.0, -22.0);
    glVertex3f(-62.0, -19.0, -22.0);

    glVertex3f(-60.0, -19.0, -20.0);
    glVertex3f(-60.0, -35.0, -20.0);
    glVertex3f(-62.0, -35.0, -20.0);
    glVertex3f(-62.0, -19.0, -20.0);
    glEnd();
}

void lantai(){
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.0, 0.0);
    glVertex3f(-62.0, -35.0, 21.0);
    glVertex3f(100.0, -35.0, 21.0);
    glVertex3f(100.0, -35.0, -45.5);
    glVertex3f(-62.0, -35.0, -45.5);
    glEnd();

    //tanaman1
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.8, 0.0);
    glVertex3f(-62.0, -35.0, 21.0);
    glVertex3f(-41.0, -35.0, 21.0);
    glVertex3f(-41.0, -47.0, 31.0);
    glVertex3f(-62.0, -47.0, 31.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.3, 0.0);
    glVertex3f(-62.0, -33.0, 21.0);
    glVertex3f(-62.0, -35.0, 21.0);
    glVertex3f(-62.0, -47.0, 31.0);
    glVertex3f(-62.0, -45.0, 31.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.3, 0.0);
    glVertex3f(-60.0, -33.0, 21.0);
    glVertex3f(-60.0, -35.0, 21.0);
    glVertex3f(-60.0, -47.0, 31.0);
    glVertex3f(-60.0, -45.0, 31.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.3, 0.0);
    glVertex3f(-62.0, -33.0, 21.0);
    glVertex3f(-60.0, -35.0, 21.0);
    glVertex3f(-60.0, -45.0, 31.0);
    glVertex3f(-62.0, -45.0, 31.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.3, 0.0);
    glVertex3f(-62.0, -47.0, 31.0);
    glVertex3f(-60.0, -47.0, 31.0);
    glVertex3f(-60.0, -45.0, 31.0);
    glVertex3f(-62.0, -45.0, 31.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.3, 0.0);
    glVertex3f(-41.0, -33.0, 21.0);
    glVertex3f(-41.0, -35.0, 21.0);
    glVertex3f(-41.0, -47.0, 31.0);
    glVertex3f(-41.0, -45.0, 31.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.3, 0.0);
    glVertex3f(-43.0, -33.0, 21.0);
    glVertex3f(-43.0, -35.0, 21.0);
    glVertex3f(-43.0, -47.0, 31.0);
    glVertex3f(-43.0, -45.0, 31.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.0, 0.3, 0.0);
    glVertex3f(-43.0, -33.0, 21.0);
    glVertex3f(-41.0, -35.0, 21.0);
    glVertex3f(-41.0, -45.0, 31.0);
    glVertex3f(-43.0, -45.0, 31.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.3, 0.0);
    glVertex3f(-41.0, -47.0, 31.0);
    glVertex3f(-43.0, -47.0, 31.0);
    glVertex3f(-43.0, -45.0, 31.0);
    glVertex3f(-41.0, -45.0, 31.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.3, 0.0);
    glVertex3f(-62.0, -33.0, 21.0);
    glVertex3f(-41.0, -33.0, 21.0);
    glVertex3f(-41.0, -35.0, 21.0);
    glVertex3f(-62.0, -35.0, 21.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.3, 0.0);
    glVertex3f(-62.0, -35.0, 23.0);
    glVertex3f(-41.0, -35.0, 23.0);
    glVertex3f(-41.0, -37.0, 23.0);
    glVertex3f(-62.0, -37.0, 23.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.3, 0.0);
    glVertex3f(-62.0, -35.0, 23.0);
    glVertex3f(-41.0, -35.0, 23.0);
    glVertex3f(-41.0, -37.0, 23.0);
    glVertex3f(-62.0, -37.0, 23.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.3, 0.0);
    glVertex3f(-62.0, -35.0, 21.0);
    glVertex3f(-41.0, -35.0, 21.0);
    glVertex3f(-41.0, -37.0, 23.0);
    glVertex3f(-62.0, -37.0, 23.0);
    glEnd();


    //tanaman2
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.8, 0.0);
    glVertex3f(22.0, -35.0, 21.0);
    glVertex3f(-5.0, -35.0, 21.0);
    glVertex3f(-5.0, -47.0, 31.0);
    glVertex3f(22.0, -47.0, 31.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.3, 0.0);
    glVertex3f(-5.0, -33.0, 21.0);
    glVertex3f(-5.0, -35.0, 21.0);
    glVertex3f(-5.0, -47.0, 31.0);
    glVertex3f(-5.0, -45.0, 31.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.3, 0.0);
    glVertex3f(-3.0, -33.0, 21.0);
    glVertex3f(-3.0, -35.0, 21.0);
    glVertex3f(-3.0, -47.0, 31.0);
    glVertex3f(-3.0, -45.0, 31.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.3, 0.0);
    glVertex3f(-5.0, -33.0, 21.0);
    glVertex3f(-3.0, -33.0, 21.0);
    glVertex3f(-3.0, -45.0, 31.0);
    glVertex3f(-5.0, -45.0, 31.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.3, 0.0);
    glVertex3f(-5.0, -47.0, 31.0);
    glVertex3f(-3.0, -47.0, 31.0);
    glVertex3f(-3.0, -45.0, 31.0);
    glVertex3f(-5.0, -45.0, 31.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.3, 0.0);
    glVertex3f(20.0, -33.0, 21.0);
    glVertex3f(20.0, -35.0, 21.0);
    glVertex3f(20.0, -47.0, 31.0);
    glVertex3f(20.0, -45.0, 31.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.3, 0.0);
    glVertex3f(22.0, -33.0, 21.0);
    glVertex3f(22.0, -35.0, 21.0);
    glVertex3f(22.0, -47.0, 31.0);
    glVertex3f(22.0, -45.0, 31.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.3, 0.0);
    glVertex3f(20.0, -33.0, 21.0);
    glVertex3f(22.0, -33.0, 21.0);
    glVertex3f(22.0, -45.0, 31.0);
    glVertex3f(20.0, -45.0, 31.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.3, 0.0);
    glVertex3f(20.0, -47.0, 31.0);
    glVertex3f(22.0, -47.0, 31.0);
    glVertex3f(22.0, -45.0, 31.0);
    glVertex3f(20.0, -45.0, 31.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.3, 0.0);
    glVertex3f(-5.0, -35.0, 23.0);
    glVertex3f(22.0, -35.0, 23.0);
    glVertex3f(22.0, -37.0, 23.0);
    glVertex3f(-5.0, -37.0, 23.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.3, 0.0);
    glVertex3f(-5.0, -33.0, 21.0);
    glVertex3f(22.0, -33.0, 21.0);
    glVertex3f(22.0, -35.0, 21.0);
    glVertex3f(-5.0, -35.0, 21.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.3, 0.0);
    glVertex3f(-5.0, -35.0, 21.0);
    glVertex3f(22.0, -35.0, 21.0);
    glVertex3f(22.0, -37.0, 23.0);
    glVertex3f(-5.0, -37.0, 23.0);
    glEnd();

    //
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.0, 0.0);
    glVertex3f(-62.0, -47.0, 31.0);
    glVertex3f(100.0, -47.0, 31.0);
    glVertex3f(100.0, -47.0, -45.5);
    glVertex3f(-62.0, -47.0, -45.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3, 0.0, 0.0);
    glVertex3f(-62.0, -35.0, -45.5);
    glVertex3f(-62.0, -35.0, 21.0);
    glVertex3f(-62.0, -47.0, 31.0);
    glVertex3f(-62.0, -47.0, -45.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3, 0.0, 0.0);
    glVertex3f(100.0, -35.0, -45.5);
    glVertex3f(100.0, -35.0, 21.0);
    glVertex3f(100.0, -47.0, 31.0);
    glVertex3f(100.0, -47.0, -45.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3, 0.0, 0.0);
    glVertex3f(-62.0, -35.0, -45.5);
    glVertex3f(100.0, -35.0, -45.5);
    glVertex3f(100.0, -47.0, -45.5);
    glVertex3f(-62.0, -47.0, -45.5);
    glEnd();

    //terowongan
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(50.0, -35.0, -45.5);
    glVertex3f(50.0, -35.0, 21.0);
    glVertex3f(50.0, -47.0, 31.0);
    glVertex3f(50.0, -47.0, -45.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(62.0, -35.0, -45.5);
    glVertex3f(62.0, -35.0, 21.0);
    glVertex3f(62.0, -47.0, 31.0);
    glVertex3f(62.0, -47.0, -45.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8,0.8,0.8);
    glVertex3f(62.0, -35.0, 21.0);
    glVertex3f(50.0, -35.0, 21.0);
    glVertex3f(50.0, -40.0, 21.0);
    glVertex3f(62.0, -40.0, 21.0);
    glEnd();

}

void atap(){
    glBegin(GL_QUADS);
    ///depan
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-62.0, 40.0, 10.0);
    glVertex3f(-10.0, 40.0, 10.0);
    glVertex3f(-10.0, 40.0, 4.5);
    glVertex3f(-62.0, 40.0, 4.5);
    ///belakang
    glVertex3f(-62.0, 40.0, -45.5);
    glVertex3f(-10.0, 40.0, -45.5);
    glVertex3f(-10.0, 40.0, -40.0);
    glVertex3f(-62.0, 40.0, -40.0);
    ///kanan
    glVertex3f(-10.0, 40.0, -40.0);
    glVertex3f(-13.0, 40.0, -40.0);
    glVertex3f(-13.0, 40.0, 4.5);
    glVertex3f(-10.0, 40.0, 4.5);
    ///kiri
    glVertex3f(-62.0, 40.0, -40.0);
    glVertex3f(-59.0, 40.0, -40.0);
    glVertex3f(-59.0, 40.0, 4.5);
    glVertex3f(-62.0, 40.0, 4.5);

    ///depan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-59.0, 40.0, 4.5);
    glVertex3f(-59.0, 37.0, 4.5);
    glVertex3f(-13.0, 37.0, 4.5);
    glVertex3f(-13.0, 40.0, 4.5);
    ///belakang
    glVertex3f(-59.0, 40.0, -40.0);
    glVertex3f(-59.0, 37.0, -40.0);
    glVertex3f(-13.0, 37.0, -40.0);
    glVertex3f(-13.0, 40.0, -40.0);
    ///kanan
    glVertex3f(-13.0, 40.0, -40.0);
    glVertex3f(-13.0, 37.0, -40.0);
    glVertex3f(-13.0, 37.0, 4.5);
    glVertex3f(-13.0, 40.0, 4.5);
    ///kiri
    glVertex3f(-59.0, 40.0, -40.0);
    glVertex3f(-59.0, 37.0, -40.0);
    glVertex3f(-59.0, 37.0, 4.5);
    glVertex3f(-59.0, 40.0, 4.5);
    ///atas
    glColor3f(0.5f, 1.0f, 1.0f);
    glVertex3f(-59.0, 37.0, 4.5);
    glVertex3f(-13.0, 37.0, 4.5);
    glVertex3f(-13.0, 37.0, -40.0);
    glVertex3f(-59.0, 37.0, -40.0);

    ///menara
    glColor3f(1.0, 1.0, 1.0);
    ///depan
    glVertex3f(-50.0, 65.0, 0.0);
    glVertex3f(-50.0, -35.0, 0.0);
    glVertex3f(-40.0, -35.0, 0.0);
    glVertex3f(-40.0, 65.0, 0.0);
    ///kanan
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-40.0, 65.0, -10.0);
    glVertex3f(-40.0, -35.0, -10.0);
    glVertex3f(-40.0, -35.0, 0.0);
    glVertex3f(-40.0, 65.0, 0.0);
    ///belakang
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-50.0, 65.0, -10.0);
    glVertex3f(-50.0, -35.0, -10.0);
    glVertex3f(-40.0, -35.0, -10.0);
    glVertex3f(-40.0, 65.0, -10.0);
    ///kiri
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-50.0, 65.0, -10.0);
    glVertex3f(-50.0, -35.0, -10.0);
    glVertex3f(-50.0, -35.0, 0.0);
    glVertex3f(-50.0, 65.0, 0.0);
    ///atas
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-50.0, 65.0, -10.0);
    glVertex3f(-40.0, 65.0, -10.0);
    glVertex3f(-40.0, 65.0, 0.0);
    glVertex3f(-50.0, 65.0, 0.0);
    glEnd();
}

void gedungkanan(){
    ///gedungkecil
    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(50.0,15.0,10.0);
    glVertex3f(50.0,15.0,-45.0);
    glVertex3f(50.0,-35.0,-45.0);
    glVertex3f(50.0,-35.0,10.0);
    glEnd();
    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(100.0,15.0,-45.0);
    glVertex3f(50.0,15.0,-45.0);
    glVertex3f(50.0,-35.0,-45.0);
    glVertex3f(100.0,-35.0,-45.0);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(100.0,15.0,-45.0);
    glVertex3f(100.0,15.0,10.0);
    glVertex3f(100.0,-35.0,10.0);
    glVertex3f(100.0,-35.0,-45.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(65.0,15.0,10.0);
    glVertex3f(50.0,15.0,10.0);
    glVertex3f(50.0,-35.0,10.0);
    glVertex3f(65.0,-35.0,10.0);

    glVertex3f(65.0,15.0,10.0);
    glVertex3f(85.0,15.0,10.0);
    glVertex3f(85.0,0.0,10.0);
    glVertex3f(65.0,0.0,10.0);

    glVertex3f(85.0,15.0,10.0);
    glVertex3f(100.0,15.0,10.0);
    glVertex3f(100.0,-35.0,10.0);
    glVertex3f(85.0,-35.0,10.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(50.0,13.0,10.0);
    glVertex3f(50.0,13.0,-45.0);
    glVertex3f(100.0,13.0,-45.0);
    glVertex3f(100.0,13.0,10.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor3f(0.5f, 1.0f, 1.0f);
    glVertex3f(90.0,13.1,-5.0);
    glVertex3f(90.0,13.1,-25.0);
    glVertex3f(60.0,13.1,-25.0);
    glVertex3f(60.0,13.1,-5.0);
    glEnd();
}
void kaca(){
    //jendela depan
    glBegin(GL_QUADS);
    glColor3f(0.5f, 1.0f, 1.0f);
    glVertex3f(56.6,-23.0,10.1);
    glVertex3f(51.0,-23.0,10.1);
    glVertex3f(51.0,-33.0,10.1);
    glVertex3f(56.6,-33.0,10.1);

    glVertex3f(64.0,-23.0,10.1);
    glVertex3f(58.7,-23.0,10.1);
    glVertex3f(58.7,-33.0,10.1);
    glVertex3f(64.0,-33.0,10.1);

    glVertex3f(64.0,-22.0,10.1);
    glVertex3f(58.7,-22.0,10.1);
    glVertex3f(58.7,-12.0,10.1);
    glVertex3f(64.0,-12.0,10.1);

    glVertex3f(56.6,-22.0,10.1);
    glVertex3f(51.0,-22.0,10.1);
    glVertex3f(51.0,-12.0,10.1);
    glVertex3f(56.6,-12.0,10.1);

    glVertex3f(64.0,-11.0,10.1);
    glVertex3f(58.7,-11.0,10.1);
    glVertex3f(58.7,-1.0,10.1);
    glVertex3f(64.0,-1.0,10.1);

    glVertex3f(56.6,-11.0,10.1);
    glVertex3f(51.0,-11.0,10.1);
    glVertex3f(51.0,-1.0,10.1);
    glVertex3f(56.6,-1.0,10.1);

    glVertex3f(64.0,0.0,10.1);
    glVertex3f(58.7,0.0,10.1);
    glVertex3f(58.7,10.0,10.1);
    glVertex3f(64.0,10.0,10.1);

    glVertex3f(56.6,0.0,10.1);
    glVertex3f(51.0,0.0,10.1);
    glVertex3f(51.0,10.0,10.1);
    glVertex3f(56.6,10.0,10.1);

    glVertex3f(65.0,0.0,10.1);
    glVertex3f(70.3,0.0,10.1);
    glVertex3f(70.3,10.0,10.1);
    glVertex3f(65.0,10.0,10.1);

    glVertex3f(77.8,0.0,10.1);
    glVertex3f(72.3,0.0,10.1);
    glVertex3f(72.3,10.0,10.1);
    glVertex3f(77.8,10.0,10.1);
    //2
    glVertex3f(99.0,-23.0,10.1);
    glVertex3f(93.6,-23.0,10.1);
    glVertex3f(93.6,-33.0,10.1);
    glVertex3f(99.0,-33.0,10.1);

    glVertex3f(86.0,-23.0,10.1);
    glVertex3f(91.7,-23.0,10.1);
    glVertex3f(91.7,-33.0,10.1);
    glVertex3f(86.0,-33.0,10.1);

    glVertex3f(99.0,-22.0,10.1);
    glVertex3f(93.6,-22.0,10.1);
    glVertex3f(93.6,-12.0,10.1);
    glVertex3f(99.0,-12.0,10.1);

    glVertex3f(86.0,-22.0,10.1);
    glVertex3f(91.7,-22.0,10.1);
    glVertex3f(91.7,-12.0,10.1);
    glVertex3f(86.0,-12.0,10.1);

    glVertex3f(99.0,-11.0,10.1);
    glVertex3f(93.6,-11.0,10.1);
    glVertex3f(93.6,-1.0,10.1);
    glVertex3f(99.0,-1.0,10.1);

    glVertex3f(86.0,-11.0,10.1);
    glVertex3f(91.7,-11.0,10.1);
    glVertex3f(91.7,-1.0,10.1);
    glVertex3f(86.0,-1.0,10.1);

    glVertex3f(86.0,0.0,10.1);
    glVertex3f(91.7,0.0,10.1);
    glVertex3f(91.7,10.0,10.1);
    glVertex3f(86.0,10.0,10.1);

    glVertex3f(99.0,0.0,10.1);
    glVertex3f(93.7,0.0,10.1);
    glVertex3f(93.7,10.0,10.1);
    glVertex3f(99.0,10.0,10.1);

    glVertex3f(79.8,0.0,10.1);
    glVertex3f(85.0,0.0,10.1);
    glVertex3f(85.0,10.0,10.1);
    glVertex3f(79.8,10.0,10.1);
    //jendela kiri
    glVertex3f(49.9,-23.0,9.0);
    glVertex3f(49.9,-23.0,4.0);
    glVertex3f(49.9,-33.0,4.0);
    glVertex3f(49.9,-33.0,9.0);

    glVertex3f(49.9,-23.0,-2.0);
    glVertex3f(49.9,-23.0,3.0);
    glVertex3f(49.9,-33.0,3.0);
    glVertex3f(49.9,-33.0,-2.0);

    glVertex3f(49.9,-23.0,-3.0);
    glVertex3f(49.9,-23.0,-8.0);
    glVertex3f(49.9,-33.0,-8.0);
    glVertex3f(49.9,-33.0,-3.0);

    glVertex3f(49.9,-23.0,-14.0);
    glVertex3f(49.9,-23.0,-9.0);
    glVertex3f(49.9,-33.0,-9.0);
    glVertex3f(49.9,-33.0,-14.0);

    glVertex3f(49.9,-23.0,-15.0);
    glVertex3f(49.9,-23.0,-20.0);
    glVertex3f(49.9,-33.0,-20.0);
    glVertex3f(49.9,-33.0,-15.0);

    glVertex3f(49.9,-23.0,-26.0);
    glVertex3f(49.9,-23.0,-21.0);
    glVertex3f(49.9,-33.0,-21.0);
    glVertex3f(49.9,-33.0,-26.0);

    glVertex3f(49.9,-23.0,-27.0);
    glVertex3f(49.9,-23.0,-32.0);
    glVertex3f(49.9,-33.0,-32.0);
    glVertex3f(49.9,-33.0,-27.0);

    glVertex3f(49.9,-23.0,-38.0);
    glVertex3f(49.9,-23.0,-33.0);
    glVertex3f(49.9,-33.0,-33.0);
    glVertex3f(49.9,-33.0,-38.0);

    glVertex3f(49.9,-23.0,-39.0);
    glVertex3f(49.9,-23.0,-44.0);
    glVertex3f(49.9,-33.0,-44.0);
    glVertex3f(49.9,-33.0,-39.0);
    //
    glVertex3f(49.9,-22.0,9.0);
    glVertex3f(49.9,-22.0,4.0);
    glVertex3f(49.9,-12.0,4.0);
    glVertex3f(49.9,-12.0,9.0);

    glVertex3f(49.9,-22.0,-2.0);
    glVertex3f(49.9,-22.0,3.0);
    glVertex3f(49.9,-12.0,3.0);
    glVertex3f(49.9,-12.0,-2.0);

    glVertex3f(49.9,-22.0,-3.0);
    glVertex3f(49.9,-22.0,-8.0);
    glVertex3f(49.9,-12.0,-8.0);
    glVertex3f(49.9,-12.0,-3.0);

    glVertex3f(49.9,-22.0,-14.0);
    glVertex3f(49.9,-22.0,-9.0);
    glVertex3f(49.9,-12.0,-9.0);
    glVertex3f(49.9,-12.0,-14.0);

    glVertex3f(49.9,-22.0,-15.0);
    glVertex3f(49.9,-22.0,-20.0);
    glVertex3f(49.9,-12.0,-20.0);
    glVertex3f(49.9,-12.0,-15.0);

    glVertex3f(49.9,-22.0,-26.0);
    glVertex3f(49.9,-22.0,-21.0);
    glVertex3f(49.9,-12.0,-21.0);
    glVertex3f(49.9,-12.0,-26.0);

    glVertex3f(49.9,-22.0,-27.0);
    glVertex3f(49.9,-22.0,-32.0);
    glVertex3f(49.9,-12.0,-32.0);
    glVertex3f(49.9,-12.0,-27.0);

    glVertex3f(49.9,-22.0,-38.0);
    glVertex3f(49.9,-22.0,-33.0);
    glVertex3f(49.9,-12.0,-33.0);
    glVertex3f(49.9,-12.0,-38.0);

    glVertex3f(49.9,-22.0,-39.0);
    glVertex3f(49.9,-22.0,-44.0);
    glVertex3f(49.9,-12.0,-44.0);
    glVertex3f(49.9,-12.0,-39.0);
    //
    glVertex3f(49.9,-11.0,9.0);
    glVertex3f(49.9,-11.0,4.0);
    glVertex3f(49.9,-1.0,4.0);
    glVertex3f(49.9,-1.0,9.0);

    glVertex3f(49.9,-11.0,-2.0);
    glVertex3f(49.9,-11.0,3.0);
    glVertex3f(49.9,-1.0,3.0);
    glVertex3f(49.9,-1.0,-2.0);

    glVertex3f(49.9,-11.0,-3.0);
    glVertex3f(49.9,-11.0,-8.0);
    glVertex3f(49.9,-1.0,-8.0);
    glVertex3f(49.9,-1.0,-3.0);

    glVertex3f(49.9,-11.0,-14.0);
    glVertex3f(49.9,-11.0,-9.0);
    glVertex3f(49.9,-1.0,-9.0);
    glVertex3f(49.9,-1.0,-14.0);

    glVertex3f(49.9,-11.0,-15.0);
    glVertex3f(49.9,-11.0,-20.0);
    glVertex3f(49.9,-1.0,-20.0);
    glVertex3f(49.9,-1.0,-15.0);

    glVertex3f(49.9,-11.0,-26.0);
    glVertex3f(49.9,-11.0,-21.0);
    glVertex3f(49.9,-1.0,-21.0);
    glVertex3f(49.9,-1.0,-26.0);

    glVertex3f(49.9,-11.0,-27.0);
    glVertex3f(49.9,-11.0,-32.0);
    glVertex3f(49.9,-1.0,-32.0);
    glVertex3f(49.9,-1.0,-27.0);

    glVertex3f(49.9,-11.0,-38.0);
    glVertex3f(49.9,-11.0,-33.0);
    glVertex3f(49.9,-1.0,-33.0);
    glVertex3f(49.9,-1.0,-38.0);

    glVertex3f(49.9,-11.0,-39.0);
    glVertex3f(49.9,-11.0,-44.0);
    glVertex3f(49.9,-1.0,-44.0);
    glVertex3f(49.9,-1.0,-39.0);
    //
    glVertex3f(49.9,0.0,9.0);
    glVertex3f(49.9,0.0,4.0);
    glVertex3f(49.9,10.0,4.0);
    glVertex3f(49.9,10.0,9.0);

    glVertex3f(49.9,0.0,-2.0);
    glVertex3f(49.9,0.0,3.0);
    glVertex3f(49.9,10.0,3.0);
    glVertex3f(49.9,10.0,-2.0);

    glVertex3f(49.9,0.0,-3.0);
    glVertex3f(49.9,0.0,-8.0);
    glVertex3f(49.9,10.0,-8.0);
    glVertex3f(49.9,10.0,-3.0);

    glVertex3f(49.9,0.0,-14.0);
    glVertex3f(49.9,0.0,-9.0);
    glVertex3f(49.9,10.0,-9.0);
    glVertex3f(49.9,10.0,-14.0);

    glVertex3f(49.9,0.0,-15.0);
    glVertex3f(49.9,0.0,-20.0);
    glVertex3f(49.9,10.0,-20.0);
    glVertex3f(49.9,10.0,-15.0);

    glVertex3f(49.9,0.0,-26.0);
    glVertex3f(49.9,0.0,-21.0);
    glVertex3f(49.9,10.0,-21.0);
    glVertex3f(49.9,10.0,-26.0);

    glVertex3f(49.9,0.0,-27.0);
    glVertex3f(49.9,0.0,-32.0);
    glVertex3f(49.9,10.0,-32.0);
    glVertex3f(49.9,10.0,-27.0);

    glVertex3f(49.9,0.0,-38.0);
    glVertex3f(49.9,0.0,-33.0);
    glVertex3f(49.9,10.0,-33.0);
    glVertex3f(49.9,10.0,-38.0);

    glVertex3f(49.9,0.0,-39.0);
    glVertex3f(49.9,0.0,-44.0);
    glVertex3f(49.9,10.0,-44.0);
    glVertex3f(49.9,10.0,-39.0);
    //jendela kanan
    glVertex3f(100.1,-23.0,9.0);
    glVertex3f(100.1,-23.0,4.0);
    glVertex3f(100.1,-33.0,4.0);
    glVertex3f(100.1,-33.0,9.0);

    glVertex3f(100.1,-23.0,-2.0);
    glVertex3f(100.1,-23.0,3.0);
    glVertex3f(100.1,-33.0,3.0);
    glVertex3f(100.1,-33.0,-2.0);

    glVertex3f(100.1,-23.0,-3.0);
    glVertex3f(100.1,-23.0,-8.0);
    glVertex3f(100.1,-33.0,-8.0);
    glVertex3f(100.1,-33.0,-3.0);

    glVertex3f(100.1,-23.0,-14.0);
    glVertex3f(100.1,-23.0,-9.0);
    glVertex3f(100.1,-33.0,-9.0);
    glVertex3f(100.1,-33.0,-14.0);

    glVertex3f(100.1,-23.0,-15.0);
    glVertex3f(100.1,-23.0,-20.0);
    glVertex3f(100.1,-33.0,-20.0);
    glVertex3f(100.1,-33.0,-15.0);

    glVertex3f(100.1,-23.0,-26.0);
    glVertex3f(100.1,-23.0,-21.0);
    glVertex3f(100.1,-33.0,-21.0);
    glVertex3f(100.1,-33.0,-26.0);

    glVertex3f(100.1,-23.0,-27.0);
    glVertex3f(100.1,-23.0,-32.0);
    glVertex3f(100.1,-33.0,-32.0);
    glVertex3f(100.1,-33.0,-27.0);

    glVertex3f(100.1,-23.0,-38.0);
    glVertex3f(100.1,-23.0,-33.0);
    glVertex3f(100.1,-33.0,-33.0);
    glVertex3f(100.1,-33.0,-38.0);

    glVertex3f(100.1,-23.0,-39.0);
    glVertex3f(100.1,-23.0,-44.0);
    glVertex3f(100.1,-33.0,-44.0);
    glVertex3f(100.1,-33.0,-39.0);
    //
    glVertex3f(100.1,-22.0,9.0);
    glVertex3f(100.1,-22.0,4.0);
    glVertex3f(100.1,-12.0,4.0);
    glVertex3f(100.1,-12.0,9.0);

    glVertex3f(100.1,-22.0,-2.0);
    glVertex3f(100.1,-22.0,3.0);
    glVertex3f(100.1,-12.0,3.0);
    glVertex3f(100.1,-12.0,-2.0);

    glVertex3f(100.1,-22.0,-3.0);
    glVertex3f(100.1,-22.0,-8.0);
    glVertex3f(100.1,-12.0,-8.0);
    glVertex3f(100.1,-12.0,-3.0);

    glVertex3f(100.1,-22.0,-14.0);
    glVertex3f(100.1,-22.0,-9.0);
    glVertex3f(100.1,-12.0,-9.0);
    glVertex3f(100.1,-12.0,-14.0);

    glVertex3f(100.1,-22.0,-15.0);
    glVertex3f(100.1,-22.0,-20.0);
    glVertex3f(100.1,-12.0,-20.0);
    glVertex3f(100.1,-12.0,-15.0);

    glVertex3f(100.1,-22.0,-26.0);
    glVertex3f(100.1,-22.0,-21.0);
    glVertex3f(100.1,-12.0,-21.0);
    glVertex3f(100.1,-12.0,-26.0);

    glVertex3f(100.1,-22.0,-27.0);
    glVertex3f(100.1,-22.0,-32.0);
    glVertex3f(100.1,-12.0,-32.0);
    glVertex3f(100.1,-12.0,-27.0);

    glVertex3f(100.1,-22.0,-38.0);
    glVertex3f(100.1,-22.0,-33.0);
    glVertex3f(100.1,-12.0,-33.0);
    glVertex3f(100.1,-12.0,-38.0);

    glVertex3f(100.1,-22.0,-39.0);
    glVertex3f(100.1,-22.0,-44.0);
    glVertex3f(100.1,-12.0,-44.0);
    glVertex3f(100.1,-12.0,-39.0);
    //
    glVertex3f(100.1,-11.0,9.0);
    glVertex3f(100.1,-11.0,4.0);
    glVertex3f(100.1,-1.0,4.0);
    glVertex3f(100.1,-1.0,9.0);

    glVertex3f(100.1,-11.0,-2.0);
    glVertex3f(100.1,-11.0,3.0);
    glVertex3f(100.1,-1.0,3.0);
    glVertex3f(100.1,-1.0,-2.0);

    glVertex3f(100.1,-11.0,-3.0);
    glVertex3f(100.1,-11.0,-8.0);
    glVertex3f(100.1,-1.0,-8.0);
    glVertex3f(100.1,-1.0,-3.0);

    glVertex3f(100.1,-11.0,-14.0);
    glVertex3f(100.1,-11.0,-9.0);
    glVertex3f(100.1,-1.0,-9.0);
    glVertex3f(100.1,-1.0,-14.0);

    glVertex3f(100.1,-11.0,-15.0);
    glVertex3f(100.1,-11.0,-20.0);
    glVertex3f(100.1,-1.0,-20.0);
    glVertex3f(100.1,-1.0,-15.0);

    glVertex3f(100.1,-11.0,-26.0);
    glVertex3f(100.1,-11.0,-21.0);
    glVertex3f(100.1,-1.0,-21.0);
    glVertex3f(100.1,-1.0,-26.0);

    glVertex3f(100.1,-11.0,-27.0);
    glVertex3f(100.1,-11.0,-32.0);
    glVertex3f(100.1,-1.0,-32.0);
    glVertex3f(100.1,-1.0,-27.0);

    glVertex3f(100.1,-11.0,-38.0);
    glVertex3f(100.1,-11.0,-33.0);
    glVertex3f(100.1,-1.0,-33.0);
    glVertex3f(100.1,-1.0,-38.0);

    glVertex3f(100.1,-11.0,-39.0);
    glVertex3f(100.1,-11.0,-44.0);
    glVertex3f(100.1,-1.0,-44.0);
    glVertex3f(100.1,-1.0,-39.0);
    //
    glVertex3f(100.1,0.0,9.0);
    glVertex3f(100.1,0.0,4.0);
    glVertex3f(100.1,10.0,4.0);
    glVertex3f(100.1,10.0,9.0);

    glVertex3f(100.1,0.0,-2.0);
    glVertex3f(100.1,0.0,3.0);
    glVertex3f(100.1,10.0,3.0);
    glVertex3f(100.1,10.0,-2.0);

    glVertex3f(100.1,0.0,-3.0);
    glVertex3f(100.1,0.0,-8.0);
    glVertex3f(100.1,10.0,-8.0);
    glVertex3f(100.1,10.0,-3.0);

    glVertex3f(100.1,0.0,-14.0);
    glVertex3f(100.1,0.0,-9.0);
    glVertex3f(100.1,10.0,-9.0);
    glVertex3f(100.1,10.0,-14.0);

    glVertex3f(100.1,0.0,-15.0);
    glVertex3f(100.1,0.0,-20.0);
    glVertex3f(100.1,10.0,-20.0);
    glVertex3f(100.1,10.0,-15.0);

    glVertex3f(100.1,0.0,-26.0);
    glVertex3f(100.1,0.0,-21.0);
    glVertex3f(100.1,10.0,-21.0);
    glVertex3f(100.1,10.0,-26.0);

    glVertex3f(100.1,0.0,-27.0);
    glVertex3f(100.1,0.0,-32.0);
    glVertex3f(100.1,10.0,-32.0);
    glVertex3f(100.1,10.0,-27.0);

    glVertex3f(100.1,0.0,-38.0);
    glVertex3f(100.1,0.0,-33.0);
    glVertex3f(100.1,10.0,-33.0);
    glVertex3f(100.1,10.0,-38.0);

    glVertex3f(100.1,0.0,-39.0);
    glVertex3f(100.1,0.0,-44.0);
    glVertex3f(100.1,10.0,-44.0);
    glVertex3f(100.1,10.0,-39.0);
    glEnd();

}

void tugu (void)
{
    //kiri kanan
    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-44.0,-22.0,5.0);
    glVertex3f(-44.0,-22.0,20.0);
    glVertex3f(-44.0,-35.0,20.0);
    glVertex3f(-44.0,-35.0,5.0);
    glEnd();

    //atass
    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-44.0,-22.0,5.0);
    glVertex3f(50.0,-22.0,5.0);
    glVertex3f(50.0,-22.0,20.0);
    glVertex3f(-44.0,-22.0,20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(50.0,-22.0,10.0);
    glVertex3f(100.0,-22.0,10.0);
    glVertex3f(100.0,-22.0,20.0);
    glVertex3f(50.0,-22.0,20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(100.0,-22.0,20.0);
    glVertex3f(100.0,-22.0,10.0);
    glVertex3f(100.0,-25.0,10.0);
    glVertex3f(100.0,-25.0,20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(50.0,-25.0,10.0);
    glVertex3f(62.0,-25.0,10.0);
    glVertex3f(62.0,-25.0,20.0);
    glVertex3f(50.0,-25.0,20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-44.0,-22.0,20.0);
    glVertex3f(100.0,-22.0,20.0);
    glVertex3f(100.0,-25.0,20.0);
    glVertex3f(-44.0,-25.0,20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-44.0,-22.0,5.0);
    glVertex3f(50.0,-22.0,5.0);
    glVertex3f(50.0,-25.0,5.0);
    glVertex3f(-44.0,-25.0,5.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-41.0,-25.0,5.0);
    glVertex3f(-41.0,-25.0,20.0);
    glVertex3f(-41.0,-35.0,20.0);
    glVertex3f(-41.0,-35.0,5.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-41.0,-25.0,5.0);
    glVertex3f(50.0,-25.0,5.0);
    glVertex3f(50.0,-25.0,20.0);
    glVertex3f(-41.0,-25.0,20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-30.0,-25.0,5.0);
    glVertex3f(-30.0,-25.0,20.0);
    glVertex3f(-30.0,-35.0,20.0);
    glVertex3f(-30.0,-35.0,5.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-27.0,-25.0,5.0);
    glVertex3f(-27.0,-25.0,20.0);
    glVertex3f(-27.0,-35.0,20.0);
    glVertex3f(-27.0,-35.0,5.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-27.0,-25.0,5.0);
    glVertex3f(-27.0,-25.0,20.0);
    glVertex3f(-27.0,-35.0,20.0);
    glVertex3f(-27.0,-35.0,5.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-13.0,-25.0,18.0);
    glVertex3f(-13.0,-25.0,20.0);
    glVertex3f(-13.0,-35.0,20.0);
    glVertex3f(-13.0,-35.0,18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-10.0,-25.0,18.0);
    glVertex3f(-10.0,-25.0,20.0);
    glVertex3f(-10.0,-35.0,20.0);
    glVertex3f(-10.0,-35.0,18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(5.0,-25.0,18.0);
    glVertex3f(5.0,-25.0,20.0);
    glVertex3f(5.0,-35.0,20.0);
    glVertex3f(5.0,-35.0,18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(8.0,-25.0,18.0);
    glVertex3f(8.0,-25.0,20.0);
    glVertex3f(8.0,-35.0,20.0);
    glVertex3f(8.0,-35.0,18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(5.0,-25.0,8.0);
    glVertex3f(5.0,-25.0,10.0);
    glVertex3f(5.0,-35.0,10.0);
    glVertex3f(5.0,-35.0,8.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(8.0,-25.0,8.0);
    glVertex3f(8.0,-25.0,10.0);
    glVertex3f(8.0,-35.0,10.0);
    glVertex3f(8.0,-35.0,8.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(25.0,-25.0,8.0);
    glVertex3f(25.0,-25.0,10.0);
    glVertex3f(25.0,-35.0,10.0);
    glVertex3f(25.0,-35.0,8.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(27.0,-25.0,8.0);
    glVertex3f(27.0,-25.0,10.0);
    glVertex3f(27.0,-35.0,10.0);
    glVertex3f(27.0,-35.0,8.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(25.0,-25.0,18.0);
    glVertex3f(25.0,-25.0,20.0);
    glVertex3f(25.0,-35.0,20.0);
    glVertex3f(25.0,-35.0,18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(27.0,-25.0,18.0);
    glVertex3f(27.0,-25.0,20.0);
    glVertex3f(27.0,-35.0,20.0);
    glVertex3f(27.0,-35.0,18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(45.0,-25.0,8.0);
    glVertex3f(45.0,-25.0,10.0);
    glVertex3f(45.0,-35.0,10.0);
    glVertex3f(45.0,-35.0,8.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(47.0,-25.0,8.0);
    glVertex3f(47.0,-25.0,10.0);
    glVertex3f(47.0,-35.0,10.0);
    glVertex3f(47.0,-35.0,8.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(45.0,-25.0,18.0);
    glVertex3f(45.0,-25.0,20.0);
    glVertex3f(45.0,-35.0,20.0);
    glVertex3f(45.0,-35.0,18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(47.0,-25.0,18.0);
    glVertex3f(47.0,-25.0,20.0);
    glVertex3f(47.0,-35.0,20.0);
    glVertex3f(47.0,-35.0,18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(63.0,-25.0,18.0);
    glVertex3f(63.0,-25.0,20.0);
    glVertex3f(63.0,-35.0,20.0);
    glVertex3f(63.0,-35.0,18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(65.0,-25.0,18.0);
    glVertex3f(65.0,-25.0,20.0);
    glVertex3f(65.0,-35.0,20.0);
    glVertex3f(65.0,-35.0,18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(85.0,-25.0,18.0);
    glVertex3f(85.0,-25.0,20.0);
    glVertex3f(85.0,-35.0,20.0);
    glVertex3f(85.0,-35.0,18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(87.0,-25.0,18.0);
    glVertex3f(87.0,-25.0,20.0);
    glVertex3f(87.0,-35.0,20.0);
    glVertex3f(87.0,-35.0,18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(85.0,-25.0,20.0);
    glVertex3f(87.0,-25.0,20.0);
    glVertex3f(87.0,-35.0,20.0);
    glVertex3f(85.0,-35.0,20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(98.0,-25.0,18.0);
    glVertex3f(98.0,-25.0,20.0);
    glVertex3f(98.0,-35.0,20.0);
    glVertex3f(98.0,-35.0,18.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(100.0,-25.0,18.0);
    glVertex3f(100.0,-25.0,20.0);
    glVertex3f(100.0,-35.0,20.0);
    glVertex3f(100.0,-35.0,18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(98.0,-25.0,20.0);
    glVertex3f(100.0,-25.0,20.0);
    glVertex3f(100.0,-35.0,20.0);
    glVertex3f(98.0,-35.0,20.0);
    glEnd();

    //depan
    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-44.0,-22.0,20.0);
    glVertex3f(-41.0,-22.0,20.0);
    glVertex3f(-41.0,-35.0,20.0);
    glVertex3f(-44.0,-35.0,20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-30.0,-25.0,20.0);
    glVertex3f(-27.0,-25.0,20.0);
    glVertex3f(-27.0,-35.0,20.0);
    glVertex3f(-30.0,-35.0,20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-44.0,-25.0,20.0);
    glVertex3f(-41.0,-25.0,20.0);
    glVertex3f(-41.0,-35.0,20.0);
    glVertex3f(-44.0,-35.0,20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-13.0,-25.0,20.0);
    glVertex3f(-10.0,-25.0,20.0);
    glVertex3f(-10.0,-35.0,20.0);
    glVertex3f(-13.0,-35.0,20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(8.0,-25.0,20.0);
    glVertex3f(5.0,-25.0,20.0);
    glVertex3f(5.0,-35.0,20.0);
    glVertex3f(8.0,-35.0,20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(27.0,-25.0,20.0);
    glVertex3f(25.0,-25.0,20.0);
    glVertex3f(25.0,-35.0,20.0);
    glVertex3f(27.0,-35.0,20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(47.0,-25.0,20.0);
    glVertex3f(45.0,-25.0,20.0);
    glVertex3f(45.0,-35.0,20.0);
    glVertex3f(47.0,-35.0,20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(65.0,-25.0,20.0);
    glVertex3f(63.0,-25.0,20.0);
    glVertex3f(63.0,-35.0,20.0);
    glVertex3f(65.0,-35.0,20.0);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(8.0,-25.0,10.0);
    glVertex3f(5.0,-25.0,10.0);
    glVertex3f(5.0,-35.0,10.0);
    glVertex3f(8.0,-35.0,10.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(8.0,-25.0,8.0);
    glVertex3f(5.0,-25.0,8.0);
    glVertex3f(5.0,-35.0,8.0);
    glVertex3f(8.0,-35.0,8.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(27.0,-25.0,10.0);
    glVertex3f(25.0,-25.0,10.0);
    glVertex3f(25.0,-35.0,10.0);
    glVertex3f(27.0,-35.0,10.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(27.0,-25.0,8.0);
    glVertex3f(25.0,-25.0,8.0);
    glVertex3f(25.0,-35.0,8.0);
    glVertex3f(27.0,-35.0,8.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(47.0,-25.0,10.0);
    glVertex3f(45.0,-25.0,10.0);
    glVertex3f(45.0,-35.0,10.0);
    glVertex3f(47.0,-35.0,10.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(47.0,-25.0,8.0);
    glVertex3f(45.0,-25.0,8.0);
    glVertex3f(45.0,-35.0,8.0);
    glVertex3f(47.0,-35.0,8.0);
    glEnd();



}

void tangga (void)
{

    //tangga1
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.1);
    glVertex3f(22.0, -35.0, 21.0);
    glVertex3f(50.0, -35.0, 21.0);
    glVertex3f(50.0, -37.0, 21.0);
    glVertex3f(22.0, -37.0, 21.0);
    glEnd();

    //*
    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(22.0, -37.0, 21.0);
    glVertex3f(50.0, -37.0, 21.0);
    glVertex3f(50.0, -37.0, 23.0);
    glVertex3f(22.0, -37.0, 23.0);
    glEnd();

    //2
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.1);
    glVertex3f(22.0, -37.0, 23.0);
    glVertex3f(50.0, -37.0, 23.0);
    glVertex3f(50.0, -39.0, 23.0);
    glVertex3f(22.0, -39.0, 23.0);
    glEnd();

    //*
    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(22.0, -39.0, 23.0);
    glVertex3f(50.0, -39.0, 23.0);
    glVertex3f(50.0, -39.0, 25.0);
    glVertex3f(22.0, -39.0, 25.0);
    glEnd();

    //3
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.1);
    glVertex3f(22.0, -39.0, 25.0);
    glVertex3f(50.0, -39.0, 25.0);
    glVertex3f(50.0, -41.0, 25.0);
    glVertex3f(22.0, -41.0, 25.0);
    glEnd();

    //*
    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(22.0, -41.0, 25.0);
    glVertex3f(50.0, -41.0, 25.0);
    glVertex3f(50.0, -41.0, 27.0);
    glVertex3f(22.0, -41.0, 27.0);
    glEnd();

    //4
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.1);
    glVertex3f(22.0, -41.0, 27.0);
    glVertex3f(50.0, -41.0, 27.0);
    glVertex3f(50.0, -43.0, 27.0);
    glVertex3f(22.0, -43.0, 27.0);
    glEnd();

    //*
    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(22.0, -43.0, 27.0);
    glVertex3f(50.0, -43.0, 27.0);
    glVertex3f(50.0, -43.0, 29.0);
    glVertex3f(22.0, -43.0, 29.0);
    glEnd();

    //5
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.1);
    glVertex3f(22.0, -43.0, 29.0);
    glVertex3f(50.0, -43.0, 29.0);
    glVertex3f(50.0, -45.0, 29.0);
    glVertex3f(22.0, -45.0, 29.0);
    glEnd();

    //*
    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(22.0, -45.0, 29.0);
    glVertex3f(50.0, -45.0, 29.0);
    glVertex3f(50.0, -45.0, 31.0);
    glVertex3f(22.0, -45.0, 31.0);
    glEnd();

    //6
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.1);
    glVertex3f(22.0, -45.0, 31.0);
    glVertex3f(50.0, -45.0, 31.0);
    glVertex3f(50.0, -47.0, 31.0);
    glVertex3f(22.0, -47.0, 31.0);
    glEnd();

    //tangga2

    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.1);
    glVertex3f(-41.0, -35.0, 21.0);
    glVertex3f(-5.0, -35.0, 21.0);
    glVertex3f(-5.0, -37.0, 21.0);
    glVertex3f(-41.0, -37.0, 21.0);
    glEnd();

    //*
    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-41.0, -37.0, 21.0);
    glVertex3f(-5.0, -37.0, 21.0);
    glVertex3f(-5.0, -37.0, 23.0);
    glVertex3f(-41.0, -37.0, 23.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.1);
    glVertex3f(-41.0, -37.0, 23.0);
    glVertex3f(-5.0, -37.0, 23.0);
    glVertex3f(-5.0, -39.0, 23.0);
    glVertex3f(-41.0, -39.0, 23.0);
    glEnd();

    //*
    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-41.0, -39.0, 23.0);
    glVertex3f(-5.0, -39.0, 23.0);
    glVertex3f(-5.0, -39.0, 25.0);
    glVertex3f(-41.0, -39.0, 25.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.1);
    glVertex3f(-41.0, -39.0, 25.0);
    glVertex3f(-5.0, -39.0, 25.0);
    glVertex3f(-5.0, -41.0, 25.0);
    glVertex3f(-41.0, -41.0, 25.0);
    glEnd();

    //*
    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-41.0, -41.0, 25.0);
    glVertex3f(-5.0, -41.0, 25.0);
    glVertex3f(-5.0, -41.0, 27.0);
    glVertex3f(-41.0, -41.0, 27.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.1);
    glVertex3f(-41.0, -41.0, 27.0);
    glVertex3f(-5.0, -41.0, 27.0);
    glVertex3f(-5.0, -43.0, 27.0);
    glVertex3f(-41.0, -43.0, 27.0);
    glEnd();

    //*
    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-41.0, -43.0, 27.0);
    glVertex3f(-5.0, -43.0, 27.0);
    glVertex3f(-5.0, -43.0, 29.0);
    glVertex3f(-41.0, -43.0, 29.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.1);
    glVertex3f(-41.0, -43.0, 29.0);
    glVertex3f(-5.0, -43.0, 29.0);
    glVertex3f(-5.0, -45.0, 29.0);
    glVertex3f(-41.0, -45.0, 29.0);
    glEnd();

    //*
    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-41.0, -45.0, 29.0);
    glVertex3f(-5.0, -45.0, 29.0);
    glVertex3f(-5.0, -45.0, 31.0);
    glVertex3f(-41.0, -45.0, 31.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.1);
    glVertex3f(-41.0, -45.0, 31.0);
    glVertex3f(-5.0, -45.0, 31.0);
    glVertex3f(-5.0, -47.0, 31.0);
    glVertex3f(-41.0, -47.0, 31.0);
    glEnd();

    //tangga3
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.1);
    glVertex3f(62.0, -35.0, 21.0);
    glVertex3f(100.0, -35.0, 21.0);
    glVertex3f(100.0, -37.0, 21.0);
    glVertex3f(62.0, -37.0, 21.0);
    glEnd();

    //*
    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(62.0, -37.0, 21.0);
    glVertex3f(100.0, -37.0, 21.0);
    glVertex3f(100.0, -37.0, 23.0);
    glVertex3f(62.0, -37.0, 23.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.1);
    glVertex3f(62.0, -37.0, 23.0);
    glVertex3f(100.0, -37.0, 23.0);
    glVertex3f(100.0, -39.0, 23.0);
    glVertex3f(62.0, -39.0, 23.0);
    glEnd();

    //*
    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(62.0, -39.0, 23.0);
    glVertex3f(100.0, -39.0, 23.0);
    glVertex3f(100.0, -39.0, 25.0);
    glVertex3f(62.0, -39.0, 25.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.1);
    glVertex3f(62.0, -39.0, 25.0);
    glVertex3f(100.0, -39.0, 25.0);
    glVertex3f(100.0, -41.0, 25.0);
    glVertex3f(62.0, -41.0, 25.0);
    glEnd();

    //*
    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(62.0, -41.0, 25.0);
    glVertex3f(100.0, -41.0, 25.0);
    glVertex3f(100.0, -41.0, 27.0);
    glVertex3f(62.0, -41.0, 27.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.1);
    glVertex3f(62.0, -41.0, 27.0);
    glVertex3f(100.0, -41.0, 27.0);
    glVertex3f(100.0, -43.0, 27.0);
    glVertex3f(62.0, -43.0, 27.0);
    glEnd();

    //*
    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(62.0, -43.0, 27.0);
    glVertex3f(100.0, -43.0, 27.0);
    glVertex3f(100.0, -43.0, 29.0);
    glVertex3f(62.0, -43.0, 29.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.1);
    glVertex3f(62.0, -43.0, 29.0);
    glVertex3f(100.0, -43.0, 29.0);
    glVertex3f(100.0, -45.0, 29.0);
    glVertex3f(62.0, -45.0, 29.0);
    glEnd();

    //*
    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(62.0, -45.0, 29.0);
    glVertex3f(100.0, -45.0, 29.0);
    glVertex3f(100.0, -45.0, 31.0);
    glVertex3f(62.0, -45.0, 31.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.1);
    glVertex3f(62.0, -45.0, 31.0);
    glVertex3f(100.0, -45.0, 31.0);
    glVertex3f(100.0, -47.0, 31.0);
    glVertex3f(62.0, -47.0, 31.0);
    glEnd();
}

void objek(){
    ///layar pengumuman
    glBegin(GL_QUADS);
    if (pattern1) {
		glColor3fv(pink);
	}
	if (pattern2) {
		glColor3fv(biru);
	}
    glVertex3f(46.0, -5.0, 13.0);
    glVertex3f(67.0, -5.0, 13.0);
    glVertex3f(67.0, 17.0, 15.0);
    glVertex3f(46.0, 17.0, 15.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(46.0, -5.0, 11.0);
    glVertex3f(67.0, -5.0, 11.0);
    glVertex3f(67.0, 17.0, 13.0);
    glVertex3f(46.0, 17.0, 13.0);

    glVertex3f(46.0, 17.0, 15.0);
    glVertex3f(67.0, 17.0, 15.0);
    glVertex3f(67.0, 17.0, 13.0);
    glVertex3f(46.0, 17.0, 13.0);

    glVertex3f(46.0, -5.0, 11.0);
    glVertex3f(67.0, -5.0, 11.0);
    glVertex3f(67.0, -5.0, 13.0);
    glVertex3f(46.0, -5.0, 13.0);

    glVertex3f(46.0, -5.0, 11.0);
    glVertex3f(46.0, -5.0, 13.0);
    glVertex3f(46.0, 17.0, 15.0);
    glVertex3f(46.0, 17.0, 13.0);

    glVertex3f(67.0, -5.0, 11.0);
    glVertex3f(67.0, -5.0, 13.0);
    glVertex3f(67.0, 17.0, 15.0);
    glVertex3f(67.0, 17.0, 13.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(57.0, 3.0, 11.0);
    glVertex3f(59.0, 3.0, 11.0);
    glVertex3f(59.0, 5.0, 13.0);
    glVertex3f(57.0, 5.0, 13.0);

    glVertex3f(57.0, 3.0, 10.0);
    glVertex3f(59.0, 3.0, 10.0);
    glVertex3f(59.0, 5.0, 10.0);
    glVertex3f(57.0, 5.0, 10.0);

    glVertex3f(57.0, 3.0, 10.0);
    glVertex3f(59.0, 3.0, 10.0);
    glVertex3f(59.0, 3.0, 11.0);
    glVertex3f(57.0, 3.0, 11.0);

    glVertex3f(57.0, 5.0, 10.0);
    glVertex3f(59.0, 5.0, 10.0);
    glVertex3f(59.0, 5.0, 13.0);
    glVertex3f(57.0, 5.0, 13.0);
    glEnd();
    
    ///rakbuku
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.0f, 0.0f);
    ///belakang
    glVertex3f(98.0, 0.0,-15.0);
    glVertex3f(98.5, 0.0, 5.0);
    glVertex3f(98.5,-35.0,5.0);
    glVertex3f(98.0,-35.0,-15.0);

    ///depan
    glVertex3f(90.0, -27.0,-15.0);
    glVertex3f(90.5, -27.0, 5.0);
    glVertex3f(90.5, -35.0,5.0);
    glVertex3f(90.0, -35.0,-15.0);

    ///batas
    glVertex3f(90.0, -35.0, -15.0);
    glVertex3f(90.0, -35.0, 5.0);
    glVertex3f(98.0, -35.0, 5.5);
    glVertex3f(98.0, -35.0, -15.5);

    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(90.0, -27.0, -15.0);
    glVertex3f(90.0, -27.0, 5.0);
    glVertex3f(98.0, -27.0, 5.5);
    glVertex3f(98.0, -27.0, -15.5);

    glVertex3f(94.0, -20.0, -15.0);
    glVertex3f(94.0, -20.0, 5.0);
    glVertex3f(98.0, -20.0, 5.5);
    glVertex3f(98.0, -20.0, -15.5);

    glVertex3f(94.0, -10.0, -15.0);
    glVertex3f(94.0, -10.0, 5.0);
    glVertex3f(98.0, -10.0, 5.5);
    glVertex3f(98.0, -10.0, -15.5);

    glColor3f(0.1f, 0.0f, 0.0f);
    ///atas
    glVertex3f(94.0, 0.0, -15.0);
    glVertex3f(94.0, 0.0, 5.0);
    glVertex3f(98.0, 0.0, 5.5);
    glVertex3f(98.0, 0.0, -15.5);

    ///kiri
    glVertex3f(98.0, 0.0, -15.0);
    glVertex3f(94.5, 0.0, -15.0);
    glVertex3f(94.5,-35.0, -15.0);
    glVertex3f(98.0,-35.0, -15.0);

    ///kanan
    glVertex3f(98.0, 0.0, 5.0);
    glVertex3f(94.5, 0.0, 5.0);
    glVertex3f(94.5,-35.0, 5.0);
    glVertex3f(98.0,-35.0, 5.0);

    ///
    glVertex3f(90.0, -27.0, 5.0);
    glVertex3f(94.5, -27.0, 5.0);
    glVertex3f(94.5,-35.0, 5.0);
    glVertex3f(90.0,-35.0, 5.0);

    glVertex3f(90.0, -27.0, -15.0);
    glVertex3f(94.5, -27.0, -15.0);
    glVertex3f(94.5,-35.0, -15.0);
    glVertex3f(90.0,-35.0, -15.0);
    glEnd();
    
    ///papan tulis
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(70.0, 0.0, -40.0);
    glVertex3f(87.0, 0.0, -40.0);
    glVertex3f(87.0, -17.0, -40.0);
    glVertex3f(70.0, -17.0, -40.0);

    glColor3f(0.0,0.0,0.0);
    glVertex3f(70.0, 0.0, -40.0);
    glVertex3f(87.0, 0.0, -40.0);
    glVertex3f(87.0, 1.0, -40.0);
    glVertex3f(70.0, 1.0, -40.0);

    glVertex3f(70.0, 1.0, -40.0);
    glVertex3f(71.0, 1.0, -40.0);
    glVertex3f(71.0, -34.0, -40.0);
    glVertex3f(70.0, -34.0, -40.0);

    glVertex3f(87.0, 1.0, -40.0);
    glVertex3f(88.0, 1.0, -40.0);
    glVertex3f(88.0, -34.0, -40.0);
    glVertex3f(87.0, -34.0, -40.0);

    glVertex3f(70.0, -17.0, -40.0);
    glVertex3f(87.0, -17.0, -40.0);
    glVertex3f(87.0, -18.0, -40.0);
    glVertex3f(70.0, -18.0, -40.0);

    ///kiri
    glVertex3f(70.0, -34.0, -42.0);
    glVertex3f(71.0, -34.0, -42.0);
    glVertex3f(71.0, -34.0, -38.0);
    glVertex3f(70.0, -34.0, -38.0);

    glVertex3f(70.0, -35.0, -42.0);
    glVertex3f(71.0, -35.0, -42.0);
    glVertex3f(71.0, -35.0, -38.0);
    glVertex3f(70.0, -35.0, -38.0);

    glVertex3f(70.0, -35.0, -38.0);
    glVertex3f(71.0, -35.0, -38.0);
    glVertex3f(71.0, -34.0, -38.0);
    glVertex3f(70.0, -34.0, -38.0);

    glVertex3f(70.0, -35.0, -42.0);
    glVertex3f(71.0, -35.0, -42.0);
    glVertex3f(71.0, -34.0, -42.0);
    glVertex3f(70.0, -34.0, -42.0);

    ///kanan
    glVertex3f(87.0, -34.0, -42.0);
    glVertex3f(88.0, -34.0, -42.0);
    glVertex3f(88.0, -34.0, -38.0);
    glVertex3f(87.0, -34.0, -38.0);

    glVertex3f(87.0, -35.0, -42.0);
    glVertex3f(88.0, -35.0, -42.0);
    glVertex3f(88.0, -35.0, -38.0);
    glVertex3f(87.0, -35.0, -38.0);

    glVertex3f(87.0, -35.0, -38.0);
    glVertex3f(88.0, -35.0, -38.0);
    glVertex3f(88.0, -34.0, -38.0);
    glVertex3f(87.0, -34.0, -38.0);

    glVertex3f(87.0, -35.0, -42.0);
    glVertex3f(88.0, -35.0, -42.0);
    glVertex3f(88.0, -34.0, -42.0);
    glVertex3f(87.0, -34.0, -42.0);
    glEnd();
    
    //meja
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(67.0,-29.1,-24.0);
    glVertex3f(67.0,-29.0,-25.0);
    glVertex3f(67.0,-35.1,-25.0);
    glVertex3f(67.0,-35.1,-24.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(69.0,-29.1,-24.0);
    glVertex3f(69.0,-29.0,-25.0);
    glVertex3f(69.0,-35.1,-25.0);
    glVertex3f(69.0,-35.1,-24.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(67.0,-29.1,-24.0);
    glVertex3f(69.0,-29.0,-24.0);
    glVertex3f(69.0,-35.1,-24.0);
    glVertex3f(67.0,-35.1,-24.0);
    glEnd();

    //meja
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(67.0,-29.1,-29.0);
    glVertex3f(67.0,-29.0,-30.0);
    glVertex3f(67.0,-35.1,-30.0);
    glVertex3f(67.0,-35.1,-29.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(69.0,-29.1,-29.0);
    glVertex3f(69.0,-29.0,-30.0);
    glVertex3f(69.0,-35.1,-30.0);
    glVertex3f(69.0,-35.1,-29.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(67.0,-29.1,-29.0);
    glVertex3f(69.0,-29.0,-29.0);
    glVertex3f(69.0,-35.1,-29.0);
    glVertex3f(67.0,-35.1,-29.0);
    glEnd();

    //meja
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(90.0,-29.1,-24.0);
    glVertex3f(90.0,-29.0,-25.0);
    glVertex3f(90.0,-35.1,-25.0);
    glVertex3f(90.0,-35.1,-24.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(88.0,-29.1,-24.0);
    glVertex3f(88.0,-29.0,-25.0);
    glVertex3f(88.0,-35.1,-25.0);
    glVertex3f(88.0,-35.1,-24.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(88.0,-29.1,-24.0);
    glVertex3f(90.0,-29.0,-24.0);
    glVertex3f(90.0,-35.1,-24.0);
    glVertex3f(88.0,-35.1,-24.0);
    glEnd();

    //meja
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(90.0,-29.1,-29.0);
    glVertex3f(90.0,-29.0,-30.0);
    glVertex3f(90.0,-35.1,-30.0);
    glVertex3f(90.0,-35.1,-29.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(88.0,-29.1,-29.0);
    glVertex3f(88.0,-29.0,-30.0);
    glVertex3f(88.0,-35.1,-30.0);
    glVertex3f(88.0,-35.1,-29.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(88.0,-29.1,-29.0);
    glVertex3f(90.0,-29.0,-29.0);
    glVertex3f(90.0,-35.1,-29.0);
    glVertex3f(88.0,-35.1,-29.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(67.0,-29.1,-30.0);
    glVertex3f(90.0,-29.0,-30.0);
    glVertex3f(90.0,-29.1,-24.0);
    glVertex3f(67.0,-29.1,-24.0);
    glEnd();

    //kursi1
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(70.0,-31.1,-22.0);
    glVertex3f(70.0,-31.0,-23.0);
    glVertex3f(70.0,-35.1,-23.0);
    glVertex3f(70.0,-35.1,-22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(70.5,-31.1,-22.0);
    glVertex3f(70.5,-31.0,-23.0);
    glVertex3f(70.5,-35.1,-23.0);
    glVertex3f(70.5,-35.1,-22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(70.0,-31.1,-22.0);
    glVertex3f(70.5,-31.0,-22.0);
    glVertex3f(70.5,-35.1,-22.0);
    glVertex3f(70.0,-35.1,-22.0);
    glEnd();

    //
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(75.0,-31.1,-22.0);
    glVertex3f(75.0,-31.0,-23.0);
    glVertex3f(75.0,-35.1,-23.0);
    glVertex3f(75.0,-35.1,-22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(75.5,-31.1,-22.0);
    glVertex3f(75.5,-31.0,-23.0);
    glVertex3f(75.5,-35.1,-23.0);
    glVertex3f(75.5,-35.1,-22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(75.0,-31.1,-22.0);
    glVertex3f(75.5,-31.0,-22.0);
    glVertex3f(75.5,-35.1,-22.0);
    glVertex3f(75.0,-35.1,-22.0);
    glEnd();

    //
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(70.0,-23.0,-17.0);
    glVertex3f(70.0,-23.0,-18.0);
    glVertex3f(70.0,-35.0,-18.0);
    glVertex3f(70.0,-35.0,-17.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(70.5,-23.0,-17.0);
    glVertex3f(70.5,-23.0,-18.0);
    glVertex3f(70.5,-35.0,-18.0);
    glVertex3f(70.5,-35.0,-17.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(70.0,-23.0,-17.0);
    glVertex3f(70.5,-23.0,-18.0);
    glVertex3f(70.5,-35.0,-18.0);
    glVertex3f(70.0,-35.0,-17.0);
    glEnd();

    //
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(75.0,-23.1,-17.0);
    glVertex3f(75.0,-23.0,-18.0);
    glVertex3f(75.0,-35.1,-18.0);
    glVertex3f(75.0,-35.1,-17.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(75.5,-23.1,-17.0);
    glVertex3f(75.5,-23.0,-18.0);
    glVertex3f(75.5,-35.1,-18.0);
    glVertex3f(75.5,-35.1,-17.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(75.0,-23.1,-17.0);
    glVertex3f(75.5,-23.0,-18.0);
    glVertex3f(75.5,-35.1,-18.0);
    glVertex3f(75.0,-35.1,-17.0);
    glEnd();

    //
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(70.0,-31.1,-23.0);
    glVertex3f(75.5,-31.0,-23.0);
    glVertex3f(75.5,-31.1,-16.0);
    glVertex3f(70.0,-31.1,-16.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(69.0,-22.1,-17.0);
    glVertex3f(76.5,-22.0,-17.0);
    glVertex3f(76.5,-26.0,-17.0);
    glVertex3f(69.0,-26.0,-17.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(69.0,-22.1,-18.0);
    glVertex3f(76.5,-22.0,-18.0);
    glVertex3f(76.5,-26.0,-18.0);
    glVertex3f(69.0,-26.0,-18.0);
    glEnd();

    //kursi2
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(80.0,-31.1,-22.0);
    glVertex3f(80.0,-31.0,-23.0);
    glVertex3f(80.0,-35.1,-23.0);
    glVertex3f(80.0,-35.1,-22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(80.5,-31.1,-22.0);
    glVertex3f(80.5,-31.0,-23.0);
    glVertex3f(80.5,-35.1,-23.0);
    glVertex3f(80.5,-35.1,-22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(80.0,-31.1,-22.0);
    glVertex3f(80.5,-31.0,-22.0);
    glVertex3f(80.5,-35.1,-22.0);
    glVertex3f(80.0,-35.1,-22.0);
    glEnd();

    //
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(85.0,-31.1,-22.0);
    glVertex3f(85.0,-31.0,-23.0);
    glVertex3f(85.0,-35.1,-23.0);
    glVertex3f(85.0,-35.1,-22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(85.5,-31.1,-22.0);
    glVertex3f(85.5,-31.0,-23.0);
    glVertex3f(85.5,-35.1,-23.0);
    glVertex3f(85.5,-35.1,-22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(85.0,-31.1,-22.0);
    glVertex3f(85.5,-31.0,-22.0);
    glVertex3f(85.5,-35.1,-22.0);
    glVertex3f(85.0,-35.1,-22.0);
    glEnd();

    //
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(80.0,-23.0,-17.0);
    glVertex3f(80.0,-23.0,-18.0);
    glVertex3f(80.0,-35.0,-18.0);
    glVertex3f(80.0,-35.0,-17.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(80.5,-23.0,-17.0);
    glVertex3f(80.5,-23.0,-18.0);
    glVertex3f(80.5,-35.0,-18.0);
    glVertex3f(80.5,-35.0,-17.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(80.0,-23.0,-17.0);
    glVertex3f(80.5,-23.0,-18.0);
    glVertex3f(80.5,-35.0,-18.0);
    glVertex3f(80.0,-35.0,-17.0);
    glEnd();

    //
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(85.0,-23.1,-17.0);
    glVertex3f(85.0,-23.0,-18.0);
    glVertex3f(85.0,-35.1,-18.0);
    glVertex3f(85.0,-35.1,-17.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(85.5,-23.1,-17.0);
    glVertex3f(85.5,-23.0,-18.0);
    glVertex3f(85.5,-35.1,-18.0);
    glVertex3f(85.5,-35.1,-17.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(85.0,-23.1,-17.0);
    glVertex3f(85.5,-23.0,-18.0);
    glVertex3f(85.5,-35.1,-18.0);
    glVertex3f(85.0,-35.1,-17.0);
    glEnd();

    //
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(80.0,-31.1,-23.0);
    glVertex3f(85.5,-31.0,-23.0);
    glVertex3f(85.5,-31.1,-16.0);
    glVertex3f(80.0,-31.1,-16.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(79.0,-22.1,-17.0);
    glVertex3f(86.5,-22.0,-17.0);
    glVertex3f(86.5,-26.0,-17.0);
    glVertex3f(79.0,-26.0,-17.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3f(79.0,-22.1,-18.0);
    glVertex3f(86.5,-22.0,-18.0);
    glVertex3f(86.5,-26.0,-18.0);
    glVertex3f(79.0,-26.0,-18.0);
    glEnd();
}

void hasil(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
    if(is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
    glClear(GL_COLOR_BUFFER_BIT);

    depan();
    garisdepan();
    sampingkanan();
    belakang();
    sampingkiri();
    belakangbawah();
    gedungdalam();
    atap();
    kaca();
    gedungkanan();
    lantai();
    objek();
    tugu();
    tangga();

    
    glPopMatrix();
    glutSwapBuffers();
}

void idle(){
if(!mouseDown){
    xrot += 0.3f;
    yrot += 0.4f;}
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
else
    mouseDown = false;
}

void mouseMotion(int x, int y){
    if (mouseDown){
    yrot = x - xdiff;
    xrot = y + ydiff;
    glutPostRedisplay();
}
}

void keyboard(unsigned char key, int x, int y){
    switch (key)
    {
    case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 3.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(3.0, 0.0, 0.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0, 0.0, -3.0);
        break;
    case 'a':
    case 'A':
        glTranslatef(-3.0, 0.0, 0.0);
        break;
    case '2':
        glTranslatef(0.0, 3.0, 0.0);
        break;
    case '3':
        glTranslatef(0.0, -3.0, 0.0);
        break;
    case '4':
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case '5':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case '6':
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case '7':
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case '8':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case '9':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;
    case '1':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    hasil();

}

void ukuran(int lebar, int tinggi){
    if (tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(-20.0, -5.0, -300.0);
    glMatrixMode(GL_MODELVIEW);
}

int main (int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1400, 750);
    glutInitWindowPosition(70, 70);
    glutCreateWindow("The Library of Chongqing Normal University");
    init();
    glutDisplayFunc(hasil);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(ukuran);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutTimerFunc(0, warna, 0);
    glutIdleFunc(hasil);
    glutMainLoop();
    return 0;
}

