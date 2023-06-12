#include <stdlib.h>
#include <GL/freeglut.h>
#include <math.h>

int moveCloud = 0;
int rotateBlade = 0;
int boatMove = 0;

void circle(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y){
    int i=0;
    float angle;
    GLfloat PI= 2.0f * 3.1416;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    for(i=0;i<100;i++)
    {
        angle = 2 * PI * i/100;
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)* ry));
    }
    glEnd();
}

static void displayDay(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3ub(0,154,23);
    glBegin(GL_QUADS);
        //earth
        glVertex2i(0,0);
        glVertex2i(700,0);
        glVertex2i(630,700);
        glVertex2i(0,700);

        //river
        glColor3ub(	0, 105, 148);
        glVertex2i(700,0);
        glVertex2i(1000,0);
        glVertex2i(1000,700);
        glVertex2i(630,700);

        //sky
        glColor3ub(0,181,226);
        glVertex2i(0,1000);
        glVertex2i(1000,1000);
        glVertex2i(1000,700);
        glVertex2i(0,700);
    glEnd();

    //earth add-ons
    glColor3ub(	0, 105, 148);
    circle(10,30, 635, 670);
    circle(20,80, 650, 620);
    circle(30,110, 655, 540);
    circle(20,70, 665, 360);
    circle(20,70, 675, 300);
    circle(100,100, 750, 100);

    //boat
    glColor3ub(101, 67, 33);
    glPushMatrix();
    glTranslated(-boatMove/2, boatMove, 0);
    glBegin(GL_TRIANGLES);
        glVertex2i(660,100);
        glVertex2i(690,50);
        glVertex2i(690,75);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2i(780,50);
        glVertex2i(800,100);
        glVertex2i(780,75);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2i(690,50);
        glVertex2i(690,75);
        glVertex2i(780,75);
        glVertex2i(780,50);
    glEnd();

    glColor3ub(152,118,184);
    glBegin(GL_TRIANGLES);
        glVertex2i(660,100);
        glVertex2i(690,75);
        glVertex2i(690,100);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2i(780,100);
        glVertex2i(800,100);
        glVertex2i(780,75);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2i(690,75);
        glVertex2i(690,100);
        glVertex2i(780,100);
        glVertex2i(780,75);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2i(690,75);
        glVertex2i(690,100);
        glVertex2i(695,100);
        glVertex2i(695,75);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2i(775,75);
        glVertex2i(775,100);
        glVertex2i(780,100);
        glVertex2i(780,75);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslated(-boatMove/2, boatMove, 0);
    glTranslated(-10, 250, 0);
    glBegin(GL_TRIANGLES);
        glVertex2i(660,100);
        glVertex2i(690,50);
        glVertex2i(690,75);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2i(780,50);
        glVertex2i(800,100);
        glVertex2i(780,75);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2i(690,50);
        glVertex2i(690,75);
        glVertex2i(780,75);
        glVertex2i(780,50);
    glEnd();

    glColor3ub(152,118,184);
    glBegin(GL_TRIANGLES);
        glVertex2i(660,100);
        glVertex2i(690,75);
        glVertex2i(690,100);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2i(780,100);
        glVertex2i(800,100);
        glVertex2i(780,75);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2i(690,75);
        glVertex2i(690,100);
        glVertex2i(780,100);
        glVertex2i(780,75);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2i(690,75);
        glVertex2i(690,100);
        glVertex2i(695,100);
        glVertex2i(695,75);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2i(775,75);
        glVertex2i(775,100);
        glVertex2i(780,100);
        glVertex2i(780,75);
    glEnd();

    glPopMatrix();
    //sun
    glColor3ub(252, 229, 112);
    glPushMatrix();
    circle(40, 75, 150, 850);
    glPopMatrix();

    //cloud1
    glColor3ub(255,255,255);
    glPushMatrix();
    glTranslated(moveCloud,0, 0);
    glPushMatrix();
    glTranslated(800,900, 0);
    glutSolidSphere(20, 100, 100);
    glPopMatrix();
    glutPostRedisplay();
    glPushMatrix();
    glTranslated(815,915, 0);
    glutSolidSphere(20, 100, 100);
    glPopMatrix();
    glPushMatrix();
    glTranslated(830,900, 0);
    glutSolidSphere(20, 100, 100);
    glPopMatrix();
    glPushMatrix();
    glTranslated(815,885, 0);
    glutSolidSphere(20, 100, 100);
    glPopMatrix();
    glPopMatrix();

    //cloud2
    glColor3ub(255,255,255);
    glPushMatrix();
    glTranslated(moveCloud,0, 0);
    glPushMatrix();
    glTranslated(400,850, 0);
    glutSolidSphere(20, 100, 100);
    glPopMatrix();
    glPushMatrix();
    glTranslated(415,865, 0);
    glutSolidSphere(20, 100, 100);
    glPopMatrix();
    glPushMatrix();
    glTranslated(430,850, 0);
    glutSolidSphere(20, 100, 100);
    glPopMatrix();
    glPushMatrix();
    glTranslated(415,835, 0);
    glutSolidSphere(20, 100, 100);
    glPopMatrix();
    glPopMatrix();

    //cloud3
    glColor3ub(255,255,255);
    glPushMatrix();
    glTranslated(moveCloud,0, 0);
    glPushMatrix();
    glTranslated(600,875, 0);
    glutSolidSphere(20, 100, 100);
    glPopMatrix();
    glPushMatrix();
    glTranslated(615,890, 0);
    glutSolidSphere(20, 100, 100);
    glPopMatrix();
    glPushMatrix();
    glTranslated(630,875, 0);
    glutSolidSphere(20, 100, 100);
    glPopMatrix();
    glPushMatrix();
    glTranslated(615,860, 0);
    glutSolidSphere(20, 100, 100);
    glPopMatrix();
    glPopMatrix();

    //hills
    glColor3ub(0,75,0);
    glBegin(GL_POLYGON);
        glVertex2i(20,700);
        glVertex2i(120,700);
        glVertex2i(105,745);
        glVertex2i(85,765);
        glVertex2i(55,765);
        glVertex2i(35,745);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(120,700);
        glVertex2i(160,750);
        glVertex2i(220,780);
        glVertex2i(280,750);
        glVertex2i(320,700);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(317,700);
        glVertex2i(327,720);
        glVertex2i(347,740);
        glVertex2i(367,720);
        glVertex2i(377,700);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(377,700);
        glVertex2i(407,745);
        glVertex2i(447,785);
        glVertex2i(497,800);
        glVertex2i(557,785);
        glVertex2i(597,745);
        glVertex2i(627,700);
    glEnd();

    //trees
    glColor3ub(93, 41, 6);
    glPushMatrix();
    glTranslated(100,500, 0);
    glutSolidSphere(20, 100, 100);
    glPopMatrix();

    glBegin(GL_POLYGON);
        glVertex2i(80,490);
        glVertex2i(120,490);
        glVertex2i(110,600);
        glVertex2i(90, 600);
    glEnd();

    glColor3ub(42,126,25);
    glBegin(GL_POLYGON);
        glVertex2i(60,600);
        glVertex2i(140,600);
        glVertex2i(120,630);
        glVertex2i(80, 630);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(60,630);
        glVertex2i(140,630);
        glVertex2i(100,750);
    glEnd();

    glColor3ub(93, 41, 6);
    glPushMatrix();
    glTranslated(500,520, 0);
    glutSolidSphere(20, 100, 100);
    glPopMatrix();

    glBegin(GL_POLYGON);
        glVertex2i(480,510);
        glVertex2i(520,510);
        glVertex2i(510,620);
        glVertex2i(490,620);
    glEnd();

    glColor3ub(42,126,25);
    glBegin(GL_POLYGON);
        glVertex2i(480,620);
        glVertex2i(520,620);
        glVertex2i(510,650);
        glVertex2i(490, 650);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(480,650);
        glVertex2i(520,650);
        glVertex2i(500,770);
    glEnd();

    glColor3ub(93, 41, 6);
    glPushMatrix();
    glTranslated(250,530, 0);
    glutSolidSphere(20, 100, 100);
    glPopMatrix();

    glBegin(GL_POLYGON);
        glVertex2i(230,520);
        glVertex2i(270,520);
        glVertex2i(260,630);
        glVertex2i(240,630);
    glEnd();

    glColor3ub(42,126,25);
    glBegin(GL_POLYGON);
        glVertex2i(210,630);
        glVertex2i(290,630);
        glVertex2i(270,660);
        glVertex2i(230, 660);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(210,660);
        glVertex2i(290,660);
        glVertex2i(250,780);
    glEnd();

    glColor3ub(93, 41, 6);
    glPushMatrix();
    glTranslated(380,550, 0);
    glutSolidSphere(20, 100, 100);
    glPopMatrix();

    glBegin(GL_POLYGON);
        glVertex2i(360,540);
        glVertex2i(400,540);
        glVertex2i(390,650);
        glVertex2i(370,650);
    glEnd();

    glColor3ub(42,126,25);
    glBegin(GL_POLYGON);
        glVertex2i(360,650);
        glVertex2i(400,650);
        glVertex2i(390,680);
        glVertex2i(370, 680);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(360,680);
        glVertex2i(400,680);
        glVertex2i(380,800);
    glEnd();

    //shed
    glColor3ub(246,190,0);
    glBegin(GL_POLYGON);
        glVertex2i(70,120);
        glVertex2i(220,120);
        glVertex2i(220,270);
        glVertex2i(70, 270);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_LINES);
        glVertex2i(70,120);
        glVertex2i(20,140);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(70,120);
        glVertex2i(220,120);
        glVertex2i(220,270);
        glVertex2i(70, 270);
    glEnd();

    glBegin(GL_LINES);
        glVertex2i(20,140);
        glVertex2i(20,270);
    glEnd();

    glBegin(GL_LINES);
        glVertex2i(20,270);
        glVertex2i(38,390);
    glEnd();

    glBegin(GL_LINES);
        glVertex2i(70,270);
        glVertex2i(38,390);
    glEnd();

    glBegin(GL_LINES);
        glVertex2i(220,270);
        glVertex2i(188,390);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(188,390.5);
        glVertex2f(38,390.5);
    glEnd();

    glColor3ub(246,190,0);
    glBegin(GL_POLYGON);
        glVertex2f(69.8,121);
        glVertex2i(20,141);
        glVertex2i(20,270);
        glVertex2f(69.8, 270);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(69.8,269.8);
        glVertex2f(20.5, 269.8);
        glVertex2f(38.2,390);
    glEnd();

    glColor3ub(150,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(70.5,270);
        glVertex2i(220,270);
        glVertex2i(188,390);
        glVertex2f(38.7, 390);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_LINES);
        glVertex2i(70,269);
        glVertex2i(220,269);
    glEnd();

    glColor3ub(128,164,164);
    glBegin(GL_POLYGON);
        glVertex2f(50,280);
        glVertex2i(35,286);
        glVertex2i(35,336);
        glVertex2f(50, 330);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(50,170);
        glVertex2i(35,176);
        glVertex2i(35,226);
        glVertex2f(50, 220);
    glEnd();

    glColor3ub(255,255,255);
    glBegin(GL_LINES);
        glVertex2f(35,311);
        glVertex2f(50,305);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(42.5,333);
        glVertex2f(42.5,283);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(35,201);
        glVertex2f(50,195);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(42.5,223);
        glVertex2f(42.5,173);
    glEnd();

    //door
    glColor3ub(150, 111, 5);
    glBegin(GL_POLYGON);
        glVertex2i(90,120);
        glVertex2i(120,120);
        glVertex2i(120,220);
        glVertex2i(90,220);
    glEnd();
    glColor3ub(0,0,0);
    circle(2,4,115, 165);

    glColor3ub(128,164,164);
    glBegin(GL_POLYGON);
        glVertex2f(160,230);
        glVertex2i(200,230);
        glVertex2i(200,160);
        glVertex2f(160, 160);
    glEnd();

    glColor3ub(255,255,255);
    glBegin(GL_LINES);
        glVertex2f(160,195);
        glVertex2f(200,195);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(180,230);
        glVertex2f(180,160);
    glEnd();

    //windmill base
    glColor3ub(178,34,34);
    glPushMatrix();
    glTranslated(400,200, 0);
    glutSolidSphere(100, 100, 200);
    glPopMatrix();
    glColor3ub(178,34,34);

    glBegin(GL_POLYGON);
        glVertex2i(300,200);
        glVertex2i(360,530);
        glVertex2i(392,580);
        glVertex2i(408,580);
        glVertex2i(440,530);
        glVertex2i(500,200);
    glEnd();

    //head attachment
    glColor3ub(1,34,34);
    glBegin(GL_POLYGON);
        glVertex2i(350,505);
        glVertex2i(350,535);
        glVertex2i(380,570);
        glVertex2i(400,600);
        glVertex2i(420,570);
        glVertex2i(450,535);
        glVertex2i(450,505);
    glEnd();

    //windmill windows
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
        glVertex2i(391,495);
        glVertex2i(409,495);
        glVertex2i(409,456);
        glVertex2i(391,456);
    glEnd();
    glColor3ub(128,164,164);
    glBegin(GL_POLYGON);
        glVertex2i(394,488);
        glVertex2i(406,488);
        glVertex2i(406,463);
        glVertex2i(394,463);
    glEnd();
    glColor3ub(255,255,255);
    glBegin(GL_LINES);
        glVertex2f(394.0,475.5);
        glVertex2f(406.0,475.5);
    glEnd();
    glBegin(GL_LINES);
        glVertex2i(400,488);
        glVertex2i(400,463);
    glEnd();

    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
        glVertex2i(386,400);
        glVertex2i(414,400);
        glVertex2i(414,340);
        glVertex2i(386,340);
    glEnd();
    glColor3ub(128,164,164);
    glBegin(GL_POLYGON);
        glVertex2i(388,390);
        glVertex2i(412,390);
        glVertex2i(412,350);
        glVertex2i(388,350);
    glEnd();
    glColor3ub(255,255,255);
    glBegin(GL_LINES);
        glVertex2f(388.0,370.0);
        glVertex2f(412.0,370.0);
    glEnd();
    glBegin(GL_LINES);
        glVertex2i(400,390);
        glVertex2i(400,350);
    glEnd();

    //windmill door
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2i(370,105);
        glVertex2i(430,105);
        glVertex2i(430,225);
        glVertex2i(400,235);
        glVertex2i(370,225);

    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(370,105);
        glVertex2f(382,103);
        glVertex2i(400,100);
        glVertex2f(420,103);
        glVertex2i(430,105);
    glEnd();

    glColor3ub(150, 111, 5);
    glBegin(GL_POLYGON);
        glVertex2i(370,105);
        glVertex2f(373,105);
        glVertex2i(373,225);
        glVertex2f(370,225);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(430,105);
        glVertex2f(427,105);
        glVertex2i(427,225);
        glVertex2f(430,225);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(370,225);
        glVertex2f(373,222);
        glVertex2i(400,232);
        glVertex2f(400,235);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(430,225);
        glVertex2f(427,222);
        glVertex2f(400,232);
        glVertex2i(400,235);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(350,235);
        glVertex2f(370,225);
        glVertex2f(370,105);
        glVertex2i(350,105);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(430,225);
        glVertex2f(450,235);
        glVertex2f(450,105);
        glVertex2i(430,105);
    glEnd();

    glColor3ub(130, 73, 11);
    glBegin(GL_POLYGON);
        glVertex2i(350,235);
        glVertex2f(347,235);
        glVertex2f(347,105);
        glVertex2i(350,105);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(450,235);
        glVertex2f(453,235);
        glVertex2f(453,105);
        glVertex2i(450,105);
    glEnd();

    //blade holder
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2i(390,525);
        glVertex2i(410,525);
        glVertex2i(410,565);
        glVertex2i(390,565);
    glEnd();
    //blade mechanism
    glPushMatrix();
    glTranslated(400, 545, 0);
    glRotatef(rotateBlade, 0, 0, 1.0);
    glTranslated(-400, -545, 0);
    //blade head
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2i(394,530);
        glVertex2i(406,530);
        glVertex2i(406,560);
        glVertex2i(394,560);
    glEnd();

    //blade1 (upwards at start)
    glColor3ub(128,128,128);
    glBegin(GL_POLYGON);
        glVertex2i(











































                   395,560);
        glVertex2i(405,560);
        glVertex2i(405,600);
        glVertex2i(395,600);
    glEnd();

    glColor3ub(128,128,128);
    glBegin(GL_POLYGON);
        glVertex2i(395,600);
        glVertex2i(405,600);
        glVertex2i(405,760);
        glVertex2i(395,760);
    glEnd();

    glColor3ub(105,105,105);
    glBegin(GL_POLYGON);
        glVertex2i(385,600);
        glVertex2i(395,600);
        glVertex2i(395,760);
        glVertex2i(385,760);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(405,600);
        glVertex2i(410,600);
        glVertex2i(410,616);
        glVertex2i(405,616);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(405,616);
        glVertex2i(410,616);
        glVertex2i(410,632);
        glVertex2i(405,632);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(410,616);
        glVertex2i(419,616);
        glVertex2i(419,632);
        glVertex2i(410,632);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(405,632);
        glVertex2i(410,632);
        glVertex2i(410,648);
        glVertex2i(405,648);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(410,632);
        glVertex2i(419,632);
        glVertex2i(419,648);
        glVertex2i(410,648);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(419,632);
        glVertex2i(428,632);
        glVertex2i(428,648);
        glVertex2i(419,648);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(405,648);
        glVertex2i(410,648);
        glVertex2i(410,664);
        glVertex2i(405,664);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(410,648);
        glVertex2i(419,648);
        glVertex2i(419,664);
        glVertex2i(410,664);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(419,648);
        glVertex2i(428,648);
        glVertex2i(428,664);
        glVertex2i(419,664);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(405,664);
        glVertex2i(410,664);
        glVertex2i(410,680);
        glVertex2i(405,680);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(410,664);
        glVertex2i(419,664);
        glVertex2i(419,680);
        glVertex2i(410,680);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(419,664);
        glVertex2i(428,664);
        glVertex2i(428,680);
        glVertex2i(419,680);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(405,680);
        glVertex2i(410,680);
        glVertex2i(410,696);
        glVertex2i(405,696);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(410,680);
        glVertex2i(419,680);
        glVertex2i(419,696);
        glVertex2i(410,696);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(419,680);
        glVertex2i(428,680);
        glVertex2i(428,696);
        glVertex2i(419,696);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(405,696);
        glVertex2i(410,696);
        glVertex2i(410,712);
        glVertex2i(405,712);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(410,696);
        glVertex2i(419,696);
        glVertex2i(419,712);
        glVertex2i(410,712);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(419,696);
        glVertex2i(428,696);
        glVertex2i(428,712);
        glVertex2i(419,712);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(405,712);
        glVertex2i(410,712);
        glVertex2i(410,728);
        glVertex2i(405,728);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(410,712);
        glVertex2i(419,712);
        glVertex2i(419,728);
        glVertex2i(410,728);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(419,712);
        glVertex2i(428,712);
        glVertex2i(428,728);
        glVertex2i(419,728);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(405,728);
        glVertex2i(410,728);
        glVertex2i(410,744);
        glVertex2i(405,744);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(410,728);
        glVertex2i(419,728);
        glVertex2i(419,744);
        glVertex2i(410,744);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(419,728);
        glVertex2i(428,728);
        glVertex2i(428,744);
        glVertex2i(419,744);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(405,744);
        glVertex2i(410,744);
        glVertex2i(410,760);
        glVertex2i(405,760);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(410,744);
        glVertex2i(419,744);
        glVertex2i(419,760);
        glVertex2i(410,760);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(419,744);
        glVertex2i(428,744);
        glVertex2i(428,760);
        glVertex2i(419,760);
    glEnd();


    //blade2 (downwards at start)
    glColor3ub(128,128,128);
    glBegin(GL_POLYGON);
        glVertex2i(395,530);
        glVertex2i(405,530);
        glVertex2i(405,490);
        glVertex2i(395,490);
    glEnd();

    glColor3ub(128,128,128);
    glBegin(GL_POLYGON);
        glVertex2i(395,490);
        glVertex2i(405,490);
        glVertex2i(405,330);
        glVertex2i(395,330);
    glEnd();

    glColor3ub(105,105,105);
    glBegin(GL_POLYGON);
        glVertex2i(405,490);
        glVertex2i(415,490);
        glVertex2i(415,330);
        glVertex2i(405,330);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(395,490);
        glVertex2i(390,490);
        glVertex2i(390,474);
        glVertex2i(395,474);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(395,474);
        glVertex2i(390,474);
        glVertex2i(390,458);
        glVertex2i(395,458);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(390,474);
        glVertex2i(381,474);
        glVertex2i(381,458);
        glVertex2i(390,458);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(395,458);
        glVertex2i(390,458);
        glVertex2i(390,442);
        glVertex2i(395,442);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(390,458);
        glVertex2i(381,458);
        glVertex2i(381,442);
        glVertex2i(390,442);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(381,458);
        glVertex2i(372,458);
        glVertex2i(372,442);
        glVertex2i(381,442);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(395,442);
        glVertex2i(390,442);
        glVertex2i(390,426);
        glVertex2i(395,426);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(390,442);
        glVertex2i(381,442);
        glVertex2i(381,426);
        glVertex2i(390,426);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(381,442);
        glVertex2i(372,442);
        glVertex2i(372,426);
        glVertex2i(381,426);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(395,426);
        glVertex2i(390,426);
        glVertex2i(390,410);
        glVertex2i(395,410);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(390,426);
        glVertex2i(381,426);
        glVertex2i(381,410);
        glVertex2i(390,410);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(381,426);
        glVertex2i(372,426);
        glVertex2i(372,410);
        glVertex2i(381,410);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(395,410);
        glVertex2i(390,410);
        glVertex2i(390,394);
        glVertex2i(395,394);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(390,410);
        glVertex2i(381,410);
        glVertex2i(381,394);
        glVertex2i(390,394);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(381,410);
        glVertex2i(372,410);
        glVertex2i(372,394);
        glVertex2i(381,394);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(395,394);
        glVertex2i(390,394);
        glVertex2i(390,378);
        glVertex2i(395,378);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(390,394);
        glVertex2i(381,394);
        glVertex2i(381,378);
        glVertex2i(390,378);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(381,394);
        glVertex2i(372,394);
        glVertex2i(372,378);
        glVertex2i(381,378);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(395,378);
        glVertex2i(390,378);
        glVertex2i(390,362);
        glVertex2i(395,362);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(390,378);
        glVertex2i(381,378);
        glVertex2i(381,362);
        glVertex2i(390,362);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(381,378);
        glVertex2i(372,378);
        glVertex2i(372,362);
        glVertex2i(381,362);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(395,362);
        glVertex2i(390,362);
        glVertex2i(390,346);
        glVertex2i(395,346);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(390,362);
        glVertex2i(381,362);
        glVertex2i(381,346);
        glVertex2i(390,346);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(381,362);
        glVertex2i(372,362);
        glVertex2i(372,346);
        glVertex2i(381,346);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(395,346);
        glVertex2i(390,346);
        glVertex2i(390,330);
        glVertex2i(395,330);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(390,346);
        glVertex2i(381,346);
        glVertex2i(381,330);
        glVertex2i(390,330);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(381,346);
        glVertex2i(372,346);
        glVertex2i(372,330);
        glVertex2i(381,330);
    glEnd();

    //blade3 (leftwards on start)
    glColor3ub(128,128,128);
    glBegin(GL_POLYGON);
        glVertex2f(394,536.5);
        glVertex2f(354,536.5);
        glVertex2f(354,546.5);
        glVertex2f(394,546.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(354,536.5);
        glVertex2f(194,536.5);
        glVertex2f(194,546.5);
        glVertex2f(354,546.5);
    glEnd();

    glColor3ub(105,105,105);
    glBegin(GL_POLYGON);
        glVertex2f(354,526.5);
        glVertex2f(194,526.5);
        glVertex2f(194,536.5);
        glVertex2f(354,536.5);
    glEnd();

    glColor3ub(128,128,128);

    glBegin(GL_LINE_LOOP);
        glVertex2f(354,546.5);
        glVertex2f(338,546.5);
        glVertex2f(338,551.5);
        glVertex2f(354,551.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(338,546.5);
        glVertex2f(322,546.5);
        glVertex2f(322,551.5);
        glVertex2f(338,551.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(338,551.5);
        glVertex2f(322,551.5);
        glVertex2f(322,560.5);
        glVertex2f(338,560.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(322,546.5);
        glVertex2f(306,546.5);
        glVertex2f(306,551.5);
        glVertex2f(322,551.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(322,551.5);
        glVertex2f(306,551.5);
        glVertex2f(306,560.5);
        glVertex2f(322,560.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(322,560.5);
        glVertex2f(306,560.5);
        glVertex2f(306,569.5);
        glVertex2f(322,569.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(306,546.5);
        glVertex2f(290,546.5);
        glVertex2f(290,551.5);
        glVertex2f(306,551.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(306,551.5);
        glVertex2f(290,551.5);
        glVertex2f(290,560.5);
        glVertex2f(306,560.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(306,560.5);
        glVertex2f(290,560.5);
        glVertex2f(290,569.5);
        glVertex2f(306,569.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(290,546.5);
        glVertex2f(274,546.5);
        glVertex2f(274,551.5);
        glVertex2f(290,551.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(290,551.5);
        glVertex2f(274,551.5);
        glVertex2f(274,560.5);
        glVertex2f(290,560.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(290,560.5);
        glVertex2f(274,560.5);
        glVertex2f(274,569.5);
        glVertex2f(290,569.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(274,546.5);
        glVertex2f(258,546.5);
        glVertex2f(258,551.5);
        glVertex2f(274,551.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(274,551.5);
        glVertex2f(258,551.5);
        glVertex2f(258,560.5);
        glVertex2f(274,560.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(274,560.5);
        glVertex2f(258,560.5);
        glVertex2f(258,569.5);
        glVertex2f(274,569.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(258,546.5);
        glVertex2f(242,546.5);
        glVertex2f(242,551.5);
        glVertex2f(258,551.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(258,551.5);
        glVertex2f(242,551.5);
        glVertex2f(242,560.5);
        glVertex2f(258,560.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(258,560.5);
        glVertex2f(242,560.5);
        glVertex2f(242,569.5);
        glVertex2f(258,569.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(242,546.5);
        glVertex2f(226,546.5);
        glVertex2f(226,551.5);
        glVertex2f(242,551.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(242,551.5);
        glVertex2f(226,551.5);
        glVertex2f(226,560.5);
        glVertex2f(242,560.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(242,560.5);
        glVertex2f(226,560.5);
        glVertex2f(226,569.5);
        glVertex2f(242,569.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(226,546.5);
        glVertex2f(210,546.5);
        glVertex2f(210,551.5);
        glVertex2f(226,551.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(226,551.5);
        glVertex2f(210,551.5);
        glVertex2f(210,560.5);
        glVertex2f(226,560.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(226,560.5);
        glVertex2f(210,560.5);
        glVertex2f(210,569.5);
        glVertex2f(226,569.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(210,546.5);
        glVertex2f(194,546.5);
        glVertex2f(194,551.5);
        glVertex2f(210,551.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(210,551.5);
        glVertex2f(194,551.5);
        glVertex2f(194,560.5);
        glVertex2f(210,560.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(210,560.5);
        glVertex2f(194,560.5);
        glVertex2f(194,569.5);
        glVertex2f(210,569.5);
    glEnd();

    //blade4(rightwards at start)
    glColor3ub(128,128,128);
    glBegin(GL_POLYGON);
        glVertex2f(406,536.5);
        glVertex2f(446,536.5);
        glVertex2f(446,546.5);
        glVertex2f(406,546.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(446,536.5);
        glVertex2f(606,536.5);
        glVertex2f(606,546.5);
        glVertex2f(446,546.5);
    glEnd();

    glColor3ub(105,105,105);
    glBegin(GL_POLYGON);
        glVertex2f(446,546.5);
        glVertex2f(606,546.5);
        glVertex2f(606,556.5);
        glVertex2f(446,556.5);
    glEnd();

    glColor3ub(128,128,128);

    glBegin(GL_LINE_LOOP);
        glVertex2f(446,536.5);
        glVertex2f(462,536.5);
        glVertex2f(462,531.5);
        glVertex2f(446,531.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(462,536.5);
        glVertex2f(478,536.5);
        glVertex2f(478,531.5);
        glVertex2f(462,531.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(462,531.5);
        glVertex2f(478,531.5);
        glVertex2f(478,522.5);
        glVertex2f(462,522.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(478,536.5);
        glVertex2f(494,536.5);
        glVertex2f(494,531.5);
        glVertex2f(478,531.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(478,531.5);
        glVertex2f(494,531.5);
        glVertex2f(494,522.5);
        glVertex2f(478,522.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(478,522.5);
        glVertex2f(494,522.5);
        glVertex2f(494,513.5);
        glVertex2f(478,513.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(494,536.5);
        glVertex2f(510,536.5);
        glVertex2f(510,531.5);
        glVertex2f(494,531.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(494,531.5);
        glVertex2f(510,531.5);
        glVertex2f(510,522.5);
        glVertex2f(494,522.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(494,522.5);
        glVertex2f(510,522.5);
        glVertex2f(510,513.5);
        glVertex2f(494,513.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(510,536.5);
        glVertex2f(526,536.5);
        glVertex2f(526,531.5);
        glVertex2f(510,531.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(510,531.5);
        glVertex2f(526,531.5);
        glVertex2f(526,522.5);
        glVertex2f(510,522.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(510,522.5);
        glVertex2f(526,522.5);
        glVertex2f(526,513.5);
        glVertex2f(510,513.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(526,536.5);
        glVertex2f(542,536.5);
        glVertex2f(542,531.5);
        glVertex2f(526,531.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(526,531.5);
        glVertex2f(542,531.5);
        glVertex2f(542,522.5);
        glVertex2f(526,522.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(526,522.5);
        glVertex2f(542,522.5);
        glVertex2f(542,513.5);
        glVertex2f(526,513.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(542,536.5);
        glVertex2f(558,536.5);
        glVertex2f(558,531.5);
        glVertex2f(542,531.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(542,531.5);
        glVertex2f(558,531.5);
        glVertex2f(558,522.5);
        glVertex2f(542,522.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(542,522.5);
        glVertex2f(558,522.5);
        glVertex2f(558,513.5);
        glVertex2f(542,513.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(558,536.5);
        glVertex2f(574,536.5);
        glVertex2f(574,531.5);
        glVertex2f(558,531.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(558,531.5);
        glVertex2f(574,531.5);
        glVertex2f(574,522.5);
        glVertex2f(558,522.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(558,522.5);
        glVertex2f(574,522.5);
        glVertex2f(574,513.5);
        glVertex2f(558,513.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(574,536.5);
        glVertex2f(590,536.5);
        glVertex2f(590,531.5);
        glVertex2f(574,531.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(574,531.5);
        glVertex2f(590,531.5);
        glVertex2f(590,522.5);
        glVertex2f(574,522.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(574,522.5);
        glVertex2f(590,522.5);
        glVertex2f(590,513.5);
        glVertex2f(574,513.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(590,536.5);
        glVertex2f(606,536.5);
        glVertex2f(606,531.5);
        glVertex2f(590,531.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(590,531.5);
        glVertex2f(606,531.5);
        glVertex2f(606,522.5);
        glVertex2f(590,522.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(590,522.5);
        glVertex2f(606,522.5);
        glVertex2f(606,513.5);
        glVertex2f(590,513.5);
    glEnd();


    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}


static void displayNight(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3ub(0,50,23);
    glBegin(GL_QUADS);
        //earth
        glVertex2i(0,0);
        glVertex2i(700,0);
        glVertex2i(630,700);
        glVertex2i(0,700);

        //river
        glColor3ub(	0, 10, 60);
        glVertex2i(700,0);
        glVertex2i(1000,0);
        glVertex2i(1000,700);
        glVertex2i(630,700);

        //sky
        glColor3ub(0,20,30);
        glVertex2i(0,1000);
        glVertex2i(1000,1000);
        glVertex2i(1000,700);
        glVertex2i(0,700);
    glEnd();

    //earth add-ons
    glColor3ub(	0, 10, 60);
    circle(10,30, 635, 670);
    circle(20,80, 650, 620);
    circle(30,110, 655, 540);
    circle(20,70, 665, 360);
    circle(20,70, 675, 300);
    circle(100,100, 750, 100);

    //boat
    glColor3ub(30, 30, 0);
    glPushMatrix();
    glTranslated(-boatMove/2, boatMove, 0);
    glBegin(GL_TRIANGLES);
        glVertex2i(660,100);
        glVertex2i(690,50);
        glVertex2i(690,75);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2i(780,50);
        glVertex2i(800,100);
        glVertex2i(780,75);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2i(690,50);
        glVertex2i(690,75);
        glVertex2i(780,75);
        glVertex2i(780,50);
    glEnd();

    glColor3ub(50,50,30);
    glBegin(GL_TRIANGLES);
        glVertex2i(660,100);
        glVertex2i(690,75);
        glVertex2i(690,100);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2i(780,100);
        glVertex2i(800,100);
        glVertex2i(780,75);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2i(690,75);
        glVertex2i(690,100);
        glVertex2i(780,100);
        glVertex2i(780,75);
    glEnd();


    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2i(690,75);
        glVertex2i(690,100);
        glVertex2i(695,100);
        glVertex2i(695,75);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2i(775,75);
        glVertex2i(775,100);
        glVertex2i(780,100);
        glVertex2i(780,75);
    glEnd();

    glPopMatrix();




    glPushMatrix();
    glTranslated(-boatMove/2, boatMove, 0);
    glTranslated(-10, 250, 0);
    glBegin(GL_TRIANGLES);
        glVertex2i(660,100);
        glVertex2i(690,50);
        glVertex2i(690,75);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2i(780,50);
        glVertex2i(800,100);
        glVertex2i(780,75);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2i(690,50);
        glVertex2i(690,75);
        glVertex2i(780,75);
        glVertex2i(780,50);
    glEnd();

    glColor3ub(50,50,30);
    glBegin(GL_TRIANGLES);
        glVertex2i(660,100);
        glVertex2i(690,75);
        glVertex2i(690,100);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2i(780,100);
        glVertex2i(800,100);
        glVertex2i(780,75);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2i(690,75);
        glVertex2i(690,100);
        glVertex2i(780,100);
        glVertex2i(780,75);
    glEnd();


    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2i(690,75);
        glVertex2i(690,100);
        glVertex2i(695,100);
        glVertex2i(695,75);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2i(775,75);
        glVertex2i(775,100);
        glVertex2i(780,100);
        glVertex2i(780,75);
    glEnd();

    glPopMatrix();



    //moon
    glColor3ub(240, 240, 240);
    circle(30, 55, 600, 850);


    //stars
    circle(2,2,700,850);
    circle(3,2,800,900);
    circle(4,4,850,920);
    circle(2,2,400,800);
    circle(2,2,200,820);
    circle(3,2,100,950);
    circle(2,2,350,930);
    circle(2,2,500,830);
    circle(1,1,50,960);


    //hills
    glColor3ub(0,30,0);
    glBegin(GL_POLYGON);
        glVertex2i(20,700);
        glVertex2i(120,700);
        glVertex2i(105,745);
        glVertex2i(85,765);
        glVertex2i(55,765);
        glVertex2i(35,745);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(120,700);
        glVertex2i(160,750);
        glVertex2i(220,780);
        glVertex2i(280,750);
        glVertex2i(320,700);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(317,700);
        glVertex2i(327,720);
        glVertex2i(347,740);
        glVertex2i(367,720);
        glVertex2i(377,700);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(377,700);
        glVertex2i(407,745);
        glVertex2i(447,785);
        glVertex2i(497,800);
        glVertex2i(557,785);
        glVertex2i(597,745);
        glVertex2i(627,700);
    glEnd();

    //trees
    glColor3ub(33, 31, 6);
    glPushMatrix();
    glTranslated(100,500, 0);
    glutSolidSphere(20, 100, 100);
    glPopMatrix();

    glBegin(GL_POLYGON);
        glVertex2i(80,490);
        glVertex2i(120,490);
        glVertex2i(110,600);
        glVertex2i(90, 600);
    glEnd();

    glColor3ub(10,60,15);
    glBegin(GL_POLYGON);
        glVertex2i(60,600);
        glVertex2i(140,600);
        glVertex2i(120,630);
        glVertex2i(80, 630);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(60,630);
        glVertex2i(140,630);
        glVertex2i(100,750);
    glEnd();


    glColor3ub(33, 31, 6);
    glPushMatrix();
    glTranslated(500,520, 0);
    glutSolidSphere(20, 100, 100);
    glPopMatrix();

    glBegin(GL_POLYGON);
        glVertex2i(480,510);
        glVertex2i(520,510);
        glVertex2i(510,620);
        glVertex2i(490,620);
    glEnd();

    glColor3ub(10,60,15);
    glBegin(GL_POLYGON);
        glVertex2i(480,620);
        glVertex2i(520,620);
        glVertex2i(510,650);
        glVertex2i(490, 650);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(480,650);
        glVertex2i(520,650);
        glVertex2i(500,770);
    glEnd();


    glColor3ub(33, 31, 6);
    glPushMatrix();
    glTranslated(250,530, 0);
    glutSolidSphere(20, 100, 100);
    glPopMatrix();

    glBegin(GL_POLYGON);
        glVertex2i(230,520);
        glVertex2i(270,520);
        glVertex2i(260,630);
        glVertex2i(240,630);
    glEnd();

    glColor3ub(10,60,15);
    glBegin(GL_POLYGON);
        glVertex2i(210,630);
        glVertex2i(290,630);
        glVertex2i(270,660);
        glVertex2i(230, 660);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(210,660);
        glVertex2i(290,660);
        glVertex2i(250,780);
    glEnd();

    glColor3ub(33, 31, 6);
    glPushMatrix();
    glTranslated(380,550, 0);
    glutSolidSphere(20, 100, 100);
    glPopMatrix();

    glBegin(GL_POLYGON);
        glVertex2i(360,540);
        glVertex2i(400,540);
        glVertex2i(390,650);
        glVertex2i(370,650);
    glEnd();

    glColor3ub(10,60,15);
    glBegin(GL_POLYGON);
        glVertex2i(360,650);
        glVertex2i(400,650);
        glVertex2i(390,680);
        glVertex2i(370, 680);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(360,680);
        glVertex2i(400,680);
        glVertex2i(380,800);
    glEnd();

    //shed
    glColor3ub(139, 128, 0);
    glBegin(GL_POLYGON);
        glVertex2i(70,120);
        glVertex2i(220,120);
        glVertex2i(220,270);
        glVertex2i(70, 270);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_LINES);
        glVertex2i(70,120);
        glVertex2i(20,140);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(70,120);
        glVertex2i(220,120);
        glVertex2i(220,270);
        glVertex2i(70, 270);
    glEnd();

    glBegin(GL_LINES);
        glVertex2i(20,140);
        glVertex2i(20,270);
    glEnd();

    glBegin(GL_LINES);
        glVertex2i(20,270);
        glVertex2i(38,390);
    glEnd();

    glBegin(GL_LINES);
        glVertex2i(70,270);
        glVertex2i(38,390);
    glEnd();

    glBegin(GL_LINES);
        glVertex2i(220,270);
        glVertex2i(188,390);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(188,390.5);
        glVertex2f(38,390.5);
    glEnd();

    glColor3ub(139, 128, 0);
    glBegin(GL_POLYGON);
        glVertex2f(69.8,121);
        glVertex2i(20,141);
        glVertex2i(20,270);
        glVertex2f(69.8, 270);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(69.8,269.8);
        glVertex2f(20.5, 269.8);
        glVertex2f(38.2,390);
    glEnd();

    glColor3ub(50,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(70.5,270);
        glVertex2i(220,270);
        glVertex2i(188,390);
        glVertex2f(38.7, 390);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_LINES);
        glVertex2i(70,269);
        glVertex2i(220,269);
    glEnd();


    glColor3ub(26, 17, 16);
    glBegin(GL_POLYGON);
        glVertex2f(50,280);
        glVertex2i(35,286);
        glVertex2i(35,336);
        glVertex2f(50, 330);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(50,170);
        glVertex2i(35,176);
        glVertex2i(35,226);
        glVertex2f(50, 220);
    glEnd();

    glColor3ub(26, 17, 16);
    glBegin(GL_LINES);
        glVertex2f(35,311);
        glVertex2f(50,305);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(42.5,333);
        glVertex2f(42.5,283);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(35,201);
        glVertex2f(50,195);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(42.5,223);
        glVertex2f(42.5,173);
    glEnd();

    //door
    glColor3ub(58,43,36);
    glBegin(GL_POLYGON);
        glVertex2i(90,120);
        glVertex2i(120,120);
        glVertex2i(120,220);
        glVertex2i(90,220);
    glEnd();
    glColor3ub(0,0,0);
    circle(2,4,115, 165);

    glColor3ub(26, 17, 16);
    glBegin(GL_POLYGON);
        glVertex2f(160,230);
        glVertex2i(200,230);
        glVertex2i(200,160);
        glVertex2f(160, 160);
    glEnd();

    glColor3ub(26, 17, 16);
    glBegin(GL_LINES);
        glVertex2f(160,195);
        glVertex2f(200,195);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(180,230);
        glVertex2f(180,160);
    glEnd();

    //circle(100, 100, 400, 200);
    //windmill base
    glColor3ub(84,11,12);
    glPushMatrix();
    glTranslated(400,200, 0);
    glutSolidSphere(100, 100, 200);
    glPopMatrix();
    glColor3ub(84,11,12);

    glBegin(GL_POLYGON);
        glVertex2i(300,200);
        glVertex2i(360,530);
        glVertex2i(392,580);
        glVertex2i(408,580);
        glVertex2i(440,530);
        glVertex2i(500,200);
    glEnd();

    //head attachment
    glColor3ub(1,14,10);
    glBegin(GL_POLYGON);
        glVertex2i(350,505);
        glVertex2i(350,535);
        glVertex2i(380,570);
        glVertex2i(400,600);
        glVertex2i(420,570);
        glVertex2i(450,535);
        glVertex2i(450,505);
    glEnd();


    //windmill windows
    glColor3ub(40, 40, 40);
    glBegin(GL_POLYGON);
        glVertex2i(391,495);
        glVertex2i(409,495);
        glVertex2i(409,456);
        glVertex2i(391,456);
    glEnd();
    glColor3ub(26, 17, 16);
    glBegin(GL_POLYGON);
        glVertex2i(394,488);
        glVertex2i(406,488);
        glVertex2i(406,463);
        glVertex2i(394,463);
    glEnd();
    glColor3ub(26, 17, 16);
    glBegin(GL_LINES);
        glVertex2f(394.0,475.5);
        glVertex2f(406.0,475.5);
    glEnd();
    glBegin(GL_LINES);
        glVertex2i(400,488);
        glVertex2i(400,463);
    glEnd();

    glColor3ub(40,40,40);
    glBegin(GL_POLYGON);
        glVertex2i(386,400);
        glVertex2i(414,400);
        glVertex2i(414,340);
        glVertex2i(386,340);
    glEnd();
    glColor3ub(26, 17, 16);
    glBegin(GL_POLYGON);
        glVertex2i(388,390);
        glVertex2i(412,390);
        glVertex2i(412,350);
        glVertex2i(388,350);
    glEnd();
    glColor3ub(26, 17, 16);
    glBegin(GL_LINES);
        glVertex2f(388.0,370.0);
        glVertex2f(412.0,370.0);
    glEnd();
    glBegin(GL_LINES);
        glVertex2i(400,390);
        glVertex2i(400,350);
    glEnd();


    //windmill door
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2i(370,105);
        glVertex2i(430,105);
        glVertex2i(430,225);
        glVertex2i(400,235);
        glVertex2i(370,225);

    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(370,105);
        glVertex2f(382,103);
        glVertex2i(400,100);
        glVertex2f(420,103);
        glVertex2i(430,105);
    glEnd();

    glColor3ub(40, 41, 5);
    glBegin(GL_POLYGON);
        glVertex2i(370,105);
        glVertex2f(373,105);
        glVertex2i(373,225);
        glVertex2f(370,225);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(430,105);
        glVertex2f(427,105);
        glVertex2i(427,225);
        glVertex2f(430,225);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(370,225);
        glVertex2f(373,222);
        glVertex2i(400,232);
        glVertex2f(400,235);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(430,225);
        glVertex2f(427,222);
        glVertex2f(400,232);
        glVertex2i(400,235);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(350,235);
        glVertex2f(370,225);
        glVertex2f(370,105);
        glVertex2i(350,105);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(430,225);
        glVertex2f(450,235);
        glVertex2f(450,105);
        glVertex2i(430,105);
    glEnd();

    glColor3ub(40, 41, 5);
    glBegin(GL_POLYGON);
        glVertex2i(350,235);
        glVertex2f(347,235);
        glVertex2f(347,105);
        glVertex2i(350,105);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(450,235);
        glVertex2f(453,235);
        glVertex2f(453,105);
        glVertex2i(450,105);
    glEnd();

    //blade holder
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2i(390,525);
        glVertex2i(410,525);
        glVertex2i(410,565);
        glVertex2i(390,565);
    glEnd();
    //blade mechanism
    glPushMatrix();
    glTranslated(400, 545, 0);
    glRotatef(rotateBlade, 0, 0, 1.0);
    glTranslated(-400, -545, 0);
    //blade head
    glColor3ub(0,0,0);
    //glPushMatrix();
    glBegin(GL_POLYGON);
        glVertex2i(394,530);
        glVertex2i(406,530);
        glVertex2i(406,560);
        glVertex2i(394,560);
    glEnd();
    //glPopMatrix();

    //blade1 (upwards at start)
    glColor3ub(45,45,45);

    glBegin(GL_POLYGON);
        glVertex2i(395,560);
        glVertex2i(405,560);
        glVertex2i(405,600);
        glVertex2i(395,600);
    glEnd();


    glColor3ub(45,45,45);

    glBegin(GL_POLYGON);
        glVertex2i(395,600);
        glVertex2i(405,600);
        glVertex2i(405,760);
        glVertex2i(395,760);
    glEnd();


    glColor3ub(40,40,40);

    glBegin(GL_POLYGON);
        glVertex2i(385,600);
        glVertex2i(395,600);
        glVertex2i(395,760);
        glVertex2i(385,760);
    glEnd();


    glColor3ub(50,50,50);

    glBegin(GL_LINE_LOOP);
        glVertex2i(405,600);
        glVertex2i(410,600);
        glVertex2i(410,616);
        glVertex2i(405,616);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(405,616);
        glVertex2i(410,616);
        glVertex2i(410,632);
        glVertex2i(405,632);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(410,616);
        glVertex2i(419,616);
        glVertex2i(419,632);
        glVertex2i(410,632);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(405,632);
        glVertex2i(410,632);
        glVertex2i(410,648);
        glVertex2i(405,648);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(410,632);
        glVertex2i(419,632);
        glVertex2i(419,648);
        glVertex2i(410,648);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(419,632);
        glVertex2i(428,632);
        glVertex2i(428,648);
        glVertex2i(419,648);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(405,648);
        glVertex2i(410,648);
        glVertex2i(410,664);
        glVertex2i(405,664);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(410,648);
        glVertex2i(419,648);
        glVertex2i(419,664);
        glVertex2i(410,664);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(419,648);
        glVertex2i(428,648);
        glVertex2i(428,664);
        glVertex2i(419,664);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(405,664);
        glVertex2i(410,664);
        glVertex2i(410,680);
        glVertex2i(405,680);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(410,664);
        glVertex2i(419,664);
        glVertex2i(419,680);
        glVertex2i(410,680);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(419,664);
        glVertex2i(428,664);
        glVertex2i(428,680);
        glVertex2i(419,680);
    glEnd();



    glBegin(GL_LINE_LOOP);
        glVertex2i(405,680);
        glVertex2i(410,680);
        glVertex2i(410,696);
        glVertex2i(405,696);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(410,680);
        glVertex2i(419,680);
        glVertex2i(419,696);
        glVertex2i(410,696);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(419,680);
        glVertex2i(428,680);
        glVertex2i(428,696);
        glVertex2i(419,696);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(405,696);
        glVertex2i(410,696);
        glVertex2i(410,712);
        glVertex2i(405,712);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(410,696);
        glVertex2i(419,696);
        glVertex2i(419,712);
        glVertex2i(410,712);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(419,696);
        glVertex2i(428,696);
        glVertex2i(428,712);
        glVertex2i(419,712);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(405,712);
        glVertex2i(410,712);
        glVertex2i(410,728);
        glVertex2i(405,728);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(410,712);
        glVertex2i(419,712);
        glVertex2i(419,728);
        glVertex2i(410,728);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(419,712);
        glVertex2i(428,712);
        glVertex2i(428,728);
        glVertex2i(419,728);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(405,728);
        glVertex2i(410,728);
        glVertex2i(410,744);
        glVertex2i(405,744);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(410,728);
        glVertex2i(419,728);
        glVertex2i(419,744);
        glVertex2i(410,744);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(419,728);
        glVertex2i(428,728);
        glVertex2i(428,744);
        glVertex2i(419,744);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(405,744);
        glVertex2i(410,744);
        glVertex2i(410,760);
        glVertex2i(405,760);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(410,744);
        glVertex2i(419,744);
        glVertex2i(419,760);
        glVertex2i(410,760);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(419,744);
        glVertex2i(428,744);
        glVertex2i(428,760);
        glVertex2i(419,760);
    glEnd();


    //blade2 (downwards at start)
    glColor3ub(45,45,45);
    glBegin(GL_POLYGON);
        glVertex2i(395,530);
        glVertex2i(405,530);
        glVertex2i(405,490);
        glVertex2i(395,490);
    glEnd();

    glColor3ub(45,45,45);
    glBegin(GL_POLYGON);
        glVertex2i(395,490);
        glVertex2i(405,490);
        glVertex2i(405,330);
        glVertex2i(395,330);
    glEnd();

    glColor3ub(40,40,40);
    glBegin(GL_POLYGON);
        glVertex2i(405,490);
        glVertex2i(415,490);
        glVertex2i(415,330);
        glVertex2i(405,330);
    glEnd();

    glColor3ub(50,50,50);

    glBegin(GL_LINE_LOOP);
        glVertex2i(395,490);
        glVertex2i(390,490);
        glVertex2i(390,474);
        glVertex2i(395,474);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(395,474);
        glVertex2i(390,474);
        glVertex2i(390,458);
        glVertex2i(395,458);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(390,474);
        glVertex2i(381,474);
        glVertex2i(381,458);
        glVertex2i(390,458);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(395,458);
        glVertex2i(390,458);
        glVertex2i(390,442);
        glVertex2i(395,442);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(390,458);
        glVertex2i(381,458);
        glVertex2i(381,442);
        glVertex2i(390,442);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(381,458);
        glVertex2i(372,458);
        glVertex2i(372,442);
        glVertex2i(381,442);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(395,442);
        glVertex2i(390,442);
        glVertex2i(390,426);
        glVertex2i(395,426);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(390,442);
        glVertex2i(381,442);
        glVertex2i(381,426);
        glVertex2i(390,426);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(381,442);
        glVertex2i(372,442);
        glVertex2i(372,426);
        glVertex2i(381,426);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(395,426);
        glVertex2i(390,426);
        glVertex2i(390,410);
        glVertex2i(395,410);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(390,426);
        glVertex2i(381,426);
        glVertex2i(381,410);
        glVertex2i(390,410);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(381,426);
        glVertex2i(372,426);
        glVertex2i(372,410);
        glVertex2i(381,410);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(395,410);
        glVertex2i(390,410);
        glVertex2i(390,394);
        glVertex2i(395,394);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(390,410);
        glVertex2i(381,410);
        glVertex2i(381,394);
        glVertex2i(390,394);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(381,410);
        glVertex2i(372,410);
        glVertex2i(372,394);
        glVertex2i(381,394);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(395,394);
        glVertex2i(390,394);
        glVertex2i(390,378);
        glVertex2i(395,378);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(390,394);
        glVertex2i(381,394);
        glVertex2i(381,378);
        glVertex2i(390,378);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(381,394);
        glVertex2i(372,394);
        glVertex2i(372,378);
        glVertex2i(381,378);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(395,378);
        glVertex2i(390,378);
        glVertex2i(390,362);
        glVertex2i(395,362);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(390,378);
        glVertex2i(381,378);
        glVertex2i(381,362);
        glVertex2i(390,362);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(381,378);
        glVertex2i(372,378);
        glVertex2i(372,362);
        glVertex2i(381,362);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(395,362);
        glVertex2i(390,362);
        glVertex2i(390,346);
        glVertex2i(395,346);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(390,362);
        glVertex2i(381,362);
        glVertex2i(381,346);
        glVertex2i(390,346);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(381,362);
        glVertex2i(372,362);
        glVertex2i(372,346);
        glVertex2i(381,346);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(395,346);
        glVertex2i(390,346);
        glVertex2i(390,330);
        glVertex2i(395,330);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(390,346);
        glVertex2i(381,346);
        glVertex2i(381,330);
        glVertex2i(390,330);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(381,346);
        glVertex2i(372,346);
        glVertex2i(372,330);
        glVertex2i(381,330);
    glEnd();

    //blade3 (leftwards on start)
    glColor3ub(45,45,45);
    glBegin(GL_POLYGON);
        glVertex2f(394,536.5);
        glVertex2f(354,536.5);
        glVertex2f(354,546.5);
        glVertex2f(394,546.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(354,536.5);
        glVertex2f(194,536.5);
        glVertex2f(194,546.5);
        glVertex2f(354,546.5);
    glEnd();

    glColor3ub(40,40,40);
    glBegin(GL_POLYGON);
        glVertex2f(354,526.5);
        glVertex2f(194,526.5);
        glVertex2f(194,536.5);
        glVertex2f(354,536.5);
    glEnd();

    glColor3ub(50,50,50);

    glBegin(GL_LINE_LOOP);
        glVertex2f(354,546.5);
        glVertex2f(338,546.5);
        glVertex2f(338,551.5);
        glVertex2f(354,551.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(338,546.5);
        glVertex2f(322,546.5);
        glVertex2f(322,551.5);
        glVertex2f(338,551.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(338,551.5);
        glVertex2f(322,551.5);
        glVertex2f(322,560.5);
        glVertex2f(338,560.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(322,546.5);
        glVertex2f(306,546.5);
        glVertex2f(306,551.5);
        glVertex2f(322,551.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(322,551.5);
        glVertex2f(306,551.5);
        glVertex2f(306,560.5);
        glVertex2f(322,560.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(322,560.5);
        glVertex2f(306,560.5);
        glVertex2f(306,569.5);
        glVertex2f(322,569.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(306,546.5);
        glVertex2f(290,546.5);
        glVertex2f(290,551.5);
        glVertex2f(306,551.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(306,551.5);
        glVertex2f(290,551.5);
        glVertex2f(290,560.5);
        glVertex2f(306,560.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(306,560.5);
        glVertex2f(290,560.5);
        glVertex2f(290,569.5);
        glVertex2f(306,569.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(290,546.5);
        glVertex2f(274,546.5);
        glVertex2f(274,551.5);
        glVertex2f(290,551.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(290,551.5);
        glVertex2f(274,551.5);
        glVertex2f(274,560.5);
        glVertex2f(290,560.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(290,560.5);
        glVertex2f(274,560.5);
        glVertex2f(274,569.5);
        glVertex2f(290,569.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(274,546.5);
        glVertex2f(258,546.5);
        glVertex2f(258,551.5);
        glVertex2f(274,551.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(274,551.5);
        glVertex2f(258,551.5);
        glVertex2f(258,560.5);
        glVertex2f(274,560.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(274,560.5);
        glVertex2f(258,560.5);
        glVertex2f(258,569.5);
        glVertex2f(274,569.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(258,546.5);
        glVertex2f(242,546.5);
        glVertex2f(242,551.5);
        glVertex2f(258,551.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(258,551.5);
        glVertex2f(242,551.5);
        glVertex2f(242,560.5);
        glVertex2f(258,560.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(258,560.5);
        glVertex2f(242,560.5);
        glVertex2f(242,569.5);
        glVertex2f(258,569.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(242,546.5);
        glVertex2f(226,546.5);
        glVertex2f(226,551.5);
        glVertex2f(242,551.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(242,551.5);
        glVertex2f(226,551.5);
        glVertex2f(226,560.5);
        glVertex2f(242,560.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(242,560.5);
        glVertex2f(226,560.5);
        glVertex2f(226,569.5);
        glVertex2f(242,569.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(226,546.5);
        glVertex2f(210,546.5);
        glVertex2f(210,551.5);
        glVertex2f(226,551.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(226,551.5);
        glVertex2f(210,551.5);
        glVertex2f(210,560.5);
        glVertex2f(226,560.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(226,560.5);
        glVertex2f(210,560.5);
        glVertex2f(210,569.5);
        glVertex2f(226,569.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(210,546.5);
        glVertex2f(194,546.5);
        glVertex2f(194,551.5);
        glVertex2f(210,551.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(210,551.5);
        glVertex2f(194,551.5);
        glVertex2f(194,560.5);
        glVertex2f(210,560.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(210,560.5);
        glVertex2f(194,560.5);
        glVertex2f(194,569.5);
        glVertex2f(210,569.5);
    glEnd();

    //blade4(rightwards at start)
    glColor3ub(45,45,45);
    glBegin(GL_POLYGON);
        glVertex2f(406,536.5);
        glVertex2f(446,536.5);
        glVertex2f(446,546.5);
        glVertex2f(406,546.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(446,536.5);
        glVertex2f(606,536.5);
        glVertex2f(606,546.5);
        glVertex2f(446,546.5);
    glEnd();

    glColor3ub(40,40,40);
    glBegin(GL_POLYGON);
        glVertex2f(446,546.5);
        glVertex2f(606,546.5);
        glVertex2f(606,556.5);
        glVertex2f(446,556.5);
    glEnd();

    glColor3ub(50,50,50);

    glBegin(GL_LINE_LOOP);
        glVertex2f(446,536.5);
        glVertex2f(462,536.5);
        glVertex2f(462,531.5);
        glVertex2f(446,531.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(462,536.5);
        glVertex2f(478,536.5);
        glVertex2f(478,531.5);
        glVertex2f(462,531.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(462,531.5);
        glVertex2f(478,531.5);
        glVertex2f(478,522.5);
        glVertex2f(462,522.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(478,536.5);
        glVertex2f(494,536.5);
        glVertex2f(494,531.5);
        glVertex2f(478,531.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(478,531.5);
        glVertex2f(494,531.5);
        glVertex2f(494,522.5);
        glVertex2f(478,522.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(478,522.5);
        glVertex2f(494,522.5);
        glVertex2f(494,513.5);
        glVertex2f(478,513.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(494,536.5);
        glVertex2f(510,536.5);
        glVertex2f(510,531.5);
        glVertex2f(494,531.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(494,531.5);
        glVertex2f(510,531.5);
        glVertex2f(510,522.5);
        glVertex2f(494,522.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(494,522.5);
        glVertex2f(510,522.5);
        glVertex2f(510,513.5);
        glVertex2f(494,513.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(510,536.5);
        glVertex2f(526,536.5);
        glVertex2f(526,531.5);
        glVertex2f(510,531.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(510,531.5);
        glVertex2f(526,531.5);
        glVertex2f(526,522.5);
        glVertex2f(510,522.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(510,522.5);
        glVertex2f(526,522.5);
        glVertex2f(526,513.5);
        glVertex2f(510,513.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(526,536.5);
        glVertex2f(542,536.5);
        glVertex2f(542,531.5);
        glVertex2f(526,531.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(526,531.5);
        glVertex2f(542,531.5);
        glVertex2f(542,522.5);
        glVertex2f(526,522.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(526,522.5);
        glVertex2f(542,522.5);
        glVertex2f(542,513.5);
        glVertex2f(526,513.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(542,536.5);
        glVertex2f(558,536.5);
        glVertex2f(558,531.5);
        glVertex2f(542,531.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(542,531.5);
        glVertex2f(558,531.5);
        glVertex2f(558,522.5);
        glVertex2f(542,522.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(542,522.5);
        glVertex2f(558,522.5);
        glVertex2f(558,513.5);
        glVertex2f(542,513.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(558,536.5);
        glVertex2f(574,536.5);
        glVertex2f(574,531.5);
        glVertex2f(558,531.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(558,531.5);
        glVertex2f(574,531.5);
        glVertex2f(574,522.5);
        glVertex2f(558,522.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(558,522.5);
        glVertex2f(574,522.5);
        glVertex2f(574,513.5);
        glVertex2f(558,513.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(574,536.5);
        glVertex2f(590,536.5);
        glVertex2f(590,531.5);
        glVertex2f(574,531.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(574,531.5);
        glVertex2f(590,531.5);
        glVertex2f(590,522.5);
        glVertex2f(574,522.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(574,522.5);
        glVertex2f(590,522.5);
        glVertex2f(590,513.5);
        glVertex2f(574,513.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(590,536.5);
        glVertex2f(606,536.5);
        glVertex2f(606,531.5);
        glVertex2f(590,531.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(590,531.5);
        glVertex2f(606,531.5);
        glVertex2f(606,522.5);
        glVertex2f(590,522.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(590,522.5);
        glVertex2f(606,522.5);
        glVertex2f(606,513.5);
        glVertex2f(590,513.5);
    glEnd();

    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}


void init()
{
    glClearColor(0, 0, 0, 10);
    glOrtho(0, 1000.0, 0, 1000.0, 0, 1000.0);
}


void update(int value) {

    rotateBlade += 1;

    glutTimerFunc(20, update, 0);
    glutPostRedisplay();
}

void update2(int value) {

    boatMove += 1;
    if(boatMove > 10){
        boatMove = 0;
    }
    glutTimerFunc(150, update2, 0);
    glutPostRedisplay();
}

void update3(int value) {

    if(moveCloud > 700)
    {
        moveCloud = -1100;
    }
    moveCloud += 2;
    glutTimerFunc(20, update3, 0);
    glutPostRedisplay();
}


void special(int key, int, int) {
  switch (key) {
    //case GLUT_KEY_LEFT: (rotateBlade -= 2) %= 360; break;
    case GLUT_KEY_RIGHT: (rotateBlade += 3) %= 360;
    (boatMove) +=1;
    break;
    case GLUT_KEY_UP: glutDisplayFunc(displayDay); break;
    case GLUT_KEY_DOWN: glutDisplayFunc(displayNight); break;
    default: return;
  }
  glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1920,1080);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Projet");
    init();
    glutDisplayFunc(displayDay);
    glutTimerFunc(20, update, 0);
    glutTimerFunc(150, update2, 0);
    glutTimerFunc(20, update3, 0);
    glutSpecialFunc(special);

    glutMainLoop();

    return EXIT_SUCCESS;
}
