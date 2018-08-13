#include <stdio.h>
#include <unistd.h>

int main(void) 
{
    int i;
    int j;

    char arr[9][27] = {
    "............ooo............",
    "....o....o.................", 
    ".....ooo....o...oo........", 
    "ooo.............oo.........", 
    "....o...........oo..o......", 
    ".......ooooo...o.......o...", 
    ".oo........................", 
    "......o....................", 
    "..o.......o................"
    };
    i = 0;
    j = 0;
    for(i = 0 ; i < 9 ; i++){
    for(j = 0 ; j < 27 ; j++){
        printf("%c", arr[i][j]);
    }
    printf("\n");
    }
//===
    int linenumber; //行數
    int biggestsofar; //目前找到最大的
    int obstacle;
    int pointX; //目前找到最大的點x值
    int pointY; //目前找到最大的點y值
    int x;
    int y;
    int testbiggest;
    int testx;
    int testy;

    linenumber = 9;
    biggestsofar = 0;
    obstacle = 0;
    pointX = 0;
    pointY = 0;
    x = 0;
    while (x < (linenumber - biggestsofar))
    {
        y = 0;
        while (y < (27 - biggestsofar))
        {
            testbiggest = (linenumber - x);
            while (testbiggest > biggestsofar)
            {
                obstacle = 0;
                testx = 0;
                while (testx < testbiggest)
                {
                    testy = 0 ;
                    while (testy < testbiggest)
                    {
                        if (arr[x + testx][y + testy] == 'o')
                        {
                            obstacle = 1;
                            break;
                        }
                        testy++;
                    }
                    if (obstacle == 1)
                    {
                        break;
                    }
                    testx++;
                }
                if (obstacle == 0)
                {
                    pointX = x;
                    pointY = y;
                    biggestsofar = testbiggest;
                    break;
                }
                testbiggest--;
            }
            y++;
        }
        x++;
    }
//===
    printf("%d\n", biggestsofar);
    printf("[%d, %d]\n", pointX, pointY);
//===
    int a;
    int b;

    a = pointX;
    while (a < pointX + biggestsofar)
    {
        b = pointY;
        while (b < (pointY + biggestsofar))
        {
            arr[a][b] = 'x';
            b++;
        }
        a++;
    }
//===
    i = 0;
    while (i < 9)
    {
        j = 0;
        while (j < 27)
        {
            printf("%c", arr[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}