#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>>
#include<cstdio>
#include <GL/gl.h>
# define PI           3.14159265358979323846

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
GLfloat i = 0.6f;

GLfloat position = 0.0f;
GLfloat position1 = 0.0f;
GLfloat position2 = 0.0f;
GLfloat position3 = 0.0f;
GLfloat speed = 0.01f;
GLfloat speed1 = 0.01f;
GLfloat speed2 = 0.01f;
GLfloat speed3 = 0.01f;
void demo_morning();
void demo_day(int val);
void demo_night(int val);
void demo_rain(int val);
void demo_evening(int val);
void demo_latenight(int val);
void sound(int val);
void sound2(int val);
void handleKeypress(unsigned char key, int x, int y);
GLfloat moonposition=0.0f;
GLfloat moonspeed=0.01f;
GLfloat moonposition2=0.0f;
GLfloat moonspeed2=0.02f;
GLfloat sunposition2=0.0f;
GLfloat sunspeed2=0.02f;
void moonupdate(int moonvalue) {

    if(moonposition >1.5)
        moonposition = -1.5f;

    moonposition += moonspeed;

    glutPostRedisplay();


    glutTimerFunc(25, moonupdate, 0);
}
void moonupdate2(int moonvalue) {

    if(moonposition2 <-2.5)
        moonposition2 = 2.5f;

    moonposition2 -= moonspeed2;

    glutPostRedisplay();


    glutTimerFunc(25, moonupdate2, 0);
}

void sunupdate2(int sunvalue) {

    if(sunposition2 <-2.0)
        sunposition2 = 2.0f;

    sunposition2 -= sunspeed2;

    glutPostRedisplay();


    glutTimerFunc(25, sunupdate2, 0);
}

//negtopos
void update(int value) {

    if(position >2.50)
        position = -2.50f;

    position += speed;

    glutPostRedisplay();


    glutTimerFunc(22, update, 0);
}
//postoneg
void update1(int value) {

    if(position1 >1.5)
        position1 = -1.5f;

    position1 += speed1;

    glutPostRedisplay();


    glutTimerFunc(25, update1, 0);
}

void update2(int value) {

    if(position2 <-4.0)
        position2 = 2.5f;

    position2 -= speed2;

    glutPostRedisplay();


    glutTimerFunc(25, update2, 0);
}
void update3(int value) {

    if(position3 <-2.5)
        position3 = 2.5f;

    position3 -= speed3;

    glutPostRedisplay();


    glutTimerFunc(25, update3, 0);
}
void sound(int val)
{

    PlaySound("city.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);


}
void sound2(int val)
{

    PlaySound("rain.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);


}


void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}

void demo_back(int val){

glutDisplayFunc(demo_morning);

}

void day() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);




//Sky
glBegin(GL_QUADS);
        glColor3ub(240, 250, 250);
        glVertex2f(1.0,1.0);
        glVertex2f(-1.0,1.0);
        glVertex2f(-1.0,-0.6);
        glVertex2f(1.0,-0.6);
        glEnd();
//sun



  glPushMatrix();
glTranslatef(position1-1,position1,0);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(249, 248, 154);
       int is;
       float xs=0.77;
       float ys=0.77;
        glVertex2f(xs, ys);
        for(is = 0; is <= 100;is++) {
            glVertex2f(
                    xs + (0.2 * cos(is *  2.0f*PI/ 100)),
                ys + (0.2 * sin(is * 2.0f*PI / 100))
            );
        }
    glEnd();
glPopMatrix();

//clouds1
glPushMatrix();
glTranslatef(position2,0,0);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255);
       int ic1;
       float xc1=0.75;
       float yc1=0.7;
        glVertex2f(xc1, yc1);
        for(ic1 = 0; ic1 <= 100;ic1++) {
            glVertex2f(
                    xc1 + (0.15 * cos(ic1 *  2.0f*PI/ 100)),
                yc1 + (0.15 * sin(ic1 * 2.0f*PI / 100))
            );
        }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255);

       float xc2=0.9;
       float yc2=0.68;
        glVertex2f(xc2, yc2);
        for(ic1 = 0; ic1 <= 100;ic1++) {
            glVertex2f(
                    xc2 + (0.1 * cos(ic1 *  2.0f*PI/ 100)),
                yc2 + (0.1 * sin(ic1 * 2.0f*PI / 100))
            );
        }
    glEnd();
glPopMatrix();

