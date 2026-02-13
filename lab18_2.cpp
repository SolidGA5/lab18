#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *R1,Rect *R2){
	double Sx,Sy;
if (R1->x > R2->x){
		Rect *Temp = R1;
		R1 = R2;
		R2 = Temp;
	}
	if (R1->x <= R2->x){
		if (R1->x+R1->w >= R2->x){
			Sx = R1->w-abs(R2->x-R1->x);
		}else{return 0;}
		if (R1->x+R1->w > R2->x+R2->w){
			Sx -= (R1->x+R1->w-R2->x-R2->w);
		}
	}
	if (R1->y < R2->y){
		Rect *Temp = R1;
		R1 = R2;
		R2 = Temp;
	}
	if (R1->y >= R2->y){
		if (R1->y-R1->h <= R2->y){
			Sy = R1->h-abs(R2->y-R1->y);
		}else{return 0;}
		if (R1->y-R1->h < R2->y-R2->h){
			Sy -= (abs(R1->y-R1->h)-abs(R2->y-R2->h));
		}

	}
	return Sy*Sx;
}
