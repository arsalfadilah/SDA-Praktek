#include <stdio.h>
#include "point.h"
#include <math.h>
#include "boolean.h"

int main (){
	int X, Y;
	POINT P;
	int kuadran = 0;
	int N;

	scanf ("%d %d", &X, &Y);
	MakePoint(&P, X, Y);
	kuadran = Kuadran(P);

    PrintPoint(P);
    printf("\n");
	switch(kuadran){
		case 1 :
			NextX (&P);PrintPoint(P);
			break;

		case 2 :
			PrevX(&P);PrintPoint(P);
			break;

		case 3 :
			scanf ("%d", &N);PrintPoint(P);
			PrevX_N(&P, N);PrintPoint(P);
			break;

		case 4 :
			scanf ("%d", &N);
			NextX_N(&P, N);PrintPoint(P);
			break;

		default :
			if (IsOrigin(P)) printf("Titik Origin");
			else if (IsOnSumbuX(P)) printf("Titik berada pada sumbu X");
			else if (IsOnSumbuY(P)) printf("Titik berada pada sumbu Y");
	}
}