//clouds2
glPushMatrix();
glTranslatef(position2,0,0);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255);
       int ic2;
       float xc3=0.45;
       float yc3=0.4;
        glVertex2f(xc3, yc3);
        for(ic2 = 0; ic2 <= 100;ic2++) {
            glVertex2f(
                    xc3 + (0.15 * cos(ic2 *  2.0f*PI/ 100)),
                yc3 + (0.15 * sin(ic2 * 2.0f*PI / 100))
            );
        }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255);

       float xc4=0.6;
       float yc4=0.38;
        glVertex2f(xc4, yc4);
        for(ic1 = 0; ic1 <= 100;ic1++) {
            glVertex2f(
                    xc4 + (0.1 * cos(ic1 *  2.0f*PI/ 100)),
                yc4 + (0.1 * sin(ic1 * 2.0f*PI / 100))
            );
        }
    glEnd();
glPopMatrix();
//clouds2
glPushMatrix();
glTranslatef(position2,0,0);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255);
       int ic3;
       float xc5=0.05;
       float yc5=0.7;
        glVertex2f(xc5, yc5);
        for(ic3 = 0; ic3 <= 100;ic3++) {
            glVertex2f(
                    xc5 + (0.15 * cos(ic3 *  2.0f*PI/ 100)),
                yc5 + (0.15 * sin(ic3 * 2.0f*PI / 100))
            );
        }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255);

       float xc6=0.2;
       float yc6=0.7;
        glVertex2f(xc5, yc5);
        for(ic1 = 0; ic1 <= 100;ic1++) {
            glVertex2f(
                    xc6 + (0.1 * cos(ic1 *  2.0f*PI/ 100)),
                yc6 + (0.1 * sin(ic1 * 2.0f*PI / 100))
            );
        }
    glEnd();
glPopMatrix();
//Background 1
glBegin(GL_QUADS);//Left_Building1
        glColor3ub(45, 90, 143);
        glVertex2f(-0.9,0.6);
        glVertex2f(-1.0,0.7);
        glVertex2f(-1.0,-0.6);
        glVertex2f(-0.9,-0.6);
        glEnd();
glBegin(GL_POLYGON);//Left_Building2
        glColor3ub(45, 90, 143);
        glVertex2f(-0.7,0.78);
        glVertex2f(-0.75,0.85);
        glVertex2f(-0.88,0.78);
        glVertex2f(-0.88,-0.6);
        glVertex2f(-0.7,-0.6);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(176, 176, 176);
        glVertex2f(-0.75,0.85);
        glVertex2f(-0.75,-0.6);
        glEnd();

glBegin(GL_POLYGON);//Left_Building3
        glColor3ub(45, 90, 143);
        glVertex2f(-0.4,0.47);
        glVertex2f(-0.4,0.78);
        glVertex2f(-0.5,0.85);
        glVertex2f(-0.6,0.78);
        glVertex2f(-0.6,0.47);
        glVertex2f(-0.69,0.4);
        glVertex2f(-0.69,-0.6);
        glVertex2f(-0.3,-0.6);
        glVertex2f(-0.3,0.4);

        glEnd();
glBegin(GL_LINES);
        glColor3ub(176, 176, 176);
        glVertex2f(-0.5,0.85);
        glVertex2f(-0.5,-0.6);
        glEnd();
//background 2
glBegin(GL_POLYGON);//Right_Building1
        glColor3ub(149, 187, 187);
        glVertex2f(-0.1,0.53);
        glVertex2f(-0.23,0.58);
        glVertex2f(-0.35,0.53);
        glVertex2f(-0.35,-0.6);
        glVertex2f(-0.1,-0.6);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(145, 161, 161);
        glVertex2f(-0.23,0.58);
        glVertex2f(-0.23,-0.6);
        glEnd();

glBegin(GL_POLYGON);//Right_Building2
        glColor3ub(149, 187, 187);
        glVertex2f(-0.39,0.41);
        glVertex2f(-0.45,0.46);
        glVertex2f(-0.65,0.41);
        glVertex2f(-0.65,-0.6);
        glVertex2f(-0.39,-0.6);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(145, 161, 161);
        glVertex2f(-0.45,0.46);
        glVertex2f(-0.45,-0.6);
        glEnd();
glBegin(GL_POLYGON);//Right_Building3
        glColor3ub(149, 187, 187);
        glVertex2f(-0.67,0.45);
        glVertex2f(-0.8,0.5);
        glVertex2f(-1.0,0.45);
        glVertex2f(-1.0,-0.6);
        glVertex2f(-0.67,-0.6);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(145, 161, 161);
        glVertex2f(-0.8,0.5);
        glVertex2f(-0.8,-0.6);
        glEnd();
//footpath
glBegin(GL_QUADS);
        glColor3ub(201, 201, 201);
        glVertex2f(1.0,-0.6);
        glVertex2f(-1.0,-0.6);
        glVertex2f(-1.0,-0.8);
        glVertex2f(1.0,-0.8);
        glEnd();

