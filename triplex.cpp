#include <iostream>
#include <ctime>

void PrintIntroduction(int LevelDifficulty)
{
    std::cout << "\n\n";
    std::cout << "  _________                                 __________\n";
    std::cout << " /   _____/ ______________  __ ___________  \\______   \\ ____   ____   _____\n";
    std::cout << " \\_____  \\_/ __ \\_  __ \\  \\/ // __ \\_  __ \\  |       _//  _ \\ /  _ \\ /     \\\n";
    std::cout << " /        \\  ___/|  | \\/\\   /\\  ___/|  | \\/  |    |   (  <_> |  <_> )  Y Y  \\\n";
    std::cout << "/_______  /\\___  >__|    \\_/  \\___  >__|     |____|_  /\\____/ \\____/|__|_|  /\n";
    std::cout << "        \\/     \\/                 \\/                \\/                    \\/\n";
    std::cout << "You are a secret agent breaking into a level " << LevelDifficulty << " secure server room\n";
    std::cout << "You need to enter the correct code to continue...\n";
}

bool PlayGame(int LevelDifficulty)
{
    // Declare 3 number code
    const int CodeA = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeB = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeC = rand() % LevelDifficulty + LevelDifficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "\n+ There are three numbers in the code";
    std::cout << "\n+ The codes add up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << "\n\n";

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    return GuessSum == CodeSum && GuessProduct == CodeProduct;
}

int main()
{
    // Seed the random numbers based on the time of day
    srand(time(NULL));

    const int MaximumLevelDifficulty = 5;
    int LevelDifficulty = 1;

    while (LevelDifficulty <= MaximumLevelDifficulty)
    {
        PrintIntroduction(LevelDifficulty);
        bool bLevelComplete = PlayGame(LevelDifficulty);

        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            if (LevelDifficulty != MaximumLevelDifficulty)
            {
                std::cout << "Success, you broke in the level " << LevelDifficulty << " server room\n";
            }

            ++LevelDifficulty;
        }
        else
        {
            std::cout << "Fail, try again but don't get caught\n";
        }
    }

    std::cout << "Congratulations, you are a master hacker!\n";

    return 0;
}