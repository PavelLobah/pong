#include "pong.h"

int main() {
  int fl = 1;
  int a = 1, b;
  while (fl) {
    menu(a);
    // dvizhenie po menu
    switch (b = getchar()) {
      case UP:
        if (a > 1) {
          a--;
        }
        menu(a);
        break;
      case DOWN:
        if (a < 4) {
          a++;
        }
        menu(a);
        break;
      case SPACE:
        menu(a);
        // vibor nuzhnogo punkta menu
        if (a == 1) {
          pvc();
        }

        if (a == 2) {
          pvp();
        }
        if (a == 3) {
          autors();
        }
        if (a == 4) {
          fl = 0;
        }
        break;
      default:
        break;
    }
  }
  return 0;
}
// otrisovka menu (v zavisimosti ot vhodyashego argimenta,
// podsvechivaetsya punkt menu)
void menu(int color) {
  for (int i = 0; i < 10; i++) {
    printf("\n");
  }
  switch (color) {
    case 1:
      printf("\t\t\t%s          Один игрок%s\n\n", GREEN, RESET);
      printf("\t\t\t          Два игрока\n\n");
      printf("\t\t\t            Авторы\n\n");
      printf("\t\t\t            Выход\n\n");
      break;
    case 2:
      printf("\t\t\t          Один игрок\n\n");
      printf("\t\t\t%s          Два игрока%s\n\n", GREEN, RESET);
      printf("\t\t\t            Авторы\n\n");
      printf("\t\t\t            Выход\n\n");
      break;
    case 3:
      printf("\t\t\t          Один игрок\n\n");
      printf("\t\t\t          Два игрока\n\n");
      printf("\t\t\t%s            Авторы%s\n\n", GREEN, RESET);
      printf("\t\t\t            Выход\n\n");

      break;
    case 4:
      printf("\t\t\t          Один игрок\n\n");
      printf("\t\t\t          Два игрока\n\n");
      printf("\t\t\t            Авторы\n\n");
      printf("\t\t\t%s            Выход%s\n\n", GREEN, RESET);
      break;
    default:
      break;
  }

  for (int i = 0; i < 10; i++) {
    printf("\n");
  }
}
// rejim 2 igroka
void pvp() {
  char a;
  int left, right, fl;
  int x, dx, y, dy;
  int scoreRightPlayer, scoreLeftPlayer;
  x = COORD_X;
  y = COORD_Y;
  dx = 1;
  dy = 1;
  fl = 1;
  left = BEGIN;
  right = BEGIN;
  scoreLeftPlayer = 0;
  scoreRightPlayer = 0;
  while (fl) {
    printf("Player 1: %s%d%s\t\t\t\t\t\t\tPlayer 2: %s%d%s\n",
           GREEN, scoreLeftPlayer, RESET, GREEN, scoreRightPlayer, RESET);
    field(left, right, x, y);
    switch (a = getchar()) {
      // dvijenie raketki levogo igroka
      case UP_FIRST:
        if (left > 1) {
          left--;
        }
        break;
      case DOWN_FIRST:
        if (left < 21) {
          left++;
        }
        break;
      // dvijenie raketki pravogo igroka
      case UP_SECOND:
        if (right > 1) {
          right--;
        }
        break;
      case DOWN_SECOND:
        if (right < 21) {
          right++;
        }
        break;
      case ESC:
        fl = 0;
        break;
    }
    // stolknovenie so stenkoi
    if (x == 0 || x == 24)
      dx = -dx;
    x += dx;
    // stolknoveni s raketkoi
    if (y == 1 && (x == left || x == left + 1 || x == left + 2)) {
      dy = -dy;
    }
    if (y == 78 && (x == right || x == right + 1 || x == right + 2)) {
      dy = -dy;
    }
    // goal (vse po mestam)
    if (y == 0 || y == 79) {
      if (y == 0) {
        scoreRightPlayer++;
        if (scoreRightPlayer == 21) {
          wins(scoreLeftPlayer, scoreRightPlayer);
          break;
        }
      }
      if (y == 79) {
        scoreLeftPlayer++;
        if (scoreLeftPlayer == 21) {
          wins(scoreLeftPlayer, scoreRightPlayer);
          break;
        }
      }
      x = COORD_X;
      y = COORD_Y;
      left = BEGIN;
      right = BEGIN;
      dy = -dy;
      dx = -dx;
    }
    y += dy;
  }
}
// rejim s PC
void pvc() {
  char a;
  int left, right, fl;
  int x, dx, y, dy;
  int scoreRightPlayer, scoreLeftPlayer;
  x = COORD_X;
  y = COORD_Y;
  dx = 1;
  dy = 1;
  fl = 1;
  left = BEGIN;
  right = BEGIN;
  scoreLeftPlayer = 0;
  scoreRightPlayer = 0;
  while (fl) {
    printf("Player 1: %s%d%s\t\t\t\t\t\t\tPlayer 2: %s%d%s\n",
           GREEN, scoreLeftPlayer, RESET, GREEN, scoreRightPlayer, RESET);
    field(left, right, x, y);
    // dvijenie raketki levogo igroka
    switch (a = getchar()) {
      case UP_FIRST:
        if (left > 1) {
          left--;
        }
        break;
      case DOWN_FIRST:
        if (left < 21) {
          left++;
        }
        break;
      case ESC:
        fl = 0;
        break;
      default:
        break;
    }
    // stolknovenie so stenkoi
    if (x == 0 || x == 24)
      dx = -dx;
    x += dx;
    // AI - menyaya znaceniya X - mojno pomenyat slojnost
    if (x > 2 && x < 22)
      right = x - 1;
    // stolknoveniya s raketkami
    if (y == 1 && (x == left || x == left + 1 || x == left + 2)) {
      dy = -dy;
    }
    if (y == 78 && (x == right || x == right + 1 || x == right + 2)) {
      dy = -dy;
    }
    // goal (vse po mestam)
    if (y == 0 || y == 79) {
      if (y == 0) {
        scoreRightPlayer++;
        if (scoreRightPlayer == 21) {
          wins(scoreLeftPlayer, scoreRightPlayer);
          break;
        }
      }
      if (y == 79) {
        scoreLeftPlayer++;
        if (scoreLeftPlayer == 21) {
          wins(scoreLeftPlayer, scoreRightPlayer);
          break;
        }
      }
      x = COORD_X;
      y = COORD_Y;
      left = BEGIN;
      right = BEGIN;
      dy = -dy;
      dx = -dx;
    }
    y += dy;
  }
}

