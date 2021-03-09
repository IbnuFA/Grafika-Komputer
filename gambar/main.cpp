#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<Windows.h>
#include<stdio.h>
#include<math.h>


//garis
void garis() {
	glBegin(GL_LINES);
	glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
	glVertex3f(300, 0, 0.0);
	glVertex3f(300, 600, 0.0);

	glVertex3f(0, 300, 0.0);
	glVertex3f(600, 300, 0.0);
	glEnd();
}

//kaki
void kaki() {
	//Kiri
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(265, 150);
	glVertex2f(265, 300);
	glVertex2f(275, 300);
	glVertex2f(275, 150);
	glEnd();

	//Kanan
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(325, 150);
	glVertex2f(325, 300);
	glVertex2f(335, 300);
	glVertex2f(335, 150);
	glEnd();
}

//badan
void badan() {
	float radiusX, radiusY;
	int i;
	float DEG2RAD = 3.14159 / 180.0;

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 1.0f);
	double radius = 90; //Besar badan
	double ori_x = 300; // Koordinat x
	double ori_y = 300; // Koordinat y
	double pi = 3.14;
	for (int i = 0; i <= 300; i++) {
		double angle = 2 * pi * i / 300;
		double x = cos(angle) * radius;
		double y = sin(angle) * radius;
		glVertex2d(ori_x + x, ori_y + y);
	}
	glEnd();

	glPushAttrib(GL_CURRENT_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	glLineWidth(2.0);

	glBegin(GL_POINTS);
	glColor3f(0.5, 0.0, 1.0);
	glPointSize(3);
	glVertex2d(100, 200);
	glVertex2d(200, 300);
	glVertex2d(200, 300);
	glVertex2d(200, 400);
	glEnd();

	glBegin(GL_POINTS);
	glVertex2d(0, 0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	for (GLfloat i = 0; i < 360; i++)
	{
		float x = cos(i * 314 / 180.f) * 0.5;
		float y = sin(i * 314 / 180.f) * 0.5;
		glVertex2f(x, y);
	}
	glEnd();
}

//Kepala luar
void kepala_luar() {

	glBegin(GL_POINTS);
	glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
	int Xc = 300, Yc = 350;
	int x = 0, y = 90, ry2 = 90 * 90, rx2 = 50 * 50, doublerx2 = 2 * rx2, doublery2 = 2 * ry2;
	int pk = ry2 - rx2 * 90 + (1 / 4 * ry2);
	glVertex2d(Xc + x, Yc + y);
	glVertex2d(Xc - x, Yc + y);
	glVertex2d(Xc + x, Yc - y);
	glVertex2d(Xc - x, Yc - y);

	if (pk < 0) {
		x += 1;
	}
	else {
		x += 1;
		y -= 1;
	}
	glVertex2d(Xc + x, Yc + y);
	glVertex2d(Xc - x, Yc + y);
	glVertex2d(Xc + x, Yc - y);
	glVertex2d(Xc - x, Yc - y);
	int fx, fy;
	fx = doublery2 * x;
	fy = doublerx2 * y;
	while (fx < fy)
	{
		if (pk < 0) {
			pk = pk + fx + ry2;
			if (pk < 0) {
				x += 1;
			}
			else {
				x += 1;
				y -= 1;
			}
		}
		else
		{
			pk = pk + fx - fy + ry2;
			if (pk < 0) {
				x += 1;
			}
			else {
				x += 1;
				y -= 1;
			}
		}
		glVertex2d(Xc + x, Yc + y);
		glVertex2d(Xc - x, Yc + y);
		glVertex2d(Xc + x, Yc - y);
		glVertex2d(Xc - x, Yc - y);
		fx = doublery2 * x;
		fy = doublerx2 * y;
	}
	float x0 = x, y0 = y;
	int pk1 = ry2 * pow((x0 + 0.5), 2) + rx2 * pow((y0 - 1), 2) - (rx2 * ry2);
	if (pk1 > 0)
		y -= 1;
	else {
		x += 1;
		y -= 1;
	}
	fx = doublery2 * x;
	fy = doublerx2 * y;
	while (y != 0)
	{
		if (pk1 > 0) {
			pk1 = pk1 - fy + rx2;
			if (pk1 > 0)
				y -= 1;
			else {
				x += 1;
				y -= 1;
			}
		}
		else {
			pk1 = pk1 + fx - fy + rx2;
			if (pk1 > 0)
				y -= 1;
			else {
				x += 1;
				y -= 1;
			}
		}
		glVertex2d(Xc + x, Yc + y);
		glVertex2d(Xc - x, Yc + y);
		glVertex2d(Xc + x, Yc - y);
		glVertex2d(Xc - x, Yc - y);
		fx = doublery2 * x;
		fy = doublerx2 * y;
	}
	glEnd();
}

//kepala
void kepala() {
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 1.0f);
	int Xc = 300, Yc = 350;
	int x = 0, y = 90, ry2 = 90 * 90, rx2 = 50 * 50, doublerx2 = 2 * rx2, doublery2 = 2 * ry2;
	int pk = ry2 - rx2 * 100 + (1 / 4 * ry2);
	int fx, fy;
	fx = doublery2 * x;
	fy = doublerx2 * y;
	while (fx < fy)
	{
		if (pk < 0) {
			pk = pk + fx + ry2;
			if (pk < 0) {
				x += 1;
			}
			else {
				x += 1;
				y -= 1;
			}
		}
		else
		{
			pk = pk + fx - fy + ry2;
			if (pk < 0) {
				x += 1;
			}
			else {
				x += 1;
				y -= 1;
			}
		}
		glVertex2d(Xc + x, Yc + y);
		glVertex2d(Xc - x, Yc + y);
		glVertex2d(Xc + x, Yc - y);
		glVertex2d(Xc - x, Yc - y);
		fx = doublery2 * x;
		fy = doublerx2 * y;
	}
	float x0 = x, y0 = y;
	int pk1 = ry2 * pow((x0 + 0.5), 2) + rx2 * pow((y0 - 1), 2) - (rx2 * ry2);
	if (pk1 > 0)
		y -= 1;
	else {
		x += 1;
		y -= 1;
	}
	fx = doublery2 * x;
	fy = doublerx2 * y;
	while (y != 0)
	{
		if (pk1 > 0) {
			pk1 = pk1 - fy + rx2;
			if (pk1 > 0)
				y -= 1;
			else {
				x += 1;
				y -= 1;
			}
		}
		else {
			pk1 = pk1 + fx - fy + rx2;
			if (pk1 > 0)
				y -= 1;
			else {
				x += 1;
				y -= 1;
			}
		}
		glVertex2d(Xc + x, Yc + y);
		glVertex2d(Xc - x, Yc + y);
		glVertex2d(Xc + x, Yc - y);
		glVertex2d(Xc - x, Yc - y);
		fx = doublery2 * x;
		fy = doublerx2 * y;
	}
	glEnd();
}

