//Filename NumGuess
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string.h>
using namespace std;


int main(){
 char choice, answer1, answer2, answer3;
 int counter, i, j, A, B, win = 0, loss = 0;
 string choice_cin, answer_cin;

    while (1)
    {
        srand(time(NULL));
        int key[3] = {rand() * 10 / (RAND_MAX + 1), rand() * 10 / (RAND_MAX + 1), rand() * 10 / (RAND_MAX + 1)};
        if ((key[0] == key[1])||(key[0] == key[2])||(key[2] == key[1])) continue;
        //make sure the three numbers are different

        cout<<"需要玩游戏吗（Y/N）?"<<endl;
        cin>>choice_cin;
        if (choice_cin.size() != 1) continue;
        choice = toupper(choice_cin[0]);
        if ((choice != 'Y')&&(choice != 'N')) continue; //make sure the choice can only be {y,n,Y,N}

        if (choice == 'Y')
        {
            for (counter = 0; counter < 7; ++counter)
            {
                A = 0;
                B = 0;

                while (1)
                {
                    cout<<"请输入你猜测的数字："<<endl;
                    cin>>answer_cin;
                    answer1 = answer_cin[0];
                    answer2 = answer_cin[1];
                    answer3 = answer_cin[2];
                    if ((answer_cin.size() == 3)&&(answer1 >= '0')&&(answer1 <= '9')&&
                        (answer2 >= '0')&&(answer2 <= '9')&&(answer3 >= '0')&&(answer3 <= '9'))
                        //make sure the input can only be three numbers
                        break;
                }
                int answer[3] = {answer1 - '0', answer2 - '0', answer3 - '0'}; //change it form char to int

                for (j = 0; j < 3; ++j )
                {
                    for (i = 0; i < 3; ++i)
                    {
                        if ((i == j)&&(key[i] == answer[j])) ++A;
                        else
                            if (key[i] == answer[j]) ++B; //compare answer and key to get A B
                    }
                }
                if (A == 3)
                {
                    ++win;
                    cout<<"恭喜，你猜对了"<<endl;
                    break;
                }
                else cout<<A<<"A"<<B<<"B"<<endl;
            }

            if (counter == 7)
            {
                ++loss;
                cout<<"很遗憾，你没有在规定次数内猜对。答案是 ";
                for (i = 0; i < 3; ++i ) cout<<key[i];
                cout<<endl;
            }

        }
        else
        {
            cout<<"你一共玩了"<<win + loss<<"局，赢了"<<win<<"局，输了"<<loss<<"局";
            break;
        }
    }
}
