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

        cout<<"��Ҫ����Ϸ��Y/N��?"<<endl;
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
                    cout<<"��������²�����֣�"<<endl;
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
                    cout<<"��ϲ����¶���"<<endl;
                    break;
                }
                else cout<<A<<"A"<<B<<"B"<<endl;
            }

            if (counter == 7)
            {
                ++loss;
                cout<<"���ź�����û���ڹ涨�����ڲ¶ԡ����� ";
                for (i = 0; i < 3; ++i ) cout<<key[i];
                cout<<endl;
            }

        }
        else
        {
            cout<<"��һ������"<<win + loss<<"�֣�Ӯ��"<<win<<"�֣�����"<<loss<<"��";
            break;
        }
    }
}