//mulut
void mulut() {

	glBegin(GL_POLYGON);
	glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
	int Xc = 300, Yc = 290, Y = 10, X = 15;
	int x = 0, y = Y, ry2 = Y * Y, rx2 = X * X, doublerx2 = 2 * rx2, doublery2 = 2 * ry2;
	int pk = ry2 - rx2 * Y + (1 / 4 * ry2);
	int fx, fy;
	fx = doublery2 * x;
	fy = doublerx2 * y;
	while (fx < fy)
	{
		if (pk < 0) {
			pk = pk + fx + ry2;
			if (pk < 0) {
				x += 1;
			}
			else {
				x += 1;
				y -= 1;
			}
		}
		else
		{
			pk = pk + fx - fy + ry2;
			if (pk < 0) {
				x += 1;
			}
			else {
				x += 1;
				y -= 1;
			}
		}
		glVertex2d(Xc + x, Yc + y);
		glVertex2d(Xc - x, Yc + y);
		glVertex2d(Xc + x, Yc - y);
		glVertex2d(Xc - x, Yc - y);
		fx = doublery2 * x;
		fy = doublerx2 * y;
	}
	float x0 = x, y0 = y;
	int pk1 = ry2 * pow((x0 + 0.5), 2) + rx2 * pow((y0 - 1), 2) - (rx2 * ry2);
	if (pk1 > 0)
		y -= 1;
	else {
		x += 1;
		y -= 1;
	}
	fx = doublery2 * x;
	fy = doublerx2 * y;
	while (y != 0)
	{
		if (pk1 > 0) {
			pk1 = pk1 - fy + rx2;
			if (pk1 > 0)
				y -= 1;
			else {
				x += 1;
				y -= 1;
			}
		}
		else {
			pk1 = pk1 + fx - fy + rx2;
			if (pk1 > 0)
				y -= 1;
			else {
				x += 1;
				y -= 1;
			}
		}
		glVertex2d(Xc + x, Yc + y);
		glVertex2d(Xc - x, Yc + y);
		glVertex2d(Xc + x, Yc - y);
		glVertex2d(Xc - x, Yc - y);
		fx = doublery2 * x;
		fy = doublerx2 * y;
	}
	glEnd();
}

