#include <windows.h>
#include <GL/glut.h>
#include <math.h>

///a >> perbesar
///b >> perkecil
///c >> geser kanan
///d >> geser kiri
///1 >> menampilkan bagian dalam
///2 >> bergerak keatas
///3 >> bergerak kebawah
///4 >> putar kebawah
///5 >> putar keatas
///6 >> putar kanan
///7 >> putar kiri
///8 >> putar samping kiri
///9 >> putar samping kanan

void init(void);
void hasil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);

int is_depth;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(6.0);
    glLineWidth(3.0f);
}

void garisdepan()
{
    /*
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.5);
    glVertex3f(-44.5, -10.5, 10.0);
    glVertex3f(-44.5, -5.0, 10.0);
    glVertex3f(-44.0, -10.5, 10.0);
    glVertex3f(-44.0, -5.0, 10.0);

    glVertex3f(-43.5, -10.5, 10.0);
    glVertex3f(-43.5, -5.0, 10.0);
    glVertex3f(-43.0, -10.5, 10.0);
    glVertex3f(-43.0, -5.0, 10.0);

    glVertex3f(-42.5, -10.5, 10.0);
    glVertex3f(-42.5, -5.0, 10.0);
    glVertex3f(-42.0, -10.5, 10.0);
    glVertex3f(-42.0, -5.0, 10.0);

    glVertex3f(-41.5, -10.5, 10.0);
    glVertex3f(-41.5, -5.0, 10.0);
    glVertex3f(-41.0, -10.5, 10.0);
    glVertex3f(-41.0, -5.0, 10.0);

    glVertex3f(-40.5, -10.5, 10.0);
    glVertex3f(-40.5, -5.0, 10.0);
    glVertex3f(-40.0, -10.5, 10.0);
    glVertex3f(-40.0, -5.0, 10.0);

    glVertex3f(-39.5, -10.5, 10.0);
    glVertex3f(-39.5, -5.0, 10.0);
    glVertex3f(-39.0, -10.5, 10.0);
    glVertex3f(-39.0, -5.0, 10.0);

    glVertex3f(-38.5, -10.5, 10.0);
    glVertex3f(-38.5, -5.0, 10.0);
    glVertex3f(-38.0, -10.5, 10.0);
    glVertex3f(-38.0, -5.0, 10.0);

    glVertex3f(-37.5, -10.5, 10.0);
    glVertex3f(-37.5, -5.0, 10.0);
    glVertex3f(-37.0, -10.5, 10.0);
    glVertex3f(-37.0, -5.0, 10.0);

    glVertex3f(-36.5, -10.5, 10.0);
    glVertex3f(-36.5, -5.0, 10.0);
    glVertex3f(-36.0, -10.5, 10.0);
    glVertex3f(-36.0, -5.0, 10.0);

    glVertex3f(-35.5, -10.5, 10.0);
    glVertex3f(-35.5, -5.0, 10.0);
    glVertex3f(-35.0, -10.5, 10.0);
    glVertex3f(-35.0, -5.0, 10.0);

    glVertex3f(-34.5, -10.5, 10.0);
    glVertex3f(-34.5, -5.0, 10.0);
    glVertex3f(-34.0, -10.5, 10.0);
    glVertex3f(-34.0, -5.0, 10.0);

    glVertex3f(-33.5, -10.5, 10.0);
    glVertex3f(-33.5, -5.0, 10.0);
    glVertex3f(-33.0, -10.5, 10.0);
    glVertex3f(-33.0, -5.0, 10.0);

    glVertex3f(-32.5, -10.5, 10.0);
    glVertex3f(-32.5, -5.0, 10.0);
    glVertex3f(-32.0, -10.5, 10.0);
    glVertex3f(-32.0, -5.0, 10.0);

    glVertex3f(-31.5, -10.5, 10.0);
    glVertex3f(-31.5, -5.0, 10.0);
    glVertex3f(-31.0, -10.5, 10.0);
    glVertex3f(-31.0, -5.0, 10.0);

    glVertex3f(-30.5, -10.5, 10.0);
    glVertex3f(-30.5, -5.0, 10.0);
    glVertex3f(-30.0, -10.5, 10.0);
    glVertex3f(-30.0, -5.0, 10.0);

    glVertex3f(-29.5, -10.5, 10.0);
    glVertex3f(-29.5, -5.0, 10.0);
    glVertex3f(-29.0, -10.5, 10.0);
    glVertex3f(-29.0, -5.0, 10.0);

    glVertex3f(-28.5, -10.5, 10.0);
    glVertex3f(-28.5, -5.0, 10.0);
    glVertex3f(-28.0, -10.5, 10.0);
    glVertex3f(-28.0, -5.0, 10.0);

    glVertex3f(-27.5, -10.5, 10.0);
    glVertex3f(-27.5, -5.0, 10.0);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(-44.5, -17.5, 10.0);
    glVertex3f(-44.5, -12.0, 10.0);
    glVertex3f(-44.0, -17.5, 10.0);
    glVertex3f(-44.0, -12.0, 10.0);

    glVertex3f(-43.5, -17.5, 10.0);
    glVertex3f(-43.5, -12.0, 10.0);
    glVertex3f(-43.0, -17.5, 10.0);
    glVertex3f(-43.0, -12.0, 10.0);

    glVertex3f(-42.5, -17.5, 10.0);
    glVertex3f(-42.5, -12.0, 10.0);
    glVertex3f(-42.0, -17.5, 10.0);
    glVertex3f(-42.0, -12.0, 10.0);

    glVertex3f(-41.5, -17.5, 10.0);
    glVertex3f(-41.5, -12.0, 10.0);
    glVertex3f(-41.0, -17.5, 10.0);
    glVertex3f(-41.0, -12.0, 10.0);

    glVertex3f(-40.5, -17.5, 10.0);
    glVertex3f(-40.5, -12.0, 10.0);
    glVertex3f(-40.0, -17.5, 10.0);
    glVertex3f(-40.0, -12.0, 10.0);

    glVertex3f(-39.5, -17.5, 10.0);
    glVertex3f(-39.5, -12.0, 10.0);
    glVertex3f(-39.0, -17.5, 10.0);
    glVertex3f(-39.0, -12.0, 10.0);

    glVertex3f(-38.5, -17.5, 10.0);
    glVertex3f(-38.5, -12.0, 10.0);
    glVertex3f(-38.0, -17.5, 10.0);
    glVertex3f(-38.0, -12.0, 10.0);

    glVertex3f(-37.5, -17.5, 10.0);
    glVertex3f(-37.5, -12.0, 10.0);
    glVertex3f(-37.0, -17.5, 10.0);
    glVertex3f(-37.0, -12.0, 10.0);

    glVertex3f(-36.5, -17.5, 10.0);
    glVertex3f(-36.5, -12.0, 10.0);
    glVertex3f(-36.0, -17.5, 10.0);
    glVertex3f(-36.0, -12.0, 10.0);

    glVertex3f(-35.5, -17.5, 10.0);
    glVertex3f(-35.5, -12.0, 10.0);
    glVertex3f(-35.0, -17.5, 10.0);
    glVertex3f(-35.0, -12.0, 10.0);

    glVertex3f(-34.5, -17.5, 10.0);
    glVertex3f(-34.5, -12.0, 10.0);
    glVertex3f(-34.0, -17.5, 10.0);
    glVertex3f(-34.0, -12.0, 10.0);

    glVertex3f(-33.5, -17.5, 10.0);
    glVertex3f(-33.5, -12.0, 10.0);
    glVertex3f(-33.0, -17.5, 10.0);
    glVertex3f(-33.0, -12.0, 10.0);

    glVertex3f(-32.5, -17.5, 10.0);
    glVertex3f(-32.5, -12.0, 10.0);
    glVertex3f(-32.0, -17.5, 10.0);
    glVertex3f(-32.0, -12.0, 10.0);

    glVertex3f(-31.5, -17.5, 10.0);
    glVertex3f(-31.5, -12.0, 10.0);
    glVertex3f(-31.0, -17.5, 10.0);
    glVertex3f(-31.0, -12.0, 10.0);

    glVertex3f(-30.5, -17.5, 10.0);
    glVertex3f(-30.5, -12.0, 10.0);
    glVertex3f(-30.0, -17.5, 10.0);
    glVertex3f(-30.0, -12.0, 10.0);

    glVertex3f(-29.5, -17.5, 10.0);
    glVertex3f(-29.5, -12.0, 10.0);
    glVertex3f(-29.0, -17.5, 10.0);
    glVertex3f(-29.0, -12.0, 10.0);

    glVertex3f(-28.5, -17.5, 10.0);
    glVertex3f(-28.5, -12.0, 10.0);
    glVertex3f(-28.0, -17.5, 10.0);
    glVertex3f(-28.0, -12.0, 10.0);

    glVertex3f(-27.5, -19.0, 10.0);
    glVertex3f(-27.5, -12.0, 10.0);
    glEnd();
    */
}

