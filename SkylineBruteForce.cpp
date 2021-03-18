/* To check your skyline, please make sure the array has
your elements and the structure building is in order X, y, h 
i,e. left x-coordinate, right x-coordinate and height*/

#include<bits/stdc++.h>
using namespace std;

struct building
{
    int x;
    int y;
    int h;
};

struct building records[] = {
    {31, 41, 5},
    {4, 9, 21},
    {30, 36, 9},
    {14, 18, 11},
    {2, 12, 14},
    {34, 43, 19},
    {23, 25, 8},
    {14, 21, 16},
    {32, 37, 12},
    {7, 16, 7},
    {24, 27, 10}
};

struct skyline
{
    int x;
    int h;
};

vector<struct skyline> sk;

void sort_records(int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        bool swaped = false;
        for (int j = 0 ; j < size-i-1 ; j++)
        {
            if(records[j].x > records[j+1].x)
            {
                int xTemp, yTemp, hTemp;
                xTemp = records[j].x;
                yTemp = records[j].y;
                hTemp = records[j].h;
                records[j].x = records[j+1].x;
                records[j].y = records[j+1].y;
                records[j].h = records[j+1].h;
                records[j+1].x = xTemp;
                records[j+1].y = yTemp;
                records[j+1].h = hTemp;
                swaped = true;
            }
        }
        if(!swaped)
            break;
    }
}

void print_records(int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "{ " << records[i].x;
        cout << ", " << records[i].y;
        cout << ", " << records[i].h << " }" << endl;
    }
    
}

void generate_skyline(int size)
{
    int prev = 0, rm = 0;
    int auxH[1000] = {0};
    for(int i = 0 ; i < size ; i++ )
    {
        for(int j = records[i].x ; j < records[i].y ; j++)
        {
            if(auxH[j] < records[i].h)
            {
                auxH[j] = records[i].h;
                if(rm < records[i].y)
                rm = records[i].y;
            }
        }
    }
    for(int i = 1 ; i < rm ; i++)
    {
        if(prev != auxH[i])
        {
            sk.push_back({i, auxH[i]});
            prev = auxH[i];
        }
    }
    sk.push_back({rm, 0});
}

int main()
{
    int size = sizeof(records)/sizeof(records[0]), i;
    cout << "Before Sorting : " << endl;
    print_records(size);
    for(i = 0 ; i < 2 ; i++)
        cout << "---------------------------------------------------------------------------" << endl;
    sort_records(size);
    cout << "After Sorting : " << endl;
    print_records(size);
    for(i = 0 ; i < 2 ; i++)
        cout << "---------------------------------------------------------------------------" << endl;
    generate_skyline(size);
    cout << "Skyline is :" << endl;
    if( sk[0].x != 0 )
        cout << "( 0, 0 ), " ;

    for(i = 0; i < sk.size()-1 ; i++)
    {
        if((i+1)%5 == 0)
            cout << endl;
        cout << "(" << sk[i].x << ", " << sk[i].h << "), ";
    }
    cout << "(" << sk[i].x << ", " << sk[i].h << ") END." << endl;
    return 0;
}
/*
33 41 5
4 9 21
30 36 9
14 18 11
2 12 14
34 43 19
23 25 8
14 21 16
32 37 12
7 16 7
24 27 10
*/
/*
Skyline is :

(2, 14), (4, 21), (9, 14), (12, 7), (14, 16), 
(21, 0), (23, 8), (24, 10), (27, 0), (30, 9), 
(32, 12), (34, 19), (43, 0), (43, 0) END.
*/

/*THIS FILE IS CREATED BY BRIJESH ROHIT (4birju7)*/
