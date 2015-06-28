#include "vertical.h"

Vertical::Vertical()
{

}

Vertical::~Vertical()
{

}

int Vertical::condition(Blank *a[10][10], Blank *focus)
{
    int R = focus->row;
    int C = focus->column;
    int num = focus->number;
    if(num != 0 && num != 5){
        if(num/10 == 0){
            if(R >= 2
                    && (num == a[R-2][C]->number || num == a[R-2][C]->number/10)
                    && (num == a[R-1][C]->number || num == a[R-1][C]->number/10)){
                return 1;
            }// end if
            if(R <= 7
                    && (num == a[R+1][C]->number || num == a[R+1][C]->number/10)
                    && (num == a[R+2][C]->number || num == a[R+2][C]->number/10)){
                return 2;
            }// end if
        }// end if
        if(num/10 != 0){
            if(R >= 2
                    && (num == a[R-2][C]->number || num == a[R-2][C]->number/10)
                    && (num == a[R-1][C]->number || num == a[R-1][C]->number/10)){
                return 3;
            }// end if
            if(R <= 7
                    && (num == a[R+1][C]->number || num == a[R+1][C]->number/10)
                    && (num == a[R+2][C]->number || num == a[R+2][C]->number/10)){
                return 4;
            }// end if
        }// end if
    }// end if
    return 0;
}

void Vertical::spawn(Blank *a[10][10], Blank *focus, int mode)
{
    int R = focus->row;
    int C = focus->column;
    int num = focus->number;
    int ThreeNum[3] = {0};
    switch(mode){
    case 1:
        focus->number = focus->number*10+1;
        // right one
        if(R <= 8 && num == a[R+1][C]->number || num == a[R+1][C]->number/10){
            a[R+1][C]->number = 0;
        }// end if
        // enter num into ThreeNum
        if(a[R-2][C]->number/10 != 0){
            ThreeNum[0] = a[R-2][C]->number%10;
        }// end if
        if(a[R-1][C]->number/10 != 0){
            ThreeNum[1] = a[R-1][C]->number%10;
        }// end if
        ThreeNum[2] = a[R][C]->number;

        for(int i = 0; i < 3; i++){
            Destroy *d;
            switch (ThreeNum[i]) {
            case 0:
                a[R-2+i][C]->number = 0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a, a[R-2+i][C]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a, a[R-2+i][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a, a[R-2+i][C]);
                delete d;
                break;
            }// end switch
        }// end for
        break;
    case 2:
        focus->number = focus->number*10+1;
        // right one
        if(R >= 1 && num == a[R-1][C]->number || num == a[R-1][C]->number/10){
            a[R-1][C]->number = 0;
        }// end if
        // enter num into ThreeNum
        if(a[R+2][C]->number/10 != 0){
            ThreeNum[0] = a[R+2][C]->number%10;
        }// end if
        if(a[R+1][C]->number/10 != 0){
            ThreeNum[1] = a[R+1][C]->number%10;
        }// end if
        ThreeNum[2] = a[R][C]->number;

        for(int i = 0; i < 3; i++){
            Destroy *d;
            switch (ThreeNum[i]) {
            case 0:
                a[R+2-i][C]->number = 0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a, a[R+2-i][C]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a, a[R+2-i][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a, a[R+2-i][C]);
                delete d;
                break;
            }// end switch
        }// end for
        break;
    case 3:
        num/=10;
        // right one
        if(R >= 1 && num == a[R-1][C]->number || num == a[R-1][C]->number/10){
            a[R-1][C]->number = 0;
        }// end if
        // enter num into ThreeNum
        if(a[R+2][C]->number/10 != 0){
            ThreeNum[0] = a[R+2][C]->number%10;
        }// end if
        if(a[R+1][C]->number/10 != 0){
            ThreeNum[1] = a[R+1][C]->number%10;
        }// end if
        ThreeNum[2] = a[R][C]->number%10;

        for(int i = 0; i < 3; i++){
            Destroy *d;
            switch (ThreeNum[i]) {
            case 0:
                a[R+2-i][C]->number = 0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a, a[R+2-i][C]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a, a[R+2-i][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a, a[R+2-i][C]);
                delete d;
                break;
            }// end switch
        }// end for
        break;
    case 4:
        num/=10;
        // right one
        if(R >= 1 && num == a[R-1][C]->number || num == a[R-1][C]->number/10){
            a[R-1][C]->number = 0;
        }// end if
        // enter num into ThreeNum
        if(a[R+2][C]->number/10 != 0){
            ThreeNum[0] = a[R+2][C]->number%10;
        }// end if
        if(a[R+1][C]->number/10 != 0){
            ThreeNum[1] = a[R+1][C]->number%10;
        }// end if
        ThreeNum[2] = a[R][C]->number%10;

        for(int i = 0; i < 3; i++){
            Destroy *d;
            switch (ThreeNum[i]) {
            case 0:
                a[R+2-i][C]->number = 0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a, a[R+2-i][C]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a, a[R+2-i][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a, a[R+2-i][C]);
                delete d;
                break;
            }// end switch
        }// end for
        break;
    default:
        break;
    }// end switch
}

void Vertical::eliminate(Blank *a[10][10], Blank *focus)
{
    int C = focus->column;
    focus->number = 0;
    int TenNum[10] = {0};
    Destroy *d;
    for(int i = 0; i < 10; i++){
        if(a[i][C]->number/10 != 0){
            TenNum[i] = a[i][C]->number%10;
        }// end if
    }// end for
    for(int i = 0; i < 10; i++){
        switch(TenNum[i]){
        case 0:
            a[i][C]->number = 0;
            break;
        case 1:
            d = new Vertical;
            d->eliminate(a, a[i][C]);
            delete d;
            break;
        case 2:
            d = new Horizontal;
            d->eliminate(a, a[i][C]);
            delete d;
            break;
        case 3:
            d = new NineBlock;
            d->eliminate(a, a[i][C]);
            delete d;
            break;
        }// end switch
    }// end outer for
}