void depan()
{
    ///bolongan kiri
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.5);
    glVertex3f(-59.3, -32.0, 10.0);
    glVertex3f(-59.3, 33.0, 10.0);
    glVertex3f(-58.4, -32.0, 10.0);
    glVertex3f(-58.4, 33.0, 10.0);
    glVertex3f(-57.4, -32.0, 10.0);
    glVertex3f(-57.4, 33.0, 10.0);

    glVertex3f(-54.3, -32.0, 10.0);
    glVertex3f(-54.3, 33.0, 10.0);
    glVertex3f(-53.4, -32.0, 10.0);
    glVertex3f(-53.4, 33.0, 10.0);
    glVertex3f(-52.3, -32.0, 10.0);
    glVertex3f(-52.3, 33.0, 10.0);

    glVertex3f(-49.3, -32.0, 10.0);
    glVertex3f(-49.3, 33.0, 10.0);
    glVertex3f(-48.3, -32.0, 10.0);
    glVertex3f(-48.3, 33.0, 10.0);
    glVertex3f(-47.3, -32.0, 10.0);
    glVertex3f(-47.3, 33.0, 10.0);

    ///kanan
    glColor3f(1.0, 1.0, 0.5);
    glVertex3f(-24.3, -19.0, 10.0);
    glVertex3f(-24.3, 33.0, 10.0);
    glVertex3f(-23.4, -19.0, 10.0);
    glVertex3f(-23.4, 33.0, 10.0);
    glVertex3f(-22.4, -19.0, 10.0);
    glVertex3f(-22.4, 33.0, 10.0);

    glVertex3f(-19.3, -19.0, 10.0);
    glVertex3f(-19.3, 33.0, 10.0);
    glVertex3f(-18.3, -19.0, 10.0);
    glVertex3f(-18.3, 33.0, 10.0);
    glVertex3f(-17.3, -19.0, 10.0);
    glVertex3f(-17.3, 33.0, 10.0);

    glVertex3f(-14.3, -19.0, 10.0);
    glVertex3f(-14.3, 33.0, 10.0);
    glVertex3f(-13.3, -19.0, 10.0);
    glVertex3f(-13.3, 33.0, 10.0);
    glVertex3f(-12.3, -19.0, 10.0);
    glVertex3f(-12.3, 33.0, 10.0);
    glEnd();

    ///bolongan tengah atas
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.5);
    glVertex3f(-44.3, 26.5, 10.0);
    glVertex3f(-44.3, 33.0, 10.0);
    glVertex3f(-43.4, 26.5, 10.0);
    glVertex3f(-43.4, 33.0, 10.0);
    glVertex3f(-42.3, 26.5, 10.0);
    glVertex3f(-42.3, 33.0, 10.0);

    glVertex3f(-39.3, 26.5, 10.0);
    glVertex3f(-39.3, 33.0, 10.0);
    glVertex3f(-38.3, 26.5, 10.0);
    glVertex3f(-38.3, 33.0, 10.0);
    glVertex3f(-37.3, 26.5, 10.0);
    glVertex3f(-37.3, 33.0, 10.0);

    glVertex3f(-34.3, 26.5, 10.0);
    glVertex3f(-34.3, 33.0, 10.0);
    glVertex3f(-33.3, 26.5, 10.0);
    glVertex3f(-33.3, 33.0, 10.0);
    glVertex3f(-32.3, 26.5, 10.0);
    glVertex3f(-32.3, 33.0, 10.0);

    glVertex3f(-29.3, 26.5, 10.0);
    glVertex3f(-29.3, 33.0, 10.0);
    glVertex3f(-28.4, 26.5, 10.0);
    glVertex3f(-28.4, 33.0, 10.0);
    glVertex3f(-27.5, 26.5, 10.0);
    glVertex3f(-27.5, 33.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
    ///pembatas tengah
    glVertex3f(-41.5, 26.5, 10.0);
    glVertex3f(-41.5, 33.0, 10.0);
    glVertex3f(-40.0, 33.0, 10.0);
    glVertex3f(-40.0, 26.5, 10.0);

    glVertex3f(-36.5, 26.5, 10.0);
    glVertex3f(-36.5, 33.0, 10.0);
    glVertex3f(-35.0, 33.0, 10.0);
    glVertex3f(-35.0, 26.5, 10.0);

    glVertex3f(-31.5, 26.5, 10.0);
    glVertex3f(-31.5, 33.0, 10.0);
    glVertex3f(-30.0, 33.0, 10.0);
    glVertex3f(-30.0, 26.5, 10.0);

    ///kiri
    glVertex3f(-56.5, -32.0, 10.0);
    glVertex3f(-56.5, 33.0, 10.0);
    glVertex3f(-55.0, 33.0, 10.0);
    glVertex3f(-55.0, -32.0, 10.0);

    glVertex3f(-51.5, -32.0, 10.0);
    glVertex3f(-51.5, 33.0, 10.0);
    glVertex3f(-50.0, 33.0, 10.0);
    glVertex3f(-50.0, -32.0, 10.0);

    ///kanan
    glVertex3f(-21.5, -19.0, 10.0);
    glVertex3f(-21.5, 33.0, 10.0);
    glVertex3f(-20.0, 33.0, 10.0);
    glVertex3f(-20.0, -19.0, 10.0);

    glVertex3f(-16.5, -19.0, 10.0);
    glVertex3f(-16.5, 33.0, 10.0);
    glVertex3f(-15.0, 33.0, 10.0);
    glVertex3f(-15.0, -19.0, 10.0);

    glVertex3f(-11.5, -19.0, 10.0);
    glVertex3f(-11.5, 33.0, 10.0);
    glVertex3f(-10.0, 33.0, 10.0);
    glVertex3f(-10.0, -19.0, 10.0);

    ///bawah
    glVertex3f(-62.0, -32.0, 10.0);
    glVertex3f(-62.0, -35.0, 10.0);
    glVertex3f(-45.0, -35.0, 10.0);
    glVertex3f(-45.0, -32.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
    ///bataskiri
    glColor3f(1.0, 1.0, 0.5);
    glVertex3f(-11.5, 26.5, 10.0);
    glVertex3f(-11.5, 25.0, 10.0);
    glVertex3f(-60.0, 25.0, 10.0);
    glVertex3f(-60.0, 26.5, 10.0);

    glVertex3f(-46.0, 18.5, 10.0);
    glVertex3f(-46.0, 17.0, 10.0);
    glVertex3f(-60.0, 17.0, 10.0);
    glVertex3f(-60.0, 18.5, 10.0);

    glVertex3f(-46.0, 11.5, 10.0);
    glVertex3f(-46.0, 10.0, 10.0);
    glVertex3f(-60.0, 10.0, 10.0);
    glVertex3f(-60.0, 11.5, 10.0);

    glVertex3f(-46.0, 4.5, 10.0);
    glVertex3f(-46.0, 3.0, 10.0);
    glVertex3f(-60.0, 3.0, 10.0);
    glVertex3f(-60.0, 4.5, 10.0);

    glVertex3f(-11.5, -3.5, 10.0);
    glVertex3f(-11.5, -5.0, 10.0);
    glVertex3f(-60.0, -5.0, 10.0);
    glVertex3f(-60.0, -3.5, 10.0);

    glVertex3f(-11.5, -10.5, 10.0);
    glVertex3f(-11.5, -12.0, 10.0);
    glVertex3f(-60.0, -12.0, 10.0);
    glVertex3f(-60.0, -10.5, 10.0);

    glVertex3f(-11.5, -17.5, 10.0);
    glVertex3f(-11.5, -19.0, 10.0);
    glVertex3f(-60.0, -19.0, 10.0);
    glVertex3f(-60.0, -17.5, 10.0);

    glVertex3f(-46.0, -24.5, 10.0);
    glVertex3f(-46.0, -26.0, 10.0);
    glVertex3f(-60.0, -26.0, 10.0);
    glVertex3f(-60.0, -24.5, 10.0);

    ///bataskanan
    glColor3f(1.0, 1.0, 0.5);
    glVertex3f(-26.0, 18.5, 10.0);
    glVertex3f(-26.0, 17.0, 10.0);
    glVertex3f(-11.5, 17.0, 10.0);
    glVertex3f(-11.5, 18.5, 10.0);

    glVertex3f(-26.0, 11.5, 10.0);
    glVertex3f(-26.0, 10.0, 10.0);
    glVertex3f(-11.5, 10.0, 10.0);
    glVertex3f(-11.5, 11.5, 10.0);

    glVertex3f(-26.0, 4.5, 10.0);
    glVertex3f(-26.0, 3.0, 10.0);
    glVertex3f(-11.5, 3.0, 10.0);
    glVertex3f(-11.5, 4.5, 10.0);
    glEnd();

    glBegin(GL_QUADS);
    ///dindingluar
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-62.0, 40.0, 10.0);
    glVertex3f(-62.0, 39.0, 10.0);
    glVertex3f(-10.0, 39.0, 10.0);
    glVertex3f(-10.0, 40.0, 10.0);

    glColor3f(1.0, 1.0, 0.5);
    ///kiri
    glVertex3f(-60.0, 33.0, 10.0);
    glVertex3f(-60.0, -32.0, 10.0);
    glVertex3f(-62.0, -32.0, 10.0);
    glVertex3f(-62.0, 33.0, 10.0);
    ///
    glVertex3f(-45.0, 33.0, 10.0);
    glVertex3f(-45.0, -32.0, 10.0);
    glVertex3f(-46.5, -32.0, 10.0);
    glVertex3f(-46.5, 33.0, 10.0);

    ///kanan
    glVertex3f(-25.0, 40.0, 10.0);
    glVertex3f(-25.0, -19.0, 10.0);
    glVertex3f(-27.0, -19.0, 10.0);
    glVertex3f(-27.0, 40.0, 10.0);
    ///atas
    glVertex3f(-62.0, 40.0, 10.0);
    glVertex3f(-62.0, 33.0, 10.0);
    glVertex3f(-10.0, 33.0, 10.0);
    glVertex3f(-10.0, 40.0, 10.0);
    glEnd();

    ///bolongtengah
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    ///jendela
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-45.0, 25.0, 7.0);
    glVertex3f(-45.0, 20.0, 7.0);
    glVertex3f(-45.0, 20.0, 2.5);
    glVertex3f(-45.0, 25.0, 2.5);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-45.0, 25.0, 0.0);
    glVertex3f(-45.0, 20.0, 0.0);
    glVertex3f(-45.0, 20.0, 1.8);
    glVertex3f(-45.0, 25.0, 1.8);

    ///
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-45.0, 19.0, 7.0);
    glVertex3f(-45.0, 14.0, 7.0);
    glVertex3f(-45.0, 14.0, 2.5);
    glVertex3f(-45.0, 19.0, 2.5);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-45.0, 19.0, 0.0);
    glVertex3f(-45.0, 14.0, 0.0);
    glVertex3f(-45.0, 14.0, 1.8);
    glVertex3f(-45.0, 19.0, 1.8);

    ///
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-45.0, 13.0, 7.0);
    glVertex3f(-45.0, 8.0, 7.0);
    glVertex3f(-45.0, 8.0, 2.5);
    glVertex3f(-45.0, 13.0, 2.5);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-45.0, 13.0, 0.0);
    glVertex3f(-45.0, 8.0, 0.0);
    glVertex3f(-45.0, 8.0, 1.8);
    glVertex3f(-45.0, 13.0, 1.8);

    ///
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-45.0, 7.0, 7.0);
    glVertex3f(-45.0, 2.0, 7.0);
    glVertex3f(-45.0, 2.0, 2.5);
    glVertex3f(-45.0, 7.0, 2.5);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-45.0, 7.0, 0.0);
    glVertex3f(-45.0, 2.0, 0.0);
    glVertex3f(-45.0, 2.0, 1.8);
    glVertex3f(-45.0, 7.0, 1.8);

    ///
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-45.0, 1.0, 7.0);
    glVertex3f(-45.0, -3.5, 7.0);
    glVertex3f(-45.0, -3.5, 2.5);
    glVertex3f(-45.0, 1.0, 2.5);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-45.0, 1.0, 0.0);
    glVertex3f(-45.0, -3.5, 0.0);
    glVertex3f(-45.0, -3.5, 1.8);
    glVertex3f(-45.0, 1.0, 1.8);

    ///bolongantengah
    glColor3f(0.5, 0.5, 1.0);
    ///kiri
    glVertex3f(-45.0, 25.0, 10.0);
    glVertex3f(-45.0, -3.5, 10.0);
    glVertex3f(-45.0, -3.5, 0.0);
    glVertex3f(-45.0, 25.0, 0.0);
    ///kanan
    glVertex3f(-27.0, 25.0, 10.0);
    glVertex3f(-27.0, -3.5, 10.0);
    glVertex3f(-27.0, -3.5, 0.0);
    glVertex3f(-27.0, 25.0, 0.0);
    ///atas
    glVertex3f(-45.0, 25.0, 10.0);
    glVertex3f(-27.0, 25.0, 10.0);
    glVertex3f(-27.0, 25.0, 0.0);
    glVertex3f(-45.0, 25.0, 0.0);
    ///bawah
    glVertex3f(-45.0, -3.5, 10.0);
    glVertex3f(-27.0, -3.5, 10.0);
    glVertex3f(-27.0, -3.5, 0.0);
    glVertex3f(-45.0, -3.5, 0.0);


    ///bolongantengah
    ///kiri
    glColor3f(1.0, 1.0, 0.5);
    glVertex3f(-45.0, -35.0, 10.0);
    glVertex3f(-45.0, -19.0, 10.0);
    glVertex3f(-45.0, -19.0, 5.0);
    glVertex3f(-45.0, -35.0, 5.0);
    glEnd();
}

