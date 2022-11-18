#include <stdio.h>
// klavishi upravleniya raketkami
#define UP_FIRST 97
#define DOWN_FIRST 122
#define UP_SECOND 107
#define DOWN_SECOND 109
#define ESC 27
#define UP 119
#define DOWN 115
#define SPACE 32
// nachalnye koordinaty myacha i raketok
#define COORD_X 13
#define COORD_Y 40
#define BEGIN 12
// cveta teksta
#define YELLOW "\e[0;33m"
#define GREEN "\e[0;32m"
#define RED "\e[0;31m"
#define RESET "\033[0m"

void field(int, int, int, int);
void wins(int, int);
void pvp();
void pvc();
void menu(int);
void autors();