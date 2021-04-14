// c++ hangman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>;
#include "wordsList.h";
#include <string>;

using namespace std;

string getRandomWord() {
    int length = size(Words);
    srand((int)time(0));
    string randomWord = Words[rand() % length];
    
    return(randomWord);
}
bool checkGuess(string guess, string randomWord) {
    if (guess == randomWord) {
        cout << "Well Done! \n";
        return true;
    }
    else {
        int correctLetters = 0;
        int correctPosition = 0;
        for (int i = 0; i < guess.length(); i++) {
            for (int x = 0; x < randomWord.length(); x++) {
                if (guess[i] == randomWord[x] && i==x) {
                    correctPosition += 1;
                }
                else if (guess[i] == randomWord[x]) {
                    correctLetters += 1;
                }
            }
        }
        cout << "Letters in correct position : " << correctPosition << " \nCorrect letters in wrong position : " << correctLetters << "\n";
        
        return false;
    }
}
void playGame() {
    string randomWord = getRandomWord();
    string guess;
    bool correct = false;
    int wordLength = randomWord.length();
    cout << "\nWord is " << wordLength << " characters long and does not repeat any letters\n";
    while (correct == false) {
        cout << "Type your guess \n";
        cin >> guess;
        cout << "Your Guess : " << guess << "\n";
        for (int i = 0; i < guess.length(); i++) {
            guess[i] = tolower(guess[i]);
        }
       correct = checkGuess(guess, randomWord);
    }
    playGame();
}
void main()
{

    playGame();
    
    
}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
