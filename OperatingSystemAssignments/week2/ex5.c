#include <stdio.h>

void rectangle(int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) printf("*");
        printf("\n");
    }
}

void pyramid(int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < height-i-1; j++) printf(" ");
        for (int j = 0; j < i*2 + 1; j++) printf("*");
        printf("\n");
    }

}

void rightTriangle(int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < i + 1; j++) printf("*");
        printf("\n");
    }
}

void rotatedTriangle(int height) {
    for(int i = 0; i < height; i++) {
        for (int j = 0; j < i + 1; j++) printf("*");
        printf("\n");
    }
    for (int i = height-1; i > 0; i--) {
        for (int j = 0; j < i; j++) printf("*");
        printf("\n");
    }
}

int main() {
    rectangle(4, 5);
    pyramid(5);
    rightTriangle(5);
    rotatedTriangle(3);
    return 0;
}