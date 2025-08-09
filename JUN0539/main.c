#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define ShapeText(TYPE) char name[10]; \
    double (*perimeter)(struct TYPE*); \
    double (*area)(struct TYPE*)

#define PI 3.14

typedef struct shape_s {
    ShapeText(shape_s);
} shape_t;

typedef struct circle_s {
    ShapeText(circle_s);
    double radius;
} circle_t;

typedef struct rectangle_s {
    ShapeText(rectangle_s);
    double length, width;
} rectangle_t;

typedef struct square_s {
    ShapeText(square_s);
    double edge;
} square_t;

typedef struct triangle_s {
    ShapeText(triangle_s);
    double a, b, c;
} triangle_t;

// Function implementations
double circle_perimeter(circle_t* c) {
    return 2 * PI * c->radius;
}

double circle_area(circle_t* c) {
    return PI * c->radius * c->radius;
}

double rectangle_perimeter(rectangle_t* r) {
    return 2 * (r->length + r->width);
}

double rectangle_area(rectangle_t* r) {
    return r->length * r->width;
}

double square_perimeter(square_t* s) {
    return 4 * s->edge;
}

double square_area(square_t* s) {
    return s->edge * s->edge;
}

double triangle_perimeter(triangle_t* t) {
    return t->a + t->b + t->c;
}

double triangle_area(triangle_t* t) {
    double s = (t->a + t->b + t->c) / 2.0;
    return sqrt(s * (s - t->a) * (s - t->b) * (s - t->c));
}

int main() {
    int n;
    scanf("%d", &n);

    shape_t* shapes[5];
    double total_perimeter = 0, total_area = 0;

    for (int i = 0; i < n; ++i) {
        char type;
        scanf(" %c", &type);

        if (type == 'C') {
            circle_t* c = malloc(sizeof(circle_t));
            scanf("%lf", &c->radius);
            strcpy(c->name, "Circle");
            c->perimeter = (double (*)(circle_t*))circle_perimeter;
            c->area = (double (*)(circle_t*))circle_area;
            shapes[i] = (shape_t*)c;
        } else if (type == 'R') {
            rectangle_t* r = malloc(sizeof(rectangle_t));
            scanf("%lf %lf", &r->length, &r->width);
            strcpy(r->name, "Rect");
            r->perimeter = (double (*)(rectangle_t*))rectangle_perimeter;
            r->area = (double (*)(rectangle_t*))rectangle_area;
            shapes[i] = (shape_t*)r;
        } else if (type == 'S') {
            square_t* s = malloc(sizeof(square_t));
            scanf("%lf", &s->edge);
            strcpy(s->name, "Square");
            s->perimeter = (double (*)(square_t*))square_perimeter;
            s->area = (double (*)(square_t*))square_area;
            shapes[i] = (shape_t*)s;
        } else if (type == 'T') {
            triangle_t* t = malloc(sizeof(triangle_t));
            scanf("%lf %lf %lf", &t->a, &t->b, &t->c);
            strcpy(t->name, "Tri");
            t->perimeter = (double (*)(triangle_t*))triangle_perimeter;
            t->area = (double (*)(triangle_t*))triangle_area;
            shapes[i] = (shape_t*)t;
        }
    }

    for (int i = 0; i < n; ++i) {
        double peri = shapes[i]->perimeter(shapes[i]);
        double a = shapes[i]->area(shapes[i]);
        total_perimeter += peri;
        total_area += a;
        printf("%.2f %.2f\n", peri, a);
        free(shapes[i]);
    }

    printf("%.2f %.2f\n", round(total_perimeter * 100) / 100, round(total_area * 100) / 100);

    return 0;
}