//Building row 2
glTranslatef(-1.15,0.1,0);
glBegin(GL_POLYGON);//Left Building4
        glColor3ub(213, 182, 149);
        glVertex2f(0.4,0.1);
        glVertex2f(0.15,0.1);
        glVertex2f(0.1,0.07);
        glVertex2f(0.1,-0.67);
        glVertex2f(0.15,-0.7);
        glVertex2f(0.4,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(19, 124, 85);
        glVertex2f(0.15,0.1);
        glVertex2f(0.15,-0.7);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();


glTranslatef(-0.53,0.1,0.0);
glBegin(GL_POLYGON);//Left Building3
        glColor3ub(239, 200, 31);
        glVertex2f(0.1,0.1);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.3,0.07);
        glVertex2f(-0.3,-0.67);
        glVertex2f(-0.25,-0.7);
        glVertex2f(0.1,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(170, 140, 9);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.25,-0.7);
        glEnd();

glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

glTranslatef(-0.5,0.3,0);
glBegin(GL_POLYGON);//Left Building4
        glColor3ub(50, 154, 115);
        glVertex2f(0.4,0.1);
        glVertex2f(0.15,0.1);
        glVertex2f(0.1,0.07);
        glVertex2f(0.1,-0.67);
        glVertex2f(0.15,-0.7);
        glVertex2f(0.4,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(19, 124, 85);
        glVertex2f(0.15,0.1);
        glVertex2f(0.15,-0.7);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

glTranslatef(0.25,0.25,0.0);
glBegin(GL_POLYGON);//Left Building3
        glColor3ub(109, 135, 156);
        glVertex2f(0.1,0.1);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.3,0.07);
        glVertex2f(-0.3,-0.67);
        glVertex2f(-0.25,-0.7);
        glVertex2f(0.1,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(54, 67, 78);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.25,-0.7);
        glEnd();

glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

//trees
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
    glColor3ub(78, 181, 54);
        int it;
       float xt=0.78;
       float yt=-0.5;
        glVertex2f(xt, yt);
        for(it = 0; it<= 100;it++) {
            glVertex2f(
                    xt + (0.05 * cos(it *  2.0f*PI/ 100)),
                yt + (0.05 * sin(it * 2.0f*PI / 100))
            );
        }
    glEnd();
glBegin(GL_TRIANGLE_FAN);
    glColor3ub(78, 181, 54);

       float xt1=0.8;
       float yt1=-0.45;
        glVertex2f(xt1, yt1);
        for(it = 0; it<= 100;it++) {
            glVertex2f(
                    xt1 + (0.06 * cos(it *  2.0f*PI/ 100)),
                yt1 + (0.06 * sin(it * 2.0f*PI / 100))
            );
        }
    glEnd();
glBegin(GL_TRIANGLE_FAN);
    glColor3ub(78, 181, 54);

       float xt2=0.82;
       float yt2=-0.5;
        glVertex2f(xt1, yt1);
        for(it = 0; it<= 100;it++) {
            glVertex2f(
                    xt2 + (0.06 * cos(it *  2.0f*PI/ 100)),
                yt2 + (0.06 * sin(it * 2.0f*PI / 100))
            );
        }
    glEnd();

glTranslatef(0.15,0,0);
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
    glColor3ub(78, 181, 54);

        xt=0.78;
        yt=-0.5;
        glVertex2f(xt, yt);
        for(it = 0; it<= 100;it++) {
            glVertex2f(
                    xt + (0.05 * cos(it *  2.0f*PI/ 100)),
                yt + (0.05 * sin(it * 2.0f*PI / 100))
            );
        }
    glEnd();
glBegin(GL_TRIANGLE_FAN);
    glColor3ub(78, 181, 54);

        xt1=0.8;
        yt1=-0.45;
        glVertex2f(xt1, yt1);
        for(it = 0; it<= 100;it++) {
            glVertex2f(
                    xt1 + (0.06 * cos(it *  2.0f*PI/ 100)),
                yt1 + (0.06 * sin(it * 2.0f*PI / 100))
            );
        }
    glEnd();
glBegin(GL_TRIANGLE_FAN);
    glColor3ub(78, 181, 54);

        xt2=0.82;
        yt2=-0.5;
        glVertex2f(xt1, yt1);
        for(it = 0; it<= 100;it++) {
            glVertex2f(
                    xt2 + (0.06 * cos(it *  2.0f*PI/ 100)),
                yt2 + (0.06 * sin(it * 2.0f*PI / 100))
            );
        }
    glEnd();
glLoadIdentity();

glTranslatef(-0.15,0,0);
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
