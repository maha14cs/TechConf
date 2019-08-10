#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
   int score;
    score = 0;

    enum fields {WORD, HINT, NUM_FIELDS};
    const int NUM_WORDS = 5;
    const string WORDS[NUM_WORDS][NUM_FIELDS] =
    {
          {"wall", "Do you feel like banging your head against something?"},
          {"glasses", "These might help you see the answer" },
          {"labored", "Going slowly, is it?" },
          {"persistent", "keep at it"},
          {"jumble", "It's what the game is all about!",}
    };

    srand(time(0));

    int choice = (rand() % NUM_WORDS);
    string theWord = WORDS[choice][WORD]; //word to guess
    string theHint = WORDS[choice][HINT]; //hint

    //to jumble the word

    string jumble = theWord; //jumbled version of the word
    int length = jumble.size();
    for (int i = 0; i < length; ++i)
    {
       int index1 = (rand() % length);
       int index2 = (rand() % length);
       char temp = jumble[index1];
       jumble[index1] = jumble[index2];
       jumble[index2] = temp;
       score = length;   // score based on the length of the word


    }

    // welcome the player

    cout << "\t\tWelcome to JumbleWord\n\n";
    cout << "Unscarmble the letters to make a word.\n";
    cout << "Enter 'hint' for a hint.\n";
    cout << "Enter 'quit' to quit the game\n\n";
    cout << "The jumble is " << jumble;

    string guess;
    cout <<"\n\nYour guess: ";
    cin >> guess;

    //entering the game loop

    while ((guess != theWord) && ( guess != "quit"))
    {

          if (guess == "hint")
             cout << theHint;



          else
              cout << "Sorry that is not it...";
              --score;  //subtracts points for hint or if you guess wrong

    cout << "\n\nYour guess: ";
    cin >> guess;

    }

    if (guess == theWord)
       cout << "\nThat's it! You guessed it! You have a score of " << score << endl;

       cout << "\nThanks for playing!\n";


    system("pause");

    return 0;
    }