//mata kiri
void mata_kiri() {
	glBegin(GL_POLYGON);
	glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
	int Xc = 285, Yc = 370, Y = 20, X = 10;
	int x = 0, y = Y, ry2 = Y * Y, rx2 = X * X, doublerx2 = 2 * rx2, doublery2 = 2 * ry2;
	int pk = ry2 - rx2 * Y + (1 / 4 * ry2);
	int fx, fy;
	fx = doublery2 * x;
	fy = doublerx2 * y;
	while (fx < fy)
	{
		if (pk < 0) {
			pk = pk + fx + ry2;
			if (pk < 0) {
				x += 1;
			}
			else {
				x += 1;
				y -= 1;
			}
		}
		else
		{
			pk = pk + fx - fy + ry2;
			if (pk < 0) {
				x += 1;
			}
			else {
				x += 1;
				y -= 1;
			}
		}
		glVertex2d(Xc + x, Yc + y);
		glVertex2d(Xc - x, Yc + y);
		glVertex2d(Xc + x, Yc - y);
		glVertex2d(Xc - x, Yc - y);
		fx = doublery2 * x;
		fy = doublerx2 * y;
	}
	float x0 = x, y0 = y;
	int pk1 = ry2 * pow((x0 + 0.5), 2) + rx2 * pow((y0 - 1), 2) - (rx2 * ry2);
	if (pk1 > 0)
		y -= 1;
	else {
		x += 1;
		y -= 1;
	}
	fx = doublery2 * x;
	fy = doublerx2 * y;
	while (y != 0)
	{
		if (pk1 > 0) {
			pk1 = pk1 - fy + rx2;
			if (pk1 > 0)
				y -= 1;
			else {
				x += 1;
				y -= 1;
			}
		}
		else {
			pk1 = pk1 + fx - fy + rx2;
			if (pk1 > 0)
				y -= 1;
			else {
				x += 1;
				y -= 1;
			}
		}
		glVertex2d(Xc + x, Yc + y);
		glVertex2d(Xc - x, Yc + y);
		glVertex2d(Xc + x, Yc - y);
		glVertex2d(Xc - x, Yc - y);
		fx = doublery2 * x;
		fy = doublerx2 * y;
	}
	glEnd();
}

//bola mata kiri
void bolamata_kiri() {

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	int Xc = 287, Yc = 354, Y = 5, X = 5;
	int x = 0, y = Y, ry2 = Y * Y, rx2 = X * X, doublerx2 = 2 * rx2, doublery2 = 2 * ry2;
	int pk = ry2 - rx2 * Y + (1 / 4 * ry2);
	int fx, fy;
	fx = doublery2 * x;
	fy = doublerx2 * y;
	while (fx < fy)
	{
		if (pk < 0) {
			pk = pk + fx + ry2;
			if (pk < 0) {
				x += 1;
			}
			else {
				x += 1;
				y -= 1;
			}
		}
		else
		{
			pk = pk + fx - fy + ry2;
			if (pk < 0) {
				x += 1;
			}
			else {
				x += 1;
				y -= 1;
			}
		}
		glVertex2d(Xc + x, Yc + y);
		glVertex2d(Xc - x, Yc + y);
		glVertex2d(Xc + x, Yc - y);
		glVertex2d(Xc - x, Yc - y);
		fx = doublery2 * x;
		fy = doublerx2 * y;
	}
	float x0 = x, y0 = y;
	int pk1 = ry2 * pow((x0 + 0.5), 2) + rx2 * pow((y0 - 1), 2) - (rx2 * ry2);
	if (pk1 > 0)
		y -= 1;
	else {
		x += 1;
		y -= 1;
	}
	fx = doublery2 * x;
	fy = doublerx2 * y;
	while (y != 0)
	{
		if (pk1 > 0) {
			pk1 = pk1 - fy + rx2;
			if (pk1 > 0)
				y -= 1;
			else {
				x += 1;
				y -= 1;
			}
		}
		else {
			pk1 = pk1 + fx - fy + rx2;
			if (pk1 > 0)
				y -= 1;
			else {
				x += 1;
				y -= 1;
			}
		}
		glVertex2d(Xc + x, Yc + y);
		glVertex2d(Xc - x, Yc + y);
		glVertex2d(Xc + x, Yc - y);
		glVertex2d(Xc - x, Yc - y);
		fx = doublery2 * x;
		fy = doublerx2 * y;
	}
	glEnd();
}

