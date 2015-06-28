#include "nineblock.h"
#include <QDebug>
NineBlock::NineBlock()
{

}

NineBlock::~NineBlock()
{

}

int NineBlock::condition(Blank *a[10][10], Blank *focus)
{
    int R = focus->row;
    int C = focus->column;
    int num = focus->number;
    if(num != 0 && num != 5){
        if(num/10 == 0){
            // when in 'L' shape
            // right lower
            if(R >= 2 && C >= 2
                    && (num == a[R-2][C]->number || num == a[R-2][C]->number/10)
                    && (num == a[R-1][C]->number || num == a[R-1][C]->number/10)
                    && (num == a[R][C-1]->number || num == a[R][C-1]->number/10)
                    && (num == a[R][C-2]->number || num == a[R][C-2]->number/10)){
                return 1;
            }// end if
            // right upper
            if(R <= 7 && C >= 2
                    && (num == a[R+2][C]->number || num == a[R+2][C]->number/10)
                    && (num == a[R+1][C]->number || num == a[R+1][C]->number/10)
                    && (num == a[R][C-1]->number || num == a[R][C-1]->number/10)
                    && (num == a[R][C-2]->number || num == a[R][C-2]->number/10)){
                return 2;
            }// end if
            // left lower
            if(R >= 2 && C <= 7
                    && (num == a[R][C+2]->number || num == a[R][C+2]->number/10)
                    && (num == a[R][C+1]->number || num == a[R][C+1]->number/10)
                    && (num == a[R-1][C]->number || num == a[R-1][C]->number/10)
                    && (num == a[R-2][C]->number || num == a[R-2][C]->number/10)){
                return 3;
            }// end if
            // left upper
            if(R <= 7 && C <= 7
                    && (num == a[R][C+2]->number || num == a[R][C+2]->number/10)
                    && (num == a[R][C+1]->number || num == a[R][C+1]->number/10)
                    && (num == a[R+1][C]->number || num == a[R+1][C]->number/10)
                    && (num == a[R+2][C]->number || num == a[R+2][C]->number/10)){
                return 4;
            }// end if
            // when in 'T' shape
            // left T
            if(R >= 1 && R <= 8 && C >= 2
                    && (num == a[R][C-2]->number || num == a[R][C-2]->number/10)
                    && (num == a[R][C-1]->number || num == a[R][C-1]->number/10)
                    && (num == a[R-1][C]->number || num == a[R-1][C]->number/10)
                    && (num == a[R+1][C]->number || num == a[R+1][C]->number/10)){
                return 5;
            }// end if
            // right T
            if(R >= 1 && R <= 8 && C <= 7
                    && (num == a[R][C+2]->number || num == a[R][C+2]->number/10)
                    && (num == a[R][C+1]->number || num == a[R][C+1]->number/10)
                    && (num == a[R-1][C]->number || num == a[R-1][C]->number/10)
                    && (num == a[R+1][C]->number || num == a[R+1][C]->number/10)){
                return 6;
            }// end if
            // up T
            if(R >= 2 && C >=1 && C <= 8
                    && (num == a[R-2][C]->number || num == a[R-2][C]->number/10)
                    && (num == a[R-1][C]->number || num == a[R-1][C]->number/10)
                    && (num == a[R][C-1]->number || num == a[R][C-1]->number/10)
                    && (num == a[R][C+1]->number || num == a[R][C+1]->number/10)){
                return 7;
            }// end if
            // down T
            if(R <= 7 && C >=1 && C <= 8
                    && (num == a[R+2][C]->number || num == a[R+2][C]->number/10)
                    && (num == a[R+1][C]->number || num == a[R+1][C]->number/10)
                    && (num == a[R][C-1]->number || num == a[R][C-1]->number/10)
                    && (num == a[R][C+1]->number || num == a[R][C+1]->number/10)){
                return 8;
            }// end if
        }// end if
        if(num/10 != 0){
            // right lower
            if(R >= 2 && C >= 2
                    && (num == a[R-2][C]->number || num == a[R-2][C]->number/10)
                    && (num == a[R-1][C]->number || num == a[R-1][C]->number/10)
                    && (num == a[R][C-1]->number || num == a[R][C-1]->number/10)
                    && (num == a[R][C-2]->number || num == a[R][C-2]->number/10)){
                return 9;
            }// end if
            // right upper
            if(R >= 2 && C >= 2
                    && (num == a[R+2][C]->number || num == a[R+2][C]->number/10)
                    && (num == a[R+1][C]->number || num == a[R+1][C]->number/10)
                    && (num == a[R][C-1]->number || num == a[R][C-1]->number/10)
                    && (num == a[R][C-2]->number || num == a[R][C-2]->number/10)){
                return 10;
            }// end if
            // left lower
            if(R >= 2 && C >= 2
                    && (num == a[R][C+2]->number || num == a[R][C+2]->number/10)
                    && (num == a[R][C+1]->number || num == a[R][C+1]->number/10)
                    && (num == a[R-1][C]->number || num == a[R-1][C]->number/10)
                    && (num == a[R-2][C]->number || num == a[R-2][C]->number/10)){
                return 11;
            }// end if
            // left upper
            if(R >= 2 && C >= 2
                    && (num == a[R][C+2]->number || num == a[R][C+2]->number/10)
                    && (num == a[R][C+1]->number || num == a[R][C+1]->number/10)
                    && (num == a[R+1][C]->number || num == a[R+1][C]->number/10)
                    && (num == a[R+2][C]->number || num == a[R+2][C]->number/10)){
                return 12;
            }// end if
            // left T
            if(R >= 1 && R <= 8 && C >= 2
                    && (num == a[R][C-2]->number || num == a[R][C-2]->number/10)
                    && (num == a[R][C-1]->number || num == a[R][C-1]->number/10)
                    && (num == a[R-1][C]->number || num == a[R-2][C]->number/10)
                    && (num == a[R+1][C]->number || num == a[R+1][C]->number/10)){
                return 13;
            }// end if
            // right T
            if(R >= 1 && R <= 8 && C <= 7
                    && (num == a[R][C+2]->number || num == a[R][C+2]->number/10)
                    && (num == a[R][C+1]->number || num == a[R][C+1]->number/10)
                    && (num == a[R-1][C]->number || num == a[R-2][C]->number/10)
                    && (num == a[R+1][C]->number || num == a[R+1][C]->number/10)){
                return 14;
            }// end if
            // up T
            if(R >= 2 && C >=1 && C <= 8
                    && (num == a[R-2][C]->number || num == a[R-2][C]->number/10)
                    && (num == a[R-1][C]->number || num == a[R-1][C]->number/10)
                    && (num == a[R][C-1]->number || num == a[R][C-1]->number/10)
                    && (num == a[R][C+1]->number || num == a[R][C+1]->number/10)){
                return 15;
            }// end if
            // down T
            if(R <= 7 && C >=1 && C <= 8
                    && (num == a[R+2][C]->number || num == a[R+2][C]->number/10)
                    && (num == a[R+1][C]->number || num == a[R+1][C]->number/10)
                    && (num == a[R][C-1]->number || num == a[R][C-1]->number/10)
                    && (num == a[R][C+1]->number || num == a[R][C+1]->number/10)){
                return 16;
            }// end if
        }// end if
    }// end if
    return 0;
}