void sampingkanan()
{
    glBegin(GL_QUADS);
    ///dindingluar
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-10.0, 40.0, 10.0);
    glVertex3f(-10.0, 39.0, 10.0);
    glVertex3f(-10.0, 39.0, -45.5);
    glVertex3f(-10.0, 40.0, -45.5);

    glColor3f(1.0, 0.0, 0.0);
    ///kiri
    glVertex3f(-10.0, 40.0, 10.0);
    glVertex3f(-10.0, -20.0, 10.0);
    glVertex3f(-10.0, -20.0, 3.0);
    glVertex3f(-10.0, 40.0, 3.0);
    ///tengah
    glVertex3f(-10.0, 25.0, -30.0);
    glVertex3f(-10.0, -20.0, -30.0);
    glVertex3f(-10.0, -20.0, -10.0);
    glVertex3f(-10.0, 25.0, -10.0);
    ///kanan
    glVertex3f(-10.0, 40.0, -45.5);
    glVertex3f(-10.0, -35.0, -45.5);
    glVertex3f(-10.0, -35.0, -40.0);
    glVertex3f(-10.0, 40.0, -40.0);
    ///atas
    glVertex3f(-10.0, 40.0, 3.0);
    glVertex3f(-10.0, 25.0, 3.0);
    glVertex3f(-10.0, 25.0, -40.0);
    glVertex3f(-10.0, 40.0, -40.0);
    ///bawah
    glVertex3f(-10.0, -20.0, 3.0);
    glVertex3f(-10.0, 7.0, 3.0);
    glVertex3f(-10.0, 7.0, -10.0);
    glVertex3f(-10.0, -20.0, -10.0);
    glEnd();
}

