#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 40
#define COLS 80

char canvas[ROWS][COLS];

// Initialize canvas with '_'
void initCanvas() {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            canvas[i][j] = '_';
}

// Display canvas
void displayCanvas() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            printf("%c", canvas[i][j]);
        printf("\n");
    }
}

// Draw a rectangle
void drawRectangle(int x, int y, int w, int h) {
    for (int i = x; i < x + h && i < ROWS; i++) {
        for (int j = y; j < y + w && j < COLS; j++) {
            if (i == x || i == x + h - 1 || j == y || j == y + w - 1)
                canvas[i][j] = '*';
        }
    }
}

// Draw a line (simple Bresenham’s algorithm)
void drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        if (x1 >= 0 && x1 < ROWS && y1 >= 0 && y1 < COLS)
            canvas[x1][y1] = '*';
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx) { err += dx; y1 += sy; }
    }
}

// Draw a circle (Midpoint circle algorithm)
void drawCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 3 - 2 * r;
    while (y >= x) {
        int points[8][2] = {
            {xc+x, yc+y}, {xc-x, yc+y}, {xc+x, yc-y}, {xc-x, yc-y},
            {xc+y, yc+x}, {xc-y, yc+x}, {xc+y, yc-x}, {xc-y, yc-x}
        };
        for (int i = 0; i < 8; i++) {
            int px = points[i][0], py = points[i][1];
            if (px >= 0 && px < ROWS && py >= 0 && py < COLS)
                canvas[px][py] = '*';
        }
        x++;
        if (d > 0) { y--; d = d + 4 * (x - y) + 10; }
        else d = d + 4 * x + 6;
    }
}

// Draw a triangle (outline)
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    drawLine(x1, y1, x2, y2);
    drawLine(x2, y2, x3, y3);
    drawLine(x3, y3, x1, y1);
}

// Clear object (delete by overwriting with '_')
void clearObject(int x, int y, int w, int h) {
    for (int i = x; i < x + h && i < ROWS; i++)
        for (int j = y; j < y + w && j < COLS; j++)
            canvas[i][j] = '_';
}

// Menu-driven interface
int main() {
    int choice;
    initCanvas();

    while (1) {
        printf("\n--- 2D Graphics Editor ---\n");
        printf("1. Draw Rectangle\n");
        printf("2. Draw Line\n");
        printf("3. Draw Circle\n");
        printf("4. Draw Triangle\n");
        printf("5. Clear Object\n");
        printf("6. Display Canvas\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 7) break;

        int x, y, w, h, r, x2, y2, x3, y3;
        switch (choice) {
            case 1:
                printf("Enter x y width height: ");
                scanf("%d %d %d %d", &x, &y, &w, &h);
                drawRectangle(x, y, w, h);
                break;
            case 2:
                printf("Enter x1 y1 x2 y2: ");
                scanf("%d %d %d %d", &x, &y, &x2, &y2);
                drawLine(x, y, x2, y2);
                break;
            case 3:
                printf("Enter center_x center_y radius: ");
                scanf("%d %d %d", &x, &y, &r);
                drawCircle(x, y, r);
                break;
            case 4:
                printf("Enter x1 y1 x2 y2 x3 y3: ");
                scanf("%d %d %d %d %d %d", &x, &y, &x2, &y2, &x3, &y3);
                drawTriangle(x, y, x2, y2, x3, y3);
                break;
            case 5:
                printf("Enter x y width height to clear: ");
                scanf("%d %d %d %d", &x, &y, &w, &h);
                clearObject(x, y, w, h);
                break;
            case 6:
                displayCanvas();
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
