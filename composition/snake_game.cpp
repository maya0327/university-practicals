#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

// Function prototypes
void Setup();
void Draw();
void Input();
void Logic();
void PlaceFruit();

void Setup() {
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    nTail = 0;
    score = 0;
    srand(time(0)); // Initialize random seed
    PlaceFruit();   // Place the first fruit
}

void PlaceFruit() {
    while (true) {
        fruitX = rand() % width;
        fruitY = rand() % height;

        // Ensure fruit doesn't spawn on the snake's body
        bool onSnake = false;
        for (int i = 0; i < nTail; i++) {
            if (tailX[i] == fruitX && tailY[i] == fruitY) {
                onSnake = true;
                break;
            }
        }

        if (!onSnake && !(fruitX == x && fruitY == y)) {
            break; // Valid position for fruit
        }
    }
}

void Draw() {
    system("cls"); // Clear the screen

    // Top border
    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) // Left border
                cout << "#";

            if (i == y && j == x) // Snake's head
                cout << "O";
            else if (i == fruitY && j == fruitX) // Fruit
                cout << "F";
            else {
                bool print = false;
                for (int k = 0; k < nTail; k++) { // Snake's body
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o";
                        print = true;
                        break;
                    }
                }
                if (!print)
                    cout << " "; // Empty space
            }

            if (j == width - 1) // Right border
                cout << "#";
        }
        cout << endl;
    }

    // Bottom border
    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;

    // Score display
    cout << "Score: " << score << endl;
    cout << "Controls: W = UP, S = DOWN, A = LEFT, D = RIGHT, X = EXIT\n";
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            if (dir != RIGHT) dir = LEFT;
            break;
        case 'd':
            if (dir != LEFT) dir = RIGHT;
            break;
        case 'w':
            if (dir != DOWN) dir = UP;
            break;
        case 's':
            if (dir != UP) dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void Logic() {
    // Move the tail
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    // Update head position based on direction
    switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    // Handle wall collision (wrap around the screen)
    if (x >= width) x = 0;
    else if (x < 0) x = width - 1;
    if (y >= height) y = 0;
    else if (y < 0) y = height - 1;

    // Check collision with the tail
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y) {
            gameOver = true;
        }
    }

    // Check collision with the fruit
    if (x == fruitX && y == fruitY) {
        score += 10;
        nTail++;
        PlaceFruit(); // Reposition the fruit
    }
}

int main() {
    Setup(); // Initialize the game
    while (!gameOver) {
        Draw();  // Render the game
        Input(); // Handle user input
        Logic(); // Update game logic
        Sleep(100); // Delay for game speed (100ms)
    }

    // Game Over Message
    system("cls");
    cout << "Game Over!" << endl;
    cout << "Final Score: " << score << endl;

    return 0;
}


/*---

Features and Fixes Added

1. Tail Movement: Properly shifts each segment of the tail as the snake moves.


2. Fruit Placement: Ensures the fruit does not spawn on the snake's body.


3. Wall Wrapping: Allows the snake to reappear from the opposite edge when it moves beyond the screen boundaries.


4. Game Over Logic: Ends the game if the snake's head collides with its tail.


5. Improved User Interface: Displays controls and scores, and clears the screen between frames for smooth gameplay.


6. Game Speed Control: Adjusted using Sleep(100).




---

How to Run the Game

1. Copy and paste the code into any C++ compiler or IDE (e.g., Code::Blocks, Visual Studio, or Dev-C++).


2. Compile and run the program.


3. Use the following controls to play:

W: Move up

S: Move down

A: Move left

D: Move right

X: Exit the game



4. Enjoy the game! The score will increase by 10 points every time the snake eats the fruit.*/
