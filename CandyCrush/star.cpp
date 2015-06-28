#include "star.h"
#include <QDebug>
Star::Star()
{

}

Star::~Star()
{

}

int Star::condition(Blank *a[10][10], Blank *focus){
     int R = focus->row;
     int C = focus->column;
     int num = focus->number;
     if(num!=0 && num!=5){ // blank/star in a row doesnt count
         // focus is normal item
         if(num/10 == 0){
             // five in straight
             if(R >= 2 && R <= 7
                     // normal items             // special items
                     && (num == a[R-2][C]->number || num == a[R-2][C]->number/10)
                     && (num == a[R-1][C]->number || num == a[R-1][C]->number/10)
                     && (num == a[R+1][C]->number || num == a[R+1][C]->number/10)
                     && (num == a[R+2][C]->number || num == a[R+2][C]->number/10)){
                 return 1;
             }// end if
             // five in a row
             if(C >= 2 && C <= 7
                     // normal items             // special items
                     && (num == a[R][C-2]->number || num == a[R][C-2]->number/10)
                     && (num == a[R][C-1]->number || num == a[R][C-1]->number/10)
                     && (num == a[R][C+1]->number || num == a[R][C+1]->number/10)
                     && (num == a[R][C+2]->number || num == a[R][C+2]->number/10)){
                 return 2;
             }// end if
         }// end if
         // focus is special item
         else if(num/10 != 0){
             num /= 10;
             // five in straight
             if(R >= 2 && R <= 7
                     // normal items             // special items
                     && (num == a[R-2][C]->number || num == a[R-2][C]->number/10)
                     && (num == a[R-1][C]->number || num == a[R-1][C]->number/10)
                     && (num == a[R+1][C]->number || num == a[R+1][C]->number/10)
                     && (num == a[R+2][C]->number || num == a[R+2][C]->number/10)){
                 return 3;
             }// end if
             // five in a row
             if(C >= 2 && C <= 7
                     // normal items             // special items ex.bombs
                     && (num == a[R][C-2]->number || num == a[R][C-2]->number/10)
                     && (num == a[R][C-1]->number || num == a[R][C-1]->number/10)
                     && (num == a[R][C+1]->number || num == a[R][C+1]->number/10)
                     && (num == a[R][C+2]->number || num == a[R][C+2]->number/10)){
                 return 4;
             }// end if
         }// end else if

     }// end if
     return 0;
 }

