/* To check your skyline, please make sure the array has
your elements and the structure building is in order X, y, h 
i,e. left x-coordinate, right x-coordinate and height*/

#include <bits/stdc++.h>
using namespace std;

struct building{
	int x;
	int y;
	int h;
};

struct bounPoint{
	int x;
	int y;
};

vector<struct building> records{
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

vector<struct bounPoint> skyBoun;

vector<struct bounPoint> merge(vector<struct bounPoint> sky_l,vector<struct bounPoint> sky_h)
{
	int h_l = 0 , h_h = 0;
	int ind = 0;
	int i = 0, j = 0;
	vector<struct bounPoint> skyline_merged;
	while(i<sky_l.size()&&j<sky_h.size())
	{
		if(sky_l.empty() || sky_h.empty())
			break;
		struct bounPoint temp;
		if(sky_l[i].x < sky_h[j].x)
		{
			temp.x = sky_l[i].x;
			temp.y = sky_l[i].y;

			if(sky_l[i].y < h_h)
				temp.y = h_h;

			h_l = sky_l[i].y;
			i++;
		}

		else if(sky_l[i].x > sky_h[j].x)
		{
			temp.x = sky_h[j].x;
			temp.y = sky_h[j].y;

			if(sky_h[j].y < h_l)
				temp.y = h_l;

			h_h = sky_h[j].y;
			j++;
		}

		else
		{
			temp.x=sky_h[j].x;
			temp.y=max(sky_l[i].y,sky_h[j].y);
			h_l=sky_l[i].y;
			h_h=sky_h[j].y;
			i++;
			j++;
		}

		skyline_merged.push_back(temp);
	}

	if(i >= sky_l.size())
	{
		while(j < sky_h.size())
		{
			skyline_merged.push_back(sky_h[j]);
			j++;
		}
	}
	if(j >= sky_h.size())
	{
		while(i < sky_l.size())
		{
			skyline_merged.push_back(sky_l[i]);
			i++;
		}
	}

	int inx = 1;
	vector<int> redun;
    redun.push_back(0);
	while(inx < skyline_merged.size())
	{
		if(skyline_merged[inx].y == skyline_merged[inx-1].y)
			redun.push_back(1);
		else
			redun.push_back(0);
		inx++;
	}
	for(i = 0 ; i < redun.size() ; i++)
	{
		if(redun[i] == 1)
			skyline_merged[i].x = -1;
	}
	return skyline_merged;
}

vector<struct bounPoint> skyline(int l,int h,vector<struct building> sky1)
{
	vector<struct bounPoint> skyvec;
	if(l>h)
		return skyvec;
	else if(l == h)
	{
		struct bounPoint p = {sky1[l].x,sky1[l].h};
		skyvec.push_back(p);
		p.x = sky1[l].y;
		p.y = 0;
		skyvec.push_back(p);
		return skyvec;
	}
	else
	{
		int mid = l + ((h-l)/2);
		vector<struct bounPoint> sky_l = skyline(l, mid, sky1);
		vector<struct bounPoint> sky_h = skyline(mid+1, h, sky1);

		return merge(sky_l, sky_h);
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

int main()
{
	skyBoun = skyline(0, records.size()-1, records);
	skyBoun.insert(skyBoun.begin(), {0,0});

    cout << endl << "Skyline is :"  << endl;

	for(int count = 0, i = 0 ; i < skyBoun.size() ; i++)
	{
		if(skyBoun[i].x != -1)
		{
            if(count%5 == 0)
            cout << endl;
			cout<<"("<<skyBoun[i].x<<", "<<skyBoun[i].y<<"), ";
            count++;
		}
	}
    cout << "END." << endl << endl;
	return 0;
}

/*THIS FILE IS CREATED BY BRIJESH ROHIT (4birju7)*/
