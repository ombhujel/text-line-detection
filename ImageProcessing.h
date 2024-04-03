#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H

#include <iostream>
#include <fstream>
#include <string>

struct boxNode {
    public:
        int boxType;
        int minR;
        int minC;
        int maxR;
        int maxC;
        class boxNode* next;
        boxNode(int b, int m1, int m2, int m3, int m4, boxNode* bx);
};

void setzero(int **Ary, int numRows, int numCols);
void loadImage(std::ifstream &infile, int **Ary, int numRows, int numCols);
void imgReformat(int **Ary, int numRows, int numCols, std::ofstream &File);
void computePP(int **Ary, int numRows, int numCols, int *&HPP, int *&VPP, int &HPP_size, int &VPP_size);
void printPP(int *ary, std::ofstream &file, int size);
void binaryThreshold(int *ary1, int val, int *ary2, int size);
boxNode* computeZoneBox(int *Ar1, int* Ar2, int numRows, int numCols, int *&binHPP, int *&binVPP);
boxNode* listInsert(boxNode* listhead, boxNode* zbox);
void printBox(boxNode* box, std::ofstream& file);
void morphClosing(int* ary1, int* ary2, int size);
int computePPruns(int *pp, int lastindex);
int computeDirection(int runHPPP, int runVPP, std::ofstream& file);
boxNode* computeHorizontalTextBox(boxNode* listhead, int *pp, int lastindex);
boxNode* computeVerticalTextBox(boxNode* listhead, int *pp, int lastindex);
void overlayBox(boxNode* listhead, int **ary, int numRows, int numCols);

#endif
