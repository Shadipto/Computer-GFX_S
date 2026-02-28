# OpenGL Shapes Template

A beginner-friendly OpenGL/GLUT template for 2D drawing in C++. Comes with ready-to-use shape functions, 1100+ named colors, and automatic aspect ratio correction.

---

## File Structure

```
myCode/
├── include/
│   ├── header.h      — all #includes (OpenGL, GLUT, std libraries)
│   ├── shapes.h      — all shape drawing functions
│   ├── colors.h      — 1100+ named color macros
│   └── reshape.h     — window resize / aspect ratio handler
├── main.cpp          — your drawing code goes here
└── Makefile
```

---

## How to Build & Run

```bash
# macOS
clang++ -o main main.cpp -framework OpenGL -framework GLUT && ./main

# Linux
g++ -o main main.cpp -lGL -lGLUT -lGLU && ./main

# or just use make
make
```

---

## Coordinate System

The world space runs from **-1 to 1** on both axes for a square window. The `reshape.h` handler automatically expands the range on the longer axis for rectangular windows so shapes never look stretched.

```
                  y = 1.0
                    |
        (-1, 0) ----+---- (1, 0)
                    |
                  y = -1.0
```

For example, a **1200×600** window gives:
- x range: `-2.0 to 2.0`
- y range: `-1.0 to 1.0`

---

## Shapes Reference

All functions are in `include/shapes.h`. Every shape has a filled version and most have an outline version too.

### Circle
```cpp
circleFan(centerX, centerY, radius);            // filled circle
circleOutline(centerX, centerY, radius);         // outline only
circleArc(centerX, centerY, radius, startAngle, endAngle); // partial arc in degrees
```

### Ellipse
```cpp
ellipse(centerX, centerY, radiusX, radiusY);     // filled ellipse
ellipseOutline(centerX, centerY, radiusX, radiusY);
```

### Ring / Donut
```cpp
ring(centerX, centerY, innerRadius, outerRadius);
```

### Triangle
```cpp
triangle(x1,y1, x2,y2, x3,y3);                  // filled, 3 corners
triangleOutline(x1,y1, x2,y2, x3,y3);
equilateralTriangle(centerX, centerY, size);      // equal sides, given center
```

### Rectangle
```cpp
rectangle(x1,y1, x2,y2, x3,y3, x4,y4);          // filled, 4 corners
rectangleWH(x, y, width, height);                 // filled, top-left + size
rectangleOutline(x, y, width, height);
```

### Square
```cpp
square(x1,y1, x2,y2, x3,y3, x4,y4);             // filled, 4 corners
squareSize(centerX, centerY, size);               // filled, center + size
squareOutline(centerX, centerY, size);
```

### Polygon
```cpp
polygon(centerX, centerY, radius, sides);         // any regular polygon
polygonOutline(centerX, centerY, radius, sides);

// examples
polygon(0, 0, 0.3, 6);   // hexagon
polygon(0, 0, 0.3, 8);   // octagon
polygon(0, 0, 0.3, 3);   // triangle
```

### Star
```cpp
star(centerX, centerY, outerRadius, innerRadius, points); // default 5 points
```

### Line
```cpp
line(x1, y1, x2, y2);
thickLine(x1, y1, x2, y2, width);
```

### Point
```cpp
point(x, y);
bigPoint(x, y, size);
```

### Arrow
```cpp
arrow(centerX, centerY, size);    // points right
```

---

## Colors Reference

All colors are in `include/colors.h`. They work as macros that expand into `R, G, B` values.

```cpp
glColor3ub(RED);
glColor3ub(FOREST_GREEN);
glColor3ub(ROYAL_BLUE);
glColor3ub(GOLD);
```

You can also use raw RGB values directly:
```cpp
glColor3ub(255, 128, 0);   // any custom color
```

### Color Categories
| Category | Examples |
|---|---|
| Basics | `RED` `GREEN` `BLUE` `WHITE` `BLACK` `YELLOW` `CYAN` `MAGENTA` |
| Reds | `CRIMSON` `FIREBRICK` `TOMATO` `CORAL` `SALMON` |
| Oranges | `ORANGE` `DARK_ORANGE` `AMBER` `TANGERINE` |
| Yellows | `GOLD` `MUSTARD` `SUNFLOWER` `HONEY` |
| Greens | `FOREST_GREEN` `LIME_GREEN` `OLIVE` `EMERALD` `SAGE` |
| Blues | `NAVY` `ROYAL_BLUE` `COBALT` `DODGER_BLUE` `STEEL_BLUE` |
| Purples | `PURPLE` `VIOLET` `LAVENDER` `INDIGO` `AMETHYST` |
| Pinks | `HOT_PINK` `DEEP_PINK` `ROSE` `FLAMINGO` |
| Browns | `BROWN` `CHOCOLATE` `COFFEE` `SIENNA` `TAN` |
| Grays | `GRAY` `SILVER` `CHARCOAL` `SLATE_GRAY` |
| Neons | `NEON_GREEN` `NEON_PINK` `ELECTRIC_BLUE` `LASER_LEMON` |
| Pastels | `PASTEL_RED` `PASTEL_BLUE` `BABY_PINK` `LAVENDER` |
| Metallics | `GOLD_METALLIC` `BRONZE` `COPPER` `GUNMETAL` |
| Material Design | `RED_100` → `RED_900`, `BLUE_100` → `BLUE_900`, etc. |
| Nature | `OCEAN` `FOREST` `SAND` `GLACIER` `VOLCANIC` |
| Food | `ESPRESSO` `LATTE` `MANGO` `BLUEBERRY` `AVOCADO` |
| Pantone | `PANTONE_CLASSIC_BLUE` `PANTONE_LIVING_CORAL` etc. |
| Crayon | `CRAYON_RED` `CRAYON_CERULEAN` `CRAYON_DANDELION` etc. |

> Total: **1100+** named colors

---

## Basic Usage Template

```cpp
#include "include/header.h"
#include "include/colors.h"
#include "include/shapes.h"
#include "include/reshape.h"

#define float double

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // set color then draw shape
    glColor3ub(ROYAL_BLUE);
    circleFan(0.0, 0.0, 0.3);

    glColor3ub(FOREST_GREEN);
    rectangle(-0.5, 0.5, 0.5, 0.5, 0.5, -0.5, -0.5, -0.5);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("My Window");
    glClearColor(1.0, 1.0, 1.0, 1.0); // white background
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
```

---

## Notes

- `#define float double` is used after all includes so you don't need to add `f` suffix to every literal (e.g. `0.5` instead of `0.5f`). Keep it after your `#include` lines or it will break the OpenGL headers.
- `glutReshapeFunc(reshape)` must be registered in `main` for aspect ratio correction to work.
- All shape functions use `glVertex2d` (double precision) internally.
- Color macros expand to 3 comma-separated values, so `glColor3ub(RED)` becomes `glColor3ub(255, 0, 0)`.
