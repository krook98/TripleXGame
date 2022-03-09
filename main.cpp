#include <iostream>
#include <ctime>


void PrintIntroduction(int Difficulty) {

    // Print welcome messages to the terminal
    std::cout << "\nYou're a spy in a secret laboratory. You're currently on level " << Difficulty <<"\nThe doors are locked and you need a proper combination of numbers to enter another room...\n";
    std::cout << "Enter the correct code to continue\n";
}

bool PlayGame(int Difficulty) {

    PrintIntroduction(Difficulty);

    // Declare 3 number code
    const int CodeA = rand()%(Difficulty+Difficulty);
    const int CodeB = rand()%(Difficulty+Difficulty);
    const int CodeC = rand()%(Difficulty+Difficulty);

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print sum and product to the terminal
    std::cout << "+ There are 3 numbers in the code\n";
    std::cout << "+ The code adds up to: " << CodeSum << std::endl;
    std::cout << "+ The code multiplies to give: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;

    std::cout << "You entered: " << GuessA << GuessB << GuessC << std::endl;

    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;

    // Checking if players answer is correct
    if(GuessSum == CodeSum && GuessProduct == CodeProduct) {
        std::cout << "\nWell done, you extracted the files! Keep going.\n";
        return true;
    }
    else {
        std::cout << "\nWrong code. Try again.\n";
        return false;
    }
}

int main() {

    srand(time(NULL)); // creates random sequence based on time of day

    int LevelDifficulty = 1;
    const int MaxDifficulty = 10;

    while(LevelDifficulty <= MaxDifficulty) {

        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete) {
            ++LevelDifficulty;
        }
        
    }

    std::cout << "*** Great job agent. You completed all the levels. Now get out of there! ***";
    return 0;
}