void belakang()
{
    glBegin(GL_QUADS);
    ///dindingluar
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-62.0, 40.0, -45.5);
    glVertex3f(-62.0, 39.0, -45.5);
    glVertex3f(-10.0, 39.0, -45.5);
    glVertex3f(-10.0, 40.0, -45.5);

    glColor3f(0.0, 0.0, 1.0);
    ///kanan
    glVertex3f(-45.0, 40.0, -45.5);
    glVertex3f(-45.0, -19.0, -45.5);
    glVertex3f(-62.0, -19.0, -45.5);
    glVertex3f(-62.0, 40.0, -45.5);
    ///kiri
    glVertex3f(-10.0, 40.0, -45.5);
    glVertex3f(-10.0, -35.0, -45.5);
    glVertex3f(-27.0, -35.0, -45.5);
    glVertex3f(-27.0, 40.0, -45.5);
    ///atas
    glVertex3f(-45.0, 40.0, -45.5);
    glVertex3f(-45.0, 25.0, -45.5);
    glVertex3f(-10.0, 25.0, -45.5);
    glVertex3f(-10.0, 40.0, -45.5);
    ///bawah
    glVertex3f(-45.0, -19.0, -45.5);
    glVertex3f(-45.0, -3.5, -45.5);
    glVertex3f(-10.0, -3.5, -45.5);
    glVertex3f(-10.0, -19.0, -45.5);
    glEnd();
}