// otrisovka polya. na vhod - koordinaty raketok i myacha
void field(int a, int b, int x, int y) {
  int i, j;
  for (i = 0; i < 25; i++) {
    for (j = 0; j < 80; j++) {
      // myach
      if (i == x && j == y) {
        printf("*");
      } else {
        // granicy polya
        if (i == 0 || i == 24) {
          printf("-");
        } else {
          // raketki
          if ((i == a || i == (a + 1) || i == (a + 2)) && j == 0) {
            printf("X");
          } else {
            if ((i == b || i == (b + 1) || i == (b + 2)) && j == 79)
              printf("X");
            else
              printf(" ");
          }
        }
      }
    }
    printf("\n");
  }
}

// otrisovkf pobedy
void wins(int left, int right) {
  char exit;
  for (int i = 0; i < 14; i++)
    printf("\n");

  printf("%s\t\t\t\t   SKORE%s\n", GREEN, RESET);
  printf("%s\t\t\t\t  %d - %d%s\n", GREEN, left, right, RESET);
  if (left > right)
    printf("%s\t\t\t     PLAYER 1 - WINS!!!%s", GREEN, RESET);
  else
    printf("%s\t\t\t     PLAYER 2 - WINS!!!%s", GREEN, RESET);
  for (int i = 0; i < 14; i++) {
    printf("\n");
  }
  // vozvrat v predydushee menu
  do {
    exit = getchar();
  } while (exit != SPACE);
}
// imena avtorov
void autors() {
  char exit;
  for (int i = 0; i < 9; i++)
    printf("\n");
  printf("\t\t\t%s*     *\t\t       *     *\n", YELLOW);
  printf("\t\t\t * * *\t\t\t* * *\n");
  for (int i = 0; i < 4; i++)
    printf("\n");
  printf("\t\t\t\t *          *\n");
  printf("\t\t\t\t  *        *\n");
  printf("\t\t\t\t   ********%s\n", RESET);
  for (int i = 0; i < 4; i++)
    printf("\n");
  printf("%sBaines Medgar\n", GREEN);
  printf("Princess Izetta%s\n", RESET);

  // vozvrat v predydushee menu
  do {
    exit = getchar();
  } while (exit != SPACE);
}
//  upravlenie
//     v menu:
//         w - UP
//         s - DOWN
//         space - ENTER
//     v igre:
//         a - UP for left player
//         z - DOWN for left player
//         k - UP for right player
//         m - DOWN for right player
//         esc - quit