//mata kanan
void mata_Kanan() {

	glBegin(GL_POLYGON);
	glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
	int Xc = 315, Yc = 370, Y = 20, X = 10;
	int x = 0, y = Y, ry2 = Y * Y, rx2 = X * X, doublerx2 = 2 * rx2, doublery2 = 2 * ry2;
	int pk = ry2 - rx2 * Y + (1 / 4 * ry2);
	int fx, fy;
	fx = doublery2 * x;
	fy = doublerx2 * y;
	while (fx < fy)
	{
		if (pk < 0) {
			pk = pk + fx + ry2;
			if (pk < 0) {
				x += 1;
			}
			else {
				x += 1;
				y -= 1;
			}
		}
		else
		{
			pk = pk + fx - fy + ry2;
			if (pk < 0) {
				x += 1;
			}
			else {
				x += 1;
				y -= 1;
			}
		}
		glVertex2d(Xc + x, Yc + y);
		glVertex2d(Xc - x, Yc + y);
		glVertex2d(Xc + x, Yc - y);
		glVertex2d(Xc - x, Yc - y);
		fx = doublery2 * x;
		fy = doublerx2 * y;
	}
	float x0 = x, y0 = y;
	int pk1 = ry2 * pow((x0 + 0.5), 2) + rx2 * pow((y0 - 1), 2) - (rx2 * ry2);
	if (pk1 > 0)
		y -= 1;
	else {
		x += 1;
		y -= 1;
	}
	fx = doublery2 * x;
	fy = doublerx2 * y;
	while (y != 0)
	{
		if (pk1 > 0) {
			pk1 = pk1 - fy + rx2;
			if (pk1 > 0)
				y -= 1;
			else {
				x += 1;
				y -= 1;
			}
		}
		else {
			pk1 = pk1 + fx - fy + rx2;
			if (pk1 > 0)
				y -= 1;
			else {
				x += 1;
				y -= 1;
			}
		}
		glVertex2d(Xc + x, Yc + y);
		glVertex2d(Xc - x, Yc + y);
		glVertex2d(Xc + x, Yc - y);
		glVertex2d(Xc - x, Yc - y);
		fx = doublery2 * x;
		fy = doublerx2 * y;
	}
	glEnd();
}

//bola mata kanan
void bolamata_kanan() {
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	int Xc = 312, Yc = 354, Y = 5, X = 5;
	int x = 0, y = Y, ry2 = Y * Y, rx2 = X * X, doublerx2 = 2 * rx2, doublery2 = 2 * ry2;
	int pk = ry2 - rx2 * Y + (1 / 4 * ry2);
	int fx, fy;
	fx = doublery2 * x;
	fy = doublerx2 * y;
	while (fx < fy)
	{
		if (pk < 0) {
			pk = pk + fx + ry2;
			if (pk < 0) {
				x += 1;
			}
			else {
				x += 1;
				y -= 1;
			}
		}
		else
		{
			pk = pk + fx - fy + ry2;
			if (pk < 0) {
				x += 1;
			}
			else {
				x += 1;
				y -= 1;
			}
		}
		glVertex2d(Xc + x, Yc + y);
		glVertex2d(Xc - x, Yc + y);
		glVertex2d(Xc + x, Yc - y);
		glVertex2d(Xc - x, Yc - y);
		fx = doublery2 * x;
		fy = doublerx2 * y;
	}
	float x0 = x, y0 = y;
	int pk1 = ry2 * pow((x0 + 0.5), 2) + rx2 * pow((y0 - 1), 2) - (rx2 * ry2);
	if (pk1 > 0)
		y -= 1;
	else {
		x += 1;
		y -= 1;
	}
	fx = doublery2 * x;
	fy = doublerx2 * y;
	while (y != 0)
	{
		if (pk1 > 0) {
			pk1 = pk1 - fy + rx2;
			if (pk1 > 0)
				y -= 1;
			else {
				x += 1;
				y -= 1;
			}
		}
		else {
			pk1 = pk1 + fx - fy + rx2;
			if (pk1 > 0)
				y -= 1;
			else {
				x += 1;
				y -= 1;
			}
		}
		glVertex2d(Xc + x, Yc + y);
		glVertex2d(Xc - x, Yc + y);
		glVertex2d(Xc + x, Yc - y);
		glVertex2d(Xc - x, Yc - y);
		fx = doublery2 * x;
		fy = doublerx2 * y;
	}
	glEnd();
}