void Star::spawn(Blank *a[10][10], Blank *focus, int mode){
    int R = focus->row;
    int C = focus->column;
    int num = focus->number;
    int FiveNum[5] = {0};
    switch(mode){
        case 1:
            focus->number = 5;
            // right
            if(C >= 2 && (num == a[R][C-2]->number || num == a[R][C-2]->number/10) && (num == a[R][C-1]->number || num == a[R][C-1]->number/10)){
                a[R][C-2]->number = 0;
                a[R][C-1]->number = 0;
            }// end if
            // left
            if(C <= 7 && (num == a[R][C+1]->number || num == a[R][C+1]->number/10) && (num == a[R][C+2]->number || num == a[R][C+2]->number/10)){
                a[R][C+1]->number = 0;
                a[R][C+2]->number = 0;
            }// end if
            if(a[R-2][C]->number/10!=0){
                FiveNum[0] = a[R-2][C]->number%10;
            }// end if
            if(a[R-1][C]->number/10!=0){
                FiveNum[1] = a[R-1][C]->number%10;
            }// end if
            FiveNum[2] = a[R][C]->number;
            if(a[R+1][C]->number/10!=0){
                FiveNum[3] = a[R+1][C]->number%10;
            }// end if
            if(a[R+2][C]->number/10!=0){
                FiveNum[4] = a[R+2][C]->number%10;
            }// end if
            for(int i = 0; i < 5; i++){
                Destroy *d;
                switch(FiveNum[i]){
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
        focus->number = 5;
        // up
        if(R >= 2 && (num == a[R-2][C]->number || num == a[R-2][C]->number/10) && (num == a[R-1][C]->number || num == a[R-1][C]->number/10)){
            a[R-2][C]->number = 0;
            a[R-1][C]->number = 0;
        }// end if
        // down
        if(R <= 7 && (num == a[R+1][C]->number || num == a[R+1][C]->number/10) && (num == a[R+2][C]->number || num == a[R+2][C]->number/10)){
            a[R+1][C]->number = 0;
            a[R+2][C]->number = 0;
        }// end if
        if(a[R][C-2]->number/10!=0){
            FiveNum[0] = a[R][C-2]->number%10;
        }// end if
        if(a[R][C-1]->number/10!=0){
            FiveNum[1] = a[R][C-1]->number%10;
        }// end if
        FiveNum[2] = a[R][C]->number;
        if(a[R][C+1]->number/10!=0){
            FiveNum[3] = a[R][C+1]->number%10;
        }// end if
        if(a[R][C+2]->number/10!=0){
            FiveNum[4] = a[R][C+2]->number%10;
        }// end if
        for(int i = 0; i < 5; i++){
            Destroy *d;
            switch(FiveNum[i]){
                case 0:
                    a[R][C-2+i]->number = 0;
                break;
                case 1:
                    d = new Vertical;
                    d->eliminate(a, a[R][C-2+i]);
                    delete d;
                break;
                case 2:
                    d = new Horizontal;
                    d->eliminate(a, a[R][C-2+i]);
                    delete d;
                break;
                case 3:
                   d = new NineBlock;
                   d->eliminate(a, a[R][C-2+i]);
                   delete d;
                break;
            }// end switch
        }// end for
    break;
    case 3:
        num/=10;
        // right
        if(C >= 2 && (num == a[R][C-2]->number || num == a[R][C-2]->number/10) && (num == a[R][C-1]->number || num == a[R][C-1]->number/10)){
            a[R][C-2]->number = 0;
            a[R][C-1]->number = 0;
        }// end if
        // left
        if(C <= 7 && (num == a[R][C+1]->number || num == a[R][C+1]->number/10) && (num == a[R][C+2]->number || num == a[R][C+2]->number/10)){
            a[R][C+1]->number = 0;
            a[R][C+2]->number = 0;
        }// end if
        if(a[R-2][C]->number/10!=0){
            FiveNum[0] = a[R-2][C]->number%10;
        }// end if
        if(a[R-1][C]->number/10!=0){
            FiveNum[1] = a[R-1][C]->number%10;
        }// end if
        FiveNum[2] = a[R][C]->number%10;
        if(a[R+1][C]->number/10!=0){
            FiveNum[3] = a[R+1][C]->number%10;
        }// end if
        if(a[R+2][C]->number/10!=0){
            FiveNum[4] = a[R+2][C]->number%10;
        }// end if
        for(int i = 0; i < 5; i++){
            Destroy *d;
            switch(FiveNum[i]){
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
    case 4:
        num/=10;
        // up
        if(R >= 2 && (num == a[R-2][C]->number || num == a[R-2][C]->number/10) && (num == a[R-1][C]->number || num == a[R-1][C]->number/10)){
            a[R-2][C]->number = 0;
            a[R-1][C]->number = 0;
        }// end if
        // down
        if(R <= 7 && (num == a[R+1][C]->number || num == a[R+1][C]->number/10) && (num == a[R+2][C]->number || num == a[R+2][C]->number/10)){
            a[R+1][C]->number = 0;
            a[R+2][C]->number = 0;
        }// end if
        if(a[R][C-2]->number/10!=0){
            FiveNum[0] = a[R][C-2]->number%10;
        }// end if
        if(a[R][C-1]->number/10!=0){
            FiveNum[1] = a[R][C-1]->number%10;
        }// end if
        FiveNum[2] = a[R][C]->number%10;
        if(a[R][C+1]->number/10!=0){
            FiveNum[3] = a[R][C+1]->number%10;
        }// end if
        if(a[R][C+2]->number/10!=0){
            FiveNum[4] = a[R][C+2]->number%10;
        }// end if
        for(int i = 0; i < 5; i++){
            Destroy *d;
            switch(FiveNum[i]){
                case 0:
                    a[R][C-2+i]->number = 0;
                break;
                case 1:
                    d = new Vertical;
                    d->eliminate(a, a[R][C-2+i]);
                    delete d;
                break;
                case 2:
                    d = new Horizontal;
                    d->eliminate(a, a[R][C-2+i]);
                    delete d;
                break;
                case 3:
                   d = new NineBlock;
                   d->eliminate(a, a[R][C-2+i]);
                   delete d;
                break;
            }// end switch
        }// end for
        break;
    default:
        break;

    }// end switch
}

void Star::eliminate(Blank *a[10][10], Blank *focus)
{
    int num;
    // if normal or special
    if(focus->number/10 == 0){
        num = focus->number;
    }else{
        num = focus->number/10;
    }// end if else
    focus->number = 0;
    int amount = 0;
    int *TheNum;
    int *ind;
    int *jnd;
    Destroy *d;

    // set amount
    for(int i  = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(a[i][j]->number == num || a[i][j]->number/10 == num){
                amount++;
            }// end if
        }// end inner for
    }// end outer for
    TheNum = new int[amount];
    ind = new int[amount];
    jnd = new int[amount];

    // initialize arr
    TheNum[amount] = {0};

    // store number into TheNum
    int n = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(a[i][j]->number == num || a[i][j]->number/10 == num){
                // if special items
                if(a[i][j]->number/10 != 0){
                    TheNum[n] = a[i][j]->number%10;
                }// end if
                ind[n] = i;
                //qDebug()<<ind[n];
                jnd[n] = j;
                //qDebug()<<jnd[n];
                n++;
            }// end if
        }// end inner for
    }// end for
    for(int i = 0; i < amount; i++){
        int R = ind[i];
        int C = jnd[i];
        switch (TheNum[i]) {
        case 0:
            a[R][C]->number = 0;
            break;
        case 1:
            d = new Vertical;
            d->eliminate(a, a[R][C]);
            delete d;
            break;
        case 2:
            d = new Horizontal;
            d->eliminate(a, a[R][C]);
            delete d;
            break;
        case 3:
            d = new NineBlock;
            d->eliminate(a, a[R][C]);
            delete d;
            break;
        }// end switch
    }// end for
}
