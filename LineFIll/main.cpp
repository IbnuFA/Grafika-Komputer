#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

using namespace std;

int main(void)
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(400, 400, "Hello World", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
void dda(){

    float x1, x2, y1, y2, m;
    float x3, y3;
    float x4, y4;
    float x, y;
    float steps;

    cout << "x1 = ";
    cin >> x1;
    cout << "y1 = ";
    cin >> y1;
    cout << "x2 = ";
    cin >> x2;
    cout << "y2 = ";
    cin >> y2;

    x = x1;
    y = y1;

    x3 = x2 - x1;
    y3 = y2 - y1;

    m = y3 / x3;

    cout << "\n m nya adalah " << m << endl;
    cout << endl;

    if (abs(y3) > abs(x3)) {
       steps = abs(y3);
    }
    else {
       steps = abs(x3);
    }

    x4 = x3 / steps;
    y4 = y3 / steps;

    glBegin(GL_LINES);
    glVertex2f(round(x), round(y)); // titik awal

    //looping menggambar titik-titik
    do {
       x += x4; // x = x + x_inc
       y += y4; // y = y + y_inc
       glVertex2f(round(x), round(y)); //gambar titik
    } while (x < x2);
    glEnd();
}