void NineBlock::spawn(Blank *a[10][10], Blank *focus, int mode)
{
    int R = focus->row;
    int C = focus->column;
    int num = focus->number;
    int FiveNum[5] = {0};
    switch(mode){
    case 1:
        focus->number = focus->number*10+3;
        // left one on the corner
        if(C <= 8 && num == a[R][C+1]->number || num == a[R][C+1]->number/10){
            a[R][C+1]->number = 0;
        }// end if
        // lower one on the corner
        if(R <= 8 && num == a[R+1][C]->number || num == a[R+1][C]->number/10){
            a[R+1][C]->number = 0;
        }// end if
        // enter num into FiveNum
        if(a[R][C-2]->number/10 != 0){
            FiveNum[0] = a[R][C-2]->number%10;
        }// end if
        if(a[R][C-1]->number/10 != 0){
            FiveNum[1] = a[R][C-1]->number%10;
        }// end if
        FiveNum[2] = a[R][C]->number;
        if(a[R-2][C]->number/10 != 0){
            FiveNum[3] = a[R-2][C]->number%10;
        }// end if
        if(a[R-1][C]->number/10 != 0){
            FiveNum[4] = a[R-1][C]->number%10;
        }// end if

        for(int i = 0; i < 2; i++){
            Destroy *d;
            switch (FiveNum[i]) {
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

        for(int i = 0; i < 2; i++){
            Destroy *d;
            switch (FiveNum[3+i]) {
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
        focus->number = focus->number*10+3;
        // left one on the corner
        if(C <= 8 && num == a[R][C+1]->number || num == a[R][C+1]->number/10){
            a[R][C+1]->number = 0;
        }// end if
        // upper one on the corner
        if(R >= 1 && num == a[R-1][C]->number || num == a[R-1][C]->number/10){
            a[R-1][C]->number = 0;
        }// end if
        // enter num into FiveNum
        if(a[R][C-2]->number/10 != 0){
            FiveNum[0] = a[R][C-2]->number%10;
        }// end if
        if(a[R][C-1]->number/10 != 0){
            FiveNum[1] = a[R][C-1]->number%10;
        }// end if
        FiveNum[2] = a[R][C]->number;
        if(a[R+2][C]->number/10 != 0){
            FiveNum[3] = a[R+2][C]->number%10;
        }// end if
        if(a[R+1][C]->number/10 != 0){
            FiveNum[4] = a[R+1][C]->number%10;
        }// end if

        for(int i = 0; i < 2; i++){
            Destroy *d;
            switch (FiveNum[i]) {
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

        for(int i = 0; i < 2; i++){
            Destroy *d;
            switch (FiveNum[3+i]) {
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
        focus->number = focus->number*10+3;
        // right one on the corner
        if(C >= 1 && num == a[R][C-1]->number || num == a[R][C-1]->number/10){
            a[R][C-1]->number = 0;
        }// end if
        // lower one on the corner
        if(R <= 8 && num == a[R+1][C]->number || num == a[R+1][C]->number/10){
            a[R+1][C]->number = 0;
        }// end if
        // enter num into FiveNum
        if(a[R][C+2]->number/10 != 0){
            FiveNum[0] = a[R][C+2]->number%10;
        }// end if
        if(a[R][C+1]->number/10 != 0){
            FiveNum[1] = a[R][C+1]->number%10;
        }// end if
        FiveNum[2] = a[R][C]->number;
        if(a[R-2][C]->number/10 != 0){
            FiveNum[3] = a[R-2][C]->number%10;
        }// end if
        if(a[R-1][C]->number/10 != 0){
            FiveNum[4] = a[R-1][C]->number%10;
        }// end if

        for(int i = 0; i < 2; i++){
            Destroy *d;
            switch (FiveNum[i]) {
            case 0:
                a[R][C+2-i]->number = 0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a, a[R][C+2-i]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a, a[R][C+2-i]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a, a[R][C+2-i]);
                delete d;
                break;
            }// end switch
        }// end for

        for(int i = 0; i < 2; i++){
            Destroy *d;
            switch (FiveNum[3+i]) {
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
        focus->number = focus->number*10+3;
        // right one on the corner
        if(C >= 1 && num == a[R][C-1]->number || num == a[R][C-1]->number/10){
            a[R][C-1]->number = 0;
        }// end if
        // lower one on the corner
        if(R >= 2 && num == a[R-1][C]->number || num == a[R-1][C]->number/10){
            a[R-1][C]->number = 0;
        }// end if
        // enter num into FiveNum
        if(a[R][C+2]->number/10 != 0){
            FiveNum[0] = a[R][C+2]->number%10;
        }// end if
        if(a[R][C+1]->number/10 != 0){
            FiveNum[1] = a[R][C+1]->number%10;
        }// end if
        FiveNum[2] = a[R][C]->number;
        if(a[R+2][C]->number/10 != 0){
            FiveNum[3] = a[R+2][C]->number%10;
        }// end if
        if(a[R+1][C]->number/10 != 0){
            FiveNum[4] = a[R+1][C]->number%10;
        }// end if

        for(int i = 0; i < 2; i++){
            Destroy *d;
            switch (FiveNum[i]) {
            case 0:
                a[R][C+2-i]->number = 0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a, a[R][C+2-i]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a, a[R][C+2-i]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a, a[R][C+2-i]);
                delete d;
                break;
            }// end switch
        }// end for

        for(int i = 0; i < 2; i++){
            Destroy *d;
            switch (FiveNum[3+i]) {
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
    case 5:
        focus->number = focus->number*10+3;
        // enter num into FiveNum
        if(a[R][C-2]->number/10 != 0){
            FiveNum[0] = a[R][C-2]->number%10;
        }// end if
        if(a[R][C-1]->number/10 != 0){
            FiveNum[1] = a[R][C-1]->number%10;
        }// end if
        FiveNum[2] = a[R][C]->number;
        if(a[R-1][C]->number/10 != 0){
            FiveNum[3] = a[R-1][C]->number%10;
        }// end if
        if(a[R+1][C]->number/10 != 0){
            FiveNum[4] = a[R+1][C]->number%10;
        }// end if

        for(int i = 0; i < 2; i++){
            //qDebug()<<"left "<<i;
            Destroy *d;
            switch (FiveNum[i]) {
            case 0:
                a[R][C-2-i]->number = 0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a, a[R][C-2-i]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a, a[R][C-2-i]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a, a[R][C-2-i]);
                delete d;
                break;
            }// end switch
        }// end for

        for(int i = 0; i <= 2; i+=2){
            int ind = 0;
            Destroy *d;
            switch (FiveNum[3+ind]) {
            case 0:
                a[R-1+i][C]->number = 0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a, a[R-1+i][C]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a, a[R-1+i][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a, a[R-1+i][C]);
                delete d;
                break;
            }// end switch
            ind++;
        }// end for
        break;
    case 6:
        focus->number = focus->number*10+3;
        // enter num into FiveNum
        if(a[R][C+2]->number/10 != 0){
            FiveNum[0] = a[R][C+2]->number%10;
        }// end if
        if(a[R][C+1]->number/10 != 0){
            FiveNum[1] = a[R][C+1]->number%10;
        }// end if
        FiveNum[2] = a[R][C]->number;
        if(a[R-1][C]->number/10 != 0){
            FiveNum[3] = a[R-1][C]->number%10;
        }// end if
        if(a[R+1][C]->number/10 != 0){
            FiveNum[4] = a[R+1][C]->number%10;
        }// end if

        for(int i = 0; i < 2; i++){
            Destroy *d;
            switch (FiveNum[i]) {
            case 0:
                a[R][C+2-i]->number = 0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a, a[R][C+2-i]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a, a[R][C+2-i]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a, a[R][C+2-i]);
                delete d;
                break;
            }// end switch
        }// end for

        for(int i = 0; i <= 2; i+=2){
            int ind = 0;
            Destroy *d;
            switch (FiveNum[3+ind]) {
            case 0:
                a[R-1+i][C]->number = 0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a, a[R-1+i][C]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a, a[R-1+i][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a, a[R-1+i][C]);
                delete d;
                break;
            }// end switch
            ind++;
        }// end for
        break;
    case 7:
        focus->number = focus->number*10+3;
        // enter num into FiveNum
        if(a[R-2][C]->number/10 != 0){
            FiveNum[0] = a[R-2][C]->number%10;
        }// end if
        if(a[R-1][C]->number/10 != 0){
            FiveNum[1] = a[R-1][C]->number%10;
        }// end if
        FiveNum[2] = a[R][C]->number;
        if(a[R][C-1]->number/10 != 0){
            FiveNum[3] = a[R][C-1]->number%10;
        }// end if
        if(a[R][C+1]->number/10 != 0){
            FiveNum[4] = a[R][C+1]->number%10;
        }// end if

        for(int i = 0; i < 2; i++){
            Destroy *d;
            switch (FiveNum[i]) {
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

        for(int i = 0; i <= 2; i+=2){
            int ind = 0;
            Destroy *d;
            switch (FiveNum[3+ind]) {
            case 0:
                a[R][C-1+i]->number = 0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a, a[R][C-1+i]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a, a[R][C-1+i]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a, a[R][C-1+i]);
                delete d;
                break;
            }// end switch
            ind++;
        }// end for
        break;
    case 8:
        focus->number = focus->number*10+3;
        // enter num into FiveNum
        if(a[R+2][C]->number/10 != 0){
            FiveNum[0] = a[R+2][C]->number%10;
        }// end if
        if(a[R+1][C]->number/10 != 0){
            FiveNum[1] = a[R+1][C]->number%10;
        }// end if
        FiveNum[2] = a[R][C]->number;
        if(a[R][C-1]->number/10 != 0){
            FiveNum[3] = a[R][C-1]->number%10;
        }// end if
        if(a[R][C+1]->number/10 != 0){
            FiveNum[4] = a[R][C+1]->number%10;
        }// end if

        for(int i = 0; i < 2; i++){
            Destroy *d;
            switch (FiveNum[i]) {
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

        for(int i = 0; i <= 2; i+=2){
            int ind = 0;
            Destroy *d;
            switch (FiveNum[3+ind]) {
            case 0:
                a[R][C-1+i]->number = 0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a, a[R][C-1+i]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a, a[R][C-1+i]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a, a[R][C-1+i]);
                delete d;
                break;
            }// end switch
            ind++;
        }// end for
        break;
    case 9:
        num/=10;
        // left one on the corner
        if(C <= 8 && num == a[R][C+1]->number || num == a[R][C+1]->number/10){
            a[R][C+1]->number = 0;
        }// end if
        // lower one on the corner
        if(R <= 8 && num == a[R+1][C]->number || num == a[R+1][C]->number/10){
            a[R+1][C]->number = 0;
        }// end if
        // enter num into FiveNum
        if(a[R][C-2]->number/10 != 0){
            FiveNum[0] = a[R][C-2]->number%10;
        }// end if
        if(a[R][C-1]->number/10 != 0){
            FiveNum[1] = a[R][C-1]->number%10;
        }// end if
        FiveNum[2] = a[R][C]->number%10;
        if(a[R-2][C]->number/10 != 0){
            FiveNum[3] = a[R-2][C]->number%10;
        }// end if
        if(a[R-1][C]->number/10 != 0){
            FiveNum[4] = a[R-1][C]->number%10;
        }// end if

        for(int i = 0; i < 2; i++){
            Destroy *d;
            switch (FiveNum[i]) {
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

        for(int i = 0; i < 2; i++){
            Destroy *d;
            switch (FiveNum[3+i]) {
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
    case 10:
        num/=10;
        // left one on the corner
        if(C <= 8 && num == a[R][C+1]->number || num == a[R][C+1]->number/10){
            a[R][C+1]->number = 0;
        }// end if
        // upper one on the corner
        if(R >= 1 && num == a[R-1][C]->number || num == a[R-1][C]->number/10){
            a[R-1][C]->number = 0;
        }// end if
        // enter num into FiveNum
        if(a[R][C-2]->number/10 != 0){
            FiveNum[0] = a[R][C-2]->number%10;
        }// end if
        if(a[R][C-1]->number/10 != 0){
            FiveNum[1] = a[R][C-1]->number%10;
        }// end if
        FiveNum[2] = a[R][C]->number%10;
        if(a[R+2][C]->number/10 != 0){
            FiveNum[3] = a[R+2][C]->number%10;
        }// end if
        if(a[R+1][C]->number/10 != 0){
            FiveNum[4] = a[R+1][C]->number%10;
        }// end if

        for(int i = 0; i < 2; i++){
            Destroy *d;
            switch (FiveNum[i]) {
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

        for(int i = 0; i < 2; i++){
            Destroy *d;
            switch (FiveNum[3+i]) {
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
    case 11:
        num/=10;
        // right one on the corner
        if(C >= 1 && num == a[R][C-1]->number || num == a[R][C-1]->number/10){
            a[R][C-1]->number = 0;
        }// end if
        // lower one on the corner
        if(R <= 8 && num == a[R+1][C]->number || num == a[R+1][C]->number/10){
            a[R+1][C]->number = 0;
        }// end if
        // enter num into FiveNum
        if(a[R][C+2]->number/10 != 0){
            FiveNum[0] = a[R][C+2]->number%10;
        }// end if
        if(a[R][C+1]->number/10 != 0){
            FiveNum[1] = a[R][C+1]->number%10;
        }// end if
        FiveNum[2] = a[R][C]->number%10;
        if(a[R-2][C]->number/10 != 0){
            FiveNum[3] = a[R-2][C]->number%10;
        }// end if
        if(a[R-1][C]->number/10 != 0){
            FiveNum[4] = a[R-1][C]->number%10;
        }// end if

        for(int i = 0; i < 2; i++){
            Destroy *d;
            switch (FiveNum[i]) {
            case 0:
                a[R][C+2-i]->number = 0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a, a[R][C+2-i]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a, a[R][C+2-i]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a, a[R][C+2-i]);
                delete d;
                break;
            }// end switch
        }// end for

        for(int i = 0; i < 2; i++){
            Destroy *d;
            switch (FiveNum[3+i]) {
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
    case 12:
        num/=10;
        // right one on the corner
        if(C >= 1 && num == a[R][C-1]->number || num == a[R][C-1]->number/10){
            a[R][C-1]->number = 0;
        }// end if
        // lower one on the corner
        if(R >= 2 && num == a[R-1][C]->number || num == a[R-1][C]->number/10){
            a[R-1][C]->number = 0;
        }// end if
        // enter num into FiveNum
        if(a[R][C+2]->number/10 != 0){
            FiveNum[0] = a[R][C+2]->number%10;
        }// end if
        if(a[R][C+1]->number/10 != 0){
            FiveNum[1] = a[R][C+1]->number%10;
        }// end if
        FiveNum[2] = a[R][C]->number%10;
        if(a[R+2][C]->number/10 != 0){
            FiveNum[3] = a[R+2][C]->number%10;
        }// end if
        if(a[R+1][C]->number/10 != 0){
            FiveNum[4] = a[R+1][C]->number%10;
        }// end if

        for(int i = 0; i < 2; i++){
            Destroy *d;
            switch (FiveNum[i]) {
            case 0:
                a[R][C+2-i]->number = 0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a, a[R][C+2-i]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a, a[R][C+2-i]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a, a[R][C+2-i]);
                delete d;
                break;
            }// end switch
        }// end for

        for(int i = 0; i < 2; i++){
            Destroy *d;
            switch (FiveNum[3+i]) {
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
    case 13:
        num/=10;
        // enter num into FiveNum
        if(a[R][C-2]->number/10 != 0){
            FiveNum[0] = a[R][C-2]->number%10;
        }// end if
        if(a[R][C-1]->number/10 != 0){
            FiveNum[1] = a[R][C-1]->number%10;
        }// end if
        FiveNum[2] = a[R][C]->number%10;
        if(a[R-1][C]->number/10 != 0){
            FiveNum[3] = a[R-1][C]->number%10;
        }// end if
        if(a[R+1][C]->number/10 != 0){
            FiveNum[4] = a[R+1][C]->number%10;
        }// end if

        for(int i = 0; i < 2; i++){
            //qDebug()<<"left "<<i;
            Destroy *d;
            switch (FiveNum[i]) {
            case 0:
                a[R][C-2-i]->number = 0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a, a[R][C-2-i]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a, a[R][C-2-i]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a, a[R][C-2-i]);
                delete d;
                break;
            }// end switch
        }// end for

        for(int i = 0; i <= 2; i+=2){
            int ind = 0;
            Destroy *d;
            switch (FiveNum[3+ind]) {
            case 0:
                a[R-1+i][C]->number = 0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a, a[R-1+i][C]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a, a[R-1+i][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a, a[R-1+i][C]);
                delete d;
                break;
            }// end switch
            ind++;
        }// end for
        break;
    case 14:
        num/=10;
        // enter num into FiveNum
        if(a[R][C+2]->number/10 != 0){
            FiveNum[0] = a[R][C+2]->number%10;
        }// end if
        if(a[R][C+1]->number/10 != 0){
            FiveNum[1] = a[R][C+1]->number%10;
        }// end if
        FiveNum[2] = a[R][C]->number%10;
        if(a[R-1][C]->number/10 != 0){
            FiveNum[3] = a[R-1][C]->number%10;
        }// end if
        if(a[R+1][C]->number/10 != 0){
            FiveNum[4] = a[R+1][C]->number%10;
        }// end if

        for(int i = 0; i < 2; i++){
            Destroy *d;
            switch (FiveNum[i]) {
            case 0:
                a[R][C+2-i]->number = 0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a, a[R][C+2-i]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a, a[R][C+2-i]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a, a[R][C+2-i]);
                delete d;
                break;
            }// end switch
        }// end for

        for(int i = 0; i <= 2; i+=2){
            int ind = 0;
            Destroy *d;
            switch (FiveNum[3+ind]) {
            case 0:
                a[R-1+i][C]->number = 0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a, a[R-1+i][C]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a, a[R-1+i][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a, a[R-1+i][C]);
                delete d;
                break;
            }// end switch
            ind++;
        }// end for
        break;
    case 15:
        num/=10;
        // enter num into FiveNum
        if(a[R-2][C]->number/10 != 0){
            FiveNum[0] = a[R-2][C]->number%10;
        }// end if
        if(a[R-1][C]->number/10 != 0){
            FiveNum[1] = a[R-1][C]->number%10;
        }// end if
        FiveNum[2] = a[R][C]->number%10;
        if(a[R][C-1]->number/10 != 0){
            FiveNum[3] = a[R][C-1]->number%10;
        }// end if
        if(a[R][C+1]->number/10 != 0){
            FiveNum[4] = a[R][C+1]->number%10;
        }// end if

        for(int i = 0; i < 2; i++){
            Destroy *d;
            switch (FiveNum[i]) {
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

        for(int i = 0; i <= 2; i+=2){
            int ind = 0;
            Destroy *d;
            switch (FiveNum[3+ind]) {
            case 0:
                a[R][C-1+i]->number = 0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a, a[R][C-1+i]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a, a[R][C-1+i]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a, a[R][C-1+i]);
                delete d;
                break;
            }// end switch
            ind++;
        }// end for
        break;
    case 16:
        num/=10;
        // enter num into FiveNum
        if(a[R+2][C]->number/10 != 0){
            FiveNum[0] = a[R+2][C]->number%10;
        }// end if
        if(a[R+1][C]->number/10 != 0){
            FiveNum[1] = a[R+1][C]->number%10;
        }// end if
        FiveNum[2] = a[R][C]->number%10;
        if(a[R][C-1]->number/10 != 0){
            FiveNum[3] = a[R][C-1]->number%10;
        }// end if
        if(a[R][C+1]->number/10 != 0){
            FiveNum[4] = a[R][C+1]->number%10;
        }// end if

        for(int i = 0; i < 2; i++){
            Destroy *d;
            switch (FiveNum[i]) {
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

        for(int i = 0; i <= 2; i+=2){
            int ind = 0;
            Destroy *d;
            switch (FiveNum[3+ind]) {
            case 0:
                a[R][C-1+i]->number = 0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a, a[R][C-1+i]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a, a[R][C-1+i]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a, a[R][C-1+i]);
                delete d;
                break;
            }// end switch
            ind++;
        }// end for
        break;
    default:
        break;

    }// end switch

}

void NineBlock::eliminate(Blank *a[10][10], Blank *focus)
{
    int R = focus->row;
    int C = focus->column;
    focus->number = 0;
    int EightNum[8] = {0};

    if(R >= 1 && C >= 1 && a[R-1][C-1]->number/10 != 0){
        EightNum[0] = a[R-1][C-1]->number%10;
    }// end if
    if(R >= 1 && a[R-1][C]->number/10 != 0){
        EightNum[1] = a[R-1][C]->number%10;
    }// end if
    if(R >= 1 && C <= 8 && a[R-1][C+1]->number/10 != 0){
        EightNum[2] = a[R-1][C+1]->number%10;
    }// end if
    if(C >= 1 && a[R][C-1]->number/10 != 0){
        EightNum[3] = a[R][C-1]->number%10;
    }// end if
    if(C <= 8 && a[R][C+1]->number/10 != 0){
        EightNum[4] = a[R][C+1]->number%10;
    }// end if
    if(R <= 8 && C >= 1 && a[R+1][C-1]->number != 0){
        EightNum[5] = a[R+1][C-1]->number%10;
    }// end if
    if(R <= 8 && a[R+1][C]->number != 0){
        EightNum[6] = a[R+1][C]->number%10;
    }// end if
    if(R <= 8 && C <= 8 && a[R+1][C+1] != 0){
        EightNum[7] = a[R+1][C+1]->number%10;
    }// end if


    if(R-1 >= 0 && C-1 >=0){
        Destroy *d;
        switch (EightNum[0]) {
        case 0:
            a[R-1][C-1]->number = 0;
            break;
        case 1:
            d = new Vertical;
            d->eliminate(a, a[R-1][C-1]);
            delete d;
            break;
        case 2:
            d = new Horizontal;
            d->eliminate(a, a[R-1][C-1]);
            delete d;
            break;
        case 3:
            d = new NineBlock;
            d->eliminate(a, a[R-1][C-1]);
            delete d;
            break;
        default:
            break;
        }
    }// end if
    if(R-1 >= 0){
        Destroy *d;
        switch (EightNum[1]) {
        case 0:
            a[R-1][C]->number = 0;
            break;
        case 1:
            d = new Vertical;
            d->eliminate(a, a[R-1][C]);
            delete d;
            break;
        case 2:
            d = new Horizontal;
            d->eliminate(a, a[R-1][C]);
            delete d;
            break;
        case 3:
            d = new NineBlock;
            d->eliminate(a, a[R-1][C]);
            delete d;
            break;
        default:
            break;
        }
    }// end if
    if(R >= 1 && C <= 8){
         Destroy *d;
        switch (EightNum[2]) {
        case 0:
            a[R-1][C+1]->number = 0;
            break;
        case 1:
            d = new Vertical;
            d->eliminate(a, a[R-1][C+1]);
            delete d;
            break;
        case 2:
            d = new Horizontal;
            d->eliminate(a, a[R-1][C+1]);
            delete d;
            break;
        case 3:
            d = new NineBlock;
            d->eliminate(a, a[R-1][C+1]);
            delete d;
            break;
        default:
            break;
        }
    }// end if
    if(C >= 1){
         Destroy *d;
        switch (EightNum[3]) {
        case 0:
            a[R][C-1]->number = 0;
            break;
        case 1:
            d = new Vertical;
            d->eliminate(a, a[R][C-1]);
            delete d;
            break;
        case 2:
            d = new Horizontal;
            d->eliminate(a, a[R][C-1]);
            delete d;
            break;
        case 3:
            d = new NineBlock;
            d->eliminate(a, a[R][C-1]);
            delete d;
            break;
        default:
            break;
        }
    }// end if
    if(C <= 8){
         Destroy *d;
        switch (EightNum[4]) {
        case 0:
            a[R][C+1]->number = 0;
            break;
        case 1:
            d = new Vertical;
            d->eliminate(a, a[R][C+1]);
            delete d;
            break;
        case 2:
            d = new Horizontal;
            d->eliminate(a, a[R][C+1]);
            delete d;
            break;
        case 3:
            d = new NineBlock;
            d->eliminate(a, a[R][C+1]);
            delete d;
            break;
        default:
            break;
        }
    }// end if
    if(R <= 8 && C >= 1){
         Destroy *d;
        switch (EightNum[5]) {
        case 0:
            a[R+1][C-1]->number = 0;
            break;
        case 1:
            d = new Vertical;
            d->eliminate(a, a[R+1][C-1]);
            delete d;
            break;
        case 2:
            d = new Horizontal;
            d->eliminate(a, a[R+1][C-1]);
            delete d;
            break;
        case 3:
            d = new NineBlock;
            d->eliminate(a, a[R+1][C-1]);
            delete d;
            break;
        default:
            break;
        }
    }// end if
    if(R <= 8){
         Destroy *d;
        switch (EightNum[6]) {
        case 0:
            a[R+1][C]->number = 0;
            break;
        case 1:
            d = new Vertical;
            d->eliminate(a, a[R+1][C]);
            delete d;
            break;
        case 2:
            d = new Horizontal;
            d->eliminate(a, a[R+1][C]);
            delete d;
            break;
        case 3:
            d = new NineBlock;
            d->eliminate(a, a[R+1][C]);
            delete d;
            break;
        default:
            break;
        }
    }// end if
    if(R <= 8 && C <= 8){
         Destroy *d;
        switch (EightNum[7]) {
        case 0:
            a[R+1][C+1]->number = 0;
            break;
        case 1:
            d = new Vertical;
            d->eliminate(a, a[R+1][C+1]);
            delete d;
            break;
        case 2:
            d = new Horizontal;
            d->eliminate(a, a[R+1][C+1]);
            delete d;
            break;
        case 3:
            d = new NineBlock;
            d->eliminate(a, a[R+1][C+1]);
            delete d;
            break;
        default:
            break;
        }
    }// end if

}