void sampingkiri()
{
    glBegin(GL_QUADS);
    ///dindingluar
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-62.0, 40.0, 10.0);
    glVertex3f(-62.0, 39.0, 10.0);
    glVertex3f(-62.0, 39.0, -45.5);
    glVertex3f(-62.0, 40.0, -45.5);

    glColor3f(0.0, 1.0, 0.0);
    ///kiri
    glVertex3f(-62.0, 40.0, 10.0);
    glVertex3f(-62.0, -35.0, 10.0);
    glVertex3f(-62.0, -35.0, -10.0);
    glVertex3f(-62.0, 40.0, -10.0);
    ///kanan
    glVertex3f(-62.0, 40.0, -45.5);
    glVertex3f(-62.0, -20.0, -45.5);
    glVertex3f(-62.0, -20.0, -30.0);
    glVertex3f(-62.0, 40.0, -30.0);
    ///atas
    glVertex3f(-62.0, 40.0, -10.0);
    glVertex3f(-62.0, 25.0, -10.0);
    glVertex3f(-62.0, 25.0, -30.0);
    glVertex3f(-62.0, 40.0, -30.0);
    ///bawah
    glVertex3f(-62.0, -20.0, -10.0);
    glVertex3f(-62.0, 7.0, -10.0);
    glVertex3f(-62.0, 7.0, -30.0);
    glVertex3f(-62.0, -20.0, -30.0);
    glEnd();
}

void lantai()
{
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.0, 0.0);
    glVertex3f(-62.0, -35.0, 10.0);
    glVertex3f(-10.0, -35.0, 10.0);
    glVertex3f(-10.0, -35.0, -45.5);
    glVertex3f(-62.0, -35.0, -45.5);
    glEnd();
}

void atap()
{
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
    glColor3f(1.0, 0.0, 0.5);
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

void hasil(void)
{
    if(is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
    glClear(GL_COLOR_BUFFER_BIT);

    depan();
    sampingkanan();
    belakang();
    sampingkiri();
    lantai();
    atap();

    glPushMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a':
    case 'A':
        glTranslatef(0.0, 0.0, 3.0);
        break;
    case 'c':
    case 'C':
        glTranslatef(3.0, 0.0, 0.0);
        break;
    case 'b':
    case 'B':
        glTranslatef(0.0, 0.0, -3.0);
        break;
    case 'd':
    case 'D':
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

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(-20.0, -5.0, -200.0);
    glMatrixMode(GL_MODELVIEW);
}

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1400, 750);
    glutInitWindowPosition(70, 70);
    glutCreateWindow("The Library of Chongqing Normal University");
    init();
    glutDisplayFunc(hasil);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}
