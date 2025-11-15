#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <time.h>
#define MINX 2
#define MINY 2
#define MAXX 35
#define MAXY 20
using namespace std;
void gotoxy(int column, int line);
struct Point {
    int x, y;
};
class CONRAN {
public:
    struct Point A[100];
    int DoDai;
    CONRAN() {
        DoDai = 3;
        A[0].x = 10; A[0].y = 10;
        A[1].x = 11; A[1].y = 10;
        A[2].x = 12; A[2].y = 10;
    }
    void Ve(Point Qua) {
        for (int i = 0; i < DoDai; i++) {
            gotoxy(A[i].x, A[i].y);
            cout << "X";
        }
        gotoxy(Qua.x, Qua.y); cout << "*";
    }
    void DiChuyen(int &Huong, Point& Qua) {
        
        for (int i = DoDai - 1; i > 0; i--)
            A[i] = A[i - 1];

        int newX = A[0].x;
        int newY = A[0].y;

     
        if (Huong == 0) newX++;
        if (Huong == 1) newY++;
        if (Huong == 2) newX--;
        if (Huong == 3) newY--;

       
        if (newX <= MINX || newX >= MAXX || newY <= MINY || newY >= MAXY) {

            if (Huong == 0) Huong = 2;
            else if (Huong == 2) Huong = 0;
            else if (Huong == 1) Huong = 3;
            else if (Huong == 3) Huong = 1;

            
            newX = A[0].x;
            newY = A[0].y;

            if (Huong == 0) newX++;
            if (Huong == 1) newY++;
            if (Huong == 2) newX--;
            if (Huong == 3) newY--;
        }

       
        A[0].x = newX;
        A[0].y = newY;

       
        if (A[0].x == Qua.x && A[0].y == Qua.y) {
            DoDai++;
            Qua.x = rand() % (MAXX - MINX) + MINX;
            Qua.y = rand() % (MAXY - MINY) + MINY;
        }
    }
};


