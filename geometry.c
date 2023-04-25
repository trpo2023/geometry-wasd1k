#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

struct Point {
    float x;
    float y;
};

struct WKTcircle {
    struct Point point;
    float number;
};

int main()
{
    FILE* myfile = fopen("test.txt", "r");
    if (!myfile) {
        puts("Failed to open file.");
        return 0;
    }
    char* type;
    char line[MAX_LEN];
    char line1[MAX_LEN];
    struct WKTcircle c1;
    while ((fgets(line, MAX_LEN, myfile)) != 0) {
        strcpy(line1, line);
        type = strtok(line1, "(");
        if (strcmp(type, "circle") == 0) {
            if ((sscanf(line,
                        "circle(%f %f, %f)",
                        &c1.point.x,
                        &c1.point.y,
                        &c1.number))
                == 3)
                printf("circle(%f %f, %f) \n",
                       c1.point.x,
                       c1.point.y,
                       c1.number);
            else {
                puts(line);
                printf("Incorrect data of points of circle. Expected NUM NUM, "
                       "NUM \n");
            }
        } else {
            puts(line);
            printf("Incorrect type of figure format. Expected: \"circle\" \n");
        }
    }
    return 0;
}