//hidung
void hidungpangkal() {

	float radiusX, radiusY;
	int i;
	float DEG2RAD = 3.14159 / 180.0;

	glBegin(GL_POLYGON);
	glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
	double radius = 10; //Besar badan
	double ori_x = 300; // Koordinat badan x
	double ori_y = 330; // Koordinat badan y
	double pi = 3.14;
	for (int i = 0; i <= 300; i++) {
		double angle = 2 * pi * i / 300;
		double x = cos(angle) * radius;
		double y = sin(angle) * radius;
		glVertex2d(ori_x + x, ori_y + y);
	}
	glEnd();

	glPushAttrib(GL_CURRENT_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	glLineWidth(2.0);

	glBegin(GL_POINTS);
	glColor3f(0.5, 0.0, 1.0);
	glPointSize(3);
	glVertex2d(100, 200);
	glVertex2d(200, 300);
	glVertex2d(200, 300);
	glVertex2d(200, 400);
	glEnd();

	glBegin(GL_POINTS);
	glVertex2d(0, 0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	for (GLfloat i = 0; i < 360; i++)
	{
		float x = cos(i * 314 / 180.f) * 0.5;
		float y = sin(i * 314 / 180.f) * 0.5;
		glVertex2f(x, y);
	}
	glEnd();
}

//hidung kiri
void hidungkiri() {

	float radiusX, radiusY;
	int i;
	float DEG2RAD = 3.14159 / 180.0;

	glBegin(GL_POLYGON);
	glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
	double radius = 3; //Besar badan
	double ori_x = 295; // Koordinat badan x
	double ori_y = 330; // Koordinat badan y
	double pi = 3.14;
	for (int i = 0; i <= 300; i++) {
		double angle = 2 * pi * i / 300;
		double x = cos(angle) * radius;
		double y = sin(angle) * radius;
		glVertex2d(ori_x + x, ori_y + y);
	}
	glEnd();

	glPushAttrib(GL_CURRENT_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	glLineWidth(2.0);

	glBegin(GL_POINTS);
	glColor3f(0.5, 0.0, 1.0);
	glPointSize(3);
	glVertex2d(100, 200);
	glVertex2d(200, 300);
	glVertex2d(200, 300);
	glVertex2d(200, 400);
	glEnd();

	glBegin(GL_POINTS);
	glVertex2d(0, 0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	for (GLfloat i = 0; i < 360; i++)
	{
		float x = cos(i * 314 / 180.f) * 0.5;
		float y = sin(i * 314 / 180.f) * 0.5;
		glVertex2f(x, y);
	}
	glEnd();
}

//hidung kanan
void hidungkanan() {
	float radiusX, radiusY;
	int i;
	float DEG2RAD = 3.14159 / 180.0;

	glBegin(GL_POLYGON);
	glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
	double radius = 3; //Besar badan
	double ori_x = 305; // Koordinat badan x
	double ori_y = 330; // Koordinat badan y
	double pi = 3.14;
	for (int i = 0; i <= 300; i++) {
		double angle = 2 * pi * i / 300;
		double x = cos(angle) * radius;
		double y = sin(angle) * radius;
		glVertex2d(ori_x + x, ori_y + y);
	}
	glEnd();

	glPushAttrib(GL_CURRENT_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	glLineWidth(2.0);

	glBegin(GL_POINTS);
	glColor3f(0.5, 0.0, 1.0);
	glPointSize(3);
	glVertex2d(100, 200);
	glVertex2d(200, 300);
	glVertex2d(200, 300);
	glVertex2d(200, 400);
	glEnd();

	glBegin(GL_POINTS);
	glVertex2d(0, 0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	for (GLfloat i = 0; i < 360; i++)
	{
		float x = cos(i * 314 / 180.f) * 0.5;
		float y = sin(i * 314 / 180.f) * 0.5;
		glVertex2f(x, y);
	}
	glEnd();
}

//display gambar
void display() {

	garis();
	kaki();
	badan();
	kepala();
	kepala_luar();
	mata_kiri();
	bolamata_kiri();
	mata_Kanan();
	bolamata_kanan();
	hidungpangkal();
	hidungkiri();
	hidungkanan();
	mulut();

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Gambar");
	glColor3f(0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(0, 600, 0, 600);
	glutDisplayFunc(display);
	glutMainLoop();

}
