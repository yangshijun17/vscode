#include <stdio.h>
#define true 1
#define boolean int
#define false 0
boolean flag[2];
int turn;
void procedure0()
{
    while (true)
    {
        flag[0] = true;
        while (flag[1] == true)
        {
            if (turn == 1)
            {
                flag[0] = false;
                while (turn == 1)
                {
                    printf("hello from 0");
                }
                flag[0] = true;
            }
        }
        /*critical section*/;
        turn = 1;
        flag[0] = false;
        /*remainder section*/
    }
}
void procedure()
{
    while (true)
    {
        flag[1] = true;
        while (flag[0] == true)
        {
            if (turn == 0)
            {
                flag[1] = false;
                while (turn == 0)
                {
                    printf("hello from 1\n");
                }
                flag[1] = true;
            }
        }
        /*critical section*/;
        turn = 0;
        flag[1] = false;
        /*remainder section*/
    }
}
int main()
{
    flag[0] = flag[1] = 0;
    turn = 1;
    procedure0(),procedure();
}