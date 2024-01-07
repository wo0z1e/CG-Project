#include<iostream>
#include<cstdio>
#include<windows.h>
#include<GL/glut.h>
#include<math.h>
#define PI 3.14159265358979323846

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

GLfloat position = 0.0f;//cloud
GLfloat speed = 0.001f;

GLfloat position3 = 0.0f;//wave 1
GLfloat speed3 = 0.003f;

GLfloat position4 = 0.0f;//wave 2
GLfloat speed4 = 0.003f;

GLfloat position5 = 0.0f;//ship 1
GLfloat speed5 = 0.003f;

GLfloat position51 = 0.0f;//ship1 NIGHT
GLfloat speed51 = 0.0015f;

GLfloat position6 = 0.0f;//Hanger
GLfloat speed6 = 0.0005f;

GLfloat position64 = 0.0f;//Hanger back night
GLfloat speed64 = 0.0004f;

GLfloat position7 = 0.0f;//truck
GLfloat speed7 = 0.0045f;

GLfloat position72 = 0.0f;//truck middle
GLfloat speed72 = 0.008f;

GLfloat position73 = 0.0f;//truck middle
GLfloat speed73 = 0.005f;

GLfloat position8 = 0.0f;//evening sun
GLfloat speed8 = 0.001f;

GLfloat position9 = 0.0f;//rain
GLfloat speed9 = 0.04f;

GLfloat position91 = 0.0f;//rain2
GLfloat speed91 = 0.02f;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void updateCloud(int value) {

    if(position >1.0)
        position =-1.0f;

    position += speed;

	glutPostRedisplay();

	glutTimerFunc(100, updateCloud, 0);
}


void updateWave1(int value) {

    if(position3 >1.0)
        position3 =-1.0f;

    position3 += speed3;

	glutPostRedisplay();

	glutTimerFunc(100, updateWave1, 0);
}

void updateWave2(int value) {

    if(position4 >1.0)
        position4 =-1.0f;

    position4 += speed4;

	glutPostRedisplay();

	glutTimerFunc(100, updateWave2, 0);
}

void updateShip1(int value) {

    if(position5 <-1.0)
        position5 =1.0f;

    position5 -= speed5;

	glutPostRedisplay();

	glutTimerFunc(100, updateShip1, 0);
}

void updateHanger(int value) {

    if(position6 <-1.0)
        position6 =1.0f;

    position6 -= speed6;

	glutPostRedisplay();

	glutTimerFunc(100, updateHanger, 0);
}


void updateTruck(int value) {

    if(position7 >1.0)
        position7 =-1.0f;

    position7 += speed7;

	glutPostRedisplay();

	glutTimerFunc(100, updateTruck, 0);
}

void updateSunEve(int value) {

    if(position8 >1.0)
        position8 =-1.0f;

    position8 += speed8;

	glutPostRedisplay();

	glutTimerFunc(100, updateSunEve, 0);
}

void updateRain(int value) {

    if(position9 <-1.0)
        position9 = 0.2f;

    position9 -= speed9;
	glutPostRedisplay();

	glutTimerFunc(100, updateRain, 0);
}

void updateRain2(int value) {

    if(position91 >1.0)
        position91 = -1.0f;

    position91 += speed91;
	glutPostRedisplay();

	glutTimerFunc(100, updateRain2, 0);
}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




void rain()
{   glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //white_background
    glClear(GL_COLOR_BUFFER_BIT);

//first_sky_layer
glBegin(GL_QUADS); //layer
glColor3ub(95, 106, 106 );
glVertex2f(-1, 1);
glVertex2f(-1, 0.9);
glVertex2f(1, 0.9);
glVertex2f(1, 1);
glEnd();

glBegin(GL_QUADS);//layer
glColor3ub(113, 125, 126);
glVertex2f(-1, 0.9);
glVertex2f(-1, 0.8);
glVertex2f(1, 0.8);
glVertex2f(1, 0.9);
glEnd();

glBegin(GL_QUADS);//layer
glColor3ub(131, 145, 146);
glVertex2f(-1, 0.8);
glVertex2f(-1, 0.7);
glVertex2f(1, 0.7);
glVertex2f(1, 0.8);
glEnd();

glBegin(GL_QUADS);//layer
glColor3ub(149, 165, 166);
glVertex2f(-1, 0.7);
glVertex2f(-1, 0.6);
glVertex2f(1, 0.6);
glVertex2f(1, 0.7);
glEnd();


glBegin(GL_QUADS);//layer
glColor3ub(170, 183, 184);
glVertex2f(-1, 0.6);
glVertex2f(-1, 0.5);
glVertex2f(1, 0.5);
glVertex2f(1, 0.6);
glEnd();

glBegin(GL_QUADS);//layer
glColor3ub(191, 201, 202 );
glVertex2f(-1, 0.5);
glVertex2f(-1, 0.4);
glVertex2f(1, 0.4);
glVertex2f(1, 0.5);
glEnd();

glBegin(GL_QUADS);//layer
glColor3ub(213, 219, 219);
glVertex2f(-1, 0.4);
glVertex2f(-1, 0.05);
glVertex2f(1, 0.05);
glVertex2f(1, 0.4);
glEnd();

//cloud start
glPushMatrix();
glTranslatef(position,0,0); //cloud animation
int i;
GLfloat x1721=-.9f; GLfloat y1721=.72f; GLfloat radius1721 =0.030f;
	int triangleAmount1721 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1721 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(44, 68, 88); // window
		glVertex2f(x1721, y1721); // center of circle
		for(i = 0; i<= triangleAmount1721;i++) {
			glVertex2f(
		            x1721 + (radius1721 * cos(i *  twicePi1721 / triangleAmount1721)),
			    y1721 + (radius1721 * sin(i * twicePi1721 / triangleAmount1721))
			);
		}
	glEnd();

	GLfloat x1821=-.894f; GLfloat y1821=.725f; GLfloat radius1821 =0.030f;
	int triangleAmount1821 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1821 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(92, 115, 137); // window
		glVertex2f(x1821, y1821); // center of circle
		for(i = 0; i<= triangleAmount1821;i++) {
			glVertex2f(
		            x1821 + (radius1821 * cos(i *  twicePi1821 / triangleAmount1821)),
			    y1821 + (radius1821 * sin(i * twicePi1821/ triangleAmount1821))
			);
		}
	glEnd();


	GLfloat x1921=-.885f; GLfloat y1921=.75f; GLfloat radius1921 =0.030f;
	int triangleAmount1921 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1921 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(44, 68, 88); // wi2ndow
		glVertex2f(x1921, y1921); // center of circle
		for(i= 0; i<= triangleAmount1921;i++) {
			glVertex2f(
		            x1921 + (radius1921 * cos(i *  twicePi1921 / triangleAmount1921)),
			    y1921+ (radius1921 * sin(i * twicePi1921/ triangleAmount1921))
			);
		}
	glEnd();


	GLfloat x1991=-.88f; GLfloat y1991=.76f; GLfloat radius1991 =0.030f;
	int triangleAmount1991= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1991 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(92, 115, 137); // window
		glVertex2f(x1991, y1991); // center of circle
		for(i = 0; i<= triangleAmount1991;i++) {
			glVertex2f(
		            x1991 + (radius1991 * cos(i *  twicePi1991 / triangleAmount1991)),
			    y1991 + (radius1991 * sin(i * twicePi1991/ triangleAmount1991))
			);
		}
	glEnd();

	GLfloat x199112=-.87f; GLfloat y199112=.72f; GLfloat radius199112 =0.030f;
	int triangleAmount199112= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi199112 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(44, 68, 88); // window
		glVertex2f(x199112, y199112); // center of circle
		for(i = 0; i<= triangleAmount199112;i++) {
			glVertex2f(
		            x199112 + (radius199112 * cos(i *  twicePi199112 / triangleAmount199112)),
			    y199112 + (radius199112 * sin(i * twicePi199112/ triangleAmount199112))
			);
		}
	glEnd();

GLfloat x199111=-.85f; GLfloat y199111=.72f; GLfloat radius199111 =0.030f;
	int triangleAmount199111= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi199111 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(92, 115, 137); // window
		glVertex2f(x199111, y199111); // center of circle
		for(i = 0; i<= triangleAmount199111;i++) {
			glVertex2f(
		            x199111 + (radius199111 * cos(i *  twicePi199111 / triangleAmount199111)),
			    y199111 + (radius199111 * sin(i * twicePi199111/ triangleAmount199111))
			);
		}
	glEnd();


GLfloat x1991111=-.85f; GLfloat y1991111=.74f; GLfloat radius1991111 =0.030f;
	int triangleAmount1991111= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1991111 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(44, 68, 88); // window
		glVertex2f(x1991111, y1991111); // center of circle
		for(i = 0; i<= triangleAmount1991111;i++) {
			glVertex2f(
		            x1991111 + (radius1991111 * cos(i *  twicePi1991111 / triangleAmount199111)),
			    y1991111 + (radius1991111 * sin(i * twicePi1991111/ triangleAmount1991111))
			);
		}
	glEnd();


GLfloat x19911112=-.83f; GLfloat y19911112=.72f; GLfloat radius19911112 =0.030f;
	int triangleAmount19911112= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi19911112 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(44, 68, 88); // window
		glVertex2f(x19911112, y19911112); // center of circle
		for(i = 0; i<= triangleAmount19911112;i++) {
			glVertex2f(
		            x19911112 + (radius19911112 * cos(i *  twicePi19911112 / triangleAmount19911112)),
			    y19911112 + (radius19911112 * sin(i * twicePi19911112/ triangleAmount19911112))
			);
		}
	glEnd();


GLfloat x19911111=-.84f; GLfloat y19911111=.76f; GLfloat radius19911111 =0.030f;
	int triangleAmount19911111= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi19911111 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(92, 115, 137); // window
		glVertex2f(x19911111, y19911111); // center of circle
		for(i = 0; i<= triangleAmount19911111;i++) {
			glVertex2f(
		            x19911111 + (radius19911111 * cos(i *  twicePi19911111 / triangleAmount19911111)),
			    y19911111 + (radius19911111 * sin(i * twicePi19911111/ triangleAmount19911111))
			);
		}
	glEnd();

	GLfloat x199111111=-.83f; GLfloat y199111111=.72f; GLfloat radius199111111 =0.030f;
	int triangleAmount199111111= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi199111111 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(44, 68, 88); // window
		glVertex2f(x199111111, y199111111); // center of circle
		for(i = 0; i<= triangleAmount199111111;i++) {
			glVertex2f(
		            x199111111 + (radius199111111 * cos(i *  twicePi199111111 / triangleAmount199111111)),
			    y199111111 + (radius199111111 * sin(i * twicePi199111111/ triangleAmount199111111))
			);
		}
	glEnd();

		GLfloat x1991111111=-.815f; GLfloat y1991111111=.72f; GLfloat radius1991111111 =0.030f;
	int triangleAmount1991111111= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1991111111 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(92, 115, 137); // window
		glVertex2f(x1991111111, y1991111111); // center of circle
		for(i= 0; i<= triangleAmount1991111111;i++) {
			glVertex2f(
		            x1991111111 + (radius1991111111 * cos(i *  twicePi1991111111 / triangleAmount1991111111)),
			    y1991111111 + (radius1991111111 * sin(i * twicePi1991111111/ triangleAmount1991111111))
			);
		}
	glEnd();
	glTranslatef(0.6,0.14,0);
    GLfloat x172=-.9f; GLfloat y172=.72f; GLfloat radius172 =0.030f;
	int triangleAmount172 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi172 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(44, 68, 88); // window
		glVertex2f(x172, y172); // center of circle
		for(i = 0; i<= triangleAmount172;i++) {
			glVertex2f(
		            x172 + (radius172 * cos(i *  twicePi172 / triangleAmount172)),
			    y172 + (radius172 * sin(i * twicePi172 / triangleAmount172))
			);
		}
	glEnd();

	GLfloat x18212=-.894f; GLfloat y18212=.725f; GLfloat radius18212 =0.030f;
	int triangleAmount18212= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi18212 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(92, 115, 137); // window
		glVertex2f(x18212, y18212); // center of circle
		for(i = 0; i<= triangleAmount18212;i++) {
			glVertex2f(
		            x18212 + (radius18212 * cos(i *  twicePi18212 / triangleAmount18212)),
			    y18212 + (radius18212 * sin(i * twicePi18212/ triangleAmount18212))
			);
		}
	glEnd();


	GLfloat x19212=-.885f; GLfloat y19212=.75f; GLfloat radius19212 =0.030f;
	int triangleAmount19212 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi19212 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(44, 68, 88); // wi2ndow
		glVertex2f(x19212, y19212); // center of circle
		for(i= 0; i<= triangleAmount19212;i++) {
			glVertex2f(
		            x19212 + (radius19212 * cos(i *  twicePi19212 / triangleAmount19212)),
			    y19212+ (radius19212 * sin(i * twicePi19212/ triangleAmount19212))
			);
		}
	glEnd();


	GLfloat x199122=-.88f; GLfloat y199122=.76f; GLfloat radius199122 =0.030f;
	int triangleAmount199122= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi199122 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(92, 115, 137); // window
		glVertex2f(x199122, y199122); // center of circle
		for(i = 0; i<= triangleAmount199122;i++) {
			glVertex2f(
		            x199122 + (radius199122 * cos(i *  twicePi199122 / triangleAmount199122)),
			    y199122 + (radius199122 * sin(i * twicePi199122/ triangleAmount199122))
			);
		}
	glEnd();

	GLfloat x1991123=-.87f; GLfloat y1991123=.72f; GLfloat radius1991123 =0.030f;
	int triangleAmount1991123= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1991123 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(44, 68, 88); // window
		glVertex2f(x1991123, y1991123); // center of circle
		for(i = 0; i<= triangleAmount1991123;i++) {
			glVertex2f(
		            x1991123 + (radius1991123 * cos(i *  twicePi1991123 / triangleAmount1991123)),
			    y1991123+ (radius1991123 * sin(i * twicePi1991123/ triangleAmount1991123))
			);
		}
	glEnd();

GLfloat x19911133=-.85f; GLfloat y19911133=.72f; GLfloat radius19911133 =0.030f;
	int triangleAmount19911133= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi19911133 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(92, 115, 137); // window
		glVertex2f(x19911133, y19911133); // center of circle
		for(i = 0; i<= triangleAmount19911133;i++) {
			glVertex2f(
		            x19911133 + (radius19911133 * cos(i *  twicePi19911133 / triangleAmount19911133)),
			    y19911133 + (radius19911133 * sin(i * twicePi19911133/ triangleAmount19911133))
			);
		}
	glEnd();


GLfloat x199111133=-.85f; GLfloat y199111133=.74f; GLfloat radius199111133 =0.030f;
	int triangleAmount199111133= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi199111133 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(44, 68, 88); // window
		glVertex2f(x199111133, y199111133); // center of circle
		for(i = 0; i<= triangleAmount199111133;i++) {
			glVertex2f(
		            x199111133 + (radius199111133 * cos(i *  twicePi199111133 / triangleAmount199111133)),
			    y199111133 + (radius199111133 * sin(i * twicePi199111133/ triangleAmount199111133))
			);
		}
	glEnd();


GLfloat x1991111112=-.83f; GLfloat y1991111112=.72f; GLfloat radius1991111112 =0.030f;
	int triangleAmount1991111112= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1991111112 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(44, 68, 88); // window
		glVertex2f(x1991111112, y1991111112); // center of circle
		for(i = 0; i<= triangleAmount1991111112;i++) {
			glVertex2f(
		            x1991111112 + (radius1991111112 * cos(i *  twicePi1991111112 / triangleAmount1991111112)),
			    y1991111112 + (radius1991111112 * sin(i * twicePi1991111112/ triangleAmount1991111112))
			);
		}
	glEnd();


GLfloat x19911111123=-.84f; GLfloat y19911111123=.76f; GLfloat radius19911111123 =0.030f;
	int triangleAmount19911111123= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi19911111123 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(92, 115, 137); // window
		glVertex2f(x19911111123, y19911111123); // center of circle
		for(i = 0; i<= triangleAmount19911111123;i++) {
			glVertex2f(
		            x19911111123 + (radius19911111123 * cos(i *  twicePi19911111123 / triangleAmount19911111123)),
			    y19911111123 + (radius19911111123 * sin(i * twicePi19911111123/ triangleAmount19911111123))
			);
		}
	glEnd();

	GLfloat x199111111132=-.83f; GLfloat y199111111132=.72f; GLfloat radius199111111132 =0.030f;
	int triangleAmount199111111132= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi199111111132 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(44, 68, 88); // window
		glVertex2f(x199111111132, y199111111132); // center of circle
		for(i = 0; i<= triangleAmount199111111132;i++) {
			glVertex2f(
		            x199111111132 + (radius199111111132 * cos(i *  twicePi199111111132 / triangleAmount199111111132)),
			    y199111111132 + (radius199111111132 * sin(i * twicePi199111111132/ triangleAmount199111111132))
			);
		}
	glEnd();

		GLfloat x19911111111=-.815f; GLfloat y19911111111=.72f; GLfloat radius19911111111 =0.030f;
	int triangleAmount19911111111= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi19911111111 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(92, 115, 137); // window
		glVertex2f(x19911111111, y19911111111); // center of circle
		for(i= 0; i<= triangleAmount19911111111;i++) {
			glVertex2f(
		            x19911111111 + (radius19911111111 * cos(i *  twicePi19911111111 / triangleAmount19911111111)),
			    y19911111111 + (radius19911111111 * sin(i * twicePi19911111111/ triangleAmount19911111111))
			);
		}
	glEnd();
	glLoadIdentity();



	glPopMatrix();


glPushMatrix();
glTranslatef(position,0,0); //cloud 2 animation

	GLfloat x92=0.36f; GLfloat y92=0.69f; GLfloat radius92 =0.035f;
	int triangleAmount92 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi92 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(92, 115, 137); // windmill
		glVertex2f(x92, y92); // center of circle
		for(i = 0; i <= triangleAmount92;i++) {
			glVertex2f(
		            x92 + (radius92* cos(i *  twicePi92 / triangleAmount92)),
			    y92 + (radius92 * sin(i * twicePi92 / triangleAmount92))
			);
		}
	glEnd();


		GLfloat x102=0.32f; GLfloat y102=0.67f; GLfloat radius102 =0.035f;
	int triangleAmount102= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi102 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(44, 68, 88); // windmill
		glVertex2f(x102, y102); // center of circle
		for(i = 0; i <= triangleAmount102;i++) {
			glVertex2f(
		            x102 + (radius102 * cos(i *  twicePi102/ triangleAmount102)),
			    y102 + (radius102 * sin(i * twicePi102 / triangleAmount102))
			);
		}
	glEnd();


	GLfloat x1122=0.38f; GLfloat y1122=0.67f; GLfloat radius1122 =0.035f;
	int triangleAmount1122 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1122 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(44, 68, 88); // windmill
		glVertex2f(x1122, y1122); // center of circle
		for(i = 0; i <= triangleAmount1122;i++) {
			glVertex2f(
		            x1122 + (radius1122 * cos(i *  twicePi1122 / triangleAmount1122)),
			    y1122 + (radius1122* sin(i * twicePi1122 / triangleAmount1122))
			);
		}
	glEnd();


	GLfloat x122=0.4f; GLfloat y122=0.71f; GLfloat radius122 =0.035f;
	int triangleAmount122 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi122 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(92, 115, 137); // windmill
		glVertex2f(x122, y122); // center of circle
		for(i = 0; i <= triangleAmount122;i++) {
			glVertex2f(
		            x122 + (radius122* cos(i *  twicePi122 / triangleAmount122)),
			    y122 + (radius122 * sin(i * twicePi122 / triangleAmount122))
			);
		}
	glEnd();


	GLfloat x1322=0.43f; GLfloat y1322=0.67f; GLfloat radius1322 =0.035f;
	int triangleAmount1322 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1322 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(44, 68, 88); // windmill
		glVertex2f(x1322, y1322); // center of circle
		for(i = 0; i <= triangleAmount1322;i++) {
			glVertex2f(
		            x1322 + (radius1322* cos(i *  twicePi1322 / triangleAmount1322)),
			    y1322 + (radius1322 * sin(i * twicePi1322 / triangleAmount1322))
			);
		}
	glEnd();

	GLfloat x142=0.45f; GLfloat y142=0.67f; GLfloat radius142=0.035f;
	int triangleAmount142 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi142 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(44, 68, 88); // windmill
		glVertex2f(x142, y142); // center of circle
		for(i = 0; i <= triangleAmount142;i++) {
			glVertex2f(
		            x142 + (radius142* cos(i *  twicePi142 / triangleAmount142)),
			    y142 + (radius142 * sin(i * twicePi142 / triangleAmount142))
			);
		}
	glEnd();

		GLfloat x152=0.33f; GLfloat y152=0.684f; GLfloat radius152=0.035f;
	int triangleAmount152 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi152 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(92, 115, 137); // windmill
		glVertex2f(x152, y152); // center of circle
		for(i = 0; i <= triangleAmount152;i++) {
			glVertex2f(
		            x152 + (radius152* cos(i *  twicePi152 / triangleAmount152)),
			    y152 + (radius152 * sin(i * twicePi152 / triangleAmount152))
			);
		}
	glEnd();

	GLfloat x162=0.33f; GLfloat y162=0.684f; GLfloat radius162=0.035f;
	int triangleAmount162 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi162 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(92, 115, 137); // windmill
		glVertex2f(x162, y162); // center of circle
		for(i = 0; i <= triangleAmount162;i++) {
			glVertex2f(
		            x162 + (radius162* cos(i *  twicePi162 / triangleAmount162)),
			    y162 + (radius162 * sin(i * twicePi162 / triangleAmount162))
			);
		}
	glEnd();


	glTranslatef(-0.9,0.05,0);
	GLfloat x921=0.36f; GLfloat y921=0.69f; GLfloat radius921 =0.035f;
	int triangleAmount921 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi921 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(92, 115, 137); // windmill
		glVertex2f(x921, y921); // center of circle
		for(i = 0; i <= triangleAmount921;i++) {
			glVertex2f(
		            x921 + (radius921* cos(i *  twicePi921 / triangleAmount921)),
			    y92 + (radius921 * sin(i * twicePi921 / triangleAmount921))
			);
		}
	glEnd();


		GLfloat x1021=0.32f; GLfloat y1021=0.67f; GLfloat radius1021 =0.035f;
	int triangleAmount1021= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1021 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(44, 68, 88); // windmill
		glVertex2f(x1021, y1021); // center of circle
		for(i = 0; i <= triangleAmount102;i++) {
			glVertex2f(
		            x1021 + (radius1021 * cos(i *  twicePi1021/ triangleAmount1021)),
			    y1021 + (radius1021 * sin(i * twicePi1021 / triangleAmount1021))
			);
		}
	glEnd();


	GLfloat x11221=0.38f; GLfloat y11221=0.67f; GLfloat radius11221 =0.035f;
	int triangleAmount11221 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi11221 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(44, 68, 88); // windmill
		glVertex2f(x11221, y11221); // center of circle
		for(i = 0; i <= triangleAmount11221;i++) {
			glVertex2f(
		            x11221 + (radius11221 * cos(i *  twicePi11221 / triangleAmount11221)),
			    y11221 + (radius11221* sin(i * twicePi11221 / triangleAmount11221))
			);
		}
	glEnd();


	GLfloat x1221=0.4f; GLfloat y1221=0.71f; GLfloat radius1221 =0.035f;
	int triangleAmount1221 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1221 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(92, 115, 137); // windmill
		glVertex2f(x1221, y1221); // center of circle
		for(i = 0; i <= triangleAmount1221;i++) {
			glVertex2f(
		            x1221 + (radius1221* cos(i *  twicePi1221 / triangleAmount1221)),
			    y1221 + (radius1221 * sin(i * twicePi1221 / triangleAmount1221))
			);
		}
	glEnd();


	GLfloat x13221=0.43f; GLfloat y13221=0.67f; GLfloat radius13221 =0.035f;
	int triangleAmount13221 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi13221 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(44, 68, 88); // windmill
		glVertex2f(x13221, y13221); // center of circle
		for(i = 0; i <= triangleAmount13221;i++) {
			glVertex2f(
		            x13221 + (radius13221* cos(i *  twicePi13221 / triangleAmount13221)),
			    y13221 + (radius13221 * sin(i * twicePi13221 / triangleAmount13221))
			);
		}
	glEnd();

	GLfloat x1421=0.45f; GLfloat y1421=0.67f; GLfloat radius1421=0.035f;
	int triangleAmount1421 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1421 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(92, 115, 137); // windmill
		glVertex2f(x1421, y1421); // center of circle
		for(i = 0; i <= triangleAmount1421;i++) {
			glVertex2f(
		            x1421 + (radius1421* cos(i *  twicePi1421 / triangleAmount1421)),
			    y1421 + (radius1421 * sin(i * twicePi1421 / triangleAmount1421))
			);
		}
	glEnd();

		GLfloat x1521=0.33f; GLfloat y1521=0.684f; GLfloat radius1521=0.035f;
	int triangleAmount1521 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1521 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(92, 115, 137); // windmill
		glVertex2f(x1521, y1521); // center of circle
		for(i = 0; i <= triangleAmount1521;i++) {
			glVertex2f(
		            x1521 + (radius1521* cos(i *  twicePi1521 / triangleAmount1521)),
			    y1521 + (radius1521 * sin(i * twicePi1521 / triangleAmount1521))
			);
		}
	glEnd();

	GLfloat x1621=0.33f; GLfloat y1621=0.684f; GLfloat radius1621=0.035f;
	int triangleAmount1621 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1621 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(92, 115, 137); // windmill
		glVertex2f(x1621, y1621); // center of circle
		for(i = 0; i <= triangleAmount1621;i++) {
			glVertex2f(
		            x1621 + (radius1621* cos(i *  twicePi1621 / triangleAmount1621)),
			    y1621 + (radius1621 * sin(i * twicePi1621 / triangleAmount1621))
			);
		}
	glEnd();
    glLoadIdentity();


    glPushMatrix();
    glTranslatef(position,0,0);//cloud 3 animation

    glTranslatef(0.3,0.15,0);
    GLfloat x9213=0.36f; GLfloat y9213=0.69f; GLfloat radius9213 =0.035f;
	int triangleAmount9213 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi9213 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(92, 115, 137); // windmill
		glVertex2f(x9213, y9213); // center of circle
		for(i = 0; i <= triangleAmount9213;i++) {
			glVertex2f(
		            x9213 + (radius9213* cos(i *  twicePi9213 / triangleAmount9213)),
			    y92 + (radius9213 * sin(i * twicePi9213/ triangleAmount9213))
			);
		}
	glEnd();


		GLfloat x10213=0.32f; GLfloat y10213=0.67f; GLfloat radius10213 =0.035f;
	int triangleAmount10213= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi10213 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(44, 68, 88); // windmill
		glVertex2f(x10213, y10213); // center of circle
		for(i = 0; i <= triangleAmount10213;i++) {
			glVertex2f(
		            x10213 + (radius10213 * cos(i *  twicePi10213/ triangleAmount10213)),
			    y10213 + (radius10213 * sin(i * twicePi10213 / triangleAmount10213))
			);
		}
	glEnd();


	GLfloat x112213=0.38f; GLfloat y112213=0.67f; GLfloat radius112213 =0.035f;
	int triangleAmount112213 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi112213 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(44, 68, 88); // windmill
		glVertex2f(x112213, y112213); // center of circle
		for(i = 0; i <= triangleAmount112213;i++) {
			glVertex2f(
		            x112213 + (radius112213 * cos(i *  twicePi112213 / triangleAmount112213)),
			    y112213 + (radius112213* sin(i * twicePi112213 / triangleAmount112213))
			);
		}
	glEnd();


	GLfloat x12213=0.4f; GLfloat y12213=0.71f; GLfloat radius12213 =0.035f;
	int triangleAmount12213 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi12213 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(92, 115, 137); // windmill
		glVertex2f(x12213, y12213); // center of circle
		for(i = 0; i <= triangleAmount12213;i++) {
			glVertex2f(
		            x12213 + (radius12213* cos(i *  twicePi12213 / triangleAmount12213)),
			    y12213 + (radius12213* sin(i * twicePi12213 / triangleAmount12213))
			);
		}
	glEnd();


	GLfloat x132213=0.43f; GLfloat y132213=0.67f; GLfloat radius132213 =0.035f;
	int triangleAmount132213 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi132213 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(44, 68, 88); // windmill
		glVertex2f(x132213, y132213); // center of circle
		for(i = 0; i <= triangleAmount132213;i++) {
			glVertex2f(
		            x132213 + (radius132213* cos(i *  twicePi132213 / triangleAmount132213)),
			    y132213+ (radius132213 * sin(i * twicePi132213 / triangleAmount132213))
			);
		}
	glEnd();

	GLfloat x14213=0.45f; GLfloat y14213=0.67f; GLfloat radius14213=0.035f;
	int triangleAmount14213 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi14213 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(92, 115, 137); // windmill
		glVertex2f(x14213, y14213); // center of circle
		for(i = 0; i <= triangleAmount14213;i++) {
			glVertex2f(
		            x14213 + (radius14213* cos(i *  twicePi14213 / triangleAmount14213)),
			    y14213 + (radius14213 * sin(i * twicePi14213 / triangleAmount14213))
			);
		}
	glEnd();

		GLfloat x15213=0.33f; GLfloat y15213=0.684f; GLfloat radius15213=0.035f;
	int triangleAmount15213 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi15213 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(92, 115, 137); // windmill
		glVertex2f(x15213, y15213); // center of circle
		for(i = 0; i <= triangleAmount1521;i++) {
			glVertex2f(
		            x15213 + (radius15213* cos(i *  twicePi15213 / triangleAmount15213)),
			    y15213 + (radius15213 * sin(i * twicePi15213 / triangleAmount15213))
			);
		}
	glEnd();

	GLfloat x16213=0.33f; GLfloat y16213=0.684f; GLfloat radius16213=0.035f;
	int triangleAmount16213 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi16213 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(92, 115, 137); // windmill
		glVertex2f(x16213, y16213); // center of circle
		for(i = 0; i <= triangleAmount16213;i++) {
			glVertex2f(
		            x16213+ (radius16213* cos(i *  twicePi16213 / triangleAmount16213)),
			    y16213 + (radius16213 * sin(i * twicePi16213 / triangleAmount16213))
			);
		}
	glEnd();
	glLoadIdentity();
    glPopMatrix();
//cloud end


//Building_1
glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f( -1.0, 0.34 );
glVertex2f( -1.0, 0.1 );
glVertex2f( -0.925, 0.1 );
glVertex2f( -0.925, 0.34 );
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f(-0.925, 0.43 );
glVertex2f( -0.925, 0.1 );
glVertex2f( -0.855, 0.1 );
glVertex2f( -0.855, 0.43 );
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f(-0.844, 0.34 );
glVertex2f( -0.844, 0.1 );
glVertex2f(-0.779, 0.1 );
glVertex2f( -0.779, 0.34 );
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f(-0.709, 0.474);
glVertex2f( -0.709, 0.1 );
glVertex2f(-0.55, 0.1 );
glVertex2f( -0.55, 0.44 );
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f(-0.53, 0.418);
glVertex2f( -0.53, 0.1 );
glVertex2f(-0.504, 0.1 );
glVertex2f( -0.504, 0.418);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f(-0.504, 0.476);
glVertex2f( -0.504, 0.1 );
glVertex2f(-0.476, 0.1 );
glVertex2f( -0.476, 0.476);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f(-0.476, 0.458);
glVertex2f( -0.476, 0.1 );
glVertex2f(-0.442, 0.1 );
glVertex2f( -0.442, 0.458);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f(-0.442, 0.505);
glVertex2f( -0.442, 0.1 );
glVertex2f(-0.358, 0.1 );
glVertex2f( -0.358, 0.505);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f(-0.358, 0.458);
glVertex2f( -0.358, 0.1 );
glVertex2f(-0.327, 0.1 );
glVertex2f( -0.327, 0.458);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f(-0.327, 0.49);
glVertex2f( -0.327, 0.1 );
glVertex2f(-0.2935, 0.1 );
glVertex2f( -0.2935, 0.49);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f(-0.2935, 0.42);
glVertex2f( -0.2935, 0.1 );
glVertex2f(-0.256, 0.1 );
glVertex2f( -0.256, 0.42);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f(-0.256, 0.515);
glVertex2f( -0.256, 0.1 );
glVertex2f(-0.244, 0.1 );
glVertex2f(-0.244, 0.515);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f(-0.244, 0.534);
glVertex2f( -0.244, 0.1 );
glVertex2f(-0.236, 0.1 );
glVertex2f(-0.236, 0.534);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f(-0.236, 0.568);
glVertex2f( -0.236, 0.1 );
glVertex2f(-0.224, 0.1 );
glVertex2f(-0.224, 0.568);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f(-0.224, 0.592);
glVertex2f( -0.224, 0.1 );
glVertex2f(-0.171, 0.1 );
glVertex2f(-0.171, 0.592);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f(-0.171, 0.568);
glVertex2f( -0.171, 0.1 );
glVertex2f(-0.155, 0.1 );
glVertex2f(-0.155, 0.568);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f(-0.155, 0.534);
glVertex2f( -0.155, 0.1 );
glVertex2f(-0.141, 0.1 );
glVertex2f(-0.141, 0.534);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f(-0.155, 0.534);
glVertex2f( -0.155, 0.1 );
glVertex2f(-0.141, 0.1 );
glVertex2f(-0.141, 0.534);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f(-0.141, 0.515);
glVertex2f( -0.141, 0.1 );
glVertex2f(-0.128, 0.1 );
glVertex2f(-0.128, 0.515);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f(-0.128, 0.42);
glVertex2f( -0.128, 0.1 );
glVertex2f(-0.12, 0.1 );
glVertex2f(-0.12, 0.42);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f(-0.12, 0.49);
glVertex2f( -0.12, 0.1 );
glVertex2f(0.008, 0.1 );
glVertex2f(0.008, 0.49);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f(0.008, 0.55);
glVertex2f( 0.008, 0.1 );
glVertex2f(0.098, 0.1 );
glVertex2f(0.098, 0.55);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f(0.098, 0.295);
glVertex2f( 0.098, 0.1 );
glVertex2f(0.116, 0.1 );
glVertex2f(0.116, 0.295);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f(0.195, 0.39);
glVertex2f( 0.195, 0.1 );
glVertex2f(0.245, 0.1 );
glVertex2f(0.245, 0.358);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f(0.245, 0.301);
glVertex2f( 0.245, 0.1 );
glVertex2f(0.26, 0.1 );
glVertex2f(0.26, 0.301);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f(0.26, 0.445);
glVertex2f( 0.26, 0.1 );
glVertex2f(0.37, 0.1 );
glVertex2f(0.37, 0.445);
glEnd();

glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f(0.39, 0.4);
glVertex2f( 0.39, 0.1 );
glVertex2f(0.45, 0.1 );
glVertex2f(0.45, 0.4);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f(0.45, 0.35);
glVertex2f( 0.45, 0.1 );
glVertex2f(0.495, 0.1 );
glVertex2f(0.495, 0.35);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f(0.495, 0.26);
glVertex2f( 0.495, 0.1 );
glVertex2f(0.662, 0.1 );
glVertex2f(0.662, 0.26);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f(0.662, 0.36);
glVertex2f( 0.662, 0.1 );
glVertex2f(0.854, 0.1 );
glVertex2f(0.854, 0.36);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f(0.854, 0.32);
glVertex2f( 0.854, 0.1 );
glVertex2f(0.894, 0.1 );
glVertex2f(0.894, 0.32);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f(0.894, 0.345);
glVertex2f( 0.894, 0.1 );
glVertex2f(0.922, 0.1 );
glVertex2f(0.922, 0.345);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 111, 110);
glVertex2f(0.922, 0.32);
glVertex2f( 0.922, 0.1 );
glVertex2f(1.0, 0.1 );
glVertex2f(1.0, 0.32);
glEnd();

//Building_2
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(-1.0, 0.212);
glVertex2f( -1.0, -0.05 );
glVertex2f(-0.993, -0.05 );
glVertex2f(-0.993, 0.212);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(-0.993, 0.28);
glVertex2f( -0.993, -0.05 );
glVertex2f(-0.94, -0.05 );
glVertex2f(-0.94, 0.28);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(-0.94, 0.1);
glVertex2f( -0.94, -0.05 );
glVertex2f(-0.932, -0.05 );
glVertex2f(-0.932, 0.1);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(-0.932, 0.212);
glVertex2f( -0.932, -0.05 );
glVertex2f(-0.894, -0.05 );
glVertex2f(-0.894, 0.212);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(-0.894, 0.168);
glVertex2f( -0.894, -0.05 );
glVertex2f(-0.83, -0.05 );
glVertex2f(-0.83, 0.168);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(-0.83, 0.316);
glVertex2f( -0.83, -0.05 );
glVertex2f(-0.708, -0.05 );
glVertex2f(-0.708, 0.284);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(-0.708, 0.1);
glVertex2f( -0.708, -0.05 );
glVertex2f(-0.688, -0.05 );
glVertex2f(-0.688, 0.1);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(-0.688, 0.27);
glVertex2f( -0.688, -0.05 );
glVertex2f(-0.674, -0.05 );
glVertex2f(-0.674, 0.27);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(-0.674, 0.315);
glVertex2f( -0.674, -0.05 );
glVertex2f(-0.656, -0.05 );
glVertex2f(-0.656, 0.315);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(-0.656, 0.3);
glVertex2f( -0.656, -0.05 );
glVertex2f(-0.63, -0.05 );
glVertex2f(-0.63, 0.3);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(-0.63, 0.335);
glVertex2f( -0.63, -0.05 );
glVertex2f(-0.568, -0.05 );
glVertex2f(-0.568, 0.335);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(-0.568, 0.3);
glVertex2f( -0.568, -0.05 );
glVertex2f(-0.544, -0.05 );
glVertex2f(-0.544, 0.3);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(-0.544, 0.325);
glVertex2f( -0.544, -0.05 );
glVertex2f(-0.52, -0.05 );
glVertex2f(-0.52, 0.325);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(-0.52, 0.27);
glVertex2f( -0.52, -0.05 );
glVertex2f(-0.49, -0.05 );
glVertex2f(-0.49, 0.27);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(-0.49, 0.34);
glVertex2f( -0.49, -0.05 );
glVertex2f(-0.482, -0.05 );
glVertex2f(-0.482, 0.34);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(-0.482, 0.36);
glVertex2f( -0.482, -0.05 );
glVertex2f(-0.476, -0.05 );
glVertex2f(-0.476, 0.36);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(-0.476, 0.38);
glVertex2f( -0.476, -0.05 );
glVertex2f(-0.464, -0.05 );
glVertex2f(-0.464, 0.38);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(-0.464, 0.41);
glVertex2f( -0.464, -0.05 );
glVertex2f(-0.426, -0.05 );
glVertex2f(-0.426, 0.41);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(-0.426, 0.38);
glVertex2f( -0.426, -0.05 );
glVertex2f(-0.414, -0.05 );
glVertex2f(-0.414, 0.38);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(-0.414, 0.36);
glVertex2f( -0.414, -0.05 );
glVertex2f(-0.402, -0.05 );
glVertex2f(-0.402, 0.36);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(-0.402, 0.34);
glVertex2f( -0.402, -0.05 );
glVertex2f(-0.396, -0.05 );
glVertex2f(-0.396, 0.34);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(-0.396, 0.27);
glVertex2f( -0.396, -0.05 );
glVertex2f(-0.388, -0.05 );
glVertex2f(-0.388, 0.27);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(-0.388, 0.33);
glVertex2f( -0.388, -0.05 );
glVertex2f(-0.292, -0.05 );
glVertex2f(-0.292, 0.33);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(-0.292, 0.37);
glVertex2f( -0.292, -0.05 );
glVertex2f(-0.224, -0.05 );
glVertex2f(-0.224, 0.37);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(-0.224, 0.15);
glVertex2f( -0.224, -0.05 );
glVertex2f(-0.21, -0.05 );
glVertex2f(-0.21, 0.15);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(-0.21, 0.32);
glVertex2f( -0.21, -0.05 );
glVertex2f(-0.164, -0.05 );
glVertex2f(-0.164, 0.34);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(-0.164, 0.182);
glVertex2f( -0.164, -0.05 );
glVertex2f(-0.152, -0.05 );
glVertex2f(-0.152, 0.182);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(-0.152, 0.25);
glVertex2f( -0.152, -0.05 );
glVertex2f(-0.114, -0.05 );
glVertex2f(-0.114, 0.225);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(-0.114, 0.164);
glVertex2f( -0.114, -0.05 );
glVertex2f(-0.10, -0.05 );
glVertex2f(-0.10, 0.164);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(-0.10, 0.287);
glVertex2f( -0.10, -0.05 );
glVertex2f(-0.019, -0.05 );
glVertex2f(-0.019, 0.287);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(-0.019, 0.151);
glVertex2f( -0.10, -0.05 );
glVertex2f(-0.006, -0.05 );
glVertex2f(-0.006, 0.151);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(-0.006, 0.255);
glVertex2f( -0.006, -0.05 );
glVertex2f(0.038, -0.05 );
glVertex2f(0.038, 0.255);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(0.038, 0.15);
glVertex2f(0.038, -0.05 );
glVertex2f(0.053, -0.05 );
glVertex2f(0.053, 0.15);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(0.053, 0.232);
glVertex2f(0.053, -0.05 );
glVertex2f(0.073, -0.05 );
glVertex2f(0.073, 0.21);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(0.073, 0.15);
glVertex2f(0.073, -0.05 );
glVertex2f(0.093, -0.05 );
glVertex2f(0.093, 0.15);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(0.093, 0.323);
glVertex2f(0.093, -0.05 );
glVertex2f(0.105, -0.05 );
glVertex2f(0.105, 0.31);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(0.105, 0.261);
glVertex2f(0.105, -0.05 );
glVertex2f(0.116, -0.05 );
glVertex2f(0.116, 0.261);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(0.116, 0.288);
glVertex2f(0.116, -0.05 );
glVertex2f(0.188, -0.05 );
glVertex2f(0.188, 0.288);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(0.188, 0.25);
glVertex2f(0.188, -0.05 );
glVertex2f(0.21, -0.05 );
glVertex2f(0.21, 0.25);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(0.21, 0.23);
glVertex2f(0.21, -0.05 );
glVertex2f(0.224, -0.05 );
glVertex2f(0.224, 0.23);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(0.224, 0.245);
glVertex2f(0.224, -0.05 );
glVertex2f(0.237, -0.05 );
glVertex2f(0.237, 0.245);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(0.237, 0.19);
glVertex2f(0.237, -0.05 );
glVertex2f(0.28, -0.05 );
glVertex2f(0.28, 0.19);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(0.28, 0.35);
glVertex2f(0.28, -0.05 );
glVertex2f(0.37, -0.05 );
glVertex2f(0.37, 0.35);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(0.37, 0.28);
glVertex2f(0.37, -0.05 );
glVertex2f(0.447, -0.05 );
glVertex2f(0.447, 0.28);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(0.447, 0.194);
glVertex2f(0.447, -0.05 );
glVertex2f(0.472, -0.05 );
glVertex2f(0.472, 0.194);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(0.472, 0.21);
glVertex2f(0.472, -0.05 );
glVertex2f(0.494, -0.05 );
glVertex2f(0.494, 0.21);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(0.494, 0.191);
glVertex2f(0.494, -0.05 );
glVertex2f(0.512, -0.05 );
glVertex2f(0.512, 0.191);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(0.512, 0.22);
glVertex2f(0.512, -0.05 );
glVertex2f(0.56, -0.05 );
glVertex2f(0.56, 0.22);
glEnd();

glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(0.56, 0.24);
glVertex2f(0.56, -0.05 );
glVertex2f(0.59, -0.05 );
glVertex2f(0.59, 0.24);
glEnd();

glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(0.59, 0.18);
glVertex2f(0.59, -0.05 );
glVertex2f(0.63, -0.05 );
glVertex2f(0.63, 0.18);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(0.63, 0.25);
glVertex2f(0.63, -0.05 );
glVertex2f(0.69, -0.05 );
glVertex2f(0.69, 0.25);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(0.69, 0.22);
glVertex2f(0.69, -0.05 );
glVertex2f(0.72, -0.05 );
glVertex2f(0.72, 0.22);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(0.72, 0.2);
glVertex2f(0.72, -0.05 );
glVertex2f(0.75, -0.05 );
glVertex2f(0.75, 0.2);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(0.75, 0.18);
glVertex2f(0.75, -0.05 );
glVertex2f(0.78, -0.05 );
glVertex2f(0.78, 0.18);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(0.78, 0.15);
glVertex2f(0.78, -0.05 );
glVertex2f(0.81, -0.05 );
glVertex2f(0.81, 0.15);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(0.81, 0.25);
glVertex2f(0.81, -0.05 );
glVertex2f(0.83, -0.05 );
glVertex2f(0.83, 0.25);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(0.83, 0.22);
glVertex2f(0.83, -0.05 );
glVertex2f(0.86, -0.05 );
glVertex2f(0.86, 0.22);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(0.86, 0.26);
glVertex2f(0.86, -0.05 );
glVertex2f(0.89, -0.05 );
glVertex2f(0.89, 0.26);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(0.89, 0.17);
glVertex2f(0.89, -0.05 );
glVertex2f(0.93, -0.05 );
glVertex2f(0.93, 0.17);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(0.93, 0.23);
glVertex2f(0.93, -0.05 );
glVertex2f(0.96, -0.05 );
glVertex2f(0.96, 0.19);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(0.96, 0.16);
glVertex2f(0.96, -0.05 );
glVertex2f(0.98, -0.05 );
glVertex2f(0.98, 0.16);
glEnd();
glBegin(GL_QUADS);
glColor3ub(68, 79, 72);
glVertex2f(0.98, 0.3);
glVertex2f(0.98, -0.05 );
glVertex2f(1.0, -0.05 );
glVertex2f(1.0, 0.3);
glEnd();
//building 2 end

glBegin(GL_QUADS); //back sea 1
glColor3ub(46, 144, 217);
glVertex2f(1, -0.05);
glVertex2f(1, -0.15 );
glVertex2f(-1, -0.15 );
glVertex2f(-1, -0.05);
glEnd();


glPushMatrix();
glTranslatef(position3,0,0);
glBegin(GL_TRIANGLES); //back sea 1 waves left to right 1
glColor3ub(46, 144, 217);
glVertex2f(1, -0.05);
glVertex2f(0.88, -0.03);
glVertex2f(0.7, -0.05 );
glEnd();

glBegin(GL_TRIANGLES); //back sea 1 waves left to right 2
glColor3ub(46, 144, 217);
glVertex2f(0.25, -0.05);
glVertex2f(0.52, -0.03);
glVertex2f(0.7, -0.05 );
glEnd();

glBegin(GL_TRIANGLES); //back sea 1 waves left to right 3
glColor3ub(46, 144, 217);
glVertex2f(0.25, -0.05);
glVertex2f(-0.02, -0.03);
glVertex2f(-0.3, -0.05 );
glEnd();

glBegin(GL_TRIANGLES); //back sea 1 waves left to right 4
glColor3ub(46, 144, 217);
glVertex2f(-0.85, -0.05);
glVertex2f(-0.6, -0.03);
glVertex2f(-0.3, -0.05 );
glEnd();

glBegin(GL_TRIANGLES); //back sea 1 waves left to right 5
glColor3ub(46, 144, 217);
glVertex2f(-0.82, -0.05);
glVertex2f(-1, -0.05);
glVertex2f(-0.92, -0.03);
glEnd();
glPopMatrix();


glBegin(GL_QUADS); //back sea 2
glColor3ub(28, 131, 180);
glVertex2f(1, -0.15);
glVertex2f(1, -0.22);
glVertex2f(-1, -0.22 );
glVertex2f(-1, -0.15);
glEnd();

glPushMatrix();
glTranslatef(position4,0,0);
glBegin(GL_TRIANGLES); //back sea 2 waves left to right 1
glColor3ub(28, 131, 180);
glVertex2f(1, -0.15);
glVertex2f(0.88, -0.13);
glVertex2f(0.7, -0.15 );
glEnd();

glBegin(GL_TRIANGLES); //back sea 2 waves left to right 2
glColor3ub(28, 131, 180);
glVertex2f(0.2, -0.15);
glVertex2f(0.52, -0.13);
glVertex2f(0.7, -0.15 );
glEnd();

glBegin(GL_TRIANGLES); //back sea 2 waves left to right 3
glColor3ub(28, 131, 180);
glVertex2f(0.25, -0.15);
glVertex2f(-0.02, -0.13);
glVertex2f(-0.3, -0.15 );
glEnd();

glBegin(GL_TRIANGLES); //back sea 2 waves left to right 4
glColor3ub(28, 131, 180);
glVertex2f(-0.38, -0.13);
glVertex2f(-0.38, -0.15);
glVertex2f(-0.3, -0.15 );
glEnd();

glBegin(GL_TRIANGLES); //back sea 2 waves left to right 5
glColor3ub(28, 131, 180);
glVertex2f(-0.38, -0.15);
glVertex2f(-0.38, -0.13);
glVertex2f(-0.58, -0.15);
glEnd();

glBegin(GL_TRIANGLES); //back sea 2 waves left to right 6
glColor3ub(28, 131, 180);
glVertex2f(-0.58, -0.15);
glVertex2f(-0.72, -0.13);
glVertex2f(-0.88, -0.15);
glEnd();

glBegin(GL_TRIANGLES); //back sea 2 waves left to right 6
glColor3ub(28, 131, 180);
glVertex2f(-1, -0.15);
glVertex2f(-0.94, -0.13);
glVertex2f(-0.88, -0.15);
glEnd();

glPopMatrix();


glBegin(GL_QUADS); //Middle port
glColor3ub(164, 160, 159);
glVertex2f(1, -0.22);
glVertex2f(1, -0.38);
glVertex2f(-1, -0.38);
glVertex2f(-1, -0.22);
glEnd();

glBegin(GL_QUADS);//front port
glColor3ub(192, 192, 192);
glVertex2f(-1, -0.58);
glVertex2f(-1, -1);
glVertex2f(1, -1);
glVertex2f(1, -0.58);
glEnd();


//Back Ship Start
glPushMatrix();
glTranslatef(position5,0,0);//animate ship

glBegin(GL_QUADS); //Cabin
glColor3ub(203, 205, 204);
glVertex2f(0.66, -0.088);
glVertex2f(0.79, -0.088 );
glVertex2f(0.79, -0.17 );
glVertex2f(0.66, -0.17);
glEnd();

glBegin(GL_QUADS); //Cabin middle line
glColor3ub(127, 128, 127);
glVertex2f(0.66, -0.125);
glVertex2f(0.79, -0.125 );
glVertex2f(0.79, -0.13 );
glVertex2f(0.66, -0.13);
glEnd();

glBegin(GL_QUADS); //Cabin middle line 2
glColor3ub(127, 128, 127);
glVertex2f(0.695, -0.084);
glVertex2f(0.79, -0.084 );
glVertex2f(0.79, -0.088 );
glVertex2f(0.695, -0.088);
glEnd();

glBegin(GL_QUADS); //Cabin upper
glColor3ub(203, 205, 204);
glVertex2f(0.695, -0.025);
glVertex2f(0.79, -0.025 );
glVertex2f(0.79, -0.084 );
glVertex2f(0.695, -0.084);
glEnd();

glBegin(GL_QUADS); //Cabin Cabin middle line 3
glColor3ub(127, 128, 127);
glVertex2f(0.695, -0.025);
glVertex2f(0.79, -0.025 );
glVertex2f(0.79, -0.02 );
glVertex2f(0.695, -0.02);
glEnd();

glBegin(GL_QUADS); //cabin upper
glColor3ub(203, 205, 204);
glVertex2f(0.695, -0.02);
glVertex2f(0.79, -0.02 );
glVertex2f(0.79, 0.008 );
glVertex2f(0.684, 0.008);
glEnd();


glBegin(GL_QUADS); //cabin middle 4
glColor3ub(131, 128, 135);
glVertex2f(0.73, 0.01);
glVertex2f(0.778, 0.01);
glVertex2f(0.778, 0.008 );
glVertex2f(0.73, 0.008);
glEnd();


glBegin(GL_QUADS); //cabin upper
glColor3ub(203, 205, 204);
glVertex2f(0.73, 0.01);
glVertex2f(0.778, 0.01);
glVertex2f(0.778, 0.03 );
glVertex2f(0.73, 0.03);
glEnd();


glBegin(GL_QUADS); //cabin flag rod
glColor3ub(203, 205, 204);
glVertex2f(0.75, 0.03);
glVertex2f(0.754, 0.03);
glVertex2f(0.754, 0.078 );
glVertex2f(0.75, 0.078);
glEnd();

glBegin(GL_QUADS); //cabin flag
glColor3ub(46, 184, 46);
glVertex2f(0.754, 0.074);
glVertex2f(0.778, 0.074);
glVertex2f(0.778, 0.054 );
glVertex2f(0.754, 0.054);
glEnd();

glBegin(GL_LINES); //cabin flag
glColor3ub(0, 179, 60);
glVertex2f(0.754, 0.074);
glVertex2f(0.778, 0.074);
glVertex2f(0.778, 0.074);
glVertex2f(0.778, 0.054 );
glVertex2f(0.778, 0.054 );
glVertex2f(0.754, 0.054);
glVertex2f(0.754, 0.054);
glVertex2f(0.754, 0.074);
glEnd();


    GLfloat x=.766f; GLfloat y=.064f; GLfloat radius =0.006f;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 0, 0); // flag circle
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


glBegin(GL_QUADS); //top windows 1
glColor3ub(114, 136, 173);
glVertex2f(0.691, 0.004);
glVertex2f(0.71, 0.004 );
glVertex2f(0.71, -0.014 );
glVertex2f(0.698, -0.014);
glEnd();

glBegin(GL_QUADS); //top windows 2
glColor3ub(114, 136, 173);
glVertex2f(0.715, 0.004);
glVertex2f(0.73, 0.004 );
glVertex2f(0.73, -0.014 );
glVertex2f(0.715, -0.014);
glEnd();

glBegin(GL_QUADS); //top windows 3
glColor3ub(114, 136, 173);
glVertex2f(0.735, 0.004);
glVertex2f(0.75, 0.004 );
glVertex2f(0.75, -0.014 );
glVertex2f(0.735, -0.014);
glEnd();

glBegin(GL_QUADS); //top windows 4
glColor3ub(114, 136, 173);
glVertex2f(0.755, 0.004);
glVertex2f(0.77, 0.004 );
glVertex2f(0.77, -0.014 );
glVertex2f(0.755, -0.014);
glEnd();

glBegin(GL_QUADS); //top windows 5
glColor3ub(114, 136, 173);
glVertex2f(0.774, 0.004);
glVertex2f(0.788, 0.004 );
glVertex2f(0.788, -0.014 );
glVertex2f(0.774, -0.014);
glEnd();

glBegin(GL_QUADS); //middle windows 1
glColor3ub(114, 136, 173);
glVertex2f(0.7, -0.03);
glVertex2f(0.71, -0.03 );
glVertex2f(0.71, -0.045 );
glVertex2f(0.7, -0.045);
glEnd();

glBegin(GL_QUADS); //middle windows 2
glColor3ub(114, 136, 173);
glVertex2f(0.715, -0.03);
glVertex2f(0.725, -0.03 );
glVertex2f(0.725, -0.045 );
glVertex2f(0.715, -0.045);
glEnd();

glBegin(GL_QUADS); //middle windows 3
glColor3ub(114, 136, 173);
glVertex2f(0.735, -0.03);
glVertex2f(0.75, -0.03 );
glVertex2f(0.75, -0.045 );
glVertex2f(0.735, -0.045);
glEnd();

glBegin(GL_QUADS); //middle windows 4
glColor3ub(114, 136, 173);
glVertex2f(0.76, -0.03);
glVertex2f(0.77, -0.03 );
glVertex2f(0.77, -0.045 );
glVertex2f(0.76, -0.045);
glEnd();

glBegin(GL_QUADS); //middle windows 5
glColor3ub(114, 136, 173);
glVertex2f(0.775, -0.03);
glVertex2f(0.785, -0.03 );
glVertex2f(0.785, -0.045 );
glVertex2f(0.775, -0.045);
glEnd();

glBegin(GL_QUADS); //middle windows 6
glColor3ub(114, 136, 173);
glVertex2f(0.7, -0.055);
glVertex2f(0.71,-0.055 );
glVertex2f(0.71, -0.07 );
glVertex2f(0.7, -0.07);
glEnd();

glBegin(GL_QUADS); //middle windows 7
glColor3ub(114, 136, 173);
glVertex2f(0.715, -0.055);
glVertex2f(0.725, -0.055 );
glVertex2f(0.725, -0.07 );
glVertex2f(0.715, -0.07);
glEnd();

glBegin(GL_QUADS); //middle windows 8
glColor3ub(114, 136, 173);
glVertex2f(0.735, -0.055);
glVertex2f(0.75,-0.055 );
glVertex2f(0.75, -0.07 );
glVertex2f(0.735, -0.07);
glEnd();

glBegin(GL_QUADS); //middle windows 9
glColor3ub(114, 136, 173);
glVertex2f(0.76, -0.055);
glVertex2f(0.77, -0.055 );
glVertex2f(0.77,-0.07 );
glVertex2f(0.76, -0.07);
glEnd();

glBegin(GL_QUADS); //middle windows 10
glColor3ub(114, 136, 173);
glVertex2f(0.775, -0.055);
glVertex2f(0.785,-0.055 );
glVertex2f(0.785, -0.07 );
glVertex2f(0.775, -0.07);
glEnd();


   GLfloat x1=.68f; GLfloat y1=-.15f; GLfloat radius1 =0.009f;
	int triangleAmount1 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(114, 136, 173); // lower windows 1
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= triangleAmount1;i++) {
			glVertex2f(
		            x1 + (radius1 * cos(i *  twicePi1 / triangleAmount1)),
			    y1 + (radius1 * sin(i * twicePi1 / triangleAmount1))
			);
		}
	glEnd();

	   GLfloat x2=.7f; GLfloat y2=-.15f; GLfloat radius2 =0.009f;
	int triangleAmount2 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi2 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(114, 136, 173); // lower windows 1
		glVertex2f(x2, y2); // center of circle
		for(i = 0; i <= triangleAmount2;i++) {
			glVertex2f(
		            x2 + (radius2 * cos(i *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i * twicePi2 / triangleAmount2))
			);
		}
	glEnd();


	   GLfloat x3=.72f; GLfloat y3=-.15f; GLfloat radius3 =0.009f;
	int triangleAmount3 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi3 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(114, 136, 173); // lower windows 1
		glVertex2f(x3, y3); // center of circle
		for(i = 0; i <= triangleAmount3;i++) {
			glVertex2f(
		            x3 + (radius3 * cos(i *  twicePi3 / triangleAmount3)),
			    y3 + (radius3 * sin(i * twicePi3 / triangleAmount3))
			);
		}
	glEnd();


glBegin(GL_QUADS); //cargo
glColor3ub(53, 77, 156);
glVertex2f(0.545, -0.135);
glVertex2f(0.615,-0.135 );
glVertex2f(0.615, -0.176 );
glVertex2f(0.545, -0.175);
glEnd();

glBegin(GL_LINES); //cargo
glColor3ub(22, 42, 119);
glVertex2f(0.545, -0.135);
glVertex2f(0.615,-0.135 );

glVertex2f(0.615,-0.135 );
glVertex2f(0.615, -0.176 );

glVertex2f(0.615, -0.176 );
glVertex2f(0.545, -0.175);

glVertex2f(0.545, -0.175);
glVertex2f(0.545, -0.135);

glEnd();

glBegin(GL_QUADS); //cargo
glColor3ub(93, 144, 144);
glVertex2f(0.47, -0.135);
glVertex2f(0.54,-0.135 );
glVertex2f(0.54, -0.176 );
glVertex2f(0.47, -0.176);
glEnd();

glBegin(GL_LINES); //cargo
glColor3ub(68, 117, 95);
glVertex2f(0.47, -0.135);
glVertex2f(0.54,-0.135 );
glVertex2f(0.54,-0.135 );
glVertex2f(0.54, -0.176 );
glVertex2f(0.54, -0.176 );
glVertex2f(0.47, -0.176);
glVertex2f(0.47, -0.176);
glVertex2f(0.47, -0.135);
glEnd();

glBegin(GL_QUADS); //cargo
glColor3ub(46, 76, 151);
glVertex2f(0.4, -0.135);
glVertex2f(0.468,-0.135 );
glVertex2f(0.468, -0.176 );
glVertex2f(0.4, -0.176);
glEnd();

glBegin(GL_LINES); //cargo
glColor3ub(40, 57, 102);
glVertex2f(0.4, -0.135);
glVertex2f(0.468,-0.135 );
glVertex2f(0.468,-0.135 );
glVertex2f(0.468, -0.176 );
glVertex2f(0.468, -0.176 );
glVertex2f(0.4, -0.176);
glVertex2f(0.4, -0.176);
glVertex2f(0.4, -0.135);
glEnd();

glBegin(GL_QUADS); //cargo
glColor3ub(139, 60, 52);
glVertex2f(0.4, -0.098);
glVertex2f(0.468,-0.098 );
glVertex2f(0.468, -0.135 );
glVertex2f(0.4, -0.135);
glEnd();

glBegin(GL_LINES); //cargo
glColor3ub(102, 29, 24);
glVertex2f(0.4, -0.098);
glVertex2f(0.468,-0.098 );
glVertex2f(0.468,-0.098 );
glVertex2f(0.468, -0.135 );
glVertex2f(0.468, -0.135 );
glVertex2f(0.4, -0.135);
glVertex2f(0.4, -0.135);
glVertex2f(0.4, -0.098);
glEnd();

glBegin(GL_QUADS); //cargo
glColor3ub(191, 188, 195);
glVertex2f(0.47, -0.095);
glVertex2f(0.54,-0.095 );
glVertex2f(0.54, -0.135 );
glVertex2f(0.47, -0.135);
glEnd();

glBegin(GL_LINES); //cargo
glColor3ub(124, 124, 132);
glVertex2f(0.47, -0.095);
glVertex2f(0.54,-0.095 );
glVertex2f(0.54,-0.095 );
glVertex2f(0.54, -0.135 );
glVertex2f(0.54, -0.135 );
glVertex2f(0.47, -0.135);
glVertex2f(0.47, -0.135);
glVertex2f(0.47, -0.095);
glEnd();


glBegin(GL_QUADS); //cargo
glColor3ub(175, 186, 99);
glVertex2f(0.47, -0.06);
glVertex2f(0.54,-0.06 );
glVertex2f(0.54, -0.095 );
glVertex2f(0.47, -0.095);
glEnd();

glBegin(GL_LINES); //cargo
glColor3ub(113, 122, 46);
glVertex2f(0.47, -0.06);
glVertex2f(0.54,-0.06 );
glVertex2f(0.54,-0.06 );
glVertex2f(0.54, -0.095 );
glVertex2f(0.54, -0.095 );
glVertex2f(0.47, -0.095);
glVertex2f(0.47, -0.095);
glVertex2f(0.47, -0.06);
glEnd();

glBegin(GL_QUADS); //cargo
glColor3ub(100, 134, 75);
glVertex2f(0.47, -0.03);
glVertex2f(0.54,-0.03 );
glVertex2f(0.54, -0.06 );
glVertex2f(0.47, -0.06);
glEnd();

glBegin(GL_LINES); //cargo
glColor3ub(38, 107, 10);
glVertex2f(0.47, -0.03);
glVertex2f(0.54,-0.03 );
glVertex2f(0.54,-0.03 );
glVertex2f(0.54, -0.06 );
glVertex2f(0.54, -0.06 );
glVertex2f(0.47, -0.06);
glVertex2f(0.47, -0.06);
glVertex2f(0.47, -0.03);
glEnd();


glBegin(GL_QUADS); //cargo
glColor3ub(76, 59, 134);
glVertex2f(0.545, -0.097);
glVertex2f(0.615,-0.097 );
glVertex2f(0.615, -0.135 );
glVertex2f(0.545, -0.135);
glEnd();

glBegin(GL_LINES); //cargo
glColor3ub(62, 52, 96);
glVertex2f(0.545, -0.097);
glVertex2f(0.615,-0.097 );
glVertex2f(0.615,-0.097 );
glVertex2f(0.615, -0.135 );
glVertex2f(0.615, -0.135 );
glVertex2f(0.545, -0.135);
glVertex2f(0.545, -0.135);
glVertex2f(0.545, -0.097);
glEnd();

glBegin(GL_QUADS); //cargo
glColor3ub(126, 51, 38);
glVertex2f(0.545, -0.06);
glVertex2f(0.615,-0.06 );
glVertex2f(0.615, -0.097 );
glVertex2f(0.545, -0.097);
glEnd();

glBegin(GL_LINES); //cargo
glColor3ub(96, 35, 23);
glVertex2f(0.545, -0.06);
glVertex2f(0.615,-0.06 );
glVertex2f(0.615,-0.06 );
glVertex2f(0.615, -0.097 );
glVertex2f(0.615, -0.097 );
glVertex2f(0.545, -0.097);
glVertex2f(0.545, -0.097);
glVertex2f(0.545, -0.06);
glEnd();

glBegin(GL_POLYGON); //Hull
glColor3ub(33, 35, 34);
glVertex2f(0.762, -0.106);
glVertex2f(0.76, -0.13);
glVertex2f(0.75, -0.145 );
glVertex2f(0.8, -0.17);
glVertex2f(0.82, -0.15);
glVertex2f(0.83, -0.13);
glVertex2f(0.832, -0.106);
glEnd();

glBegin(GL_POLYGON); //Hull 2
glColor3ub(33, 35, 34);
glVertex2f(0.722, -0.166);
glVertex2f(0.74, -0.155);
glVertex2f(0.75, -0.145 );
glVertex2f(0.8, -0.17);
glVertex2f(0.78, -0.188);
glVertex2f(0.77, -0.204);
glVertex2f(0.765, -0.22);
glVertex2f(0.722, -0.22);
glEnd();

glBegin(GL_QUADS); //Hull 3
glColor3ub(33, 35, 34);
glVertex2f(0.637, -0.166);
glVertex2f(0.722, -0.166 );
glVertex2f(0.722, -0.22 );
glVertex2f(0.637, -0.22);
glEnd();


glBegin(GL_QUADS); //Hull 4
glColor3ub(33, 35, 34);
glVertex2f(0.637, -0.18);
glVertex2f(0.637, -0.22 );
glVertex2f(0.42, -0.22 );
glVertex2f(0.42, -0.18);
glEnd();

glBegin(GL_POLYGON); //Hull 5
glColor3ub(33, 35, 34);
glVertex2f(0.42, -0.22);
glVertex2f(0.42, -0.18);
glVertex2f(0.398, -0.16 );
glVertex2f(0.39, -0.15);
glVertex2f(0.384, -0.132);
glVertex2f(0.38, -0.132);
glVertex2f(0.38, -0.22);
glEnd();

glBegin(GL_QUADS); //Hull 5
glColor3ub(33, 35, 34);
glVertex2f(0.38, -0.132);
glVertex2f(0.38, -0.22 );
glVertex2f(0.27, -0.22 );
glVertex2f(0.27, -0.132);
glEnd();

glBegin(GL_POLYGON); //Hull 6
glColor3ub(33, 35, 34);
glVertex2f(0.27, -0.132);
glVertex2f(0.215, -0.132);
glVertex2f(0.23, -0.168 );
glVertex2f(0.248, -0.195);
glVertex2f(0.27, -0.22);
glEnd();

glBegin(GL_QUADS); //Hull 6
glColor3ub(255, 255, 255);
glVertex2f(0.383, -0.128);
glVertex2f(0.384, -0.132 );
glVertex2f(0.215, -0.132 );
glVertex2f(0.214, -0.128);
glEnd();

glBegin(GL_QUADS); //Hull 7
glColor3ub(159, 41, 37);
glVertex2f(0.383, -0.128);
glVertex2f(0.214, -0.128);
glVertex2f(0.207, -0.108 );
glVertex2f(0.38, -0.108 );
glEnd();

glBegin(GL_QUADS); //Railings
glColor3ub(255, 255, 255);
glVertex2f(0.4158, -0.176);
glVertex2f(0.42, -0.18);
glVertex2f(0.637, -0.18 );
glVertex2f(0.637, -0.176 );
glEnd();

glBegin(GL_LINES); //Railings 2
glColor3ub(255, 255, 255);

glVertex2f(0.644, -0.166);
glVertex2f(0.644, -0.145);

glVertex2f(0.644, -0.145);
glVertex2f(0.3885, -0.145);

glVertex2f(0.625, -0.145);
glVertex2f(0.625, -0.176);

glVertex2f(0.608, -0.145);
glVertex2f(0.608, -0.176);

glVertex2f(0.59, -0.145);
glVertex2f(0.59, -0.176);

glVertex2f(0.573, -0.145);
glVertex2f(0.573, -0.176);

glVertex2f(0.5545, -0.145);
glVertex2f(0.5545, -0.176);

glVertex2f(0.5375, -0.145);
glVertex2f(0.5375, -0.176);

glVertex2f(0.519, -0.145);
glVertex2f(0.519, -0.176);

glVertex2f(0.502, -0.145);
glVertex2f(0.502, -0.176);

glVertex2f(0.484, -0.145);
glVertex2f(0.484, -0.176);

glVertex2f(0.466, -0.145);
glVertex2f(0.466, -0.176);

glVertex2f(0.448, -0.145);
glVertex2f(0.448, -0.176);

glVertex2f(0.43, -0.145);
glVertex2f(0.43, -0.176);

glVertex2f(0.413, -0.145);
glVertex2f(0.413, -0.1736);

glVertex2f(0.402, -0.145);
glVertex2f(0.402, -0.1636);
glEnd();
//back ship end

//back ship shadow
glBegin(GL_POLYGON); //shadow
glColor3ub(126, 126, 125);
glVertex2f(0.66, -0.22);
glVertex2f(0.764, -0.22);
glVertex2f(0.767, -0.23);
glVertex2f(0.773, -0.24);
glVertex2f(0.79, -0.25);
glVertex2f(0.79, -0.25);
glVertex2f(0.66, -0.25);
glEnd();

glBegin(GL_POLYGON); //shadow
glColor3ub(126, 126, 125);
glVertex2f(0.66, -0.25);
glVertex2f(0.79, -0.25);
glVertex2f(0.816, -0.262);
glVertex2f(0.828, -0.274);
glVertex2f(0.83, -0.3);
glVertex2f(0.66, -0.3);
glEnd();


glBegin(GL_POLYGON); //shadow
glColor3ub(126, 126, 125);
glVertex2f(0.66, -0.22);
glVertex2f(0.66, -0.255);
glVertex2f(0.636, -0.255);
glVertex2f(0.636, -0.252);
glVertex2f(0.235, -0.252);
glVertex2f(0.255, -0.236);
glVertex2f(0.28, -0.22);
glEnd();

glBegin(GL_POLYGON); //shadow
glColor3ub(126, 126, 125);
glVertex2f(0.235, -0.252);
glVertex2f(0.225, -0.26);
glVertex2f(0.22, -0.27);
glVertex2f(0.218, -0.285);
glVertex2f(0.38, -0.285);
glVertex2f(0.385, -0.27);
glVertex2f(0.4, -0.25);
glEnd();

glBegin(GL_QUADS); //shadow
glColor3ub(126, 126, 125);
glVertex2f(0.4, -0.25);
glVertex2f(0.4, -0.29);
glVertex2f(0.47, -0.29);
glVertex2f(0.47, -0.25);
glEnd();

glBegin(GL_QUADS); //shadow
glColor3ub(126, 126, 125);
glVertex2f(0.472, -0.25);
glVertex2f(0.472, -0.324);
glVertex2f(0.54, -0.324);
glVertex2f(0.54, -0.25);
glEnd();

glBegin(GL_QUADS); //shadow
glColor3ub(126, 126, 125);
glVertex2f(0.545, -0.25);
glVertex2f(0.545, -0.31);
glVertex2f(0.62, -0.31);
glVertex2f(0.62, -0.25);
glEnd();

glBegin(GL_LINES); //shadow
glColor3ub(126, 126, 125);
glVertex2f(0.644, -0.254);
glVertex2f(0.644, -0.268);
glVertex2f(0.644, -0.268);
glVertex2f(0.42, -0.268);
glEnd();

glBegin(GL_QUADS); //shadow
glColor3ub(126, 126, 125);
glVertex2f(0.695, -0.3);
glVertex2f(0.79, -0.3);
glVertex2f(0.79, -0.33);
glVertex2f(0.695, -0.33);
glEnd();

glBegin(GL_QUADS); //shadow
glColor3ub(126, 126, 125);
glVertex2f(0.695, -0.33);
glVertex2f(0.79, -0.33);
glVertex2f(0.79, -0.35);
glVertex2f(0.685, -0.35);
glEnd();

glBegin(GL_QUADS); //shadow
glColor3ub(126, 126, 125);
glVertex2f(0.73, -0.35);
glVertex2f(0.78, -0.35);
glVertex2f(0.78, -0.355);
glVertex2f(0.73, -0.355);
glEnd();

glPopMatrix();
//back ship shadow ends

glBegin(GL_QUADS); //Cargo Floor
glColor3ub(151, 142, 124);
glVertex2f(-1, -0.275);
glVertex2f(-1, -0.312);
glVertex2f(-0.345, -0.312);
glVertex2f(-0.345, -0.275);
glEnd();

glBegin(GL_LINES); //Cargo Floor
glColor3ub(122, 111, 91);
glVertex2f(-1, -0.275);
glVertex2f(-1, -0.312);
glVertex2f(-1, -0.312);
glVertex2f(-0.345, -0.312);
glVertex2f(-0.345, -0.312);
glVertex2f(-0.345, -0.275);
glVertex2f(-0.345, -0.275);
glVertex2f(-1, -0.275);
glEnd();


glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.991, -0.281);
glVertex2f(-0.991, -0.306);
glVertex2f(-0.975, -0.306);
glVertex2f(-0.975, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.96, -0.281);
glVertex2f(-0.96, -0.306);
glVertex2f(-0.945, -0.306);
glVertex2f(-0.945, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.93, -0.281);
glVertex2f(-0.93, -0.306);
glVertex2f(-0.915, -0.306);
glVertex2f(-0.915, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.9, -0.281);
glVertex2f(-0.9, -0.306);
glVertex2f(-0.885, -0.306);
glVertex2f(-0.885, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.87, -0.281);
glVertex2f(-0.87, -0.306);
glVertex2f(-0.856, -0.306);
glVertex2f(-0.856, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.845, -0.281);
glVertex2f(-0.845, -0.306);
glVertex2f(-0.83, -0.306);
glVertex2f(-0.83, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.815, -0.281);
glVertex2f(-0.815, -0.306);
glVertex2f(-0.8, -0.306);
glVertex2f(-0.8, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.785, -0.281);
glVertex2f(-0.785, -0.306);
glVertex2f(-0.77, -0.306);
glVertex2f(-0.77, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.755, -0.281);
glVertex2f(-0.755, -0.306);
glVertex2f(-0.74, -0.306);
glVertex2f(-0.74, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.725, -0.281);
glVertex2f(-0.725, -0.306);
glVertex2f(-0.71, -0.306);
glVertex2f(-0.71, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.695, -0.281);
glVertex2f(-0.695, -0.306);
glVertex2f(-0.68, -0.306);
glVertex2f(-0.68, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.665, -0.281);
glVertex2f(-0.665, -0.306);
glVertex2f(-0.65, -0.306);
glVertex2f(-0.65, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.64, -0.281);
glVertex2f(-0.64, -0.306);
glVertex2f(-0.625, -0.306);
glVertex2f(-0.625, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.61, -0.281);
glVertex2f(-0.61, -0.306);
glVertex2f(-0.595, -0.306);
glVertex2f(-0.595, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.58, -0.281);
glVertex2f(-0.58, -0.306);
glVertex2f(-0.56, -0.306);
glVertex2f(-0.56, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.55, -0.281);
glVertex2f(-0.55, -0.306);
glVertex2f(-0.53, -0.306);
glVertex2f(-0.53, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.52, -0.281);
glVertex2f(-0.52, -0.306);
glVertex2f(-0.5, -0.306);
glVertex2f(-0.5, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.49, -0.281);
glVertex2f(-0.49, -0.306);
glVertex2f(-0.47, -0.306);
glVertex2f(-0.47, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.46, -0.281);
glVertex2f(-0.46, -0.306);
glVertex2f(-0.44, -0.306);
glVertex2f(-0.44, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.43, -0.281);
glVertex2f(-0.43, -0.306);
glVertex2f(-0.41, -0.306);
glVertex2f(-0.41, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.4, -0.281);
glVertex2f(-0.4, -0.306);
glVertex2f(-0.38, -0.306);
glVertex2f(-0.38, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.37, -0.281);
glVertex2f(-0.37, -0.306);
glVertex2f(-0.35, -0.306);
glVertex2f(-0.35, -0.281);
glEnd();

//Cargo boxes left upper then lines
glBegin(GL_QUADS);
glColor3ub(137, 97, 27);
glVertex2f(-0.855, -0.01);
glVertex2f(-0.855, -0.062);
glVertex2f(-0.768, -0.062);
glVertex2f(-0.768, -0.01);
glEnd();
glBegin(GL_QUADS);
glColor3ub(130, 17, 23);
glVertex2f(-0.8552, -0.062);
glVertex2f(-0.8552, -0.115);
glVertex2f(-0.768, -0.115);
glVertex2f(-0.768, -0.062);
glEnd();
glBegin(GL_QUADS);
glColor3ub(71, 95, 133);
glVertex2f(-0.942, -0.062);
glVertex2f(-0.942, -0.115);
glVertex2f(-0.8552, -0.115);
glVertex2f(-0.8552, -0.062);
glEnd();
glBegin(GL_QUADS);
glColor3ub(137, 97, 27);
glVertex2f(-1, -0.115);
glVertex2f(-1, -0.168);
glVertex2f(-0.942, -0.168);
glVertex2f(-0.942, -0.115);
glEnd();
glBegin(GL_QUADS);
glColor3ub(53, 54, 160);
glVertex2f(-0.942, -0.115);
glVertex2f(-0.942, -0.168);
glVertex2f(-0.8552, -0.168);
glVertex2f(-0.8552, -0.115);
glEnd();
glBegin(GL_QUADS);
glColor3ub(118, 77, 145);
glVertex2f(-0.855, -0.115);
glVertex2f(-0.8552, -0.168);
glVertex2f(-0.768, -0.168);
glVertex2f(-0.768, -0.115);
glEnd();
glBegin(GL_QUADS);
glColor3ub(53, 54, 160);
glVertex2f(-0.768, -0.115);
glVertex2f(-0.768, -0.168);
glVertex2f(-0.677, -0.168);
glVertex2f(-0.677, -0.115);
glEnd();
glBegin(GL_QUADS);
glColor3ub(161, 47, 53);
glVertex2f(-0.768, -0.168);
glVertex2f(-0.768, -0.222);
glVertex2f(-0.677, -0.222);
glVertex2f(-0.677, -0.168);
glEnd();
glBegin(GL_QUADS);
glColor3ub(205, 194, 49);
glVertex2f(-0.8552, -0.168);
glVertex2f(-0.8552, -0.222);
glVertex2f(-0.768, -0.222);
glVertex2f(-0.768, -0.168);
glEnd();
glBegin(GL_QUADS);
glColor3ub(161, 47, 53);
glVertex2f(-0.945, -0.168);
glVertex2f(-0.945, -0.222);
glVertex2f(-0.8552, -0.222);
glVertex2f(-0.8552, -0.168);
glEnd();
glBegin(GL_QUADS);
glColor3ub(56, 84, 129);
glVertex2f(-1, -0.168);
glVertex2f(-1, -0.222);
glVertex2f(-0.945, -0.222);
glVertex2f(-0.945, -0.168);
glEnd();
glBegin(GL_QUADS);
glColor3ub(157, 53, 116);
glVertex2f(-1, -0.222);
glVertex2f(-1, -0.274);
glVertex2f(-0.945, -0.274);
glVertex2f(-0.945, -0.222);
glEnd();
glBegin(GL_QUADS);
glColor3ub(205, 194, 49);
glVertex2f(-0.945, -0.222);
glVertex2f(-0.945, -0.274);
glVertex2f(-0.8552, -0.274);
glVertex2f(-0.8552, -0.222);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 163, 92);
glVertex2f(-0.8552, -0.222);
glVertex2f(-0.8552, -0.274);
glVertex2f(-0.768, -0.274);
glVertex2f(-0.768, -0.222);
glEnd();
glBegin(GL_QUADS);
glColor3ub(205, 194, 49);
glVertex2f(-0.768, -0.222);
glVertex2f(-0.768, -0.274);
glVertex2f(-0.677, -0.274);
glVertex2f(-0.677, -0.222);
glEnd();
glBegin(GL_QUADS);
glColor3ub(191, 181, 40);
glVertex2f(-0.644, -0.222);
glVertex2f(-0.554, -0.222);
glVertex2f(-0.554, -0.275);
glVertex2f(-0.644, -0.275);
glEnd();
glBegin(GL_QUADS);
glColor3ub(140, 31, 35);
glVertex2f(-0.644, -0.168);
glVertex2f(-0.554, -0.168);
glVertex2f(-0.554, -0.222);
glVertex2f(-0.644, -0.222);
glEnd();
glBegin(GL_QUADS);
glColor3ub(38, 40, 151);
glVertex2f(-0.644, -0.116);
glVertex2f(-0.554, -0.116);
glVertex2f(-0.554, -0.168);
glVertex2f(-0.644, -0.168);
glEnd();
glBegin(GL_QUADS);
glColor3ub(69, 90, 124);
glVertex2f(-0.644, -0.066);
glVertex2f(-0.554, -0.066);
glVertex2f(-0.554, -0.116);
glVertex2f(-0.644, -0.116);
glEnd();
glBegin(GL_QUADS);
glColor3ub(61, 173, 95);
glVertex2f(-0.554, -0.222);
glVertex2f(-0.465, -0.222);
glVertex2f(-0.465, -0.275);
glVertex2f(-0.554, -0.275);
glEnd();
glBegin(GL_QUADS);
glColor3ub(50, 71, 109);
glVertex2f(-0.554, -0.168);
glVertex2f(-0.465, -0.168);
glVertex2f(-0.465, -0.222);
glVertex2f(-0.554, -0.222);
glEnd();
glBegin(GL_QUADS);
glColor3ub(132, 91, 25);
glVertex2f(-0.554, -0.116);
glVertex2f(-0.465, -0.116);
glVertex2f(-0.465, -0.168);
glVertex2f(-0.554, -0.168);
glEnd();
glBegin(GL_QUADS);
glColor3ub(162, 46, 53);
glVertex2f(-0.554, -0.066);
glVertex2f(-0.465, -0.066);
glVertex2f(-0.465, -0.116);
glVertex2f(-0.554, -0.116);
glEnd();
glBegin(GL_QUADS);
glColor3ub(190, 184, 37);
glVertex2f(-0.554, -0.012);
glVertex2f(-0.465, -0.012);
glVertex2f(-0.465, -0.066);
glVertex2f(-0.554, -0.066);
glEnd();
glBegin(GL_QUADS);
glColor3ub(102, 67, 132);
glVertex2f(-0.554, 0.04);
glVertex2f(-0.465, 0.04);
glVertex2f(-0.465, -0.012);
glVertex2f(-0.554, -0.012);
glEnd();
glBegin(GL_QUADS);
glColor3ub(196, 185, 42);
glVertex2f(-0.465, -0.225);
glVertex2f(-0.375, -0.225);
glVertex2f(-0.375, -0.275);
glVertex2f(-0.465, -0.275);
glEnd();
glBegin(GL_QUADS);
glColor3ub(173, 85, 28);
glVertex2f(-0.465, -0.18);
glVertex2f(-0.375, -0.18);
glVertex2f(-0.375, -0.225);
glVertex2f(-0.465, -0.225);
glEnd();

glBegin(GL_QUADS);
glColor3ub(19, 23, 119);
glVertex2f(-0.465, -0.135);
glVertex2f(-0.375, -0.135);
glVertex2f(-0.375, -0.18);
glVertex2f(-0.465, -0.18);
glEnd();

glBegin(GL_QUADS);
glColor3ub(135, 25, 32);
glVertex2f(-0.465, -0.085);
glVertex2f(-0.375, -0.085);
glVertex2f(-0.375, -0.135);
glVertex2f(-0.465, -0.135);
glEnd();

glBegin(GL_QUADS);
glColor3ub(33, 33, 139);
glVertex2f(-0.465, -0.025);
glVertex2f(-0.375, -0.025);
glVertex2f(-0.375, -0.085);
glVertex2f(-0.465, -0.085);
glEnd();


glBegin(GL_LINES);
glColor3ub(64, 64, 64);
glVertex2f(-0.855, -0.01);//1
glVertex2f(-0.855, -0.062);
glVertex2f(-0.855, -0.062);
glVertex2f(-0.768, -0.062);
glVertex2f(-0.768, -0.062);
glVertex2f(-0.768, -0.01);
glVertex2f(-0.768, -0.01);
glVertex2f(-0.855, -0.01);

glVertex2f(-0.855, -0.062);//2
glVertex2f(-0.855, -0.115);
glVertex2f(-0.855, -0.115);
glVertex2f(-0.768, -0.115);
glVertex2f(-0.768, -0.115);
glVertex2f(-0.768, -0.062);
glVertex2f(-0.768, -0.062);
glVertex2f(-0.855, -0.062);

glVertex2f(-0.942, -0.062);//3
glVertex2f(-0.942, -0.115);
glVertex2f(-0.942, -0.115);
glVertex2f(-0.855, -0.115);
glVertex2f(-0.855, -0.115);
glVertex2f(-0.855, -0.062);
glVertex2f(-0.855, -0.062);
glVertex2f(-0.942, -0.062);

glVertex2f(-1, -0.115);//4
glVertex2f(-1, -0.168);
glVertex2f(-1, -0.168);
glVertex2f(-0.942, -0.168);
glVertex2f(-0.942, -0.168);
glVertex2f(-0.942, -0.115);
glVertex2f(-0.942, -0.115);
glVertex2f(-1, -0.115);

glVertex2f(-0.942, -0.115);//5
glVertex2f(-0.942, -0.168);
glVertex2f(-0.942, -0.168);
glVertex2f(-0.8552, -0.168);
glVertex2f(-0.8552, -0.168);
glVertex2f(-0.8552, -0.115);
glVertex2f(-0.8552, -0.115);
glVertex2f(-0.942, -0.115);

glVertex2f(-0.8552, -0.115);//6
glVertex2f(-0.8552, -0.168);
glVertex2f(-0.8552, -0.168);
glVertex2f(-0.768, -0.168);
glVertex2f(-0.768, -0.168);
glVertex2f(-0.768, -0.115);
glVertex2f(-0.768, -0.115);
glVertex2f(-0.8552, -0.115);

glVertex2f(-0.768, -0.115);//7
glVertex2f(-0.768, -0.168);
glVertex2f(-0.768, -0.168);
glVertex2f(-0.677, -0.168);
glVertex2f(-0.677, -0.168);
glVertex2f(-0.677, -0.115);
glVertex2f(-0.677, -0.115);
glVertex2f(-0.768, -0.115);

glVertex2f(-0.768, -0.168);//8
glVertex2f(-0.768, -0.222);
glVertex2f(-0.768, -0.222);
glVertex2f(-0.677, -0.222);
glVertex2f(-0.677, -0.222);
glVertex2f(-0.677, -0.168);
glVertex2f(-0.677, -0.168);
glVertex2f(-0.768, -0.168);

glVertex2f(-0.8552, -0.168);//9
glVertex2f(-0.8552, -0.222);
glVertex2f(-0.8552, -0.222);
glVertex2f(-0.768, -0.222);
glVertex2f(-0.768, -0.222);
glVertex2f(-0.768, -0.168);
glVertex2f(-0.768, -0.168);
glVertex2f(-0.8552, -0.168);

glVertex2f(-0.945, -0.168);//10
glVertex2f(-0.945, -0.222);
glVertex2f(-0.945, -0.222);
glVertex2f(-0.8552, -0.222);
glVertex2f(-0.8552, -0.222);
glVertex2f(-0.8552, -0.168);
glVertex2f(-0.8552, -0.168);
glVertex2f(-0.945, -0.168);

glVertex2f(-1, -0.168);//11
glVertex2f(-1, -0.222);
glVertex2f(-1, -0.222);
glVertex2f(-0.945, -0.222);
glVertex2f(-0.945, -0.222);
glVertex2f(-0.945, -0.168);
glVertex2f(-0.945, -0.168);
glVertex2f(-1, -0.168);

glVertex2f(-1, -0.222);//12
glVertex2f(-1, -0.274);
glVertex2f(-1, -0.274);
glVertex2f(-0.945, -0.274);
glVertex2f(-0.945, -0.274);
glVertex2f(-0.945, -0.222);
glVertex2f(-0.945, -0.222);
glVertex2f(-1, -0.222);

glVertex2f(-0.945, -0.222);//13
glVertex2f(-0.945, -0.274);
glVertex2f(-0.945, -0.274);
glVertex2f(-0.8552, -0.274);
glVertex2f(-0.8552, -0.274);
glVertex2f(-0.8552, -0.222);
glVertex2f(-0.8552, -0.222);
glVertex2f(-0.945, -0.222);

glVertex2f(-0.8552, -0.222);//14
glVertex2f(-0.8552, -0.274);
glVertex2f(-0.8552, -0.274);
glVertex2f(-0.768, -0.274);
glVertex2f(-0.768, -0.274);
glVertex2f(-0.768, -0.222);
glVertex2f(-0.768, -0.222);
glVertex2f(-0.8552, -0.222);

glVertex2f(-0.768, -0.222);//15
glVertex2f(-0.768, -0.274);
glVertex2f(-0.768, -0.274);
glVertex2f(-0.677, -0.274);
glVertex2f(-0.677, -0.274);
glVertex2f(-0.677, -0.222);
glVertex2f(-0.677, -0.222);
glVertex2f(-0.768, -0.222);

glVertex2f(-0.644, -0.222);//16
glVertex2f(-0.554, -0.222);
glVertex2f(-0.554, -0.222);
glVertex2f(-0.554, -0.275);
glVertex2f(-0.554, -0.275);
glVertex2f(-0.644, -0.275);
glVertex2f(-0.644, -0.275);
glVertex2f(-0.644, -0.222);

glVertex2f(-0.644, -0.168);//17
glVertex2f(-0.554, -0.168);
glVertex2f(-0.554, -0.168);
glVertex2f(-0.554, -0.222);
glVertex2f(-0.554, -0.222);
glVertex2f(-0.644, -0.222);
glVertex2f(-0.644, -0.222);
glVertex2f(-0.644, -0.168);

glVertex2f(-0.644, -0.116);//18
glVertex2f(-0.554, -0.116);
glVertex2f(-0.554, -0.116);
glVertex2f(-0.554, -0.168);
glVertex2f(-0.554, -0.168);
glVertex2f(-0.644, -0.168);
glVertex2f(-0.644, -0.168);
glVertex2f(-0.644, -0.116);

glVertex2f(-0.644, -0.066);//19
glVertex2f(-0.554, -0.066);
glVertex2f(-0.554, -0.066);
glVertex2f(-0.554, -0.116);
glVertex2f(-0.554, -0.116);
glVertex2f(-0.644, -0.116);
glVertex2f(-0.644, -0.116);
glVertex2f(-0.644, -0.066);

glVertex2f(-0.554, -0.222);//20
glVertex2f(-0.465, -0.222);
glVertex2f(-0.465, -0.222);
glVertex2f(-0.465, -0.275);
glVertex2f(-0.465, -0.275);
glVertex2f(-0.554, -0.275);
glVertex2f(-0.554, -0.275);
glVertex2f(-0.554, -0.222);

glVertex2f(-0.554, -0.168);//21
glVertex2f(-0.465, -0.168);
glVertex2f(-0.465, -0.168);
glVertex2f(-0.465, -0.222);
glVertex2f(-0.465, -0.222);
glVertex2f(-0.554, -0.222);
glVertex2f(-0.554, -0.222);
glVertex2f(-0.554, -0.168);

glVertex2f(-0.554, -0.116);//22
glVertex2f(-0.465, -0.116);
glVertex2f(-0.465, -0.116);
glVertex2f(-0.465, -0.168);
glVertex2f(-0.465, -0.168);
glVertex2f(-0.554, -0.168);
glVertex2f(-0.554, -0.168);
glVertex2f(-0.554, -0.116);

glVertex2f(-0.554, -0.066);//23
glVertex2f(-0.465, -0.066);
glVertex2f(-0.465, -0.066);
glVertex2f(-0.465, -0.116);
glVertex2f(-0.465, -0.116);
glVertex2f(-0.554, -0.116);
glVertex2f(-0.554, -0.116);
glVertex2f(-0.554, -0.066);

glVertex2f(-0.554, -0.012);//24
glVertex2f(-0.465, -0.012);
glVertex2f(-0.465, -0.012);
glVertex2f(-0.465, -0.066);
glVertex2f(-0.465, -0.066);
glVertex2f(-0.554, -0.066);
glVertex2f(-0.554, -0.066);
glVertex2f(-0.554, -0.012);

glVertex2f(-0.554, 0.04);//25
glVertex2f(-0.465, 0.04);
glVertex2f(-0.465, 0.04);
glVertex2f(-0.465, -0.012);
glVertex2f(-0.465, -0.012);
glVertex2f(-0.554, -0.012);
glVertex2f(-0.554, -0.012);
glVertex2f(-0.554, 0.04);

glVertex2f(-0.465, -0.225);//26
glVertex2f(-0.375, -0.225);
glVertex2f(-0.375, -0.225);
glVertex2f(-0.375, -0.275);
glVertex2f(-0.375, -0.275);
glVertex2f(-0.465, -0.275);
glVertex2f(-0.465, -0.275);
glVertex2f(-0.465, -0.225);

glVertex2f(-0.465, -0.18);//27
glVertex2f(-0.375, -0.18);
glVertex2f(-0.375, -0.18);
glVertex2f(-0.375, -0.225);
glVertex2f(-0.375, -0.225);
glVertex2f(-0.465, -0.225);
glVertex2f(-0.465, -0.225);
glVertex2f(-0.465, -0.18);

glVertex2f(-0.465, -0.135);//28
glVertex2f(-0.375, -0.135);
glVertex2f(-0.375, -0.135);
glVertex2f(-0.375, -0.18);
glVertex2f(-0.375, -0.18);
glVertex2f(-0.465, -0.18);
glVertex2f(-0.465, -0.18);
glVertex2f(-0.465, -0.135);

glVertex2f(-0.465, -0.085);//29
glVertex2f(-0.375, -0.085);
glVertex2f(-0.375, -0.085);
glVertex2f(-0.375, -0.135);
glVertex2f(-0.375, -0.135);
glVertex2f(-0.465, -0.135);
glVertex2f(-0.465, -0.135);

glVertex2f(-0.465, -0.025);//30
glVertex2f(-0.375, -0.025);
glVertex2f(-0.375, -0.025);
glVertex2f(-0.375, -0.085);
glVertex2f(-0.375, -0.085);
glVertex2f(-0.465, -0.085);
glVertex2f(-0.465, -0.085);
glVertex2f(-0.465, -0.025);
glEnd();

//box carrier back


glLoadIdentity();

glBegin(GL_QUADS);// TOP HORIZONTAL STAND
glColor3ub(173, 141, 7);
glVertex2f(-0.898, 0.216);
glVertex2f(-0.898, 0.204);
glVertex2f(-0.396, 0.204);
glVertex2f(-0.38, 0.216);
glEnd();
glBegin(GL_QUADS);// top diagonal stand
glColor3ub(173, 141, 7);
glVertex2f(-0.658, 0.38);
glVertex2f(-0.864, 0.216);
glVertex2f(-0.855, 0.216);
glVertex2f(-0.658, 0.372);
glEnd();
glBegin(GL_QUADS);// left stand
glColor3ub(185, 152, 59);
glVertex2f(-0.797, 0.286);
glVertex2f(-0.797, -0.26);
glVertex2f(-0.79, -0.26);
glVertex2f(-0.79, 0.286);
glEnd();
glBegin(GL_QUADS);// right stand
glColor3ub(185, 152, 59);
glVertex2f(-0.655, 0.249);
glVertex2f(-0.655, -0.26);
glVertex2f(-0.648, -0.26);
glVertex2f(-0.648, 0.249);
glEnd();
glBegin(GL_QUADS);//lower brown left
glColor3ub(61, 43, 6);
glVertex2f(-0.797, -0.258);
glVertex2f(-0.797, -0.267);
glVertex2f(-0.79, -0.267);
glVertex2f(-0.79, -0.258);
glEnd();
glBegin(GL_QUADS);//lower brown left
glColor3ub(61, 43, 6);
glVertex2f(-0.8, -0.267);
glVertex2f(-0.8, -0.274);
glVertex2f(-0.787, -0.274);
glVertex2f(-0.787, -0.267);
glEnd();
glBegin(GL_QUADS);//lower brown right
glColor3ub(61, 43, 6);
glVertex2f(-0.655, -0.258);
glVertex2f(-0.655, -0.267);
glVertex2f(-0.648, -0.267);
glVertex2f(-0.648, -0.258);
glEnd();
glBegin(GL_QUADS);//lower brown right
glColor3ub(61, 43, 6);
glVertex2f(-0.657, -0.267);
glVertex2f(-0.657, -0.274);
glVertex2f(-0.645, -0.274);
glVertex2f(-0.645, -0.267);
glEnd();

glBegin(GL_QUADS);// top left stand extension
glColor3ub(185, 152, 59);
glVertex2f(-0.6526, 0.3658);
glVertex2f(-0.6525, 0.24);
glVertex2f(-0.6495, 0.24);
glVertex2f(-0.6495, 0.3658);
glEnd();
glBegin(GL_QUADS);//top left stand extension 2
glColor3ub(185, 152, 59);
glVertex2f(-0.658, 0.398);
glVertex2f(-0.658, 0.3658);
glVertex2f(-0.6435, 0.3658);
glVertex2f(-0.6435, 0.398);
glEnd();

glBegin(GL_QUADS);// back box
glColor3ub(82, 52, 35);
glVertex2f(-0.89, 0.204);
glVertex2f(-0.89, 0.199);
glVertex2f(-0.858, 0.199);
glVertex2f(-0.858, 0.204);
glEnd();
glBegin(GL_QUADS);// back box
glColor3ub(230, 172, 49);
glVertex2f(-0.897, 0.199);
glVertex2f(-0.897, 0.165);
glVertex2f(-0.853, 0.165);
glVertex2f(-0.853, 0.199);
glEnd();
glBegin(GL_QUADS);// red box
glColor3ub(206, 29, 58);
glVertex2f(-0.717, 0.26);
glVertex2f(-0.717, 0.216);
glVertex2f(-0.659, 0.216);
glVertex2f(-0.659, 0.26);
glEnd();
glBegin(GL_QUADS);// red box glass
glColor3ub(62, 59, 59);
glVertex2f(-0.71, 0.252);
glVertex2f(-0.71, 0.242);
glVertex2f(-0.702, 0.242);
glVertex2f(-0.702, 0.252);
glEnd();
glBegin(GL_QUADS);// red box glass
glColor3ub(62, 59, 59);
glVertex2f(-0.698, 0.252);
glVertex2f(-0.698, 0.242);
glVertex2f(-0.69, 0.242);
glVertex2f(-0.69, 0.252);
glEnd();
glBegin(GL_QUADS);// red box glass
glColor3ub(62, 59, 59);
glVertex2f(-0.686, 0.252);
glVertex2f(-0.686, 0.242);
glVertex2f(-0.678, 0.242);
glVertex2f(-0.678, 0.252);
glEnd();
glBegin(GL_QUADS);// red box glass
glColor3ub(62, 59, 59);
glVertex2f(-0.674, 0.252);
glVertex2f(-0.674, 0.242);
glVertex2f(-0.666, 0.242);
glVertex2f(-0.666, 0.252);
glEnd();
glBegin(GL_LINES);// rope
glColor3ub(62, 59, 59);
glVertex2f(-0.6435, 0.376);
glVertex2f(-0.629, 0.358);
glVertex2f(-0.629, 0.358);
glVertex2f(-0.613, 0.338);
glVertex2f(-0.613, 0.338);
glVertex2f(-0.592, 0.317);
glVertex2f(-0.592, 0.317);
glVertex2f(-0.549, 0.281);
glVertex2f(-0.549, 0.281);
glVertex2f(-0.531, 0.267);
glVertex2f(-0.531, 0.267);
glVertex2f(-0.501, 0.246);
glVertex2f(-0.501, 0.246);
glVertex2f(-0.45, 0.216);
glEnd();

glBegin(GL_QUADS);// right box
glColor3ub(70, 44, 11);
glVertex2f(-0.432, 0.204);
glVertex2f(-0.432, 0.196);
glVertex2f(-0.41, 0.196);
glVertex2f(-0.41, 0.204);
glEnd();
glBegin(GL_QUADS);// right box
glColor3ub(173, 141, 7);
glVertex2f(-0.438, 0.196);
glVertex2f(-0.438, 0.191);
glVertex2f(-0.404, 0.191);
glVertex2f(-0.404, 0.196);
glEnd();
glBegin(GL_QUADS);// stand right box
glColor3ub(31, 41, 40);
glVertex2f(-0.438, 0.191);
glVertex2f(-0.438, -0.008);
glVertex2f(-0.434, -0.008);
glVertex2f(-0.434, 0.191);
glEnd();
glBegin(GL_QUADS);// stand right box
glColor3ub(31, 41, 40);
glVertex2f(-0.408, 0.191);
glVertex2f(-0.408, -0.008);
glVertex2f(-0.404, -0.008);
glVertex2f(-0.404, 0.191);
glEnd();
glBegin(GL_QUADS);// yellow box
glColor3ub(230, 172, 49);
glVertex2f(-0.44, -0.008);
glVertex2f(-0.44, -0.0255);
glVertex2f(-0.4, -0.0255);
glVertex2f(-0.4, -0.008);
glEnd();


glBegin(GL_LINES);// left of back crane stairs
glColor3ub(173, 141, 7);
glVertex2f(-0.67, 0.21);
glVertex2f(-0.67, -0.275);
glVertex2f(-0.67, 0.205);
glVertex2f(-0.655, 0.18);
glVertex2f(-0.655, 0.205);
glVertex2f(-0.67, 0.18);
glVertex2f(-0.67, 0.18);
glVertex2f(-0.655, 0.155);
glVertex2f(-0.655, 0.18);
glVertex2f(-0.67, 0.155);
glVertex2f(-0.67, 0.155);
glVertex2f(-0.655, 0.13);
glVertex2f(-0.655, 0.155);
glVertex2f(-0.67, 0.13);
glVertex2f(-0.67, 0.13);
glVertex2f(-0.655, 0.105);
glVertex2f(-0.655, 0.13);
glVertex2f(-0.67, 0.105);
glVertex2f(-0.67, 0.105);
glVertex2f(-0.655, 0.085);
glVertex2f(-0.655, 0.105);
glVertex2f(-0.67, 0.085);
glVertex2f(-0.67, 0.085);
glVertex2f(-0.655, 0.06);
glVertex2f(-0.655, 0.085);
glVertex2f(-0.67, 0.06);
glVertex2f(-0.655, 0.035);
glVertex2f(-0.655, 0.06);
glVertex2f(-0.655, 0.06);
glVertex2f(-0.67, 0.035);
glVertex2f(-0.67, 0.06);
glVertex2f(-0.655, 0.035);
glVertex2f(-0.67, 0.035);
glVertex2f(-0.655, 0.01);
glVertex2f(-0.655, 0.035);
glVertex2f(-0.67, 0.01);
glVertex2f(-0.67, 0.01);
glVertex2f(-0.655, -0.015);
glVertex2f(-0.655, 0.01);
glVertex2f(-0.67, -0.015);
glVertex2f(-0.67, -0.015);
glVertex2f(-0.655, -0.04);
glVertex2f(-0.655, -0.015);
glVertex2f(-0.67, -0.04);
glVertex2f(-0.67, -0.04);
glVertex2f(-0.655, -0.065);
glVertex2f(-0.655, -0.04);
glVertex2f(-0.67, -0.065);
glVertex2f(-0.67, -0.04);
glVertex2f(-0.655, -0.065);
glVertex2f(-0.655, -0.04);
glVertex2f(-0.67, -0.065);
glVertex2f(-0.67, -0.065);
glVertex2f(-0.655, -0.09);
glVertex2f(-0.655, -0.065);
glVertex2f(-0.67, -0.09);
glEnd();

glBegin(GL_LINES);// left of back crane stairs
glColor3ub(173, 141, 7);
glVertex2f(-0.67, -0.09);
glVertex2f(-0.655, -0.115);
glVertex2f(-0.655, -0.09);
glVertex2f(-0.67, -0.115);
glVertex2f(-0.67, -0.115);
glVertex2f(-0.655, -0.14);
glVertex2f(-0.655, -0.115);
glVertex2f(-0.67, -0.14);
glVertex2f(-0.67, -0.14);
glVertex2f(-0.655, -0.165);
glVertex2f(-0.655, -0.14);
glVertex2f(-0.67, -0.165);
glVertex2f(-0.67, -0.165);
glVertex2f(-0.655, -0.19);
glVertex2f(-0.655, -0.165);
glVertex2f(-0.67, -0.19);
glVertex2f(-0.67, -0.19);
glVertex2f(-0.655, -0.215);
glVertex2f(-0.655, -0.19);
glVertex2f(-0.67, -0.215);
glVertex2f(-0.67, -0.215);
glVertex2f(-0.655, -0.24);
glVertex2f(-0.655, -0.215);
glVertex2f(-0.67, -0.24);
glEnd();

glBegin(GL_LINES); //stairs back crane
glColor3ub(173, 141, 7);
glVertex2f(-0.695, 0.205);
glVertex2f(-0.695, -0.275);
glVertex2f(-0.685, -0.275);
glVertex2f(-0.685, 0.205);
glVertex2f(-0.695, 0.2);
glVertex2f(-0.685, 0.2);
glVertex2f(-0.695, 0.18);
glVertex2f(-0.685, 0.18);
glVertex2f(-0.695, 0.18);
glVertex2f(-0.685, 0.18);
glVertex2f(-0.695, 0.16);
glVertex2f(-0.685, 0.16);
glVertex2f(-0.695, 0.14);
glVertex2f(-0.685, 0.14);
glVertex2f(-0.695, 0.12);
glVertex2f(-0.685, 0.12);
glVertex2f(-0.695, 0.1);
glVertex2f(-0.685, 0.1);
glVertex2f(-0.695, 0.08);
glVertex2f(-0.685, 0.08);
glVertex2f(-0.695, 0.06);
glVertex2f(-0.685, 0.06);
glVertex2f(-0.695, 0.04);
glVertex2f(-0.685, 0.04);
glVertex2f(-0.695, 0.02);
glVertex2f(-0.685, 0.02);
glVertex2f(-0.695, 0.0);
glVertex2f(-0.685, 0.0);
glVertex2f(-0.695, -0.02);
glVertex2f(-0.685, -0.02);
glVertex2f(-0.695, -0.04);
glVertex2f(-0.685, -0.04);
glVertex2f(-0.695, -0.06);
glVertex2f(-0.685, -0.06);
glVertex2f(-0.695, -0.08);
glVertex2f(-0.685, -0.08);
glVertex2f(-0.695, -0.1);
glVertex2f(-0.685, -0.1);
glVertex2f(-0.695, -0.12);
glVertex2f(-0.685, -0.12);
glVertex2f(-0.695, -0.14);
glVertex2f(-0.685, -0.14);
glVertex2f(-0.695, -0.16);
glVertex2f(-0.685, -0.16);
glVertex2f(-0.695, -0.18);
glVertex2f(-0.685, -0.18);
glVertex2f(-0.695, -0.2);
glVertex2f(-0.685, -0.2);
glVertex2f(-0.695, -0.22);
glVertex2f(-0.685, -0.22);
glVertex2f(-0.695, -0.24);
glVertex2f(-0.685, -0.24);
glVertex2f(-0.695, -0.26);
glVertex2f(-0.685, -0.26);
glEnd();

glBegin(GL_QUADS);// middle horizontal stand
glColor3ub(164, 129, 3);
glVertex2f(-0.79, 0.044);
glVertex2f(-0.79, 0.028);
glVertex2f(-0.654, 0.028);
glVertex2f(-0.654, 0.044);
glEnd();

glBegin(GL_QUADS);// middle horizontal stand
glColor3ub(164, 129, 3);
glVertex2f(-0.79, -0.12);
glVertex2f(-0.79, -0.14);
glVertex2f(-0.654, -0.14);
glVertex2f(-0.654, -0.12);
glEnd();


glBegin(GL_QUADS);// middle cross top
glColor3ub(164, 129, 3);
glVertex2f(-0.79, 0.155);
glVertex2f(-0.79, 0.145);
glVertex2f(-0.655, 0.067);
glVertex2f(-0.655, 0.075);
glEnd();

glBegin(GL_QUADS);// middle cross top
glColor3ub(164, 129, 3);
glVertex2f(-0.79, 0.074);
glVertex2f(-0.79, 0.064);
glVertex2f(-0.655, 0.145);
glVertex2f(-0.655, 0.153);
glEnd();

glBegin(GL_QUADS);// middle cross down
glColor3ub(164, 129, 3);
glVertex2f(-0.79, 0.00);
glVertex2f(-0.79, -0.01);
glVertex2f(-0.655, -0.0885);
glVertex2f(-0.655, -0.08);
glEnd();

glBegin(GL_QUADS);// middle cross down
glColor3ub(164, 129, 3);
glVertex2f(-0.79, -0.085);
glVertex2f(-0.79, -0.095);
glVertex2f(-0.655, -0.011);
glVertex2f(-0.655, -0.002);
glEnd();

glBegin(GL_QUADS);// middle sea
glColor3ub(29, 131, 179);
glVertex2f(-1, -0.38);
glVertex2f(-1, -0.58);
glVertex2f(1, -0.58);
glVertex2f(1, -0.38);
glEnd();

glBegin(GL_QUADS);//crane shadow
glColor3ub(23, 109, 150);
glVertex2f(-1, -0.38);
glVertex2f(-1, -0.43);
glVertex2f(-0.94, -0.43);
glVertex2f(-0.94, -0.38);
glEnd();

glBegin(GL_QUADS);//crane shadow
glColor3ub(23, 109, 150);
glVertex2f(-0.94, -0.38);
glVertex2f(-0.94, -0.46);
glVertex2f(-0.85, -0.46);
glVertex2f(-0.85, -0.38);
glEnd();

glBegin(GL_QUADS);//crane shadow
glColor3ub(23, 109, 150);
glVertex2f(-0.85, -0.38);
glVertex2f(-0.85, -0.49);
glVertex2f(-0.77, -0.49);
glVertex2f(-0.77, -0.38);
glEnd();

glBegin(GL_QUADS);//crane shadow
glColor3ub(23, 109, 150);
glVertex2f(-0.77, -0.38);
glVertex2f(-0.77, -0.43);
glVertex2f(-0.67, -0.43);
glVertex2f(-0.67, -0.38);
glEnd();

glBegin(GL_QUADS);//crane shadow
glColor3ub(23, 109, 150);
glVertex2f(-0.695, -0.43);
glVertex2f(-0.685, -0.43);
glVertex2f(-0.685, -0.58);
glVertex2f(-0.695, -0.58);
glEnd();

glBegin(GL_QUADS);//crane shadow
glColor3ub(23, 109, 150);
glVertex2f(-0.67, -0.38);
glVertex2f(-0.65, -0.38);
glVertex2f(-0.65, -0.58);
glVertex2f(-0.67, -0.58);
glEnd();

glBegin(GL_QUADS);//crane shadow
glColor3ub(23, 109, 150);
glVertex2f(-0.795, -0.49);
glVertex2f(-0.79, -0.49);
glVertex2f(-0.79, -0.58);
glVertex2f(-0.795, -0.58);
glEnd();

glBegin(GL_QUADS);//crane shadow
glColor3ub(23, 109, 150);
glVertex2f(-0.79, -0.52);
glVertex2f(-0.79, -0.53);
glVertex2f(-0.67, -0.53);
glVertex2f(-0.67, -0.52);
glEnd();


glBegin(GL_QUADS);//crane shadow
glColor3ub(23, 109, 150);
glVertex2f(-0.77, -0.44);
glVertex2f(-0.77, -0.445);
glVertex2f(-0.67, -0.485);
glVertex2f(-0.67, -0.48);
glEnd();

glBegin(GL_QUADS);//crane shadow
glColor3ub(23, 109, 150);
glVertex2f(-0.77, -0.48);
glVertex2f(-0.77, -0.485);
glVertex2f(-0.67, -0.455);
glVertex2f(-0.67, -0.45);
glEnd();

glBegin(GL_QUADS);//crane shadow
glColor3ub(23, 109, 150);
glVertex2f(-0.64, -0.38);
glVertex2f(-0.64, -0.44);
glVertex2f(-0.55, -0.44);
glVertex2f(-0.55, -0.38);
glEnd();

glBegin(GL_QUADS);//crane shadow
glColor3ub(23, 109, 150);
glVertex2f(-0.55, -0.38);
glVertex2f(-0.55, -0.47);
glVertex2f(-0.46, -0.47);
glVertex2f(-0.46, -0.38);
glEnd();

glBegin(GL_QUADS);//crane shadow
glColor3ub(23, 109, 150);
glVertex2f(-0.46, -0.38);
glVertex2f(-0.46, -0.44);
glVertex2f(-0.38, -0.44);
glVertex2f(-0.38, -0.38);
glEnd();


//Ship Front START
glBegin(GL_QUADS);//steel behind railing
glColor3ub(170, 171, 166);
glVertex2f(-0.32, -0.47);
glVertex2f(-0.32, -0.49);
glVertex2f(0.08, -0.49);
glVertex2f(0.08, -0.47);
glEnd();

//ship cargo start

glBegin(GL_QUADS);//down row left to right
glColor3ub(136, 83, 173);
glVertex2f(-0.34, -0.4);
glVertex2f(-0.34, -0.47);
glVertex2f(-0.25, -0.47);
glVertex2f(-0.25, -0.4);
glEnd();

glBegin(GL_QUADS);//down raw left to right
glColor3ub(52, 182, 86);
glVertex2f(-0.25, -0.4);
glVertex2f(-0.16, -0.4);
glVertex2f(-0.16, -0.47);
glVertex2f(-0.25, -0.47);
glEnd();

glBegin(GL_QUADS);//down raw left to right
glColor3ub(185, 105, 44);
glVertex2f(-0.16, -0.4);
glVertex2f(-0.07, -0.4);
glVertex2f(-0.07, -0.47);
glVertex2f(-0.16, -0.47);
glEnd();

glBegin(GL_QUADS);//down raw left to right
glColor3ub(220, 75, 158);
glVertex2f(-0.07, -0.4);
glVertex2f(0.01, -0.4);
glVertex2f(0.01, -0.47);
glVertex2f(-0.07, -0.47);
glEnd();

glBegin(GL_QUADS);//down raw left to right
glColor3ub(234, 218, 52);
glVertex2f(0.01, -0.4);
glVertex2f(0.1, -0.4);
glVertex2f(0.1, -0.47);
glVertex2f(0.01, -0.47);
glEnd();

glBegin(GL_QUADS);//down raw left to right
glColor3ub(50, 202, 94);
glVertex2f(0.1, -0.4);
glVertex2f(0.19, -0.4);
glVertex2f(0.19, -0.47);
glVertex2f(0.1, -0.47);
glEnd();

glBegin(GL_QUADS);//middle raw left to right
glColor3ub(82, 217, 214);
glVertex2f(-0.34, -0.34);
glVertex2f(-0.25, -0.34);
glVertex2f(-0.25, -0.4);
glVertex2f(-0.34, -0.4);
glEnd();

glBegin(GL_QUADS);//middle raw left to right
glColor3ub(215, 209, 63);
glVertex2f(-0.25, -0.34);
glVertex2f(-0.16, -0.34);
glVertex2f(-0.16, -0.4);
glVertex2f(-0.25, -0.4);
glEnd();

glBegin(GL_QUADS);//middle raw left to right
glColor3ub(182, 48, 52);
glVertex2f(-0.16, -0.34);
glVertex2f(-0.07, -0.34);
glVertex2f(-0.07, -0.4);
glVertex2f(-0.16, -0.4);
glEnd();

glBegin(GL_QUADS);//middle raw left to right
glColor3ub(75, 104, 148);
glVertex2f(-0.07, -0.34);
glVertex2f(0.01, -0.34);
glVertex2f(0.01, -0.4);
glVertex2f(-0.07, -0.4);
glEnd();

glBegin(GL_QUADS);//middle raw left to right
glColor3ub(198, 35, 38);
glVertex2f(0.01, -0.34);
glVertex2f(0.1, -0.34);
glVertex2f(0.1, -0.4);
glVertex2f(0.01, -0.4);
glEnd();

glBegin(GL_QUADS);//middle raw left to right
glColor3ub(206, 196, 30);
glVertex2f(0.1, -0.34);
glVertex2f(0.19, -0.34);
glVertex2f(0.19, -0.4);
glVertex2f(0.1, -0.4);
glEnd();

glBegin(GL_QUADS);//middle raw left to right
glColor3ub(29, 33, 168);
glVertex2f(-0.34, -0.27);
glVertex2f(-0.25, -0.27);
glVertex2f(-0.25, -0.34);
glVertex2f(-0.34, -0.34);
glEnd();

glBegin(GL_QUADS);//middle raw left to right
glColor3ub(29, 169, 161);
glVertex2f(-0.25, -0.27);
glVertex2f(-0.16, -0.27);
glVertex2f(-0.16, -0.34);
glVertex2f(-0.25, -0.34);
glEnd();

glBegin(GL_QUADS);//middle row left to right
glColor3ub(154, 100, 188);
glVertex2f(-0.16, -0.27);
glVertex2f(-0.07, -0.27);
glVertex2f(-0.07, -0.34);
glVertex2f(-0.16, -0.34);
glEnd();

glBegin(GL_QUADS);//middle row left to right
glColor3ub(211, 160, 69);
glVertex2f(-0.07, -0.27);
glVertex2f(0.01, -0.27);
glVertex2f(0.01, -0.34);
glVertex2f(-0.07, -0.34);
glEnd();

glBegin(GL_QUADS);//middle row left to right
glColor3ub(132, 91, 158);
glVertex2f(0.01, -0.27);
glVertex2f(0.1, -0.27);
glVertex2f(0.1, -0.34);
glVertex2f(0.01, -0.34);
glEnd();

glBegin(GL_QUADS);//middle row left to right
glColor3ub(40, 45, 176);
glVertex2f(0.19, -0.27);
glVertex2f(0.28, -0.27);
glVertex2f(0.28, -0.34);
glVertex2f(0.19, -0.34);
glEnd();

glBegin(GL_QUADS);//middle row left to right
glColor3ub(155, 163, 94);
glVertex2f(0.1, -0.27);
glVertex2f(0.19, -0.27);
glVertex2f(0.19, -0.34);
glVertex2f(0.1, -0.34);
glEnd();

glBegin(GL_LINES);//down row left
glColor3ub(64, 64, 64);
glVertex2f(-0.34, -0.4);//1
glVertex2f(-0.34, -0.47);
glVertex2f(-0.34, -0.47);
glVertex2f(-0.25, -0.47);
glVertex2f(-0.25, -0.47);
glVertex2f(-0.25, -0.4);
glVertex2f(-0.25, -0.4);
glVertex2f(-0.34, -0.4);

glVertex2f(-0.25, -0.4);//2
glVertex2f(-0.16, -0.4);
glVertex2f(-0.16, -0.4);
glVertex2f(-0.16, -0.47);
glVertex2f(-0.16, -0.47);
glVertex2f(-0.25, -0.47);
glVertex2f(-0.25, -0.47);
glVertex2f(-0.25, -0.4);

glVertex2f(-0.16, -0.4);//3
glVertex2f(-0.07, -0.4);
glVertex2f(-0.07, -0.4);
glVertex2f(-0.07, -0.47);
glVertex2f(-0.07, -0.47);
glVertex2f(-0.16, -0.47);
glVertex2f(-0.16, -0.47);
glVertex2f(-0.16, -0.4);

glVertex2f(-0.07, -0.4);//4
glVertex2f(0.01, -0.4);
glVertex2f(0.01, -0.4);
glVertex2f(0.01, -0.47);
glVertex2f(0.01, -0.47);
glVertex2f(-0.07, -0.47);
glVertex2f(-0.07, -0.47);
glVertex2f(-0.07, -0.4);

glVertex2f(0.01, -0.4);//5
glVertex2f(0.1, -0.4);
glVertex2f(0.1, -0.4);
glVertex2f(0.1, -0.47);
glVertex2f(0.1, -0.47);
glVertex2f(0.01, -0.47);
glVertex2f(0.01, -0.47);
glVertex2f(0.01, -0.4);

glVertex2f(0.1, -0.4);//6
glVertex2f(0.19, -0.4);
glVertex2f(0.19, -0.4);
glVertex2f(0.19, -0.47);
glVertex2f(0.19, -0.47);
glVertex2f(0.1, -0.47);
glVertex2f(0.1, -0.47);
glVertex2f(0.1, -0.4);

glVertex2f(-0.34, -0.34);//7
glVertex2f(-0.25, -0.34);
glVertex2f(-0.25, -0.34);
glVertex2f(-0.25, -0.4);
glVertex2f(-0.25, -0.4);
glVertex2f(-0.34, -0.4);
glVertex2f(-0.34, -0.4);
glVertex2f(-0.34, -0.34);

glVertex2f(-0.25, -0.34);//8
glVertex2f(-0.16, -0.34);
glVertex2f(-0.16, -0.34);
glVertex2f(-0.16, -0.4);
glVertex2f(-0.16, -0.4);
glVertex2f(-0.25, -0.4);
glVertex2f(-0.25, -0.4);
glVertex2f(-0.25, -0.34);

glVertex2f(-0.16, -0.34);//7
glVertex2f(-0.07, -0.34);
glVertex2f(-0.07, -0.34);
glVertex2f(-0.07, -0.4);
glVertex2f(-0.07, -0.4);
glVertex2f(-0.16, -0.4);
glVertex2f(-0.16, -0.4);
glVertex2f(-0.16, -0.34);

glVertex2f(-0.07, -0.34);//8
glVertex2f(0.01, -0.34);
glVertex2f(0.01, -0.34);
glVertex2f(0.01, -0.4);
glVertex2f(0.01, -0.4);
glVertex2f(-0.07, -0.4);
glVertex2f(-0.07, -0.4);
glVertex2f(-0.07, -0.34);

glVertex2f(0.01, -0.34);//9
glVertex2f(0.1, -0.34);
glVertex2f(0.1, -0.34);
glVertex2f(0.1, -0.4);
glVertex2f(0.1, -0.4);
glVertex2f(0.01, -0.4);
glVertex2f(0.01, -0.4);
glVertex2f(0.01, -0.34);

glVertex2f(0.1, -0.34);//10
glVertex2f(0.19, -0.34);
glVertex2f(0.19, -0.34);
glVertex2f(0.19, -0.4);
glVertex2f(0.19, -0.4);
glVertex2f(0.1, -0.4);
glVertex2f(0.1, -0.4);
glVertex2f(0.1, -0.34);

glVertex2f(-0.34, -0.27);//11
glVertex2f(-0.25, -0.27);
glVertex2f(-0.25, -0.27);
glVertex2f(-0.25, -0.34);
glVertex2f(-0.25, -0.34);
glVertex2f(-0.34, -0.34);
glVertex2f(-0.34, -0.34);
glVertex2f(-0.34, -0.27);

glVertex2f(-0.25, -0.27);//12
glVertex2f(-0.16, -0.27);
glVertex2f(-0.16, -0.27);
glVertex2f(-0.16, -0.34);
glVertex2f(-0.16, -0.34);
glVertex2f(-0.25, -0.34);
glVertex2f(-0.25, -0.34);
glVertex2f(-0.25, -0.27);

glVertex2f(-0.16, -0.27);//13
glVertex2f(-0.07, -0.27);
glVertex2f(-0.07, -0.27);
glVertex2f(-0.07, -0.34);
glVertex2f(-0.07, -0.34);
glVertex2f(-0.16, -0.34);
glVertex2f(-0.16, -0.34);
glVertex2f(-0.16, -0.27);

glVertex2f(-0.07, -0.27);//14
glVertex2f(0.01, -0.27);
glVertex2f(0.01, -0.27);
glVertex2f(0.01, -0.34);
glVertex2f(0.01, -0.34);
glVertex2f(-0.07, -0.34);
glVertex2f(-0.07, -0.34);
glVertex2f(-0.07, -0.27);

glVertex2f(0.01, -0.27);//15
glVertex2f(0.1, -0.27);
glVertex2f(0.1, -0.27);
glVertex2f(0.1, -0.34);
glVertex2f(0.1, -0.34);
glVertex2f(0.01, -0.34);
glVertex2f(0.01, -0.34);
glVertex2f(0.01, -0.27);

glVertex2f(0.19, -0.27);//16
glVertex2f(0.28, -0.27);
glVertex2f(0.28, -0.27);
glVertex2f(0.28, -0.34);
glVertex2f(0.28, -0.34);
glVertex2f(0.19, -0.34);
glVertex2f(0.19, -0.34);
glVertex2f(0.19, -0.27);


glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.335, -0.44);
glVertex2f(-0.33, -0.445);
glVertex2f(-0.33, -0.465);
glVertex2f(-0.335, -0.465);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.335, -0.44);
glVertex2f(-0.33, -0.445);
glVertex2f(0.095, -0.445);
glVertex2f(0.1, -0.44);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(0.07, -0.445);
glVertex2f(0.07, -0.48);
glVertex2f(0.075, -0.48);
glVertex2f(0.075, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(0.035, -0.445);
glVertex2f(0.035, -0.48);
glVertex2f(0.04, -0.48);
glVertex2f(0.04, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(0.005, -0.445);
glVertex2f(0.005, -0.48);
glVertex2f(0.01, -0.48);
glVertex2f(0.01, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.025, -0.445);
glVertex2f(-0.025, -0.48);
glVertex2f(-0.02, -0.48);
glVertex2f(-0.02, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.055, -0.445);
glVertex2f(-0.055, -0.48);
glVertex2f(-0.05, -0.48);
glVertex2f(-0.05, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.085, -0.445);
glVertex2f(-0.085, -0.48);
glVertex2f(-0.08, -0.48);
glVertex2f(-0.08, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.115, -0.445);
glVertex2f(-0.115, -0.48);
glVertex2f(-0.11, -0.48);
glVertex2f(-0.11, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.145, -0.445);
glVertex2f(-0.145, -0.48);
glVertex2f(-0.14, -0.48);
glVertex2f(-0.14, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.18, -0.445);
glVertex2f(-0.18, -0.48);
glVertex2f(-0.175, -0.48);
glVertex2f(-0.175, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.21, -0.445);
glVertex2f(-0.21, -0.48);
glVertex2f(-0.205, -0.48);
glVertex2f(-0.205, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.24, -0.445);
glVertex2f(-0.24, -0.48);
glVertex2f(-0.235, -0.48);
glVertex2f(-0.235, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.27, -0.445);
glVertex2f(-0.27, -0.48);
glVertex2f(-0.265, -0.48);
glVertex2f(-0.265, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.305, -0.445);
glVertex2f(-0.305, -0.48);
glVertex2f(-0.3, -0.48);
glVertex2f(-0.3, -0.445);
glEnd();

glBegin(GL_QUADS);//cabin left
glColor3ub(211, 211, 207);
glVertex2f(-0.46, -0.27);
glVertex2f(-0.46, -0.46);
glVertex2f(-0.38, -0.46);
glVertex2f(-0.38, -0.27);
glEnd();

glBegin(GL_QUADS);//cabin middle
glColor3ub(204, 204, 204);
glVertex2f(-0.5, -0.27);
glVertex2f(-0.5, -0.46);
glVertex2f(-0.46, -0.46);
glVertex2f(-0.46, -0.27);
glEnd();

glBegin(GL_QUADS);//cabin right
glColor3ub(198, 198, 198);
glVertex2f(-0.58, -0.27);
glVertex2f(-0.58, -0.46);
glVertex2f(-0.5, -0.46);
glVertex2f(-0.5, -0.27);
glEnd();


glBegin(GL_QUADS);//cabin glass left
glColor3ub(77, 175, 231);
glVertex2f(-0.46, -0.246);
glVertex2f(-0.46, -0.27);
glVertex2f(-0.386, -0.27);
glVertex2f(-0.386, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin glass middle
glColor3ub(73, 158, 202);
glVertex2f(-0.5, -0.246);
glVertex2f(-0.5, -0.27);
glVertex2f(-0.46, -0.27);
glVertex2f(-0.46, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin glass right
glColor3ub(37, 145, 198);
glVertex2f(-0.572, -0.246);
glVertex2f(-0.572, -0.27);
glVertex2f(-0.5, -0.27);
glVertex2f(-0.5, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin glass railing left
glColor3ub(150, 150, 150);
glVertex2f(-0.556, -0.246);
glVertex2f(-0.556, -0.27);
glVertex2f(-0.554, -0.27);
glVertex2f(-0.554, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin glass railing left
glColor3ub(150, 150, 150);
glVertex2f(-0.536, -0.246);
glVertex2f(-0.536, -0.27);
glVertex2f(-0.534, -0.27);
glVertex2f(-0.534, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin glass railing middle
glColor3ub(160, 160, 154);
glVertex2f(-0.494, -0.246);
glVertex2f(-0.494, -0.27);
glVertex2f(-0.492, -0.27);
glVertex2f(-0.492, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin glass railing middle
glColor3ub(160, 160, 154);
glVertex2f(-0.468, -0.246);
glVertex2f(-0.468, -0.27);
glVertex2f(-0.466, -0.27);
glVertex2f(-0.466, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin glass railing right
glColor3ub(182, 181, 188);
glVertex2f(-0.424, -0.246);
glVertex2f(-0.424, -0.27);
glVertex2f(-0.422, -0.27);
glVertex2f(-0.422, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin glass railing right
glColor3ub(182, 181, 188);
glVertex2f(-0.404, -0.246);
glVertex2f(-0.404, -0.27);
glVertex2f(-0.402, -0.27);
glVertex2f(-0.402, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin left
glColor3ub(211, 211, 207);
glVertex2f(-0.46, -0.2);
glVertex2f(-0.365, -0.2);
glVertex2f(-0.372, -0.246);
glVertex2f(-0.46, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin middle
glColor3ub(204, 204, 204);
glVertex2f(-0.5, -0.2);
glVertex2f(-0.46, -0.2);
glVertex2f(-0.46, -0.246);
glVertex2f(-0.5, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin right
glColor3ub(198, 198, 198);
glVertex2f(-0.59, -0.2);
glVertex2f(-0.582, -0.246);
glVertex2f(-0.5, -0.246);
glVertex2f(-0.5, -0.2);
glEnd();


glBegin(GL_QUADS);//cabin middle left
glColor3ub(174, 172, 174);
glVertex2f(-0.46, -0.165);
glVertex2f(-0.405, -0.165);
glVertex2f(-0.405, -0.2);
glVertex2f(-0.46, -0.2);
glEnd();

glBegin(GL_QUADS);//cabin middle middle
glColor3ub(142, 144, 145);
glVertex2f(-0.5, -0.165);
glVertex2f(-0.46, -0.165);
glVertex2f(-0.46, -0.2);
glVertex2f(-0.5, -0.2);
glEnd();

glBegin(GL_QUADS);//cabin middle  right
glColor3ub(127, 129, 130);
glVertex2f(-0.55, -0.165);
glVertex2f(-0.5, -0.165);
glVertex2f(-0.5, -0.2);
glVertex2f(-0.55, -0.2);
glEnd();


glBegin(GL_QUADS);//cabin middle top left
glColor3ub(185, 180, 181);
glVertex2f(-0.46, -0.095);
glVertex2f(-0.388, -0.095);
glVertex2f(-0.402, -0.165);
glVertex2f(-0.46, -0.165);
glEnd();

glBegin(GL_QUADS);//cabin middle top middle
glColor3ub(163, 163, 161);
glVertex2f(-0.5, -0.095);
glVertex2f(-0.46, -0.095);
glVertex2f(-0.46, -0.165);
glVertex2f(-0.5, -0.165);
glEnd();

glBegin(GL_QUADS);//cabin middle top  right
glColor3ub(153, 151, 149);
glVertex2f(-0.565, -0.095);
glVertex2f(-0.5, -0.095);
glVertex2f(-0.5, -0.165);
glVertex2f(-0.555, -0.165);
glEnd();

glBegin(GL_QUADS);//cabin middle top top left
glColor3ub(188, 184, 185);
glVertex2f(-0.46, -0.08);
glVertex2f(-0.46, -0.095);
glVertex2f(-0.384, -0.095);
glVertex2f(-0.39, -0.08);
glEnd();

glBegin(GL_QUADS);//cabin middle top top middle
glColor3ub(163, 163, 161);
glVertex2f(-0.5, -0.08);
glVertex2f(-0.46, -0.08);
glVertex2f(-0.46, -0.095);
glVertex2f(-0.5, -0.095);
glEnd();

glBegin(GL_QUADS);//cabin middle top top  right
glColor3ub(153, 151, 149);
glVertex2f(-0.565, -0.08);
glVertex2f(-0.5, -0.08);
glVertex2f(-0.5, -0.095);
glVertex2f(-0.57, -0.095);
glEnd();

glBegin(GL_LINES);//cabin middle top top  right
glColor3ub(124, 121, 119);
glVertex2f(-0.565, -0.08);
glVertex2f(-0.39, -0.08);
glVertex2f(-0.39, -0.08);
glVertex2f(-0.384, -0.095);
glVertex2f(-0.384, -0.095);
glVertex2f(-0.57, -0.095);
glVertex2f(-0.57, -0.095);
glVertex2f(-0.565, -0.08);
glEnd();

glBegin(GL_QUADS);//cabin middle top top left
glColor3ub(183, 183, 183);
glVertex2f(-0.46, -0.055);
glVertex2f(-0.395, -0.055);
glVertex2f(-0.39, -0.08);
glVertex2f(-0.46, -0.08);
glEnd();

glBegin(GL_QUADS);//cabin middle top top middle
glColor3ub(163, 161, 161);
glVertex2f(-0.5, -0.055);
glVertex2f(-0.46, -0.055);
glVertex2f(-0.46, -0.08);
glVertex2f(-0.5, -0.08);
glEnd();

glBegin(GL_QUADS);//cabin middle top top  right
glColor3ub(155, 155, 152);
glVertex2f(-0.56, -0.055);
glVertex2f(-0.565, -0.08);
glVertex2f(-0.5, -0.08);
glVertex2f(-0.5, -0.055);
glEnd();

glBegin(GL_LINES);//cabin middle top top  right
glColor3ub(124, 121, 119);
glVertex2f(-0.565, -0.08);
glVertex2f(-0.39, -0.08);
glVertex2f(-0.39, -0.08);
glVertex2f(-0.384, -0.095);
glVertex2f(-0.384, -0.095);
glVertex2f(-0.57, -0.095);
glVertex2f(-0.57, -0.095);
glVertex2f(-0.565, -0.08);
glEnd();


glBegin(GL_QUADS);//cabin middle glass left
glColor3ub(77, 175, 231);
glVertex2f(-0.46, -0.1);
glVertex2f(-0.44, -0.1);
glVertex2f(-0.45, -0.16);
glVertex2f(-0.46, -0.16);
glEnd();
glBegin(GL_QUADS);//cabin middle glass left
glColor3ub(77, 175, 231);
glVertex2f(-0.435, -0.1);
glVertex2f(-0.395, -0.1);
glVertex2f(-0.408, -0.16);
glVertex2f(-0.445, -0.16);
glEnd();

glBegin(GL_QUADS);//cabin middle glass middle
glColor3ub(73, 158, 202);
glVertex2f(-0.5, -0.1);
glVertex2f(-0.46, -0.1);
glVertex2f(-0.46, -0.16);
glVertex2f(-0.5, -0.16);
glEnd();

glBegin(GL_QUADS);//cabin middle glass right
glColor3ub(37, 145, 198);
glVertex2f(-0.56, -0.1);
glVertex2f(-0.52, -0.1);
glVertex2f(-0.51, -0.16);
glVertex2f(-0.55, -0.16);
glEnd();
glBegin(GL_QUADS);//cabin middle glass right
glColor3ub(37, 145, 198);
glVertex2f(-0.515, -0.1);
glVertex2f(-0.5, -0.1);
glVertex2f(-0.5, -0.16);
glVertex2f(-0.505, -0.16);
glEnd();


glBegin(GL_LINES);//cabin railing right
glColor3ub(198, 198, 198);
glVertex2f(-0.59, -0.175);
glVertex2f(-0.5, -0.175);
glVertex2f(-0.5, -0.175);
glVertex2f(-0.5, -0.2);
glVertex2f(-0.5, -0.2);
glVertex2f(-0.59, -0.2);
glVertex2f(-0.59, -0.2);
glVertex2f(-0.59, -0.175);

glVertex2f(-0.58, -0.175);
glVertex2f(-0.58, -0.2);
glVertex2f(-0.56, -0.175);
glVertex2f(-0.56, -0.2);
glVertex2f(-0.54, -0.175);
glVertex2f(-0.54, -0.2);
glVertex2f(-0.52, -0.175);
glVertex2f(-0.52, -0.2);

glBegin(GL_LINES);//cabin railing middle
glColor3ub(204, 204, 204);
glVertex2f(-0.5, -0.175);
glVertex2f(-0.46, -0.175);
glVertex2f(-0.46, -0.175);
glVertex2f(-0.46, -0.2);
glVertex2f(-0.46, -0.2);
glVertex2f(-0.5, -0.2);
glVertex2f(-0.5, -0.2);
glVertex2f(-0.5, -0.175);
glVertex2f(-0.48, -0.175);
glVertex2f(-0.48, -0.2);
glEnd();

glBegin(GL_LINES);//cabin left
glColor3ub(211, 211, 207);
glVertex2f(-0.46, -0.175);
glVertex2f(-0.365, -0.175);
glVertex2f(-0.365, -0.175);
glVertex2f(-0.365, -0.2);
glVertex2f(-0.365, -0.2);
glVertex2f(-0.46, -0.2);
glVertex2f(-0.46, -0.2);
glVertex2f(-0.46, -0.175);

glVertex2f(-0.44, -0.175);
glVertex2f(-0.44, -0.2);
glVertex2f(-0.42, -0.175);
glVertex2f(-0.42, -0.2);
glVertex2f(-0.4, -0.175);
glVertex2f(-0.4, -0.2);
glVertex2f(-0.38, -0.175);
glVertex2f(-0.38, -0.2);
glEnd();

glBegin(GL_QUADS);//pole
glColor3ub(255, 255, 255);
glVertex2f(-0.54, 0.04);
glVertex2f(-0.535, 0.04);
glVertex2f(-0.535, -0.055);
glVertex2f(-0.54, -0.055);
glEnd();

glBegin(GL_QUADS);//pole red line
glColor3ub(216, 54, 45);
glVertex2f(-0.54, 0.025);
glVertex2f(-0.535, 0.025);
glVertex2f(-0.535, 0.01);
glVertex2f(-0.54, 0.01);
glEnd();

glBegin(GL_QUADS);//pole red line
glColor3ub(216, 54, 45);
glVertex2f(-0.54, -0.005);
glVertex2f(-0.535, -0.005);
glVertex2f(-0.535, -0.02);
glVertex2f(-0.54, -0.02);
glEnd();

glBegin(GL_QUADS);//pole
glColor3ub(255, 255, 255);
glVertex2f(-0.525, 0.005);
glVertex2f(-0.52, 0.005);
glVertex2f(-0.52, -0.055);
glVertex2f(-0.525, -0.055);
glEnd();

glBegin(GL_QUADS);//pole red line
glColor3ub(216, 54, 45);
glVertex2f(-0.525, -0.005);
glVertex2f(-0.52, -0.005);
glVertex2f(-0.52, -0.02);
glVertex2f(-0.525, -0.02);
glEnd();

glBegin(GL_QUADS);//pole red line
glColor3ub(216, 54, 45);
glVertex2f(-0.525, -0.035);
glVertex2f(-0.52, -0.035);
glVertex2f(-0.52, -0.05);
glVertex2f(-0.525, -0.05);
glEnd();

glBegin(GL_QUADS);//pole
glColor3ub(255, 255, 255);
glVertex2f(-0.415, 0.005);
glVertex2f(-0.41, 0.005);
glVertex2f(-0.41, -0.055);
glVertex2f(-0.415, -0.055);
glEnd();

glBegin(GL_QUADS);//pole red line
glColor3ub(216, 54, 45);
glVertex2f(-0.415, -0.005);
glVertex2f(-0.41, -0.005);
glVertex2f(-0.41, -0.015);
glVertex2f(-0.415, -0.015);
glEnd();
glBegin(GL_QUADS);//pole red line
glColor3ub(216, 54, 45);
glVertex2f(-0.415, -0.025);
glVertex2f(-0.41, -0.025);
glVertex2f(-0.41, -0.035);
glVertex2f(-0.415, -0.035);
glEnd();

glBegin(GL_QUADS);//pole
glColor3ub(155, 157, 151);
glVertex2f(-0.48, 0.07);
glVertex2f(-0.475, 0.07);
glVertex2f(-0.475, -0.055);
glVertex2f(-0.48, -0.055);
glEnd();

glBegin(GL_QUADS);//pole
glColor3ub(147, 147, 144);
glVertex2f(-0.48, 0.07);
glVertex2f(-0.475, 0.07);
glVertex2f(-0.475, 0.07);
glVertex2f(-0.475, -0.055);
glVertex2f(-0.475, -0.055);
glVertex2f(-0.48, -0.055);
glVertex2f(-0.48, -0.055);
glVertex2f(-0.48, 0.07);

glEnd();

glBegin(GL_POLYGON);//flag
glColor3ub(27, 138, 57);
glVertex2f(-0.48, 0.065);
glVertex2f(-0.486, -0.011);
glVertex2f(-0.482, -0.002);
glVertex2f(-0.481, -0.008);
glVertex2f(-0.478, -0.002);
glVertex2f(-0.479, 0.049);
glEnd();

glBegin(GL_LINES);//flag
glColor3ub(23, 119, 49);
glVertex2f(-0.48, 0.065);
glVertex2f(-0.486, -0.011);
glVertex2f(-0.486, -0.011);
glVertex2f(-0.482, -0.002);
glVertex2f(-0.482, -0.002);
glVertex2f(-0.481, -0.008);
glVertex2f(-0.481, -0.008);
glVertex2f(-0.478, -0.002);
glVertex2f(-0.478, -0.002);
glVertex2f(-0.479, 0.049);
glVertex2f(-0.479, 0.049);
glVertex2f(-0.48, 0.065);
glEnd();

glBegin(GL_POLYGON);//flag circle
glColor3ub(214, 32, 38);
glVertex2f(-0.481, 0.036);
glVertex2f(-0.482, 0.014);
glVertex2f(-0.48, 0.018);
glVertex2f(-0.479, 0.015);
glVertex2f(-0.4805, 0.033);
glEnd();


	   GLfloat x4=-.52f; GLfloat y4=-.35f; GLfloat radius4 =0.012f;
	int triangleAmount4 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi4 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(37, 145, 198); //left window
		glVertex2f(x4, y4); // center of circle
		for(i = 0; i <= triangleAmount4;i++) {
			glVertex2f(
		            x4 + (radius4 * cos(i *  twicePi4 / triangleAmount4)),
			    y4 + (radius4 * sin(i * twicePi4 / triangleAmount4))
			);
		}
	glEnd();


		   GLfloat x5=-.52f; GLfloat y5=-.39f; GLfloat radius5 =0.012f;
	int triangleAmount5 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi5 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(37, 145, 198); // left window
		glVertex2f(x5, y5); // center of circle
		for(i = 0; i <= triangleAmount5;i++) {
			glVertex2f(
		            x5 + (radius5* cos(i *  twicePi5 / triangleAmount5)),
			    y5 + (radius5* sin(i * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


	GLfloat x6=-.48f; GLfloat y6=-.35f; GLfloat radius6 =0.012f;
	int triangleAmount6 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi6 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(73, 158, 202); // middle window
		glVertex2f(x6, y6); // center of circle
		for(i = 0; i <= triangleAmount6;i++) {
			glVertex2f(
		            x6 + (radius6* cos(i *  twicePi6 / triangleAmount6)),
			    y6 + (radius6* sin(i * twicePi6 / triangleAmount6))
			);
		}
	glEnd();


	GLfloat x7=-.48f; GLfloat y7=-.39f; GLfloat radius7 =0.012f;
	int triangleAmount7 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi7 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(73, 158, 202); // middle window
		glVertex2f(x7, y7); // center of circle
		for(i = 0; i <= triangleAmount7;i++) {
			glVertex2f(
		            x7 + (radius7* cos(i *  twicePi7 / triangleAmount7)),
			    y7 + (radius7* sin(i * twicePi7 / triangleAmount7))
			);
		}
	glEnd();


	GLfloat x8=-.48f; GLfloat y8=-.43f; GLfloat radius8 =0.012f;
	int triangleAmount8 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi8 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(73, 158, 202); // middle window
		glVertex2f(x8, y8); // center of circle
		for(i = 0; i <= triangleAmount8;i++) {
			glVertex2f(
		            x8 + (radius8* cos(i *  twicePi8 / triangleAmount8)),
			    y8 + (radius8* sin(i * twicePi8 / triangleAmount8))
			);
		}
	glEnd();


GLfloat x9=-0.44f; GLfloat y9=-0.35f; GLfloat radius9 =0.012f;
	int triangleAmount9 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi9 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 175, 231);
		glVertex2f(x9, y9); // center of circle
		for(i = 0; i <= triangleAmount9;i++) {
			glVertex2f(
		            x9 + (radius9 * cos(i *  twicePi9 / triangleAmount9)),
			    y9 + (radius9 * sin(i * twicePi9 / triangleAmount9))
			);
		}
	glEnd();


		GLfloat x10=-0.44f; GLfloat y10=-0.39f; GLfloat radius10 =0.012f;
	int triangleAmount10 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi10 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 175, 231);
		glVertex2f(x10, y10); // center of circle
		for(i = 0; i <= triangleAmount10;i++) {
			glVertex2f(
		            x10 + (radius10 * cos(i *  twicePi10 / triangleAmount10)),
			    y10 + (radius10 * sin(i * twicePi10 / triangleAmount10))
			);
		}
	glEnd();


	GLfloat x11=-0.44f; GLfloat y11=-0.43f; GLfloat radius11 =0.012f;
	int triangleAmount11 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi11 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 175, 231);
		glVertex2f(x11, y11); // center of circle
		for(i = 0; i <= triangleAmount11;i++) {
			glVertex2f(
		            x11 + (radius11 * cos(i *  twicePi11 / triangleAmount11)),
			    y11 + (radius11 * sin(i * twicePi11 / triangleAmount11))
			);
		}
	glEnd();


	GLfloat x12=-0.4f; GLfloat y12=-0.35f; GLfloat radius12 =0.012f;
	int triangleAmount12 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi12 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 175, 231);
		glVertex2f(x12, y12); // center of circle
		for(i = 0; i <= triangleAmount12;i++) {
			glVertex2f(
		            x12 + (radius12* cos(i *  twicePi12 / triangleAmount12)),
			    y12 + (radius12 * sin(i * twicePi12 / triangleAmount12))
			);
		}
	glEnd();

	GLfloat x13=-0.4f; GLfloat y13=-0.39f; GLfloat radius13 =0.012f;
	int triangleAmount13 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi13 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 175, 231);
		glVertex2f(x13, y13); // center of circle
		for(i = 0; i <= triangleAmount13;i++) {
			glVertex2f(
		            x13 + (radius13* cos(i *  twicePi13 / triangleAmount13)),
			    y13 + (radius13 * sin(i * twicePi13 / triangleAmount13))
			);
		}
	glEnd();

	GLfloat x14=-0.4f; GLfloat y14=-0.43f; GLfloat radius14 =0.012f;
	int triangleAmount14 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi14 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 175, 231);
		glVertex2f(x14, y14); // center of circle
		for(i = 0; i <= triangleAmount14;i++) {
			glVertex2f(
		            x14 + (radius14* cos(i *  twicePi14 / triangleAmount14)),
			    y14 + (radius14 * sin(i * twicePi14 / triangleAmount14))
			);
		}
	glEnd();


glBegin(GL_POLYGON);//hull red
glColor3ub(164, 41, 45);
glVertex2f(-0.66, -0.325);
glVertex2f(-0.659, -0.345);
glVertex2f(-0.656, -0.37);
glVertex2f(-0.534, -0.37);
glVertex2f(-0.54, -0.345);
glVertex2f(-0.54, -0.325);
glEnd();

glBegin(GL_POLYGON);//hull red
glColor3ub(164, 41, 45);
glVertex2f(0.128, -0.328);
glVertex2f(0.126, -0.358);
glVertex2f(0.124, -0.37);
glVertex2f(0.422, -0.37);
glVertex2f(0.432, -0.34);
glVertex2f(0.434, -0.328);
glEnd();

glBegin(GL_QUADS);//hull white top
glColor3ub(252, 250, 253);
glVertex2f(-0.656, -0.37);
glVertex2f(-0.534, -0.37);
glVertex2f(-0.531, -0.382);
glVertex2f(-0.654, -0.382);
glEnd();

glBegin(GL_QUADS);//hull white top
glColor3ub(252, 250, 253);
glVertex2f(0.124, -0.37);
glVertex2f(0.122, -0.382);
glVertex2f(0.418, -0.382);
glVertex2f(0.422, -0.37);
glEnd();

glBegin(GL_POLYGON);//hull mid black
glColor3ub(88, 85, 80);
glVertex2f(-0.654, -0.382);
glVertex2f(-0.64, -0.41);
glVertex2f(-0.61, -0.45);
glVertex2f(-0.59, -0.47);
glVertex2f(-0.57, -0.5);
glVertex2f(-0.57, -0.382);
glEnd();

glBegin(GL_POLYGON);//hull mid black
glColor3ub(88, 85, 80);
glVertex2f(-0.57, -0.382);
glVertex2f(-0.57, -0.5);
glVertex2f(-0.56, -0.52);
glVertex2f(-0.5, -0.52);
glVertex2f(-0.46, -0.455);
glVertex2f(-0.495, -0.44);
glVertex2f(-0.52, -0.41);
glVertex2f(-0.531, -0.382);
glEnd();

glBegin(GL_TRIANGLES);//hull mid black
glColor3ub(88, 85, 80);
glVertex2f(-0.46, -0.455);
glVertex2f(-0.5, -0.52);
glVertex2f(-0.46, -0.52);
glEnd();

glBegin(GL_QUADS);//hull mid black
glColor3ub(88, 85, 80);
glVertex2f(-0.46, -0.455);
glVertex2f(-0.32, -0.455);
glVertex2f(-0.32, -0.52);
glVertex2f(-0.46, -0.52);
glEnd();

glBegin(GL_QUADS);//hull mid black
glColor3ub(88, 85, 80);
glVertex2f(-0.32, -0.48);
glVertex2f(0.06, -0.48);
glVertex2f(0.06, -0.52);
glVertex2f(-0.32, -0.52);
glEnd();


glBegin(GL_POLYGON);//hull mid black
glColor3ub(88, 85, 80);
glVertex2f(0.06, -0.52);
glVertex2f(0.16, -0.52);
glVertex2f(0.16, -0.382);
glVertex2f(0.122, -0.382);
glVertex2f(0.12, -0.4);
glVertex2f(0.105, -0.435);
glVertex2f(0.08, -0.465);
glVertex2f(0.06, -0.48);
glEnd();

glBegin(GL_QUADS);//hull mid black
glColor3ub(88, 85, 80);
glVertex2f(0.16, -0.382);
glVertex2f(0.36, -0.382);
glVertex2f(0.36, -0.52);
glVertex2f(0.16, -0.52);
glEnd();

glBegin(GL_POLYGON);//hull mid black
glColor3ub(88, 85, 80);
glVertex2f(0.36, -0.382);
glVertex2f(0.418, -0.382);
glVertex2f(0.41, -0.41);
glVertex2f(0.39, -0.46);
glVertex2f(0.36, -0.52);
glEnd();

glBegin(GL_QUADS);//hull mid white
glColor3ub(202, 198, 199);
glVertex2f(-0.56, -0.52);
glVertex2f(-0.552, -0.538);
glVertex2f(0.3471, -0.538);
glVertex2f(0.36, -0.52);
glEnd();

glBegin(GL_POLYGON);//hull down black
glColor3ub(88, 85, 80);
glVertex2f(-0.552, -0.538);
glVertex2f(-0.54, -0.58);
glVertex2f(0.315, -0.58);
glVertex2f(0.335, -0.555);
glVertex2f(0.3471, -0.538);
glEnd();

glBegin(GL_POLYGON);//break  down red
glColor3ub(204, 77, 67);
glVertex2f(-0.57, -0.5);
glVertex2f(-0.57, -0.58);
glVertex2f(-0.54, -0.58);
glVertex2f(-0.544, -0.56);
glVertex2f(-0.552, -0.536);
glVertex2f(-0.558, -0.52);
glVertex2f(-0.57, -0.5);
glEnd();

		GLfloat x15=0.258f; GLfloat y15=-0.438f; GLfloat radius15 =0.011f;
	int triangleAmount15 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi15 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 175, 165);
		glVertex2f(x15, y15); // center of circle
		for(i = 0; i <= triangleAmount15;i++) {
			glVertex2f(
		            x15 + (radius15* cos(i *  twicePi15 / triangleAmount15)),
			    y15 + (radius15 * sin(i * twicePi15 / triangleAmount15))
			);
		}
	glEnd();

		GLfloat x16=0.258f; GLfloat y16=-0.438f; GLfloat radius16 =0.006f;
	int triangleAmount16 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi16 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(116, 117, 112); // windmill
		glVertex2f(x16, y16); // center of circle
		for(i = 0; i <= triangleAmount16;i++) {
			glVertex2f(
		            x16 + (radius16* cos(i *  twicePi16 / triangleAmount16)),
			    y16 + (radius16 * sin(i * twicePi16 / triangleAmount16))
			);
		}
	glEnd();

glBegin(GL_QUADS);//anchor
glColor3ub(116, 117, 112);
glVertex2f(0.256, -0.448);
glVertex2f(0.26, -0.448);
glVertex2f(0.26, -0.496);
glVertex2f(0.256, -0.496);
glEnd();


glBegin(GL_POLYGON);//anchor low
glColor3ub(116, 117, 112);
glVertex2f(0.25, -0.492);
glVertex2f(0.25, -0.496);
glVertex2f(0.258, -0.502);
glVertex2f(0.266, -0.496);
glVertex2f(0.27, -0.49);
glVertex2f(0.266, -0.492);
glVertex2f(0.26, -0.496);
glVertex2f(0.256, -0.496);
glEnd();


glBegin(GL_POLYGON);//anchor low
glColor3ub(116, 117, 112);
glVertex2f(0.266, -0.492);
glVertex2f(0.27, -0.49);
glVertex2f(0.272, -0.482);
glVertex2f(0.272, -0.474);
glVertex2f(0.27, -0.474);
glVertex2f(0.27, -0.48);
glVertex2f(0.266, -0.492);
glEnd();

glBegin(GL_TRIANGLES);//anchor low
glColor3ub(116, 117, 112);
glVertex2f(0.272, -0.474);
glVertex2f(0.266, -0.474);
glVertex2f(0.272, -0.466);
glEnd();

glBegin(GL_POLYGON);//anchor low
glColor3ub(116, 117, 112);
glVertex2f(0.25, -0.492);
glVertex2f(0.25, -0.496);
glVertex2f(0.246, -0.49);
glVertex2f(0.244, -0.482);
glVertex2f(0.244, -0.474);
glVertex2f(0.246, -0.474);
glVertex2f(0.246, -0.48);
glEnd();

glBegin(GL_TRIANGLES);//anchor low
glColor3ub(116, 117, 112);
glVertex2f(0.244, -0.474);
glVertex2f(0.25, -0.474);
glVertex2f(0.244, -0.466);
glEnd();


//ship shadow start


glBegin(GL_POLYGON);//shadow
glColor3ub(150, 150, 150);
glVertex2f(0.28, -0.58);
glVertex2f(0.34, -0.6);
glVertex2f(0.38, -0.62);
glVertex2f(0.43, -0.66);
glVertex2f(0.28, -0.66);
glEnd();

glBegin(GL_QUADS);//shadow
glColor3ub(150, 150, 150);
glVertex2f(0.19, -0.58);
glVertex2f(0.28, -0.58);
glVertex2f(0.28, -0.68);
glVertex2f(0.19, -0.68);
glEnd();

glBegin(GL_QUADS);//shadow
glColor3ub(150, 150, 150);
glVertex2f(0.1, -0.58);
glVertex2f(0.19, -0.58);
glVertex2f(0.19, -0.716);
glVertex2f(0.1, -0.715);
glEnd();

glBegin(GL_QUADS);//shadow
glColor3ub(150, 150, 150);
glVertex2f(0.015, -0.58);
glVertex2f(0.1, -0.58);
glVertex2f(0.1, -0.7);
glVertex2f(0.015, -0.7);
glEnd();

glBegin(GL_QUADS);//shadow
glColor3ub(150, 150, 150);
glVertex2f(-0.08, -0.58);
glVertex2f(0.015, -0.58);
glVertex2f(0.015, -0.68);
glVertex2f(-0.08, -0.68);
glEnd();

glBegin(GL_QUADS);//shadow
glColor3ub(150, 150, 150);
glVertex2f(-0.16, -0.58);
glVertex2f(-0.08, -0.58);
glVertex2f(-0.08, -0.7);
glVertex2f(-0.16, -0.7);
glEnd();

glBegin(GL_QUADS);//shadow
glColor3ub(150, 150, 150);
glVertex2f(-0.34, -0.58);
glVertex2f(-0.16, -0.58);
glVertex2f(-0.16, -0.68);
glVertex2f(-0.34, -0.68);
glEnd();

glBegin(GL_QUADS);//shadow
glColor3ub(150, 150, 150);
glVertex2f(-0.38, -0.58);
glVertex2f(-0.34, -0.58);
glVertex2f(-0.34, -0.63);
glVertex2f(-0.38, -0.63);
glEnd();

glBegin(GL_QUADS);//shadow
glColor3ub(150, 150, 150);
glVertex2f(-0.57, -0.58);
glVertex2f(-0.38, -0.58);
glVertex2f(-0.38, -0.68);
glVertex2f(-0.57, -0.68);
glEnd();

glBegin(GL_QUADS);//shadow
glColor3ub(150, 150, 150);
glVertex2f(-0.57, -0.68);
glVertex2f(-0.59, -0.7);
glVertex2f(-0.36, -0.7);
glVertex2f(-0.38, -0.68);
glEnd();

glBegin(GL_QUADS);//shadow
glColor3ub(150, 150, 150);
glVertex2f(-0.54, -0.7);
glVertex2f(-0.54, -0.72);
glVertex2f(-0.4, -0.72);
glVertex2f(-0.4, -0.7);
glEnd();

glBegin(GL_POLYGON);//shadow
glColor3ub(150, 150, 150);
glVertex2f(-0.57, -0.59);
glVertex2f(-0.585, -0.595);
glVertex2f(-0.605, -0.605);
glVertex2f(-0.63, -0.625);
glVertex2f(-0.65, -0.645);
glVertex2f(-0.66, -0.66);
glVertex2f(-0.66, -0.665);
glVertex2f(-0.57, -0.665);
glEnd();

glBegin(GL_QUADS);//shadow
glColor3ub(150, 150, 150);
glVertex2f(-0.525, -0.72);
glVertex2f(-0.52, -0.72);
glVertex2f(-0.52, -0.74);
glVertex2f(-0.525, -0.74);
glEnd();

glBegin(GL_QUADS);//shadow
glColor3ub(150, 150, 150);
glVertex2f(-0.515, -0.72);
glVertex2f(-0.515, -0.735);
glVertex2f(-0.51, -0.735);
glVertex2f(-0.51, -0.72);
glEnd();

glBegin(GL_QUADS);//shadow
glColor3ub(150, 150, 150);
glVertex2f(-0.47, -0.72);
glVertex2f(-0.47, -0.745);
glVertex2f(-0.465, -0.745);
glVertex2f(-0.465, -0.72);
glEnd();

glBegin(GL_QUADS);//shadow
glColor3ub(150, 150, 150);
glVertex2f(-0.415, -0.72);
glVertex2f(-0.41, -0.72);
glVertex2f(-0.41, -0.735);
glVertex2f(-0.415, -0.735);
glEnd();

//ship shadow end
//front ship end


//front crane start

glBegin(GL_QUADS);//brown leg
glColor3ub(109, 33, 14);
glVertex2f(0.36, -0.574);
glVertex2f(0.37, -0.574);
glVertex2f(0.37, -0.59);
glVertex2f(0.36, -0.59);
glEnd();

glBegin(GL_POLYGON);//brown leg 2
glColor3ub(109, 33, 14);
glVertex2f(0.36, -0.59);
glVertex2f(0.356, -0.594);
glVertex2f(0.356, -0.606);
glVertex2f(0.374, -0.606);
glVertex2f(0.374, -0.594);
glVertex2f(0.37, -0.59);
glEnd();

glLoadIdentity();

glBegin(GL_QUADS);//top Horizontal pole
glColor3ub(211, 139, 2);
glVertex2f(-0.14, 0.29);
glVertex2f(-0.1, 0.27);
glVertex2f(0.82, 0.27);
glVertex2f(0.82, 0.29);
glEnd();

glBegin(GL_QUADS);//top diagonal pole
glColor3ub(230, 169, 0);
glVertex2f(0.74, 0.29);
glVertex2f(0.76, 0.29);
glVertex2f(0.38, 0.6);
glVertex2f(0.38, 0.58);
glEnd();

glBegin(GL_QUADS);//top left pole
glColor3ub(232, 186, 20);
glVertex2f(0.35, 0.63);
glVertex2f(0.38, 0.63);
glVertex2f(0.38, 0.57);
glVertex2f(0.35, 0.57);
glEnd();

glBegin(GL_QUADS);//top narrow left pole
glColor3ub(230, 169, 0);
glVertex2f(0.36, 0.57);
glVertex2f(0.36, 0.356);
glVertex2f(0.37, 0.356);
glVertex2f(0.37, 0.57);
glEnd();

glBegin(GL_QUADS);//top left pole 2nd
glColor3ub(232, 186, 20);
glVertex2f(0.354, 0.356);
glVertex2f(0.376, 0.356);
glVertex2f(0.376, 0.302);
glVertex2f(0.354, 0.302);
glEnd();

glBegin(GL_QUADS);// left pole
glColor3ub(230, 169, 0);
glVertex2f(0.358, 0.302);
glVertex2f(0.372, 0.302);
glVertex2f(0.372, -0.574);
glVertex2f(0.358, -0.574);
glEnd();

glBegin(GL_QUADS);// right pole top
glColor3ub(232, 186, 20);
glVertex2f(0.61, 0.425);
glVertex2f(0.635, 0.425);
glVertex2f(0.635, 0.37);
glVertex2f(0.61, 0.37);
glEnd();

glBegin(GL_QUADS);// right pole top narrow
glColor3ub(230, 169, 0);
glVertex2f(0.615, 0.37);
glVertex2f(0.63, 0.37);
glVertex2f(0.63, 0.355);
glVertex2f(0.615, 0.355);
glEnd();

glBegin(GL_QUADS);// right pole top 2nd
glColor3ub(232, 186, 20);
glVertex2f(0.61, 0.355);
glVertex2f(0.635, 0.355);
glVertex2f(0.635, 0.3);
glVertex2f(0.61, 0.3);
glEnd();

glBegin(GL_QUADS);// right pole
glColor3ub(230, 169, 0);
glVertex2f(0.616, 0.3);
glVertex2f(0.63, 0.3);
glVertex2f(0.63, -0.475);
glVertex2f(0.616, -0.475);
glEnd();

glBegin(GL_QUADS);// cross pole top
glColor3ub(205, 154, 10);
glVertex2f(0.372, 0.18);
glVertex2f(0.616, 0.04);
glVertex2f(0.616, 0.02);
glVertex2f(0.372, 0.16);
glEnd();

glBegin(GL_QUADS);// cross pole top
glColor3ub(205, 154, 10);
glVertex2f(0.616, 0.18);
glVertex2f(0.372, 0.04);
glVertex2f(0.372, 0.02);
glVertex2f(0.616, 0.16);
glEnd();

glBegin(GL_QUADS);// cross pole down
glColor3ub(205, 154, 10);
glVertex2f(0.372, -0.11);
glVertex2f(0.616, -0.25);
glVertex2f(0.616, -0.27);
glVertex2f(0.372, -0.13);
glEnd();

glBegin(GL_QUADS);// cross pole down
glColor3ub(205, 154, 10);
glVertex2f(0.372, -0.252);
glVertex2f(0.372, -0.27);
glVertex2f(0.616, -0.125);
glVertex2f(0.616, -0.11);
glEnd();

glBegin(GL_QUADS);// horizontal pole middle top
glColor3ub(205, 154, 10);
glVertex2f(0.372, -0.02);
glVertex2f(0.372, -0.05);
glVertex2f(0.616, -0.05);
glVertex2f(0.616, -0.02);
glEnd();

glBegin(GL_QUADS);// horizontal pole middle down
glColor3ub(205, 154, 10);
glVertex2f(0.372, -0.325);
glVertex2f(0.372, -0.36);
glVertex2f(0.616, -0.36);
glVertex2f(0.616, -0.325);
glEnd();

glBegin(GL_QUADS);// top red deck
glColor3ub(237, 54, 84);
glVertex2f(0.38, 0.37);
glVertex2f(0.49, 0.37);
glVertex2f(0.49, 0.3);
glVertex2f(0.38, 0.3);
glEnd();

glBegin(GL_QUADS);// top red deck 2
glColor3ub(109, 33, 14);
glVertex2f(0.4, 0.3);
glVertex2f(0.47, 0.3);
glVertex2f(0.47, 0.29);
glVertex2f(0.4, 0.29);
glEnd();

glBegin(GL_QUADS);// top red deck window
glColor3ub(38, 38, 38);
glVertex2f(0.39, 0.36);
glVertex2f(0.39, 0.34);
glVertex2f(0.41, 0.34);
glVertex2f(0.41, 0.36);
glEnd();

glBegin(GL_QUADS);// top red deck window 2
glColor3ub(38, 38, 38);
glVertex2f(0.42, 0.36);
glVertex2f(0.42, 0.34);
glVertex2f(0.45, 0.34);
glVertex2f(0.45, 0.36);
glEnd();

glBegin(GL_QUADS);// top red deck window 3
glColor3ub(38, 38, 38);
glVertex2f(0.46, 0.36);
glVertex2f(0.46, 0.34);
glVertex2f(0.48, 0.34);
glVertex2f(0.48, 0.36);
glEnd();

glBegin(GL_QUADS);// square box near the rope
glColor3ub(109, 33, 14);
glVertex2f(0.745, 0.27);
glVertex2f(0.805, 0.27);
glVertex2f(0.805, 0.26);
glVertex2f(0.745, 0.26);
glEnd();

glBegin(GL_QUADS);// square box near the rope
glColor3ub(230, 169, 0);
glVertex2f(0.735, 0.26);
glVertex2f(0.815, 0.26);
glVertex2f(0.815, 0.2);
glVertex2f(0.735, 0.2);
glEnd();


glPushMatrix();
glTranslatef(position6,0,0);//animate Hanger
glBegin(GL_QUADS);// cargo hanger 1
glColor3ub(109, 33, 14);
glVertex2f(0.035, 0.27);
glVertex2f(0.035, 0.255);
glVertex2f(0.075, 0.255);
glVertex2f(0.075, 0.27);
glEnd();

glBegin(GL_QUADS);// cargo hanger 2
glColor3ub(230, 169, 0);
glVertex2f(0.09, 0.255);
glVertex2f(0.02, 0.255);
glVertex2f(0.02, 0.245);
glVertex2f(0.09, 0.245);
glEnd();

glBegin(GL_QUADS);// cargo hanger rope left
glColor3ub(109, 33, 14);
glVertex2f(0.085, 0.245);
glVertex2f(0.08, 0.245);
glVertex2f(0.08, 0.07);
glVertex2f(0.085, 0.07);
glEnd();

glBegin(GL_QUADS);// cargo hanger rope right
glColor3ub(109, 33, 14);
glVertex2f(0.03, 0.245);
glVertex2f(0.025, 0.245);
glVertex2f(0.025, 0.07);
glVertex2f(0.03, 0.07);
glEnd();

glBegin(GL_QUADS);// cargo hanger 3
glColor3ub(230, 169, 0);
glVertex2f(0.09, 0.07);
glVertex2f(0.02, 0.07);
glVertex2f(0.02, 0.04);
glVertex2f(0.09, 0.04);
glEnd();

glBegin(GL_QUADS);// cargo hanger 3 cargo
glColor3ub(33, 39, 179);
glVertex2f(0.11, 0.04);
glVertex2f(-0.0, 0.04);
glVertex2f(-0.0, -0.03);
glVertex2f(0.11, -0.03);
glEnd();

glBegin(GL_LINES);// cargo hanger 3 cargo line
glColor3ub(51, 53, 91);
glVertex2f(0.11, 0.04);
glVertex2f(-0.0, 0.04);
glVertex2f(-0.0, 0.04);
glVertex2f(-0.0, -0.03);
glVertex2f(-0.0, -0.03);
glVertex2f(0.11, -0.03);
glVertex2f(0.11, -0.03);
glVertex2f(0.11, 0.04);
glEnd();

glPopMatrix();


//front cargo cross
glBegin(GL_LINES);
glColor3ub(205, 154, 10);
glVertex2f(0.4, 0.265);//right cross
glVertex2f(0.37, 0.225);
glVertex2f(0.4, 0.27);
glVertex2f(0.4, -0.605);
glVertex2f(0.4, 0.265);
glVertex2f(0.4, 0.265);
glVertex2f(0.37, 0.225);
glVertex2f(0.4, 0.185);
glVertex2f(0.4, 0.185);
glVertex2f(0.37, 0.14);
glVertex2f(0.37, 0.14);
glVertex2f(0.4, 0.1);
glVertex2f(0.4, 0.1);
glVertex2f(0.37, 0.062);
glVertex2f(0.37, 0.062);
glVertex2f(0.4, 0.02);
glVertex2f(0.4, 0.02);
glVertex2f(0.37, -0.02);
glVertex2f(0.37, -0.02);
glVertex2f(0.4, -0.06);
glVertex2f(0.4, -0.06);
glVertex2f(0.37, -0.105);
glVertex2f(0.37, -0.105);
glVertex2f(0.4, -0.145);
glVertex2f(0.4, -0.145);
glVertex2f(0.37, -0.185);
glVertex2f(0.37, -0.185);
glVertex2f(0.4, -0.225);
glVertex2f(0.4, -0.225);
glVertex2f(0.37, -0.265);
glVertex2f(0.37, -0.265);
glVertex2f(0.4, -0.305);
glVertex2f(0.4, -0.305);
glVertex2f(0.37, -0.345);
glVertex2f(0.37, -0.345);
glVertex2f(0.4, -0.39);
glVertex2f(0.4, -0.39);
glVertex2f(0.37, -0.43);
glVertex2f(0.37, -0.43);
glVertex2f(0.4, -0.47);
glVertex2f(0.4, -0.47);
glVertex2f(0.37, -0.51);
glVertex2f(0.37, -0.51);
glVertex2f(0.4, -0.555);
glVertex2f(0.37, 0.265);//left cross
glVertex2f(0.4, 0.225);
glVertex2f(0.4, 0.225);
glVertex2f(0.37, 0.185);
glVertex2f(0.37, 0.185);
glVertex2f(0.4, 0.14);
glVertex2f(0.4, 0.14);
glVertex2f(0.37, 0.1);
glVertex2f(0.37, 0.1);
glVertex2f(0.4, 0.062);
glVertex2f(0.4, 0.062);
glVertex2f(0.37, 0.02);
glVertex2f(0.37, 0.02);
glVertex2f(0.4, -0.02);
glVertex2f(0.4, -0.02);
glVertex2f(0.37, -0.06);
glVertex2f(0.37, -0.06);
glVertex2f(0.4, -0.105);
glVertex2f(0.4, -0.105);
glVertex2f(0.37, -0.145);
glVertex2f(0.37, -0.145);
glVertex2f(0.4, -0.185);
glVertex2f(0.4, -0.185);
glVertex2f(0.37, -0.225);
glVertex2f(0.37, -0.225);
glVertex2f(0.4, -0.265);
glVertex2f(0.4, -0.265);
glVertex2f(0.37, -0.305);
glVertex2f(0.37, -0.305);
glVertex2f(0.4, -0.345);
glVertex2f(0.4, -0.345);
glVertex2f(0.37, -0.39);
glVertex2f(0.37, -0.39);
glVertex2f(0.4, -0.43);
glVertex2f(0.4, -0.43);
glVertex2f(0.37, -0.47);
glVertex2f(0.37, -0.47);
glVertex2f(0.4, -0.51);
glVertex2f(0.4, -0.51);
glVertex2f(0.37, -0.555);
glVertex2f(0.43, 0.27);//front cargo ladder
glVertex2f(0.43, -0.605);
glVertex2f(0.45, 0.27);
glVertex2f(0.45, -0.605);
glVertex2f(0.43, 0.255);
glVertex2f(0.45, 0.255);
glVertex2f(0.43, 0.24);
glVertex2f(0.45, 0.24);
glVertex2f(0.43, 0.222);
glVertex2f(0.45, 0.222);
glVertex2f(0.43, 0.206);
glVertex2f(0.45, 0.206);
glVertex2f(0.43, 0.188);
glVertex2f(0.45, 0.188);
glVertex2f(0.43, 0.172);
glVertex2f(0.45, 0.172);
glVertex2f(0.43, 0.156);
glVertex2f(0.45, 0.156);
glVertex2f(0.43, 0.106);
glVertex2f(0.45, 0.106);
glVertex2f(0.43, 0.088);
glVertex2f(0.45, 0.088);
glVertex2f(0.43, 0.04);
glVertex2f(0.45, 0.04);
glVertex2f(0.43, 0.022);
glVertex2f(0.45, 0.022);
glVertex2f(0.43, 0.006);
glVertex2f(0.45, 0.006);
glVertex2f(0.43, -0.01);
glVertex2f(0.45, -0.01);
glVertex2f(0.43, -0.06);
glVertex2f(0.45, -0.06);
glVertex2f(0.43, -0.078);
glVertex2f(0.45, -0.078);
glVertex2f(0.43, -0.094);
glVertex2f(0.45, -0.094);
glVertex2f(0.43, -0.11);
glVertex2f(0.45, -0.11);
glVertex2f(0.43, -0.128);
glVertex2f(0.45, -0.128);
glVertex2f(0.43, -0.178);
glVertex2f(0.45, -0.178);
glVertex2f(0.43, -0.194);
glVertex2f(0.45, -0.194);
glVertex2f(0.43, -0.21);
glVertex2f(0.45, -0.21);
glVertex2f(0.43, -0.244);
glVertex2f(0.45, -0.244);
glVertex2f(0.43, -0.262);
glVertex2f(0.45, -0.262);
glVertex2f(0.45, -0.278);
glVertex2f(0.45, -0.278);
glVertex2f(0.45, -0.292);
glVertex2f(0.45, -0.292);
glVertex2f(0.43, -0.31);
glVertex2f(0.45, -0.31);
glVertex2f(0.43, -0.362);
glVertex2f(0.45, -0.362);
glVertex2f(0.43, -0.376);
glVertex2f(0.45, -0.376);
glVertex2f(0.43, -0.394);
glVertex2f(0.45, -0.394);
glVertex2f(0.43, -0.41);
glVertex2f(0.45, -0.41);
glVertex2f(0.43, -0.426);
glVertex2f(0.45, -0.426);
glVertex2f(0.43, -0.444);
glVertex2f(0.45, -0.444);
glVertex2f(0.43, -0.46);
glVertex2f(0.45, -0.46);
glVertex2f(0.43, -0.478);
glVertex2f(0.45, -0.478);
glVertex2f(0.43, -0.494);
glVertex2f(0.45, -0.494);
glVertex2f(0.43, -0.51);
glVertex2f(0.45, -0.51);
glVertex2f(0.43, -0.526);
glVertex2f(0.45, -0.526);
glVertex2f(0.43, -0.544);
glVertex2f(0.45, -0.544);
glVertex2f(0.43, -0.56);
glVertex2f(0.45, -0.56);
glVertex2f(0.43, -0.576);
glVertex2f(0.45, -0.576);
glVertex2f(0.43, -0.592);
glEnd();


//Shadow of cross and ladder
glBegin(GL_LINES);
glColor3ub(147, 147, 147);
glVertex2f(0.4, -0.6);//cross shadow
glVertex2f(0.4, -0.694);
glVertex2f(0.386, -0.664);
glVertex2f(0.372, -0.68);
glVertex2f(0.372, -0.68);
glVertex2f(0.386, -0.696);
glVertex2f(0.386, -0.696);
glVertex2f(0.4, -0.68);
glVertex2f(0.4, -0.68);
glVertex2f(0.386, -0.664);
glVertex2f(0.43,- 0.6);//front cargo ladder shadow
glVertex2f(0.43, -0.694);
glVertex2f(0.45,- 0.6);
glVertex2f(0.45, -0.694);
glVertex2f(0.43, -0.615);
glVertex2f(0.45, -0.615);
glVertex2f(0.43, -0.63);
glVertex2f(0.45, -0.63);
glVertex2f(0.43, -0.645);
glVertex2f(0.45, -0.645);
glVertex2f(0.43, -0.655);
glVertex2f(0.45, -0.655);
glVertex2f(0.43, -0.668);
glVertex2f(0.45, -0.668);
glVertex2f(0.43, -0.683);
glVertex2f(0.45, -0.683);
glEnd();

glBegin(GL_QUADS);//left pole shadow
glColor3ub(150, 150, 150);
glVertex2f(0.356, -0.606);
glVertex2f(0.374, -0.606);
glVertex2f(0.374, -0.69);
glVertex2f(0.356, -0.69);

//cargo box front left
glBegin(GL_QUADS);//1
glColor3ub(230, 177, 81);
glVertex2f(0.695, -0.28);
glVertex2f(0.695, -0.38);
glVertex2f(0.86, -0.38);
glVertex2f(0.86, -0.28);
glEnd();

glBegin(GL_LINES);//down row left
glColor3ub(64, 64, 64);
glVertex2f(0.695, -0.28);
glVertex2f(0.695, -0.38);
glVertex2f(0.695, -0.38);
glVertex2f(0.86, -0.38);
glVertex2f(0.86, -0.38);
glVertex2f(0.86, -0.28);
glVertex2f(0.86, -0.28);
glVertex2f(0.695, -0.28);
glEnd();

glBegin(GL_QUADS);//2
glColor3ub(172, 18, 28);
glVertex2f(0.695, -0.38);
glVertex2f(0.695, -0.47);
glVertex2f(0.86, -0.47);
glVertex2f(0.86, -0.38);
glEnd();

glBegin(GL_LINES);//down row left
glColor3ub(64, 64, 64);
glVertex2f(0.695, -0.38);
glVertex2f(0.695, -0.47);
glVertex2f(0.695, -0.47);
glVertex2f(0.86, -0.47);
glVertex2f(0.86, -0.47);
glVertex2f(0.86, -0.38);
glVertex2f(0.86, -0.38);
glVertex2f(0.695, -0.38);
glEnd();

glBegin(GL_QUADS);//3
glColor3ub(97, 126, 166);
glVertex2f(0.86, -0.38);
glVertex2f(0.86, -0.47);
glVertex2f(1, -0.47);
glVertex2f(1, -0.38);
glEnd();

glBegin(GL_LINES);//down raw left
glColor3ub(64, 64, 64);
glVertex2f(0.86, -0.38);
glVertex2f(0.86, -0.47);
glVertex2f(0.86, -0.47);
glVertex2f(1, -0.47);
glVertex2f(1, -0.47);
glVertex2f(1, -0.38);
glVertex2f(1, -0.38);
glVertex2f(0.86, -0.38);
glEnd();

glBegin(GL_QUADS);//4
glColor3ub(22, 28, 157);
glVertex2f(0.86, -0.47);
glVertex2f(0.86, -0.57);
glVertex2f(1, -0.57);
glVertex2f(1, -0.47);
glEnd();

glBegin(GL_LINES);//down raw left
glColor3ub(64, 64, 64);
glVertex2f(0.86, -0.47);
glVertex2f(0.86, -0.57);
glVertex2f(0.86, -0.57);
glVertex2f(1, -0.57);
glVertex2f(1, -0.57);
glVertex2f(1, -0.47);
glVertex2f(1, -0.47);
glVertex2f(0.86, -0.47);
glEnd();

glBegin(GL_QUADS);//5
glColor3ub(219, 103, 109);
glVertex2f(0.86, -0.57);
glVertex2f(0.86, -0.665);
glVertex2f(1, -0.665);
glVertex2f(1, -0.57);
glEnd();

glBegin(GL_LINES);//down raw left
glColor3ub(64, 64, 64);
glVertex2f(0.86, -0.57);
glVertex2f(0.86, -0.665);
glVertex2f(0.86, -0.665);
glVertex2f(1, -0.665);
glVertex2f(1, -0.665);
glVertex2f(1, -0.57);
glVertex2f(1, -0.57);
glVertex2f(0.86, -0.57);
glEnd();

glBegin(GL_QUADS);//6
glColor3ub(252, 239, 73);
glVertex2f(0.86, -0.665);
glVertex2f(0.86, -0.764);
glVertex2f(1, -0.764);
glVertex2f(1, -0.665);
glEnd();

glBegin(GL_LINES);//down raw left
glColor3ub(64, 64, 64);
glVertex2f(0.86, -0.665);
glVertex2f(0.86, -0.764);
glVertex2f(0.86, -0.764);
glVertex2f(1, -0.764);
glVertex2f(1, -0.764);
glVertex2f(1, -0.665);
glVertex2f(1, -0.665);
glVertex2f(0.86, -0.665);
glEnd();

glBegin(GL_QUADS);//7
glColor3ub(76, 217, 115);
glVertex2f(0.695, -0.665);
glVertex2f(0.695, -0.764);
glVertex2f(0.86, -0.764);
glVertex2f(0.86, -0.665);
glEnd();

glBegin(GL_LINES);//down raw left
glColor3ub(64, 64, 64);
glVertex2f(0.695, -0.665);
glVertex2f(0.695, -0.764);
glVertex2f(0.695, -0.764);
glVertex2f(0.86, -0.764);
glVertex2f(0.86, -0.764);
glVertex2f(0.86, -0.665);
glVertex2f(0.86, -0.665);
glVertex2f(0.695, -0.665);
glEnd();

glBegin(GL_QUADS);//8
glColor3ub(252, 239, 73);
glVertex2f(0.53, -0.665);
glVertex2f(0.53, -0.764);
glVertex2f(0.695, -0.764);
glVertex2f(0.695, -0.665);
glEnd();

glBegin(GL_LINES);//down row left
glColor3ub(64, 64, 64);
glVertex2f(0.53, -0.665);
glVertex2f(0.53, -0.764);
glVertex2f(0.53, -0.764);
glVertex2f(0.695, -0.764);
glVertex2f(0.695, -0.764);
glVertex2f(0.695, -0.665);
glVertex2f(0.695, -0.665);
glVertex2f(0.53, -0.665);
glEnd();


glBegin(GL_QUADS);//9
glColor3ub(175, 31, 38);
glVertex2f(0.53, -0.57);
glVertex2f(0.53, -0.665);
glVertex2f(0.695, -0.665);
glVertex2f(0.695, -0.57);
glEnd();

glBegin(GL_LINES);//down row left
glColor3ub(64, 64, 64);
glVertex2f(0.53, -0.57);
glVertex2f(0.53, -0.665);
glVertex2f(0.53, -0.665);
glVertex2f(0.695, -0.665);
glVertex2f(0.695, -0.665);
glVertex2f(0.695, -0.57);
glVertex2f(0.695, -0.57);
glVertex2f(0.53, -0.57);
glEnd();

glBegin(GL_QUADS);//10
glColor3ub(252, 239, 73);
glVertex2f(0.695, -0.57);
glVertex2f(0.695, -0.665);
glVertex2f(0.86, -0.665);
glVertex2f(0.86, -0.57);
glEnd();

glBegin(GL_LINES);//down row left
glColor3ub(64, 64, 64);
glVertex2f(0.695, -0.57);
glVertex2f(0.695, -0.665);
glVertex2f(0.695, -0.665);
glVertex2f(0.86, -0.665);
glVertex2f(0.86, -0.665);
glVertex2f(0.86, -0.57);
glVertex2f(0.86, -0.57);
glEnd();

glBegin(GL_QUADS);//11
glColor3ub(132, 85, 164);
glVertex2f(0.695, -0.47);
glVertex2f(0.695, -0.57);
glVertex2f(0.86, -0.57);
glVertex2f(0.86, -0.47);
glEnd();

glBegin(GL_LINES);//down row left
glColor3ub(64, 64, 64);
glVertex2f(0.695, -0.47);
glVertex2f(0.695, -0.57);
glVertex2f(0.695, -0.57);
glVertex2f(0.86, -0.57);
glVertex2f(0.86, -0.57);
glVertex2f(0.86, -0.47);
glVertex2f(0.86, -0.47);
glVertex2f(0.695, -0.47);
glEnd();

glBegin(GL_QUADS);//12
glColor3ub(45, 46, 208);
glVertex2f(0.53, -0.47);
glVertex2f(0.53, -0.57);
glVertex2f(0.695, -0.57);
glVertex2f(0.695, -0.47);
glEnd();

glBegin(GL_LINES);//down raw left
glColor3ub(64, 64, 64);
glVertex2f(0.53, -0.47);
glVertex2f(0.53, -0.57);
glVertex2f(0.53, -0.57);
glVertex2f(0.695, -0.57);
glVertex2f(0.695, -0.57);
glVertex2f(0.695, -0.47);
glVertex2f(0.695, -0.47);
glVertex2f(0.53, -0.47);
glEnd();

glBegin(GL_QUADS);//front cargo shadow
glColor3ub(150, 150, 150);
glVertex2f(0.53, -0.765);
glVertex2f(0.53, -1);
glVertex2f(1, -1);
glVertex2f(1, -0.765);
glEnd();

//cargo truck start

glPushMatrix();
glTranslatef(position7,0,0);// animate truck

glBegin(GL_QUADS);//front cargo car
glColor3ub(231, 139, 54);
glVertex2f(-0.306, -0.63);
glVertex2f(-0.306, -0.67);
glVertex2f(-0.256, -0.67);
glVertex2f(-0.262, -0.63);
glEnd();

glBegin(GL_QUADS);//front cargo car
glColor3ub(231, 139, 54);
glVertex2f(-0.306, -0.67);
glVertex2f(-0.306, -0.74);
glVertex2f(-0.256, -0.74);
glVertex2f(-0.256, -0.67);
glEnd();

glBegin(GL_QUADS);//front cargo car
glColor3ub(231, 139, 54);
glVertex2f(-0.256, -0.67);
glVertex2f(-0.256, -0.74);
glVertex2f(-0.223, -0.74);
glVertex2f(-0.223, -0.682);
glEnd();

glBegin(GL_QUADS);//front cargo car
glColor3ub(231, 139, 54);
glVertex2f(-0.223, -0.682);
glVertex2f(-0.223, -0.722);
glVertex2f(-0.212, -0.722);
glVertex2f(-0.212, -0.686);
glEnd();

glBegin(GL_QUADS);//front cargo car light
glColor3ub(240, 241, 243);
glVertex2f(-0.216, -0.692);
glVertex2f(-0.216, -0.704);
glVertex2f(-0.212, -0.704);
glVertex2f(-0.212, -0.692);
glEnd();
glBegin(GL_QUADS);//front cargo car glass
glColor3ub(169, 209, 242);
glVertex2f(-0.292, -0.635);
glVertex2f(-0.292, -0.67);
glVertex2f(-0.261, -0.67);
glVertex2f(-0.265, -0.635);
glEnd();

glBegin(GL_QUADS);//car handle
glColor3ub(72, 65, 63);
glVertex2f(-0.223, -0.722);
glVertex2f(-0.223, -0.739);
glVertex2f(-0.212, -0.739);
glVertex2f(-0.212, -0.722);
glEnd();

glBegin(GL_QUADS);//car handle
glColor3ub(72, 65, 63);
glVertex2f(-0.388, -0.739);
glVertex2f(-0.388, -0.752);
glVertex2f(-0.212, -0.752);
glVertex2f(-0.212, -0.739);
glEnd();

glBegin(GL_POLYGON);//car oil engine
glColor3ub(131, 131, 131);
glVertex2f(-0.337, -0.742);
glVertex2f(-0.341, -0.747);
glVertex2f(-0.341, -0.761);
glVertex2f(-0.337, -0.767);
glVertex2f(-0.305, -0.767);
glVertex2f(-0.3, -0.76);
glVertex2f(-0.3, -0.746);
glVertex2f(-0.305, -0.742);
glEnd();

glBegin(GL_QUADS);//car oil black box
glColor3ub(38, 33, 35);
glVertex2f(-0.322, -0.716);
glVertex2f(-0.322, -0.74);
glVertex2f(-0.306, -0.74);
glVertex2f(-0.306, -0.716);
glEnd();

glBegin(GL_QUADS);//car opener
glColor3ub(38, 33, 35);
glVertex2f(-0.292, -0.692);
glVertex2f(-0.292, -0.698);
glVertex2f(-0.286, -0.698);
glVertex2f(-0.286, -0.692);
glEnd();

glBegin(GL_QUADS);//middle car
glColor3ub(38, 33, 35);
glVertex2f(-0.38, -0.734);
glVertex2f(-0.38, -0.738);
glVertex2f(-0.35, -0.738);
glVertex2f(-0.35, -0.734);
glEnd();

glBegin(GL_QUADS);//middle car handle
glColor3ub(38, 33, 35);
glVertex2f(-0.602, -0.728);
glVertex2f(-0.602, -0.734);
glVertex2f(-0.344, -0.734);
glVertex2f(-0.344, -0.728);
glEnd();

glBegin(GL_QUADS);//middle car handle
glColor3ub (63, 61, 62);
glVertex2f(-0.4435, -0.734);
glVertex2f(-0.4435, -0.744);
glVertex2f(-0.402, -0.744);
glVertex2f(-0.402, -0.734);
glEnd();

glBegin(GL_QUADS);//middle car handle
glColor3ub (63, 61, 62);
glVertex2f(-0.408, -0.744);
glVertex2f(-0.408, -0.762);
glVertex2f(-0.404, -0.762);
glVertex2f(-0.404, -0.744);
glEnd();

glBegin(GL_QUADS);//middle car handle
glColor3ub (63, 61, 62);
glVertex2f(-0.414, -0.744);
glVertex2f(-0.408, -0.753);
glVertex2f(-0.408, -0.75);
glVertex2f(-0.412, -0.744);
glEnd();

glBegin(GL_QUADS);//middle car handle
glColor3ub (63, 61, 62);
glVertex2f(-0.58, -0.734);
glVertex2f(-0.58, -0.75);
glVertex2f(-0.46, -0.75);
glVertex2f(-0.42, -0.734);
glEnd();

glBegin(GL_QUADS);//middle car handle
glColor3ub (63, 61, 62);
glVertex2f(-0.597, -0.728);
glVertex2f(-0.597, -0.744);
glVertex2f(-0.576, -0.744);
glVertex2f(-0.576, -0.728);
glEnd();

glBegin(GL_QUADS);//middle car handle
glColor3ub (63, 61, 62);
glVertex2f(-0.592, -0.744);
glVertex2f(-0.592, -0.762);
glVertex2f(-0.59, -0.762);
glVertex2f(-0.59, -0.744);
glEnd();

glBegin(GL_QUADS);//cargo box
glColor3ub(36, 45, 198);
glVertex2f(-0.572, -0.62);
glVertex2f(-0.572, -0.728);
glVertex2f(-0.386, -0.728);
glVertex2f(-0.386, -0.62);
glEnd();

glBegin(GL_LINES);//car line
glColor3ub(120, 90, 58);
glVertex2f(-0.295, -0.633);
glVertex2f(-0.265, -0.633);
glVertex2f(-0.265, -0.633);
glVertex2f(-0.2585, -0.67);
glVertex2f(-0.2585, -0.67);
glVertex2f(-0.2586, -0.735);
glVertex2f(-0.2586, -0.735);
glVertex2f(-0.295, -0.735);
glVertex2f(-0.295, -0.735);
glVertex2f(-0.295, -0.633);

glVertex2f(-0.213, -0.692);
glVertex2f(-0.213, -0.691);
glVertex2f(-0.213, -0.691);
glVertex2f(-0.217, -0.691);
glVertex2f(-0.217, -0.691);
glVertex2f(-0.217, -0.709);
glVertex2f(-0.217, -0.709);
glVertex2f(-0.213, -0.709);
glVertex2f(-0.213, -0.709);
glVertex2f(-0.213, -0.704);
glEnd();

//car wheels

GLfloat x17=-0.247f, y17=-0.76f, radius17 =0.016f;  //front wheel
	int triangleAmount17= 20; //# of triangles used to draw circle

	GLfloat twicePi17 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub (4, 0, 2); // truck tire
		glVertex2f(x17, y17); // center of circle
		for(i = 0; i <= triangleAmount17; i++)
            {
			glVertex2f(
		            x17 + (radius17* cos(i *  twicePi17 / triangleAmount17)),
			    y17 + (radius17 * sin(i * twicePi17 / triangleAmount17))
			);
		}
	glEnd();

GLfloat x18=-0.247f, y18=-0.76f, radius18 =0.009f;  //front wheel Inner Circle
	int triangleAmount18= 20; //# of triangles used to draw circle

	GLfloat twicePi18 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(239, 240, 242); // truck tire
		glVertex2f(x18, y18); // center of circle
		for(i = 0; i <= triangleAmount18;i++) {
			glVertex2f(
		            x18 + (radius18* cos(i *  twicePi18 / triangleAmount18)),
			    y18 + (radius18* sin(i * twicePi18 / triangleAmount18))
			);
		}
	glEnd();

GLfloat x19=-0.247f, y19=-0.76f, radius19 =0.004f;
	int triangleAmount19= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi19 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub (4, 0, 2); //truck tire
		glVertex2f(x19, y19); // center of circle
		for(i = 0; i <= triangleAmount19;i++) {
			glVertex2f(
		            x19 + (radius19* cos(i *  twicePi19 / triangleAmount19)),
			    y19 + (radius19* sin(i * twicePi19 / triangleAmount19))
			);
		}
	glEnd();

GLfloat x20=-0.3645f, y20= -0.76f, radius20 =0.016f;
	int triangleAmount20= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi20= 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub (4, 0, 2); // truck tire
		glVertex2f(x20, y20); // center of circle
		for(i = 0; i <= triangleAmount20;i++) {
			glVertex2f(
		            x20 + (radius20* cos(i *  twicePi20/ triangleAmount20)),
			    y20+ (radius20 * sin(i * twicePi20/ triangleAmount20))
			);
		}
	glEnd();

GLfloat x21=-0.3645f, y21= -0.76f, radius21 =0.009f;
	int triangleAmount21= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi21= 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub (239, 240, 242); // truck tire
		glVertex2f(x21, y21); // center of circle
		for(i = 0; i <= triangleAmount21;i++) {
			glVertex2f(
		            x21 + (radius21* cos(i *  twicePi21/ triangleAmount21)),
			    y21+ (radius21 * sin(i * twicePi21/ triangleAmount21))
			);
		}
	glEnd();

GLfloat x22=-0.3645f, y22= -0.76f, radius22 =0.004f;
	int triangleAmount22= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi22= 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub (4, 0, 2); // truck tire
		glVertex2f(x22, y22); // center of circle
		for(i = 0; i <= triangleAmount22;i++) {
			glVertex2f(
		            x22 + (radius22* cos(i *  twicePi22/ triangleAmount22)),
			    y22+ (radius22 * sin(i * twicePi22/ triangleAmount22))
			);
		}
	glEnd();

GLfloat x23=-0.5285f, y23=  -0.76f, radius23 =0.016f;
	int triangleAmount23= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi23= 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub (4, 0, 2); // truck tire
		glVertex2f(x23, y23); // center of circle
		for(i = 0; i <= triangleAmount23;i++) {
			glVertex2f(
		            x23 + (radius23* cos(i *  twicePi23/ triangleAmount23)),
			    y23+ (radius23 * sin(i * twicePi23/ triangleAmount23))
			);
		}
	glEnd();

GLfloat x24=-0.5285f, y24=  -0.76f, radius24 =0.009f;
	int triangleAmount24= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi24= 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub (239, 240, 242); //truck tire
		glVertex2f(x24, y24); // center of circle
		for(i = 0; i <= triangleAmount24;i++) {
			glVertex2f(
		            x24 + (radius24* cos(i *  twicePi24/ triangleAmount24)),
			    y24+ (radius24 * sin(i * twicePi24/ triangleAmount24))
			);
		}
	glEnd();

	GLfloat x25=-0.5285f, y25=  -0.76f, radius25 =0.004f;
	int triangleAmount25= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi25= 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub (4, 0, 2); // truck tire
		glVertex2f(x25, y25); // center of circle
		for(i = 0; i <= triangleAmount25;i++) {
			glVertex2f(
		            x25 + (radius25* cos(i *  twicePi25/ triangleAmount25)),
			    y25+ (radius25* sin(i * twicePi25/ triangleAmount25))
			);
		}
	glEnd();

	GLfloat x26=-0.564f, y26=  -0.76f, radius26 =0.016f;
	int triangleAmount26= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi26= 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub (4, 0, 2); // truck tire
		glVertex2f(x26, y26); // center of circle
		for(i = 0; i <= triangleAmount26;i++) {
			glVertex2f(
		            x26+ (radius26* cos(i *  twicePi26/ triangleAmount26)),
			    y26+ (radius26* sin(i * twicePi26/ triangleAmount26))
			);
		}
	glEnd();

		GLfloat x27=-0.564f, y27=  -0.76f, radius27 =0.009f;
	int triangleAmount27= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi27= 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub (239, 240, 242); // truck tire
		glVertex2f(x27, y27); // center of circle
		for(i = 0; i <= triangleAmount27;i++) {
			glVertex2f(
		            x27+ (radius27* cos(i *  twicePi27/ triangleAmount27)),
			    y27+ (radius27* sin(i * twicePi27/ triangleAmount27))
			);
		}
	glEnd();
		GLfloat x28=-0.564f, y28=  -0.76f, radius28 =0.004f;
	int triangleAmount28= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi28= 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub (4, 0, 2); // truck tire
		glVertex2f(x28, y28); // center of circle
		for(i = 0; i <= triangleAmount28;i++) {
			glVertex2f(
		            x28+ (radius28* cos(i *  twicePi28/ triangleAmount28)),
			    y28+ (radius28* sin(i * twicePi28/ triangleAmount28))
			);
		}
	glEnd();

//cargo truck end

glPopMatrix();

//Cargo | Box | Container Start

glBegin(GL_QUADS);//left cargo1
glColor3ub(33, 39, 179);
glVertex2f(-0.88, -0.54);
glVertex2f(-0.72, -0.54);
glVertex2f(-0.72, -0.64);
glVertex2f(-0.88, -0.64);
glEnd();

glBegin(GL_LINES);//dark line
glColor3ub(64, 64, 64);
glVertex2f(-0.88, -0.54);
glVertex2f(-0.72, -0.54);
glVertex2f(-0.72, -0.54);
glVertex2f(-0.72, -0.64);
glVertex2f(-0.72, -0.64);
glVertex2f(-0.88, -0.64);
glVertex2f(-0.88, -0.64);
glVertex2f(-0.88, -0.54);
glEnd();

glBegin(GL_QUADS);//left cargo2
glColor3ub(191, 48, 45);
glVertex2f(-0.88, -0.64);
glVertex2f(-0.72, -0.64);
glVertex2f(-0.72, -0.74);
glVertex2f(-0.88, -0.74);
glEnd();

glBegin(GL_LINES);//dark line
glColor3ub(64, 64, 64);
glVertex2f(-0.88, -0.64);
glVertex2f(-0.72, -0.64);
glVertex2f(-0.72, -0.64);
glVertex2f(-0.72, -0.74);
glVertex2f(-0.72, -0.74);
glVertex2f(-0.88, -0.74);
glVertex2f(-0.88, -0.74);
glVertex2f(-0.88, -0.64);
glEnd();

glBegin(GL_QUADS);//left cargo3
glColor3ub(255, 242, 78);
glVertex2f(-0.88, -0.74);
glVertex2f(-0.72, -0.74);
glVertex2f(-0.72, -0.84);
glVertex2f(-0.88, -0.84);
glEnd();

glBegin(GL_LINES);//dark line
glColor3ub(64, 64, 64);
glVertex2f(-0.88, -0.74);
glVertex2f(-0.72, -0.74);
glVertex2f(-0.72, -0.74);
glVertex2f(-0.72, -0.84);
glVertex2f(-0.72, -0.84);
glVertex2f(-0.88, -0.84);
glVertex2f(-0.88, -0.84);
glVertex2f(-0.88, -0.74);
glEnd();

glBegin(GL_QUADS);//left cargo shadow
glColor3ub(150, 150, 150);
glVertex2f(-0.88, -0.84);
glVertex2f(-0.72, -0.84);
glVertex2f(-0.72, -1);
glVertex2f(-0.88, -1);
glEnd();

glBegin(GL_QUADS);//2nd right cargo
glColor3ub(212, 41, 37);
glVertex2f(0.23, -0.69);
glVertex2f(0.39, -0.69);
glVertex2f(0.39, -0.79);
glVertex2f(0.23, -0.79);
glEnd();

glBegin(GL_LINES);//dark line
glColor3ub(64, 64, 64);
glVertex2f(0.23, -0.69);
glVertex2f(0.39, -0.69);
glVertex2f(0.39, -0.69);
glVertex2f(0.39, -0.79);
glVertex2f(0.39, -0.79);
glVertex2f(0.23, -0.79);
glVertex2f(0.23, -0.79);
glVertex2f(0.23, -0.69);
glEnd();

glBegin(GL_QUADS);//2nd right cargo
glColor3ub(234, 226, 41);
glVertex2f(0.23, -0.79);
glVertex2f(0.39, -0.79);
glVertex2f(0.39, -0.89);
glVertex2f(0.23, -0.89);
glEnd();

glBegin(GL_LINES);//dark line
glColor3ub(64, 64, 64);
glVertex2f(0.23, -0.79);
glVertex2f(0.39, -0.79);
glVertex2f(0.39, -0.79);
glVertex2f(0.39, -0.89);
glVertex2f(0.39, -0.89);
glVertex2f(0.23, -0.89);
glVertex2f(0.23, -0.89);
glVertex2f(0.23, -0.79);
glEnd();

glBegin(GL_QUADS);//2nd right cargo
glColor3ub(63, 91, 128);
glVertex2f(0.39, -0.69);
glVertex2f(0.52, -0.69);
glVertex2f(0.52, -0.79);
glVertex2f(0.39, -0.79);
glEnd();

glBegin(GL_LINES);//dark line
glColor3ub(64, 64, 64);
glVertex2f(0.39, -0.69);
glVertex2f(0.52, -0.69);
glVertex2f(0.52, -0.69);
glVertex2f(0.52, -0.79);
glVertex2f(0.52, -0.79);
glVertex2f(0.39, -0.79);
glVertex2f(0.39, -0.79);
glVertex2f(0.39, -0.69);
glEnd();

glBegin(GL_QUADS);//2nd right cargo
glColor3ub(43, 46, 189);
glVertex2f(0.39, -0.79);
glVertex2f(0.52, -0.79);
glVertex2f(0.52, -0.89);
glVertex2f(0.39, -0.89);
glEnd();

glBegin(GL_LINES);//dark line
glColor3ub(64, 64, 64);
glVertex2f(0.39, -0.79);
glVertex2f(0.52, -0.79);
glVertex2f(0.52, -0.79);
glVertex2f(0.52, -0.89);
glVertex2f(0.52, -0.89);
glVertex2f(0.39, -0.89);
glVertex2f(0.39, -0.89);
glVertex2f(0.39, -0.79);
glEnd();

glBegin(GL_QUADS);//2nd right cargo shadow
glColor3ub(150, 150, 150);
glVertex2f(0.23, -0.89);
glVertex2f(0.52, -0.89);
glVertex2f(0.52, -1);
glVertex2f(0.23, -1);
glEnd();


//rain
glPushMatrix();
glTranslatef(position91, position9, 0.0f);

glColor3ub(174,214,241);
glBegin(GL_LINES);
glVertex2f(-0.4,0.47);
glVertex2f(-0.35,0.28);
glEnd();

glTranslatef(0.2, 0.1, 0);

glColor3ub(174,214,241);
glBegin(GL_LINES);
glVertex2f(-0.4,0.47);
glVertex2f(-0.35,0.28);
glEnd();

glTranslatef(-0.2, 0.1, 0);

glColor3ub(174,214,241);
glBegin(GL_LINES);
glVertex2f(-0.4,0.47);
glVertex2f(-0.35,0.28);
glEnd();

glTranslatef(0.2, -0.1, 0);

glColor3ub(174,214,241);
glBegin(GL_LINES);
glVertex2f(-0.4,0.47);
glVertex2f(-0.35,0.28);
glEnd();

glTranslatef(-0.2, -0.1, 0);

glColor3ub(174,214,241);
glBegin(GL_LINES);
glVertex2f(-0.4,0.47);
glVertex2f(-0.35,0.28);
glEnd();

glTranslatef(-0.4, -0.2, 0);

glColor3ub(174,214,241);
glBegin(GL_LINES);
glVertex2f(-0.4,0.47);
glVertex2f(-0.35,0.28);
glEnd();

glTranslatef(-0.4, 0.2, 0);

glColor3ub(174,214,241);
glBegin(GL_LINES);
glVertex2f(-0.4,0.47);
glVertex2f(-0.35,0.28);
glEnd();

glTranslatef(0.4, -0.2, 0);

glColor3ub(174,214,241);
glBegin(GL_LINES);
glVertex2f(-0.4,0.47);
glVertex2f(-0.35,0.28);
glEnd();

glTranslatef(0.4, 0.2, 0);

glColor3ub(174,214,241);
glBegin(GL_LINES);
glVertex2f(-0.4,0.47);
glVertex2f(-0.35,0.28);
glEnd();

glTranslatef(0.8, 0.4, 0);

glColor3ub(174,214,241);
glBegin(GL_LINES);
glVertex2f(-0.4,0.47);
glVertex2f(-0.35,0.28);
glEnd();

glTranslatef(0.8, -0.4, 0);

glColor3ub(174,214,241);
glBegin(GL_LINES);
glVertex2f(-0.4,0.47);
glVertex2f(-0.35,0.28);
glEnd();

glTranslatef(-0.8, 0.4, 0);

glColor3ub(174,214,241);
glBegin(GL_LINES);
glVertex2f(-0.4,0.47);
glVertex2f(-0.35,0.28);
glEnd();

glTranslatef(-0.8, -0.4, 0);

glColor3ub(174,214,241);
glBegin(GL_LINES);
glVertex2f(-0.4,0.47);
glVertex2f(-0.35,0.28);
glEnd();

glTranslatef(0.6, .3, 0);

glColor3ub(174,214,241);
glBegin(GL_LINES);
glVertex2f(-0.4,0.47);
glVertex2f(-0.35,0.28);
glEnd();

glTranslatef(0.6, -0.3, 0);

glColor3ub(174,214,241);
glBegin(GL_LINES);
glVertex2f(-0.4,0.47);
glVertex2f(-0.35,0.28);
glEnd();

glTranslatef(-0.6, 0.3, 0);

glColor3ub(174,214,241);
glBegin(GL_LINES);
glVertex2f(-0.4,0.47);
glVertex2f(-0.35,0.28);
glEnd();

glTranslatef(-0.6, -0.3, 0);

glColor3ub(174,214,241);
glBegin(GL_LINES);
glVertex2f(-0.4,0.47);
glVertex2f(-0.35,0.28);
glEnd();

glTranslatef(0.5, -0.25, 0);

glColor3ub(174,214,241);
glBegin(GL_LINES);
glVertex2f(-0.4,0.47);
glVertex2f(-0.35,0.28);
glEnd();

glTranslatef(-0.5, 0.25, 0);

glColor3ub(174,214,241);
glBegin(GL_LINES);
glVertex2f(-0.4,0.47);
glVertex2f(-0.35,0.28);
glEnd();

glColor3ub(174,214,241);
glBegin(GL_LINES);
glVertex2f(-0.4,0.47);
glVertex2f(-0.35,0.28);
glEnd();

glTranslatef(0.025,-0.5,0);

glLoadIdentity();
glPopMatrix();


glFlush();
}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void rain_loop(int val) {

 glutDisplayFunc(rain);

}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




void night()
{    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //white_background
    glClear(GL_COLOR_BUFFER_BIT);

//first_sky_layer
glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
glVertex2f( -1.0f, 1.0f );
glVertex2f( -1.0f, 0.0f );
glVertex2f( 1.0f, 0.0 );
glVertex2f( 1.0f, 1.0f );
glEnd();
glBegin(GL_QUADS);//layer
glColor3ub(0, 0, 51);
glVertex2f(-1, 0.9);
glVertex2f(-1, 0.8);
glVertex2f(1, 0.8);
glVertex2f(1, 0.9);
glEnd();

glBegin(GL_QUADS);//layer
glColor3ub(0, 0, 77);
glVertex2f(-1, 0.8);
glVertex2f(-1, 0.7);
glVertex2f(1, 0.7);
glVertex2f(1, 0.8);
glEnd();

glBegin(GL_QUADS);//layer
glColor3ub(0, 0, 102);
glVertex2f(-1, 0.7);
glVertex2f(-1, 0.6);
glVertex2f(1, 0.6);
glVertex2f(1, 0.7);
glEnd();


glBegin(GL_QUADS);//layer
glColor3ub(0, 0, 128);
glVertex2f(-1, 0.6);
glVertex2f(-1, 0.5);
glVertex2f(1, 0.5);
glVertex2f(1, 0.6);
glEnd();

glBegin(GL_QUADS);//layer
glColor3ub(0, 0, 153 );
glVertex2f(-1, 0.5);
glVertex2f(-1, 0.4);
glVertex2f(1, 0.4);
glVertex2f(1, 0.5);
glEnd();

glBegin(GL_QUADS);//layer
glColor3ub(0, 0, 179);
glVertex2f(-1, 0.4);
glVertex2f(-1, 0.05);
glVertex2f(1, 0.05);
glVertex2f(1, 0.4);
glEnd();

//stars
glBegin(GL_LINES); //stars
glColor3ub(255, 255, 255);
glVertex2f(-0.9, 0.895);
glVertex2f(-0.9, 0.885);
glVertex2f(-0.895, 0.89);
glVertex2f(-0.905, 0.89);
glEnd();
glTranslatef(0,-0.18, 0);
glBegin(GL_LINES); //stars
glVertex2f(-0.9, 0.895);
glVertex2f(-0.9, 0.885);
glVertex2f(-0.895, 0.89);
glVertex2f(-0.905, 0.89);
glEnd();
glTranslatef(0,-0.18, 0);
glBegin(GL_LINES); //stars
glVertex2f(-0.9, 0.895);
glVertex2f(-0.9, 0.885);
glVertex2f(-0.895, 0.89);
glVertex2f(-0.905, 0.89);
glEnd();
glLoadIdentity();


glBegin(GL_LINES); //stars
glColor3ub(255, 255, 255);
glVertex2f(-0.9, 0.895);
glVertex2f(-0.9, 0.885);
glVertex2f(-0.895, 0.89);
glVertex2f(-0.905, 0.89);
glEnd();
glTranslatef(0.18,0,0);
glBegin(GL_LINES); //stars
glVertex2f(-0.9, 0.895);
glVertex2f(-0.9, 0.885);
glVertex2f(-0.895, 0.89);
glVertex2f(-0.905, 0.89);
glEnd();
glTranslatef(0,-0.16,0);
glBegin(GL_LINES); //stars
glVertex2f(-0.9, 0.895);
glVertex2f(-0.9, 0.885);
glVertex2f(-0.895, 0.89);
glVertex2f(-0.905, 0.89);
glEnd();
glTranslatef(0.18,-0.18,0);
glBegin(GL_LINES); //stars
glVertex2f(-0.9, 0.895);
glVertex2f(-0.9, 0.885);
glVertex2f(-0.895, 0.89);
glVertex2f(-0.905, 0.89);
glEnd();
glTranslatef(0.15,-0.15,0);
glBegin(GL_LINES); //stars
glVertex2f(-0.9, 0.895);
glVertex2f(-0.9, 0.885);
glVertex2f(-0.895, 0.89);
glVertex2f(-0.905, 0.89);
glEnd();
glTranslatef(0,0.15,0);
glBegin(GL_LINES); //stars
glVertex2f(-0.9, 0.895);
glVertex2f(-0.9, 0.885);
glVertex2f(-0.895, 0.89);
glVertex2f(-0.905, 0.89);
glEnd();
glTranslatef(0.11,-0.11,0);
glBegin(GL_LINES); //stars
glVertex2f(-0.9, 0.895);
glVertex2f(-0.9, 0.885);
glVertex2f(-0.895, 0.89);
glVertex2f(-0.905, 0.89);
glEnd();
glTranslatef(0,0.11,0);
glBegin(GL_LINES); //stars
glVertex2f(-0.9, 0.895);
glVertex2f(-0.9, 0.885);
glVertex2f(-0.895, 0.89);
glVertex2f(-0.905, 0.89);
glEnd();
glTranslatef(0.18,0,0);
glBegin(GL_LINES); //stars
glVertex2f(-0.9, 0.895);
glVertex2f(-0.9, 0.885);
glVertex2f(-0.895, 0.89);
glVertex2f(-0.905, 0.89);
glEnd();
glLoadIdentity();

glBegin(GL_LINES); //stars
glColor3ub(255, 255, 255);
glVertex2f(-0.9, 0.895);
glVertex2f(-0.9, 0.885);
glVertex2f(-0.895, 0.89);
glVertex2f(-0.905, 0.89);
glEnd();
glTranslatef(0.36,-0.11,0);
glBegin(GL_LINES); //stars
glVertex2f(-0.9, 0.895);
glVertex2f(-0.9, 0.885);
glVertex2f(-0.895, 0.89);
glVertex2f(-0.905, 0.89);
glEnd();

glBegin(GL_LINES); //stars
glColor3ub(255, 255, 255);
glVertex2f(-0.9, 0.895);
glVertex2f(-0.9, 0.885);
glVertex2f(-0.895, 0.89);
glVertex2f(-0.905, 0.89);
glEnd();
glTranslatef(0.36,-0.11,0);
glBegin(GL_LINES); //stars
glVertex2f(-0.9, 0.895);
glVertex2f(-0.9, 0.885);
glVertex2f(-0.895, 0.89);
glVertex2f(-0.905, 0.89);
glEnd();

glLoadIdentity();

glBegin(GL_LINES); //stars
glColor3ub(255, 255, 255);
glVertex2f(-0.9, 0.895);
glVertex2f(-0.9, 0.885);
glVertex2f(-0.895, 0.89);
glVertex2f(-0.905, 0.89);
glEnd();
glTranslatef(0.55,0,0);
glBegin(GL_LINES); //stars
glVertex2f(-0.9, 0.895);
glVertex2f(-0.9, 0.885);
glVertex2f(-0.895, 0.89);
glVertex2f(-0.905, 0.89);
glEnd();
glTranslatef(0.66,0,0);
glBegin(GL_LINES); //stars
glVertex2f(-0.9, 0.895);
glVertex2f(-0.9, 0.885);
glVertex2f(-0.895, 0.89);
glVertex2f(-0.905, 0.89);
glEnd();
glTranslatef(0.66,-0.13,0);
glBegin(GL_LINES); //stars
glVertex2f(-0.9, 0.895);
glVertex2f(-0.9, 0.885);
glVertex2f(-0.895, 0.89);
glVertex2f(-0.905, 0.89);
glEnd();
glTranslatef(0.66,-0.13,0);
glBegin(GL_LINES); //stars
glVertex2f(-0.9, 0.895);
glVertex2f(-0.9, 0.885);
glVertex2f(-0.895, 0.89);
glVertex2f(-0.905, 0.89);
glEnd();
glTranslatef(0.89,0,0);
glBegin(GL_LINES); //stars
glVertex2f(-0.9, 0.895);
glVertex2f(-0.9, 0.885);
glVertex2f(-0.895, 0.89);
glVertex2f(-0.905, 0.89);
glEnd();
glTranslatef(0.89,0.15,0);
glBegin(GL_LINES); //stars
glVertex2f(-0.9, 0.895);
glVertex2f(-0.9, 0.885);
glVertex2f(-0.895, 0.89);
glVertex2f(-0.905, 0.89);
glEnd();
glBegin(GL_LINES); //stars
glColor3ub(255, 255, 255);
glVertex2f(-0.9, 0.895);
glVertex2f(-0.9, 0.885);
glVertex2f(-0.895, 0.89);
glVertex2f(-0.905, 0.89);
glEnd();
glLoadIdentity();

glBegin(GL_LINES); //stars
glColor3ub(255, 255, 255);
glVertex2f(-0.1, 0.94);
glVertex2f(-0.1, 0.93);
glVertex2f(-0.096, 0.935);
glVertex2f(-0.104, 0.935);
glEnd();
glTranslatef(-0.18,0, 0);
glBegin(GL_LINES); //stars
glVertex2f(-0.1, 0.94);
glVertex2f(-0.1, 0.93);
glVertex2f(-0.096, 0.935);
glVertex2f(-0.104, 0.935);
glEnd();
glTranslatef(0.18,0, 0);
glBegin(GL_LINES); //stars
glVertex2f(-0.1, 0.94);
glVertex2f(-0.1, 0.93);
glVertex2f(-0.096, 0.935);
glVertex2f(-0.104, 0.935);
glEnd();
glTranslatef(0.18,0, 0);
glBegin(GL_LINES); //stars
glVertex2f(-0.1, 0.94);
glVertex2f(-0.1, 0.93);
glVertex2f(-0.096, 0.935);
glVertex2f(-0.104, 0.935);
glEnd();
glTranslatef(0.18,0, 0);
glBegin(GL_LINES); //stars
glVertex2f(-0.1, 0.94);
glVertex2f(-0.1, 0.93);
glVertex2f(-0.096, 0.935);
glVertex2f(-0.104, 0.935);
glEnd();
glTranslatef(0.18,-0.11, 0);
glBegin(GL_LINES); //stars
glVertex2f(-0.1, 0.94);
glVertex2f(-0.1, 0.93);
glVertex2f(-0.096, 0.935);
glVertex2f(-0.104, 0.935);
glEnd();
glTranslatef(0.18,-0.11, 0);
glBegin(GL_LINES); //stars
glVertex2f(-0.1, 0.94);
glVertex2f(-0.1, 0.93);
glVertex2f(-0.096, 0.935);
glVertex2f(-0.104, 0.935);
glEnd();
glTranslatef(0.18,0, 0);
glBegin(GL_LINES); //stars
glVertex2f(-0.1, 0.94);
glVertex2f(-0.1, 0.93);
glVertex2f(-0.096, 0.935);
glVertex2f(-0.104, 0.935);
glEnd();
glLoadIdentity();
glBegin(GL_LINES); //stars
glColor3ub(255, 255, 255);
glVertex2f(-0.098, 0.762);
glVertex2f(-0.098, 0.752);
glVertex2f(-0.095, 0.757);
glVertex2f(-0.101, 0.757);
glEnd();
glTranslatef(0.18,0,0);
glBegin(GL_LINES); //stars
glVertex2f(-0.098, 0.762);
glVertex2f(-0.098, 0.752);
glVertex2f(-0.095, 0.757);
glVertex2f(-0.101, 0.757);
glEnd();
glTranslatef(0.18,0,0);
glBegin(GL_LINES); //stars
glVertex2f(-0.098, 0.762);
glVertex2f(-0.098, 0.752);
glVertex2f(-0.095, 0.757);
glVertex2f(-0.101, 0.757);
glEnd();
glTranslatef(0.18,0,0);
glBegin(GL_LINES); //stars
glVertex2f(-0.098, 0.762);
glVertex2f(-0.098, 0.752);
glVertex2f(-0.095, 0.757);
glVertex2f(-0.101, 0.757);
glEnd();
glTranslatef(0.18,0,0);
glBegin(GL_LINES); //stars
glVertex2f(-0.098, 0.762);
glVertex2f(-0.098, 0.752);
glVertex2f(-0.095, 0.757);
glVertex2f(-0.101, 0.757);
glEnd();

glLoadIdentity();

glBegin(GL_LINES); //stars
glColor3ub(255, 255, 255);
glVertex2f(-0.098, 0.762);
glVertex2f(-0.098, 0.752);
glVertex2f(-0.095, 0.757);
glVertex2f(-0.101, 0.757);
glEnd();
glTranslatef(0,0.18,0);
glBegin(GL_LINES); //stars
glVertex2f(-0.098, 0.762);
glVertex2f(-0.098, 0.752);
glVertex2f(-0.095, 0.757);
glVertex2f(-0.101, 0.757);
glEnd();
glTranslatef(0,0.18,0);
glBegin(GL_LINES); //stars
glVertex2f(-0.098, 0.762);
glVertex2f(-0.098, 0.752);
glVertex2f(-0.095, 0.757);
glVertex2f(-0.101, 0.757);
glEnd();
glTranslatef(0.18,0,0);
glBegin(GL_LINES); //stars
glVertex2f(-0.098, 0.762);
glVertex2f(-0.098, 0.752);
glVertex2f(-0.095, 0.757);
glVertex2f(-0.101, 0.757);
glEnd();

glLoadIdentity();

glBegin(GL_LINES); //stars
glColor3ub(255, 255, 255);
glVertex2f(0.1, 0.644);
glVertex2f(0.1, 0.636);
glVertex2f(0.102, 0.64);
glVertex2f(0.098, 0.64);
glEnd();
glTranslatef(0.18,0,0);
glBegin(GL_LINES); //stars
glVertex2f(0.1, 0.644);
glVertex2f(0.1, 0.636);
glVertex2f(0.102, 0.64);
glVertex2f(0.098, 0.64);
glEnd();

glTranslatef(0.18,0,0);
glBegin(GL_LINES); //stars
glVertex2f(0.1, 0.644);
glVertex2f(0.1, 0.636);
glVertex2f(0.102, 0.64);
glVertex2f(0.098, 0.64);
glEnd();

glTranslatef(0.18,0,0);
glBegin(GL_LINES); //stars
glVertex2f(0.1, 0.644);
glVertex2f(0.1, 0.636);
glVertex2f(0.102, 0.64);
glVertex2f(0.098, 0.64);
glEnd();

glTranslatef(0.18,0,0);
glBegin(GL_LINES); //stars
glVertex2f(0.1, 0.644);
glVertex2f(0.1, 0.636);
glVertex2f(0.102, 0.64);
glVertex2f(0.098, 0.64);
glEnd();


glTranslatef(0.18,0.5,0);
glBegin(GL_LINES); //stars
glVertex2f(0.1, 0.644);
glVertex2f(0.1, 0.636);
glVertex2f(0.102, 0.64);
glVertex2f(0.098, 0.64);
glEnd();
glTranslatef(0.18,0.5,0);
glBegin(GL_LINES); //stars
glVertex2f(0.1, 0.644);
glVertex2f(0.1, 0.636);
glVertex2f(0.102, 0.64);
glVertex2f(0.098, 0.64);
glEnd();
glTranslatef(0.18,0.5,0);
glBegin(GL_LINES); //stars
glVertex2f(0.1, 0.644);
glVertex2f(0.1, 0.636);
glVertex2f(0.102, 0.64);
glVertex2f(0.098, 0.64);
glEnd();
glLoadIdentity();


glBegin(GL_LINES); //stars
glColor3ub(255, 255, 255);
glVertex2f(0.25, 0.468);
glVertex2f(0.25, 0.452);
glVertex2f(0.254, 0.46);
glVertex2f(0.246, 0.46);
glEnd();
glTranslatef(0.15,0,0);
glBegin(GL_LINES); //stars
glVertex2f(0.25, 0.468);
glVertex2f(0.25, 0.452);
glVertex2f(0.254, 0.46);
glVertex2f(0.246, 0.46);
glEnd();
glTranslatef(0.15,0,0);
glBegin(GL_LINES); //stars
glVertex2f(0.25, 0.468);
glVertex2f(0.25, 0.452);
glVertex2f(0.254, 0.46);
glVertex2f(0.246, 0.46);
glEnd();
glTranslatef(0.15,0,0);
glBegin(GL_LINES); //stars
glVertex2f(0.25, 0.468);
glVertex2f(0.25, 0.452);
glVertex2f(0.254, 0.46);
glVertex2f(0.246, 0.46);
glEnd();
glTranslatef(0.15,0,0);
glBegin(GL_LINES); //stars
glVertex2f(0.25, 0.468);
glVertex2f(0.25, 0.452);
glVertex2f(0.254, 0.46);
glVertex2f(0.246, 0.46);
glEnd();
glLoadIdentity();


glBegin(GL_LINES); //stars
glColor3ub(255, 255, 255);
glVertex2f(0.65, 0.935);
glVertex2f(0.65, 0.92);
glVertex2f(0.656, 0.928);
glVertex2f(0.644, 0.928);
glEnd();
glTranslatef(0.16,0,0);
glBegin(GL_LINES); //stars
glVertex2f(0.65, 0.935);
glVertex2f(0.65, 0.92);
glVertex2f(0.656, 0.928);
glVertex2f(0.644, 0.928);
glEnd();
glTranslatef(0.16,0,0);
glBegin(GL_LINES); //stars
glVertex2f(0.65, 0.935);
glVertex2f(0.65, 0.92);
glVertex2f(0.656, 0.928);
glVertex2f(0.644, 0.928);
glEnd();
glTranslatef(0.16,0,0);
glBegin(GL_LINES); //stars
glVertex2f(0.65, 0.935);
glVertex2f(0.65, 0.92);
glVertex2f(0.656, 0.928);
glVertex2f(0.644, 0.928);
glEnd();
glTranslatef(0.16,0,0);
glBegin(GL_LINES); //stars
glVertex2f(0.65, 0.935);
glVertex2f(0.65, 0.92);
glVertex2f(0.656, 0.928);
glVertex2f(0.644, 0.928);
glEnd();
glTranslatef(0.16,0,0);
glBegin(GL_LINES); //stars
glVertex2f(0.65, 0.935);
glVertex2f(0.65, 0.92);
glVertex2f(0.656, 0.928);
glVertex2f(0.644, 0.928);
glEnd();
glLoadIdentity();



//moon
glPushMatrix();//animate sun
glTranslatef(position8,-position8,0);
int i;

 GLfloat x110=-0.01f; GLfloat y110= 0.81f; GLfloat radius110 =0.10f;
	int triangleAmount110 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi110 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(242, 242, 242); // sun
		glVertex2f(x110, y110); // center of circle
		for(i = 0; i <= triangleAmount110;i++) {
			glVertex2f(
		            x110 + (radius110* cos(i *  twicePi110 / triangleAmount110)),
			    y110 + (radius110 * sin(i * twicePi110 / triangleAmount110))
			);
		}
	glEnd();
//Moon End

//moon spot
glBegin(GL_POLYGON);
glColor3ub(224, 224, 210);
glVertex2f(-0.02, 0.815);
glVertex2f(-0.022, 0.812);
glVertex2f(-0.022, 0.808 );
glVertex2f( -0.018, 0.804);
glColor3ub(224, 224, 210);
glVertex2f(-0.02, 0.802);
glVertex2f(-0.014, 0.806);
glVertex2f(-0.016, 0.812);
glVertex2f( -0.016, 0.816);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(224, 224, 210);
glVertex2f(-0.04, 0.85);
glVertex2f(-0.04, 0.84);
glVertex2f(-0.06, 0.82);
glVertex2f(-0.05, 0.81);
glVertex2f(-0.05, 0.8);
glVertex2f(-0.04, 0.79);
glVertex2f(-0.04, 0.78);
glVertex2f(-0.03, 0.8);
glVertex2f( -0.02, 0.84);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(224, 224, 210);
glVertex2f(-0.03, 0.862);
glVertex2f(-0.021, 0.864);
glVertex2f(-0.005, 0.856);
glVertex2f(-0.002, 0.846);
glVertex2f(0.012, 0.825);
glVertex2f(0.008, 0.842);
glVertex2f(0.004, 0.852);
glVertex2f(0.005, 0.862);
glVertex2f(-0.013, 0.864);
glVertex2f(-0.022, 0.872);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(224, 224, 210);
glVertex2f(0.014, 0.805);
glVertex2f(0.0005, 0.792);
glVertex2f(0.002, 0.78);
glVertex2f(-0.005, 0.775);
glVertex2f(0.01, 0.765);
glVertex2f(0.022, 0.772);
glVertex2f(0.02, 0.785);
glVertex2f(0.015, 0.79);
glVertex2f(0.014, 0.805);

glEnd();
glBegin(GL_POLYGON);
glColor3ub(224, 224, 210);
glVertex2f(0.04, 0.84);
glVertex2f(0.05, 0.84);
glVertex2f(0.036, 0.855);
glVertex2f(0.026, 0.846);
glVertex2f(0.025, 0.82);
glVertex2f(0.01, 0.81);
glVertex2f(0.035, 0.8);
glVertex2f(0.035, 0.83);
glVertex2f(0.04, 0.84);

glEnd();
glBegin(GL_POLYGON);
glColor3ub(224, 224, 210);
glVertex2f(-0.05, 0.75);
glVertex2f(-0.05, 0.75);
glVertex2f(-0.035, 0.73);
glVertex2f(0.01, 0.75);
glVertex2f(-0.015, 0.76);
glVertex2f(-0.035, 0.75);
glVertex2f(-0.045, 0.75);
glVertex2f(-0.05, 0.75);
glEnd();
glBegin(GL_QUADS);
glColor3ub(224, 224, 210);
glVertex2f(-0.032, 0.775);
glVertex2f(-0.028, 0.765);
glVertex2f(-0.022, 0.765);
glVertex2f(-0.025, 0.78);

glEnd();
glBegin(GL_QUADS);
glColor3ub(224, 224, 210);
glVertex2f(0.028, 0.785);
glVertex2f(0.03, 0.77);
glVertex2f(0.034, 0.78);
glVertex2f(0.034, 0.79);
glEnd();
glBegin(GL_QUADS);
glColor3ub(224, 224, 210);
glVertex2f(-0.068, 0.856);
glVertex2f(-0.07, 0.84);
glVertex2f(-0.062, 0.848);
glVertex2f(-0.058, 0.86);
glEnd();
glBegin(GL_QUADS);
glColor3ub(224, 224, 210);
glVertex2f(-0.07, 0.8);
glVertex2f(-0.066, 0.785);
glVertex2f(-0.056, 0.78);
glVertex2f(-0.056, 0.795);
glEnd();
glBegin(GL_QUADS);
glColor3ub(224, 224, 210);
glVertex2f(-0.008, 0.835);
glVertex2f(-0.01, 0.82);
glVertex2f(-0.002, 0.825);
glVertex2f(0, 0.84);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(224, 224, 210);
glVertex2f(0.06, 0.82);
glVertex2f(0.05, 0.81);
glVertex2f(0.045, 0.8);
glVertex2f(0.045, 0.78);
glVertex2f(0.04, 0.77);
glVertex2f(0.03, 0.76);
glVertex2f(0.045, 0.76);
glVertex2f(0.05, 0.79);
glVertex2f(0.065, 0.81);
glEnd();
glPopMatrix();

//Building_1
glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f( -1.0, 0.34 );
glVertex2f( -1.0, 0.1 );
glVertex2f( -0.925, 0.1 );
glVertex2f( -0.925, 0.34 );
glEnd();
glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f(-0.925, 0.43 );
glVertex2f( -0.925, 0.1 );
glVertex2f( -0.855, 0.1 );
glVertex2f( -0.855, 0.43 );
glEnd();
glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f(-0.844, 0.34 );
glVertex2f( -0.844, 0.1 );
glVertex2f(-0.779, 0.1 );
glVertex2f( -0.779, 0.34 );
glEnd();
glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f(-0.709, 0.474);
glVertex2f( -0.709, 0.1 );
glVertex2f(-0.55, 0.1 );
glVertex2f( -0.55, 0.44 );
glEnd();
glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f(-0.53, 0.418);
glVertex2f( -0.53, 0.1 );
glVertex2f(-0.504, 0.1 );
glVertex2f( -0.504, 0.418);
glEnd();
glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f(-0.504, 0.476);
glVertex2f( -0.504, 0.1 );
glVertex2f(-0.476, 0.1 );
glVertex2f( -0.476, 0.476);
glEnd();
glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f(-0.476, 0.458);
glVertex2f( -0.476, 0.1 );
glVertex2f(-0.442, 0.1 );
glVertex2f( -0.442, 0.458);
glEnd();
glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f(-0.442, 0.505);
glVertex2f( -0.442, 0.1 );
glVertex2f(-0.358, 0.1 );
glVertex2f( -0.358, 0.505);
glEnd();
glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f(-0.358, 0.458);
glVertex2f( -0.358, 0.1 );
glVertex2f(-0.327, 0.1 );
glVertex2f( -0.327, 0.458);
glEnd();
glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f(-0.327, 0.49);
glVertex2f( -0.327, 0.1 );
glVertex2f(-0.2935, 0.1 );
glVertex2f( -0.2935, 0.49);
glEnd();
glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f(-0.2935, 0.42);
glVertex2f( -0.2935, 0.1 );
glVertex2f(-0.256, 0.1 );
glVertex2f( -0.256, 0.42);
glEnd();
glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f(-0.256, 0.515);
glVertex2f( -0.256, 0.1 );
glVertex2f(-0.244, 0.1 );
glVertex2f(-0.244, 0.515);
glEnd();
glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f(-0.244, 0.534);
glVertex2f( -0.244, 0.1 );
glVertex2f(-0.236, 0.1 );
glVertex2f(-0.236, 0.534);
glEnd();
glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f(-0.236, 0.568);
glVertex2f( -0.236, 0.1 );
glVertex2f(-0.224, 0.1 );
glVertex2f(-0.224, 0.568);
glEnd();
glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f(-0.224, 0.592);
glVertex2f( -0.224, 0.1 );
glVertex2f(-0.171, 0.1 );
glVertex2f(-0.171, 0.592);
glEnd();
glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f(-0.171, 0.568);
glVertex2f( -0.171, 0.1 );
glVertex2f(-0.155, 0.1 );
glVertex2f(-0.155, 0.568);
glEnd();
glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f(-0.155, 0.534);
glVertex2f( -0.155, 0.1 );
glVertex2f(-0.141, 0.1 );
glVertex2f(-0.141, 0.534);
glEnd();
glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f(-0.155, 0.534);
glVertex2f( -0.155, 0.1 );
glVertex2f(-0.141, 0.1 );
glVertex2f(-0.141, 0.534);
glEnd();
glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f(-0.141, 0.515);
glVertex2f( -0.141, 0.1 );
glVertex2f(-0.128, 0.1 );
glVertex2f(-0.128, 0.515);
glEnd();
glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f(-0.128, 0.42);
glVertex2f( -0.128, 0.1 );
glVertex2f(-0.12, 0.1 );
glVertex2f(-0.12, 0.42);
glEnd();
glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f(-0.12, 0.49);
glVertex2f( -0.12, 0.1 );
glVertex2f(0.008, 0.1 );
glVertex2f(0.008, 0.49);
glEnd();
glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f(0.008, 0.55);
glVertex2f( 0.008, 0.1 );
glVertex2f(0.098, 0.1 );
glVertex2f(0.098, 0.55);
glEnd();
glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f(0.098, 0.295);
glVertex2f( 0.098, 0.1 );
glVertex2f(0.116, 0.1 );
glVertex2f(0.116, 0.295);
glEnd();
glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f(0.195, 0.39);
glVertex2f( 0.195, 0.1 );
glVertex2f(0.245, 0.1 );
glVertex2f(0.245, 0.358);
glEnd();
glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f(0.245, 0.301);
glVertex2f( 0.245, 0.1 );
glVertex2f(0.26, 0.1 );
glVertex2f(0.26, 0.301);
glEnd();
glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f(0.26, 0.445);
glVertex2f( 0.26, 0.1 );
glVertex2f(0.37, 0.1 );
glVertex2f(0.37, 0.445);
glEnd();

glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f(0.39, 0.4);
glVertex2f( 0.39, 0.1 );
glVertex2f(0.45, 0.1 );
glVertex2f(0.45, 0.4);
glEnd();
glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f(0.45, 0.35);
glVertex2f( 0.45, 0.1 );
glVertex2f(0.495, 0.1 );
glVertex2f(0.495, 0.35);
glEnd();
glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f(0.495, 0.26);
glVertex2f( 0.495, 0.1 );
glVertex2f(0.662, 0.1 );
glVertex2f(0.662, 0.26);
glEnd();
glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f(0.662, 0.36);
glVertex2f( 0.662, 0.1 );
glVertex2f(0.854, 0.1 );
glVertex2f(0.854, 0.36);
glEnd();
glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f(0.854, 0.32);
glVertex2f( 0.854, 0.1 );
glVertex2f(0.894, 0.1 );
glVertex2f(0.894, 0.32);
glEnd();
glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f(0.894, 0.345);
glVertex2f( 0.894, 0.1 );
glVertex2f(0.922, 0.1 );
glVertex2f(0.922, 0.345);
glEnd();
glBegin(GL_QUADS);
glColor3ub(37, 121, 142);
glVertex2f(0.922, 0.32);
glVertex2f( 0.922, 0.1 );
glVertex2f(1.0, 0.1 );
glVertex2f(1.0, 0.32);
glEnd();

//Building_2
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(-1.0, 0.212);
glVertex2f( -1.0, -0.05 );
glVertex2f(-0.993, -0.05 );
glVertex2f(-0.993, 0.212);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(-0.993, 0.28);
glVertex2f( -0.993, -0.05 );
glVertex2f(-0.94, -0.05 );
glVertex2f(-0.94, 0.28);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(-0.94, 0.1);
glVertex2f( -0.94, -0.05 );
glVertex2f(-0.932, -0.05 );
glVertex2f(-0.932, 0.1);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(-0.932, 0.212);
glVertex2f( -0.932, -0.05 );
glVertex2f(-0.894, -0.05 );
glVertex2f(-0.894, 0.212);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(-0.894, 0.168);
glVertex2f( -0.894, -0.05 );
glVertex2f(-0.83, -0.05 );
glVertex2f(-0.83, 0.168);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(-0.83, 0.316);
glVertex2f( -0.83, -0.05 );
glVertex2f(-0.708, -0.05 );
glVertex2f(-0.708, 0.284);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(-0.708, 0.1);
glVertex2f( -0.708, -0.05 );
glVertex2f(-0.688, -0.05 );
glVertex2f(-0.688, 0.1);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(-0.688, 0.27);
glVertex2f( -0.688, -0.05 );
glVertex2f(-0.674, -0.05 );
glVertex2f(-0.674, 0.27);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(-0.674, 0.315);
glVertex2f( -0.674, -0.05 );
glVertex2f(-0.656, -0.05 );
glVertex2f(-0.656, 0.315);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(-0.656, 0.3);
glVertex2f( -0.656, -0.05 );
glVertex2f(-0.63, -0.05 );
glVertex2f(-0.63, 0.3);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(-0.63, 0.335);
glVertex2f( -0.63, -0.05 );
glVertex2f(-0.568, -0.05 );
glVertex2f(-0.568, 0.335);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(-0.568, 0.3);
glVertex2f( -0.568, -0.05 );
glVertex2f(-0.544, -0.05 );
glVertex2f(-0.544, 0.3);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(-0.544, 0.325);
glVertex2f( -0.544, -0.05 );
glVertex2f(-0.52, -0.05 );
glVertex2f(-0.52, 0.325);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(-0.52, 0.27);
glVertex2f( -0.52, -0.05 );
glVertex2f(-0.49, -0.05 );
glVertex2f(-0.49, 0.27);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(-0.49, 0.34);
glVertex2f( -0.49, -0.05 );
glVertex2f(-0.482, -0.05 );
glVertex2f(-0.482, 0.34);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(-0.482, 0.36);
glVertex2f( -0.482, -0.05 );
glVertex2f(-0.476, -0.05 );
glVertex2f(-0.476, 0.36);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(-0.476, 0.38);
glVertex2f( -0.476, -0.05 );
glVertex2f(-0.464, -0.05 );
glVertex2f(-0.464, 0.38);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(-0.464, 0.41);
glVertex2f( -0.464, -0.05 );
glVertex2f(-0.426, -0.05 );
glVertex2f(-0.426, 0.41);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(-0.426, 0.38);
glVertex2f( -0.426, -0.05 );
glVertex2f(-0.414, -0.05 );
glVertex2f(-0.414, 0.38);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(-0.414, 0.36);
glVertex2f( -0.414, -0.05 );
glVertex2f(-0.402, -0.05 );
glVertex2f(-0.402, 0.36);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(-0.402, 0.34);
glVertex2f( -0.402, -0.05 );
glVertex2f(-0.396, -0.05 );
glVertex2f(-0.396, 0.34);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(-0.396, 0.27);
glVertex2f( -0.396, -0.05 );
glVertex2f(-0.388, -0.05 );
glVertex2f(-0.388, 0.27);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(-0.388, 0.33);
glVertex2f( -0.388, -0.05 );
glVertex2f(-0.292, -0.05 );
glVertex2f(-0.292, 0.33);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(-0.292, 0.37);
glVertex2f( -0.292, -0.05 );
glVertex2f(-0.224, -0.05 );
glVertex2f(-0.224, 0.37);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(-0.224, 0.15);
glVertex2f( -0.224, -0.05 );
glVertex2f(-0.21, -0.05 );
glVertex2f(-0.21, 0.15);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(-0.21, 0.32);
glVertex2f( -0.21, -0.05 );
glVertex2f(-0.164, -0.05 );
glVertex2f(-0.164, 0.34);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(-0.164, 0.182);
glVertex2f( -0.164, -0.05 );
glVertex2f(-0.152, -0.05 );
glVertex2f(-0.152, 0.182);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(-0.152, 0.25);
glVertex2f( -0.152, -0.05 );
glVertex2f(-0.114, -0.05 );
glVertex2f(-0.114, 0.225);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(-0.114, 0.164);
glVertex2f( -0.114, -0.05 );
glVertex2f(-0.10, -0.05 );
glVertex2f(-0.10, 0.164);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(-0.10, 0.287);
glVertex2f( -0.10, -0.05 );
glVertex2f(-0.019, -0.05 );
glVertex2f(-0.019, 0.287);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(-0.019, 0.151);
glVertex2f( -0.10, -0.05 );
glVertex2f(-0.006, -0.05 );
glVertex2f(-0.006, 0.151);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(-0.006, 0.255);
glVertex2f( -0.006, -0.05 );
glVertex2f(0.038, -0.05 );
glVertex2f(0.038, 0.255);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(0.038, 0.15);
glVertex2f(0.038, -0.05 );
glVertex2f(0.053, -0.05 );
glVertex2f(0.053, 0.15);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(0.053, 0.232);
glVertex2f(0.053, -0.05 );
glVertex2f(0.073, -0.05 );
glVertex2f(0.073, 0.21);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(0.073, 0.15);
glVertex2f(0.073, -0.05 );
glVertex2f(0.093, -0.05 );
glVertex2f(0.093, 0.15);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(0.093, 0.323);
glVertex2f(0.093, -0.05 );
glVertex2f(0.105, -0.05 );
glVertex2f(0.105, 0.31);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(0.105, 0.261);
glVertex2f(0.105, -0.05 );
glVertex2f(0.116, -0.05 );
glVertex2f(0.116, 0.261);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(0.116, 0.288);
glVertex2f(0.116, -0.05 );
glVertex2f(0.188, -0.05 );
glVertex2f(0.188, 0.288);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(0.188, 0.25);
glVertex2f(0.188, -0.05 );
glVertex2f(0.21, -0.05 );
glVertex2f(0.21, 0.25);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(0.21, 0.23);
glVertex2f(0.21, -0.05 );
glVertex2f(0.224, -0.05 );
glVertex2f(0.224, 0.23);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(0.224, 0.245);
glVertex2f(0.224, -0.05 );
glVertex2f(0.237, -0.05 );
glVertex2f(0.237, 0.245);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(0.237, 0.19);
glVertex2f(0.237, -0.05 );
glVertex2f(0.28, -0.05 );
glVertex2f(0.28, 0.19);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(0.28, 0.35);
glVertex2f(0.28, -0.05 );
glVertex2f(0.37, -0.05 );
glVertex2f(0.37, 0.35);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(0.37, 0.28);
glVertex2f(0.37, -0.05 );
glVertex2f(0.447, -0.05 );
glVertex2f(0.447, 0.28);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(0.447, 0.194);
glVertex2f(0.447, -0.05 );
glVertex2f(0.472, -0.05 );
glVertex2f(0.472, 0.194);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(0.472, 0.21);
glVertex2f(0.472, -0.05 );
glVertex2f(0.494, -0.05 );
glVertex2f(0.494, 0.21);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(0.494, 0.191);
glVertex2f(0.494, -0.05 );
glVertex2f(0.512, -0.05 );
glVertex2f(0.512, 0.191);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(0.512, 0.22);
glVertex2f(0.512, -0.05 );
glVertex2f(0.56, -0.05 );
glVertex2f(0.56, 0.22);
glEnd();

glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(0.56, 0.24);
glVertex2f(0.56, -0.05 );
glVertex2f(0.59, -0.05 );
glVertex2f(0.59, 0.24);
glEnd();

glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(0.59, 0.18);
glVertex2f(0.59, -0.05 );
glVertex2f(0.63, -0.05 );
glVertex2f(0.63, 0.18);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(0.63, 0.25);
glVertex2f(0.63, -0.05 );
glVertex2f(0.69, -0.05 );
glVertex2f(0.69, 0.25);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(0.69, 0.22);
glVertex2f(0.69, -0.05 );
glVertex2f(0.72, -0.05 );
glVertex2f(0.72, 0.22);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(0.72, 0.2);
glVertex2f(0.72, -0.05 );
glVertex2f(0.75, -0.05 );
glVertex2f(0.75, 0.2);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(0.75, 0.18);
glVertex2f(0.75, -0.05 );
glVertex2f(0.78, -0.05 );
glVertex2f(0.78, 0.18);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(0.78, 0.15);
glVertex2f(0.78, -0.05 );
glVertex2f(0.81, -0.05 );
glVertex2f(0.81, 0.15);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(0.81, 0.25);
glVertex2f(0.81, -0.05 );
glVertex2f(0.83, -0.05 );
glVertex2f(0.83, 0.25);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(0.83, 0.22);
glVertex2f(0.83, -0.05 );
glVertex2f(0.86, -0.05 );
glVertex2f(0.86, 0.22);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(0.86, 0.26);
glVertex2f(0.86, -0.05 );
glVertex2f(0.89, -0.05 );
glVertex2f(0.89, 0.26);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(0.89, 0.17);
glVertex2f(0.89, -0.05 );
glVertex2f(0.93, -0.05 );
glVertex2f(0.93, 0.17);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(0.93, 0.23);
glVertex2f(0.93, -0.05 );
glVertex2f(0.96, -0.05 );
glVertex2f(0.96, 0.19);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(0.96, 0.16);
glVertex2f(0.96, -0.05 );
glVertex2f(0.98, -0.05 );
glVertex2f(0.98, 0.16);
glEnd();
glBegin(GL_QUADS);
glColor3ub(26, 86, 101);
glVertex2f(0.98, 0.3);
glVertex2f(0.98, -0.05 );
glVertex2f(1.0, -0.05 );
glVertex2f(1.0, 0.3);
glEnd();
//building 2 end

glBegin(GL_QUADS); //back sea 1
glColor3ub(32, 111, 172);
glVertex2f(1, -0.05);
glVertex2f(1, -0.15 );
glVertex2f(-1, -0.15 );
glVertex2f(-1, -0.05);
glEnd();


glPushMatrix();
glTranslatef(position3,0,0);
glBegin(GL_TRIANGLES); //back sea 1 waves left to right 1
glColor3ub(32, 111, 172);
glVertex2f(1, -0.05);
glVertex2f(0.88, -0.03);
glVertex2f(0.7, -0.05 );
glEnd();

glBegin(GL_TRIANGLES); //back sea 1 waves left to right 2
glColor3ub(32, 111, 172);
glVertex2f(0.25, -0.05);
glVertex2f(0.52, -0.03);
glVertex2f(0.7, -0.05 );
glEnd();

glBegin(GL_TRIANGLES); //back sea 1 waves left to right 3
glColor3ub(32, 111, 172);
glVertex2f(0.25, -0.05);
glVertex2f(-0.02, -0.03);
glVertex2f(-0.3, -0.05 );
glEnd();

glBegin(GL_TRIANGLES); //back sea 1 waves left to right 4
glColor3ub(32, 111, 172);
glVertex2f(-0.85, -0.05);
glVertex2f(-0.6, -0.03);
glVertex2f(-0.3, -0.05 );
glEnd();

glBegin(GL_TRIANGLES); //back sea 1 waves left to right 5
glColor3ub(32, 111, 172);
glVertex2f(-0.82, -0.05);
glVertex2f(-1, -0.05);
glVertex2f(-0.92, -0.03);
glEnd();
glPopMatrix();


glBegin(GL_QUADS); //back sea 2
glColor3ub(28, 129, 176);
glVertex2f(1, -0.15);
glVertex2f(1, -0.22);
glVertex2f(-1, -0.22 );
glVertex2f(-1, -0.15);
glEnd();

glPushMatrix();
glTranslatef(position4,0,0);
glBegin(GL_TRIANGLES); //back sea 2 waves left to right 1
glColor3ub(28, 129, 176);
glVertex2f(1, -0.15);
glVertex2f(0.88, -0.13);
glVertex2f(0.7, -0.15 );
glEnd();

glBegin(GL_TRIANGLES); //back sea 2 waves left to right 2
glColor3ub(28, 129, 176);
glVertex2f(0.2, -0.15);
glVertex2f(0.52, -0.13);
glVertex2f(0.7, -0.15 );
glEnd();

glBegin(GL_TRIANGLES); //back sea 2 waves left to right 3
glColor3ub(28, 129, 176);
glVertex2f(0.25, -0.15);
glVertex2f(-0.02, -0.13);
glVertex2f(-0.3, -0.15 );
glEnd();

glBegin(GL_TRIANGLES); //back sea 2 waves left to right 4
glColor3ub(28, 129, 176);
glVertex2f(-0.38, -0.13);
glVertex2f(-0.38, -0.15);
glVertex2f(-0.3, -0.15 );
glEnd();

glBegin(GL_TRIANGLES); //back sea 2 waves left to right 5
glColor3ub(28, 129, 176);
glVertex2f(-0.38, -0.15);
glVertex2f(-0.38, -0.13);
glVertex2f(-0.58, -0.15);
glEnd();

glBegin(GL_TRIANGLES); //back sea 2 waves left to right 6
glColor3ub(28, 129, 176);
glVertex2f(-0.58, -0.15);
glVertex2f(-0.72, -0.13);
glVertex2f(-0.88, -0.15);
glEnd();

glBegin(GL_TRIANGLES); //back sea 2 waves left to right 6
glColor3ub(28, 129, 176);
glVertex2f(-1, -0.15);
glVertex2f(-0.94, -0.13);
glVertex2f(-0.88, -0.15);
glEnd();

glPopMatrix();


glBegin(GL_QUADS); //Middle port
glColor3ub(131, 125, 124);
glVertex2f(1, -0.22);
glVertex2f(1, -0.38);
glVertex2f(-1, -0.38);
glVertex2f(-1, -0.22);
glEnd();

glBegin(GL_QUADS);//front port
glColor3ub(131, 125, 124);
glVertex2f(-1, -0.58);
glVertex2f(-1, -1);
glVertex2f(1, -1);
glVertex2f(1, -0.58);
glEnd();

//Back Ship Start

glPushMatrix();
glTranslatef(position51,0,0);//animate ship

glBegin(GL_QUADS); //Cabin
glColor3ub(203, 205, 204);
glVertex2f(-0.66, -0.088);
glVertex2f(-0.79, -0.088 );
glVertex2f(-0.79, -0.17 );
glVertex2f(-0.66, -0.17);
glEnd();

glBegin(GL_QUADS); //Cabin middle line
glColor3ub(127, 128, 127);
glVertex2f(-0.66, -0.125);
glVertex2f(-0.79, -0.125 );
glVertex2f(-0.79, -0.13 );
glVertex2f(-0.66, -0.13);
glEnd();

glBegin(GL_QUADS); //Cabin middle line 2
glColor3ub(127, 128, 127);
glVertex2f(-0.695, -0.084);
glVertex2f(-0.79, -0.084 );
glVertex2f(-0.79, -0.088 );
glVertex2f(-0.695, -0.088);
glEnd();

glBegin(GL_QUADS); //Cabin upper
glColor3ub(203, 205, 204);
glVertex2f(-0.695, -0.025);
glVertex2f(-0.79, -0.025 );
glVertex2f(-0.79, -0.084 );
glVertex2f(-0.695, -0.084);
glEnd();

glBegin(GL_QUADS); //Cabin Cabin middle line 3
glColor3ub(127, 128, 127);
glVertex2f(-0.695, -0.025);
glVertex2f(-0.79, -0.025 );
glVertex2f(-0.79, -0.02 );
glVertex2f(-0.695, -0.02);
glEnd();

glBegin(GL_QUADS); //cabin upper
glColor3ub(203, 205, 204);
glVertex2f(-0.695, -0.02);
glVertex2f(-0.79, -0.02 );
glVertex2f(-0.79, 0.008 );
glVertex2f(-0.684, 0.008);
glEnd();


glBegin(GL_QUADS); //cabin middle 4
glColor3ub(131, 128, 135);
glVertex2f(-0.73, 0.01);
glVertex2f(-0.778, 0.01);
glVertex2f(-0.778, 0.008 );
glVertex2f(-0.73, 0.008);
glEnd();


glBegin(GL_QUADS); //cabin upper
glColor3ub(203, 205, 204);
glVertex2f(-0.73, 0.01);
glVertex2f(-0.778, 0.01);
glVertex2f(-0.778, 0.03 );
glVertex2f(-0.73, 0.03);
glEnd();


glBegin(GL_QUADS); //cabin flag rod
glColor3ub(203, 205, 204);
glVertex2f(-0.75, 0.03);
glVertex2f(-0.754, 0.03);
glVertex2f(-0.754, 0.078 );
glVertex2f(-0.75, 0.078);
glEnd();

glBegin(GL_QUADS); //cabin flag
glColor3ub(46, 184, 46);
glVertex2f(-0.754, 0.074);
glVertex2f(-0.778, 0.074);
glVertex2f(-0.778, 0.054 );
glVertex2f(-0.754, 0.054);
glEnd();

glBegin(GL_LINES); //cabin flag
glColor3ub(0, 179, 60);
glVertex2f(-0.754, 0.074);
glVertex2f(-0.778, 0.074);
glVertex2f(-0.778, 0.074);
glVertex2f(-0.778, 0.054 );
glVertex2f(-0.778, 0.054 );
glVertex2f(-0.754, 0.054);
glVertex2f(-0.754, 0.054);
glVertex2f(-0.754, 0.074);
glEnd();


    GLfloat x=-.766f; GLfloat y=.064f; GLfloat radius =0.006f;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 0, 0); // flag circle
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


glBegin(GL_QUADS); //top windows 1
glColor3ub(204, 204, 0);
glVertex2f(-0.691, 0.004);
glVertex2f(-0.71, 0.004 );
glVertex2f(-0.71, -0.014 );
glVertex2f(-0.698, -0.014);
glEnd();

glBegin(GL_QUADS); //top windows 2
glColor3ub(204, 204, 0);
glVertex2f(-0.715, 0.004);
glVertex2f(-0.73, 0.004 );
glVertex2f(-0.73, -0.014 );
glVertex2f(-0.715, -0.014);
glEnd();

glBegin(GL_QUADS); //top windows 3
glColor3ub(204, 204, 0);
glVertex2f(-0.735, 0.004);
glVertex2f(-0.75, 0.004 );
glVertex2f(-0.75, -0.014 );
glVertex2f(-0.735, -0.014);
glEnd();

glBegin(GL_QUADS); //top windows 4
glColor3ub(204, 204, 0);
glVertex2f(-0.755, 0.004);
glVertex2f(-0.77, 0.004 );
glVertex2f(-0.77, -0.014 );
glVertex2f(-0.755, -0.014);
glEnd();

glBegin(GL_QUADS); //top windows 5
glColor3ub(204, 204, 0);
glVertex2f(-0.774, 0.004);
glVertex2f(-0.788, 0.004 );
glVertex2f(-0.788, -0.014 );
glVertex2f(-0.774, -0.014);
glEnd();

glBegin(GL_QUADS); //middle windows 1
glColor3ub(204, 204, 0);
glVertex2f(-0.7, -0.03);
glVertex2f(-0.71, -0.03 );
glVertex2f(-0.71, -0.045 );
glVertex2f(-0.7, -0.045);
glEnd();

glBegin(GL_QUADS); //middle windows 2
glColor3ub(204, 204, 0);
glVertex2f(-0.715, -0.03);
glVertex2f(-0.725, -0.03 );
glVertex2f(-0.725, -0.045 );
glVertex2f(-0.715, -0.045);
glEnd();

glBegin(GL_QUADS); //middle windows 3
glColor3ub(204, 204, 0);
glVertex2f(-0.735, -0.03);
glVertex2f(-0.75, -0.03 );
glVertex2f(-0.75, -0.045 );
glVertex2f(-0.735, -0.045);
glEnd();

glBegin(GL_QUADS); //middle windows 4
glColor3ub(204, 204, 0);
glVertex2f(-0.76, -0.03);
glVertex2f(-0.77, -0.03 );
glVertex2f(-0.77, -0.045 );
glVertex2f(-0.76, -0.045);
glEnd();

glBegin(GL_QUADS); //middle windows 5
glColor3ub(204, 204, 0);
glVertex2f(-0.775, -0.03);
glVertex2f(-0.785, -0.03 );
glVertex2f(-0.785, -0.045 );
glVertex2f(-0.775, -0.045);
glEnd();

glBegin(GL_QUADS); //middle windows 6
glColor3ub(204, 204, 0);
glVertex2f(-0.7, -0.055);
glVertex2f(-0.71,-0.055 );
glVertex2f(-0.71, -0.07 );
glVertex2f(-0.7, -0.07);
glEnd();

glBegin(GL_QUADS); //middle windows 7
glColor3ub(204, 204, 0);
glVertex2f(-0.715, -0.055);
glVertex2f(-0.725, -0.055 );
glVertex2f(-0.725, -0.07 );
glVertex2f(-0.715, -0.07);
glEnd();

glBegin(GL_QUADS); //middle windows 8
glColor3ub(204, 204, 0);
glVertex2f(-0.735, -0.055);
glVertex2f(-0.75,-0.055 );
glVertex2f(-0.75, -0.07 );
glVertex2f(-0.735, -0.07);
glEnd();

glBegin(GL_QUADS); //middle windows 9
glColor3ub(204, 204, 0);
glVertex2f(-0.76, -0.055);
glVertex2f(-0.77, -0.055 );
glVertex2f(-0.77,-0.07 );
glVertex2f(-0.76, -0.07);
glEnd();

glBegin(GL_QUADS); //middle windows 10
glColor3ub(204, 204, 0);
glVertex2f(-0.775, -0.055);
glVertex2f(-0.785,-0.055 );
glVertex2f(-0.785, -0.07 );
glVertex2f(-0.775, -0.07);
glEnd();


   GLfloat x1=-.68f; GLfloat y1=-.15f; GLfloat radius1 =0.009f;
	int triangleAmount1 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 204, 0); // lower windows 1
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= triangleAmount1;i++) {
			glVertex2f(
		            x1 + (radius1 * cos(i *  twicePi1 / triangleAmount1)),
			    y1 + (radius1 * sin(i * twicePi1 / triangleAmount1))
			);
		}
	glEnd();

	   GLfloat x2=-.7f; GLfloat y2=-.15f; GLfloat radius2 =0.009f;
	int triangleAmount2 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi2 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 204, 0); // lower windows 1
		glVertex2f(x2, y2); // center of circle
		for(i = 0; i <= triangleAmount2;i++) {
			glVertex2f(
		            x2 + (radius2 * cos(i *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i * twicePi2 / triangleAmount2))
			);
		}
	glEnd();


	   GLfloat x3=-.72f; GLfloat y3=-.15f; GLfloat radius3 =0.009f;
	int triangleAmount3 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi3 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 204, 0); // lower windows 1
		glVertex2f(x3, y3); // center of circle
		for(i = 0; i <= triangleAmount3;i++) {
			glVertex2f(
		            x3 + (radius3 * cos(i *  twicePi3 / triangleAmount3)),
			    y3 + (radius3 * sin(i * twicePi3 / triangleAmount3))
			);
		}
	glEnd();


glBegin(GL_QUADS); //cargo
glColor3ub(53, 77, 156);
glVertex2f(-0.545, -0.135);
glVertex2f(-0.615,-0.135 );
glVertex2f(-0.615, -0.176 );
glVertex2f(-0.545, -0.175);
glEnd();

glBegin(GL_LINES); //cargo
glColor3ub(-22, 42, 119);
glVertex2f(-0.545, -0.135);
glVertex2f(-0.615,-0.135 );

glVertex2f(-0.615,-0.135 );
glVertex2f(-0.615, -0.176 );

glVertex2f(-0.615, -0.176 );
glVertex2f(-0.545, -0.175);

glVertex2f(-0.545, -0.175);
glVertex2f(-0.545, -0.135);

glEnd();

glBegin(GL_QUADS); //cargo
glColor3ub(93, 144, 144);
glVertex2f(-0.47, -0.135);
glVertex2f(-0.54,-0.135 );
glVertex2f(-0.54, -0.176 );
glVertex2f(-0.47, -0.176);
glEnd();

glBegin(GL_LINES); //cargo
glColor3ub(68, 117, 95);
glVertex2f(-0.47, -0.135);
glVertex2f(-0.54,-0.135 );
glVertex2f(-0.54,-0.135 );
glVertex2f(-0.54, -0.176 );
glVertex2f(-0.54, -0.176 );
glVertex2f(-0.47, -0.176);
glVertex2f(-0.47, -0.176);
glVertex2f(-0.47, -0.135);
glEnd();

glBegin(GL_QUADS); //cargo
glColor3ub(46, 76, 151);
glVertex2f(-0.4, -0.135);
glVertex2f(-0.468,-0.135 );
glVertex2f(-0.468, -0.176 );
glVertex2f(-0.4, -0.176);
glEnd();

glBegin(GL_LINES); //cargo
glColor3ub(40, 57, 102);
glVertex2f(-0.4, -0.135);
glVertex2f(-0.468,-0.135 );
glVertex2f(-0.468,-0.135 );
glVertex2f(-0.468, -0.176 );
glVertex2f(-0.468, -0.176 );
glVertex2f(-0.4, -0.176);
glVertex2f(-0.4, -0.176);
glVertex2f(-0.4, -0.135);
glEnd();

glBegin(GL_QUADS); //cargo
glColor3ub(139, 60, 52);
glVertex2f(-0.4, -0.098);
glVertex2f(-0.468,-0.098 );
glVertex2f(-0.468, -0.135 );
glVertex2f(-0.4, -0.135);
glEnd();

glBegin(GL_LINES); //cargo
glColor3ub(102, 29, 24);
glVertex2f(-0.4, -0.098);
glVertex2f(-0.468,-0.098 );
glVertex2f(-0.468,-0.098 );
glVertex2f(-0.468, -0.135 );
glVertex2f(-0.468, -0.135 );
glVertex2f(-0.4, -0.135);
glVertex2f(-0.4, -0.135);
glVertex2f(-0.4, -0.098);
glEnd();

glBegin(GL_QUADS); //cargo
glColor3ub(191, 188, 195);
glVertex2f(-0.47, -0.095);
glVertex2f(-0.54,-0.095 );
glVertex2f(-0.54, -0.135 );
glVertex2f(-0.47, -0.135);
glEnd();

glBegin(GL_LINES); //cargo
glColor3ub(124, 124, 132);
glVertex2f(-0.47, -0.095);
glVertex2f(-0.54,-0.095 );
glVertex2f(-0.54,-0.095 );
glVertex2f(-0.54, -0.135 );
glVertex2f(-0.54, -0.135 );
glVertex2f(-0.47, -0.135);
glVertex2f(-0.47, -0.135);
glVertex2f(-0.47, -0.095);
glEnd();


glBegin(GL_QUADS); //cargo
glColor3ub(175, 186, 99);
glVertex2f(-0.47, -0.06);
glVertex2f(-0.54,-0.06 );
glVertex2f(-0.54, -0.095 );
glVertex2f(-0.47, -0.095);
glEnd();

glBegin(GL_LINES); //cargo
glColor3ub(113, 122, 46);
glVertex2f(-0.47, -0.06);
glVertex2f(-0.54,-0.06 );
glVertex2f(-0.54,-0.06 );
glVertex2f(-0.54, -0.095 );
glVertex2f(-0.54, -0.095 );
glVertex2f(-0.47, -0.095);
glVertex2f(-0.47, -0.095);
glVertex2f(-0.47, -0.06);
glEnd();

glBegin(GL_QUADS); //cargoglVertex2f(-0.845, 0.204);
glVertex2f(-0.8445, 0.194);
glVertex2f(-0.8445, 0.194);
glVertex2f(-0.844, 0.188);
glVertex2f(-0.844, 0.188);
glVertex2f(-0.843, 0.181);
glVertex2f(-0.843, 0.181);
glVertex2f(-0.843, 0.181);
glVertex2f(-0.843, 0.181);
glVertex2f(-0.842, 0.176);
glVertex2f(-0.842, 0.176);
glVertex2f(-0.841, 0.173);
glVertex2f(-0.841, 0.173);
glVertex2f(-0.839, 0.169);
glVertex2f(-0.839, 0.169);
glVertex2f(-0.837, 0.168);
glVertex2f(-0.837, 0.168);
glVertex2f(-0.834, 0.168);
glVertex2f(-0.834, 0.168);
glVertex2f(-0.832, 0.17);
glVertex2f(-0.832, 0.17);
glVertex2f(-0.829, 0.181);
glVertex2f(-0.829, 0.181);
glVertex2f(-0.828, 0.194);
glVertex2f(-0.828, 0.194);
glVertex2f(-0.828, 0.205);
glVertex2f(-0.828, 0.205);
glVertex2f(-0.828, 0.205);
glVertex2f(-0.828, 0.205);
glVertex2f(-0.828, 0.205);
glVertex2f(-0.828, 0.205);
glVertex2f(-0.828, 0.205);
glEnd();


glBegin(GL_QUADS); //cargo
glColor3ub(100, 134, 75);
glVertex2f(-0.47, -0.03);
glVertex2f(-0.54,-0.03 );
glVertex2f(-0.54, -0.06 );
glVertex2f(-0.47, -0.06);
glEnd();

glBegin(GL_LINES); //cargo
glColor3ub(38, 107, 10);
glVertex2f(-0.47, -0.03);
glVertex2f(-0.54,-0.03 );
glVertex2f(-0.54,-0.03 );
glVertex2f(-0.54, -0.06 );
glVertex2f(-0.54, -0.06 );
glVertex2f(-0.47, -0.06);
glVertex2f(-0.47, -0.06);
glVertex2f(-0.47, -0.03);
glEnd();


glBegin(GL_QUADS); //cargo
glColor3ub(76, 59, 134);
glVertex2f(-0.545, -0.097);
glVertex2f(-0.615,-0.097 );
glVertex2f(-0.615, -0.135 );
glVertex2f(-0.545, -0.135);
glEnd();

glBegin(GL_LINES); //cargo
glColor3ub(62, 52, 96);
glVertex2f(-0.545, -0.097);
glVertex2f(-0.615,-0.097 );
glVertex2f(-0.615,-0.097 );
glVertex2f(-0.615, -0.135 );
glVertex2f(-0.615, -0.135 );
glVertex2f(-0.545, -0.135);
glVertex2f(-0.545, -0.135);
glVertex2f(-0.545, -0.097);
glEnd();

glBegin(GL_QUADS); //cargo
glColor3ub(126, 51, 38);
glVertex2f(-0.545, -0.06);
glVertex2f(-0.615,-0.06 );
glVertex2f(-0.615, -0.097 );
glVertex2f(-0.545, -0.097);
glEnd();

glBegin(GL_LINES); //cargo
glColor3ub(96, 35, 23);
glVertex2f(-0.545, -0.06);
glVertex2f(-0.615,-0.06 );
glVertex2f(-0.615,-0.06 );
glVertex2f(-0.615, -0.097 );
glVertex2f(-0.615, -0.097 );
glVertex2f(-0.545, -0.097);
glVertex2f(-0.545, -0.097);
glVertex2f(-0.545, -0.06);
glEnd();

glBegin(GL_POLYGON); //Hull
glColor3ub(33, 35, 34);
glVertex2f(-0.762, -0.106);
glVertex2f(-0.76, -0.13);
glVertex2f(-0.75, -0.145 );
glVertex2f(-0.8, -0.17);
glVertex2f(-0.82, -0.15);
glVertex2f(-0.83, -0.13);
glVertex2f(-0.832, -0.106);
glEnd();

glBegin(GL_POLYGON); //Hull 2
glColor3ub(33, 35, 34);
glVertex2f(-0.722, -0.166);
glVertex2f(-0.74, -0.155);
glVertex2f(-0.75, -0.145 );
glVertex2f(-0.8, -0.17);
glVertex2f(-0.78, -0.188);
glVertex2f(-0.77, -0.204);
glVertex2f(-0.765, -0.22);
glVertex2f(-0.722, -0.22);
glEnd();

glBegin(GL_QUADS); //Hull 3
glColor3ub(33, 35, 34);
glVertex2f(-0.637, -0.166);
glVertex2f(-0.722, -0.166 );
glVertex2f(-0.722, -0.22 );
glVertex2f(-0.637, -0.22);
glEnd();


glBegin(GL_QUADS); //Hull 4
glColor3ub(33, 35, 34);
glVertex2f(-0.637, -0.18);
glVertex2f(-0.637, -0.22 );
glVertex2f(-0.42, -0.22 );
glVertex2f(-0.42, -0.18);
glEnd();

glBegin(GL_POLYGON); //Hull 5
glColor3ub(33, 35, 34);
glVertex2f(-0.42, -0.22);
glVertex2f(-0.42, -0.18);
glVertex2f(-0.398, -0.16 );
glVertex2f(-0.39, -0.15);
glVertex2f(-0.384, -0.132);
glVertex2f(-0.38, -0.132);
glVertex2f(-0.38, -0.22);
glEnd();

glBegin(GL_QUADS); //Hull 5
glColor3ub(33, 35, 34);
glVertex2f(-0.38, -0.132);
glVertex2f(-0.38, -0.22 );
glVertex2f(-0.27, -0.22 );
glVertex2f(-0.27, -0.132);
glEnd();

glBegin(GL_POLYGON); //Hull 6
glColor3ub(33, 35, 34);
glVertex2f(-0.27, -0.132);
glVertex2f(-0.215, -0.132);
glVertex2f(-0.23, -0.168 );
glVertex2f(-0.248, -0.195);
glVertex2f(-0.27, -0.22);
glEnd();

glBegin(GL_QUADS); //Hull 6
glColor3ub(212, 41, 37);
glVertex2f(-0.383, -0.128);
glVertex2f(-0.384, -0.132 );
glVertex2f(-0.215, -0.132 );
glVertex2f(-0.214, -0.128);
glEnd();

glBegin(GL_QUADS); //Hull 7
glColor3ub(27, 138, 57);
glVertex2f(-0.383, -0.128);
glVertex2f(-0.214, -0.128);
glVertex2f(-0.207, -0.108 );
glVertex2f(-0.38, -0.108 );
glEnd();

glBegin(GL_QUADS); //Railings
glColor3ub(255, 255, 255);
glVertex2f(-0.4158, -0.176);
glVertex2f(-0.42, -0.18);
glVertex2f(-0.637, -0.18 );
glVertex2f(-0.637, -0.176 );
glEnd();

glBegin(GL_LINES); //Railings 2
glColor3ub(255, 255, 255);

glVertex2f(-0.644, -0.166);
glVertex2f(-0.644, -0.145);

glVertex2f(-0.644, -0.145);
glVertex2f(-0.3885, -0.145);

glVertex2f(-0.625, -0.145);
glVertex2f(-0.625, -0.176);

glVertex2f(-0.608, -0.145);
glVertex2f(-0.608, -0.176);

glVertex2f(-0.59, -0.145);
glVertex2f(-0.59, -0.176);

glVertex2f(-0.573, -0.145);
glVertex2f(-0.573, -0.176);

glVertex2f(-0.5545, -0.145);
glVertex2f(-0.5545, -0.176);

glVertex2f(-0.5375, -0.145);
glVertex2f(-0.5375, -0.176);

glVertex2f(-0.519, -0.145);
glVertex2f(-0.519, -0.176);

glVertex2f(-0.502, -0.145);
glVertex2f(-0.502, -0.176);

glVertex2f(-0.484, -0.145);
glVertex2f(-0.484, -0.176);

glVertex2f(-0.466, -0.145);
glVertex2f(-0.466, -0.176);

glVertex2f(-0.448, -0.145);
glVertex2f(-0.448, -0.176);

glVertex2f(-0.43, -0.145);
glVertex2f(-0.43, -0.176);

glVertex2f(-0.413, -0.145);
glVertex2f(-0.413, -0.1736);

glVertex2f(-0.402, -0.145);
glVertex2f(-0.402, -0.1636);
glEnd();
glLoadIdentity();
//back ship end

//night car standing start

glBegin(GL_POLYGON); //truck
glColor3ub(241, 142, 35);
glVertex2f(0.91, -0.215);
glVertex2f(0.926, -0.214);
glVertex2f(0.944, -0.214);
glVertex2f(0.965, -0.215);
glVertex2f(0.965, -0.225);
glVertex2f(0.91, -0.225);
glEnd();

glBegin(GL_POLYGON); //truck
glColor3ub(241, 142, 35);
glVertex2f(0.91, -0.215);
glVertex2f(0.905, -0.23);
glVertex2f(0.903, -0.245);
glVertex2f(0.9015, -0.255);
glVertex2f(0.907, -0.245);
glVertex2f(0.91, -0.225);
glEnd();

glBegin(GL_POLYGON); //truck
glColor3ub(241, 142, 35);
glVertex2f(0.965, -0.215);
glVertex2f(0.965, -0.225);
glVertex2f(0.968, -0.245);
glVertex2f(0.9742, -0.256);
glVertex2f(0.972, -0.244);
glVertex2f(0.97, -0.232);
glEnd();

glBegin(GL_POLYGON); //truck
glColor3ub(241, 142, 35);
glVertex2f(0.907, -0.245);
glVertex2f(0.9015, -0.255);
glVertex2f(0.918, -0.256);
glVertex2f(0.958, -0.256);
glVertex2f(0.9742, -0.256);
glVertex2f(0.968, -0.245);
glEnd();

glBegin(GL_POLYGON); //truck
glColor3ub(241, 142, 35);
glVertex2f(0.9015, -0.255);
glVertex2f(0.918, -0.256);
glVertex2f(0.958, -0.256);
glVertex2f(0.9742, -0.256);
glVertex2f(0.975, -0.2692);
glVertex2f(0.95, -0.271);
glVertex2f(0.93, -0.271);
glVertex2f(0.9005, -0.269);
glEnd();


glBegin(GL_POLYGON); //truck
glColor3ub(0,0,0);
glVertex2f(0.9, -0.282);
glVertex2f(0.9, -0.296);
glVertex2f(0.902, -0.298);
glVertex2f(0.908, -0.298);
glVertex2f(0.91, -0.296);
glVertex2f(0.91, -0.288);
glEnd();


glBegin(GL_POLYGON); //truck
glColor3ub(0,0,0);
glVertex2f(0.966, -0.288);
glVertex2f(0.966, -0.296);
glVertex2f(0.968, -0.298);
glVertex2f(0.974, -0.298);
glVertex2f(0.975, -0.296);
glVertex2f(0.975, -0.282);
glEnd();



glBegin(GL_POLYGON); //truck
glColor3ub(73, 91, 80);
glVertex2f(0.9005, -0.269);
glVertex2f(0.9, -0.282);
glVertex2f(0.902, -0.288);
glVertex2f(0.91, -0.288);
glVertex2f(0.966, -0.288);
glVertex2f(0.95, -0.271);
glVertex2f(0.93, -0.271);
glEnd();

glBegin(GL_POLYGON); //truck
glColor3ub(73, 91, 80);
glVertex2f(0.966, -0.288);
glVertex2f(0.95, -0.271);
glVertex2f(0.975, -0.2692);
glVertex2f(0.975, -0.282);
glVertex2f(0.974, -0.288);
glEnd();

glBegin(GL_POLYGON); //truck
glColor3ub(73, 91, 80);
glVertex2f(0.92, -0.262);
glVertex2f(0.92, -0.266);
glVertex2f(0.922, -0.268);
glVertex2f(0.954, -0.268);
glVertex2f(0.956, -0.266);
glVertex2f(0.956, -0.262);
glEnd();

glBegin(GL_QUADS); //truck
glColor3ub(221, 229, 241);
glVertex2f(0.905, -0.275);
glVertex2f(0.91, -0.275);
glVertex2f(0.91, -0.28);
glVertex2f(0.905, -0.28);
glEnd();

glBegin(GL_QUADS); //truck
glColor3ub(221, 229, 241);
glVertex2f(0.965, -0.275);
glVertex2f(0.965, -0.28);
glVertex2f(0.97, -0.28);
glVertex2f(0.97, -0.275);
glEnd();

glBegin(GL_QUADS); //truck
glColor3ub(221, 229, 241);
glVertex2f(0.9015, -0.255);
glVertex2f(0.901, -0.262);
glVertex2f(0.918, -0.264);
glVertex2f(0.918, -0.256);
glEnd();

glBegin(GL_QUADS); //truck
glColor3ub(221, 229, 241);
glVertex2f(0.959, -0.257);
glVertex2f(0.96, -0.266);
glVertex2f(0.9745, -0.263);
glVertex2f(0.9742, -0.256);
glEnd();


glBegin(GL_QUADS); //truck
glColor3ub(0,0,0);
glVertex2f(0.902, -0.245);
glVertex2f(0.902, -0.246);
glVertex2f(0.903, -0.246);
glVertex2f(0.903, -0.245);
glEnd();

glBegin(GL_QUADS); //truck
glColor3ub(0,0,0);
glVertex2f(0.902, -0.24);
glVertex2f(0.897, -0.24);
glVertex2f(0.897, -0.249);
glVertex2f(0.902, -0.249);
glEnd();

glBegin(GL_QUADS); //truck
glColor3ub(0,0,0);
glVertex2f(0.972, -0.244);
glVertex2f(0.972, -0.246);
glVertex2f(0.974, -0.246);
glVertex2f(0.974, -0.244);
glEnd();

glBegin(GL_QUADS); //truck
glColor3ub(0,0,0);
glVertex2f(0.974, -0.24);
glVertex2f(0.974, -0.248);
glVertex2f(0.98, -0.248);
glVertex2f(0.98, -0.24);
glEnd();

glBegin(GL_QUADS); //GLASS
glColor3ub(230, 230, 0);
glVertex2f(0.91, -0.225);
glVertex2f(0.907, -0.245);
glVertex2f(0.968, -0.245);
glVertex2f(0.965, -0.225);
glEnd();
glTranslatef(-0.1,0,0);

glBegin(GL_POLYGON); //truck
glColor3ub(83, 111, 160);
glVertex2f(0.91, -0.215);
glVertex2f(0.926, -0.214);
glVertex2f(0.944, -0.214);
glVertex2f(0.965, -0.215);
glVertex2f(0.965, -0.225);
glVertex2f(0.91, -0.225);
glEnd();

glBegin(GL_POLYGON); //truck
glColor3ub(83, 111, 160);
glVertex2f(0.91, -0.215);
glVertex2f(0.905, -0.23);
glVertex2f(0.903, -0.245);
glVertex2f(0.9015, -0.255);
glVertex2f(0.907, -0.245);
glVertex2f(0.91, -0.225);
glEnd();

glBegin(GL_POLYGON); //truck
glColor3ub(83, 111, 160);
glVertex2f(0.965, -0.215);
glVertex2f(0.965, -0.225);
glVertex2f(0.968, -0.245);
glVertex2f(0.9742, -0.256);
glVertex2f(0.972, -0.244);
glVertex2f(0.97, -0.232);
glEnd();

glBegin(GL_POLYGON); //truck
glColor3ub(83, 111, 160);
glVertex2f(0.907, -0.245);
glVertex2f(0.9015, -0.255);
glVertex2f(0.918, -0.256);
glVertex2f(0.958, -0.256);
glVertex2f(0.9742, -0.256);
glVertex2f(0.968, -0.245);
glEnd();

glBegin(GL_POLYGON); //truck
glColor3ub(83, 111, 160);
glVertex2f(0.9015, -0.255);
glVertex2f(0.918, -0.256);
glVertex2f(0.958, -0.256);
glVertex2f(0.9742, -0.256);
glVertex2f(0.975, -0.2692);
glVertex2f(0.95, -0.271);
glVertex2f(0.93, -0.271);
glVertex2f(0.9005, -0.269);
glEnd();


glBegin(GL_POLYGON); //truck
glColor3ub(0,0,0);
glVertex2f(0.9, -0.282);
glVertex2f(0.9, -0.296);
glVertex2f(0.902, -0.298);
glVertex2f(0.908, -0.298);
glVertex2f(0.91, -0.296);
glVertex2f(0.91, -0.288);
glEnd();


glBegin(GL_POLYGON); //truck
glColor3ub(0,0,0);
glVertex2f(0.966, -0.288);
glVertex2f(0.966, -0.296);
glVertex2f(0.968, -0.298);
glVertex2f(0.974, -0.298);
glVertex2f(0.975, -0.296);
glVertex2f(0.975, -0.282);
glEnd();



glBegin(GL_POLYGON); //truck
glColor3ub(73, 91, 80);
glVertex2f(0.9005, -0.269);
glVertex2f(0.9, -0.282);
glVertex2f(0.902, -0.288);
glVertex2f(0.91, -0.288);
glVertex2f(0.966, -0.288);
glVertex2f(0.95, -0.271);
glVertex2f(0.93, -0.271);
glEnd();

glBegin(GL_POLYGON); //truck
glColor3ub(73, 91, 80);
glVertex2f(0.966, -0.288);
glVertex2f(0.95, -0.271);
glVertex2f(0.975, -0.2692);
glVertex2f(0.975, -0.282);
glVertex2f(0.974, -0.288);
glEnd();

glBegin(GL_POLYGON); //truck
glColor3ub(73, 91, 80);
glVertex2f(0.92, -0.262);
glVertex2f(0.92, -0.266);
glVertex2f(0.922, -0.268);
glVertex2f(0.954, -0.268);
glVertex2f(0.956, -0.266);
glVertex2f(0.956, -0.262);
glEnd();

glBegin(GL_QUADS); //truck
glColor3ub(221, 229, 241);
glVertex2f(0.905, -0.275);
glVertex2f(0.91, -0.275);
glVertex2f(0.91, -0.28);
glVertex2f(0.905, -0.28);
glEnd();

glBegin(GL_QUADS); //truck
glColor3ub(221, 229, 241);
glVertex2f(0.965, -0.275);
glVertex2f(0.965, -0.28);
glVertex2f(0.97, -0.28);
glVertex2f(0.97, -0.275);
glEnd();

glBegin(GL_QUADS); //truck
glColor3ub(221, 229, 241);
glVertex2f(0.9015, -0.255);
glVertex2f(0.901, -0.262);
glVertex2f(0.918, -0.264);
glVertex2f(0.918, -0.256);
glEnd();

glBegin(GL_QUADS); //truck
glColor3ub(221, 229, 241);
glVertex2f(0.959, -0.257);
glVertex2f(0.96, -0.266);
glVertex2f(0.9745, -0.263);
glVertex2f(0.9742, -0.256);
glEnd();


glBegin(GL_QUADS); //truck
glColor3ub(0,0,0);
glVertex2f(0.902, -0.245);
glVertex2f(0.902, -0.246);
glVertex2f(0.903, -0.246);
glVertex2f(0.903, -0.245);
glEnd();

glBegin(GL_QUADS); //truck
glColor3ub(0,0,0);
glVertex2f(0.902, -0.24);
glVertex2f(0.897, -0.24);
glVertex2f(0.897, -0.249);
glVertex2f(0.902, -0.249);
glEnd();

glBegin(GL_QUADS); //truck
glColor3ub(0,0,0);
glVertex2f(0.972, -0.244);
glVertex2f(0.972, -0.246);
glVertex2f(0.974, -0.246);
glVertex2f(0.974, -0.244);
glEnd();

glBegin(GL_QUADS); //truck
glColor3ub(0,0,0);
glVertex2f(0.974, -0.24);
glVertex2f(0.974, -0.248);
glVertex2f(0.98, -0.248);
glVertex2f(0.98, -0.24);
glEnd();

glBegin(GL_QUADS); //GLASS
glColor3ub(230, 230, 0);
glVertex2f(0.91, -0.225);
glVertex2f(0.907, -0.245);
glVertex2f(0.968, -0.245);
glVertex2f(0.965, -0.225);
glEnd();


//night car standing ends



glBegin(GL_QUADS); //Cargo Floor
glColor3ub(151, 142, 124);
glVertex2f(-1, -0.275);
glVertex2f(-1, -0.312);
glVertex2f(-0.345, -0.312);
glVertex2f(-0.345, -0.275);
glEnd();

glBegin(GL_LINES); //Cargo Floor
glColor3ub(122, 111, 91);
glVertex2f(-1, -0.275);
glVertex2f(-1, -0.312);
glVertex2f(-1, -0.312);
glVertex2f(-0.345, -0.312);
glVertex2f(-0.345, -0.312);
glVertex2f(-0.345, -0.275);
glVertex2f(-0.345, -0.275);
glVertex2f(-1, -0.275);
glEnd();


glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.991, -0.281);
glVertex2f(-0.991, -0.306);
glVertex2f(-0.975, -0.306);
glVertex2f(-0.975, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.96, -0.281);
glVertex2f(-0.96, -0.306);
glVertex2f(-0.945, -0.306);
glVertex2f(-0.945, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.93, -0.281);
glVertex2f(-0.93, -0.306);
glVertex2f(-0.915, -0.306);
glVertex2f(-0.915, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.9, -0.281);
glVertex2f(-0.9, -0.306);
glVertex2f(-0.885, -0.306);
glVertex2f(-0.885, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.87, -0.281);
glVertex2f(-0.87, -0.306);
glVertex2f(-0.856, -0.306);
glVertex2f(-0.856, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.845, -0.281);
glVertex2f(-0.845, -0.306);
glVertex2f(-0.83, -0.306);
glVertex2f(-0.83, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.815, -0.281);
glVertex2f(-0.815, -0.306);
glVertex2f(-0.8, -0.306);
glVertex2f(-0.8, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.785, -0.281);
glVertex2f(-0.785, -0.306);
glVertex2f(-0.77, -0.306);
glVertex2f(-0.77, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.755, -0.281);
glVertex2f(-0.755, -0.306);
glVertex2f(-0.74, -0.306);
glVertex2f(-0.74, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.725, -0.281);
glVertex2f(-0.725, -0.306);
glVertex2f(-0.71, -0.306);
glVertex2f(-0.71, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.695, -0.281);
glVertex2f(-0.695, -0.306);
glVertex2f(-0.68, -0.306);
glVertex2f(-0.68, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.665, -0.281);
glVertex2f(-0.665, -0.306);
glVertex2f(-0.65, -0.306);
glVertex2f(-0.65, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.64, -0.281);
glVertex2f(-0.64, -0.306);
glVertex2f(-0.625, -0.306);
glVertex2f(-0.625, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.61, -0.281);
glVertex2f(-0.61, -0.306);
glVertex2f(-0.595, -0.306);
glVertex2f(-0.595, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.58, -0.281);
glVertex2f(-0.58, -0.306);
glVertex2f(-0.56, -0.306);
glVertex2f(-0.56, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.55, -0.281);
glVertex2f(-0.55, -0.306);
glVertex2f(-0.53, -0.306);
glVertex2f(-0.53, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.52, -0.281);
glVertex2f(-0.52, -0.306);
glVertex2f(-0.5, -0.306);
glVertex2f(-0.5, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.49, -0.281);
glVertex2f(-0.49, -0.306);
glVertex2f(-0.47, -0.306);
glVertex2f(-0.47, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.46, -0.281);
glVertex2f(-0.46, -0.306);
glVertex2f(-0.44, -0.306);
glVertex2f(-0.44, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.43, -0.281);
glVertex2f(-0.43, -0.306);
glVertex2f(-0.41, -0.306);
glVertex2f(-0.41, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.4, -0.281);
glVertex2f(-0.4, -0.306);
glVertex2f(-0.38, -0.306);
glVertex2f(-0.38, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.37, -0.281);
glVertex2f(-0.37, -0.306);
glVertex2f(-0.35, -0.306);
glVertex2f(-0.35, -0.281);
glEnd();



//Cargo boxes left upper then lines
glBegin(GL_QUADS);
glColor3ub(137, 97, 27);
glVertex2f(-0.855, -0.01);
glVertex2f(-0.855, -0.062);
glVertex2f(-0.768, -0.062);
glVertex2f(-0.768, -0.01);
glEnd();
glBegin(GL_QUADS);
glColor3ub(130, 17, 23);
glVertex2f(-0.8552, -0.062);
glVertex2f(-0.8552, -0.115);
glVertex2f(-0.768, -0.115);
glVertex2f(-0.768, -0.062);
glEnd();
glBegin(GL_QUADS);
glColor3ub(71, 95, 133);
glVertex2f(-0.942, -0.062);
glVertex2f(-0.942, -0.115);
glVertex2f(-0.8552, -0.115);
glVertex2f(-0.8552, -0.062);
glEnd();
glBegin(GL_QUADS);
glColor3ub(137, 97, 27);
glVertex2f(-1, -0.115);
glVertex2f(-1, -0.168);
glVertex2f(-0.942, -0.168);
glVertex2f(-0.942, -0.115);
glEnd();
glBegin(GL_QUADS);
glColor3ub(53, 54, 160);
glVertex2f(-0.942, -0.115);
glVertex2f(-0.942, -0.168);
glVertex2f(-0.8552, -0.168);
glVertex2f(-0.8552, -0.115);
glEnd();
glBegin(GL_QUADS);
glColor3ub(118, 77, 145);
glVertex2f(-0.855, -0.115);
glVertex2f(-0.8552, -0.168);
glVertex2f(-0.768, -0.168);
glVertex2f(-0.768, -0.115);
glEnd();
glBegin(GL_QUADS);
glColor3ub(53, 54, 160);
glVertex2f(-0.768, -0.115);
glVertex2f(-0.768, -0.168);
glVertex2f(-0.677, -0.168);
glVertex2f(-0.677, -0.115);
glEnd();
glBegin(GL_QUADS);
glColor3ub(161, 47, 53);
glVertex2f(-0.768, -0.168);
glVertex2f(-0.768, -0.222);
glVertex2f(-0.677, -0.222);
glVertex2f(-0.677, -0.168);
glEnd();
glBegin(GL_QUADS);
glColor3ub(205, 194, 49);
glVertex2f(-0.8552, -0.168);
glVertex2f(-0.8552, -0.222);
glVertex2f(-0.768, -0.222);
glVertex2f(-0.768, -0.168);
glEnd();
glBegin(GL_QUADS);
glColor3ub(161, 47, 53);
glVertex2f(-0.945, -0.168);
glVertex2f(-0.945, -0.222);
glVertex2f(-0.8552, -0.222);
glVertex2f(-0.8552, -0.168);
glEnd();
glBegin(GL_QUADS);
glColor3ub(56, 84, 129);
glVertex2f(-1, -0.168);
glVertex2f(-1, -0.222);
glVertex2f(-0.945, -0.222);
glVertex2f(-0.945, -0.168);
glEnd();
glBegin(GL_QUADS);
glColor3ub(157, 53, 116);
glVertex2f(-1, -0.222);
glVertex2f(-1, -0.274);
glVertex2f(-0.945, -0.274);
glVertex2f(-0.945, -0.222);
glEnd();
glBegin(GL_QUADS);
glColor3ub(205, 194, 49);
glVertex2f(-0.945, -0.222);
glVertex2f(-0.945, -0.274);
glVertex2f(-0.8552, -0.274);
glVertex2f(-0.8552, -0.222);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 163, 92);
glVertex2f(-0.8552, -0.222);
glVertex2f(-0.8552, -0.274);
glVertex2f(-0.768, -0.274);
glVertex2f(-0.768, -0.222);
glEnd();
glBegin(GL_QUADS);
glColor3ub(205, 194, 49);
glVertex2f(-0.768, -0.222);
glVertex2f(-0.768, -0.274);
glVertex2f(-0.677, -0.274);
glVertex2f(-0.677, -0.222);
glEnd();
glBegin(GL_QUADS);
glColor3ub(191, 181, 40);
glVertex2f(-0.644, -0.222);
glVertex2f(-0.554, -0.222);
glVertex2f(-0.554, -0.275);
glVertex2f(-0.644, -0.275);
glEnd();
glBegin(GL_QUADS);
glColor3ub(140, 31, 35);
glVertex2f(-0.644, -0.168);
glVertex2f(-0.554, -0.168);
glVertex2f(-0.554, -0.222);
glVertex2f(-0.644, -0.222);
glEnd();
glBegin(GL_QUADS);
glColor3ub(38, 40, 151);
glVertex2f(-0.644, -0.116);
glVertex2f(-0.554, -0.116);
glVertex2f(-0.554, -0.168);
glVertex2f(-0.644, -0.168);
glEnd();
glBegin(GL_QUADS);
glColor3ub(69, 90, 124);
glVertex2f(-0.644, -0.066);
glVertex2f(-0.554, -0.066);
glVertex2f(-0.554, -0.116);
glVertex2f(-0.644, -0.116);
glEnd();
glBegin(GL_QUADS);
glColor3ub(61, 173, 95);
glVertex2f(-0.554, -0.222);
glVertex2f(-0.465, -0.222);
glVertex2f(-0.465, -0.275);
glVertex2f(-0.554, -0.275);
glEnd();
glBegin(GL_QUADS);
glColor3ub(50, 71, 109);
glVertex2f(-0.554, -0.168);
glVertex2f(-0.465, -0.168);
glVertex2f(-0.465, -0.222);
glVertex2f(-0.554, -0.222);
glEnd();
glBegin(GL_QUADS);
glColor3ub(132, 91, 25);
glVertex2f(-0.554, -0.116);
glVertex2f(-0.465, -0.116);
glVertex2f(-0.465, -0.168);
glVertex2f(-0.554, -0.168);
glEnd();
glBegin(GL_QUADS);
glColor3ub(162, 46, 53);
glVertex2f(-0.554, -0.066);
glVertex2f(-0.465, -0.066);
glVertex2f(-0.465, -0.116);
glVertex2f(-0.554, -0.116);
glEnd();
glBegin(GL_QUADS);
glColor3ub(190, 184, 37);
glVertex2f(-0.554, -0.012);
glVertex2f(-0.465, -0.012);
glVertex2f(-0.465, -0.066);
glVertex2f(-0.554, -0.066);
glEnd();
glBegin(GL_QUADS);
glColor3ub(102, 67, 132);
glVertex2f(-0.554, 0.04);
glVertex2f(-0.465, 0.04);
glVertex2f(-0.465, -0.012);
glVertex2f(-0.554, -0.012);
glEnd();
glBegin(GL_QUADS);
glColor3ub(196, 185, 42);
glVertex2f(-0.465, -0.225);
glVertex2f(-0.375, -0.225);
glVertex2f(-0.375, -0.275);
glVertex2f(-0.465, -0.275);
glEnd();
glBegin(GL_QUADS);
glColor3ub(173, 85, 28);
glVertex2f(-0.465, -0.18);
glVertex2f(-0.375, -0.18);
glVertex2f(-0.375, -0.225);
glVertex2f(-0.465, -0.225);
glEnd();

glBegin(GL_QUADS);
glColor3ub(19, 23, 119);
glVertex2f(-0.465, -0.135);
glVertex2f(-0.375, -0.135);
glVertex2f(-0.375, -0.18);
glVertex2f(-0.465, -0.18);
glEnd();

glBegin(GL_QUADS);
glColor3ub(135, 25, 32);
glVertex2f(-0.465, -0.085);
glVertex2f(-0.375, -0.085);
glVertex2f(-0.375, -0.135);
glVertex2f(-0.465, -0.135);
glEnd();



glBegin(GL_LINES);
glColor3ub(64, 64, 64);
glVertex2f(-0.855, -0.01);//1
glVertex2f(-0.855, -0.062);
glVertex2f(-0.855, -0.062);
glVertex2f(-0.768, -0.062);
glVertex2f(-0.768, -0.062);
glVertex2f(-0.768, -0.01);
glVertex2f(-0.768, -0.01);
glVertex2f(-0.855, -0.01);
glVertex2f(-0.855, -0.062);//2
glVertex2f(-0.855, -0.115);
glVertex2f(-0.855, -0.115);
glVertex2f(-0.768, -0.115);
glVertex2f(-0.768, -0.115);
glVertex2f(-0.768, -0.062);
glVertex2f(-0.768, -0.062);
glVertex2f(-0.855, -0.062);
glVertex2f(-0.942, -0.062);//3
glVertex2f(-0.942, -0.115);
glVertex2f(-0.942, -0.115);
glVertex2f(-0.855, -0.115);
glVertex2f(-0.855, -0.115);
glVertex2f(-0.855, -0.062);
glVertex2f(-0.855, -0.062);
glVertex2f(-0.942, -0.062);
glVertex2f(-1, -0.115);//4
glVertex2f(-1, -0.168);
glVertex2f(-1, -0.168);
glVertex2f(-0.942, -0.168);
glVertex2f(-0.942, -0.168);
glVertex2f(-0.942, -0.115);
glVertex2f(-0.942, -0.115);
glVertex2f(-1, -0.115);
glVertex2f(-0.942, -0.115);//5
glVertex2f(-0.942, -0.168);
glVertex2f(-0.942, -0.168);
glVertex2f(-0.8552, -0.168);
glVertex2f(-0.8552, -0.168);
glVertex2f(-0.8552, -0.115);
glVertex2f(-0.8552, -0.115);
glVertex2f(-0.942, -0.115);
glVertex2f(-0.8552, -0.115);//6
glVertex2f(-0.8552, -0.168);
glVertex2f(-0.8552, -0.168);
glVertex2f(-0.768, -0.168);
glVertex2f(-0.768, -0.168);
glVertex2f(-0.768, -0.115);
glVertex2f(-0.768, -0.115);
glVertex2f(-0.8552, -0.115);
glVertex2f(-0.768, -0.115);//7
glVertex2f(-0.768, -0.168);
glVertex2f(-0.768, -0.168);
glVertex2f(-0.677, -0.168);
glVertex2f(-0.677, -0.168);
glVertex2f(-0.677, -0.115);
glVertex2f(-0.677, -0.115);
glVertex2f(-0.768, -0.115);
glVertex2f(-0.768, -0.168);//8
glVertex2f(-0.768, -0.222);
glVertex2f(-0.768, -0.222);
glVertex2f(-0.677, -0.222);
glVertex2f(-0.677, -0.222);
glVertex2f(-0.677, -0.168);
glVertex2f(-0.677, -0.168);
glVertex2f(-0.768, -0.168);
glVertex2f(-0.8552, -0.168);//9
glVertex2f(-0.8552, -0.222);
glVertex2f(-0.8552, -0.222);
glVertex2f(-0.768, -0.222);
glVertex2f(-0.768, -0.222);
glVertex2f(-0.768, -0.168);
glVertex2f(-0.768, -0.168);
glVertex2f(-0.8552, -0.168);
glVertex2f(-0.945, -0.168);//10
glVertex2f(-0.945, -0.222);
glVertex2f(-0.945, -0.222);
glVertex2f(-0.8552, -0.222);
glVertex2f(-0.8552, -0.222);
glVertex2f(-0.8552, -0.168);
glVertex2f(-0.8552, -0.168);
glVertex2f(-0.945, -0.168);
glVertex2f(-1, -0.168);//11
glVertex2f(-1, -0.222);
glVertex2f(-1, -0.222);
glVertex2f(-0.945, -0.222);
glVertex2f(-0.945, -0.222);
glVertex2f(-0.945, -0.168);
glVertex2f(-0.945, -0.168);
glVertex2f(-1, -0.168);
glVertex2f(-1, -0.222);//12
glVertex2f(-1, -0.274);
glVertex2f(-1, -0.274);
glVertex2f(-0.945, -0.274);
glVertex2f(-0.945, -0.274);
glVertex2f(-0.945, -0.222);
glVertex2f(-0.945, -0.222);
glVertex2f(-1, -0.222);
glVertex2f(-0.945, -0.222);//13
glVertex2f(-0.945, -0.274);
glVertex2f(-0.945, -0.274);
glVertex2f(-0.8552, -0.274);
glVertex2f(-0.8552, -0.274);
glVertex2f(-0.8552, -0.222);
glVertex2f(-0.8552, -0.222);
glVertex2f(-0.945, -0.222);
glVertex2f(-0.8552, -0.222);//14
glVertex2f(-0.8552, -0.274);
glVertex2f(-0.8552, -0.274);
glVertex2f(-0.768, -0.274);
glVertex2f(-0.768, -0.274);
glVertex2f(-0.768, -0.222);
glVertex2f(-0.768, -0.222);
glVertex2f(-0.8552, -0.222);
glVertex2f(-0.768, -0.222);//15
glVertex2f(-0.768, -0.274);
glVertex2f(-0.768, -0.274);
glVertex2f(-0.677, -0.274);
glVertex2f(-0.677, -0.274);
glVertex2f(-0.677, -0.222);
glVertex2f(-0.677, -0.222);
glVertex2f(-0.768, -0.222);
glVertex2f(-0.644, -0.222);//16
glVertex2f(-0.554, -0.222);
glVertex2f(-0.554, -0.222);
glVertex2f(-0.554, -0.275);
glVertex2f(-0.554, -0.275);
glVertex2f(-0.644, -0.275);
glVertex2f(-0.644, -0.275);
glVertex2f(-0.644, -0.222);
glVertex2f(-0.644, -0.168);//17
glVertex2f(-0.554, -0.168);
glVertex2f(-0.554, -0.168);
glVertex2f(-0.554, -0.222);
glVertex2f(-0.554, -0.222);
glVertex2f(-0.644, -0.222);
glVertex2f(-0.644, -0.222);
glVertex2f(-0.644, -0.168);
glVertex2f(-0.644, -0.116);//18
glVertex2f(-0.554, -0.116);
glVertex2f(-0.554, -0.116);
glVertex2f(-0.554, -0.168);
glVertex2f(-0.554, -0.168);
glVertex2f(-0.644, -0.168);
glVertex2f(-0.644, -0.168);
glVertex2f(-0.644, -0.116);
glVertex2f(-0.644, -0.066);//19
glVertex2f(-0.554, -0.066);
glVertex2f(-0.554, -0.066);
glVertex2f(-0.554, -0.116);
glVertex2f(-0.554, -0.116);
glVertex2f(-0.644, -0.116);
glVertex2f(-0.644, -0.116);
glVertex2f(-0.644, -0.066);

glVertex2f(-0.554, -0.222);//20
glVertex2f(-0.465, -0.222);
glVertex2f(-0.465, -0.222);
glVertex2f(-0.465, -0.275);
glVertex2f(-0.465, -0.275);
glVertex2f(-0.554, -0.275);
glVertex2f(-0.554, -0.275);
glVertex2f(-0.554, -0.222);

glVertex2f(-0.554, -0.168);//21
glVertex2f(-0.465, -0.168);
glVertex2f(-0.465, -0.168);
glVertex2f(-0.465, -0.222);
glVertex2f(-0.465, -0.222);
glVertex2f(-0.554, -0.222);
glVertex2f(-0.554, -0.222);
glVertex2f(-0.554, -0.168);

glVertex2f(-0.554, -0.116);//22
glVertex2f(-0.465, -0.116);
glVertex2f(-0.465, -0.116);
glVertex2f(-0.465, -0.168);
glVertex2f(-0.465, -0.168);
glVertex2f(-0.554, -0.168);
glVertex2f(-0.554, -0.168);
glVertex2f(-0.554, -0.116);

glVertex2f(-0.554, -0.066);//23
glVertex2f(-0.465, -0.066);
glVertex2f(-0.465, -0.066);
glVertex2f(-0.465, -0.116);
glVertex2f(-0.465, -0.116);
glVertex2f(-0.554, -0.116);
glVertex2f(-0.554, -0.116);
glVertex2f(-0.554, -0.066);

glVertex2f(-0.554, -0.012);//24
glVertex2f(-0.465, -0.012);
glVertex2f(-0.465, -0.012);
glVertex2f(-0.465, -0.066);
glVertex2f(-0.465, -0.066);
glVertex2f(-0.554, -0.066);
glVertex2f(-0.554, -0.066);
glVertex2f(-0.554, -0.012);

glVertex2f(-0.554, 0.04);//25
glVertex2f(-0.465, 0.04);
glVertex2f(-0.465, 0.04);
glVertex2f(-0.465, -0.012);
glVertex2f(-0.465, -0.012);
glVertex2f(-0.554, -0.012);
glVertex2f(-0.554, -0.012);
glVertex2f(-0.554, 0.04);

glVertex2f(-0.465, -0.225);//26
glVertex2f(-0.375, -0.225);
glVertex2f(-0.375, -0.225);
glVertex2f(-0.375, -0.275);
glVertex2f(-0.375, -0.275);
glVertex2f(-0.465, -0.275);
glVertex2f(-0.465, -0.275);
glVertex2f(-0.465, -0.225);

glVertex2f(-0.465, -0.18);//27
glVertex2f(-0.375, -0.18);
glVertex2f(-0.375, -0.18);
glVertex2f(-0.375, -0.225);
glVertex2f(-0.375, -0.225);
glVertex2f(-0.465, -0.225);
glVertex2f(-0.465, -0.225);
glVertex2f(-0.465, -0.18);

glVertex2f(-0.465, -0.135);//28
glVertex2f(-0.375, -0.135);
glVertex2f(-0.375, -0.135);
glVertex2f(-0.375, -0.18);
glVertex2f(-0.375, -0.18);
glVertex2f(-0.465, -0.18);
glVertex2f(-0.465, -0.18);
glVertex2f(-0.465, -0.135);

glVertex2f(-0.465, -0.085);//29
glVertex2f(-0.375, -0.085);
glVertex2f(-0.375, -0.085);
glVertex2f(-0.375, -0.135);
glVertex2f(-0.375, -0.135);
glVertex2f(-0.465, -0.135);
glVertex2f(-0.465, -0.135);

glVertex2f(-0.465, -0.025);//30
glVertex2f(-0.375, -0.025);
glVertex2f(-0.375, -0.025);
glVertex2f(-0.375, -0.085);
glVertex2f(-0.375, -0.085);
glVertex2f(-0.465, -0.085);
glVertex2f(-0.465, -0.085);
glVertex2f(-0.465, -0.025);
glEnd();



//box carrier back

glLoadIdentity();

glBegin(GL_QUADS);// TOP HORAIZONTAL STAND
glColor3ub(173, 141, 7);
glVertex2f(-0.898, 0.216);
glVertex2f(-0.898, 0.204);
glVertex2f(-0.396, 0.204);
glVertex2f(-0.38, 0.216);
glEnd();
glBegin(GL_QUADS);// top diagonal stand
glColor3ub(173, 141, 7);
glVertex2f(-0.658, 0.38);
glVertex2f(-0.864, 0.216);
glVertex2f(-0.855, 0.216);
glVertex2f(-0.658, 0.372);
glEnd();
glBegin(GL_QUADS);// left stand
glColor3ub(185, 152, 59);
glVertex2f(-0.797, 0.286);
glVertex2f(-0.797, -0.26);
glVertex2f(-0.79, -0.26);
glVertex2f(-0.79, 0.286);
glEnd();
glBegin(GL_QUADS);// right stand
glColor3ub(185, 152, 59);
glVertex2f(-0.655, 0.249);
glVertex2f(-0.655, -0.26);
glVertex2f(-0.648, -0.26);
glVertex2f(-0.648, 0.249);
glEnd();
glBegin(GL_QUADS);//lower brown left
glColor3ub(61, 43, 6);
glVertex2f(-0.797, -0.258);
glVertex2f(-0.797, -0.267);
glVertex2f(-0.79, -0.267);
glVertex2f(-0.79, -0.258);
glEnd();
glBegin(GL_QUADS);//lower brown left
glColor3ub(61, 43, 6);
glVertex2f(-0.8, -0.267);
glVertex2f(-0.8, -0.274);
glVertex2f(-0.787, -0.274);
glVertex2f(-0.787, -0.267);
glEnd();
glBegin(GL_QUADS);//lower brown right
glColor3ub(61, 43, 6);
glVertex2f(-0.655, -0.258);
glVertex2f(-0.655, -0.267);
glVertex2f(-0.648, -0.267);
glVertex2f(-0.648, -0.258);
glEnd();
glBegin(GL_QUADS);//lower brown right
glColor3ub(61, 43, 6);
glVertex2f(-0.657, -0.267);
glVertex2f(-0.657, -0.274);
glVertex2f(-0.645, -0.274);
glVertex2f(-0.645, -0.267);
glEnd();

glBegin(GL_QUADS);// top left stand extension
glColor3ub(185, 152, 59);
glVertex2f(-0.6526, 0.3658);
glVertex2f(-0.6525, 0.24);
glVertex2f(-0.6495, 0.24);
glVertex2f(-0.6495, 0.3658);
glEnd();
glBegin(GL_QUADS);//top left stand extension 2
glColor3ub(185, 152, 59);
glVertex2f(-0.658, 0.398);
glVertex2f(-0.658, 0.3658);
glVertex2f(-0.6435, 0.3658);
glVertex2f(-0.6435, 0.398);
glEnd();

glBegin(GL_QUADS);// back box
glColor3ub(82, 52, 35);
glVertex2f(-0.89, 0.204);
glVertex2f(-0.89, 0.199);
glVertex2f(-0.858, 0.199);
glVertex2f(-0.858, 0.204);
glEnd();
glBegin(GL_QUADS);// back box
glColor3ub(230, 172, 49);
glVertex2f(-0.897, 0.199);
glVertex2f(-0.897, 0.165);
glVertex2f(-0.853, 0.165);
glVertex2f(-0.853, 0.199);
glEnd();
glBegin(GL_QUADS);// red box
glColor3ub(206, 29, 58);
glVertex2f(-0.717, 0.26);
glVertex2f(-0.717, 0.216);
glVertex2f(-0.659, 0.216);
glVertex2f(-0.659, 0.26);
glEnd();
glBegin(GL_QUADS);// red box glass
glColor3ub(62, 59, 59);
glVertex2f(-0.71, 0.252);
glVertex2f(-0.71, 0.242);
glVertex2f(-0.702, 0.242);
glVertex2f(-0.702, 0.252);
glEnd();
glBegin(GL_QUADS);// red box glass
glColor3ub(62, 59, 59);
glVertex2f(-0.698, 0.252);
glVertex2f(-0.698, 0.242);
glVertex2f(-0.69, 0.242);
glVertex2f(-0.69, 0.252);
glEnd();
glBegin(GL_QUADS);// red box glass
glColor3ub(62, 59, 59);
glVertex2f(-0.686, 0.252);
glVertex2f(-0.686, 0.242);
glVertex2f(-0.678, 0.242);
glVertex2f(-0.678, 0.252);
glEnd();
glBegin(GL_QUADS);// red box glass
glColor3ub(62, 59, 59);
glVertex2f(-0.674, 0.252);
glVertex2f(-0.674, 0.242);
glVertex2f(-0.666, 0.242);
glVertex2f(-0.666, 0.252);
glEnd();
glBegin(GL_LINES);// rope
glColor3ub(62, 59, 59);
glVertex2f(-0.6435, 0.376);
glVertex2f(-0.629, 0.358);
glVertex2f(-0.629, 0.358);
glVertex2f(-0.613, 0.338);
glVertex2f(-0.613, 0.338);
glVertex2f(-0.592, 0.317);
glVertex2f(-0.592, 0.317);
glVertex2f(-0.549, 0.281);
glVertex2f(-0.549, 0.281);
glVertex2f(-0.531, 0.267);
glVertex2f(-0.531, 0.267);
glVertex2f(-0.501, 0.246);
glVertex2f(-0.501, 0.246);
glVertex2f(-0.45, 0.216);
glEnd();

glBegin(GL_QUADS);// right box
glColor3ub(70, 44, 11);
glVertex2f(-0.432, 0.204);
glVertex2f(-0.432, 0.196);
glVertex2f(-0.41, 0.196);
glVertex2f(-0.41, 0.204);
glEnd();
glBegin(GL_QUADS);// right box
glColor3ub(173, 141, 7);
glVertex2f(-0.438, 0.196);
glVertex2f(-0.438, 0.191);
glVertex2f(-0.404, 0.191);
glVertex2f(-0.404, 0.196);
glEnd();
glBegin(GL_QUADS);// stand right box
glColor3ub(31, 41, 40);
glVertex2f(-0.438, 0.191);
glVertex2f(-0.438, -0.008);
glVertex2f(-0.434, -0.008);
glVertex2f(-0.434, 0.191);
glEnd();
glBegin(GL_QUADS);// stand right box
glColor3ub(31, 41, 40);
glVertex2f(-0.408, 0.191);
glVertex2f(-0.408, -0.008);
glVertex2f(-0.404, -0.008);
glVertex2f(-0.404, 0.191);
glEnd();
glBegin(GL_QUADS);// yellow box
glColor3ub(230, 172, 49);
glVertex2f(-0.44, -0.008);
glVertex2f(-0.44, -0.0255);
glVertex2f(-0.4, -0.0255);
glVertex2f(-0.4, -0.008);
glEnd();



glBegin(GL_LINES);// left of back crane stairs
glColor3ub(173, 141, 7);
glVertex2f(-0.67, 0.21);
glVertex2f(-0.67, -0.275);
glVertex2f(-0.67, 0.205);
glVertex2f(-0.655, 0.18);
glVertex2f(-0.655, 0.205);
glVertex2f(-0.67, 0.18);
glVertex2f(-0.67, 0.18);
glVertex2f(-0.655, 0.155);
glVertex2f(-0.655, 0.18);
glVertex2f(-0.67, 0.155);
glVertex2f(-0.67, 0.155);
glVertex2f(-0.655, 0.13);
glVertex2f(-0.655, 0.155);
glVertex2f(-0.67, 0.13);
glVertex2f(-0.67, 0.13);
glVertex2f(-0.655, 0.105);
glVertex2f(-0.655, 0.13);
glVertex2f(-0.67, 0.105);
glVertex2f(-0.67, 0.105);
glVertex2f(-0.655, 0.085);
glVertex2f(-0.655, 0.105);
glVertex2f(-0.67, 0.085);
glVertex2f(-0.67, 0.085);
glVertex2f(-0.655, 0.06);
glVertex2f(-0.655, 0.085);
glVertex2f(-0.67, 0.06);
glVertex2f(-0.655, 0.035);
glVertex2f(-0.655, 0.06);
glVertex2f(-0.655, 0.06);
glVertex2f(-0.67, 0.035);
glVertex2f(-0.67, 0.06);
glVertex2f(-0.655, 0.035);
glVertex2f(-0.67, 0.035);
glVertex2f(-0.655, 0.01);
glVertex2f(-0.655, 0.035);
glVertex2f(-0.67, 0.01);
glVertex2f(-0.67, 0.01);
glVertex2f(-0.655, -0.015);
glVertex2f(-0.655, 0.01);
glVertex2f(-0.67, -0.015);
glVertex2f(-0.67, -0.015);
glVertex2f(-0.655, -0.04);
glVertex2f(-0.655, -0.015);
glVertex2f(-0.67, -0.04);
glVertex2f(-0.67, -0.04);
glVertex2f(-0.655, -0.065);
glVertex2f(-0.655, -0.04);
glVertex2f(-0.67, -0.065);
glVertex2f(-0.67, -0.04);
glVertex2f(-0.655, -0.065);
glVertex2f(-0.655, -0.04);
glVertex2f(-0.67, -0.065);
glVertex2f(-0.67, -0.065);
glVertex2f(-0.655, -0.09);
glVertex2f(-0.655, -0.065);
glVertex2f(-0.67, -0.09);
glEnd();

glBegin(GL_LINES);// left of back crane stairs
glColor3ub(173, 141, 7);
glVertex2f(-0.67, -0.09);
glVertex2f(-0.655, -0.115);
glVertex2f(-0.655, -0.09);
glVertex2f(-0.67, -0.115);
glVertex2f(-0.67, -0.115);
glVertex2f(-0.655, -0.14);
glVertex2f(-0.655, -0.115);
glVertex2f(-0.67, -0.14);
glVertex2f(-0.67, -0.14);
glVertex2f(-0.655, -0.165);
glVertex2f(-0.655, -0.14);
glVertex2f(-0.67, -0.165);
glVertex2f(-0.67, -0.165);
glVertex2f(-0.655, -0.19);
glVertex2f(-0.655, -0.165);
glVertex2f(-0.67, -0.19);
glVertex2f(-0.67, -0.19);
glVertex2f(-0.655, -0.215);
glVertex2f(-0.655, -0.19);
glVertex2f(-0.67, -0.215);
glVertex2f(-0.67, -0.215);
glVertex2f(-0.655, -0.24);
glVertex2f(-0.655, -0.215);
glVertex2f(-0.67, -0.24);
glEnd();

glBegin(GL_LINES); //stairs back crane
glColor3ub(173, 141, 7);
glVertex2f(-0.695, 0.205);
glVertex2f(-0.695, -0.275);
glVertex2f(-0.685, -0.275);
glVertex2f(-0.685, 0.205);
glVertex2f(-0.695, 0.2);
glVertex2f(-0.685, 0.2);
glVertex2f(-0.695, 0.18);
glVertex2f(-0.685, 0.18);
glVertex2f(-0.695, 0.18);
glVertex2f(-0.685, 0.18);
glVertex2f(-0.695, 0.16);
glVertex2f(-0.685, 0.16);
glVertex2f(-0.695, 0.14);
glVertex2f(-0.685, 0.14);
glVertex2f(-0.695, 0.12);
glVertex2f(-0.685, 0.12);
glVertex2f(-0.695, 0.1);
glVertex2f(-0.685, 0.1);
glVertex2f(-0.695, 0.08);
glVertex2f(-0.685, 0.08);
glVertex2f(-0.695, 0.06);
glVertex2f(-0.685, 0.06);
glVertex2f(-0.695, 0.04);
glVertex2f(-0.685, 0.04);
glVertex2f(-0.695, 0.02);
glVertex2f(-0.685, 0.02);
glVertex2f(-0.695, 0.0);
glVertex2f(-0.685, 0.0);
glVertex2f(-0.695, -0.02);
glVertex2f(-0.685, -0.02);
glVertex2f(-0.695, -0.04);
glVertex2f(-0.685, -0.04);
glVertex2f(-0.695, -0.06);
glVertex2f(-0.685, -0.06);
glVertex2f(-0.695, -0.08);
glVertex2f(-0.685, -0.08);
glVertex2f(-0.695, -0.1);
glVertex2f(-0.685, -0.1);
glVertex2f(-0.695, -0.12);
glVertex2f(-0.685, -0.12);
glVertex2f(-0.695, -0.14);
glVertex2f(-0.685, -0.14);
glVertex2f(-0.695, -0.16);
glVertex2f(-0.685, -0.16);
glVertex2f(-0.695, -0.18);
glVertex2f(-0.685, -0.18);
glVertex2f(-0.695, -0.2);
glVertex2f(-0.685, -0.2);
glVertex2f(-0.695, -0.22);
glVertex2f(-0.685, -0.22);
glVertex2f(-0.695, -0.24);
glVertex2f(-0.685, -0.24);
glVertex2f(-0.695, -0.26);
glVertex2f(-0.685, -0.26);
glEnd();

glBegin(GL_QUADS);// middle horaizental stand
glColor3ub(164, 129, 3);
glVertex2f(-0.79, 0.044);
glVertex2f(-0.79, 0.028);
glVertex2f(-0.654, 0.028);
glVertex2f(-0.654, 0.044);
glEnd();

glBegin(GL_QUADS);// middle horaizental stand
glColor3ub(164, 129, 3);
glVertex2f(-0.79, -0.12);
glVertex2f(-0.79, -0.14);
glVertex2f(-0.654, -0.14);
glVertex2f(-0.654, -0.12);
glEnd();


glBegin(GL_QUADS);// middle cross top
glColor3ub(164, 129, 3);
glVertex2f(-0.79, 0.155);
glVertex2f(-0.79, 0.145);
glVertex2f(-0.655, 0.067);
glVertex2f(-0.655, 0.075);
glEnd();

glBegin(GL_QUADS);// middle cross top
glColor3ub(164, 129, 3);
glVertex2f(-0.79, 0.074);
glVertex2f(-0.79, 0.064);
glVertex2f(-0.655, 0.145);
glVertex2f(-0.655, 0.153);
glEnd();

glBegin(GL_QUADS);// middle cross down
glColor3ub(164, 129, 3);
glVertex2f(-0.79, 0.00);
glVertex2f(-0.79, -0.01);
glVertex2f(-0.655, -0.0885);
glVertex2f(-0.655, -0.08);
glEnd();

glBegin(GL_QUADS);// middle cross down
glColor3ub(164, 129, 3);
glVertex2f(-0.79, -0.085);
glVertex2f(-0.79, -0.095);
glVertex2f(-0.655, -0.011);
glVertex2f(-0.655, -0.002);
glEnd();

glBegin(GL_QUADS);// middle sea
glColor3ub(29, 131, 179);
glVertex2f(-1, -0.38);
glVertex2f(-1, -0.58);
glVertex2f(1, -0.58);
glVertex2f(1, -0.38);
glEnd();




//Ship Front START//
glBegin(GL_QUADS);//steel behind railing
glColor3ub(170, 171, 166);
glVertex2f(-0.32, -0.47);
glVertex2f(-0.32, -0.49);
glVertex2f(0.08, -0.49);
glVertex2f(0.08, -0.47);
glEnd();

//ship cargo start
glBegin(GL_QUADS);//down raw left to right
glColor3ub(136, 83, 173);
glVertex2f(-0.34, -0.4);
glVertex2f(-0.34, -0.47);
glVertex2f(-0.25, -0.47);
glVertex2f(-0.25, -0.4);
glEnd();

glBegin(GL_QUADS);//down raw left to right
glColor3ub(52, 182, 86);
glVertex2f(-0.25, -0.4);
glVertex2f(-0.16, -0.4);
glVertex2f(-0.16, -0.47);
glVertex2f(-0.25, -0.47);
glEnd();

glBegin(GL_QUADS);//down raw left to right
glColor3ub(185, 105, 44);
glVertex2f(-0.16, -0.4);
glVertex2f(-0.07, -0.4);
glVertex2f(-0.07, -0.47);
glVertex2f(-0.16, -0.47);
glEnd();

glBegin(GL_QUADS);//down raw left to right
glColor3ub(220, 75, 158);
glVertex2f(-0.07, -0.4);
glVertex2f(0.01, -0.4);
glVertex2f(0.01, -0.47);
glVertex2f(-0.07, -0.47);
glEnd();

glBegin(GL_QUADS);//down raw left to right
glColor3ub(234, 218, 52);
glVertex2f(0.01, -0.4);
glVertex2f(0.1, -0.4);
glVertex2f(0.1, -0.47);
glVertex2f(0.01, -0.47);
glEnd();

glBegin(GL_QUADS);//down raw left to right
glColor3ub(50, 202, 94);
glVertex2f(0.1, -0.4);
glVertex2f(0.19, -0.4);
glVertex2f(0.19, -0.47);
glVertex2f(0.1, -0.47);
glEnd();

glBegin(GL_QUADS);//middle raw left to right
glColor3ub(82, 217, 214);
glVertex2f(-0.34, -0.34);
glVertex2f(-0.25, -0.34);
glVertex2f(-0.25, -0.4);
glVertex2f(-0.34, -0.4);
glEnd();

glBegin(GL_QUADS);//middle raw left to right
glColor3ub(215, 209, 63);
glVertex2f(-0.25, -0.34);
glVertex2f(-0.16, -0.34);
glVertex2f(-0.16, -0.4);
glVertex2f(-0.25, -0.4);
glEnd();

glBegin(GL_QUADS);//middle raw left to right
glColor3ub(182, 48, 52);
glVertex2f(-0.16, -0.34);
glVertex2f(-0.07, -0.34);
glVertex2f(-0.07, -0.4);
glVertex2f(-0.16, -0.4);
glEnd();

glBegin(GL_QUADS);//middle raw left to right
glColor3ub(75, 104, 148);
glVertex2f(-0.07, -0.34);
glVertex2f(0.01, -0.34);
glVertex2f(0.01, -0.4);
glVertex2f(-0.07, -0.4);
glEnd();

glBegin(GL_QUADS);//middle raw left to right
glColor3ub(198, 35, 38);
glVertex2f(0.01, -0.34);
glVertex2f(0.1, -0.34);
glVertex2f(0.1, -0.4);
glVertex2f(0.01, -0.4);
glEnd();

glBegin(GL_QUADS);//middle raw left to right
glColor3ub(206, 196, 30);
glVertex2f(0.1, -0.34);
glVertex2f(0.19, -0.34);
glVertex2f(0.19, -0.4);
glVertex2f(0.1, -0.4);
glEnd();

glBegin(GL_QUADS);//middle raw left to right
glColor3ub(29, 33, 168);
glVertex2f(-0.34, -0.27);
glVertex2f(-0.25, -0.27);
glVertex2f(-0.25, -0.34);
glVertex2f(-0.34, -0.34);
glEnd();

glBegin(GL_QUADS);//middle raw left to right
glColor3ub(29, 169, 161);
glVertex2f(-0.25, -0.27);
glVertex2f(-0.16, -0.27);
glVertex2f(-0.16, -0.34);
glVertex2f(-0.25, -0.34);
glEnd();

glBegin(GL_QUADS);//middle raw left to right
glColor3ub(154, 100, 188);
glVertex2f(-0.16, -0.27);
glVertex2f(-0.07, -0.27);
glVertex2f(-0.07, -0.34);
glVertex2f(-0.16, -0.34);
glEnd();

glBegin(GL_QUADS);//middle raw left to right
glColor3ub(211, 160, 69);
glVertex2f(-0.07, -0.27);
glVertex2f(0.01, -0.27);
glVertex2f(0.01, -0.34);
glVertex2f(-0.07, -0.34);
glEnd();

glBegin(GL_QUADS);//middle raw left to right
glColor3ub(132, 91, 158);
glVertex2f(0.01, -0.27);
glVertex2f(0.1, -0.27);
glVertex2f(0.1, -0.34);
glVertex2f(0.01, -0.34);
glEnd();

glBegin(GL_QUADS);//middle raw left to right
glColor3ub(40, 45, 176);
glVertex2f(0.19, -0.27);
glVertex2f(0.28, -0.27);
glVertex2f(0.28, -0.34);
glVertex2f(0.19, -0.34);
glEnd();

glBegin(GL_QUADS);//middle raw left to right
glColor3ub(155, 163, 94);
glVertex2f(0.1, -0.27);
glVertex2f(0.19, -0.27);
glVertex2f(0.19, -0.34);
glVertex2f(0.1, -0.34);
glEnd();

glBegin(GL_QUADS);//top raw left to right
glColor3ub(40, 45, 176);
glVertex2f(-0.16, -0.2);
glVertex2f(-0.07, -0.2);
glVertex2f(-0.07, -0.27);
glVertex2f(-0.16, -0.27);
glEnd();



glBegin(GL_QUADS);//top raw left to right
glColor3ub(205, 62, 68);
glVertex2f(0.1, -0.2);
glVertex2f(0.19, -0.2);
glVertex2f(0.19, -0.27);
glVertex2f(0.1, -0.27);
glEnd();





glBegin(GL_LINES);//down raw left
glColor3ub(64, 64, 64);
glVertex2f(-0.34, -0.4);//1
glVertex2f(-0.34, -0.47);
glVertex2f(-0.34, -0.47);
glVertex2f(-0.25, -0.47);
glVertex2f(-0.25, -0.47);
glVertex2f(-0.25, -0.4);
glVertex2f(-0.25, -0.4);
glVertex2f(-0.34, -0.4);

glVertex2f(-0.25, -0.4);//2
glVertex2f(-0.16, -0.4);
glVertex2f(-0.16, -0.4);
glVertex2f(-0.16, -0.47);
glVertex2f(-0.16, -0.47);
glVertex2f(-0.25, -0.47);
glVertex2f(-0.25, -0.47);
glVertex2f(-0.25, -0.4);

glVertex2f(-0.16, -0.4);//3
glVertex2f(-0.07, -0.4);
glVertex2f(-0.07, -0.4);
glVertex2f(-0.07, -0.47);
glVertex2f(-0.07, -0.47);
glVertex2f(-0.16, -0.47);
glVertex2f(-0.16, -0.47);
glVertex2f(-0.16, -0.4);

glVertex2f(-0.07, -0.4);//4
glVertex2f(0.01, -0.4);
glVertex2f(0.01, -0.4);
glVertex2f(0.01, -0.47);
glVertex2f(0.01, -0.47);
glVertex2f(-0.07, -0.47);
glVertex2f(-0.07, -0.47);
glVertex2f(-0.07, -0.4);

glVertex2f(0.01, -0.4);//5
glVertex2f(0.1, -0.4);
glVertex2f(0.1, -0.4);
glVertex2f(0.1, -0.47);
glVertex2f(0.1, -0.47);
glVertex2f(0.01, -0.47);
glVertex2f(0.01, -0.47);
glVertex2f(0.01, -0.4);

glVertex2f(0.1, -0.4);//6
glVertex2f(0.19, -0.4);
glVertex2f(0.19, -0.4);
glVertex2f(0.19, -0.47);
glVertex2f(0.19, -0.47);
glVertex2f(0.1, -0.47);
glVertex2f(0.1, -0.47);
glVertex2f(0.1, -0.4);

glVertex2f(-0.34, -0.34);//7
glVertex2f(-0.25, -0.34);
glVertex2f(-0.25, -0.34);
glVertex2f(-0.25, -0.4);
glVertex2f(-0.25, -0.4);
glVertex2f(-0.34, -0.4);
glVertex2f(-0.34, -0.4);
glVertex2f(-0.34, -0.34);

glVertex2f(-0.25, -0.34);//8
glVertex2f(-0.16, -0.34);
glVertex2f(-0.16, -0.34);
glVertex2f(-0.16, -0.4);
glVertex2f(-0.16, -0.4);
glVertex2f(-0.25, -0.4);
glVertex2f(-0.25, -0.4);
glVertex2f(-0.25, -0.34);

glVertex2f(-0.16, -0.34);//7
glVertex2f(-0.07, -0.34);
glVertex2f(-0.07, -0.34);
glVertex2f(-0.07, -0.4);
glVertex2f(-0.07, -0.4);
glVertex2f(-0.16, -0.4);
glVertex2f(-0.16, -0.4);
glVertex2f(-0.16, -0.34);

glVertex2f(-0.07, -0.34);//8
glVertex2f(0.01, -0.34);
glVertex2f(0.01, -0.34);
glVertex2f(0.01, -0.4);
glVertex2f(0.01, -0.4);
glVertex2f(-0.07, -0.4);
glVertex2f(-0.07, -0.4);
glVertex2f(-0.07, -0.34);

glVertex2f(0.01, -0.34);//9
glVertex2f(0.1, -0.34);
glVertex2f(0.1, -0.34);
glVertex2f(0.1, -0.4);
glVertex2f(0.1, -0.4);
glVertex2f(0.01, -0.4);
glVertex2f(0.01, -0.4);
glVertex2f(0.01, -0.34);

glVertex2f(0.1, -0.34);//10
glVertex2f(0.19, -0.34);
glVertex2f(0.19, -0.34);
glVertex2f(0.19, -0.4);
glVertex2f(0.19, -0.4);
glVertex2f(0.1, -0.4);
glVertex2f(0.1, -0.4);
glVertex2f(0.1, -0.34);

glVertex2f(-0.34, -0.27);//11
glVertex2f(-0.25, -0.27);
glVertex2f(-0.25, -0.27);
glVertex2f(-0.25, -0.34);
glVertex2f(-0.25, -0.34);
glVertex2f(-0.34, -0.34);
glVertex2f(-0.34, -0.34);
glVertex2f(-0.34, -0.27);

glVertex2f(-0.25, -0.27);//12
glVertex2f(-0.16, -0.27);
glVertex2f(-0.16, -0.27);
glVertex2f(-0.16, -0.34);
glVertex2f(-0.16, -0.34);
glVertex2f(-0.25, -0.34);
glVertex2f(-0.25, -0.34);
glVertex2f(-0.25, -0.27);

glVertex2f(-0.16, -0.27);//13
glVertex2f(-0.07, -0.27);
glVertex2f(-0.07, -0.27);
glVertex2f(-0.07, -0.34);
glVertex2f(-0.07, -0.34);
glVertex2f(-0.16, -0.34);
glVertex2f(-0.16, -0.34);
glVertex2f(-0.16, -0.27);

glVertex2f(-0.07, -0.27);//14
glVertex2f(0.01, -0.27);
glVertex2f(0.01, -0.27);
glVertex2f(0.01, -0.34);
glVertex2f(0.01, -0.34);
glVertex2f(-0.07, -0.34);
glVertex2f(-0.07, -0.34);
glVertex2f(-0.07, -0.27);

glVertex2f(0.01, -0.27);//15
glVertex2f(0.1, -0.27);
glVertex2f(0.1, -0.27);
glVertex2f(0.1, -0.34);
glVertex2f(0.1, -0.34);
glVertex2f(0.01, -0.34);
glVertex2f(0.01, -0.34);
glVertex2f(0.01, -0.27);

glVertex2f(0.19, -0.27);//16
glVertex2f(0.28, -0.27);
glVertex2f(0.28, -0.27);
glVertex2f(0.28, -0.34);
glVertex2f(0.28, -0.34);
glVertex2f(0.19, -0.34);
glVertex2f(0.19, -0.34);
glVertex2f(0.19, -0.27);

glVertex2f(-0.16, -0.2);//17
glVertex2f(-0.07, -0.2);
glVertex2f(-0.07, -0.2);
glVertex2f(-0.07, -0.27);
glVertex2f(-0.07, -0.27);
glVertex2f(-0.16, -0.27);
glVertex2f(-0.16, -0.27);
glVertex2f(-0.16, -0.2);


glVertex2f(0.1, -0.2);//19
glVertex2f(0.19, -0.2);
glVertex2f(0.19, -0.2);
glVertex2f(0.19, -0.27);
glVertex2f(0.19, -0.27);
glVertex2f(0.1, -0.27);
glVertex2f(0.1, -0.27);
glVertex2f(0.1, -0.2);

glVertex2f(0.1, -0.27);//20
glVertex2f(0.19, -0.27);
glVertex2f(0.19, -0.27);
glVertex2f(0.19, -0.34);
glVertex2f(0.19, -0.34);
glVertex2f(0.1, -0.34);
glVertex2f(0.1, -0.34);
glVertex2f(0.1, -0.27);





glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.335, -0.44);
glVertex2f(-0.33, -0.445);
glVertex2f(-0.33, -0.465);
glVertex2f(-0.335, -0.465);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.335, -0.44);
glVertex2f(-0.33, -0.445);
glVertex2f(0.095, -0.445);
glVertex2f(0.1, -0.44);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(0.07, -0.445);
glVertex2f(0.07, -0.48);
glVertex2f(0.075, -0.48);
glVertex2f(0.075, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(0.035, -0.445);
glVertex2f(0.035, -0.48);
glVertex2f(0.04, -0.48);
glVertex2f(0.04, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(0.005, -0.445);
glVertex2f(0.005, -0.48);
glVertex2f(0.01, -0.48);
glVertex2f(0.01, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.025, -0.445);
glVertex2f(-0.025, -0.48);
glVertex2f(-0.02, -0.48);
glVertex2f(-0.02, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.055, -0.445);
glVertex2f(-0.055, -0.48);
glVertex2f(-0.05, -0.48);
glVertex2f(-0.05, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.085, -0.445);
glVertex2f(-0.085, -0.48);
glVertex2f(-0.08, -0.48);
glVertex2f(-0.08, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.115, -0.445);
glVertex2f(-0.115, -0.48);
glVertex2f(-0.11, -0.48);
glVertex2f(-0.11, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.145, -0.445);
glVertex2f(-0.145, -0.48);
glVertex2f(-0.14, -0.48);
glVertex2f(-0.14, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.18, -0.445);
glVertex2f(-0.18, -0.48);
glVertex2f(-0.175, -0.48);
glVertex2f(-0.175, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.21, -0.445);
glVertex2f(-0.21, -0.48);
glVertex2f(-0.205, -0.48);
glVertex2f(-0.205, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.24, -0.445);
glVertex2f(-0.24, -0.48);
glVertex2f(-0.235, -0.48);
glVertex2f(-0.235, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.27, -0.445);
glVertex2f(-0.27, -0.48);
glVertex2f(-0.265, -0.48);
glVertex2f(-0.265, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.305, -0.445);
glVertex2f(-0.305, -0.48);
glVertex2f(-0.3, -0.48);
glVertex2f(-0.3, -0.445);
glEnd();

glBegin(GL_QUADS);//cabin left
glColor3ub(211, 211, 207);
glVertex2f(-0.46, -0.27);
glVertex2f(-0.46, -0.46);
glVertex2f(-0.38, -0.46);
glVertex2f(-0.38, -0.27);
glEnd();

glBegin(GL_QUADS);//cabin middle
glColor3ub(204, 204, 204);
glVertex2f(-0.5, -0.27);
glVertex2f(-0.5, -0.46);
glVertex2f(-0.46, -0.46);
glVertex2f(-0.46, -0.27);
glEnd();

glBegin(GL_QUADS);//cabin right
glColor3ub(198, 198, 198);
glVertex2f(-0.58, -0.27);
glVertex2f(-0.58, -0.46);
glVertex2f(-0.5, -0.46);
glVertex2f(-0.5, -0.27);
glEnd();


glBegin(GL_QUADS);//cabin glass left
glColor3ub(255, 255, 0);
glVertex2f(-0.46, -0.246);
glVertex2f(-0.46, -0.27);
glVertex2f(-0.386, -0.27);
glVertex2f(-0.386, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin glass middle
glColor3ub(230, 230, 0);
glVertex2f(-0.5, -0.246);
glVertex2f(-0.5, -0.27);
glVertex2f(-0.46, -0.27);
glVertex2f(-0.46, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin glass right
glColor3ub(204, 204, 0);
glVertex2f(-0.572, -0.246);
glVertex2f(-0.572, -0.27);
glVertex2f(-0.5, -0.27);
glVertex2f(-0.5, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin glass railing left
glColor3ub(150, 150, 150);
glVertex2f(-0.556, -0.246);
glVertex2f(-0.556, -0.27);
glVertex2f(-0.554, -0.27);
glVertex2f(-0.554, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin glass railing left
glColor3ub(150, 150, 150);
glVertex2f(-0.536, -0.246);
glVertex2f(-0.536, -0.27);
glVertex2f(-0.534, -0.27);
glVertex2f(-0.534, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin glass railing middle
glColor3ub(160, 160, 154);
glVertex2f(-0.494, -0.246);
glVertex2f(-0.494, -0.27);
glVertex2f(-0.492, -0.27);
glVertex2f(-0.492, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin glass railing middle
glColor3ub(160, 160, 154);
glVertex2f(-0.468, -0.246);
glVertex2f(-0.468, -0.27);
glVertex2f(-0.466, -0.27);
glVertex2f(-0.466, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin glass railing right
glColor3ub(182, 181, 188);
glVertex2f(-0.424, -0.246);
glVertex2f(-0.424, -0.27);
glVertex2f(-0.422, -0.27);
glVertex2f(-0.422, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin glass railing right
glColor3ub(182, 181, 188);
glVertex2f(-0.404, -0.246);
glVertex2f(-0.404, -0.27);
glVertex2f(-0.402, -0.27);
glVertex2f(-0.402, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin left
glColor3ub(211, 211, 207);
glVertex2f(-0.46, -0.2);
glVertex2f(-0.365, -0.2);
glVertex2f(-0.372, -0.246);
glVertex2f(-0.46, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin middle
glColor3ub(204, 204, 204);
glVertex2f(-0.5, -0.2);
glVertex2f(-0.46, -0.2);
glVertex2f(-0.46, -0.246);
glVertex2f(-0.5, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin right
glColor3ub(198, 198, 198);
glVertex2f(-0.59, -0.2);
glVertex2f(-0.582, -0.246);
glVertex2f(-0.5, -0.246);
glVertex2f(-0.5, -0.2);
glEnd();


glBegin(GL_QUADS);//cabin middle left
glColor3ub(174, 172, 174);
glVertex2f(-0.46, -0.165);
glVertex2f(-0.405, -0.165);
glVertex2f(-0.405, -0.2);
glVertex2f(-0.46, -0.2);
glEnd();

glBegin(GL_QUADS);//cabin middle middle
glColor3ub(142, 144, 145);
glVertex2f(-0.5, -0.165);
glVertex2f(-0.46, -0.165);
glVertex2f(-0.46, -0.2);
glVertex2f(-0.5, -0.2);
glEnd();

glBegin(GL_QUADS);//cabin middle  right
glColor3ub(127, 129, 130);
glVertex2f(-0.55, -0.165);
glVertex2f(-0.5, -0.165);
glVertex2f(-0.5, -0.2);
glVertex2f(-0.55, -0.2);
glEnd();


glBegin(GL_QUADS);//cabin middle top left
glColor3ub(185, 180, 181);
glVertex2f(-0.46, -0.095);
glVertex2f(-0.388, -0.095);
glVertex2f(-0.402, -0.165);
glVertex2f(-0.46, -0.165);
glEnd();

glBegin(GL_QUADS);//cabin middle top middle
glColor3ub(163, 163, 161);
glVertex2f(-0.5, -0.095);
glVertex2f(-0.46, -0.095);
glVertex2f(-0.46, -0.165);
glVertex2f(-0.5, -0.165);
glEnd();

glBegin(GL_QUADS);//cabin middle top  right
glColor3ub(153, 151, 149);
glVertex2f(-0.565, -0.095);
glVertex2f(-0.5, -0.095);
glVertex2f(-0.5, -0.165);
glVertex2f(-0.555, -0.165);
glEnd();

glBegin(GL_QUADS);//cabin middle top top left
glColor3ub(188, 184, 185);
glVertex2f(-0.46, -0.08);
glVertex2f(-0.46, -0.095);
glVertex2f(-0.384, -0.095);
glVertex2f(-0.39, -0.08);
glEnd();

glBegin(GL_QUADS);//cabin middle top top middle
glColor3ub(163, 163, 161);
glVertex2f(-0.5, -0.08);
glVertex2f(-0.46, -0.08);
glVertex2f(-0.46, -0.095);
glVertex2f(-0.5, -0.095);
glEnd();

glBegin(GL_QUADS);//cabin middle top top  right
glColor3ub(153, 151, 149);
glVertex2f(-0.565, -0.08);
glVertex2f(-0.5, -0.08);
glVertex2f(-0.5, -0.095);
glVertex2f(-0.57, -0.095);
glEnd();

glBegin(GL_LINES);//cabin middle top top  right
glColor3ub(124, 121, 119);
glVertex2f(-0.565, -0.08);
glVertex2f(-0.39, -0.08);
glVertex2f(-0.39, -0.08);
glVertex2f(-0.384, -0.095);
glVertex2f(-0.384, -0.095);
glVertex2f(-0.57, -0.095);
glVertex2f(-0.57, -0.095);
glVertex2f(-0.565, -0.08);
glEnd();

glBegin(GL_QUADS);//cabin middle top top left
glColor3ub(183, 183, 183);
glVertex2f(-0.46, -0.055);
glVertex2f(-0.395, -0.055);
glVertex2f(-0.39, -0.08);
glVertex2f(-0.46, -0.08);
glEnd();

glBegin(GL_QUADS);//cabin middle top top middle
glColor3ub(163, 161, 161);
glVertex2f(-0.5, -0.055);
glVertex2f(-0.46, -0.055);
glVertex2f(-0.46, -0.08);
glVertex2f(-0.5, -0.08);
glEnd();

glBegin(GL_QUADS);//cabin middle top top  right
glColor3ub(155, 155, 152);
glVertex2f(-0.56, -0.055);
glVertex2f(-0.565, -0.08);
glVertex2f(-0.5, -0.08);
glVertex2f(-0.5, -0.055);
glEnd();

glBegin(GL_LINES);//cabin middle top top  right
glColor3ub(124, 121, 119);
glVertex2f(-0.565, -0.08);
glVertex2f(-0.39, -0.08);
glVertex2f(-0.39, -0.08);
glVertex2f(-0.384, -0.095);
glVertex2f(-0.384, -0.095);
glVertex2f(-0.57, -0.095);
glVertex2f(-0.57, -0.095);
glVertex2f(-0.565, -0.08);
glEnd();


glBegin(GL_QUADS);//cabin middle glass left
glColor3ub(255, 255, 0);
glVertex2f(-0.46, -0.1);
glVertex2f(-0.44, -0.1);
glVertex2f(-0.45, -0.16);
glVertex2f(-0.46, -0.16);
glEnd();
glBegin(GL_QUADS);//cabin middle glass left
glColor3ub(255, 255, 0);
glVertex2f(-0.435, -0.1);
glVertex2f(-0.395, -0.1);
glVertex2f(-0.408, -0.16);
glVertex2f(-0.445, -0.16);
glEnd();

glBegin(GL_QUADS);//cabin middle glass middle
glColor3ub(230, 230, 0);
glVertex2f(-0.5, -0.1);
glVertex2f(-0.46, -0.1);
glVertex2f(-0.46, -0.16);
glVertex2f(-0.5, -0.16);
glEnd();

glBegin(GL_QUADS);//cabin middle glass right
glColor3ub(204, 204, 0);
glVertex2f(-0.56, -0.1);
glVertex2f(-0.52, -0.1);
glVertex2f(-0.51, -0.16);
glVertex2f(-0.55, -0.16);
glEnd();
glBegin(GL_QUADS);//cabin middle glass right
glColor3ub(204, 204, 0);
glVertex2f(-0.515, -0.1);
glVertex2f(-0.5, -0.1);
glVertex2f(-0.5, -0.16);
glVertex2f(-0.505, -0.16);
glEnd();


glBegin(GL_LINES);//cabin railing right
glColor3ub(198, 198, 198);
glVertex2f(-0.59, -0.175);
glVertex2f(-0.5, -0.175);
glVertex2f(-0.5, -0.175);
glVertex2f(-0.5, -0.2);
glVertex2f(-0.5, -0.2);
glVertex2f(-0.59, -0.2);
glVertex2f(-0.59, -0.2);
glVertex2f(-0.59, -0.175);

glVertex2f(-0.58, -0.175);
glVertex2f(-0.58, -0.2);
glVertex2f(-0.56, -0.175);
glVertex2f(-0.56, -0.2);
glVertex2f(-0.54, -0.175);
glVertex2f(-0.54, -0.2);
glVertex2f(-0.52, -0.175);
glVertex2f(-0.52, -0.2);

glBegin(GL_LINES);//cabin railing middle
glColor3ub(204, 204, 204);
glVertex2f(-0.5, -0.175);
glVertex2f(-0.46, -0.175);
glVertex2f(-0.46, -0.175);
glVertex2f(-0.46, -0.2);
glVertex2f(-0.46, -0.2);
glVertex2f(-0.5, -0.2);
glVertex2f(-0.5, -0.2);
glVertex2f(-0.5, -0.175);
glVertex2f(-0.48, -0.175);
glVertex2f(-0.48, -0.2);
glEnd();

glBegin(GL_LINES);//cabin left
glColor3ub(211, 211, 207);
glVertex2f(-0.46, -0.175);
glVertex2f(-0.365, -0.175);
glVertex2f(-0.365, -0.175);
glVertex2f(-0.365, -0.2);
glVertex2f(-0.365, -0.2);
glVertex2f(-0.46, -0.2);
glVertex2f(-0.46, -0.2);
glVertex2f(-0.46, -0.175);

glVertex2f(-0.44, -0.175);
glVertex2f(-0.44, -0.2);
glVertex2f(-0.42, -0.175);
glVertex2f(-0.42, -0.2);
glVertex2f(-0.4, -0.175);
glVertex2f(-0.4, -0.2);
glVertex2f(-0.38, -0.175);
glVertex2f(-0.38, -0.2);
glEnd();

glBegin(GL_QUADS);//pole
glColor3ub(255, 255, 255);
glVertex2f(-0.54, 0.04);
glVertex2f(-0.535, 0.04);
glVertex2f(-0.535, -0.055);
glVertex2f(-0.54, -0.055);
glEnd();

glBegin(GL_QUADS);//pole red line
glColor3ub(216, 54, 45);
glVertex2f(-0.54, 0.025);
glVertex2f(-0.535, 0.025);
glVertex2f(-0.535, 0.01);
glVertex2f(-0.54, 0.01);
glEnd();

glBegin(GL_QUADS);//pole red line
glColor3ub(216, 54, 45);
glVertex2f(-0.54, -0.005);
glVertex2f(-0.535, -0.005);
glVertex2f(-0.535, -0.02);
glVertex2f(-0.54, -0.02);
glEnd();

glBegin(GL_QUADS);//pole
glColor3ub(255, 255, 255);
glVertex2f(-0.525, 0.005);
glVertex2f(-0.52, 0.005);
glVertex2f(-0.52, -0.055);
glVertex2f(-0.525, -0.055);
glEnd();

glBegin(GL_QUADS);//pole red line
glColor3ub(216, 54, 45);
glVertex2f(-0.525, -0.005);
glVertex2f(-0.52, -0.005);
glVertex2f(-0.52, -0.02);
glVertex2f(-0.525, -0.02);
glEnd();

glBegin(GL_QUADS);//pole red line
glColor3ub(216, 54, 45);
glVertex2f(-0.525, -0.035);
glVertex2f(-0.52, -0.035);
glVertex2f(-0.52, -0.05);
glVertex2f(-0.525, -0.05);
glEnd();

glBegin(GL_QUADS);//pole
glColor3ub(255, 255, 255);
glVertex2f(-0.415, 0.005);
glVertex2f(-0.41, 0.005);
glVertex2f(-0.41, -0.055);
glVertex2f(-0.415, -0.055);
glEnd();

glBegin(GL_QUADS);//pole red line
glColor3ub(216, 54, 45);
glVertex2f(-0.415, -0.005);
glVertex2f(-0.41, -0.005);
glVertex2f(-0.41, -0.015);
glVertex2f(-0.415, -0.015);
glEnd();
glBegin(GL_QUADS);//pole red line
glColor3ub(216, 54, 45);
glVertex2f(-0.415, -0.025);
glVertex2f(-0.41, -0.025);
glVertex2f(-0.41, -0.035);
glVertex2f(-0.415, -0.035);
glEnd();

glBegin(GL_QUADS);//pole
glColor3ub(155, 157, 151);
glVertex2f(-0.48, 0.07);
glVertex2f(-0.475, 0.07);
glVertex2f(-0.475, -0.055);
glVertex2f(-0.48, -0.055);
glEnd();

glBegin(GL_QUADS);//pole
glColor3ub(147, 147, 144);
glVertex2f(-0.48, 0.07);
glVertex2f(-0.475, 0.07);
glVertex2f(-0.475, 0.07);
glVertex2f(-0.475, -0.055);
glVertex2f(-0.475, -0.055);
glVertex2f(-0.48, -0.055);
glVertex2f(-0.48, -0.055);
glVertex2f(-0.48, 0.07);

glEnd();

glBegin(GL_POLYGON);//flag
glColor3ub(27, 138, 57);
glVertex2f(-0.48, 0.065);
glVertex2f(-0.486, -0.011);
glVertex2f(-0.482, -0.002);
glVertex2f(-0.481, -0.008);
glVertex2f(-0.478, -0.002);
glVertex2f(-0.479, 0.049);
glEnd();

glBegin(GL_LINES);//flag
glColor3ub(23, 119, 49);
glVertex2f(-0.48, 0.065);
glVertex2f(-0.486, -0.011);
glVertex2f(-0.486, -0.011);
glVertex2f(-0.482, -0.002);
glVertex2f(-0.482, -0.002);
glVertex2f(-0.481, -0.008);
glVertex2f(-0.481, -0.008);
glVertex2f(-0.478, -0.002);
glVertex2f(-0.478, -0.002);
glVertex2f(-0.479, 0.049);
glVertex2f(-0.479, 0.049);
glVertex2f(-0.48, 0.065);
glEnd();

glBegin(GL_POLYGON);//flag circle
glColor3ub(214, 32, 38);
glVertex2f(-0.481, 0.036);
glVertex2f(-0.482, 0.014);
glVertex2f(-0.48, 0.018);
glVertex2f(-0.479, 0.015);
glVertex2f(-0.4805, 0.033);
glEnd();



	   GLfloat x4=-.52f; GLfloat y4=-.35f; GLfloat radius4 =0.012f;
	int triangleAmount4 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi4 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 204, 0); //left window
		glVertex2f(x4, y4); // center of circle
		for(i = 0; i <= triangleAmount4;i++) {
			glVertex2f(
		            x4 + (radius4 * cos(i *  twicePi4 / triangleAmount4)),
			    y4 + (radius4 * sin(i * twicePi4 / triangleAmount4))
			);
		}
	glEnd();


		   GLfloat x5=-.52f; GLfloat y5=-.39f; GLfloat radius5 =0.012f;
	int triangleAmount5 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi5 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 204, 0); // left window
		glVertex2f(x5, y5); // center of circle
		for(i = 0; i <= triangleAmount5;i++) {
			glVertex2f(
		            x5 + (radius5* cos(i *  twicePi5 / triangleAmount5)),
			    y5 + (radius5* sin(i * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


	GLfloat x6=-.48f; GLfloat y6=-.35f; GLfloat radius6 =0.012f;
	int triangleAmount6 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi6 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(230, 230, 0); // middle window
		glVertex2f(x6, y6); // center of circle
		for(i = 0; i <= triangleAmount6;i++) {
			glVertex2f(
		            x6 + (radius6* cos(i *  twicePi6 / triangleAmount6)),
			    y6 + (radius6* sin(i * twicePi6 / triangleAmount6))
			);
		}
	glEnd();


	GLfloat x7=-.48f; GLfloat y7=-.39f; GLfloat radius7 =0.012f;
	int triangleAmount7 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi7 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(230, 230, 0); // middle window
		glVertex2f(x7, y7); // center of circle
		for(i = 0; i <= triangleAmount7;i++) {
			glVertex2f(
		            x7 + (radius7* cos(i *  twicePi7 / triangleAmount7)),
			    y7 + (radius7* sin(i * twicePi7 / triangleAmount7))
			);
		}
	glEnd();


	GLfloat x8=-.48f; GLfloat y8=-.43f; GLfloat radius8 =0.012f;
	int triangleAmount8 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi8 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(230, 230, 0); // middle window
		glVertex2f(x8, y8); // center of circle
		for(i = 0; i <= triangleAmount8;i++) {
			glVertex2f(
		            x8 + (radius8* cos(i *  twicePi8 / triangleAmount8)),
			    y8 + (radius8* sin(i * twicePi8 / triangleAmount8))
			);
		}
	glEnd();


GLfloat x9=-0.44f; GLfloat y9=-0.35f; GLfloat radius9 =0.012f;
	int triangleAmount9 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi9 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 0); // windmill
		glVertex2f(x9, y9); // center of circle
		for(i = 0; i <= triangleAmount9;i++) {
			glVertex2f(
		            x9 + (radius9 * cos(i *  twicePi9 / triangleAmount9)),
			    y9 + (radius9 * sin(i * twicePi9 / triangleAmount9))
			);
		}
	glEnd();


		GLfloat x10=-0.44f; GLfloat y10=-0.39f; GLfloat radius10 =0.012f;
	int triangleAmount10 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi10 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 0); // windmill
		glVertex2f(x10, y10); // center of circle
		for(i = 0; i <= triangleAmount10;i++) {
			glVertex2f(
		            x10 + (radius10 * cos(i *  twicePi10 / triangleAmount10)),
			    y10 + (radius10 * sin(i * twicePi10 / triangleAmount10))
			);
		}
	glEnd();


	GLfloat x11=-0.44f; GLfloat y11=-0.43f; GLfloat radius11 =0.012f;
	int triangleAmount11 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi11 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 0); // windmill
		glVertex2f(x11, y11); // center of circle
		for(i = 0; i <= triangleAmount11;i++) {
			glVertex2f(
		            x11 + (radius11 * cos(i *  twicePi11 / triangleAmount11)),
			    y11 + (radius11 * sin(i * twicePi11 / triangleAmount11))
			);
		}
	glEnd();


	GLfloat x12=-0.4f; GLfloat y12=-0.35f; GLfloat radius12 =0.012f;
	int triangleAmount12 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi12 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 0); // windmill
		glVertex2f(x12, y12); // center of circle
		for(i = 0; i <= triangleAmount12;i++) {
			glVertex2f(
		            x12 + (radius12* cos(i *  twicePi12 / triangleAmount12)),
			    y12 + (radius12 * sin(i * twicePi12 / triangleAmount12))
			);
		}
	glEnd();


	GLfloat x13=-0.4f; GLfloat y13=-0.39f; GLfloat radius13 =0.012f;
	int triangleAmount13 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi13 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 0); // windmill
		glVertex2f(x13, y13); // center of circle
		for(i = 0; i <= triangleAmount13;i++) {
			glVertex2f(
		            x13 + (radius13* cos(i *  twicePi13 / triangleAmount13)),
			    y13 + (radius13 * sin(i * twicePi13 / triangleAmount13))
			);
		}
	glEnd();

	GLfloat x14=-0.4f; GLfloat y14=-0.43f; GLfloat radius14 =0.012f;
	int triangleAmount14 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi14 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 0); // windmill
		glVertex2f(x14, y14); // center of circle
		for(i = 0; i <= triangleAmount14;i++) {
			glVertex2f(
		            x14 + (radius14* cos(i *  twicePi14 / triangleAmount14)),
			    y14 + (radius14 * sin(i * twicePi14 / triangleAmount14))
			);
		}
	glEnd();





glBegin(GL_POLYGON);//hull red
glColor3ub(164, 41, 45);
glVertex2f(-0.66, -0.325);
glVertex2f(-0.659, -0.345);
glVertex2f(-0.656, -0.37);
glVertex2f(-0.534, -0.37);
glVertex2f(-0.54, -0.345);
glVertex2f(-0.54, -0.325);
glEnd();

glBegin(GL_POLYGON);//hull red
glColor3ub(164, 41, 45);
glVertex2f(0.128, -0.328);
glVertex2f(0.126, -0.358);
glVertex2f(0.124, -0.37);
glVertex2f(0.422, -0.37);
glVertex2f(0.432, -0.34);
glVertex2f(0.434, -0.328);
glEnd();

glBegin(GL_QUADS);//hull white top
glColor3ub(252, 250, 253);
glVertex2f(-0.656, -0.37);
glVertex2f(-0.534, -0.37);
glVertex2f(-0.531, -0.382);
glVertex2f(-0.654, -0.382);
glEnd();

glBegin(GL_QUADS);//hull white top
glColor3ub(252, 250, 253);
glVertex2f(0.124, -0.37);
glVertex2f(0.122, -0.382);
glVertex2f(0.418, -0.382);
glVertex2f(0.422, -0.37);
glEnd();

glBegin(GL_POLYGON);//hull mid black
glColor3ub(88, 85, 80);
glVertex2f(-0.654, -0.382);
glVertex2f(-0.64, -0.41);
glVertex2f(-0.61, -0.45);
glVertex2f(-0.59, -0.47);
glVertex2f(-0.57, -0.5);
glVertex2f(-0.57, -0.382);
glEnd();

glBegin(GL_POLYGON);//hull mid black
glColor3ub(88, 85, 80);
glVertex2f(-0.57, -0.382);
glVertex2f(-0.57, -0.5);
glVertex2f(-0.56, -0.52);
glVertex2f(-0.5, -0.52);
glVertex2f(-0.46, -0.455);
glVertex2f(-0.495, -0.44);
glVertex2f(-0.52, -0.41);
glVertex2f(-0.531, -0.382);
glEnd();

glBegin(GL_TRIANGLES);//hull mid black
glColor3ub(88, 85, 80);
glVertex2f(-0.46, -0.455);
glVertex2f(-0.5, -0.52);
glVertex2f(-0.46, -0.52);
glEnd();

glBegin(GL_QUADS);//hull mid black
glColor3ub(88, 85, 80);
glVertex2f(-0.46, -0.455);
glVertex2f(-0.32, -0.455);
glVertex2f(-0.32, -0.52);
glVertex2f(-0.46, -0.52);
glEnd();

glBegin(GL_QUADS);//hull mid black
glColor3ub(88, 85, 80);
glVertex2f(-0.32, -0.48);
glVertex2f(0.06, -0.48);
glVertex2f(0.06, -0.52);
glVertex2f(-0.32, -0.52);
glEnd();


glBegin(GL_POLYGON);//hull mid black
glColor3ub(88, 85, 80);
glVertex2f(0.06, -0.52);
glVertex2f(0.16, -0.52);
glVertex2f(0.16, -0.382);
glVertex2f(0.122, -0.382);
glVertex2f(0.12, -0.4);
glVertex2f(0.105, -0.435);
glVertex2f(0.08, -0.465);
glVertex2f(0.06, -0.48);
glEnd();

glBegin(GL_QUADS);//hull mid black
glColor3ub(88, 85, 80);
glVertex2f(0.16, -0.382);
glVertex2f(0.36, -0.382);
glVertex2f(0.36, -0.52);
glVertex2f(0.16, -0.52);
glEnd();

glBegin(GL_POLYGON);//hull mid black
glColor3ub(88, 85, 80);
glVertex2f(0.36, -0.382);
glVertex2f(0.418, -0.382);
glVertex2f(0.41, -0.41);
glVertex2f(0.39, -0.46);
glVertex2f(0.36, -0.52);
glEnd();

glBegin(GL_QUADS);//hull mid white
glColor3ub(202, 198, 199);
glVertex2f(-0.56, -0.52);
glVertex2f(-0.552, -0.538);
glVertex2f(0.3471, -0.538);
glVertex2f(0.36, -0.52);
glEnd();

glBegin(GL_POLYGON);//hull down black
glColor3ub(88, 85, 80);
glVertex2f(-0.552, -0.538);
glVertex2f(-0.54, -0.58);
glVertex2f(0.315, -0.58);
glVertex2f(0.335, -0.555);
glVertex2f(0.3471, -0.538);
glEnd();

glBegin(GL_POLYGON);//break  down red
glColor3ub(204, 77, 67);
glVertex2f(-0.57, -0.5);
glVertex2f(-0.57, -0.58);
glVertex2f(-0.54, -0.58);
glVertex2f(-0.544, -0.56);
glVertex2f(-0.552, -0.536);
glVertex2f(-0.558, -0.52);
glVertex2f(-0.57, -0.5);
glEnd();


		GLfloat x15=0.258f; GLfloat y15=-0.438f; GLfloat radius15 =0.011f;
	int triangleAmount15 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi15 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 175, 165); // windmill
		glVertex2f(x15, y15); // center of circle
		for(i = 0; i <= triangleAmount15;i++) {
			glVertex2f(
		            x15 + (radius15* cos(i *  twicePi15 / triangleAmount15)),
			    y15 + (radius15 * sin(i * twicePi15 / triangleAmount15))
			);
		}
	glEnd();

		GLfloat x16=0.258f; GLfloat y16=-0.438f; GLfloat radius16 =0.006f;
	int triangleAmount16 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi16 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(116, 117, 112); // windmill
		glVertex2f(x16, y16); // center of circle
		for(i = 0; i <= triangleAmount16;i++) {
			glVertex2f(
		            x16 + (radius16* cos(i *  twicePi16 / triangleAmount16)),
			    y16 + (radius16 * sin(i * twicePi16 / triangleAmount16))
			);
		}
	glEnd();

glBegin(GL_QUADS);//anchor
glColor3ub(116, 117, 112);
glVertex2f(0.256, -0.448);
glVertex2f(0.26, -0.448);
glVertex2f(0.26, -0.496);
glVertex2f(0.256, -0.496);
glEnd();


glBegin(GL_POLYGON);//anchor low
glColor3ub(116, 117, 112);
glVertex2f(0.25, -0.492);
glVertex2f(0.25, -0.496);
glVertex2f(0.258, -0.502);
glVertex2f(0.266, -0.496);
glVertex2f(0.27, -0.49);
glVertex2f(0.266, -0.492);
glVertex2f(0.26, -0.496);
glVertex2f(0.256, -0.496);
glEnd();


glBegin(GL_POLYGON);//anchor low
glColor3ub(116, 117, 112);
glVertex2f(0.266, -0.492);
glVertex2f(0.27, -0.49);
glVertex2f(0.272, -0.482);
glVertex2f(0.272, -0.474);
glVertex2f(0.27, -0.474);
glVertex2f(0.27, -0.48);
glVertex2f(0.266, -0.492);
glEnd();

glBegin(GL_TRIANGLES);//anchor low
glColor3ub(116, 117, 112);
glVertex2f(0.272, -0.474);
glVertex2f(0.266, -0.474);
glVertex2f(0.272, -0.466);
glEnd();

glBegin(GL_POLYGON);//anchor low
glColor3ub(116, 117, 112);
glVertex2f(0.25, -0.492);
glVertex2f(0.25, -0.496);
glVertex2f(0.246, -0.49);
glVertex2f(0.244, -0.482);
glVertex2f(0.244, -0.474);
glVertex2f(0.246, -0.474);
glVertex2f(0.246, -0.48);
glEnd();

glBegin(GL_TRIANGLES);//anchor low
glColor3ub(116, 117, 112);
glVertex2f(0.244, -0.474);
glVertex2f(0.25, -0.474);
glVertex2f(0.244, -0.466);
glEnd();

//front ship end


//front crane start

glBegin(GL_QUADS);//brown leg
glColor3ub(109, 33, 14);
glVertex2f(0.36, -0.574);
glVertex2f(0.37, -0.574);
glVertex2f(0.37, -0.59);
glVertex2f(0.36, -0.59);
glEnd();

glBegin(GL_POLYGON);//brown leg 2
glColor3ub(109, 33, 14);
glVertex2f(0.36, -0.59);
glVertex2f(0.356, -0.594);
glVertex2f(0.356, -0.606);
glVertex2f(0.374, -0.606);
glVertex2f(0.374, -0.594);
glVertex2f(0.37, -0.59);
glEnd();

glLoadIdentity();

glBegin(GL_QUADS);//top Horaizental pole
glColor3ub(211, 139, 2);
glVertex2f(-0.14, 0.29);
glVertex2f(-0.1, 0.27);
glVertex2f(0.82, 0.27);
glVertex2f(0.82, 0.29);
glEnd();

glBegin(GL_QUADS);//top diagonal pole
glColor3ub(230, 169, 0);
glVertex2f(0.74, 0.29);
glVertex2f(0.76, 0.29);
glVertex2f(0.38, 0.6);
glVertex2f(0.38, 0.58);
glEnd();

glBegin(GL_QUADS);//top left pole
glColor3ub(232, 186, 20);
glVertex2f(0.35, 0.63);
glVertex2f(0.38, 0.63);
glVertex2f(0.38, 0.57);
glVertex2f(0.35, 0.57);
glEnd();

glBegin(GL_QUADS);//top narrow left pole
glColor3ub(230, 169, 0);
glVertex2f(0.36, 0.57);
glVertex2f(0.36, 0.356);
glVertex2f(0.37, 0.356);
glVertex2f(0.37, 0.57);
glEnd();

glBegin(GL_QUADS);//top left pole 2nd
glColor3ub(232, 186, 20);
glVertex2f(0.354, 0.356);
glVertex2f(0.376, 0.356);
glVertex2f(0.376, 0.302);
glVertex2f(0.354, 0.302);
glEnd();

glBegin(GL_QUADS);// left pole
glColor3ub(230, 169, 0);
glVertex2f(0.358, 0.302);
glVertex2f(0.372, 0.302);
glVertex2f(0.372, -0.574);
glVertex2f(0.358, -0.574);
glEnd();

glBegin(GL_QUADS);// right pole top
glColor3ub(232, 186, 20);
glVertex2f(0.61, 0.425);
glVertex2f(0.635, 0.425);
glVertex2f(0.635, 0.37);
glVertex2f(0.61, 0.37);
glEnd();

glBegin(GL_QUADS);// right pole top narrow
glColor3ub(230, 169, 0);
glVertex2f(0.615, 0.37);
glVertex2f(0.63, 0.37);
glVertex2f(0.63, 0.355);
glVertex2f(0.615, 0.355);
glEnd();

glBegin(GL_QUADS);// right pole top 2nd
glColor3ub(232, 186, 20);
glVertex2f(0.61, 0.355);
glVertex2f(0.635, 0.355);
glVertex2f(0.635, 0.3);
glVertex2f(0.61, 0.3);
glEnd();

glBegin(GL_QUADS);// right pole
glColor3ub(230, 169, 0);
glVertex2f(0.616, 0.3);
glVertex2f(0.63, 0.3);
glVertex2f(0.63, -0.475);
glVertex2f(0.616, -0.475);
glEnd();

glBegin(GL_QUADS);// cross pole top
glColor3ub(205, 154, 10);
glVertex2f(0.372, 0.18);
glVertex2f(0.616, 0.04);
glVertex2f(0.616, 0.02);
glVertex2f(0.372, 0.16);
glEnd();

glBegin(GL_QUADS);// cross pole top
glColor3ub(205, 154, 10);
glVertex2f(0.616, 0.18);
glVertex2f(0.372, 0.04);
glVertex2f(0.372, 0.02);
glVertex2f(0.616, 0.16);
glEnd();

glBegin(GL_QUADS);// cross pole down
glColor3ub(205, 154, 10);
glVertex2f(0.372, -0.11);
glVertex2f(0.616, -0.25);
glVertex2f(0.616, -0.27);
glVertex2f(0.372, -0.13);
glEnd();

glBegin(GL_QUADS);// cross pole down
glColor3ub(205, 154, 10);
glVertex2f(0.372, -0.252);
glVertex2f(0.372, -0.27);
glVertex2f(0.616, -0.125);
glVertex2f(0.616, -0.11);
glEnd();

glBegin(GL_QUADS);// horaizental pole middle top
glColor3ub(205, 154, 10);
glVertex2f(0.372, -0.02);
glVertex2f(0.372, -0.05);
glVertex2f(0.616, -0.05);
glVertex2f(0.616, -0.02);
glEnd();

glBegin(GL_QUADS);// horaizental pole middle down
glColor3ub(205, 154, 10);
glVertex2f(0.372, -0.325);
glVertex2f(0.372, -0.36);
glVertex2f(0.616, -0.36);
glVertex2f(0.616, -0.325);
glEnd();

glBegin(GL_QUADS);// top red deck
glColor3ub(237, 54, 84);
glVertex2f(0.38, 0.37);
glVertex2f(0.49, 0.37);
glVertex2f(0.49, 0.3);
glVertex2f(0.38, 0.3);
glEnd();

glBegin(GL_QUADS);// top red deck 2
glColor3ub(109, 33, 14);
glVertex2f(0.4, 0.3);
glVertex2f(0.47, 0.3);
glVertex2f(0.47, 0.29);
glVertex2f(0.4, 0.29);
glEnd();

glBegin(GL_QUADS);// top red deck window
glColor3ub(38, 38, 38);
glVertex2f(0.39, 0.36);
glVertex2f(0.39, 0.34);
glVertex2f(0.41, 0.34);
glVertex2f(0.41, 0.36);
glEnd();

glBegin(GL_QUADS);// top red deck window 2
glColor3ub(38, 38, 38);
glVertex2f(0.42, 0.36);
glVertex2f(0.42, 0.34);
glVertex2f(0.45, 0.34);
glVertex2f(0.45, 0.36);
glEnd();

glBegin(GL_QUADS);// top red deck window 3
glColor3ub(38, 38, 38);
glVertex2f(0.46, 0.36);
glVertex2f(0.46, 0.34);
glVertex2f(0.48, 0.34);
glVertex2f(0.48, 0.36);
glEnd();

glBegin(GL_QUADS);// square box near the rope
glColor3ub(109, 33, 14);
glVertex2f(0.745, 0.27);
glVertex2f(0.805, 0.27);
glVertex2f(0.805, 0.26);
glVertex2f(0.745, 0.26);
glEnd();

glBegin(GL_QUADS);// square box near the rope
glColor3ub(230, 169, 0);
glVertex2f(0.735, 0.26);
glVertex2f(0.815, 0.26);
glVertex2f(0.815, 0.2);
glVertex2f(0.735, 0.2);
glEnd();


glPushMatrix();
glTranslatef(position64,0,0);//animate Hanger night
glBegin(GL_QUADS);// cargo hanger 1
glColor3ub(109, 33, 14);
glVertex2f(-0.075, 0.27);
glVertex2f(-0.035, 0.27);
glVertex2f(-0.035, 0.255);
glVertex2f(-0.075, 0.255);
glEnd();

glBegin(GL_QUADS);// cargo hanger 2
glColor3ub(230, 169, 0);
glVertex2f(-0.09, 0.255);
glVertex2f(-0.02, 0.255);
glVertex2f(-0.02, 0.245);
glVertex2f(-0.09, 0.245);
glEnd();

glBegin(GL_QUADS);// cargo hanger rope left
glColor3ub(109, 33, 14);
glVertex2f(-0.085, 0.245);
glVertex2f(-0.08, 0.245);
glVertex2f(-0.08, 0.07);
glVertex2f(-0.085, 0.07);
glEnd();

glBegin(GL_QUADS);// cargo hanger rope right
glColor3ub(109, 33, 14);
glVertex2f(-0.03, 0.245);
glVertex2f(-0.025, 0.245);
glVertex2f(-0.025, 0.07);
glVertex2f(-0.03, 0.07);
glEnd();

glBegin(GL_QUADS);// cargo hanger 3
glColor3ub(230, 169, 0);
glVertex2f(-0.09, 0.07);
glVertex2f(-0.02, 0.07);
glVertex2f(-0.02, 0.04);
glVertex2f(-0.09, 0.04);
glEnd();
glPopMatrix();


//front cargo cross
glBegin(GL_LINES);
glColor3ub(205, 154, 10);
glVertex2f(0.4, 0.265);//right cross
glVertex2f(0.37, 0.225);
glVertex2f(0.4, 0.27);
glVertex2f(0.4, -0.605);
glVertex2f(0.4, 0.265);
glVertex2f(0.4, 0.265);
glVertex2f(0.37, 0.225);
glVertex2f(0.4, 0.185);
glVertex2f(0.4, 0.185);
glVertex2f(0.37, 0.14);
glVertex2f(0.37, 0.14);
glVertex2f(0.4, 0.1);
glVertex2f(0.4, 0.1);
glVertex2f(0.37, 0.062);
glVertex2f(0.37, 0.062);
glVertex2f(0.4, 0.02);
glVertex2f(0.4, 0.02);
glVertex2f(0.37, -0.02);
glVertex2f(0.37, -0.02);
glVertex2f(0.4, -0.06);
glVertex2f(0.4, -0.06);
glVertex2f(0.37, -0.105);
glVertex2f(0.37, -0.105);
glVertex2f(0.4, -0.145);
glVertex2f(0.4, -0.145);
glVertex2f(0.37, -0.185);
glVertex2f(0.37, -0.185);
glVertex2f(0.4, -0.225);
glVertex2f(0.4, -0.225);
glVertex2f(0.37, -0.265);
glVertex2f(0.37, -0.265);
glVertex2f(0.4, -0.305);
glVertex2f(0.4, -0.305);
glVertex2f(0.37, -0.345);
glVertex2f(0.37, -0.345);
glVertex2f(0.4, -0.39);
glVertex2f(0.4, -0.39);
glVertex2f(0.37, -0.43);
glVertex2f(0.37, -0.43);
glVertex2f(0.4, -0.47);
glVertex2f(0.4, -0.47);
glVertex2f(0.37, -0.51);
glVertex2f(0.37, -0.51);
glVertex2f(0.4, -0.555);
glVertex2f(0.37, 0.265);//left cross
glVertex2f(0.4, 0.225);
glVertex2f(0.4, 0.225);
glVertex2f(0.37, 0.185);
glVertex2f(0.37, 0.185);
glVertex2f(0.4, 0.14);
glVertex2f(0.4, 0.14);
glVertex2f(0.37, 0.1);
glVertex2f(0.37, 0.1);
glVertex2f(0.4, 0.062);
glVertex2f(0.4, 0.062);
glVertex2f(0.37, 0.02);
glVertex2f(0.37, 0.02);
glVertex2f(0.4, -0.02);
glVertex2f(0.4, -0.02);
glVertex2f(0.37, -0.06);
glVertex2f(0.37, -0.06);
glVertex2f(0.4, -0.105);
glVertex2f(0.4, -0.105);
glVertex2f(0.37, -0.145);
glVertex2f(0.37, -0.145);
glVertex2f(0.4, -0.185);
glVertex2f(0.4, -0.185);
glVertex2f(0.37, -0.225);
glVertex2f(0.37, -0.225);
glVertex2f(0.4, -0.265);
glVertex2f(0.4, -0.265);
glVertex2f(0.37, -0.305);
glVertex2f(0.37, -0.305);
glVertex2f(0.4, -0.345);
glVertex2f(0.4, -0.345);
glVertex2f(0.37, -0.39);
glVertex2f(0.37, -0.39);
glVertex2f(0.4, -0.43);
glVertex2f(0.4, -0.43);
glVertex2f(0.37, -0.47);
glVertex2f(0.37, -0.47);
glVertex2f(0.4, -0.51);
glVertex2f(0.4, -0.51);
glVertex2f(0.37, -0.555);
glVertex2f(0.43, 0.27);//front cargo ladder
glVertex2f(0.43, -0.605);
glVertex2f(0.45, 0.27);
glVertex2f(0.45, -0.605);
glVertex2f(0.43, 0.255);
glVertex2f(0.45, 0.255);
glVertex2f(0.43, 0.24);
glVertex2f(0.45, 0.24);
glVertex2f(0.43, 0.222);
glVertex2f(0.45, 0.222);
glVertex2f(0.43, 0.206);
glVertex2f(0.45, 0.206);
glVertex2f(0.43, 0.188);
glVertex2f(0.45, 0.188);
glVertex2f(0.43, 0.172);
glVertex2f(0.45, 0.172);
glVertex2f(0.43, 0.156);
glVertex2f(0.45, 0.156);
glVertex2f(0.43, 0.106);
glVertex2f(0.45, 0.106);
glVertex2f(0.43, 0.088);
glVertex2f(0.45, 0.088);
glVertex2f(0.43, 0.04);
glVertex2f(0.45, 0.04);
glVertex2f(0.43, 0.022);
glVertex2f(0.45, 0.022);
glVertex2f(0.43, 0.006);
glVertex2f(0.45, 0.006);
glVertex2f(0.43, -0.01);
glVertex2f(0.45, -0.01);
glVertex2f(0.43, -0.06);
glVertex2f(0.45, -0.06);
glVertex2f(0.43, -0.078);
glVertex2f(0.45, -0.078);
glVertex2f(0.43, -0.094);
glVertex2f(0.45, -0.094);
glVertex2f(0.43, -0.11);
glVertex2f(0.45, -0.11);
glVertex2f(0.43, -0.128);
glVertex2f(0.45, -0.128);
glVertex2f(0.43, -0.178);
glVertex2f(0.45, -0.178);
glVertex2f(0.43, -0.194);
glVertex2f(0.45, -0.194);
glVertex2f(0.43, -0.21);
glVertex2f(0.45, -0.21);
glVertex2f(0.43, -0.244);
glVertex2f(0.45, -0.244);
glVertex2f(0.43, -0.262);
glVertex2f(0.45, -0.262);
glVertex2f(0.45, -0.278);
glVertex2f(0.45, -0.278);
glVertex2f(0.45, -0.292);
glVertex2f(0.45, -0.292);
glVertex2f(0.43, -0.31);
glVertex2f(0.45, -0.31);
glVertex2f(0.43, -0.362);
glVertex2f(0.45, -0.362);
glVertex2f(0.43, -0.376);
glVertex2f(0.45, -0.376);
glVertex2f(0.43, -0.394);
glVertex2f(0.45, -0.394);
glVertex2f(0.43, -0.41);
glVertex2f(0.45, -0.41);
glVertex2f(0.43, -0.426);
glVertex2f(0.45, -0.426);
glVertex2f(0.43, -0.444);
glVertex2f(0.45, -0.444);
glVertex2f(0.43, -0.46);
glVertex2f(0.45, -0.46);
glVertex2f(0.43, -0.478);
glVertex2f(0.45, -0.478);
glVertex2f(0.43, -0.494);
glVertex2f(0.45, -0.494);
glVertex2f(0.43, -0.51);
glVertex2f(0.45, -0.51);
glVertex2f(0.43, -0.526);
glVertex2f(0.45, -0.526);
glVertex2f(0.43, -0.544);
glVertex2f(0.45, -0.544);
glVertex2f(0.43, -0.56);
glVertex2f(0.45, -0.56);
glVertex2f(0.43, -0.576);
glVertex2f(0.45, -0.576);
glVertex2f(0.43, -0.592);

glEnd();

//cargo box front left
glBegin(GL_QUADS);//1
glColor3ub(230, 177, 81);
glVertex2f(0.695, -0.28);
glVertex2f(0.695, -0.38);
glVertex2f(0.86, -0.38);
glVertex2f(0.86, -0.28);
glEnd();

glBegin(GL_LINES);//down raw left
glColor3ub(64, 64, 64);
glVertex2f(0.695, -0.28);
glVertex2f(0.695, -0.38);
glVertex2f(0.695, -0.38);
glVertex2f(0.86, -0.38);
glVertex2f(0.86, -0.38);
glVertex2f(0.86, -0.28);
glVertex2f(0.86, -0.28);
glVertex2f(0.695, -0.28);
glEnd();


glBegin(GL_QUADS);//2
glColor3ub(172, 18, 28);
glVertex2f(0.695, -0.38);
glVertex2f(0.695, -0.47);
glVertex2f(0.86, -0.47);
glVertex2f(0.86, -0.38);
glEnd();

glBegin(GL_LINES);//down raw left
glColor3ub(64, 64, 64);
glVertex2f(0.695, -0.38);
glVertex2f(0.695, -0.47);
glVertex2f(0.695, -0.47);
glVertex2f(0.86, -0.47);
glVertex2f(0.86, -0.47);
glVertex2f(0.86, -0.38);
glVertex2f(0.86, -0.38);
glVertex2f(0.695, -0.38);
glEnd();


glBegin(GL_QUADS);//4
glColor3ub(22, 28, 157);
glVertex2f(0.86, -0.47);
glVertex2f(0.86, -0.57);
glVertex2f(1, -0.57);
glVertex2f(1, -0.47);
glEnd();

glBegin(GL_LINES);//down raw left
glColor3ub(64, 64, 64);
glVertex2f(0.86, -0.47);
glVertex2f(0.86, -0.57);
glVertex2f(0.86, -0.57);
glVertex2f(1, -0.57);
glVertex2f(1, -0.57);
glVertex2f(1, -0.47);
glVertex2f(1, -0.47);
glVertex2f(0.86, -0.47);
glEnd();


glBegin(GL_QUADS);//5
glColor3ub(219, 103, 109);
glVertex2f(0.86, -0.57);
glVertex2f(0.86, -0.665);
glVertex2f(1, -0.665);
glVertex2f(1, -0.57);
glEnd();

glBegin(GL_LINES);//down raw left
glColor3ub(64, 64, 64);
glVertex2f(0.86, -0.57);
glVertex2f(0.86, -0.665);
glVertex2f(0.86, -0.665);
glVertex2f(1, -0.665);
glVertex2f(1, -0.665);
glVertex2f(1, -0.57);
glVertex2f(1, -0.57);
glVertex2f(0.86, -0.57);
glEnd();


glBegin(GL_QUADS);//6
glColor3ub(252, 239, 73);
glVertex2f(0.86, -0.665);
glVertex2f(0.86, -0.764);
glVertex2f(1, -0.764);
glVertex2f(1, -0.665);
glEnd();

glBegin(GL_LINES);//down raw left
glColor3ub(64, 64, 64);
glVertex2f(0.86, -0.665);
glVertex2f(0.86, -0.764);
glVertex2f(0.86, -0.764);
glVertex2f(1, -0.764);
glVertex2f(1, -0.764);
glVertex2f(1, -0.665);
glVertex2f(1, -0.665);
glVertex2f(0.86, -0.665);
glEnd();


glBegin(GL_QUADS);//7
glColor3ub(76, 217, 115);
glVertex2f(0.695, -0.665);
glVertex2f(0.695, -0.764);
glVertex2f(0.86, -0.764);
glVertex2f(0.86, -0.665);
glEnd();

glBegin(GL_LINES);//down raw left
glColor3ub(64, 64, 64);
glVertex2f(0.695, -0.665);
glVertex2f(0.695, -0.764);
glVertex2f(0.695, -0.764);
glVertex2f(0.86, -0.764);
glVertex2f(0.86, -0.764);
glVertex2f(0.86, -0.665);
glVertex2f(0.86, -0.665);
glVertex2f(0.695, -0.665);
glEnd();


glBegin(GL_QUADS);//8
glColor3ub(252, 239, 73);
glVertex2f(0.53, -0.665);
glVertex2f(0.53, -0.764);
glVertex2f(0.695, -0.764);
glVertex2f(0.695, -0.665);
glEnd();

glBegin(GL_LINES);//down raw left
glColor3ub(64, 64, 64);
glVertex2f(0.53, -0.665);
glVertex2f(0.53, -0.764);
glVertex2f(0.53, -0.764);
glVertex2f(0.695, -0.764);
glVertex2f(0.695, -0.764);
glVertex2f(0.695, -0.665);
glVertex2f(0.695, -0.665);
glVertex2f(0.53, -0.665);
glEnd();


glBegin(GL_QUADS);//9
glColor3ub(175, 31, 38);
glVertex2f(0.53, -0.57);
glVertex2f(0.53, -0.665);
glVertex2f(0.695, -0.665);
glVertex2f(0.695, -0.57);
glEnd();

glBegin(GL_LINES);//down raw left
glColor3ub(64, 64, 64);
glVertex2f(0.53, -0.57);
glVertex2f(0.53, -0.665);
glVertex2f(0.53, -0.665);
glVertex2f(0.695, -0.665);
glVertex2f(0.695, -0.665);
glVertex2f(0.695, -0.57);
glVertex2f(0.695, -0.57);
glVertex2f(0.53, -0.57);
glEnd();


glBegin(GL_QUADS);//10
glColor3ub(252, 239, 73);
glVertex2f(0.695, -0.57);
glVertex2f(0.695, -0.665);
glVertex2f(0.86, -0.665);
glVertex2f(0.86, -0.57);
glEnd();

glBegin(GL_LINES);//down raw left
glColor3ub(64, 64, 64);
glVertex2f(0.695, -0.57);
glVertex2f(0.695, -0.665);
glVertex2f(0.695, -0.665);
glVertex2f(0.86, -0.665);
glVertex2f(0.86, -0.665);
glVertex2f(0.86, -0.57);
glVertex2f(0.86, -0.57);
glEnd();

glBegin(GL_QUADS);//11
glColor3ub(132, 85, 164);
glVertex2f(0.695, -0.47);
glVertex2f(0.695, -0.57);
glVertex2f(0.86, -0.57);
glVertex2f(0.86, -0.47);
glEnd();

glBegin(GL_LINES);//down raw left
glColor3ub(64, 64, 64);
glVertex2f(0.695, -0.47);
glVertex2f(0.695, -0.57);
glVertex2f(0.695, -0.57);
glVertex2f(0.86, -0.57);
glVertex2f(0.86, -0.57);
glVertex2f(0.86, -0.47);
glVertex2f(0.86, -0.47);
glVertex2f(0.695, -0.47);
glEnd();

glBegin(GL_QUADS);//12
glColor3ub(45, 46, 208);
glVertex2f(0.53, -0.47);
glVertex2f(0.53, -0.57);
glVertex2f(0.695, -0.57);
glVertex2f(0.695, -0.47);
glEnd();

glBegin(GL_LINES);//down raw left
glColor3ub(64, 64, 64);
glVertex2f(0.53, -0.47);
glVertex2f(0.53, -0.57);
glVertex2f(0.53, -0.57);
glVertex2f(0.695, -0.57);
glVertex2f(0.695, -0.57);
glVertex2f(0.695, -0.47);
glVertex2f(0.695, -0.47);
glVertex2f(0.53, -0.47);
glEnd();

glBegin(GL_QUADS);//left cargo
glColor3ub(33, 39, 179);
glVertex2f(-0.88, -0.54);
glVertex2f(-0.72, -0.54);
glVertex2f(-0.72, -0.64);
glVertex2f(-0.88, -0.64);
glEnd();

glBegin(GL_LINES);//dark line
glColor3ub(64, 64, 64);
glVertex2f(-0.88, -0.54);
glVertex2f(-0.72, -0.54);
glVertex2f(-0.72, -0.54);
glVertex2f(-0.72, -0.64);
glVertex2f(-0.72, -0.64);
glVertex2f(-0.88, -0.64);
glVertex2f(-0.88, -0.64);
glVertex2f(-0.88, -0.54);
glEnd();

glBegin(GL_QUADS);//left cargo
glColor3ub(191, 48, 45);
glVertex2f(-0.88, -0.64);
glVertex2f(-0.72, -0.64);
glVertex2f(-0.72, -0.74);
glVertex2f(-0.88, -0.74);
glEnd();

glBegin(GL_LINES);//dark line
glColor3ub(64, 64, 64);
glVertex2f(-0.88, -0.64);
glVertex2f(-0.72, -0.64);
glVertex2f(-0.72, -0.64);
glVertex2f(-0.72, -0.74);
glVertex2f(-0.72, -0.74);
glVertex2f(-0.88, -0.74);
glVertex2f(-0.88, -0.74);
glVertex2f(-0.88, -0.64);
glEnd();

glBegin(GL_QUADS);//left cargo
glColor3ub(255, 242, 78);
glVertex2f(-0.88, -0.74);
glVertex2f(-0.72, -0.74);
glVertex2f(-0.72, -0.84);
glVertex2f(-0.88, -0.84);
glEnd();

glBegin(GL_LINES);//dark line
glColor3ub(64, 64, 64);
glVertex2f(-0.88, -0.74);
glVertex2f(-0.72, -0.74);
glVertex2f(-0.72, -0.74);
glVertex2f(-0.72, -0.84);
glVertex2f(-0.72, -0.84);
glVertex2f(-0.88, -0.84);
glVertex2f(-0.88, -0.84);
glVertex2f(-0.88, -0.74);
glEnd();

glBegin(GL_QUADS);//2nd right cargo
glColor3ub(212, 41, 37);
glVertex2f(0.23, -0.69);
glVertex2f(0.39, -0.69);
glVertex2f(0.39, -0.79);
glVertex2f(0.23, -0.79);
glEnd();
glBegin(GL_LINES);//dark line
glColor3ub(64, 64, 64);
glVertex2f(0.23, -0.69);
glVertex2f(0.39, -0.69);
glVertex2f(0.39, -0.69);
glVertex2f(0.39, -0.79);
glVertex2f(0.39, -0.79);
glVertex2f(0.23, -0.79);
glVertex2f(0.23, -0.79);
glVertex2f(0.23, -0.69);
glEnd();

glBegin(GL_QUADS);//2nd right cargo
glColor3ub(234, 226, 41);
glVertex2f(0.23, -0.79);
glVertex2f(0.39, -0.79);
glVertex2f(0.39, -0.89);
glVertex2f(0.23, -0.89);
glEnd();
glBegin(GL_LINES);//dark line
glColor3ub(64, 64, 64);
glVertex2f(0.23, -0.79);
glVertex2f(0.39, -0.79);
glVertex2f(0.39, -0.79);
glVertex2f(0.39, -0.89);
glVertex2f(0.39, -0.89);
glVertex2f(0.23, -0.89);
glVertex2f(0.23, -0.89);
glVertex2f(0.23, -0.79);
glEnd();

glBegin(GL_QUADS);//2nd right cargo
glColor3ub(63, 91, 128);
glVertex2f(0.39, -0.69);
glVertex2f(0.52, -0.69);
glVertex2f(0.52, -0.79);
glVertex2f(0.39, -0.79);
glEnd();
glBegin(GL_LINES);//dark line
glColor3ub(64, 64, 64);
glVertex2f(0.39, -0.69);
glVertex2f(0.52, -0.69);
glVertex2f(0.52, -0.69);
glVertex2f(0.52, -0.79);
glVertex2f(0.52, -0.79);
glVertex2f(0.39, -0.79);
glVertex2f(0.39, -0.79);
glVertex2f(0.39, -0.69);
glEnd();

glBegin(GL_QUADS);//2nd right cargo
glColor3ub(43, 46, 189);
glVertex2f(0.39, -0.79);
glVertex2f(0.52, -0.79);
glVertex2f(0.52, -0.89);
glVertex2f(0.39, -0.89);
glEnd();
glBegin(GL_LINES);//dark line
glColor3ub(64, 64, 64);
glVertex2f(0.39, -0.79);
glVertex2f(0.52, -0.79);
glVertex2f(0.52, -0.79);
glVertex2f(0.52, -0.89);
glVertex2f(0.52, -0.89);
glVertex2f(0.39, -0.89);
glVertex2f(0.39, -0.89);
glVertex2f(0.39, -0.79);
glEnd();


glBegin(GL_QUADS);//front middle cargo
glColor3ub(228, 220, 37);
glVertex2f(-0.14, -0.73);
glVertex2f(0.02, -0.73);
glVertex2f(0.02, -0.83);
glVertex2f(-0.14, -0.83);
glEnd();
glBegin(GL_LINES);//dark line
glColor3ub(64, 64, 64);
glVertex2f(-0.14, -0.73);
glVertex2f(0.02, -0.73);
glVertex2f(0.02, -0.73);
glVertex2f(0.02, -0.83);
glVertex2f(0.02, -0.83);
glVertex2f(-0.14, -0.83);
glVertex2f(-0.14, -0.83);
glVertex2f(-0.14, -0.73);
glEnd();

glBegin(GL_QUADS);//front middle cargo
glColor3ub(216, 46, 43);
glVertex2f(-0.14, -0.83);
glVertex2f(0.02, -0.83);
glVertex2f(0.02, -0.92);
glVertex2f(-0.14, -0.92);
glEnd();
glBegin(GL_LINES);//dark line
glColor3ub(64, 64, 64);
glVertex2f(-0.14, -0.83);
glVertex2f(0.02, -0.83);
glVertex2f(0.02, -0.83);
glVertex2f(0.02, -0.92);
glVertex2f(0.02, -0.92);
glVertex2f(-0.14, -0.92);
glVertex2f(-0.14, -0.92);
glVertex2f(-0.14, -0.83);
glEnd();

glutTimerFunc(10000,rain_loop,0);
glFlush();

}





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void night_loop(int val) {

 glutDisplayFunc(night);

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void day()
{   glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //white_background
    glClear(GL_COLOR_BUFFER_BIT);



//first_sky_layer

glBegin(GL_QUADS); //layer
glColor3ub(121, 212, 255);
glVertex2f(-1, 1);
glVertex2f(-1, 0.9);
glVertex2f(1, 0.9);
glVertex2f(1, 1);
glEnd();

glBegin(GL_QUADS);//layer
glColor3ub(121, 212, 255);
glVertex2f(-1, 0.9);
glVertex2f(-1, 0.8);
glVertex2f(1, 0.8);
glVertex2f(1, 0.9);
glEnd();

glBegin(GL_QUADS);//layer
glColor3ub(121, 212, 255);
glVertex2f(-1, 0.8);
glVertex2f(-1, 0.7);
glVertex2f(1, 0.7);
glVertex2f(1, 0.8);
glEnd();

glBegin(GL_QUADS);//layer
glColor3ub(121, 212, 255);
glVertex2f(-1, 0.7);
glVertex2f(-1, 0.6);
glVertex2f(1, 0.6);
glVertex2f(1, 0.7);
glEnd();


glBegin(GL_QUADS);//layer
glColor3ub(121, 212, 255);
glVertex2f(-1, 0.6);
glVertex2f(-1, 0.5);
glVertex2f(1, 0.5);
glVertex2f(1, 0.6);
glEnd();

glBegin(GL_QUADS);//layer
glColor3ub(121, 212, 255);
glVertex2f(-1, 0.5);
glVertex2f(-1, 0.4);
glVertex2f(1, 0.4);
glVertex2f(1, 0.5);
glEnd();

glBegin(GL_QUADS);//layer
glColor3ub(121, 212, 255);
glVertex2f(-1, 0.4);
glVertex2f(-1, 0.05);
glVertex2f(1, 0.05);
glVertex2f(1, 0.4);
glEnd();


//sun
glPushMatrix();//animate sun
glTranslatef(position8,-position8,0);
int i;

 GLfloat x110=-0.01f; GLfloat y110= 0.81f; GLfloat radius110 =0.10f;
	int triangleAmount110 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi110 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(170, 218, 239); // sun
		glVertex2f(x110, y110); // center of circle
		for(i = 0; i <= triangleAmount110;i++) {
			glVertex2f(
		            x110 + (radius110* cos(i *  twicePi110 / triangleAmount110)),
			    y110 + (radius110 * sin(i * twicePi110 / triangleAmount110))
			);
		}
	glEnd();

	    GLfloat x112=-0.01f; GLfloat y112= 0.81f; GLfloat radius112 =0.08f;
	int triangleAmount112 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi112 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 206, 71); // sun
		glVertex2f(x112, y112); // center of circle
		for(i = 0; i <= triangleAmount112;i++) {
			glVertex2f(
		            x112 + (radius112 * cos(i *  twicePi112 / triangleAmount112)),
			    y112 + (radius112 * sin(i * twicePi112 / triangleAmount112))
			);
		}
	glEnd();

glPopMatrix();
glLoadIdentity();

//sunEnd


//cloud start
glPushMatrix();
glTranslatef(position,0,0); //cloud animation

GLfloat x1721=-.9f; GLfloat y1721=.72f; GLfloat radius1721 =0.030f;
	int triangleAmount1721 = 20; //# of triangles used to draw circle

	GLfloat twicePi1721 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(242, 242, 242);
		glVertex2f(x1721, y1721); // center of circle
		for(i = 0; i<= triangleAmount1721;i++) {
			glVertex2f(
		            x1721 + (radius1721 * cos(i *  twicePi1721 / triangleAmount1721)),
			    y1721 + (radius1721 * sin(i * twicePi1721 / triangleAmount1721))
			);
		}
	glEnd();

	GLfloat x1821=-.894f; GLfloat y1821=.725f; GLfloat radius1821 =0.030f;
	int triangleAmount1821 = 20; //# of triangles used to draw circle

	GLfloat twicePi1821 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
		glVertex2f(x1821, y1821); // center of circle
		for(i = 0; i<= triangleAmount1821;i++) {
			glVertex2f(
		            x1821 + (radius1821 * cos(i *  twicePi1821 / triangleAmount1821)),
			    y1821 + (radius1821 * sin(i * twicePi1821/ triangleAmount1821))
			);
		}
	glEnd();


	GLfloat x1921=-.885f; GLfloat y1921=.75f; GLfloat radius1921 =0.030f;
	int triangleAmount1921 = 20; //# of triangles used to draw circle

	GLfloat twicePi1921 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(242, 242, 242);
		glVertex2f(x1921, y1921); // center of circle
		for(i= 0; i<= triangleAmount1921;i++) {
			glVertex2f(
		            x1921 + (radius1921 * cos(i *  twicePi1921 / triangleAmount1921)),
			    y1921+ (radius1921 * sin(i * twicePi1921/ triangleAmount1921))
			);
		}
	glEnd();


	GLfloat x1991=-.88f; GLfloat y1991=.76f; GLfloat radius1991 =0.030f;
	int triangleAmount1991= 20; //# of triangles used to draw circle

	GLfloat twicePi1991 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
		glVertex2f(x1991, y1991); // center of circle
		for(i = 0; i<= triangleAmount1991;i++) {
			glVertex2f(
		            x1991 + (radius1991 * cos(i *  twicePi1991 / triangleAmount1991)),
			    y1991 + (radius1991 * sin(i * twicePi1991/ triangleAmount1991))
			);
		}
	glEnd();

	GLfloat x199112=-.87f; GLfloat y199112=.72f; GLfloat radius199112 =0.030f;
	int triangleAmount199112= 20; //# of triangles used to draw circle

	GLfloat twicePi199112 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(242, 242, 242);
		glVertex2f(x199112, y199112); // center of circle
		for(i = 0; i<= triangleAmount199112;i++) {
			glVertex2f(
		            x199112 + (radius199112 * cos(i *  twicePi199112 / triangleAmount199112)),
			    y199112 + (radius199112 * sin(i * twicePi199112/ triangleAmount199112))
			);
		}
	glEnd();

GLfloat x199111=-.85f; GLfloat y199111=.72f; GLfloat radius199111 =0.030f;
	int triangleAmount199111= 20; //# of triangles used to draw circle

	GLfloat twicePi199111 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
		glVertex2f(x199111, y199111); // center of circle
		for(i = 0; i<= triangleAmount199111;i++) {
			glVertex2f(
		            x199111 + (radius199111 * cos(i *  twicePi199111 / triangleAmount199111)),
			    y199111 + (radius199111 * sin(i * twicePi199111/ triangleAmount199111))
			);
		}
	glEnd();


GLfloat x1991111=-.85f; GLfloat y1991111=.74f; GLfloat radius1991111 =0.030f;
	int triangleAmount1991111= 20; //# of triangles used to draw circle

	GLfloat twicePi1991111 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(242, 242, 242);
		glVertex2f(x1991111, y1991111); // center of circle
		for(i = 0; i<= triangleAmount1991111;i++) {
			glVertex2f(
		            x1991111 + (radius1991111 * cos(i *  twicePi1991111 / triangleAmount199111)),
			    y1991111 + (radius1991111 * sin(i * twicePi1991111/ triangleAmount1991111))
			);
		}
	glEnd();


GLfloat x19911112=-.83f; GLfloat y19911112=.72f; GLfloat radius19911112 =0.030f;
	int triangleAmount19911112= 20; //# of triangles used to draw circle

	GLfloat twicePi19911112 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(242, 242, 242);
		glVertex2f(x19911112, y19911112); // center of circle
		for(i = 0; i<= triangleAmount19911112;i++) {
			glVertex2f(
		            x19911112 + (radius19911112 * cos(i *  twicePi19911112 / triangleAmount19911112)),
			    y19911112 + (radius19911112 * sin(i * twicePi19911112/ triangleAmount19911112))
			);
		}
	glEnd();


GLfloat x19911111=-.84f; GLfloat y19911111=.76f; GLfloat radius19911111 =0.030f;
	int triangleAmount19911111= 20; //# of triangles used to draw circle

	GLfloat twicePi19911111 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
		glVertex2f(x19911111, y19911111); // center of circle
		for(i = 0; i<= triangleAmount19911111;i++) {
			glVertex2f(
		            x19911111 + (radius19911111 * cos(i *  twicePi19911111 / triangleAmount19911111)),
			    y19911111 + (radius19911111 * sin(i * twicePi19911111/ triangleAmount19911111))
			);
		}
	glEnd();

	GLfloat x199111111=-.83f; GLfloat y199111111=.72f; GLfloat radius199111111 =0.030f;
	int triangleAmount199111111= 20; //# of triangles used to draw circle

	GLfloat twicePi199111111 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(242, 242, 242);
		glVertex2f(x199111111, y199111111); // center of circle
		for(i = 0; i<= triangleAmount199111111;i++) {
			glVertex2f(
		            x199111111 + (radius199111111 * cos(i *  twicePi199111111 / triangleAmount199111111)),
			    y199111111 + (radius199111111 * sin(i * twicePi199111111/ triangleAmount199111111))
			);
		}
	glEnd();

		GLfloat x1991111111=-.815f; GLfloat y1991111111=.72f; GLfloat radius1991111111 =0.030f;
	int triangleAmount1991111111= 20; //# of triangles used to draw circle

	GLfloat twicePi1991111111 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
		glVertex2f(x1991111111, y1991111111); // center of circle
		for(i= 0; i<= triangleAmount1991111111;i++) {
			glVertex2f(
		            x1991111111 + (radius1991111111 * cos(i *  twicePi1991111111 / triangleAmount1991111111)),
			    y1991111111 + (radius1991111111 * sin(i * twicePi1991111111/ triangleAmount1991111111))
			);
		}
	glEnd();
	glTranslatef(0.6,0.14,0);
    GLfloat x172=-.9f; GLfloat y172=.72f; GLfloat radius172 =0.030f;
	int triangleAmount172 = 20; //# of triangles used to draw circle

	GLfloat twicePi172 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(242, 242, 242);
		glVertex2f(x172, y172); // center of circle
		for(i = 0; i<= triangleAmount172;i++) {
			glVertex2f(
		            x172 + (radius172 * cos(i *  twicePi172 / triangleAmount172)),
			    y172 + (radius172 * sin(i * twicePi172 / triangleAmount172))
			);
		}
	glEnd();

	GLfloat x18212=-.894f; GLfloat y18212=.725f; GLfloat radius18212 =0.030f;
	int triangleAmount18212= 20; //# of triangles used to draw circle

	GLfloat twicePi18212 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
		glVertex2f(x18212, y18212); // center of circle
		for(i = 0; i<= triangleAmount18212;i++) {
			glVertex2f(
		            x18212 + (radius18212 * cos(i *  twicePi18212 / triangleAmount18212)),
			    y18212 + (radius18212 * sin(i * twicePi18212/ triangleAmount18212))
			);
		}
	glEnd();


	GLfloat x19212=-.885f; GLfloat y19212=.75f; GLfloat radius19212 =0.030f;
	int triangleAmount19212 = 20; //# of triangles used to draw circle

	GLfloat twicePi19212 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(242, 242, 242);
		glVertex2f(x19212, y19212); // center of circle
		for(i= 0; i<= triangleAmount19212;i++) {
			glVertex2f(
		            x19212 + (radius19212 * cos(i *  twicePi19212 / triangleAmount19212)),
			    y19212+ (radius19212 * sin(i * twicePi19212/ triangleAmount19212))
			);
		}
	glEnd();


	GLfloat x199122=-.88f; GLfloat y199122=.76f; GLfloat radius199122 =0.030f;
	int triangleAmount199122= 20; //# of triangles used to draw circle

	GLfloat twicePi199122 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
		glVertex2f(x199122, y199122); // center of circle
		for(i = 0; i<= triangleAmount199122;i++) {
			glVertex2f(
		            x199122 + (radius199122 * cos(i *  twicePi199122 / triangleAmount199122)),
			    y199122 + (radius199122 * sin(i * twicePi199122/ triangleAmount199122))
			);
		}
	glEnd();

	GLfloat x1991123=-.87f; GLfloat y1991123=.72f; GLfloat radius1991123 =0.030f;
	int triangleAmount1991123= 20; //# of triangles used to draw circle

	GLfloat twicePi1991123 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(242, 242, 242);
		glVertex2f(x1991123, y1991123); // center of circle
		for(i = 0; i<= triangleAmount1991123;i++) {
			glVertex2f(
		            x1991123 + (radius1991123 * cos(i *  twicePi1991123 / triangleAmount1991123)),
			    y1991123+ (radius1991123 * sin(i * twicePi1991123/ triangleAmount1991123))
			);
		}
	glEnd();

GLfloat x19911133=-.85f; GLfloat y19911133=.72f; GLfloat radius19911133 =0.030f;
	int triangleAmount19911133= 20; //# of triangles used to draw circle

	GLfloat twicePi19911133 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
		glVertex2f(x19911133, y19911133); // center of circle
		for(i = 0; i<= triangleAmount19911133;i++) {
			glVertex2f(
		            x19911133 + (radius19911133 * cos(i *  twicePi19911133 / triangleAmount19911133)),
			    y19911133 + (radius19911133 * sin(i * twicePi19911133/ triangleAmount19911133))
			);
		}
	glEnd();


GLfloat x199111133=-.85f; GLfloat y199111133=.74f; GLfloat radius199111133 =0.030f;
	int triangleAmount199111133= 20; //# of triangles used to draw circle

	GLfloat twicePi199111133 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(242, 242, 242);
		glVertex2f(x199111133, y199111133); // center of circle
		for(i = 0; i<= triangleAmount199111133;i++) {
			glVertex2f(
		            x199111133 + (radius199111133 * cos(i *  twicePi199111133 / triangleAmount199111133)),
			    y199111133 + (radius199111133 * sin(i * twicePi199111133/ triangleAmount199111133))
			);
		}
	glEnd();


GLfloat x1991111112=-.83f; GLfloat y1991111112=.72f; GLfloat radius1991111112 =0.030f;
	int triangleAmount1991111112= 20; //# of triangles used to draw circle

	GLfloat twicePi1991111112 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(242, 242, 242);
		glVertex2f(x1991111112, y1991111112); // center of circle
		for(i = 0; i<= triangleAmount1991111112;i++) {
			glVertex2f(
		            x1991111112 + (radius1991111112 * cos(i *  twicePi1991111112 / triangleAmount1991111112)),
			    y1991111112 + (radius1991111112 * sin(i * twicePi1991111112/ triangleAmount1991111112))
			);
		}
	glEnd();


GLfloat x19911111123=-.84f; GLfloat y19911111123=.76f; GLfloat radius19911111123 =0.030f;
	int triangleAmount19911111123= 20; //# of triangles used to draw circle

	GLfloat twicePi19911111123 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
		glVertex2f(x19911111123, y19911111123); // center of circle
		for(i = 0; i<= triangleAmount19911111123;i++) {
			glVertex2f(
		            x19911111123 + (radius19911111123 * cos(i *  twicePi19911111123 / triangleAmount19911111123)),
			    y19911111123 + (radius19911111123 * sin(i * twicePi19911111123/ triangleAmount19911111123))
			);
		}
	glEnd();

	GLfloat x199111111132=-.83f; GLfloat y199111111132=.72f; GLfloat radius199111111132 =0.030f;
	int triangleAmount199111111132= 20; //# of triangles used to draw circle

	GLfloat twicePi199111111132 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(242, 242, 242);
		glVertex2f(x199111111132, y199111111132); // center of circle
		for(i = 0; i<= triangleAmount199111111132;i++) {
			glVertex2f(
		            x199111111132 + (radius199111111132 * cos(i *  twicePi199111111132 / triangleAmount199111111132)),
			    y199111111132 + (radius199111111132 * sin(i * twicePi199111111132/ triangleAmount199111111132))
			);
		}
	glEnd();

		GLfloat x19911111111=-.815f; GLfloat y19911111111=.72f; GLfloat radius19911111111 =0.030f;
	int triangleAmount19911111111= 20; //# of triangles used to draw circle

	GLfloat twicePi19911111111 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
		glVertex2f(x19911111111, y19911111111); // center of circle
		for(i= 0; i<= triangleAmount19911111111;i++) {
			glVertex2f(
		            x19911111111 + (radius19911111111 * cos(i *  twicePi19911111111 / triangleAmount19911111111)),
			    y19911111111 + (radius19911111111 * sin(i * twicePi19911111111/ triangleAmount19911111111))
			);
		}
	glEnd();
	glLoadIdentity();
	glPopMatrix();


glPushMatrix();
glTranslatef(position,0,0); //cloud 2 animation

	GLfloat x92=0.36f; GLfloat y92=0.69f; GLfloat radius92 =0.035f;
	int triangleAmount92 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi92 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255); // windmill
		glVertex2f(x92, y92); // center of circle
		for(i = 0; i <= triangleAmount92;i++) {
			glVertex2f(
		            x92 + (radius92* cos(i *  twicePi92 / triangleAmount92)),
			    y92 + (radius92 * sin(i * twicePi92 / triangleAmount92))
			);
		}
	glEnd();


		GLfloat x102=0.32f; GLfloat y102=0.67f; GLfloat radius102 =0.035f;
	int triangleAmount102= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi102 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(242, 242, 242); // windmill
		glVertex2f(x102, y102); // center of circle
		for(i = 0; i <= triangleAmount102;i++) {
			glVertex2f(
		            x102 + (radius102 * cos(i *  twicePi102/ triangleAmount102)),
			    y102 + (radius102 * sin(i * twicePi102 / triangleAmount102))
			);
		}
	glEnd();


	GLfloat x1122=0.38f; GLfloat y1122=0.67f; GLfloat radius1122 =0.035f;
	int triangleAmount1122 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1122 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(242, 242, 242); // windmill
		glVertex2f(x1122, y1122); // center of circle
		for(i = 0; i <= triangleAmount1122;i++) {
			glVertex2f(
		            x1122 + (radius1122 * cos(i *  twicePi1122 / triangleAmount1122)),
			    y1122 + (radius1122* sin(i * twicePi1122 / triangleAmount1122))
			);
		}
	glEnd();


	GLfloat x122=0.4f; GLfloat y122=0.71f; GLfloat radius122 =0.035f;
	int triangleAmount122 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi122 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255); // windmill
		glVertex2f(x122, y122); // center of circle
		for(i = 0; i <= triangleAmount122;i++) {
			glVertex2f(
		            x122 + (radius122* cos(i *  twicePi122 / triangleAmount122)),
			    y122 + (radius122 * sin(i * twicePi122 / triangleAmount122))
			);
		}
	glEnd();


	GLfloat x1322=0.43f; GLfloat y1322=0.67f; GLfloat radius1322 =0.035f;
	int triangleAmount1322 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1322 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(242, 242, 242); // windmill
		glVertex2f(x1322, y1322); // center of circle
		for(i = 0; i <= triangleAmount1322;i++) {
			glVertex2f(
		            x1322 + (radius1322* cos(i *  twicePi1322 / triangleAmount1322)),
			    y1322 + (radius1322 * sin(i * twicePi1322 / triangleAmount1322))
			);
		}
	glEnd();

	GLfloat x142=0.45f; GLfloat y142=0.67f; GLfloat radius142=0.035f;
	int triangleAmount142 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi142 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255); // windmill
		glVertex2f(x142, y142); // center of circle
		for(i = 0; i <= triangleAmount142;i++) {
			glVertex2f(
		            x142 + (radius142* cos(i *  twicePi142 / triangleAmount142)),
			    y142 + (radius142 * sin(i * twicePi142 / triangleAmount142))
			);
		}
	glEnd();

		GLfloat x152=0.33f; GLfloat y152=0.684f; GLfloat radius152=0.035f;
	int triangleAmount152 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi152 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255); // windmill
		glVertex2f(x152, y152); // center of circle
		for(i = 0; i <= triangleAmount152;i++) {
			glVertex2f(
		            x152 + (radius152* cos(i *  twicePi152 / triangleAmount152)),
			    y152 + (radius152 * sin(i * twicePi152 / triangleAmount152))
			);
		}
	glEnd();

	GLfloat x162=0.33f; GLfloat y162=0.684f; GLfloat radius162=0.035f;
	int triangleAmount162 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi162 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255); // windmill
		glVertex2f(x162, y162); // center of circle
		for(i = 0; i <= triangleAmount162;i++) {
			glVertex2f(
		            x162 + (radius162* cos(i *  twicePi162 / triangleAmount162)),
			    y162 + (radius162 * sin(i * twicePi162 / triangleAmount162))
			);
		}
	glEnd();


	glTranslatef(-0.9,0.05,0);
	GLfloat x921=0.36f; GLfloat y921=0.69f; GLfloat radius921 =0.035f;
	int triangleAmount921 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi921 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255); // windmill
		glVertex2f(x921, y921); // center of circle
		for(i = 0; i <= triangleAmount921;i++) {
			glVertex2f(
		            x921 + (radius921* cos(i *  twicePi921 / triangleAmount921)),
			    y92 + (radius921 * sin(i * twicePi921 / triangleAmount921))
			);
		}
	glEnd();


		GLfloat x1021=0.32f; GLfloat y1021=0.67f; GLfloat radius1021 =0.035f;
	int triangleAmount1021= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1021 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(242, 242, 242); // windmill
		glVertex2f(x1021, y1021); // center of circle
		for(i = 0; i <= triangleAmount102;i++) {
			glVertex2f(
		            x1021 + (radius1021 * cos(i *  twicePi1021/ triangleAmount1021)),
			    y1021 + (radius1021 * sin(i * twicePi1021 / triangleAmount1021))
			);
		}
	glEnd();


	GLfloat x11221=0.38f; GLfloat y11221=0.67f; GLfloat radius11221 =0.035f;
	int triangleAmount11221 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi11221 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(242, 242, 242); // windmill
		glVertex2f(x11221, y11221); // center of circle
		for(i = 0; i <= triangleAmount11221;i++) {
			glVertex2f(
		            x11221 + (radius11221 * cos(i *  twicePi11221 / triangleAmount11221)),
			    y11221 + (radius11221* sin(i * twicePi11221 / triangleAmount11221))
			);
		}
	glEnd();


	GLfloat x1221=0.4f; GLfloat y1221=0.71f; GLfloat radius1221 =0.035f;
	int triangleAmount1221 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1221 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255); // windmill
		glVertex2f(x1221, y1221); // center of circle
		for(i = 0; i <= triangleAmount1221;i++) {
			glVertex2f(
		            x1221 + (radius1221* cos(i *  twicePi1221 / triangleAmount1221)),
			    y1221 + (radius1221 * sin(i * twicePi1221 / triangleAmount1221))
			);
		}
	glEnd();


	GLfloat x13221=0.43f; GLfloat y13221=0.67f; GLfloat radius13221 =0.035f;
	int triangleAmount13221 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi13221 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(242, 242, 242); // windmill
		glVertex2f(x13221, y13221); // center of circle
		for(i = 0; i <= triangleAmount13221;i++) {
			glVertex2f(
		            x13221 + (radius13221* cos(i *  twicePi13221 / triangleAmount13221)),
			    y13221 + (radius13221 * sin(i * twicePi13221 / triangleAmount13221))
			);
		}
	glEnd();

	GLfloat x1421=0.45f; GLfloat y1421=0.67f; GLfloat radius1421=0.035f;
	int triangleAmount1421 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1421 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255); // windmill
		glVertex2f(x1421, y1421); // center of circle
		for(i = 0; i <= triangleAmount1421;i++) {
			glVertex2f(
		            x1421 + (radius1421* cos(i *  twicePi1421 / triangleAmount1421)),
			    y1421 + (radius1421 * sin(i * twicePi1421 / triangleAmount1421))
			);
		}
	glEnd();

		GLfloat x1521=0.33f; GLfloat y1521=0.684f; GLfloat radius1521=0.035f;
	int triangleAmount1521 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1521 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255); // windmill
		glVertex2f(x1521, y1521); // center of circle
		for(i = 0; i <= triangleAmount1521;i++) {
			glVertex2f(
		            x1521 + (radius1521* cos(i *  twicePi1521 / triangleAmount1521)),
			    y1521 + (radius1521 * sin(i * twicePi1521 / triangleAmount1521))
			);
		}
	glEnd();

	GLfloat x1621=0.33f; GLfloat y1621=0.684f; GLfloat radius1621=0.035f;
	int triangleAmount1621 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1621 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255); // windmill
		glVertex2f(x1621, y1621); // center of circle
		for(i = 0; i <= triangleAmount1621;i++) {
			glVertex2f(
		            x1621 + (radius1621* cos(i *  twicePi1621 / triangleAmount1621)),
			    y1621 + (radius1621 * sin(i * twicePi1621 / triangleAmount1621))
			);
		}
	glEnd();
    glLoadIdentity();


    glPushMatrix();
    glTranslatef(position,0,0);//cloud 3 animation

    glTranslatef(0.3,0.15,0);
    GLfloat x9213=0.36f; GLfloat y9213=0.69f; GLfloat radius9213 =0.035f;
	int triangleAmount9213 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi9213 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255); // windmill
		glVertex2f(x9213, y9213); // center of circle
		for(i = 0; i <= triangleAmount9213;i++) {
			glVertex2f(
		            x9213 + (radius9213* cos(i *  twicePi9213 / triangleAmount9213)),
			    y92 + (radius9213 * sin(i * twicePi9213/ triangleAmount9213))
			);
		}
	glEnd();


		GLfloat x10213=0.32f; GLfloat y10213=0.67f; GLfloat radius10213 =0.035f;
	int triangleAmount10213= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi10213 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(242, 242, 242); // windmill
		glVertex2f(x10213, y10213); // center of circle
		for(i = 0; i <= triangleAmount10213;i++) {
			glVertex2f(
		            x10213 + (radius10213 * cos(i *  twicePi10213/ triangleAmount10213)),
			    y10213 + (radius10213 * sin(i * twicePi10213 / triangleAmount10213))
			);
		}
	glEnd();


	GLfloat x112213=0.38f; GLfloat y112213=0.67f; GLfloat radius112213 =0.035f;
	int triangleAmount112213 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi112213 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(242, 242, 242); // windmill
		glVertex2f(x112213, y112213); // center of circle
		for(i = 0; i <= triangleAmount112213;i++) {
			glVertex2f(
		            x112213 + (radius112213 * cos(i *  twicePi112213 / triangleAmount112213)),
			    y112213 + (radius112213* sin(i * twicePi112213 / triangleAmount112213))
			);
		}
	glEnd();


	GLfloat x12213=0.4f; GLfloat y12213=0.71f; GLfloat radius12213 =0.035f;
	int triangleAmount12213 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi12213 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255); // windmill
		glVertex2f(x12213, y12213); // center of circle
		for(i = 0; i <= triangleAmount12213;i++) {
			glVertex2f(
		            x12213 + (radius12213* cos(i *  twicePi12213 / triangleAmount12213)),
			    y12213 + (radius12213* sin(i * twicePi12213 / triangleAmount12213))
			);
		}
	glEnd();


	GLfloat x132213=0.43f; GLfloat y132213=0.67f; GLfloat radius132213 =0.035f;
	int triangleAmount132213 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi132213 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(242, 242, 242); // windmill
		glVertex2f(x132213, y132213); // center of circle
		for(i = 0; i <= triangleAmount132213;i++) {
			glVertex2f(
		            x132213 + (radius132213* cos(i *  twicePi132213 / triangleAmount132213)),
			    y132213+ (radius132213 * sin(i * twicePi132213 / triangleAmount132213))
			);
		}
	glEnd();

	GLfloat x14213=0.45f; GLfloat y14213=0.67f; GLfloat radius14213=0.035f;
	int triangleAmount14213 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi14213 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255); // windmill
		glVertex2f(x14213, y14213); // center of circle
		for(i = 0; i <= triangleAmount14213;i++) {
			glVertex2f(
		            x14213 + (radius14213* cos(i *  twicePi14213 / triangleAmount14213)),
			    y14213 + (radius14213 * sin(i * twicePi14213 / triangleAmount14213))
			);
		}
	glEnd();

		GLfloat x15213=0.33f; GLfloat y15213=0.684f; GLfloat radius15213=0.035f;
	int triangleAmount15213 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi15213 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255); // windmill
		glVertex2f(x15213, y15213); // center of circle
		for(i = 0; i <= triangleAmount1521;i++) {
			glVertex2f(
		            x15213 + (radius15213* cos(i *  twicePi15213 / triangleAmount15213)),
			    y15213 + (radius15213 * sin(i * twicePi15213 / triangleAmount15213))
			);
		}
	glEnd();

	GLfloat x16213=0.33f; GLfloat y16213=0.684f; GLfloat radius16213=0.035f;
	int triangleAmount16213 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi16213 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255); // windmill
		glVertex2f(x16213, y16213); // center of circle
		for(i = 0; i <= triangleAmount16213;i++) {
			glVertex2f(
		            x16213+ (radius16213* cos(i *  twicePi16213 / triangleAmount16213)),
			    y16213 + (radius16213 * sin(i * twicePi16213 / triangleAmount16213))
			);
		}
	glEnd();
	glLoadIdentity();
    glPopMatrix();
//cloud end


//Building_1
glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f( -1.0, 0.34 );
glVertex2f( -1.0, 0.1 );
glVertex2f( -0.925, 0.1 );
glVertex2f( -0.925, 0.34 );
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f(-0.925, 0.43 );
glVertex2f( -0.925, 0.1 );
glVertex2f( -0.855, 0.1 );
glVertex2f( -0.855, 0.43 );
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f(-0.844, 0.34 );
glVertex2f( -0.844, 0.1 );
glVertex2f(-0.779, 0.1 );
glVertex2f( -0.779, 0.34 );
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f(-0.709, 0.474);
glVertex2f( -0.709, 0.1 );
glVertex2f(-0.55, 0.1 );
glVertex2f( -0.55, 0.44 );
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f(-0.53, 0.418);
glVertex2f( -0.53, 0.1 );
glVertex2f(-0.504, 0.1 );
glVertex2f( -0.504, 0.418);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f(-0.504, 0.476);
glVertex2f( -0.504, 0.1 );
glVertex2f(-0.476, 0.1 );
glVertex2f( -0.476, 0.476);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f(-0.476, 0.458);
glVertex2f( -0.476, 0.1 );
glVertex2f(-0.442, 0.1 );
glVertex2f( -0.442, 0.458);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f(-0.442, 0.505);
glVertex2f( -0.442, 0.1 );
glVertex2f(-0.358, 0.1 );
glVertex2f( -0.358, 0.505);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f(-0.358, 0.458);
glVertex2f( -0.358, 0.1 );
glVertex2f(-0.327, 0.1 );
glVertex2f( -0.327, 0.458);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f(-0.327, 0.49);
glVertex2f( -0.327, 0.1 );
glVertex2f(-0.2935, 0.1 );
glVertex2f( -0.2935, 0.49);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f(-0.2935, 0.42);
glVertex2f( -0.2935, 0.1 );
glVertex2f(-0.256, 0.1 );
glVertex2f( -0.256, 0.42);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f(-0.256, 0.515);
glVertex2f( -0.256, 0.1 );
glVertex2f(-0.244, 0.1 );
glVertex2f(-0.244, 0.515);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f(-0.244, 0.534);
glVertex2f( -0.244, 0.1 );
glVertex2f(-0.236, 0.1 );
glVertex2f(-0.236, 0.534);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f(-0.236, 0.568);
glVertex2f( -0.236, 0.1 );
glVertex2f(-0.224, 0.1 );
glVertex2f(-0.224, 0.568);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f(-0.224, 0.592);
glVertex2f( -0.224, 0.1 );
glVertex2f(-0.171, 0.1 );
glVertex2f(-0.171, 0.592);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f(-0.171, 0.568);
glVertex2f( -0.171, 0.1 );
glVertex2f(-0.155, 0.1 );
glVertex2f(-0.155, 0.568);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f(-0.155, 0.534);
glVertex2f( -0.155, 0.1 );
glVertex2f(-0.141, 0.1 );
glVertex2f(-0.141, 0.534);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f(-0.155, 0.534);
glVertex2f( -0.155, 0.1 );
glVertex2f(-0.141, 0.1 );
glVertex2f(-0.141, 0.534);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f(-0.141, 0.515);
glVertex2f( -0.141, 0.1 );
glVertex2f(-0.128, 0.1 );
glVertex2f(-0.128, 0.515);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f(-0.128, 0.42);
glVertex2f( -0.128, 0.1 );
glVertex2f(-0.12, 0.1 );
glVertex2f(-0.12, 0.42);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f(-0.12, 0.49);
glVertex2f( -0.12, 0.1 );
glVertex2f(0.008, 0.1 );
glVertex2f(0.008, 0.49);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f(0.008, 0.55);
glVertex2f( 0.008, 0.1 );
glVertex2f(0.098, 0.1 );
glVertex2f(0.098, 0.55);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f(0.098, 0.295);
glVertex2f( 0.098, 0.1 );
glVertex2f(0.116, 0.1 );
glVertex2f(0.116, 0.295);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f(0.195, 0.39);
glVertex2f( 0.195, 0.1 );
glVertex2f(0.245, 0.1 );
glVertex2f(0.245, 0.358);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f(0.245, 0.301);
glVertex2f( 0.245, 0.1 );
glVertex2f(0.26, 0.1 );
glVertex2f(0.26, 0.301);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f(0.26, 0.445);
glVertex2f( 0.26, 0.1 );
glVertex2f(0.37, 0.1 );
glVertex2f(0.37, 0.445);
glEnd();

glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f(0.39, 0.4);
glVertex2f( 0.39, 0.1 );
glVertex2f(0.45, 0.1 );
glVertex2f(0.45, 0.4);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f(0.45, 0.35);
glVertex2f( 0.45, 0.1 );
glVertex2f(0.495, 0.1 );
glVertex2f(0.495, 0.35);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f(0.495, 0.26);
glVertex2f( 0.495, 0.1 );
glVertex2f(0.662, 0.1 );
glVertex2f(0.662, 0.26);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f(0.662, 0.36);
glVertex2f( 0.662, 0.1 );
glVertex2f(0.854, 0.1 );
glVertex2f(0.854, 0.36);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f(0.854, 0.32);
glVertex2f( 0.854, 0.1 );
glVertex2f(0.894, 0.1 );
glVertex2f(0.894, 0.32);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f(0.894, 0.345);
glVertex2f( 0.894, 0.1 );
glVertex2f(0.922, 0.1 );
glVertex2f(0.922, 0.345);
glEnd();
glBegin(GL_QUADS);
glColor3ub(91, 198, 244);
glVertex2f(0.922, 0.32);
glVertex2f( 0.922, 0.1 );
glVertex2f(1.0, 0.1 );
glVertex2f(1.0, 0.32);
glEnd();

//Building_2
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(-1.0, 0.212);
glVertex2f( -1.0, -0.05 );
glVertex2f(-0.993, -0.05 );
glVertex2f(-0.993, 0.212);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(-0.993, 0.28);
glVertex2f( -0.993, -0.05 );
glVertex2f(-0.94, -0.05 );
glVertex2f(-0.94, 0.28);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(-0.94, 0.1);
glVertex2f( -0.94, -0.05 );
glVertex2f(-0.932, -0.05 );
glVertex2f(-0.932, 0.1);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(-0.932, 0.212);
glVertex2f( -0.932, -0.05 );
glVertex2f(-0.894, -0.05 );
glVertex2f(-0.894, 0.212);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(-0.894, 0.168);
glVertex2f( -0.894, -0.05 );
glVertex2f(-0.83, -0.05 );
glVertex2f(-0.83, 0.168);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(-0.83, 0.316);
glVertex2f( -0.83, -0.05 );
glVertex2f(-0.708, -0.05 );
glVertex2f(-0.708, 0.284);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(-0.708, 0.1);
glVertex2f( -0.708, -0.05 );
glVertex2f(-0.688, -0.05 );
glVertex2f(-0.688, 0.1);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(-0.688, 0.27);
glVertex2f( -0.688, -0.05 );
glVertex2f(-0.674, -0.05 );
glVertex2f(-0.674, 0.27);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(-0.674, 0.315);
glVertex2f( -0.674, -0.05 );
glVertex2f(-0.656, -0.05 );
glVertex2f(-0.656, 0.315);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(-0.656, 0.3);
glVertex2f( -0.656, -0.05 );
glVertex2f(-0.63, -0.05 );
glVertex2f(-0.63, 0.3);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(-0.63, 0.335);
glVertex2f( -0.63, -0.05 );
glVertex2f(-0.568, -0.05 );
glVertex2f(-0.568, 0.335);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(-0.568, 0.3);
glVertex2f( -0.568, -0.05 );
glVertex2f(-0.544, -0.05 );
glVertex2f(-0.544, 0.3);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(-0.544, 0.325);
glVertex2f( -0.544, -0.05 );
glVertex2f(-0.52, -0.05 );
glVertex2f(-0.52, 0.325);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(-0.52, 0.27);
glVertex2f( -0.52, -0.05 );
glVertex2f(-0.49, -0.05 );
glVertex2f(-0.49, 0.27);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(-0.49, 0.34);
glVertex2f( -0.49, -0.05 );
glVertex2f(-0.482, -0.05 );
glVertex2f(-0.482, 0.34);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(-0.482, 0.36);
glVertex2f( -0.482, -0.05 );
glVertex2f(-0.476, -0.05 );
glVertex2f(-0.476, 0.36);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(-0.476, 0.38);
glVertex2f( -0.476, -0.05 );
glVertex2f(-0.464, -0.05 );
glVertex2f(-0.464, 0.38);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(-0.464, 0.41);
glVertex2f( -0.464, -0.05 );
glVertex2f(-0.426, -0.05 );
glVertex2f(-0.426, 0.41);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(-0.426, 0.38);
glVertex2f( -0.426, -0.05 );
glVertex2f(-0.414, -0.05 );
glVertex2f(-0.414, 0.38);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(-0.414, 0.36);
glVertex2f( -0.414, -0.05 );
glVertex2f(-0.402, -0.05 );
glVertex2f(-0.402, 0.36);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(-0.402, 0.34);
glVertex2f( -0.402, -0.05 );
glVertex2f(-0.396, -0.05 );
glVertex2f(-0.396, 0.34);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(-0.396, 0.27);
glVertex2f( -0.396, -0.05 );
glVertex2f(-0.388, -0.05 );
glVertex2f(-0.388, 0.27);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(-0.388, 0.33);
glVertex2f( -0.388, -0.05 );
glVertex2f(-0.292, -0.05 );
glVertex2f(-0.292, 0.33);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(-0.292, 0.37);
glVertex2f( -0.292, -0.05 );
glVertex2f(-0.224, -0.05 );
glVertex2f(-0.224, 0.37);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(-0.224, 0.15);
glVertex2f( -0.224, -0.05 );
glVertex2f(-0.21, -0.05 );
glVertex2f(-0.21, 0.15);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(-0.21, 0.32);
glVertex2f( -0.21, -0.05 );
glVertex2f(-0.164, -0.05 );
glVertex2f(-0.164, 0.34);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(-0.164, 0.182);
glVertex2f( -0.164, -0.05 );
glVertex2f(-0.152, -0.05 );
glVertex2f(-0.152, 0.182);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(-0.152, 0.25);
glVertex2f( -0.152, -0.05 );
glVertex2f(-0.114, -0.05 );
glVertex2f(-0.114, 0.225);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(-0.114, 0.164);
glVertex2f( -0.114, -0.05 );
glVertex2f(-0.10, -0.05 );
glVertex2f(-0.10, 0.164);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(-0.10, 0.287);
glVertex2f( -0.10, -0.05 );
glVertex2f(-0.019, -0.05 );
glVertex2f(-0.019, 0.287);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(-0.019, 0.151);
glVertex2f( -0.10, -0.05 );
glVertex2f(-0.006, -0.05 );
glVertex2f(-0.006, 0.151);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(-0.006, 0.255);
glVertex2f( -0.006, -0.05 );
glVertex2f(0.038, -0.05 );
glVertex2f(0.038, 0.255);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(0.038, 0.15);
glVertex2f(0.038, -0.05 );
glVertex2f(0.053, -0.05 );
glVertex2f(0.053, 0.15);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(0.053, 0.232);
glVertex2f(0.053, -0.05 );
glVertex2f(0.073, -0.05 );
glVertex2f(0.073, 0.21);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(0.073, 0.15);
glVertex2f(0.073, -0.05 );
glVertex2f(0.093, -0.05 );
glVertex2f(0.093, 0.15);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(0.093, 0.323);
glVertex2f(0.093, -0.05 );
glVertex2f(0.105, -0.05 );
glVertex2f(0.105, 0.31);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(0.105, 0.261);
glVertex2f(0.105, -0.05 );
glVertex2f(0.116, -0.05 );
glVertex2f(0.116, 0.261);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(0.116, 0.288);
glVertex2f(0.116, -0.05 );
glVertex2f(0.188, -0.05 );
glVertex2f(0.188, 0.288);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(0.188, 0.25);
glVertex2f(0.188, -0.05 );
glVertex2f(0.21, -0.05 );
glVertex2f(0.21, 0.25);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(0.21, 0.23);
glVertex2f(0.21, -0.05 );
glVertex2f(0.224, -0.05 );
glVertex2f(0.224, 0.23);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(0.224, 0.245);
glVertex2f(0.224, -0.05 );
glVertex2f(0.237, -0.05 );
glVertex2f(0.237, 0.245);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(0.237, 0.19);
glVertex2f(0.237, -0.05 );
glVertex2f(0.28, -0.05 );
glVertex2f(0.28, 0.19);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(0.28, 0.35);
glVertex2f(0.28, -0.05 );
glVertex2f(0.37, -0.05 );
glVertex2f(0.37, 0.35);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(0.37, 0.28);
glVertex2f(0.37, -0.05 );
glVertex2f(0.447, -0.05 );
glVertex2f(0.447, 0.28);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(0.447, 0.194);
glVertex2f(0.447, -0.05 );
glVertex2f(0.472, -0.05 );
glVertex2f(0.472, 0.194);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(0.472, 0.21);
glVertex2f(0.472, -0.05 );
glVertex2f(0.494, -0.05 );
glVertex2f(0.494, 0.21);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(0.494, 0.191);
glVertex2f(0.494, -0.05 );
glVertex2f(0.512, -0.05 );
glVertex2f(0.512, 0.191);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(0.512, 0.22);
glVertex2f(0.512, -0.05 );
glVertex2f(0.56, -0.05 );
glVertex2f(0.56, 0.22);
glEnd();

glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(0.56, 0.24);
glVertex2f(0.56, -0.05 );
glVertex2f(0.59, -0.05 );
glVertex2f(0.59, 0.24);
glEnd();

glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(0.59, 0.18);
glVertex2f(0.59, -0.05 );
glVertex2f(0.63, -0.05 );
glVertex2f(0.63, 0.18);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(0.63, 0.25);
glVertex2f(0.63, -0.05 );
glVertex2f(0.69, -0.05 );
glVertex2f(0.69, 0.25);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(0.69, 0.22);
glVertex2f(0.69, -0.05 );
glVertex2f(0.72, -0.05 );
glVertex2f(0.72, 0.22);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(0.72, 0.2);
glVertex2f(0.72, -0.05 );
glVertex2f(0.75, -0.05 );
glVertex2f(0.75, 0.2);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(0.75, 0.18);
glVertex2f(0.75, -0.05 );
glVertex2f(0.78, -0.05 );
glVertex2f(0.78, 0.18);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(0.78, 0.15);
glVertex2f(0.78, -0.05 );
glVertex2f(0.81, -0.05 );
glVertex2f(0.81, 0.15);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(0.81, 0.25);
glVertex2f(0.81, -0.05 );
glVertex2f(0.83, -0.05 );
glVertex2f(0.83, 0.25);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(0.83, 0.22);
glVertex2f(0.83, -0.05 );
glVertex2f(0.86, -0.05 );
glVertex2f(0.86, 0.22);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(0.86, 0.26);
glVertex2f(0.86, -0.05 );
glVertex2f(0.89, -0.05 );
glVertex2f(0.89, 0.26);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(0.89, 0.17);
glVertex2f(0.89, -0.05 );
glVertex2f(0.93, -0.05 );
glVertex2f(0.93, 0.17);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(0.93, 0.23);
glVertex2f(0.93, -0.05 );
glVertex2f(0.96, -0.05 );
glVertex2f(0.96, 0.19);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(0.96, 0.16);
glVertex2f(0.96, -0.05 );
glVertex2f(0.98, -0.05 );
glVertex2f(0.98, 0.16);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 170, 221);
glVertex2f(0.98, 0.3);
glVertex2f(0.98, -0.05 );
glVertex2f(1.0, -0.05 );
glVertex2f(1.0, 0.3);
glEnd();
//building 2 end

glBegin(GL_QUADS); //back sea 1
glColor3ub(46, 144, 217);
glVertex2f(1, -0.05);
glVertex2f(1, -0.15 );
glVertex2f(-1, -0.15 );
glVertex2f(-1, -0.05);
glEnd();


glPushMatrix();
glTranslatef(position3,0,0);
glBegin(GL_TRIANGLES); //back sea 1 waves left to right 1
glColor3ub(46, 144, 217);
glVertex2f(1, -0.05);
glVertex2f(0.88, -0.03);
glVertex2f(0.7, -0.05 );
glEnd();

glBegin(GL_TRIANGLES); //back sea 1 waves left to right 2
glColor3ub(46, 144, 217);
glVertex2f(0.25, -0.05);
glVertex2f(0.52, -0.03);
glVertex2f(0.7, -0.05 );
glEnd();

glBegin(GL_TRIANGLES); //back sea 1 waves left to right 3
glColor3ub(46, 144, 217);
glVertex2f(0.25, -0.05);
glVertex2f(-0.02, -0.03);
glVertex2f(-0.3, -0.05 );
glEnd();

glBegin(GL_TRIANGLES); //back sea 1 waves left to right 4
glColor3ub(46, 144, 217);
glVertex2f(-0.85, -0.05);
glVertex2f(-0.6, -0.03);
glVertex2f(-0.3, -0.05 );
glEnd();

glBegin(GL_TRIANGLES); //back sea 1 waves left to right 5
glColor3ub(46, 144, 217);
glVertex2f(-0.82, -0.05);
glVertex2f(-1, -0.05);
glVertex2f(-0.92, -0.03);
glEnd();
glPopMatrix();


glBegin(GL_QUADS); //back sea 2
glColor3ub(28, 131, 180);
glVertex2f(1, -0.15);
glVertex2f(1, -0.22);
glVertex2f(-1, -0.22 );
glVertex2f(-1, -0.15);
glEnd();

glPushMatrix();
glTranslatef(position4,0,0);
glBegin(GL_TRIANGLES); //back sea 2 waves left to right 1
glColor3ub(28, 131, 180);
glVertex2f(1, -0.15);
glVertex2f(0.88, -0.13);
glVertex2f(0.7, -0.15 );
glEnd();

glBegin(GL_TRIANGLES); //back sea 2 waves left to right 2
glColor3ub(28, 131, 180);
glVertex2f(0.2, -0.15);
glVertex2f(0.52, -0.13);
glVertex2f(0.7, -0.15 );
glEnd();

glBegin(GL_TRIANGLES); //back sea 2 waves left to right 3
glColor3ub(28, 131, 180);
glVertex2f(0.25, -0.15);
glVertex2f(-0.02, -0.13);
glVertex2f(-0.3, -0.15 );
glEnd();

glBegin(GL_TRIANGLES); //back sea 2 waves left to right 4
glColor3ub(28, 131, 180);
glVertex2f(-0.38, -0.13);
glVertex2f(-0.38, -0.15);
glVertex2f(-0.3, -0.15 );
glEnd();

glBegin(GL_TRIANGLES); //back sea 2 waves left to right 5
glColor3ub(28, 131, 180);
glVertex2f(-0.38, -0.15);
glVertex2f(-0.38, -0.13);
glVertex2f(-0.58, -0.15);
glEnd();

glBegin(GL_TRIANGLES); //back sea 2 waves left to right 6
glColor3ub(28, 131, 180);
glVertex2f(-0.58, -0.15);
glVertex2f(-0.72, -0.13);
glVertex2f(-0.88, -0.15);
glEnd();

glBegin(GL_TRIANGLES); //back sea 2 waves left to right 6
glColor3ub(28, 131, 180);
glVertex2f(-1, -0.15);
glVertex2f(-0.94, -0.13);
glVertex2f(-0.88, -0.15);
glEnd();

glPopMatrix();


glBegin(GL_QUADS); //Middle port
glColor3ub(164, 160, 159);
glVertex2f(1, -0.22);
glVertex2f(1, -0.38);
glVertex2f(-1, -0.38);
glVertex2f(-1, -0.22);
glEnd();

glBegin(GL_QUADS);//front port
glColor3ub(192, 192, 192);
glVertex2f(-1, -0.58);
glVertex2f(-1, -1);
glVertex2f(1, -1);
glVertex2f(1, -0.58);
glEnd();


//Back Ship Start
glPushMatrix();
glTranslatef(position5,0,0);//animate ship

glBegin(GL_QUADS); //Cabin
glColor3ub(203, 205, 204);
glVertex2f(0.66, -0.088);
glVertex2f(0.79, -0.088 );
glVertex2f(0.79, -0.17 );
glVertex2f(0.66, -0.17);
glEnd();

glBegin(GL_QUADS); //Cabin middle line
glColor3ub(127, 128, 127);
glVertex2f(0.66, -0.125);
glVertex2f(0.79, -0.125 );
glVertex2f(0.79, -0.13 );
glVertex2f(0.66, -0.13);
glEnd();

glBegin(GL_QUADS); //Cabin middle line 2
glColor3ub(127, 128, 127);
glVertex2f(0.695, -0.084);
glVertex2f(0.79, -0.084 );
glVertex2f(0.79, -0.088 );
glVertex2f(0.695, -0.088);
glEnd();

glBegin(GL_QUADS); //Cabin upper
glColor3ub(203, 205, 204);
glVertex2f(0.695, -0.025);
glVertex2f(0.79, -0.025 );
glVertex2f(0.79, -0.084 );
glVertex2f(0.695, -0.084);
glEnd();

glBegin(GL_QUADS); //Cabin Cabin middle line 3
glColor3ub(127, 128, 127);
glVertex2f(0.695, -0.025);
glVertex2f(0.79, -0.025 );
glVertex2f(0.79, -0.02 );
glVertex2f(0.695, -0.02);
glEnd();

glBegin(GL_QUADS); //cabin upper
glColor3ub(203, 205, 204);
glVertex2f(0.695, -0.02);
glVertex2f(0.79, -0.02 );
glVertex2f(0.79, 0.008 );
glVertex2f(0.684, 0.008);
glEnd();


glBegin(GL_QUADS); //cabin middle 4
glColor3ub(131, 128, 135);
glVertex2f(0.73, 0.01);
glVertex2f(0.778, 0.01);
glVertex2f(0.778, 0.008 );
glVertex2f(0.73, 0.008);
glEnd();


glBegin(GL_QUADS); //cabin upper
glColor3ub(203, 205, 204);
glVertex2f(0.73, 0.01);
glVertex2f(0.778, 0.01);
glVertex2f(0.778, 0.03 );
glVertex2f(0.73, 0.03);
glEnd();


glBegin(GL_QUADS); //cabin flag rod
glColor3ub(203, 205, 204);
glVertex2f(0.75, 0.03);
glVertex2f(0.754, 0.03);
glVertex2f(0.754, 0.078 );
glVertex2f(0.75, 0.078);
glEnd();

glBegin(GL_QUADS); //cabin flag
glColor3ub(46, 184, 46);
glVertex2f(0.754, 0.074);
glVertex2f(0.778, 0.074);
glVertex2f(0.778, 0.054 );
glVertex2f(0.754, 0.054);
glEnd();

glBegin(GL_LINES); //cabin flag
glColor3ub(0, 179, 60);
glVertex2f(0.754, 0.074);
glVertex2f(0.778, 0.074);
glVertex2f(0.778, 0.074);
glVertex2f(0.778, 0.054 );
glVertex2f(0.778, 0.054 );
glVertex2f(0.754, 0.054);
glVertex2f(0.754, 0.054);
glVertex2f(0.754, 0.074);
glEnd();


    GLfloat x=.766f; GLfloat y=.064f; GLfloat radius =0.006f;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 0, 0); // flag circle
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


glBegin(GL_QUADS); //top windows 1
glColor3ub(114, 136, 173);
glVertex2f(0.691, 0.004);
glVertex2f(0.71, 0.004 );
glVertex2f(0.71, -0.014 );
glVertex2f(0.698, -0.014);
glEnd();

glBegin(GL_QUADS); //top windows 2
glColor3ub(114, 136, 173);
glVertex2f(0.715, 0.004);
glVertex2f(0.73, 0.004 );
glVertex2f(0.73, -0.014 );
glVertex2f(0.715, -0.014);
glEnd();

glBegin(GL_QUADS); //top windows 3
glColor3ub(114, 136, 173);
glVertex2f(0.735, 0.004);
glVertex2f(0.75, 0.004 );
glVertex2f(0.75, -0.014 );
glVertex2f(0.735, -0.014);
glEnd();

glBegin(GL_QUADS); //top windows 4
glColor3ub(114, 136, 173);
glVertex2f(0.755, 0.004);
glVertex2f(0.77, 0.004 );
glVertex2f(0.77, -0.014 );
glVertex2f(0.755, -0.014);
glEnd();

glBegin(GL_QUADS); //top windows 5
glColor3ub(114, 136, 173);
glVertex2f(0.774, 0.004);
glVertex2f(0.788, 0.004 );
glVertex2f(0.788, -0.014 );
glVertex2f(0.774, -0.014);
glEnd();

glBegin(GL_QUADS); //middle windows 1
glColor3ub(114, 136, 173);
glVertex2f(0.7, -0.03);
glVertex2f(0.71, -0.03 );
glVertex2f(0.71, -0.045 );
glVertex2f(0.7, -0.045);
glEnd();

glBegin(GL_QUADS); //middle windows 2
glColor3ub(114, 136, 173);
glVertex2f(0.715, -0.03);
glVertex2f(0.725, -0.03 );
glVertex2f(0.725, -0.045 );
glVertex2f(0.715, -0.045);
glEnd();

glBegin(GL_QUADS); //middle windows 3
glColor3ub(114, 136, 173);
glVertex2f(0.735, -0.03);
glVertex2f(0.75, -0.03 );
glVertex2f(0.75, -0.045 );
glVertex2f(0.735, -0.045);
glEnd();

glBegin(GL_QUADS); //middle windows 4
glColor3ub(114, 136, 173);
glVertex2f(0.76, -0.03);
glVertex2f(0.77, -0.03 );
glVertex2f(0.77, -0.045 );
glVertex2f(0.76, -0.045);
glEnd();

glBegin(GL_QUADS); //middle windows 5
glColor3ub(114, 136, 173);
glVertex2f(0.775, -0.03);
glVertex2f(0.785, -0.03 );
glVertex2f(0.785, -0.045 );
glVertex2f(0.775, -0.045);
glEnd();

glBegin(GL_QUADS); //middle windows 6
glColor3ub(114, 136, 173);
glVertex2f(0.7, -0.055);
glVertex2f(0.71,-0.055 );
glVertex2f(0.71, -0.07 );
glVertex2f(0.7, -0.07);
glEnd();

glBegin(GL_QUADS); //middle windows 7
glColor3ub(114, 136, 173);
glVertex2f(0.715, -0.055);
glVertex2f(0.725, -0.055 );
glVertex2f(0.725, -0.07 );
glVertex2f(0.715, -0.07);
glEnd();

glBegin(GL_QUADS); //middle windows 8
glColor3ub(114, 136, 173);
glVertex2f(0.735, -0.055);
glVertex2f(0.75,-0.055 );
glVertex2f(0.75, -0.07 );
glVertex2f(0.735, -0.07);
glEnd();

glBegin(GL_QUADS); //middle windows 9
glColor3ub(114, 136, 173);
glVertex2f(0.76, -0.055);
glVertex2f(0.77, -0.055 );
glVertex2f(0.77,-0.07 );
glVertex2f(0.76, -0.07);
glEnd();

glBegin(GL_QUADS); //middle windows 10
glColor3ub(114, 136, 173);
glVertex2f(0.775, -0.055);
glVertex2f(0.785,-0.055 );
glVertex2f(0.785, -0.07 );
glVertex2f(0.775, -0.07);
glEnd();


   GLfloat x1=.68f; GLfloat y1=-.15f; GLfloat radius1 =0.009f;
	int triangleAmount1 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(114, 136, 173); // lower windows 1
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= triangleAmount1;i++) {
			glVertex2f(
		            x1 + (radius1 * cos(i *  twicePi1 / triangleAmount1)),
			    y1 + (radius1 * sin(i * twicePi1 / triangleAmount1))
			);
		}
	glEnd();

	   GLfloat x2=.7f; GLfloat y2=-.15f; GLfloat radius2 =0.009f;
	int triangleAmount2 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi2 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(114, 136, 173); // lower windows 1
		glVertex2f(x2, y2); // center of circle
		for(i = 0; i <= triangleAmount2;i++) {
			glVertex2f(
		            x2 + (radius2 * cos(i *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i * twicePi2 / triangleAmount2))
			);
		}
	glEnd();


	   GLfloat x3=.72f; GLfloat y3=-.15f; GLfloat radius3 =0.009f;
	int triangleAmount3 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi3 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(114, 136, 173); // lower windows 1
		glVertex2f(x3, y3); // center of circle
		for(i = 0; i <= triangleAmount3;i++) {
			glVertex2f(
		            x3 + (radius3 * cos(i *  twicePi3 / triangleAmount3)),
			    y3 + (radius3 * sin(i * twicePi3 / triangleAmount3))
			);
		}
	glEnd();


glBegin(GL_QUADS); //cargo
glColor3ub(53, 77, 156);
glVertex2f(0.545, -0.135);
glVertex2f(0.615,-0.135 );
glVertex2f(0.615, -0.176 );
glVertex2f(0.545, -0.175);
glEnd();

glBegin(GL_LINES); //cargo
glColor3ub(22, 42, 119);
glVertex2f(0.545, -0.135);
glVertex2f(0.615,-0.135 );

glVertex2f(0.615,-0.135 );
glVertex2f(0.615, -0.176 );

glVertex2f(0.615, -0.176 );
glVertex2f(0.545, -0.175);

glVertex2f(0.545, -0.175);
glVertex2f(0.545, -0.135);

glEnd();

glBegin(GL_QUADS); //cargo
glColor3ub(93, 144, 144);
glVertex2f(0.47, -0.135);
glVertex2f(0.54,-0.135 );
glVertex2f(0.54, -0.176 );
glVertex2f(0.47, -0.176);
glEnd();

glBegin(GL_LINES); //cargo
glColor3ub(68, 117, 95);
glVertex2f(0.47, -0.135);
glVertex2f(0.54,-0.135 );
glVertex2f(0.54,-0.135 );
glVertex2f(0.54, -0.176 );
glVertex2f(0.54, -0.176 );
glVertex2f(0.47, -0.176);
glVertex2f(0.47, -0.176);
glVertex2f(0.47, -0.135);
glEnd();

glBegin(GL_QUADS); //cargo
glColor3ub(46, 76, 151);
glVertex2f(0.4, -0.135);
glVertex2f(0.468,-0.135 );
glVertex2f(0.468, -0.176 );
glVertex2f(0.4, -0.176);
glEnd();

glBegin(GL_LINES); //cargo
glColor3ub(40, 57, 102);
glVertex2f(0.4, -0.135);
glVertex2f(0.468,-0.135 );
glVertex2f(0.468,-0.135 );
glVertex2f(0.468, -0.176 );
glVertex2f(0.468, -0.176 );
glVertex2f(0.4, -0.176);
glVertex2f(0.4, -0.176);
glVertex2f(0.4, -0.135);
glEnd();

glBegin(GL_QUADS); //cargo
glColor3ub(139, 60, 52);
glVertex2f(0.4, -0.098);
glVertex2f(0.468,-0.098 );
glVertex2f(0.468, -0.135 );
glVertex2f(0.4, -0.135);
glEnd();

glBegin(GL_LINES); //cargo
glColor3ub(102, 29, 24);
glVertex2f(0.4, -0.098);
glVertex2f(0.468,-0.098 );
glVertex2f(0.468,-0.098 );
glVertex2f(0.468, -0.135 );
glVertex2f(0.468, -0.135 );
glVertex2f(0.4, -0.135);
glVertex2f(0.4, -0.135);
glVertex2f(0.4, -0.098);
glEnd();

glBegin(GL_QUADS); //cargo
glColor3ub(191, 188, 195);
glVertex2f(0.47, -0.095);
glVertex2f(0.54,-0.095 );
glVertex2f(0.54, -0.135 );
glVertex2f(0.47, -0.135);
glEnd();

glBegin(GL_LINES); //cargo
glColor3ub(124, 124, 132);
glVertex2f(0.47, -0.095);
glVertex2f(0.54,-0.095 );
glVertex2f(0.54,-0.095 );
glVertex2f(0.54, -0.135 );
glVertex2f(0.54, -0.135 );
glVertex2f(0.47, -0.135);
glVertex2f(0.47, -0.135);
glVertex2f(0.47, -0.095);
glEnd();


glBegin(GL_QUADS); //cargo
glColor3ub(175, 186, 99);
glVertex2f(0.47, -0.06);
glVertex2f(0.54,-0.06 );
glVertex2f(0.54, -0.095 );
glVertex2f(0.47, -0.095);
glEnd();

glBegin(GL_LINES); //cargo
glColor3ub(113, 122, 46);
glVertex2f(0.47, -0.06);
glVertex2f(0.54,-0.06 );
glVertex2f(0.54,-0.06 );
glVertex2f(0.54, -0.095 );
glVertex2f(0.54, -0.095 );
glVertex2f(0.47, -0.095);
glVertex2f(0.47, -0.095);
glVertex2f(0.47, -0.06);
glEnd();

glBegin(GL_QUADS); //cargo
glColor3ub(100, 134, 75);
glVertex2f(0.47, -0.03);
glVertex2f(0.54,-0.03 );
glVertex2f(0.54, -0.06 );
glVertex2f(0.47, -0.06);
glEnd();

glBegin(GL_LINES); //cargo
glColor3ub(38, 107, 10);
glVertex2f(0.47, -0.03);
glVertex2f(0.54,-0.03 );
glVertex2f(0.54,-0.03 );
glVertex2f(0.54, -0.06 );
glVertex2f(0.54, -0.06 );
glVertex2f(0.47, -0.06);
glVertex2f(0.47, -0.06);
glVertex2f(0.47, -0.03);
glEnd();


glBegin(GL_QUADS); //cargo
glColor3ub(76, 59, 134);
glVertex2f(0.545, -0.097);
glVertex2f(0.615,-0.097 );
glVertex2f(0.615, -0.135 );
glVertex2f(0.545, -0.135);
glEnd();

glBegin(GL_LINES); //cargo
glColor3ub(62, 52, 96);
glVertex2f(0.545, -0.097);
glVertex2f(0.615,-0.097 );
glVertex2f(0.615,-0.097 );
glVertex2f(0.615, -0.135 );
glVertex2f(0.615, -0.135 );
glVertex2f(0.545, -0.135);
glVertex2f(0.545, -0.135);
glVertex2f(0.545, -0.097);
glEnd();

glBegin(GL_QUADS); //cargo
glColor3ub(126, 51, 38);
glVertex2f(0.545, -0.06);
glVertex2f(0.615,-0.06 );
glVertex2f(0.615, -0.097 );
glVertex2f(0.545, -0.097);
glEnd();

glBegin(GL_LINES); //cargo
glColor3ub(96, 35, 23);
glVertex2f(0.545, -0.06);
glVertex2f(0.615,-0.06 );
glVertex2f(0.615,-0.06 );
glVertex2f(0.615, -0.097 );
glVertex2f(0.615, -0.097 );
glVertex2f(0.545, -0.097);
glVertex2f(0.545, -0.097);
glVertex2f(0.545, -0.06);
glEnd();

glBegin(GL_POLYGON); //Hull
glColor3ub(33, 35, 34);
glVertex2f(0.762, -0.106);
glVertex2f(0.76, -0.13);
glVertex2f(0.75, -0.145 );
glVertex2f(0.8, -0.17);
glVertex2f(0.82, -0.15);
glVertex2f(0.83, -0.13);
glVertex2f(0.832, -0.106);
glEnd();

glBegin(GL_POLYGON); //Hull 2
glColor3ub(33, 35, 34);
glVertex2f(0.722, -0.166);
glVertex2f(0.74, -0.155);
glVertex2f(0.75, -0.145 );
glVertex2f(0.8, -0.17);
glVertex2f(0.78, -0.188);
glVertex2f(0.77, -0.204);
glVertex2f(0.765, -0.22);
glVertex2f(0.722, -0.22);
glEnd();

glBegin(GL_QUADS); //Hull 3
glColor3ub(33, 35, 34);
glVertex2f(0.637, -0.166);
glVertex2f(0.722, -0.166 );
glVertex2f(0.722, -0.22 );
glVertex2f(0.637, -0.22);
glEnd();


glBegin(GL_QUADS); //Hull 4
glColor3ub(33, 35, 34);
glVertex2f(0.637, -0.18);
glVertex2f(0.637, -0.22 );
glVertex2f(0.42, -0.22 );
glVertex2f(0.42, -0.18);
glEnd();

glBegin(GL_POLYGON); //Hull 5
glColor3ub(33, 35, 34);
glVertex2f(0.42, -0.22);
glVertex2f(0.42, -0.18);
glVertex2f(0.398, -0.16 );
glVertex2f(0.39, -0.15);
glVertex2f(0.384, -0.132);
glVertex2f(0.38, -0.132);
glVertex2f(0.38, -0.22);
glEnd();

glBegin(GL_QUADS); //Hull 5
glColor3ub(33, 35, 34);
glVertex2f(0.38, -0.132);
glVertex2f(0.38, -0.22 );
glVertex2f(0.27, -0.22 );
glVertex2f(0.27, -0.132);
glEnd();

glBegin(GL_POLYGON); //Hull 6
glColor3ub(33, 35, 34);
glVertex2f(0.27, -0.132);
glVertex2f(0.215, -0.132);
glVertex2f(0.23, -0.168 );
glVertex2f(0.248, -0.195);
glVertex2f(0.27, -0.22);
glEnd();

glBegin(GL_QUADS); //Hull 6
glColor3ub(255, 255, 255);
glVertex2f(0.383, -0.128);
glVertex2f(0.384, -0.132 );
glVertex2f(0.215, -0.132 );
glVertex2f(0.214, -0.128);
glEnd();

glBegin(GL_QUADS); //Hull 7
glColor3ub(159, 41, 37);
glVertex2f(0.383, -0.128);
glVertex2f(0.214, -0.128);
glVertex2f(0.207, -0.108 );
glVertex2f(0.38, -0.108 );
glEnd();

glBegin(GL_QUADS); //Railings
glColor3ub(255, 255, 255);
glVertex2f(0.4158, -0.176);
glVertex2f(0.42, -0.18);
glVertex2f(0.637, -0.18 );
glVertex2f(0.637, -0.176 );
glEnd();

glBegin(GL_LINES); //Railings 2
glColor3ub(255, 255, 255);

glVertex2f(0.644, -0.166);
glVertex2f(0.644, -0.145);

glVertex2f(0.644, -0.145);
glVertex2f(0.3885, -0.145);

glVertex2f(0.625, -0.145);
glVertex2f(0.625, -0.176);

glVertex2f(0.608, -0.145);
glVertex2f(0.608, -0.176);

glVertex2f(0.59, -0.145);
glVertex2f(0.59, -0.176);

glVertex2f(0.573, -0.145);
glVertex2f(0.573, -0.176);

glVertex2f(0.5545, -0.145);
glVertex2f(0.5545, -0.176);

glVertex2f(0.5375, -0.145);
glVertex2f(0.5375, -0.176);

glVertex2f(0.519, -0.145);
glVertex2f(0.519, -0.176);

glVertex2f(0.502, -0.145);
glVertex2f(0.502, -0.176);

glVertex2f(0.484, -0.145);
glVertex2f(0.484, -0.176);

glVertex2f(0.466, -0.145);
glVertex2f(0.466, -0.176);

glVertex2f(0.448, -0.145);
glVertex2f(0.448, -0.176);

glVertex2f(0.43, -0.145);
glVertex2f(0.43, -0.176);

glVertex2f(0.413, -0.145);
glVertex2f(0.413, -0.1736);

glVertex2f(0.402, -0.145);
glVertex2f(0.402, -0.1636);
glEnd();
//back ship end

//back ship shadow
glBegin(GL_POLYGON); //shadow
glColor3ub(126, 126, 125);
glVertex2f(0.66, -0.22);
glVertex2f(0.764, -0.22);
glVertex2f(0.767, -0.23);
glVertex2f(0.773, -0.24);
glVertex2f(0.79, -0.25);
glVertex2f(0.79, -0.25);
glVertex2f(0.66, -0.25);
glEnd();

glBegin(GL_POLYGON); //shadow
glColor3ub(126, 126, 125);
glVertex2f(0.66, -0.25);
glVertex2f(0.79, -0.25);
glVertex2f(0.816, -0.262);
glVertex2f(0.828, -0.274);
glVertex2f(0.83, -0.3);
glVertex2f(0.66, -0.3);
glEnd();


glBegin(GL_POLYGON); //shadow
glColor3ub(126, 126, 125);
glVertex2f(0.66, -0.22);
glVertex2f(0.66, -0.255);
glVertex2f(0.636, -0.255);
glVertex2f(0.636, -0.252);
glVertex2f(0.235, -0.252);
glVertex2f(0.255, -0.236);
glVertex2f(0.28, -0.22);
glEnd();

glBegin(GL_POLYGON); //shadow
glColor3ub(126, 126, 125);
glVertex2f(0.235, -0.252);
glVertex2f(0.225, -0.26);
glVertex2f(0.22, -0.27);
glVertex2f(0.218, -0.285);
glVertex2f(0.38, -0.285);
glVertex2f(0.385, -0.27);
glVertex2f(0.4, -0.25);
glEnd();

glBegin(GL_QUADS); //shadow
glColor3ub(126, 126, 125);
glVertex2f(0.4, -0.25);
glVertex2f(0.4, -0.29);
glVertex2f(0.47, -0.29);
glVertex2f(0.47, -0.25);
glEnd();

glBegin(GL_QUADS); //shadow
glColor3ub(126, 126, 125);
glVertex2f(0.472, -0.25);
glVertex2f(0.472, -0.324);
glVertex2f(0.54, -0.324);
glVertex2f(0.54, -0.25);
glEnd();

glBegin(GL_QUADS); //shadow
glColor3ub(126, 126, 125);
glVertex2f(0.545, -0.25);
glVertex2f(0.545, -0.31);
glVertex2f(0.62, -0.31);
glVertex2f(0.62, -0.25);
glEnd();

glBegin(GL_LINES); //shadow
glColor3ub(126, 126, 125);
glVertex2f(0.644, -0.254);
glVertex2f(0.644, -0.268);
glVertex2f(0.644, -0.268);
glVertex2f(0.42, -0.268);
glEnd();

glBegin(GL_QUADS); //shadow
glColor3ub(126, 126, 125);
glVertex2f(0.695, -0.3);
glVertex2f(0.79, -0.3);
glVertex2f(0.79, -0.33);
glVertex2f(0.695, -0.33);
glEnd();

glBegin(GL_QUADS); //shadow
glColor3ub(126, 126, 125);
glVertex2f(0.695, -0.33);
glVertex2f(0.79, -0.33);
glVertex2f(0.79, -0.35);
glVertex2f(0.685, -0.35);
glEnd();

glBegin(GL_QUADS); //shadow
glColor3ub(126, 126, 125);
glVertex2f(0.73, -0.35);
glVertex2f(0.78, -0.35);
glVertex2f(0.78, -0.355);
glVertex2f(0.73, -0.355);
glEnd();

glPopMatrix();
//back ship shadow ends

glBegin(GL_QUADS); //Cargo Floor
glColor3ub(151, 142, 124);
glVertex2f(-1, -0.275);
glVertex2f(-1, -0.312);
glVertex2f(-0.345, -0.312);
glVertex2f(-0.345, -0.275);
glEnd();

glBegin(GL_LINES); //Cargo Floor
glColor3ub(122, 111, 91);
glVertex2f(-1, -0.275);
glVertex2f(-1, -0.312);
glVertex2f(-1, -0.312);
glVertex2f(-0.345, -0.312);
glVertex2f(-0.345, -0.312);
glVertex2f(-0.345, -0.275);
glVertex2f(-0.345, -0.275);
glVertex2f(-1, -0.275);
glEnd();


glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.991, -0.281);
glVertex2f(-0.991, -0.306);
glVertex2f(-0.975, -0.306);
glVertex2f(-0.975, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.96, -0.281);
glVertex2f(-0.96, -0.306);
glVertex2f(-0.945, -0.306);
glVertex2f(-0.945, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.93, -0.281);
glVertex2f(-0.93, -0.306);
glVertex2f(-0.915, -0.306);
glVertex2f(-0.915, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.9, -0.281);
glVertex2f(-0.9, -0.306);
glVertex2f(-0.885, -0.306);
glVertex2f(-0.885, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.87, -0.281);
glVertex2f(-0.87, -0.306);
glVertex2f(-0.856, -0.306);
glVertex2f(-0.856, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.845, -0.281);
glVertex2f(-0.845, -0.306);
glVertex2f(-0.83, -0.306);
glVertex2f(-0.83, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.815, -0.281);
glVertex2f(-0.815, -0.306);
glVertex2f(-0.8, -0.306);
glVertex2f(-0.8, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.785, -0.281);
glVertex2f(-0.785, -0.306);
glVertex2f(-0.77, -0.306);
glVertex2f(-0.77, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.755, -0.281);
glVertex2f(-0.755, -0.306);
glVertex2f(-0.74, -0.306);
glVertex2f(-0.74, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.725, -0.281);
glVertex2f(-0.725, -0.306);
glVertex2f(-0.71, -0.306);
glVertex2f(-0.71, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.695, -0.281);
glVertex2f(-0.695, -0.306);
glVertex2f(-0.68, -0.306);
glVertex2f(-0.68, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.665, -0.281);
glVertex2f(-0.665, -0.306);
glVertex2f(-0.65, -0.306);
glVertex2f(-0.65, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.64, -0.281);
glVertex2f(-0.64, -0.306);
glVertex2f(-0.625, -0.306);
glVertex2f(-0.625, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.61, -0.281);
glVertex2f(-0.61, -0.306);
glVertex2f(-0.595, -0.306);
glVertex2f(-0.595, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.58, -0.281);
glVertex2f(-0.58, -0.306);
glVertex2f(-0.56, -0.306);
glVertex2f(-0.56, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.55, -0.281);
glVertex2f(-0.55, -0.306);
glVertex2f(-0.53, -0.306);
glVertex2f(-0.53, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.52, -0.281);
glVertex2f(-0.52, -0.306);
glVertex2f(-0.5, -0.306);
glVertex2f(-0.5, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.49, -0.281);
glVertex2f(-0.49, -0.306);
glVertex2f(-0.47, -0.306);
glVertex2f(-0.47, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.46, -0.281);
glVertex2f(-0.46, -0.306);
glVertex2f(-0.44, -0.306);
glVertex2f(-0.44, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.43, -0.281);
glVertex2f(-0.43, -0.306);
glVertex2f(-0.41, -0.306);
glVertex2f(-0.41, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.4, -0.281);
glVertex2f(-0.4, -0.306);
glVertex2f(-0.38, -0.306);
glVertex2f(-0.38, -0.281);
glEnd();

glBegin(GL_QUADS); //Cargo Floor inner
glColor3ub(24, 16, 1);
glVertex2f(-0.37, -0.281);
glVertex2f(-0.37, -0.306);
glVertex2f(-0.35, -0.306);
glVertex2f(-0.35, -0.281);
glEnd();

//Cargo boxes left upper then lines
glBegin(GL_QUADS);
glColor3ub(137, 97, 27);
glVertex2f(-0.855, -0.01);
glVertex2f(-0.855, -0.062);
glVertex2f(-0.768, -0.062);
glVertex2f(-0.768, -0.01);
glEnd();
glBegin(GL_QUADS);
glColor3ub(130, 17, 23);
glVertex2f(-0.8552, -0.062);
glVertex2f(-0.8552, -0.115);
glVertex2f(-0.768, -0.115);
glVertex2f(-0.768, -0.062);
glEnd();
glBegin(GL_QUADS);
glColor3ub(71, 95, 133);
glVertex2f(-0.942, -0.062);
glVertex2f(-0.942, -0.115);
glVertex2f(-0.8552, -0.115);
glVertex2f(-0.8552, -0.062);
glEnd();
glBegin(GL_QUADS);
glColor3ub(137, 97, 27);
glVertex2f(-1, -0.115);
glVertex2f(-1, -0.168);
glVertex2f(-0.942, -0.168);
glVertex2f(-0.942, -0.115);
glEnd();
glBegin(GL_QUADS);
glColor3ub(53, 54, 160);
glVertex2f(-0.942, -0.115);
glVertex2f(-0.942, -0.168);
glVertex2f(-0.8552, -0.168);
glVertex2f(-0.8552, -0.115);
glEnd();
glBegin(GL_QUADS);
glColor3ub(118, 77, 145);
glVertex2f(-0.855, -0.115);
glVertex2f(-0.8552, -0.168);
glVertex2f(-0.768, -0.168);
glVertex2f(-0.768, -0.115);
glEnd();
glBegin(GL_QUADS);
glColor3ub(53, 54, 160);
glVertex2f(-0.768, -0.115);
glVertex2f(-0.768, -0.168);
glVertex2f(-0.677, -0.168);
glVertex2f(-0.677, -0.115);
glEnd();
glBegin(GL_QUADS);
glColor3ub(161, 47, 53);
glVertex2f(-0.768, -0.168);
glVertex2f(-0.768, -0.222);
glVertex2f(-0.677, -0.222);
glVertex2f(-0.677, -0.168);
glEnd();
glBegin(GL_QUADS);
glColor3ub(205, 194, 49);
glVertex2f(-0.8552, -0.168);
glVertex2f(-0.8552, -0.222);
glVertex2f(-0.768, -0.222);
glVertex2f(-0.768, -0.168);
glEnd();
glBegin(GL_QUADS);
glColor3ub(161, 47, 53);
glVertex2f(-0.945, -0.168);
glVertex2f(-0.945, -0.222);
glVertex2f(-0.8552, -0.222);
glVertex2f(-0.8552, -0.168);
glEnd();
glBegin(GL_QUADS);
glColor3ub(56, 84, 129);
glVertex2f(-1, -0.168);
glVertex2f(-1, -0.222);
glVertex2f(-0.945, -0.222);
glVertex2f(-0.945, -0.168);
glEnd();
glBegin(GL_QUADS);
glColor3ub(157, 53, 116);
glVertex2f(-1, -0.222);
glVertex2f(-1, -0.274);
glVertex2f(-0.945, -0.274);
glVertex2f(-0.945, -0.222);
glEnd();
glBegin(GL_QUADS);
glColor3ub(205, 194, 49);
glVertex2f(-0.945, -0.222);
glVertex2f(-0.945, -0.274);
glVertex2f(-0.8552, -0.274);
glVertex2f(-0.8552, -0.222);
glEnd();
glBegin(GL_QUADS);
glColor3ub(63, 163, 92);
glVertex2f(-0.8552, -0.222);
glVertex2f(-0.8552, -0.274);
glVertex2f(-0.768, -0.274);
glVertex2f(-0.768, -0.222);
glEnd();
glBegin(GL_QUADS);
glColor3ub(205, 194, 49);
glVertex2f(-0.768, -0.222);
glVertex2f(-0.768, -0.274);
glVertex2f(-0.677, -0.274);
glVertex2f(-0.677, -0.222);
glEnd();
glBegin(GL_QUADS);
glColor3ub(191, 181, 40);
glVertex2f(-0.644, -0.222);
glVertex2f(-0.554, -0.222);
glVertex2f(-0.554, -0.275);
glVertex2f(-0.644, -0.275);
glEnd();
glBegin(GL_QUADS);
glColor3ub(140, 31, 35);
glVertex2f(-0.644, -0.168);
glVertex2f(-0.554, -0.168);
glVertex2f(-0.554, -0.222);
glVertex2f(-0.644, -0.222);
glEnd();
glBegin(GL_QUADS);
glColor3ub(38, 40, 151);
glVertex2f(-0.644, -0.116);
glVertex2f(-0.554, -0.116);
glVertex2f(-0.554, -0.168);
glVertex2f(-0.644, -0.168);
glEnd();
glBegin(GL_QUADS);
glColor3ub(69, 90, 124);
glVertex2f(-0.644, -0.066);
glVertex2f(-0.554, -0.066);
glVertex2f(-0.554, -0.116);
glVertex2f(-0.644, -0.116);
glEnd();
glBegin(GL_QUADS);
glColor3ub(61, 173, 95);
glVertex2f(-0.554, -0.222);
glVertex2f(-0.465, -0.222);
glVertex2f(-0.465, -0.275);
glVertex2f(-0.554, -0.275);
glEnd();
glBegin(GL_QUADS);
glColor3ub(50, 71, 109);
glVertex2f(-0.554, -0.168);
glVertex2f(-0.465, -0.168);
glVertex2f(-0.465, -0.222);
glVertex2f(-0.554, -0.222);
glEnd();
glBegin(GL_QUADS);
glColor3ub(132, 91, 25);
glVertex2f(-0.554, -0.116);
glVertex2f(-0.465, -0.116);
glVertex2f(-0.465, -0.168);
glVertex2f(-0.554, -0.168);
glEnd();
glBegin(GL_QUADS);
glColor3ub(162, 46, 53);
glVertex2f(-0.554, -0.066);
glVertex2f(-0.465, -0.066);
glVertex2f(-0.465, -0.116);
glVertex2f(-0.554, -0.116);
glEnd();
glBegin(GL_QUADS);
glColor3ub(190, 184, 37);
glVertex2f(-0.554, -0.012);
glVertex2f(-0.465, -0.012);
glVertex2f(-0.465, -0.066);
glVertex2f(-0.554, -0.066);
glEnd();
glBegin(GL_QUADS);
glColor3ub(102, 67, 132);
glVertex2f(-0.554, 0.04);
glVertex2f(-0.465, 0.04);
glVertex2f(-0.465, -0.012);
glVertex2f(-0.554, -0.012);
glEnd();
glBegin(GL_QUADS);
glColor3ub(196, 185, 42);
glVertex2f(-0.465, -0.225);
glVertex2f(-0.375, -0.225);
glVertex2f(-0.375, -0.275);
glVertex2f(-0.465, -0.275);
glEnd();
glBegin(GL_QUADS);
glColor3ub(173, 85, 28);
glVertex2f(-0.465, -0.18);
glVertex2f(-0.375, -0.18);
glVertex2f(-0.375, -0.225);
glVertex2f(-0.465, -0.225);
glEnd();

glBegin(GL_QUADS);
glColor3ub(19, 23, 119);
glVertex2f(-0.465, -0.135);
glVertex2f(-0.375, -0.135);
glVertex2f(-0.375, -0.18);
glVertex2f(-0.465, -0.18);
glEnd();

glBegin(GL_QUADS);
glColor3ub(135, 25, 32);
glVertex2f(-0.465, -0.085);
glVertex2f(-0.375, -0.085);
glVertex2f(-0.375, -0.135);
glVertex2f(-0.465, -0.135);
glEnd();

glBegin(GL_QUADS);
glColor3ub(33, 33, 139);
glVertex2f(-0.465, -0.025);
glVertex2f(-0.375, -0.025);
glVertex2f(-0.375, -0.085);
glVertex2f(-0.465, -0.085);
glEnd();


glBegin(GL_LINES);
glColor3ub(64, 64, 64);
glVertex2f(-0.855, -0.01);//1
glVertex2f(-0.855, -0.062);
glVertex2f(-0.855, -0.062);
glVertex2f(-0.768, -0.062);
glVertex2f(-0.768, -0.062);
glVertex2f(-0.768, -0.01);
glVertex2f(-0.768, -0.01);
glVertex2f(-0.855, -0.01);

glVertex2f(-0.855, -0.062);//2
glVertex2f(-0.855, -0.115);
glVertex2f(-0.855, -0.115);
glVertex2f(-0.768, -0.115);
glVertex2f(-0.768, -0.115);
glVertex2f(-0.768, -0.062);
glVertex2f(-0.768, -0.062);
glVertex2f(-0.855, -0.062);

glVertex2f(-0.942, -0.062);//3
glVertex2f(-0.942, -0.115);
glVertex2f(-0.942, -0.115);
glVertex2f(-0.855, -0.115);
glVertex2f(-0.855, -0.115);
glVertex2f(-0.855, -0.062);
glVertex2f(-0.855, -0.062);
glVertex2f(-0.942, -0.062);

glVertex2f(-1, -0.115);//4
glVertex2f(-1, -0.168);
glVertex2f(-1, -0.168);
glVertex2f(-0.942, -0.168);
glVertex2f(-0.942, -0.168);
glVertex2f(-0.942, -0.115);
glVertex2f(-0.942, -0.115);
glVertex2f(-1, -0.115);

glVertex2f(-0.942, -0.115);//5
glVertex2f(-0.942, -0.168);
glVertex2f(-0.942, -0.168);
glVertex2f(-0.8552, -0.168);
glVertex2f(-0.8552, -0.168);
glVertex2f(-0.8552, -0.115);
glVertex2f(-0.8552, -0.115);
glVertex2f(-0.942, -0.115);

glVertex2f(-0.8552, -0.115);//6
glVertex2f(-0.8552, -0.168);
glVertex2f(-0.8552, -0.168);
glVertex2f(-0.768, -0.168);
glVertex2f(-0.768, -0.168);
glVertex2f(-0.768, -0.115);
glVertex2f(-0.768, -0.115);
glVertex2f(-0.8552, -0.115);

glVertex2f(-0.768, -0.115);//7
glVertex2f(-0.768, -0.168);
glVertex2f(-0.768, -0.168);
glVertex2f(-0.677, -0.168);
glVertex2f(-0.677, -0.168);
glVertex2f(-0.677, -0.115);
glVertex2f(-0.677, -0.115);
glVertex2f(-0.768, -0.115);

glVertex2f(-0.768, -0.168);//8
glVertex2f(-0.768, -0.222);
glVertex2f(-0.768, -0.222);
glVertex2f(-0.677, -0.222);
glVertex2f(-0.677, -0.222);
glVertex2f(-0.677, -0.168);
glVertex2f(-0.677, -0.168);
glVertex2f(-0.768, -0.168);

glVertex2f(-0.8552, -0.168);//9
glVertex2f(-0.8552, -0.222);
glVertex2f(-0.8552, -0.222);
glVertex2f(-0.768, -0.222);
glVertex2f(-0.768, -0.222);
glVertex2f(-0.768, -0.168);
glVertex2f(-0.768, -0.168);
glVertex2f(-0.8552, -0.168);

glVertex2f(-0.945, -0.168);//10
glVertex2f(-0.945, -0.222);
glVertex2f(-0.945, -0.222);
glVertex2f(-0.8552, -0.222);
glVertex2f(-0.8552, -0.222);
glVertex2f(-0.8552, -0.168);
glVertex2f(-0.8552, -0.168);
glVertex2f(-0.945, -0.168);

glVertex2f(-1, -0.168);//11
glVertex2f(-1, -0.222);
glVertex2f(-1, -0.222);
glVertex2f(-0.945, -0.222);
glVertex2f(-0.945, -0.222);
glVertex2f(-0.945, -0.168);
glVertex2f(-0.945, -0.168);
glVertex2f(-1, -0.168);

glVertex2f(-1, -0.222);//12
glVertex2f(-1, -0.274);
glVertex2f(-1, -0.274);
glVertex2f(-0.945, -0.274);
glVertex2f(-0.945, -0.274);
glVertex2f(-0.945, -0.222);
glVertex2f(-0.945, -0.222);
glVertex2f(-1, -0.222);

glVertex2f(-0.945, -0.222);//13
glVertex2f(-0.945, -0.274);
glVertex2f(-0.945, -0.274);
glVertex2f(-0.8552, -0.274);
glVertex2f(-0.8552, -0.274);
glVertex2f(-0.8552, -0.222);
glVertex2f(-0.8552, -0.222);
glVertex2f(-0.945, -0.222);

glVertex2f(-0.8552, -0.222);//14
glVertex2f(-0.8552, -0.274);
glVertex2f(-0.8552, -0.274);
glVertex2f(-0.768, -0.274);
glVertex2f(-0.768, -0.274);
glVertex2f(-0.768, -0.222);
glVertex2f(-0.768, -0.222);
glVertex2f(-0.8552, -0.222);

glVertex2f(-0.768, -0.222);//15
glVertex2f(-0.768, -0.274);
glVertex2f(-0.768, -0.274);
glVertex2f(-0.677, -0.274);
glVertex2f(-0.677, -0.274);
glVertex2f(-0.677, -0.222);
glVertex2f(-0.677, -0.222);
glVertex2f(-0.768, -0.222);

glVertex2f(-0.644, -0.222);//16
glVertex2f(-0.554, -0.222);
glVertex2f(-0.554, -0.222);
glVertex2f(-0.554, -0.275);
glVertex2f(-0.554, -0.275);
glVertex2f(-0.644, -0.275);
glVertex2f(-0.644, -0.275);
glVertex2f(-0.644, -0.222);

glVertex2f(-0.644, -0.168);//17
glVertex2f(-0.554, -0.168);
glVertex2f(-0.554, -0.168);
glVertex2f(-0.554, -0.222);
glVertex2f(-0.554, -0.222);
glVertex2f(-0.644, -0.222);
glVertex2f(-0.644, -0.222);
glVertex2f(-0.644, -0.168);

glVertex2f(-0.644, -0.116);//18
glVertex2f(-0.554, -0.116);
glVertex2f(-0.554, -0.116);
glVertex2f(-0.554, -0.168);
glVertex2f(-0.554, -0.168);
glVertex2f(-0.644, -0.168);
glVertex2f(-0.644, -0.168);
glVertex2f(-0.644, -0.116);

glVertex2f(-0.644, -0.066);//19
glVertex2f(-0.554, -0.066);
glVertex2f(-0.554, -0.066);
glVertex2f(-0.554, -0.116);
glVertex2f(-0.554, -0.116);
glVertex2f(-0.644, -0.116);
glVertex2f(-0.644, -0.116);
glVertex2f(-0.644, -0.066);

glVertex2f(-0.554, -0.222);//20
glVertex2f(-0.465, -0.222);
glVertex2f(-0.465, -0.222);
glVertex2f(-0.465, -0.275);
glVertex2f(-0.465, -0.275);
glVertex2f(-0.554, -0.275);
glVertex2f(-0.554, -0.275);
glVertex2f(-0.554, -0.222);

glVertex2f(-0.554, -0.168);//21
glVertex2f(-0.465, -0.168);
glVertex2f(-0.465, -0.168);
glVertex2f(-0.465, -0.222);
glVertex2f(-0.465, -0.222);
glVertex2f(-0.554, -0.222);
glVertex2f(-0.554, -0.222);
glVertex2f(-0.554, -0.168);

glVertex2f(-0.554, -0.116);//22
glVertex2f(-0.465, -0.116);
glVertex2f(-0.465, -0.116);
glVertex2f(-0.465, -0.168);
glVertex2f(-0.465, -0.168);
glVertex2f(-0.554, -0.168);
glVertex2f(-0.554, -0.168);
glVertex2f(-0.554, -0.116);

glVertex2f(-0.554, -0.066);//23
glVertex2f(-0.465, -0.066);
glVertex2f(-0.465, -0.066);
glVertex2f(-0.465, -0.116);
glVertex2f(-0.465, -0.116);
glVertex2f(-0.554, -0.116);
glVertex2f(-0.554, -0.116);
glVertex2f(-0.554, -0.066);

glVertex2f(-0.554, -0.012);//24
glVertex2f(-0.465, -0.012);
glVertex2f(-0.465, -0.012);
glVertex2f(-0.465, -0.066);
glVertex2f(-0.465, -0.066);
glVertex2f(-0.554, -0.066);
glVertex2f(-0.554, -0.066);
glVertex2f(-0.554, -0.012);

glVertex2f(-0.554, 0.04);//25
glVertex2f(-0.465, 0.04);
glVertex2f(-0.465, 0.04);
glVertex2f(-0.465, -0.012);
glVertex2f(-0.465, -0.012);
glVertex2f(-0.554, -0.012);
glVertex2f(-0.554, -0.012);
glVertex2f(-0.554, 0.04);

glVertex2f(-0.465, -0.225);//26
glVertex2f(-0.375, -0.225);
glVertex2f(-0.375, -0.225);
glVertex2f(-0.375, -0.275);
glVertex2f(-0.375, -0.275);
glVertex2f(-0.465, -0.275);
glVertex2f(-0.465, -0.275);
glVertex2f(-0.465, -0.225);

glVertex2f(-0.465, -0.18);//27
glVertex2f(-0.375, -0.18);
glVertex2f(-0.375, -0.18);
glVertex2f(-0.375, -0.225);
glVertex2f(-0.375, -0.225);
glVertex2f(-0.465, -0.225);
glVertex2f(-0.465, -0.225);
glVertex2f(-0.465, -0.18);

glVertex2f(-0.465, -0.135);//28
glVertex2f(-0.375, -0.135);
glVertex2f(-0.375, -0.135);
glVertex2f(-0.375, -0.18);
glVertex2f(-0.375, -0.18);
glVertex2f(-0.465, -0.18);
glVertex2f(-0.465, -0.18);
glVertex2f(-0.465, -0.135);

glVertex2f(-0.465, -0.085);//29
glVertex2f(-0.375, -0.085);
glVertex2f(-0.375, -0.085);
glVertex2f(-0.375, -0.135);
glVertex2f(-0.375, -0.135);
glVertex2f(-0.465, -0.135);
glVertex2f(-0.465, -0.135);

glVertex2f(-0.465, -0.025);//30
glVertex2f(-0.375, -0.025);
glVertex2f(-0.375, -0.025);
glVertex2f(-0.375, -0.085);
glVertex2f(-0.375, -0.085);
glVertex2f(-0.465, -0.085);
glVertex2f(-0.465, -0.085);
glVertex2f(-0.465, -0.025);
glEnd();

//box carrier back


glLoadIdentity();

glBegin(GL_QUADS);// TOP HORIZONTAL STAND
glColor3ub(173, 141, 7);
glVertex2f(-0.898, 0.216);
glVertex2f(-0.898, 0.204);
glVertex2f(-0.396, 0.204);
glVertex2f(-0.38, 0.216);
glEnd();
glBegin(GL_QUADS);// top diagonal stand
glColor3ub(173, 141, 7);
glVertex2f(-0.658, 0.38);
glVertex2f(-0.864, 0.216);
glVertex2f(-0.855, 0.216);
glVertex2f(-0.658, 0.372);
glEnd();
glBegin(GL_QUADS);// left stand
glColor3ub(185, 152, 59);
glVertex2f(-0.797, 0.286);
glVertex2f(-0.797, -0.26);
glVertex2f(-0.79, -0.26);
glVertex2f(-0.79, 0.286);
glEnd();
glBegin(GL_QUADS);// right stand
glColor3ub(185, 152, 59);
glVertex2f(-0.655, 0.249);
glVertex2f(-0.655, -0.26);
glVertex2f(-0.648, -0.26);
glVertex2f(-0.648, 0.249);
glEnd();
glBegin(GL_QUADS);//lower brown left
glColor3ub(61, 43, 6);
glVertex2f(-0.797, -0.258);
glVertex2f(-0.797, -0.267);
glVertex2f(-0.79, -0.267);
glVertex2f(-0.79, -0.258);
glEnd();
glBegin(GL_QUADS);//lower brown left
glColor3ub(61, 43, 6);
glVertex2f(-0.8, -0.267);
glVertex2f(-0.8, -0.274);
glVertex2f(-0.787, -0.274);
glVertex2f(-0.787, -0.267);
glEnd();
glBegin(GL_QUADS);//lower brown right
glColor3ub(61, 43, 6);
glVertex2f(-0.655, -0.258);
glVertex2f(-0.655, -0.267);
glVertex2f(-0.648, -0.267);
glVertex2f(-0.648, -0.258);
glEnd();
glBegin(GL_QUADS);//lower brown right
glColor3ub(61, 43, 6);
glVertex2f(-0.657, -0.267);
glVertex2f(-0.657, -0.274);
glVertex2f(-0.645, -0.274);
glVertex2f(-0.645, -0.267);
glEnd();

glBegin(GL_QUADS);// top left stand extension
glColor3ub(185, 152, 59);
glVertex2f(-0.6526, 0.3658);
glVertex2f(-0.6525, 0.24);
glVertex2f(-0.6495, 0.24);
glVertex2f(-0.6495, 0.3658);
glEnd();
glBegin(GL_QUADS);//top left stand extension 2
glColor3ub(185, 152, 59);
glVertex2f(-0.658, 0.398);
glVertex2f(-0.658, 0.3658);
glVertex2f(-0.6435, 0.3658);
glVertex2f(-0.6435, 0.398);
glEnd();

glBegin(GL_QUADS);// back box
glColor3ub(82, 52, 35);
glVertex2f(-0.89, 0.204);
glVertex2f(-0.89, 0.199);
glVertex2f(-0.858, 0.199);
glVertex2f(-0.858, 0.204);
glEnd();
glBegin(GL_QUADS);// back box
glColor3ub(230, 172, 49);
glVertex2f(-0.897, 0.199);
glVertex2f(-0.897, 0.165);
glVertex2f(-0.853, 0.165);
glVertex2f(-0.853, 0.199);
glEnd();
glBegin(GL_QUADS);// red box
glColor3ub(206, 29, 58);
glVertex2f(-0.717, 0.26);
glVertex2f(-0.717, 0.216);
glVertex2f(-0.659, 0.216);
glVertex2f(-0.659, 0.26);
glEnd();
glBegin(GL_QUADS);// red box glass
glColor3ub(62, 59, 59);
glVertex2f(-0.71, 0.252);
glVertex2f(-0.71, 0.242);
glVertex2f(-0.702, 0.242);
glVertex2f(-0.702, 0.252);
glEnd();
glBegin(GL_QUADS);// red box glass
glColor3ub(62, 59, 59);
glVertex2f(-0.698, 0.252);
glVertex2f(-0.698, 0.242);
glVertex2f(-0.69, 0.242);
glVertex2f(-0.69, 0.252);
glEnd();
glBegin(GL_QUADS);// red box glass
glColor3ub(62, 59, 59);
glVertex2f(-0.686, 0.252);
glVertex2f(-0.686, 0.242);
glVertex2f(-0.678, 0.242);
glVertex2f(-0.678, 0.252);
glEnd();
glBegin(GL_QUADS);// red box glass
glColor3ub(62, 59, 59);
glVertex2f(-0.674, 0.252);
glVertex2f(-0.674, 0.242);
glVertex2f(-0.666, 0.242);
glVertex2f(-0.666, 0.252);
glEnd();
glBegin(GL_LINES);// rope
glColor3ub(62, 59, 59);
glVertex2f(-0.6435, 0.376);
glVertex2f(-0.629, 0.358);
glVertex2f(-0.629, 0.358);
glVertex2f(-0.613, 0.338);
glVertex2f(-0.613, 0.338);
glVertex2f(-0.592, 0.317);
glVertex2f(-0.592, 0.317);
glVertex2f(-0.549, 0.281);
glVertex2f(-0.549, 0.281);
glVertex2f(-0.531, 0.267);
glVertex2f(-0.531, 0.267);
glVertex2f(-0.501, 0.246);
glVertex2f(-0.501, 0.246);
glVertex2f(-0.45, 0.216);
glEnd();

glBegin(GL_QUADS);// right box
glColor3ub(70, 44, 11);
glVertex2f(-0.432, 0.204);
glVertex2f(-0.432, 0.196);
glVertex2f(-0.41, 0.196);
glVertex2f(-0.41, 0.204);
glEnd();
glBegin(GL_QUADS);// right box
glColor3ub(173, 141, 7);
glVertex2f(-0.438, 0.196);
glVertex2f(-0.438, 0.191);
glVertex2f(-0.404, 0.191);
glVertex2f(-0.404, 0.196);
glEnd();
glBegin(GL_QUADS);// stand right box
glColor3ub(31, 41, 40);
glVertex2f(-0.438, 0.191);
glVertex2f(-0.438, -0.008);
glVertex2f(-0.434, -0.008);
glVertex2f(-0.434, 0.191);
glEnd();
glBegin(GL_QUADS);// stand right box
glColor3ub(31, 41, 40);
glVertex2f(-0.408, 0.191);
glVertex2f(-0.408, -0.008);
glVertex2f(-0.404, -0.008);
glVertex2f(-0.404, 0.191);
glEnd();
glBegin(GL_QUADS);// yellow box
glColor3ub(230, 172, 49);
glVertex2f(-0.44, -0.008);
glVertex2f(-0.44, -0.0255);
glVertex2f(-0.4, -0.0255);
glVertex2f(-0.4, -0.008);
glEnd();


glBegin(GL_LINES);// left of back crane stairs
glColor3ub(173, 141, 7);
glVertex2f(-0.67, 0.21);
glVertex2f(-0.67, -0.275);
glVertex2f(-0.67, 0.205);
glVertex2f(-0.655, 0.18);
glVertex2f(-0.655, 0.205);
glVertex2f(-0.67, 0.18);
glVertex2f(-0.67, 0.18);
glVertex2f(-0.655, 0.155);
glVertex2f(-0.655, 0.18);
glVertex2f(-0.67, 0.155);
glVertex2f(-0.67, 0.155);
glVertex2f(-0.655, 0.13);
glVertex2f(-0.655, 0.155);
glVertex2f(-0.67, 0.13);
glVertex2f(-0.67, 0.13);
glVertex2f(-0.655, 0.105);
glVertex2f(-0.655, 0.13);
glVertex2f(-0.67, 0.105);
glVertex2f(-0.67, 0.105);
glVertex2f(-0.655, 0.085);
glVertex2f(-0.655, 0.105);
glVertex2f(-0.67, 0.085);
glVertex2f(-0.67, 0.085);
glVertex2f(-0.655, 0.06);
glVertex2f(-0.655, 0.085);
glVertex2f(-0.67, 0.06);
glVertex2f(-0.655, 0.035);
glVertex2f(-0.655, 0.06);
glVertex2f(-0.655, 0.06);
glVertex2f(-0.67, 0.035);
glVertex2f(-0.67, 0.06);
glVertex2f(-0.655, 0.035);
glVertex2f(-0.67, 0.035);
glVertex2f(-0.655, 0.01);
glVertex2f(-0.655, 0.035);
glVertex2f(-0.67, 0.01);
glVertex2f(-0.67, 0.01);
glVertex2f(-0.655, -0.015);
glVertex2f(-0.655, 0.01);
glVertex2f(-0.67, -0.015);
glVertex2f(-0.67, -0.015);
glVertex2f(-0.655, -0.04);
glVertex2f(-0.655, -0.015);
glVertex2f(-0.67, -0.04);
glVertex2f(-0.67, -0.04);
glVertex2f(-0.655, -0.065);
glVertex2f(-0.655, -0.04);
glVertex2f(-0.67, -0.065);
glVertex2f(-0.67, -0.04);
glVertex2f(-0.655, -0.065);
glVertex2f(-0.655, -0.04);
glVertex2f(-0.67, -0.065);
glVertex2f(-0.67, -0.065);
glVertex2f(-0.655, -0.09);
glVertex2f(-0.655, -0.065);
glVertex2f(-0.67, -0.09);
glEnd();

glBegin(GL_LINES);// left of back crane stairs
glColor3ub(173, 141, 7);
glVertex2f(-0.67, -0.09);
glVertex2f(-0.655, -0.115);
glVertex2f(-0.655, -0.09);
glVertex2f(-0.67, -0.115);
glVertex2f(-0.67, -0.115);
glVertex2f(-0.655, -0.14);
glVertex2f(-0.655, -0.115);
glVertex2f(-0.67, -0.14);
glVertex2f(-0.67, -0.14);
glVertex2f(-0.655, -0.165);
glVertex2f(-0.655, -0.14);
glVertex2f(-0.67, -0.165);
glVertex2f(-0.67, -0.165);
glVertex2f(-0.655, -0.19);
glVertex2f(-0.655, -0.165);
glVertex2f(-0.67, -0.19);
glVertex2f(-0.67, -0.19);
glVertex2f(-0.655, -0.215);
glVertex2f(-0.655, -0.19);
glVertex2f(-0.67, -0.215);
glVertex2f(-0.67, -0.215);
glVertex2f(-0.655, -0.24);
glVertex2f(-0.655, -0.215);
glVertex2f(-0.67, -0.24);
glEnd();

glBegin(GL_LINES); //stairs back crane
glColor3ub(173, 141, 7);
glVertex2f(-0.695, 0.205);
glVertex2f(-0.695, -0.275);
glVertex2f(-0.685, -0.275);
glVertex2f(-0.685, 0.205);
glVertex2f(-0.695, 0.2);
glVertex2f(-0.685, 0.2);
glVertex2f(-0.695, 0.18);
glVertex2f(-0.685, 0.18);
glVertex2f(-0.695, 0.18);
glVertex2f(-0.685, 0.18);
glVertex2f(-0.695, 0.16);
glVertex2f(-0.685, 0.16);
glVertex2f(-0.695, 0.14);
glVertex2f(-0.685, 0.14);
glVertex2f(-0.695, 0.12);
glVertex2f(-0.685, 0.12);
glVertex2f(-0.695, 0.1);
glVertex2f(-0.685, 0.1);
glVertex2f(-0.695, 0.08);
glVertex2f(-0.685, 0.08);
glVertex2f(-0.695, 0.06);
glVertex2f(-0.685, 0.06);
glVertex2f(-0.695, 0.04);
glVertex2f(-0.685, 0.04);
glVertex2f(-0.695, 0.02);
glVertex2f(-0.685, 0.02);
glVertex2f(-0.695, 0.0);
glVertex2f(-0.685, 0.0);
glVertex2f(-0.695, -0.02);
glVertex2f(-0.685, -0.02);
glVertex2f(-0.695, -0.04);
glVertex2f(-0.685, -0.04);
glVertex2f(-0.695, -0.06);
glVertex2f(-0.685, -0.06);
glVertex2f(-0.695, -0.08);
glVertex2f(-0.685, -0.08);
glVertex2f(-0.695, -0.1);
glVertex2f(-0.685, -0.1);
glVertex2f(-0.695, -0.12);
glVertex2f(-0.685, -0.12);
glVertex2f(-0.695, -0.14);
glVertex2f(-0.685, -0.14);
glVertex2f(-0.695, -0.16);
glVertex2f(-0.685, -0.16);
glVertex2f(-0.695, -0.18);
glVertex2f(-0.685, -0.18);
glVertex2f(-0.695, -0.2);
glVertex2f(-0.685, -0.2);
glVertex2f(-0.695, -0.22);
glVertex2f(-0.685, -0.22);
glVertex2f(-0.695, -0.24);
glVertex2f(-0.685, -0.24);
glVertex2f(-0.695, -0.26);
glVertex2f(-0.685, -0.26);
glEnd();

glBegin(GL_QUADS);// middle horizontal stand
glColor3ub(164, 129, 3);
glVertex2f(-0.79, 0.044);
glVertex2f(-0.79, 0.028);
glVertex2f(-0.654, 0.028);
glVertex2f(-0.654, 0.044);
glEnd();

glBegin(GL_QUADS);// middle horizontal stand
glColor3ub(164, 129, 3);
glVertex2f(-0.79, -0.12);
glVertex2f(-0.79, -0.14);
glVertex2f(-0.654, -0.14);
glVertex2f(-0.654, -0.12);
glEnd();


glBegin(GL_QUADS);// middle cross top
glColor3ub(164, 129, 3);
glVertex2f(-0.79, 0.155);
glVertex2f(-0.79, 0.145);
glVertex2f(-0.655, 0.067);
glVertex2f(-0.655, 0.075);
glEnd();

glBegin(GL_QUADS);// middle cross top
glColor3ub(164, 129, 3);
glVertex2f(-0.79, 0.074);
glVertex2f(-0.79, 0.064);
glVertex2f(-0.655, 0.145);
glVertex2f(-0.655, 0.153);
glEnd();

glBegin(GL_QUADS);// middle cross down
glColor3ub(164, 129, 3);
glVertex2f(-0.79, 0.00);
glVertex2f(-0.79, -0.01);
glVertex2f(-0.655, -0.0885);
glVertex2f(-0.655, -0.08);
glEnd();

glBegin(GL_QUADS);// middle cross down
glColor3ub(164, 129, 3);
glVertex2f(-0.79, -0.085);
glVertex2f(-0.79, -0.095);
glVertex2f(-0.655, -0.011);
glVertex2f(-0.655, -0.002);
glEnd();

glBegin(GL_QUADS);// middle sea
glColor3ub(29, 131, 179);
glVertex2f(-1, -0.38);
glVertex2f(-1, -0.58);
glVertex2f(1, -0.58);
glVertex2f(1, -0.38);
glEnd();

glBegin(GL_QUADS);//crane shadow
glColor3ub(23, 109, 150);
glVertex2f(-1, -0.38);
glVertex2f(-1, -0.43);
glVertex2f(-0.94, -0.43);
glVertex2f(-0.94, -0.38);
glEnd();

glBegin(GL_QUADS);//crane shadow
glColor3ub(23, 109, 150);
glVertex2f(-0.94, -0.38);
glVertex2f(-0.94, -0.46);
glVertex2f(-0.85, -0.46);
glVertex2f(-0.85, -0.38);
glEnd();

glBegin(GL_QUADS);//crane shadow
glColor3ub(23, 109, 150);
glVertex2f(-0.85, -0.38);
glVertex2f(-0.85, -0.49);
glVertex2f(-0.77, -0.49);
glVertex2f(-0.77, -0.38);
glEnd();

glBegin(GL_QUADS);//crane shadow
glColor3ub(23, 109, 150);
glVertex2f(-0.77, -0.38);
glVertex2f(-0.77, -0.43);
glVertex2f(-0.67, -0.43);
glVertex2f(-0.67, -0.38);
glEnd();

glBegin(GL_QUADS);//crane shadow
glColor3ub(23, 109, 150);
glVertex2f(-0.695, -0.43);
glVertex2f(-0.685, -0.43);
glVertex2f(-0.685, -0.58);
glVertex2f(-0.695, -0.58);
glEnd();

glBegin(GL_QUADS);//crane shadow
glColor3ub(23, 109, 150);
glVertex2f(-0.67, -0.38);
glVertex2f(-0.65, -0.38);
glVertex2f(-0.65, -0.58);
glVertex2f(-0.67, -0.58);
glEnd();

glBegin(GL_QUADS);//crane shadow
glColor3ub(23, 109, 150);
glVertex2f(-0.795, -0.49);
glVertex2f(-0.79, -0.49);
glVertex2f(-0.79, -0.58);
glVertex2f(-0.795, -0.58);
glEnd();

glBegin(GL_QUADS);//crane shadow
glColor3ub(23, 109, 150);
glVertex2f(-0.79, -0.52);
glVertex2f(-0.79, -0.53);
glVertex2f(-0.67, -0.53);
glVertex2f(-0.67, -0.52);
glEnd();


glBegin(GL_QUADS);//crane shadow
glColor3ub(23, 109, 150);
glVertex2f(-0.77, -0.44);
glVertex2f(-0.77, -0.445);
glVertex2f(-0.67, -0.485);
glVertex2f(-0.67, -0.48);
glEnd();

glBegin(GL_QUADS);//crane shadow
glColor3ub(23, 109, 150);
glVertex2f(-0.77, -0.48);
glVertex2f(-0.77, -0.485);
glVertex2f(-0.67, -0.455);
glVertex2f(-0.67, -0.45);
glEnd();

glBegin(GL_QUADS);//crane shadow
glColor3ub(23, 109, 150);
glVertex2f(-0.64, -0.38);
glVertex2f(-0.64, -0.44);
glVertex2f(-0.55, -0.44);
glVertex2f(-0.55, -0.38);
glEnd();

glBegin(GL_QUADS);//crane shadow
glColor3ub(23, 109, 150);
glVertex2f(-0.55, -0.38);
glVertex2f(-0.55, -0.47);
glVertex2f(-0.46, -0.47);
glVertex2f(-0.46, -0.38);
glEnd();

glBegin(GL_QUADS);//crane shadow
glColor3ub(23, 109, 150);
glVertex2f(-0.46, -0.38);
glVertex2f(-0.46, -0.44);
glVertex2f(-0.38, -0.44);
glVertex2f(-0.38, -0.38);
glEnd();


//Ship Front START
glBegin(GL_QUADS);//steel behind railing
glColor3ub(170, 171, 166);
glVertex2f(-0.32, -0.47);
glVertex2f(-0.32, -0.49);
glVertex2f(0.08, -0.49);
glVertex2f(0.08, -0.47);
glEnd();

//ship cargo start

glBegin(GL_QUADS);//down row left to right
glColor3ub(136, 83, 173);
glVertex2f(-0.34, -0.4);
glVertex2f(-0.34, -0.47);
glVertex2f(-0.25, -0.47);
glVertex2f(-0.25, -0.4);
glEnd();

glBegin(GL_QUADS);//down raw left to right
glColor3ub(52, 182, 86);
glVertex2f(-0.25, -0.4);
glVertex2f(-0.16, -0.4);
glVertex2f(-0.16, -0.47);
glVertex2f(-0.25, -0.47);
glEnd();

glBegin(GL_QUADS);//down raw left to right
glColor3ub(185, 105, 44);
glVertex2f(-0.16, -0.4);
glVertex2f(-0.07, -0.4);
glVertex2f(-0.07, -0.47);
glVertex2f(-0.16, -0.47);
glEnd();

glBegin(GL_QUADS);//down raw left to right
glColor3ub(220, 75, 158);
glVertex2f(-0.07, -0.4);
glVertex2f(0.01, -0.4);
glVertex2f(0.01, -0.47);
glVertex2f(-0.07, -0.47);
glEnd();

glBegin(GL_QUADS);//down raw left to right
glColor3ub(234, 218, 52);
glVertex2f(0.01, -0.4);
glVertex2f(0.1, -0.4);
glVertex2f(0.1, -0.47);
glVertex2f(0.01, -0.47);
glEnd();

glBegin(GL_QUADS);//down raw left to right
glColor3ub(50, 202, 94);
glVertex2f(0.1, -0.4);
glVertex2f(0.19, -0.4);
glVertex2f(0.19, -0.47);
glVertex2f(0.1, -0.47);
glEnd();

glBegin(GL_QUADS);//middle raw left to right
glColor3ub(82, 217, 214);
glVertex2f(-0.34, -0.34);
glVertex2f(-0.25, -0.34);
glVertex2f(-0.25, -0.4);
glVertex2f(-0.34, -0.4);
glEnd();

glBegin(GL_QUADS);//middle raw left to right
glColor3ub(215, 209, 63);
glVertex2f(-0.25, -0.34);
glVertex2f(-0.16, -0.34);
glVertex2f(-0.16, -0.4);
glVertex2f(-0.25, -0.4);
glEnd();

glBegin(GL_QUADS);//middle raw left to right
glColor3ub(182, 48, 52);
glVertex2f(-0.16, -0.34);
glVertex2f(-0.07, -0.34);
glVertex2f(-0.07, -0.4);
glVertex2f(-0.16, -0.4);
glEnd();

glBegin(GL_QUADS);//middle raw left to right
glColor3ub(75, 104, 148);
glVertex2f(-0.07, -0.34);
glVertex2f(0.01, -0.34);
glVertex2f(0.01, -0.4);
glVertex2f(-0.07, -0.4);
glEnd();

glBegin(GL_QUADS);//middle raw left to right
glColor3ub(198, 35, 38);
glVertex2f(0.01, -0.34);
glVertex2f(0.1, -0.34);
glVertex2f(0.1, -0.4);
glVertex2f(0.01, -0.4);
glEnd();

glBegin(GL_QUADS);//middle raw left to right
glColor3ub(206, 196, 30);
glVertex2f(0.1, -0.34);
glVertex2f(0.19, -0.34);
glVertex2f(0.19, -0.4);
glVertex2f(0.1, -0.4);
glEnd();

glBegin(GL_QUADS);//middle raw left to right
glColor3ub(29, 33, 168);
glVertex2f(-0.34, -0.27);
glVertex2f(-0.25, -0.27);
glVertex2f(-0.25, -0.34);
glVertex2f(-0.34, -0.34);
glEnd();

glBegin(GL_QUADS);//middle raw left to right
glColor3ub(29, 169, 161);
glVertex2f(-0.25, -0.27);
glVertex2f(-0.16, -0.27);
glVertex2f(-0.16, -0.34);
glVertex2f(-0.25, -0.34);
glEnd();

glBegin(GL_QUADS);//middle row left to right
glColor3ub(154, 100, 188);
glVertex2f(-0.16, -0.27);
glVertex2f(-0.07, -0.27);
glVertex2f(-0.07, -0.34);
glVertex2f(-0.16, -0.34);
glEnd();

glBegin(GL_QUADS);//middle row left to right
glColor3ub(211, 160, 69);
glVertex2f(-0.07, -0.27);
glVertex2f(0.01, -0.27);
glVertex2f(0.01, -0.34);
glVertex2f(-0.07, -0.34);
glEnd();

glBegin(GL_QUADS);//middle row left to right
glColor3ub(132, 91, 158);
glVertex2f(0.01, -0.27);
glVertex2f(0.1, -0.27);
glVertex2f(0.1, -0.34);
glVertex2f(0.01, -0.34);
glEnd();

glBegin(GL_QUADS);//middle row left to right
glColor3ub(40, 45, 176);
glVertex2f(0.19, -0.27);
glVertex2f(0.28, -0.27);
glVertex2f(0.28, -0.34);
glVertex2f(0.19, -0.34);
glEnd();

glBegin(GL_QUADS);//middle row left to right
glColor3ub(155, 163, 94);
glVertex2f(0.1, -0.27);
glVertex2f(0.19, -0.27);
glVertex2f(0.19, -0.34);
glVertex2f(0.1, -0.34);
glEnd();

glBegin(GL_LINES);//down row left
glColor3ub(64, 64, 64);
glVertex2f(-0.34, -0.4);//1
glVertex2f(-0.34, -0.47);
glVertex2f(-0.34, -0.47);
glVertex2f(-0.25, -0.47);
glVertex2f(-0.25, -0.47);
glVertex2f(-0.25, -0.4);
glVertex2f(-0.25, -0.4);
glVertex2f(-0.34, -0.4);

glVertex2f(-0.25, -0.4);//2
glVertex2f(-0.16, -0.4);
glVertex2f(-0.16, -0.4);
glVertex2f(-0.16, -0.47);
glVertex2f(-0.16, -0.47);
glVertex2f(-0.25, -0.47);
glVertex2f(-0.25, -0.47);
glVertex2f(-0.25, -0.4);

glVertex2f(-0.16, -0.4);//3
glVertex2f(-0.07, -0.4);
glVertex2f(-0.07, -0.4);
glVertex2f(-0.07, -0.47);
glVertex2f(-0.07, -0.47);
glVertex2f(-0.16, -0.47);
glVertex2f(-0.16, -0.47);
glVertex2f(-0.16, -0.4);

glVertex2f(-0.07, -0.4);//4
glVertex2f(0.01, -0.4);
glVertex2f(0.01, -0.4);
glVertex2f(0.01, -0.47);
glVertex2f(0.01, -0.47);
glVertex2f(-0.07, -0.47);
glVertex2f(-0.07, -0.47);
glVertex2f(-0.07, -0.4);

glVertex2f(0.01, -0.4);//5
glVertex2f(0.1, -0.4);
glVertex2f(0.1, -0.4);
glVertex2f(0.1, -0.47);
glVertex2f(0.1, -0.47);
glVertex2f(0.01, -0.47);
glVertex2f(0.01, -0.47);
glVertex2f(0.01, -0.4);

glVertex2f(0.1, -0.4);//6
glVertex2f(0.19, -0.4);
glVertex2f(0.19, -0.4);
glVertex2f(0.19, -0.47);
glVertex2f(0.19, -0.47);
glVertex2f(0.1, -0.47);
glVertex2f(0.1, -0.47);
glVertex2f(0.1, -0.4);

glVertex2f(-0.34, -0.34);//7
glVertex2f(-0.25, -0.34);
glVertex2f(-0.25, -0.34);
glVertex2f(-0.25, -0.4);
glVertex2f(-0.25, -0.4);
glVertex2f(-0.34, -0.4);
glVertex2f(-0.34, -0.4);
glVertex2f(-0.34, -0.34);

glVertex2f(-0.25, -0.34);//8
glVertex2f(-0.16, -0.34);
glVertex2f(-0.16, -0.34);
glVertex2f(-0.16, -0.4);
glVertex2f(-0.16, -0.4);
glVertex2f(-0.25, -0.4);
glVertex2f(-0.25, -0.4);
glVertex2f(-0.25, -0.34);

glVertex2f(-0.16, -0.34);//7
glVertex2f(-0.07, -0.34);
glVertex2f(-0.07, -0.34);
glVertex2f(-0.07, -0.4);
glVertex2f(-0.07, -0.4);
glVertex2f(-0.16, -0.4);
glVertex2f(-0.16, -0.4);
glVertex2f(-0.16, -0.34);

glVertex2f(-0.07, -0.34);//8
glVertex2f(0.01, -0.34);
glVertex2f(0.01, -0.34);
glVertex2f(0.01, -0.4);
glVertex2f(0.01, -0.4);
glVertex2f(-0.07, -0.4);
glVertex2f(-0.07, -0.4);
glVertex2f(-0.07, -0.34);

glVertex2f(0.01, -0.34);//9
glVertex2f(0.1, -0.34);
glVertex2f(0.1, -0.34);
glVertex2f(0.1, -0.4);
glVertex2f(0.1, -0.4);
glVertex2f(0.01, -0.4);
glVertex2f(0.01, -0.4);
glVertex2f(0.01, -0.34);

glVertex2f(0.1, -0.34);//10
glVertex2f(0.19, -0.34);
glVertex2f(0.19, -0.34);
glVertex2f(0.19, -0.4);
glVertex2f(0.19, -0.4);
glVertex2f(0.1, -0.4);
glVertex2f(0.1, -0.4);
glVertex2f(0.1, -0.34);

glVertex2f(-0.34, -0.27);//11
glVertex2f(-0.25, -0.27);
glVertex2f(-0.25, -0.27);
glVertex2f(-0.25, -0.34);
glVertex2f(-0.25, -0.34);
glVertex2f(-0.34, -0.34);
glVertex2f(-0.34, -0.34);
glVertex2f(-0.34, -0.27);

glVertex2f(-0.25, -0.27);//12
glVertex2f(-0.16, -0.27);
glVertex2f(-0.16, -0.27);
glVertex2f(-0.16, -0.34);
glVertex2f(-0.16, -0.34);
glVertex2f(-0.25, -0.34);
glVertex2f(-0.25, -0.34);
glVertex2f(-0.25, -0.27);

glVertex2f(-0.16, -0.27);//13
glVertex2f(-0.07, -0.27);
glVertex2f(-0.07, -0.27);
glVertex2f(-0.07, -0.34);
glVertex2f(-0.07, -0.34);
glVertex2f(-0.16, -0.34);
glVertex2f(-0.16, -0.34);
glVertex2f(-0.16, -0.27);

glVertex2f(-0.07, -0.27);//14
glVertex2f(0.01, -0.27);
glVertex2f(0.01, -0.27);
glVertex2f(0.01, -0.34);
glVertex2f(0.01, -0.34);
glVertex2f(-0.07, -0.34);
glVertex2f(-0.07, -0.34);
glVertex2f(-0.07, -0.27);

glVertex2f(0.01, -0.27);//15
glVertex2f(0.1, -0.27);
glVertex2f(0.1, -0.27);
glVertex2f(0.1, -0.34);
glVertex2f(0.1, -0.34);
glVertex2f(0.01, -0.34);
glVertex2f(0.01, -0.34);
glVertex2f(0.01, -0.27);

glVertex2f(0.19, -0.27);//16
glVertex2f(0.28, -0.27);
glVertex2f(0.28, -0.27);
glVertex2f(0.28, -0.34);
glVertex2f(0.28, -0.34);
glVertex2f(0.19, -0.34);
glVertex2f(0.19, -0.34);
glVertex2f(0.19, -0.27);


glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.335, -0.44);
glVertex2f(-0.33, -0.445);
glVertex2f(-0.33, -0.465);
glVertex2f(-0.335, -0.465);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.335, -0.44);
glVertex2f(-0.33, -0.445);
glVertex2f(0.095, -0.445);
glVertex2f(0.1, -0.44);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(0.07, -0.445);
glVertex2f(0.07, -0.48);
glVertex2f(0.075, -0.48);
glVertex2f(0.075, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(0.035, -0.445);
glVertex2f(0.035, -0.48);
glVertex2f(0.04, -0.48);
glVertex2f(0.04, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(0.005, -0.445);
glVertex2f(0.005, -0.48);
glVertex2f(0.01, -0.48);
glVertex2f(0.01, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.025, -0.445);
glVertex2f(-0.025, -0.48);
glVertex2f(-0.02, -0.48);
glVertex2f(-0.02, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.055, -0.445);
glVertex2f(-0.055, -0.48);
glVertex2f(-0.05, -0.48);
glVertex2f(-0.05, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.085, -0.445);
glVertex2f(-0.085, -0.48);
glVertex2f(-0.08, -0.48);
glVertex2f(-0.08, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.115, -0.445);
glVertex2f(-0.115, -0.48);
glVertex2f(-0.11, -0.48);
glVertex2f(-0.11, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.145, -0.445);
glVertex2f(-0.145, -0.48);
glVertex2f(-0.14, -0.48);
glVertex2f(-0.14, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.18, -0.445);
glVertex2f(-0.18, -0.48);
glVertex2f(-0.175, -0.48);
glVertex2f(-0.175, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.21, -0.445);
glVertex2f(-0.21, -0.48);
glVertex2f(-0.205, -0.48);
glVertex2f(-0.205, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.24, -0.445);
glVertex2f(-0.24, -0.48);
glVertex2f(-0.235, -0.48);
glVertex2f(-0.235, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.27, -0.445);
glVertex2f(-0.27, -0.48);
glVertex2f(-0.265, -0.48);
glVertex2f(-0.265, -0.445);
glEnd();

glBegin(GL_QUADS);//railing
glColor3ub(255, 255, 255);
glVertex2f(-0.305, -0.445);
glVertex2f(-0.305, -0.48);
glVertex2f(-0.3, -0.48);
glVertex2f(-0.3, -0.445);
glEnd();

glBegin(GL_QUADS);//cabin left
glColor3ub(211, 211, 207);
glVertex2f(-0.46, -0.27);
glVertex2f(-0.46, -0.46);
glVertex2f(-0.38, -0.46);
glVertex2f(-0.38, -0.27);
glEnd();

glBegin(GL_QUADS);//cabin middle
glColor3ub(204, 204, 204);
glVertex2f(-0.5, -0.27);
glVertex2f(-0.5, -0.46);
glVertex2f(-0.46, -0.46);
glVertex2f(-0.46, -0.27);
glEnd();

glBegin(GL_QUADS);//cabin right
glColor3ub(198, 198, 198);
glVertex2f(-0.58, -0.27);
glVertex2f(-0.58, -0.46);
glVertex2f(-0.5, -0.46);
glVertex2f(-0.5, -0.27);
glEnd();


glBegin(GL_QUADS);//cabin glass left
glColor3ub(77, 175, 231);
glVertex2f(-0.46, -0.246);
glVertex2f(-0.46, -0.27);
glVertex2f(-0.386, -0.27);
glVertex2f(-0.386, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin glass middle
glColor3ub(73, 158, 202);
glVertex2f(-0.5, -0.246);
glVertex2f(-0.5, -0.27);
glVertex2f(-0.46, -0.27);
glVertex2f(-0.46, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin glass right
glColor3ub(37, 145, 198);
glVertex2f(-0.572, -0.246);
glVertex2f(-0.572, -0.27);
glVertex2f(-0.5, -0.27);
glVertex2f(-0.5, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin glass railing left
glColor3ub(150, 150, 150);
glVertex2f(-0.556, -0.246);
glVertex2f(-0.556, -0.27);
glVertex2f(-0.554, -0.27);
glVertex2f(-0.554, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin glass railing left
glColor3ub(150, 150, 150);
glVertex2f(-0.536, -0.246);
glVertex2f(-0.536, -0.27);
glVertex2f(-0.534, -0.27);
glVertex2f(-0.534, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin glass railing middle
glColor3ub(160, 160, 154);
glVertex2f(-0.494, -0.246);
glVertex2f(-0.494, -0.27);
glVertex2f(-0.492, -0.27);
glVertex2f(-0.492, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin glass railing middle
glColor3ub(160, 160, 154);
glVertex2f(-0.468, -0.246);
glVertex2f(-0.468, -0.27);
glVertex2f(-0.466, -0.27);
glVertex2f(-0.466, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin glass railing right
glColor3ub(182, 181, 188);
glVertex2f(-0.424, -0.246);
glVertex2f(-0.424, -0.27);
glVertex2f(-0.422, -0.27);
glVertex2f(-0.422, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin glass railing right
glColor3ub(182, 181, 188);
glVertex2f(-0.404, -0.246);
glVertex2f(-0.404, -0.27);
glVertex2f(-0.402, -0.27);
glVertex2f(-0.402, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin left
glColor3ub(211, 211, 207);
glVertex2f(-0.46, -0.2);
glVertex2f(-0.365, -0.2);
glVertex2f(-0.372, -0.246);
glVertex2f(-0.46, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin middle
glColor3ub(204, 204, 204);
glVertex2f(-0.5, -0.2);
glVertex2f(-0.46, -0.2);
glVertex2f(-0.46, -0.246);
glVertex2f(-0.5, -0.246);
glEnd();

glBegin(GL_QUADS);//cabin right
glColor3ub(198, 198, 198);
glVertex2f(-0.59, -0.2);
glVertex2f(-0.582, -0.246);
glVertex2f(-0.5, -0.246);
glVertex2f(-0.5, -0.2);
glEnd();


glBegin(GL_QUADS);//cabin middle left
glColor3ub(174, 172, 174);
glVertex2f(-0.46, -0.165);
glVertex2f(-0.405, -0.165);
glVertex2f(-0.405, -0.2);
glVertex2f(-0.46, -0.2);
glEnd();

glBegin(GL_QUADS);//cabin middle middle
glColor3ub(142, 144, 145);
glVertex2f(-0.5, -0.165);
glVertex2f(-0.46, -0.165);
glVertex2f(-0.46, -0.2);
glVertex2f(-0.5, -0.2);
glEnd();

glBegin(GL_QUADS);//cabin middle  right
glColor3ub(127, 129, 130);
glVertex2f(-0.55, -0.165);
glVertex2f(-0.5, -0.165);
glVertex2f(-0.5, -0.2);
glVertex2f(-0.55, -0.2);
glEnd();


glBegin(GL_QUADS);//cabin middle top left
glColor3ub(185, 180, 181);
glVertex2f(-0.46, -0.095);
glVertex2f(-0.388, -0.095);
glVertex2f(-0.402, -0.165);
glVertex2f(-0.46, -0.165);
glEnd();

glBegin(GL_QUADS);//cabin middle top middle
glColor3ub(163, 163, 161);
glVertex2f(-0.5, -0.095);
glVertex2f(-0.46, -0.095);
glVertex2f(-0.46, -0.165);
glVertex2f(-0.5, -0.165);
glEnd();

glBegin(GL_QUADS);//cabin middle top  right
glColor3ub(153, 151, 149);
glVertex2f(-0.565, -0.095);
glVertex2f(-0.5, -0.095);
glVertex2f(-0.5, -0.165);
glVertex2f(-0.555, -0.165);
glEnd();

glBegin(GL_QUADS);//cabin middle top top left
glColor3ub(188, 184, 185);
glVertex2f(-0.46, -0.08);
glVertex2f(-0.46, -0.095);
glVertex2f(-0.384, -0.095);
glVertex2f(-0.39, -0.08);
glEnd();

glBegin(GL_QUADS);//cabin middle top top middle
glColor3ub(163, 163, 161);
glVertex2f(-0.5, -0.08);
glVertex2f(-0.46, -0.08);
glVertex2f(-0.46, -0.095);
glVertex2f(-0.5, -0.095);
glEnd();

glBegin(GL_QUADS);//cabin middle top top  right
glColor3ub(153, 151, 149);
glVertex2f(-0.565, -0.08);
glVertex2f(-0.5, -0.08);
glVertex2f(-0.5, -0.095);
glVertex2f(-0.57, -0.095);
glEnd();

glBegin(GL_LINES);//cabin middle top top  right
glColor3ub(124, 121, 119);
glVertex2f(-0.565, -0.08);
glVertex2f(-0.39, -0.08);
glVertex2f(-0.39, -0.08);
glVertex2f(-0.384, -0.095);
glVertex2f(-0.384, -0.095);
glVertex2f(-0.57, -0.095);
glVertex2f(-0.57, -0.095);
glVertex2f(-0.565, -0.08);
glEnd();

glBegin(GL_QUADS);//cabin middle top top left
glColor3ub(183, 183, 183);
glVertex2f(-0.46, -0.055);
glVertex2f(-0.395, -0.055);
glVertex2f(-0.39, -0.08);
glVertex2f(-0.46, -0.08);
glEnd();

glBegin(GL_QUADS);//cabin middle top top middle
glColor3ub(163, 161, 161);
glVertex2f(-0.5, -0.055);
glVertex2f(-0.46, -0.055);
glVertex2f(-0.46, -0.08);
glVertex2f(-0.5, -0.08);
glEnd();

glBegin(GL_QUADS);//cabin middle top top  right
glColor3ub(155, 155, 152);
glVertex2f(-0.56, -0.055);
glVertex2f(-0.565, -0.08);
glVertex2f(-0.5, -0.08);
glVertex2f(-0.5, -0.055);
glEnd();

glBegin(GL_LINES);//cabin middle top top  right
glColor3ub(124, 121, 119);
glVertex2f(-0.565, -0.08);
glVertex2f(-0.39, -0.08);
glVertex2f(-0.39, -0.08);
glVertex2f(-0.384, -0.095);
glVertex2f(-0.384, -0.095);
glVertex2f(-0.57, -0.095);
glVertex2f(-0.57, -0.095);
glVertex2f(-0.565, -0.08);
glEnd();


glBegin(GL_QUADS);//cabin middle glass left
glColor3ub(77, 175, 231);
glVertex2f(-0.46, -0.1);
glVertex2f(-0.44, -0.1);
glVertex2f(-0.45, -0.16);
glVertex2f(-0.46, -0.16);
glEnd();
glBegin(GL_QUADS);//cabin middle glass left
glColor3ub(77, 175, 231);
glVertex2f(-0.435, -0.1);
glVertex2f(-0.395, -0.1);
glVertex2f(-0.408, -0.16);
glVertex2f(-0.445, -0.16);
glEnd();

glBegin(GL_QUADS);//cabin middle glass middle
glColor3ub(73, 158, 202);
glVertex2f(-0.5, -0.1);
glVertex2f(-0.46, -0.1);
glVertex2f(-0.46, -0.16);
glVertex2f(-0.5, -0.16);
glEnd();

glBegin(GL_QUADS);//cabin middle glass right
glColor3ub(37, 145, 198);
glVertex2f(-0.56, -0.1);
glVertex2f(-0.52, -0.1);
glVertex2f(-0.51, -0.16);
glVertex2f(-0.55, -0.16);
glEnd();
glBegin(GL_QUADS);//cabin middle glass right
glColor3ub(37, 145, 198);
glVertex2f(-0.515, -0.1);
glVertex2f(-0.5, -0.1);
glVertex2f(-0.5, -0.16);
glVertex2f(-0.505, -0.16);
glEnd();


glBegin(GL_LINES);//cabin railing right
glColor3ub(198, 198, 198);
glVertex2f(-0.59, -0.175);
glVertex2f(-0.5, -0.175);
glVertex2f(-0.5, -0.175);
glVertex2f(-0.5, -0.2);
glVertex2f(-0.5, -0.2);
glVertex2f(-0.59, -0.2);
glVertex2f(-0.59, -0.2);
glVertex2f(-0.59, -0.175);

glVertex2f(-0.58, -0.175);
glVertex2f(-0.58, -0.2);
glVertex2f(-0.56, -0.175);
glVertex2f(-0.56, -0.2);
glVertex2f(-0.54, -0.175);
glVertex2f(-0.54, -0.2);
glVertex2f(-0.52, -0.175);
glVertex2f(-0.52, -0.2);

glBegin(GL_LINES);//cabin railing middle
glColor3ub(204, 204, 204);
glVertex2f(-0.5, -0.175);
glVertex2f(-0.46, -0.175);
glVertex2f(-0.46, -0.175);
glVertex2f(-0.46, -0.2);
glVertex2f(-0.46, -0.2);
glVertex2f(-0.5, -0.2);
glVertex2f(-0.5, -0.2);
glVertex2f(-0.5, -0.175);
glVertex2f(-0.48, -0.175);
glVertex2f(-0.48, -0.2);
glEnd();

glBegin(GL_LINES);//cabin left
glColor3ub(211, 211, 207);
glVertex2f(-0.46, -0.175);
glVertex2f(-0.365, -0.175);
glVertex2f(-0.365, -0.175);
glVertex2f(-0.365, -0.2);
glVertex2f(-0.365, -0.2);
glVertex2f(-0.46, -0.2);
glVertex2f(-0.46, -0.2);
glVertex2f(-0.46, -0.175);

glVertex2f(-0.44, -0.175);
glVertex2f(-0.44, -0.2);
glVertex2f(-0.42, -0.175);
glVertex2f(-0.42, -0.2);
glVertex2f(-0.4, -0.175);
glVertex2f(-0.4, -0.2);
glVertex2f(-0.38, -0.175);
glVertex2f(-0.38, -0.2);
glEnd();

glBegin(GL_QUADS);//pole
glColor3ub(255, 255, 255);
glVertex2f(-0.54, 0.04);
glVertex2f(-0.535, 0.04);
glVertex2f(-0.535, -0.055);
glVertex2f(-0.54, -0.055);
glEnd();

glBegin(GL_QUADS);//pole red line
glColor3ub(216, 54, 45);
glVertex2f(-0.54, 0.025);
glVertex2f(-0.535, 0.025);
glVertex2f(-0.535, 0.01);
glVertex2f(-0.54, 0.01);
glEnd();

glBegin(GL_QUADS);//pole red line
glColor3ub(216, 54, 45);
glVertex2f(-0.54, -0.005);
glVertex2f(-0.535, -0.005);
glVertex2f(-0.535, -0.02);
glVertex2f(-0.54, -0.02);
glEnd();

glBegin(GL_QUADS);//pole
glColor3ub(255, 255, 255);
glVertex2f(-0.525, 0.005);
glVertex2f(-0.52, 0.005);
glVertex2f(-0.52, -0.055);
glVertex2f(-0.525, -0.055);
glEnd();

glBegin(GL_QUADS);//pole red line
glColor3ub(216, 54, 45);
glVertex2f(-0.525, -0.005);
glVertex2f(-0.52, -0.005);
glVertex2f(-0.52, -0.02);
glVertex2f(-0.525, -0.02);
glEnd();

glBegin(GL_QUADS);//pole red line
glColor3ub(216, 54, 45);
glVertex2f(-0.525, -0.035);
glVertex2f(-0.52, -0.035);
glVertex2f(-0.52, -0.05);
glVertex2f(-0.525, -0.05);
glEnd();

glBegin(GL_QUADS);//pole
glColor3ub(255, 255, 255);
glVertex2f(-0.415, 0.005);
glVertex2f(-0.41, 0.005);
glVertex2f(-0.41, -0.055);
glVertex2f(-0.415, -0.055);
glEnd();

glBegin(GL_QUADS);//pole red line
glColor3ub(216, 54, 45);
glVertex2f(-0.415, -0.005);
glVertex2f(-0.41, -0.005);
glVertex2f(-0.41, -0.015);
glVertex2f(-0.415, -0.015);
glEnd();
glBegin(GL_QUADS);//pole red line
glColor3ub(216, 54, 45);
glVertex2f(-0.415, -0.025);
glVertex2f(-0.41, -0.025);
glVertex2f(-0.41, -0.035);
glVertex2f(-0.415, -0.035);
glEnd();

glBegin(GL_QUADS);//pole
glColor3ub(155, 157, 151);
glVertex2f(-0.48, 0.07);
glVertex2f(-0.475, 0.07);
glVertex2f(-0.475, -0.055);
glVertex2f(-0.48, -0.055);
glEnd();

glBegin(GL_QUADS);//pole
glColor3ub(147, 147, 144);
glVertex2f(-0.48, 0.07);
glVertex2f(-0.475, 0.07);
glVertex2f(-0.475, 0.07);
glVertex2f(-0.475, -0.055);
glVertex2f(-0.475, -0.055);
glVertex2f(-0.48, -0.055);
glVertex2f(-0.48, -0.055);
glVertex2f(-0.48, 0.07);

glEnd();

glBegin(GL_POLYGON);//flag
glColor3ub(27, 138, 57);
glVertex2f(-0.48, 0.065);
glVertex2f(-0.486, -0.011);
glVertex2f(-0.482, -0.002);
glVertex2f(-0.481, -0.008);
glVertex2f(-0.478, -0.002);
glVertex2f(-0.479, 0.049);
glEnd();

glBegin(GL_LINES);//flag
glColor3ub(23, 119, 49);
glVertex2f(-0.48, 0.065);
glVertex2f(-0.486, -0.011);
glVertex2f(-0.486, -0.011);
glVertex2f(-0.482, -0.002);
glVertex2f(-0.482, -0.002);
glVertex2f(-0.481, -0.008);
glVertex2f(-0.481, -0.008);
glVertex2f(-0.478, -0.002);
glVertex2f(-0.478, -0.002);
glVertex2f(-0.479, 0.049);
glVertex2f(-0.479, 0.049);
glVertex2f(-0.48, 0.065);
glEnd();

glBegin(GL_POLYGON);//flag circle
glColor3ub(214, 32, 38);
glVertex2f(-0.481, 0.036);
glVertex2f(-0.482, 0.014);
glVertex2f(-0.48, 0.018);
glVertex2f(-0.479, 0.015);
glVertex2f(-0.4805, 0.033);
glEnd();


	   GLfloat x4=-.52f; GLfloat y4=-.35f; GLfloat radius4 =0.012f;
	int triangleAmount4 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi4 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(37, 145, 198); //left window
		glVertex2f(x4, y4); // center of circle
		for(i = 0; i <= triangleAmount4;i++) {
			glVertex2f(
		            x4 + (radius4 * cos(i *  twicePi4 / triangleAmount4)),
			    y4 + (radius4 * sin(i * twicePi4 / triangleAmount4))
			);
		}
	glEnd();


		   GLfloat x5=-.52f; GLfloat y5=-.39f; GLfloat radius5 =0.012f;
	int triangleAmount5 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi5 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(37, 145, 198); // left window
		glVertex2f(x5, y5); // center of circle
		for(i = 0; i <= triangleAmount5;i++) {
			glVertex2f(
		            x5 + (radius5* cos(i *  twicePi5 / triangleAmount5)),
			    y5 + (radius5* sin(i * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


	GLfloat x6=-.48f; GLfloat y6=-.35f; GLfloat radius6 =0.012f;
	int triangleAmount6 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi6 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(73, 158, 202); // middle window
		glVertex2f(x6, y6); // center of circle
		for(i = 0; i <= triangleAmount6;i++) {
			glVertex2f(
		            x6 + (radius6* cos(i *  twicePi6 / triangleAmount6)),
			    y6 + (radius6* sin(i * twicePi6 / triangleAmount6))
			);
		}
	glEnd();


	GLfloat x7=-.48f; GLfloat y7=-.39f; GLfloat radius7 =0.012f;
	int triangleAmount7 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi7 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(73, 158, 202); // middle window
		glVertex2f(x7, y7); // center of circle
		for(i = 0; i <= triangleAmount7;i++) {
			glVertex2f(
		            x7 + (radius7* cos(i *  twicePi7 / triangleAmount7)),
			    y7 + (radius7* sin(i * twicePi7 / triangleAmount7))
			);
		}
	glEnd();


	GLfloat x8=-.48f; GLfloat y8=-.43f; GLfloat radius8 =0.012f;
	int triangleAmount8 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi8 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(73, 158, 202); // middle window
		glVertex2f(x8, y8); // center of circle
		for(i = 0; i <= triangleAmount8;i++) {
			glVertex2f(
		            x8 + (radius8* cos(i *  twicePi8 / triangleAmount8)),
			    y8 + (radius8* sin(i * twicePi8 / triangleAmount8))
			);
		}
	glEnd();


GLfloat x9=-0.44f; GLfloat y9=-0.35f; GLfloat radius9 =0.012f;
	int triangleAmount9 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi9 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 175, 231);
		glVertex2f(x9, y9); // center of circle
		for(i = 0; i <= triangleAmount9;i++) {
			glVertex2f(
		            x9 + (radius9 * cos(i *  twicePi9 / triangleAmount9)),
			    y9 + (radius9 * sin(i * twicePi9 / triangleAmount9))
			);
		}
	glEnd();


		GLfloat x10=-0.44f; GLfloat y10=-0.39f; GLfloat radius10 =0.012f;
	int triangleAmount10 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi10 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 175, 231);
		glVertex2f(x10, y10); // center of circle
		for(i = 0; i <= triangleAmount10;i++) {
			glVertex2f(
		            x10 + (radius10 * cos(i *  twicePi10 / triangleAmount10)),
			    y10 + (radius10 * sin(i * twicePi10 / triangleAmount10))
			);
		}
	glEnd();


	GLfloat x11=-0.44f; GLfloat y11=-0.43f; GLfloat radius11 =0.012f;
	int triangleAmount11 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi11 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 175, 231);
		glVertex2f(x11, y11); // center of circle
		for(i = 0; i <= triangleAmount11;i++) {
			glVertex2f(
		            x11 + (radius11 * cos(i *  twicePi11 / triangleAmount11)),
			    y11 + (radius11 * sin(i * twicePi11 / triangleAmount11))
			);
		}
	glEnd();


	GLfloat x12=-0.4f; GLfloat y12=-0.35f; GLfloat radius12 =0.012f;
	int triangleAmount12 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi12 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 175, 231);
		glVertex2f(x12, y12); // center of circle
		for(i = 0; i <= triangleAmount12;i++) {
			glVertex2f(
		            x12 + (radius12* cos(i *  twicePi12 / triangleAmount12)),
			    y12 + (radius12 * sin(i * twicePi12 / triangleAmount12))
			);
		}
	glEnd();

	GLfloat x13=-0.4f; GLfloat y13=-0.39f; GLfloat radius13 =0.012f;
	int triangleAmount13 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi13 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 175, 231);
		glVertex2f(x13, y13); // center of circle
		for(i = 0; i <= triangleAmount13;i++) {
			glVertex2f(
		            x13 + (radius13* cos(i *  twicePi13 / triangleAmount13)),
			    y13 + (radius13 * sin(i * twicePi13 / triangleAmount13))
			);
		}
	glEnd();

	GLfloat x14=-0.4f; GLfloat y14=-0.43f; GLfloat radius14 =0.012f;
	int triangleAmount14 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi14 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 175, 231);
		glVertex2f(x14, y14); // center of circle
		for(i = 0; i <= triangleAmount14;i++) {
			glVertex2f(
		            x14 + (radius14* cos(i *  twicePi14 / triangleAmount14)),
			    y14 + (radius14 * sin(i * twicePi14 / triangleAmount14))
			);
		}
	glEnd();


glBegin(GL_POLYGON);//hull red
glColor3ub(164, 41, 45);
glVertex2f(-0.66, -0.325);
glVertex2f(-0.659, -0.345);
glVertex2f(-0.656, -0.37);
glVertex2f(-0.534, -0.37);
glVertex2f(-0.54, -0.345);
glVertex2f(-0.54, -0.325);
glEnd();

glBegin(GL_POLYGON);//hull red
glColor3ub(164, 41, 45);
glVertex2f(0.128, -0.328);
glVertex2f(0.126, -0.358);
glVertex2f(0.124, -0.37);
glVertex2f(0.422, -0.37);
glVertex2f(0.432, -0.34);
glVertex2f(0.434, -0.328);
glEnd();

glBegin(GL_QUADS);//hull white top
glColor3ub(252, 250, 253);
glVertex2f(-0.656, -0.37);
glVertex2f(-0.534, -0.37);
glVertex2f(-0.531, -0.382);
glVertex2f(-0.654, -0.382);
glEnd();

glBegin(GL_QUADS);//hull white top
glColor3ub(252, 250, 253);
glVertex2f(0.124, -0.37);
glVertex2f(0.122, -0.382);
glVertex2f(0.418, -0.382);
glVertex2f(0.422, -0.37);
glEnd();

glBegin(GL_POLYGON);//hull mid black
glColor3ub(88, 85, 80);
glVertex2f(-0.654, -0.382);
glVertex2f(-0.64, -0.41);
glVertex2f(-0.61, -0.45);
glVertex2f(-0.59, -0.47);
glVertex2f(-0.57, -0.5);
glVertex2f(-0.57, -0.382);
glEnd();

glBegin(GL_POLYGON);//hull mid black
glColor3ub(88, 85, 80);
glVertex2f(-0.57, -0.382);
glVertex2f(-0.57, -0.5);
glVertex2f(-0.56, -0.52);
glVertex2f(-0.5, -0.52);
glVertex2f(-0.46, -0.455);
glVertex2f(-0.495, -0.44);
glVertex2f(-0.52, -0.41);
glVertex2f(-0.531, -0.382);
glEnd();

glBegin(GL_TRIANGLES);//hull mid black
glColor3ub(88, 85, 80);
glVertex2f(-0.46, -0.455);
glVertex2f(-0.5, -0.52);
glVertex2f(-0.46, -0.52);
glEnd();

glBegin(GL_QUADS);//hull mid black
glColor3ub(88, 85, 80);
glVertex2f(-0.46, -0.455);
glVertex2f(-0.32, -0.455);
glVertex2f(-0.32, -0.52);
glVertex2f(-0.46, -0.52);
glEnd();

glBegin(GL_QUADS);//hull mid black
glColor3ub(88, 85, 80);
glVertex2f(-0.32, -0.48);
glVertex2f(0.06, -0.48);
glVertex2f(0.06, -0.52);
glVertex2f(-0.32, -0.52);
glEnd();


glBegin(GL_POLYGON);//hull mid black
glColor3ub(88, 85, 80);
glVertex2f(0.06, -0.52);
glVertex2f(0.16, -0.52);
glVertex2f(0.16, -0.382);
glVertex2f(0.122, -0.382);
glVertex2f(0.12, -0.4);
glVertex2f(0.105, -0.435);
glVertex2f(0.08, -0.465);
glVertex2f(0.06, -0.48);
glEnd();

glBegin(GL_QUADS);//hull mid black
glColor3ub(88, 85, 80);
glVertex2f(0.16, -0.382);
glVertex2f(0.36, -0.382);
glVertex2f(0.36, -0.52);
glVertex2f(0.16, -0.52);
glEnd();

glBegin(GL_POLYGON);//hull mid black
glColor3ub(88, 85, 80);
glVertex2f(0.36, -0.382);
glVertex2f(0.418, -0.382);
glVertex2f(0.41, -0.41);
glVertex2f(0.39, -0.46);
glVertex2f(0.36, -0.52);
glEnd();

glBegin(GL_QUADS);//hull mid white
glColor3ub(202, 198, 199);
glVertex2f(-0.56, -0.52);
glVertex2f(-0.552, -0.538);
glVertex2f(0.3471, -0.538);
glVertex2f(0.36, -0.52);
glEnd();

glBegin(GL_POLYGON);//hull down black
glColor3ub(88, 85, 80);
glVertex2f(-0.552, -0.538);
glVertex2f(-0.54, -0.58);
glVertex2f(0.315, -0.58);
glVertex2f(0.335, -0.555);
glVertex2f(0.3471, -0.538);
glEnd();

glBegin(GL_POLYGON);//break  down red
glColor3ub(204, 77, 67);
glVertex2f(-0.57, -0.5);
glVertex2f(-0.57, -0.58);
glVertex2f(-0.54, -0.58);
glVertex2f(-0.544, -0.56);
glVertex2f(-0.552, -0.536);
glVertex2f(-0.558, -0.52);
glVertex2f(-0.57, -0.5);
glEnd();

		GLfloat x15=0.258f; GLfloat y15=-0.438f; GLfloat radius15 =0.011f;
	int triangleAmount15 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi15 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 175, 165);
		glVertex2f(x15, y15); // center of circle
		for(i = 0; i <= triangleAmount15;i++) {
			glVertex2f(
		            x15 + (radius15* cos(i *  twicePi15 / triangleAmount15)),
			    y15 + (radius15 * sin(i * twicePi15 / triangleAmount15))
			);
		}
	glEnd();

		GLfloat x16=0.258f; GLfloat y16=-0.438f; GLfloat radius16 =0.006f;
	int triangleAmount16 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi16 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(116, 117, 112); // windmill
		glVertex2f(x16, y16); // center of circle
		for(i = 0; i <= triangleAmount16;i++) {
			glVertex2f(
		            x16 + (radius16* cos(i *  twicePi16 / triangleAmount16)),
			    y16 + (radius16 * sin(i * twicePi16 / triangleAmount16))
			);
		}
	glEnd();

glBegin(GL_QUADS);//anchor
glColor3ub(116, 117, 112);
glVertex2f(0.256, -0.448);
glVertex2f(0.26, -0.448);
glVertex2f(0.26, -0.496);
glVertex2f(0.256, -0.496);
glEnd();


glBegin(GL_POLYGON);//anchor low
glColor3ub(116, 117, 112);
glVertex2f(0.25, -0.492);
glVertex2f(0.25, -0.496);
glVertex2f(0.258, -0.502);
glVertex2f(0.266, -0.496);
glVertex2f(0.27, -0.49);
glVertex2f(0.266, -0.492);
glVertex2f(0.26, -0.496);
glVertex2f(0.256, -0.496);
glEnd();


glBegin(GL_POLYGON);//anchor low
glColor3ub(116, 117, 112);
glVertex2f(0.266, -0.492);
glVertex2f(0.27, -0.49);
glVertex2f(0.272, -0.482);
glVertex2f(0.272, -0.474);
glVertex2f(0.27, -0.474);
glVertex2f(0.27, -0.48);
glVertex2f(0.266, -0.492);
glEnd();

glBegin(GL_TRIANGLES);//anchor low
glColor3ub(116, 117, 112);
glVertex2f(0.272, -0.474);
glVertex2f(0.266, -0.474);
glVertex2f(0.272, -0.466);
glEnd();

glBegin(GL_POLYGON);//anchor low
glColor3ub(116, 117, 112);
glVertex2f(0.25, -0.492);
glVertex2f(0.25, -0.496);
glVertex2f(0.246, -0.49);
glVertex2f(0.244, -0.482);
glVertex2f(0.244, -0.474);
glVertex2f(0.246, -0.474);
glVertex2f(0.246, -0.48);
glEnd();

glBegin(GL_TRIANGLES);//anchor low
glColor3ub(116, 117, 112);
glVertex2f(0.244, -0.474);
glVertex2f(0.25, -0.474);
glVertex2f(0.244, -0.466);
glEnd();


//ship shadow start


glBegin(GL_POLYGON);//shadow
glColor3ub(150, 150, 150);
glVertex2f(0.28, -0.58);
glVertex2f(0.34, -0.6);
glVertex2f(0.38, -0.62);
glVertex2f(0.43, -0.66);
glVertex2f(0.28, -0.66);
glEnd();

glBegin(GL_QUADS);//shadow
glColor3ub(150, 150, 150);
glVertex2f(0.19, -0.58);
glVertex2f(0.28, -0.58);
glVertex2f(0.28, -0.68);
glVertex2f(0.19, -0.68);
glEnd();

glBegin(GL_QUADS);//shadow
glColor3ub(150, 150, 150);
glVertex2f(0.1, -0.58);
glVertex2f(0.19, -0.58);
glVertex2f(0.19, -0.716);
glVertex2f(0.1, -0.715);
glEnd();

glBegin(GL_QUADS);//shadow
glColor3ub(150, 150, 150);
glVertex2f(0.015, -0.58);
glVertex2f(0.1, -0.58);
glVertex2f(0.1, -0.7);
glVertex2f(0.015, -0.7);
glEnd();

glBegin(GL_QUADS);//shadow
glColor3ub(150, 150, 150);
glVertex2f(-0.08, -0.58);
glVertex2f(0.015, -0.58);
glVertex2f(0.015, -0.68);
glVertex2f(-0.08, -0.68);
glEnd();

glBegin(GL_QUADS);//shadow
glColor3ub(150, 150, 150);
glVertex2f(-0.16, -0.58);
glVertex2f(-0.08, -0.58);
glVertex2f(-0.08, -0.7);
glVertex2f(-0.16, -0.7);
glEnd();

glBegin(GL_QUADS);//shadow
glColor3ub(150, 150, 150);
glVertex2f(-0.34, -0.58);
glVertex2f(-0.16, -0.58);
glVertex2f(-0.16, -0.68);
glVertex2f(-0.34, -0.68);
glEnd();

glBegin(GL_QUADS);//shadow
glColor3ub(150, 150, 150);
glVertex2f(-0.38, -0.58);
glVertex2f(-0.34, -0.58);
glVertex2f(-0.34, -0.63);
glVertex2f(-0.38, -0.63);
glEnd();

glBegin(GL_QUADS);//shadow
glColor3ub(150, 150, 150);
glVertex2f(-0.57, -0.58);
glVertex2f(-0.38, -0.58);
glVertex2f(-0.38, -0.68);
glVertex2f(-0.57, -0.68);
glEnd();

glBegin(GL_QUADS);//shadow
glColor3ub(150, 150, 150);
glVertex2f(-0.57, -0.68);
glVertex2f(-0.59, -0.7);
glVertex2f(-0.36, -0.7);
glVertex2f(-0.38, -0.68);
glEnd();

glBegin(GL_QUADS);//shadow
glColor3ub(150, 150, 150);
glVertex2f(-0.54, -0.7);
glVertex2f(-0.54, -0.72);
glVertex2f(-0.4, -0.72);
glVertex2f(-0.4, -0.7);
glEnd();

glBegin(GL_POLYGON);//shadow
glColor3ub(150, 150, 150);
glVertex2f(-0.57, -0.59);
glVertex2f(-0.585, -0.595);
glVertex2f(-0.605, -0.605);
glVertex2f(-0.63, -0.625);
glVertex2f(-0.65, -0.645);
glVertex2f(-0.66, -0.66);
glVertex2f(-0.66, -0.665);
glVertex2f(-0.57, -0.665);
glEnd();

glBegin(GL_QUADS);//shadow
glColor3ub(150, 150, 150);
glVertex2f(-0.525, -0.72);
glVertex2f(-0.52, -0.72);
glVertex2f(-0.52, -0.74);
glVertex2f(-0.525, -0.74);
glEnd();

glBegin(GL_QUADS);//shadow
glColor3ub(150, 150, 150);
glVertex2f(-0.515, -0.72);
glVertex2f(-0.515, -0.735);
glVertex2f(-0.51, -0.735);
glVertex2f(-0.51, -0.72);
glEnd();

glBegin(GL_QUADS);//shadow
glColor3ub(150, 150, 150);
glVertex2f(-0.47, -0.72);
glVertex2f(-0.47, -0.745);
glVertex2f(-0.465, -0.745);
glVertex2f(-0.465, -0.72);
glEnd();

glBegin(GL_QUADS);//shadow
glColor3ub(150, 150, 150);
glVertex2f(-0.415, -0.72);
glVertex2f(-0.41, -0.72);
glVertex2f(-0.41, -0.735);
glVertex2f(-0.415, -0.735);
glEnd();

//ship shadow end
//front ship end


//front crane start

glBegin(GL_QUADS);//brown leg
glColor3ub(109, 33, 14);
glVertex2f(0.36, -0.574);
glVertex2f(0.37, -0.574);
glVertex2f(0.37, -0.59);
glVertex2f(0.36, -0.59);
glEnd();

glBegin(GL_POLYGON);//brown leg 2
glColor3ub(109, 33, 14);
glVertex2f(0.36, -0.59);
glVertex2f(0.356, -0.594);
glVertex2f(0.356, -0.606);
glVertex2f(0.374, -0.606);
glVertex2f(0.374, -0.594);
glVertex2f(0.37, -0.59);
glEnd();

glLoadIdentity();

glBegin(GL_QUADS);//top Horizontal pole
glColor3ub(211, 139, 2);
glVertex2f(-0.14, 0.29);
glVertex2f(-0.1, 0.27);
glVertex2f(0.82, 0.27);
glVertex2f(0.82, 0.29);
glEnd();

glBegin(GL_QUADS);//top diagonal pole
glColor3ub(230, 169, 0);
glVertex2f(0.74, 0.29);
glVertex2f(0.76, 0.29);
glVertex2f(0.38, 0.6);
glVertex2f(0.38, 0.58);
glEnd();

glBegin(GL_QUADS);//top left pole
glColor3ub(232, 186, 20);
glVertex2f(0.35, 0.63);
glVertex2f(0.38, 0.63);
glVertex2f(0.38, 0.57);
glVertex2f(0.35, 0.57);
glEnd();

glBegin(GL_QUADS);//top narrow left pole
glColor3ub(230, 169, 0);
glVertex2f(0.36, 0.57);
glVertex2f(0.36, 0.356);
glVertex2f(0.37, 0.356);
glVertex2f(0.37, 0.57);
glEnd();

glBegin(GL_QUADS);//top left pole 2nd
glColor3ub(232, 186, 20);
glVertex2f(0.354, 0.356);
glVertex2f(0.376, 0.356);
glVertex2f(0.376, 0.302);
glVertex2f(0.354, 0.302);
glEnd();

glBegin(GL_QUADS);// left pole
glColor3ub(230, 169, 0);
glVertex2f(0.358, 0.302);
glVertex2f(0.372, 0.302);
glVertex2f(0.372, -0.574);
glVertex2f(0.358, -0.574);
glEnd();

glBegin(GL_QUADS);// right pole top
glColor3ub(232, 186, 20);
glVertex2f(0.61, 0.425);
glVertex2f(0.635, 0.425);
glVertex2f(0.635, 0.37);
glVertex2f(0.61, 0.37);
glEnd();

glBegin(GL_QUADS);// right pole top narrow
glColor3ub(230, 169, 0);
glVertex2f(0.615, 0.37);
glVertex2f(0.63, 0.37);
glVertex2f(0.63, 0.355);
glVertex2f(0.615, 0.355);
glEnd();

glBegin(GL_QUADS);// right pole top 2nd
glColor3ub(232, 186, 20);
glVertex2f(0.61, 0.355);
glVertex2f(0.635, 0.355);
glVertex2f(0.635, 0.3);
glVertex2f(0.61, 0.3);
glEnd();

glBegin(GL_QUADS);// right pole
glColor3ub(230, 169, 0);
glVertex2f(0.616, 0.3);
glVertex2f(0.63, 0.3);
glVertex2f(0.63, -0.475);
glVertex2f(0.616, -0.475);
glEnd();

glBegin(GL_QUADS);// cross pole top
glColor3ub(205, 154, 10);
glVertex2f(0.372, 0.18);
glVertex2f(0.616, 0.04);
glVertex2f(0.616, 0.02);
glVertex2f(0.372, 0.16);
glEnd();

glBegin(GL_QUADS);// cross pole top
glColor3ub(205, 154, 10);
glVertex2f(0.616, 0.18);
glVertex2f(0.372, 0.04);
glVertex2f(0.372, 0.02);
glVertex2f(0.616, 0.16);
glEnd();

glBegin(GL_QUADS);// cross pole down
glColor3ub(205, 154, 10);
glVertex2f(0.372, -0.11);
glVertex2f(0.616, -0.25);
glVertex2f(0.616, -0.27);
glVertex2f(0.372, -0.13);
glEnd();

glBegin(GL_QUADS);// cross pole down
glColor3ub(205, 154, 10);
glVertex2f(0.372, -0.252);
glVertex2f(0.372, -0.27);
glVertex2f(0.616, -0.125);
glVertex2f(0.616, -0.11);
glEnd();

glBegin(GL_QUADS);// horizontal pole middle top
glColor3ub(205, 154, 10);
glVertex2f(0.372, -0.02);
glVertex2f(0.372, -0.05);
glVertex2f(0.616, -0.05);
glVertex2f(0.616, -0.02);
glEnd();

glBegin(GL_QUADS);// horizontal pole middle down
glColor3ub(205, 154, 10);
glVertex2f(0.372, -0.325);
glVertex2f(0.372, -0.36);
glVertex2f(0.616, -0.36);
glVertex2f(0.616, -0.325);
glEnd();

glBegin(GL_QUADS);// top red deck
glColor3ub(237, 54, 84);
glVertex2f(0.38, 0.37);
glVertex2f(0.49, 0.37);
glVertex2f(0.49, 0.3);
glVertex2f(0.38, 0.3);
glEnd();

glBegin(GL_QUADS);// top red deck 2
glColor3ub(109, 33, 14);
glVertex2f(0.4, 0.3);
glVertex2f(0.47, 0.3);
glVertex2f(0.47, 0.29);
glVertex2f(0.4, 0.29);
glEnd();

glBegin(GL_QUADS);// top red deck window
glColor3ub(38, 38, 38);
glVertex2f(0.39, 0.36);
glVertex2f(0.39, 0.34);
glVertex2f(0.41, 0.34);
glVertex2f(0.41, 0.36);
glEnd();

glBegin(GL_QUADS);// top red deck window 2
glColor3ub(38, 38, 38);
glVertex2f(0.42, 0.36);
glVertex2f(0.42, 0.34);
glVertex2f(0.45, 0.34);
glVertex2f(0.45, 0.36);
glEnd();

glBegin(GL_QUADS);// top red deck window 3
glColor3ub(38, 38, 38);
glVertex2f(0.46, 0.36);
glVertex2f(0.46, 0.34);
glVertex2f(0.48, 0.34);
glVertex2f(0.48, 0.36);
glEnd();

glBegin(GL_QUADS);// square box near the rope
glColor3ub(109, 33, 14);
glVertex2f(0.745, 0.27);
glVertex2f(0.805, 0.27);
glVertex2f(0.805, 0.26);
glVertex2f(0.745, 0.26);
glEnd();

glBegin(GL_QUADS);// square box near the rope
glColor3ub(230, 169, 0);
glVertex2f(0.735, 0.26);
glVertex2f(0.815, 0.26);
glVertex2f(0.815, 0.2);
glVertex2f(0.735, 0.2);
glEnd();


glPushMatrix();
glTranslatef(position6,0,0);//animate Hanger
glBegin(GL_QUADS);// cargo hanger 1
glColor3ub(109, 33, 14);
glVertex2f(0.035, 0.27);
glVertex2f(0.035, 0.255);
glVertex2f(0.075, 0.255);
glVertex2f(0.075, 0.27);
glEnd();

glBegin(GL_QUADS);// cargo hanger 2
glColor3ub(230, 169, 0);
glVertex2f(0.09, 0.255);
glVertex2f(0.02, 0.255);
glVertex2f(0.02, 0.245);
glVertex2f(0.09, 0.245);
glEnd();

glBegin(GL_QUADS);// cargo hanger rope left
glColor3ub(109, 33, 14);
glVertex2f(0.085, 0.245);
glVertex2f(0.08, 0.245);
glVertex2f(0.08, 0.07);
glVertex2f(0.085, 0.07);
glEnd();

glBegin(GL_QUADS);// cargo hanger rope right
glColor3ub(109, 33, 14);
glVertex2f(0.03, 0.245);
glVertex2f(0.025, 0.245);
glVertex2f(0.025, 0.07);
glVertex2f(0.03, 0.07);
glEnd();

glBegin(GL_QUADS);// cargo hanger 3
glColor3ub(230, 169, 0);
glVertex2f(0.09, 0.07);
glVertex2f(0.02, 0.07);
glVertex2f(0.02, 0.04);
glVertex2f(0.09, 0.04);
glEnd();

glBegin(GL_QUADS);// cargo hanger 3 cargo
glColor3ub(33, 39, 179);
glVertex2f(0.11, 0.04);
glVertex2f(-0.0, 0.04);
glVertex2f(-0.0, -0.03);
glVertex2f(0.11, -0.03);
glEnd();

glBegin(GL_LINES);// cargo hanger 3 cargo line
glColor3ub(51, 53, 91);
glVertex2f(0.11, 0.04);
glVertex2f(-0.0, 0.04);
glVertex2f(-0.0, 0.04);
glVertex2f(-0.0, -0.03);
glVertex2f(-0.0, -0.03);
glVertex2f(0.11, -0.03);
glVertex2f(0.11, -0.03);
glVertex2f(0.11, 0.04);
glEnd();

glPopMatrix();


//front cargo cross
glBegin(GL_LINES);
glColor3ub(205, 154, 10);
glVertex2f(0.4, 0.265);//right cross
glVertex2f(0.37, 0.225);
glVertex2f(0.4, 0.27);
glVertex2f(0.4, -0.605);
glVertex2f(0.4, 0.265);
glVertex2f(0.4, 0.265);
glVertex2f(0.37, 0.225);
glVertex2f(0.4, 0.185);
glVertex2f(0.4, 0.185);
glVertex2f(0.37, 0.14);
glVertex2f(0.37, 0.14);
glVertex2f(0.4, 0.1);
glVertex2f(0.4, 0.1);
glVertex2f(0.37, 0.062);
glVertex2f(0.37, 0.062);
glVertex2f(0.4, 0.02);
glVertex2f(0.4, 0.02);
glVertex2f(0.37, -0.02);
glVertex2f(0.37, -0.02);
glVertex2f(0.4, -0.06);
glVertex2f(0.4, -0.06);
glVertex2f(0.37, -0.105);
glVertex2f(0.37, -0.105);
glVertex2f(0.4, -0.145);
glVertex2f(0.4, -0.145);
glVertex2f(0.37, -0.185);
glVertex2f(0.37, -0.185);
glVertex2f(0.4, -0.225);
glVertex2f(0.4, -0.225);
glVertex2f(0.37, -0.265);
glVertex2f(0.37, -0.265);
glVertex2f(0.4, -0.305);
glVertex2f(0.4, -0.305);
glVertex2f(0.37, -0.345);
glVertex2f(0.37, -0.345);
glVertex2f(0.4, -0.39);
glVertex2f(0.4, -0.39);
glVertex2f(0.37, -0.43);
glVertex2f(0.37, -0.43);
glVertex2f(0.4, -0.47);
glVertex2f(0.4, -0.47);
glVertex2f(0.37, -0.51);
glVertex2f(0.37, -0.51);
glVertex2f(0.4, -0.555);
glVertex2f(0.37, 0.265);//left cross
glVertex2f(0.4, 0.225);
glVertex2f(0.4, 0.225);
glVertex2f(0.37, 0.185);
glVertex2f(0.37, 0.185);
glVertex2f(0.4, 0.14);
glVertex2f(0.4, 0.14);
glVertex2f(0.37, 0.1);
glVertex2f(0.37, 0.1);
glVertex2f(0.4, 0.062);
glVertex2f(0.4, 0.062);
glVertex2f(0.37, 0.02);
glVertex2f(0.37, 0.02);
glVertex2f(0.4, -0.02);
glVertex2f(0.4, -0.02);
glVertex2f(0.37, -0.06);
glVertex2f(0.37, -0.06);
glVertex2f(0.4, -0.105);
glVertex2f(0.4, -0.105);
glVertex2f(0.37, -0.145);
glVertex2f(0.37, -0.145);
glVertex2f(0.4, -0.185);
glVertex2f(0.4, -0.185);
glVertex2f(0.37, -0.225);
glVertex2f(0.37, -0.225);
glVertex2f(0.4, -0.265);
glVertex2f(0.4, -0.265);
glVertex2f(0.37, -0.305);
glVertex2f(0.37, -0.305);
glVertex2f(0.4, -0.345);
glVertex2f(0.4, -0.345);
glVertex2f(0.37, -0.39);
glVertex2f(0.37, -0.39);
glVertex2f(0.4, -0.43);
glVertex2f(0.4, -0.43);
glVertex2f(0.37, -0.47);
glVertex2f(0.37, -0.47);
glVertex2f(0.4, -0.51);
glVertex2f(0.4, -0.51);
glVertex2f(0.37, -0.555);
glVertex2f(0.43, 0.27);//front cargo ladder
glVertex2f(0.43, -0.605);
glVertex2f(0.45, 0.27);
glVertex2f(0.45, -0.605);
glVertex2f(0.43, 0.255);
glVertex2f(0.45, 0.255);
glVertex2f(0.43, 0.24);
glVertex2f(0.45, 0.24);
glVertex2f(0.43, 0.222);
glVertex2f(0.45, 0.222);
glVertex2f(0.43, 0.206);
glVertex2f(0.45, 0.206);
glVertex2f(0.43, 0.188);
glVertex2f(0.45, 0.188);
glVertex2f(0.43, 0.172);
glVertex2f(0.45, 0.172);
glVertex2f(0.43, 0.156);
glVertex2f(0.45, 0.156);
glVertex2f(0.43, 0.106);
glVertex2f(0.45, 0.106);
glVertex2f(0.43, 0.088);
glVertex2f(0.45, 0.088);
glVertex2f(0.43, 0.04);
glVertex2f(0.45, 0.04);
glVertex2f(0.43, 0.022);
glVertex2f(0.45, 0.022);
glVertex2f(0.43, 0.006);
glVertex2f(0.45, 0.006);
glVertex2f(0.43, -0.01);
glVertex2f(0.45, -0.01);
glVertex2f(0.43, -0.06);
glVertex2f(0.45, -0.06);
glVertex2f(0.43, -0.078);
glVertex2f(0.45, -0.078);
glVertex2f(0.43, -0.094);
glVertex2f(0.45, -0.094);
glVertex2f(0.43, -0.11);
glVertex2f(0.45, -0.11);
glVertex2f(0.43, -0.128);
glVertex2f(0.45, -0.128);
glVertex2f(0.43, -0.178);
glVertex2f(0.45, -0.178);
glVertex2f(0.43, -0.194);
glVertex2f(0.45, -0.194);
glVertex2f(0.43, -0.21);
glVertex2f(0.45, -0.21);
glVertex2f(0.43, -0.244);
glVertex2f(0.45, -0.244);
glVertex2f(0.43, -0.262);
glVertex2f(0.45, -0.262);
glVertex2f(0.45, -0.278);
glVertex2f(0.45, -0.278);
glVertex2f(0.45, -0.292);
glVertex2f(0.45, -0.292);
glVertex2f(0.43, -0.31);
glVertex2f(0.45, -0.31);
glVertex2f(0.43, -0.362);
glVertex2f(0.45, -0.362);
glVertex2f(0.43, -0.376);
glVertex2f(0.45, -0.376);
glVertex2f(0.43, -0.394);
glVertex2f(0.45, -0.394);
glVertex2f(0.43, -0.41);
glVertex2f(0.45, -0.41);
glVertex2f(0.43, -0.426);
glVertex2f(0.45, -0.426);
glVertex2f(0.43, -0.444);
glVertex2f(0.45, -0.444);
glVertex2f(0.43, -0.46);
glVertex2f(0.45, -0.46);
glVertex2f(0.43, -0.478);
glVertex2f(0.45, -0.478);
glVertex2f(0.43, -0.494);
glVertex2f(0.45, -0.494);
glVertex2f(0.43, -0.51);
glVertex2f(0.45, -0.51);
glVertex2f(0.43, -0.526);
glVertex2f(0.45, -0.526);
glVertex2f(0.43, -0.544);
glVertex2f(0.45, -0.544);
glVertex2f(0.43, -0.56);
glVertex2f(0.45, -0.56);
glVertex2f(0.43, -0.576);
glVertex2f(0.45, -0.576);
glVertex2f(0.43, -0.592);
glEnd();


//Shadow of cross and ladder
glBegin(GL_LINES);
glColor3ub(147, 147, 147);
glVertex2f(0.4, -0.6);//cross shadow
glVertex2f(0.4, -0.694);
glVertex2f(0.386, -0.664);
glVertex2f(0.372, -0.68);
glVertex2f(0.372, -0.68);
glVertex2f(0.386, -0.696);
glVertex2f(0.386, -0.696);
glVertex2f(0.4, -0.68);
glVertex2f(0.4, -0.68);
glVertex2f(0.386, -0.664);
glVertex2f(0.43,- 0.6);//front cargo ladder shadow
glVertex2f(0.43, -0.694);
glVertex2f(0.45,- 0.6);
glVertex2f(0.45, -0.694);
glVertex2f(0.43, -0.615);
glVertex2f(0.45, -0.615);
glVertex2f(0.43, -0.63);
glVertex2f(0.45, -0.63);
glVertex2f(0.43, -0.645);
glVertex2f(0.45, -0.645);
glVertex2f(0.43, -0.655);
glVertex2f(0.45, -0.655);
glVertex2f(0.43, -0.668);
glVertex2f(0.45, -0.668);
glVertex2f(0.43, -0.683);
glVertex2f(0.45, -0.683);
glEnd();

glBegin(GL_QUADS);//left pole shadow
glColor3ub(150, 150, 150);
glVertex2f(0.356, -0.606);
glVertex2f(0.374, -0.606);
glVertex2f(0.374, -0.69);
glVertex2f(0.356, -0.69);

//cargo box front left
glBegin(GL_QUADS);//1
glColor3ub(230, 177, 81);
glVertex2f(0.695, -0.28);
glVertex2f(0.695, -0.38);
glVertex2f(0.86, -0.38);
glVertex2f(0.86, -0.28);
glEnd();

glBegin(GL_LINES);//down row left
glColor3ub(64, 64, 64);
glVertex2f(0.695, -0.28);
glVertex2f(0.695, -0.38);
glVertex2f(0.695, -0.38);
glVertex2f(0.86, -0.38);
glVertex2f(0.86, -0.38);
glVertex2f(0.86, -0.28);
glVertex2f(0.86, -0.28);
glVertex2f(0.695, -0.28);
glEnd();

glBegin(GL_QUADS);//2
glColor3ub(172, 18, 28);
glVertex2f(0.695, -0.38);
glVertex2f(0.695, -0.47);
glVertex2f(0.86, -0.47);
glVertex2f(0.86, -0.38);
glEnd();

glBegin(GL_LINES);//down row left
glColor3ub(64, 64, 64);
glVertex2f(0.695, -0.38);
glVertex2f(0.695, -0.47);
glVertex2f(0.695, -0.47);
glVertex2f(0.86, -0.47);
glVertex2f(0.86, -0.47);
glVertex2f(0.86, -0.38);
glVertex2f(0.86, -0.38);
glVertex2f(0.695, -0.38);
glEnd();

glBegin(GL_QUADS);//3
glColor3ub(97, 126, 166);
glVertex2f(0.86, -0.38);
glVertex2f(0.86, -0.47);
glVertex2f(1, -0.47);
glVertex2f(1, -0.38);
glEnd();

glBegin(GL_LINES);//down raw left
glColor3ub(64, 64, 64);
glVertex2f(0.86, -0.38);
glVertex2f(0.86, -0.47);
glVertex2f(0.86, -0.47);
glVertex2f(1, -0.47);
glVertex2f(1, -0.47);
glVertex2f(1, -0.38);
glVertex2f(1, -0.38);
glVertex2f(0.86, -0.38);
glEnd();

glBegin(GL_QUADS);//4
glColor3ub(22, 28, 157);
glVertex2f(0.86, -0.47);
glVertex2f(0.86, -0.57);
glVertex2f(1, -0.57);
glVertex2f(1, -0.47);
glEnd();

glBegin(GL_LINES);//down raw left
glColor3ub(64, 64, 64);
glVertex2f(0.86, -0.47);
glVertex2f(0.86, -0.57);
glVertex2f(0.86, -0.57);
glVertex2f(1, -0.57);
glVertex2f(1, -0.57);
glVertex2f(1, -0.47);
glVertex2f(1, -0.47);
glVertex2f(0.86, -0.47);
glEnd();

glBegin(GL_QUADS);//5
glColor3ub(219, 103, 109);
glVertex2f(0.86, -0.57);
glVertex2f(0.86, -0.665);
glVertex2f(1, -0.665);
glVertex2f(1, -0.57);
glEnd();

glBegin(GL_LINES);//down raw left
glColor3ub(64, 64, 64);
glVertex2f(0.86, -0.57);
glVertex2f(0.86, -0.665);
glVertex2f(0.86, -0.665);
glVertex2f(1, -0.665);
glVertex2f(1, -0.665);
glVertex2f(1, -0.57);
glVertex2f(1, -0.57);
glVertex2f(0.86, -0.57);
glEnd();

glBegin(GL_QUADS);//6
glColor3ub(252, 239, 73);
glVertex2f(0.86, -0.665);
glVertex2f(0.86, -0.764);
glVertex2f(1, -0.764);
glVertex2f(1, -0.665);
glEnd();

glBegin(GL_LINES);//down raw left
glColor3ub(64, 64, 64);
glVertex2f(0.86, -0.665);
glVertex2f(0.86, -0.764);
glVertex2f(0.86, -0.764);
glVertex2f(1, -0.764);
glVertex2f(1, -0.764);
glVertex2f(1, -0.665);
glVertex2f(1, -0.665);
glVertex2f(0.86, -0.665);
glEnd();

glBegin(GL_QUADS);//7
glColor3ub(76, 217, 115);
glVertex2f(0.695, -0.665);
glVertex2f(0.695, -0.764);
glVertex2f(0.86, -0.764);
glVertex2f(0.86, -0.665);
glEnd();

glBegin(GL_LINES);//down raw left
glColor3ub(64, 64, 64);
glVertex2f(0.695, -0.665);
glVertex2f(0.695, -0.764);
glVertex2f(0.695, -0.764);
glVertex2f(0.86, -0.764);
glVertex2f(0.86, -0.764);
glVertex2f(0.86, -0.665);
glVertex2f(0.86, -0.665);
glVertex2f(0.695, -0.665);
glEnd();

glBegin(GL_QUADS);//8
glColor3ub(252, 239, 73);
glVertex2f(0.53, -0.665);
glVertex2f(0.53, -0.764);
glVertex2f(0.695, -0.764);
glVertex2f(0.695, -0.665);
glEnd();

glBegin(GL_LINES);//down row left
glColor3ub(64, 64, 64);
glVertex2f(0.53, -0.665);
glVertex2f(0.53, -0.764);
glVertex2f(0.53, -0.764);
glVertex2f(0.695, -0.764);
glVertex2f(0.695, -0.764);
glVertex2f(0.695, -0.665);
glVertex2f(0.695, -0.665);
glVertex2f(0.53, -0.665);
glEnd();


glBegin(GL_QUADS);//9
glColor3ub(175, 31, 38);
glVertex2f(0.53, -0.57);
glVertex2f(0.53, -0.665);
glVertex2f(0.695, -0.665);
glVertex2f(0.695, -0.57);
glEnd();

glBegin(GL_LINES);//down row left
glColor3ub(64, 64, 64);
glVertex2f(0.53, -0.57);
glVertex2f(0.53, -0.665);
glVertex2f(0.53, -0.665);
glVertex2f(0.695, -0.665);
glVertex2f(0.695, -0.665);
glVertex2f(0.695, -0.57);
glVertex2f(0.695, -0.57);
glVertex2f(0.53, -0.57);
glEnd();

glBegin(GL_QUADS);//10
glColor3ub(252, 239, 73);
glVertex2f(0.695, -0.57);
glVertex2f(0.695, -0.665);
glVertex2f(0.86, -0.665);
glVertex2f(0.86, -0.57);
glEnd();

glBegin(GL_LINES);//down row left
glColor3ub(64, 64, 64);
glVertex2f(0.695, -0.57);
glVertex2f(0.695, -0.665);
glVertex2f(0.695, -0.665);
glVertex2f(0.86, -0.665);
glVertex2f(0.86, -0.665);
glVertex2f(0.86, -0.57);
glVertex2f(0.86, -0.57);
glEnd();

glBegin(GL_QUADS);//11
glColor3ub(132, 85, 164);
glVertex2f(0.695, -0.47);
glVertex2f(0.695, -0.57);
glVertex2f(0.86, -0.57);
glVertex2f(0.86, -0.47);
glEnd();

glBegin(GL_LINES);//down row left
glColor3ub(64, 64, 64);
glVertex2f(0.695, -0.47);
glVertex2f(0.695, -0.57);
glVertex2f(0.695, -0.57);
glVertex2f(0.86, -0.57);
glVertex2f(0.86, -0.57);
glVertex2f(0.86, -0.47);
glVertex2f(0.86, -0.47);
glVertex2f(0.695, -0.47);
glEnd();

glBegin(GL_QUADS);//12
glColor3ub(45, 46, 208);
glVertex2f(0.53, -0.47);
glVertex2f(0.53, -0.57);
glVertex2f(0.695, -0.57);
glVertex2f(0.695, -0.47);
glEnd();

glBegin(GL_LINES);//down raw left
glColor3ub(64, 64, 64);
glVertex2f(0.53, -0.47);
glVertex2f(0.53, -0.57);
glVertex2f(0.53, -0.57);
glVertex2f(0.695, -0.57);
glVertex2f(0.695, -0.57);
glVertex2f(0.695, -0.47);
glVertex2f(0.695, -0.47);
glVertex2f(0.53, -0.47);
glEnd();

glBegin(GL_QUADS);//front cargo shadow
glColor3ub(150, 150, 150);
glVertex2f(0.53, -0.765);
glVertex2f(0.53, -1);
glVertex2f(1, -1);
glVertex2f(1, -0.765);
glEnd();

//cargo truck start

glPushMatrix();
glTranslatef(position7,0,0);// animate truck

glBegin(GL_QUADS);//front cargo car
glColor3ub(231, 139, 54);
glVertex2f(-0.306, -0.63);
glVertex2f(-0.306, -0.67);
glVertex2f(-0.256, -0.67);
glVertex2f(-0.262, -0.63);
glEnd();

glBegin(GL_QUADS);//front cargo car
glColor3ub(231, 139, 54);
glVertex2f(-0.306, -0.67);
glVertex2f(-0.306, -0.74);
glVertex2f(-0.256, -0.74);
glVertex2f(-0.256, -0.67);
glEnd();

glBegin(GL_QUADS);//front cargo car
glColor3ub(231, 139, 54);
glVertex2f(-0.256, -0.67);
glVertex2f(-0.256, -0.74);
glVertex2f(-0.223, -0.74);
glVertex2f(-0.223, -0.682);
glEnd();

glBegin(GL_QUADS);//front cargo car
glColor3ub(231, 139, 54);
glVertex2f(-0.223, -0.682);
glVertex2f(-0.223, -0.722);
glVertex2f(-0.212, -0.722);
glVertex2f(-0.212, -0.686);
glEnd();

glBegin(GL_QUADS);//front cargo car light
glColor3ub(240, 241, 243);
glVertex2f(-0.216, -0.692);
glVertex2f(-0.216, -0.704);
glVertex2f(-0.212, -0.704);
glVertex2f(-0.212, -0.692);
glEnd();
glBegin(GL_QUADS);//front cargo car glass
glColor3ub(169, 209, 242);
glVertex2f(-0.292, -0.635);
glVertex2f(-0.292, -0.67);
glVertex2f(-0.261, -0.67);
glVertex2f(-0.265, -0.635);
glEnd();

glBegin(GL_QUADS);//car handle
glColor3ub(72, 65, 63);
glVertex2f(-0.223, -0.722);
glVertex2f(-0.223, -0.739);
glVertex2f(-0.212, -0.739);
glVertex2f(-0.212, -0.722);
glEnd();

glBegin(GL_QUADS);//car handle
glColor3ub(72, 65, 63);
glVertex2f(-0.388, -0.739);
glVertex2f(-0.388, -0.752);
glVertex2f(-0.212, -0.752);
glVertex2f(-0.212, -0.739);
glEnd();

glBegin(GL_POLYGON);//car oil engine
glColor3ub(131, 131, 131);
glVertex2f(-0.337, -0.742);
glVertex2f(-0.341, -0.747);
glVertex2f(-0.341, -0.761);
glVertex2f(-0.337, -0.767);
glVertex2f(-0.305, -0.767);
glVertex2f(-0.3, -0.76);
glVertex2f(-0.3, -0.746);
glVertex2f(-0.305, -0.742);
glEnd();

glBegin(GL_QUADS);//car oil black box
glColor3ub(38, 33, 35);
glVertex2f(-0.322, -0.716);
glVertex2f(-0.322, -0.74);
glVertex2f(-0.306, -0.74);
glVertex2f(-0.306, -0.716);
glEnd();

glBegin(GL_QUADS);//car opener
glColor3ub(38, 33, 35);
glVertex2f(-0.292, -0.692);
glVertex2f(-0.292, -0.698);
glVertex2f(-0.286, -0.698);
glVertex2f(-0.286, -0.692);
glEnd();

glBegin(GL_QUADS);//middle car
glColor3ub(38, 33, 35);
glVertex2f(-0.38, -0.734);
glVertex2f(-0.38, -0.738);
glVertex2f(-0.35, -0.738);
glVertex2f(-0.35, -0.734);
glEnd();

glBegin(GL_QUADS);//middle car handle
glColor3ub(38, 33, 35);
glVertex2f(-0.602, -0.728);
glVertex2f(-0.602, -0.734);
glVertex2f(-0.344, -0.734);
glVertex2f(-0.344, -0.728);
glEnd();

glBegin(GL_QUADS);//middle car handle
glColor3ub (63, 61, 62);
glVertex2f(-0.4435, -0.734);
glVertex2f(-0.4435, -0.744);
glVertex2f(-0.402, -0.744);
glVertex2f(-0.402, -0.734);
glEnd();

glBegin(GL_QUADS);//middle car handle
glColor3ub (63, 61, 62);
glVertex2f(-0.408, -0.744);
glVertex2f(-0.408, -0.762);
glVertex2f(-0.404, -0.762);
glVertex2f(-0.404, -0.744);
glEnd();

glBegin(GL_QUADS);//middle car handle
glColor3ub (63, 61, 62);
glVertex2f(-0.414, -0.744);
glVertex2f(-0.408, -0.753);
glVertex2f(-0.408, -0.75);
glVertex2f(-0.412, -0.744);
glEnd();

glBegin(GL_QUADS);//middle car handle
glColor3ub (63, 61, 62);
glVertex2f(-0.58, -0.734);
glVertex2f(-0.58, -0.75);
glVertex2f(-0.46, -0.75);
glVertex2f(-0.42, -0.734);
glEnd();

glBegin(GL_QUADS);//middle car handle
glColor3ub (63, 61, 62);
glVertex2f(-0.597, -0.728);
glVertex2f(-0.597, -0.744);
glVertex2f(-0.576, -0.744);
glVertex2f(-0.576, -0.728);
glEnd();

glBegin(GL_QUADS);//middle car handle
glColor3ub (63, 61, 62);
glVertex2f(-0.592, -0.744);
glVertex2f(-0.592, -0.762);
glVertex2f(-0.59, -0.762);
glVertex2f(-0.59, -0.744);
glEnd();

glBegin(GL_QUADS);//cargo box
glColor3ub(36, 45, 198);
glVertex2f(-0.572, -0.62);
glVertex2f(-0.572, -0.728);
glVertex2f(-0.386, -0.728);
glVertex2f(-0.386, -0.62);
glEnd();

glBegin(GL_LINES);//car line
glColor3ub(120, 90, 58);
glVertex2f(-0.295, -0.633);
glVertex2f(-0.265, -0.633);
glVertex2f(-0.265, -0.633);
glVertex2f(-0.2585, -0.67);
glVertex2f(-0.2585, -0.67);
glVertex2f(-0.2586, -0.735);
glVertex2f(-0.2586, -0.735);
glVertex2f(-0.295, -0.735);
glVertex2f(-0.295, -0.735);
glVertex2f(-0.295, -0.633);

glVertex2f(-0.213, -0.692);
glVertex2f(-0.213, -0.691);
glVertex2f(-0.213, -0.691);
glVertex2f(-0.217, -0.691);
glVertex2f(-0.217, -0.691);
glVertex2f(-0.217, -0.709);
glVertex2f(-0.217, -0.709);
glVertex2f(-0.213, -0.709);
glVertex2f(-0.213, -0.709);
glVertex2f(-0.213, -0.704);
glEnd();

//car wheels

GLfloat x17=-0.247f, y17=-0.76f, radius17 =0.016f;  //front wheel
	int triangleAmount17= 20; //# of triangles used to draw circle

	GLfloat twicePi17 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub (4, 0, 2); // truck tire
		glVertex2f(x17, y17); // center of circle
		for(i = 0; i <= triangleAmount17; i++)
            {
			glVertex2f(
		            x17 + (radius17* cos(i *  twicePi17 / triangleAmount17)),
			    y17 + (radius17 * sin(i * twicePi17 / triangleAmount17))
			);
		}
	glEnd();

GLfloat x18=-0.247f, y18=-0.76f, radius18 =0.009f;  //front wheel Inner Circle
	int triangleAmount18= 20; //# of triangles used to draw circle

	GLfloat twicePi18 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(239, 240, 242); // truck tire
		glVertex2f(x18, y18); // center of circle
		for(i = 0; i <= triangleAmount18;i++) {
			glVertex2f(
		            x18 + (radius18* cos(i *  twicePi18 / triangleAmount18)),
			    y18 + (radius18* sin(i * twicePi18 / triangleAmount18))
			);
		}
	glEnd();

GLfloat x19=-0.247f, y19=-0.76f, radius19 =0.004f;
	int triangleAmount19= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi19 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub (4, 0, 2); //truck tire
		glVertex2f(x19, y19); // center of circle
		for(i = 0; i <= triangleAmount19;i++) {
			glVertex2f(
		            x19 + (radius19* cos(i *  twicePi19 / triangleAmount19)),
			    y19 + (radius19* sin(i * twicePi19 / triangleAmount19))
			);
		}
	glEnd();

GLfloat x20=-0.3645f, y20= -0.76f, radius20 =0.016f;
	int triangleAmount20= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi20= 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub (4, 0, 2); // truck tire
		glVertex2f(x20, y20); // center of circle
		for(i = 0; i <= triangleAmount20;i++) {
			glVertex2f(
		            x20 + (radius20* cos(i *  twicePi20/ triangleAmount20)),
			    y20+ (radius20 * sin(i * twicePi20/ triangleAmount20))
			);
		}
	glEnd();

GLfloat x21=-0.3645f, y21= -0.76f, radius21 =0.009f;
	int triangleAmount21= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi21= 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub (239, 240, 242); // truck tire
		glVertex2f(x21, y21); // center of circle
		for(i = 0; i <= triangleAmount21;i++) {
			glVertex2f(
		            x21 + (radius21* cos(i *  twicePi21/ triangleAmount21)),
			    y21+ (radius21 * sin(i * twicePi21/ triangleAmount21))
			);
		}
	glEnd();

GLfloat x22=-0.3645f, y22= -0.76f, radius22 =0.004f;
	int triangleAmount22= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi22= 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub (4, 0, 2); // truck tire
		glVertex2f(x22, y22); // center of circle
		for(i = 0; i <= triangleAmount22;i++) {
			glVertex2f(
		            x22 + (radius22* cos(i *  twicePi22/ triangleAmount22)),
			    y22+ (radius22 * sin(i * twicePi22/ triangleAmount22))
			);
		}
	glEnd();

GLfloat x23=-0.5285f, y23=  -0.76f, radius23 =0.016f;
	int triangleAmount23= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi23= 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub (4, 0, 2); // truck tire
		glVertex2f(x23, y23); // center of circle
		for(i = 0; i <= triangleAmount23;i++) {
			glVertex2f(
		            x23 + (radius23* cos(i *  twicePi23/ triangleAmount23)),
			    y23+ (radius23 * sin(i * twicePi23/ triangleAmount23))
			);
		}
	glEnd();

GLfloat x24=-0.5285f, y24=  -0.76f, radius24 =0.009f;
	int triangleAmount24= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi24= 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub (239, 240, 242); //truck tire
		glVertex2f(x24, y24); // center of circle
		for(i = 0; i <= triangleAmount24;i++) {
			glVertex2f(
		            x24 + (radius24* cos(i *  twicePi24/ triangleAmount24)),
			    y24+ (radius24 * sin(i * twicePi24/ triangleAmount24))
			);
		}
	glEnd();

	GLfloat x25=-0.5285f, y25=  -0.76f, radius25 =0.004f;
	int triangleAmount25= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi25= 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub (4, 0, 2); // truck tire
		glVertex2f(x25, y25); // center of circle
		for(i = 0; i <= triangleAmount25;i++) {
			glVertex2f(
		            x25 + (radius25* cos(i *  twicePi25/ triangleAmount25)),
			    y25+ (radius25* sin(i * twicePi25/ triangleAmount25))
			);
		}
	glEnd();

	GLfloat x26=-0.564f, y26=  -0.76f, radius26 =0.016f;
	int triangleAmount26= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi26= 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub (4, 0, 2); // truck tire
		glVertex2f(x26, y26); // center of circle
		for(i = 0; i <= triangleAmount26;i++) {
			glVertex2f(
		            x26+ (radius26* cos(i *  twicePi26/ triangleAmount26)),
			    y26+ (radius26* sin(i * twicePi26/ triangleAmount26))
			);
		}
	glEnd();

		GLfloat x27=-0.564f, y27=  -0.76f, radius27 =0.009f;
	int triangleAmount27= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi27= 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub (239, 240, 242); // truck tire
		glVertex2f(x27, y27); // center of circle
		for(i = 0; i <= triangleAmount27;i++) {
			glVertex2f(
		            x27+ (radius27* cos(i *  twicePi27/ triangleAmount27)),
			    y27+ (radius27* sin(i * twicePi27/ triangleAmount27))
			);
		}
	glEnd();
		GLfloat x28=-0.564f, y28=  -0.76f, radius28 =0.004f;
	int triangleAmount28= 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi28= 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub (4, 0, 2); // truck tire
		glVertex2f(x28, y28); // center of circle
		for(i = 0; i <= triangleAmount28;i++) {
			glVertex2f(
		            x28+ (radius28* cos(i *  twicePi28/ triangleAmount28)),
			    y28+ (radius28* sin(i * twicePi28/ triangleAmount28))
			);
		}
	glEnd();

//cargo truck end

glPopMatrix();

//Cargo | Box | Container Start

glBegin(GL_QUADS);//left cargo1
glColor3ub(33, 39, 179);
glVertex2f(-0.88, -0.54);
glVertex2f(-0.72, -0.54);
glVertex2f(-0.72, -0.64);
glVertex2f(-0.88, -0.64);
glEnd();

glBegin(GL_LINES);//dark line
glColor3ub(64, 64, 64);
glVertex2f(-0.88, -0.54);
glVertex2f(-0.72, -0.54);
glVertex2f(-0.72, -0.54);
glVertex2f(-0.72, -0.64);
glVertex2f(-0.72, -0.64);
glVertex2f(-0.88, -0.64);
glVertex2f(-0.88, -0.64);
glVertex2f(-0.88, -0.54);
glEnd();

glBegin(GL_QUADS);//left cargo2
glColor3ub(191, 48, 45);
glVertex2f(-0.88, -0.64);
glVertex2f(-0.72, -0.64);
glVertex2f(-0.72, -0.74);
glVertex2f(-0.88, -0.74);
glEnd();

glBegin(GL_LINES);//dark line
glColor3ub(64, 64, 64);
glVertex2f(-0.88, -0.64);
glVertex2f(-0.72, -0.64);
glVertex2f(-0.72, -0.64);
glVertex2f(-0.72, -0.74);
glVertex2f(-0.72, -0.74);
glVertex2f(-0.88, -0.74);
glVertex2f(-0.88, -0.74);
glVertex2f(-0.88, -0.64);
glEnd();

glBegin(GL_QUADS);//left cargo3
glColor3ub(255, 242, 78);
glVertex2f(-0.88, -0.74);
glVertex2f(-0.72, -0.74);
glVertex2f(-0.72, -0.84);
glVertex2f(-0.88, -0.84);
glEnd();

glBegin(GL_LINES);//dark line
glColor3ub(64, 64, 64);
glVertex2f(-0.88, -0.74);
glVertex2f(-0.72, -0.74);
glVertex2f(-0.72, -0.74);
glVertex2f(-0.72, -0.84);
glVertex2f(-0.72, -0.84);
glVertex2f(-0.88, -0.84);
glVertex2f(-0.88, -0.84);
glVertex2f(-0.88, -0.74);
glEnd();

glBegin(GL_QUADS);//left cargo shadow
glColor3ub(150, 150, 150);
glVertex2f(-0.88, -0.84);
glVertex2f(-0.72, -0.84);
glVertex2f(-0.72, -1);
glVertex2f(-0.88, -1);
glEnd();

glBegin(GL_QUADS);//2nd right cargo
glColor3ub(212, 41, 37);
glVertex2f(0.23, -0.69);
glVertex2f(0.39, -0.69);
glVertex2f(0.39, -0.79);
glVertex2f(0.23, -0.79);
glEnd();

glBegin(GL_LINES);//dark line
glColor3ub(64, 64, 64);
glVertex2f(0.23, -0.69);
glVertex2f(0.39, -0.69);
glVertex2f(0.39, -0.69);
glVertex2f(0.39, -0.79);
glVertex2f(0.39, -0.79);
glVertex2f(0.23, -0.79);
glVertex2f(0.23, -0.79);
glVertex2f(0.23, -0.69);
glEnd();

glBegin(GL_QUADS);//2nd right cargo
glColor3ub(234, 226, 41);
glVertex2f(0.23, -0.79);
glVertex2f(0.39, -0.79);
glVertex2f(0.39, -0.89);
glVertex2f(0.23, -0.89);
glEnd();

glBegin(GL_LINES);//dark line
glColor3ub(64, 64, 64);
glVertex2f(0.23, -0.79);
glVertex2f(0.39, -0.79);
glVertex2f(0.39, -0.79);
glVertex2f(0.39, -0.89);
glVertex2f(0.39, -0.89);
glVertex2f(0.23, -0.89);
glVertex2f(0.23, -0.89);
glVertex2f(0.23, -0.79);
glEnd();

glBegin(GL_QUADS);//2nd right cargo
glColor3ub(63, 91, 128);
glVertex2f(0.39, -0.69);
glVertex2f(0.52, -0.69);
glVertex2f(0.52, -0.79);
glVertex2f(0.39, -0.79);
glEnd();

glBegin(GL_LINES);//dark line
glColor3ub(64, 64, 64);
glVertex2f(0.39, -0.69);
glVertex2f(0.52, -0.69);
glVertex2f(0.52, -0.69);
glVertex2f(0.52, -0.79);
glVertex2f(0.52, -0.79);
glVertex2f(0.39, -0.79);
glVertex2f(0.39, -0.79);
glVertex2f(0.39, -0.69);
glEnd();

glBegin(GL_QUADS);//2nd right cargo
glColor3ub(43, 46, 189);
glVertex2f(0.39, -0.79);
glVertex2f(0.52, -0.79);
glVertex2f(0.52, -0.89);
glVertex2f(0.39, -0.89);
glEnd();

glBegin(GL_LINES);//dark line
glColor3ub(64, 64, 64);
glVertex2f(0.39, -0.79);
glVertex2f(0.52, -0.79);
glVertex2f(0.52, -0.79);
glVertex2f(0.52, -0.89);
glVertex2f(0.52, -0.89);
glVertex2f(0.39, -0.89);
glVertex2f(0.39, -0.89);
glVertex2f(0.39, -0.79);
glEnd();

glBegin(GL_QUADS);//2nd right cargo shadow
glColor3ub(150, 150, 150);
glVertex2f(0.23, -0.89);
glVertex2f(0.52, -0.89);
glVertex2f(0.52, -1);
glVertex2f(0.23, -1);
glEnd();

glutTimerFunc(10000,night_loop,0);
glFlush();
}





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/*void rain(){

void Rain(int value){
if(rain){

    _rain += 0.01f;

    glBegin(GL_POINTS);
    for(int i=1; i<=1000; i++)
    {
        int x=rand(),y=rand();
        x%=1000; y%=1000;
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(x,y);
        glVertex2d(x+5,y+5);
        glEnd();
    }

	glutPostRedisplay();
	glutTimerFunc(5, Rain, 0);

    glFlush();

}
}
*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void sound()
{
    PlaySound("q.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}

void sound2()
{
    PlaySound("w.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}

void sound3()
{
    PlaySound("r.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}

void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {

case '1':
    glLoadIdentity();
    glutDisplayFunc(day);
    sound();
    glutPostRedisplay();
    break;

case '2':
    glLoadIdentity();
    glutDisplayFunc(night);
    sound2();
    glutPostRedisplay();
    break;

case '3':
    glLoadIdentity();
    glutDisplayFunc(rain);
    sound3();
    glutPostRedisplay();
    break;


case 'a':
    position6 -= 0.007f;
    break;
case 'd':
    position6 += 0.007f;
    break;


case 27:     // ESC key
    exit(0);
    break;

glutPostRedisplay();
	}
}

/*void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			printf("clicked at (%d, %d)\n", x, y);
		}
	}
	glutPostRedisplay();
}
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main(int argc, char** argv)
{
    cout << endl << "*********** Instructions ********************" << endl << endl;

    cout << "Press A : To move the Crane Backward " << endl << endl;
    //cout << "Press S : To Stop the Crane" << endl << endl;
    cout << "Press D : To move the Crane Forward" << endl << endl;

    cout << "Press 1 : For Day" << endl << endl;
    cout << "Press 2 : For Night " << endl << endl;
    cout << "Press 3 : For Rain" << endl << endl;

    glutInit(&argc, argv);               // Initializing GLUT
    glutInitWindowSize(1280, 920);
    glutCreateWindow("Chittagong Port    ||     Project by: Arik . Eraz . Nowrin . Saidul . Mahin");
    glutDisplayFunc(day);
    glutKeyboardFunc(handleKeypress);
    //glutMouseFunc(handleMouse);
    glutTimerFunc(100, updateCloud, 0);
    glutTimerFunc(100, updateWave1, 0);
    glutTimerFunc(100, updateWave2, 0);
    glutTimerFunc(100, updateShip1, 0);
    glutTimerFunc(100, updateHanger, 0);
    glutTimerFunc(100, updateTruck, 0);
    glutTimerFunc(100, updateSunEve, 0);
    glutTimerFunc(100, updateRain, 0);
    glutTimerFunc(100, updateRain2, 0);
    glutMainLoop();
    return 0;
    }
