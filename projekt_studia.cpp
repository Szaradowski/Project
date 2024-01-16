#include <iostream>
#include <cstdlib>
#include <ctime>

void printMaze(char** maze, int x, int y) {
    system("cls"); // Dla systemów Unix; na Windows u¿yj system("cls");
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            std::cout << maze[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

int main() {
    int x, y;

    std::cout << "Podaj liczbe wierszy (x): ";
    std::cin >> x;
    std::cout << "Podaj liczbe kolumn (y): ";
    std::cin >> y;

    srand(time(NULL));

    int s_x = rand() % x;
    int s_y = rand() % y;
    int m_x, m_y;
    do {
        m_x = rand() % x;
        m_y = rand() % y;
    } while (s_x == m_x && s_y == m_y);

    char** maze = new char*[x];
    for (int i = 0; i < x; ++i) {
        maze[i] = new char[y];
        for (int j = 0; j < y; ++j) {
            maze[i][j] = 'X';
        }
    }

    maze[s_x][s_y] = 'S';
    maze[m_x][m_y] = 'M';

    char input;
    while (true) {
        printMaze(maze, x, y);
        std::cout << "Ruch (w, s, a, d), q aby wyjsc: ";
        std::cin >> input;

        if (input == 'q') {
            break;
        }

        int new_x = s_x, new_y = s_y;
        if (input == 'w' && s_x > 0) new_x--;
        else if (input == 's' && s_x < x - 1) new_x++;
		    else if (input == 'a' && s_y > 0) new_y--;
    else if (input == 'd' && s_y < y - 1) new_y++;

    if (new_x == m_x && new_y == m_y) {
        std::cout << "Gratulacje, wyszed³eœ z labiryntu!" << std::endl;
        break;
    }

    if (new_x != s_x || new_y != s_y) {
        maze[s_x][s_y] = 'X';
        s_x = new_x;
        s_y = new_y;
        maze[s_x][s_y] = 'S';
    }
}

return 0;
}
