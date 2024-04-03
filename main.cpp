#include <iostream>
#include <fstream>
#include "ImageProcessing.h"

int main(int argc, char** argv) {
    std::ifstream infile; 
    infile.open(argv[1]);
    int thrVal = atoi(argv[2]);
    std::ifstream structfile; 
    structfile.open(argv[3]);
    std::ofstream outfile1; 
    outfile1.open(argv[4]);
    std::ofstream outfile2; 
    outfile2.open(argv[5]);

    int numRows, numCols, minVal, maxVal;
    int numStructRows, numStructCols, structMin, structMax, rowOrigin, colOrigin;

    while (infile >> numRows >> numCols >> minVal >> maxVal) {
        break;
    }

    while (structfile >> numStructRows >> numStructCols >> structMin >> structMax >> rowOrigin >> colOrigin) {
        break;
    }

    int **imgAry = new int*[numRows + 2];
    for (int i = 0; i < numRows + 2; i++) {
        imgAry[i] = new int[numCols + 2];
    }

    int *HPP, *VPP, *binHPP, *binVPP;
    int HPP_size, VPP_size;
    int *morphHPP, *morphVPP;

    setzero(imgAry, numRows, numCols);

    loadImage(infile, imgAry, numRows, numCols);
    outfile1 << "Below is the input Image" << std::endl;
    imgReformat(imgAry, numRows, numCols, outfile1);

    computePP(imgAry, numRows, numCols, HPP, VPP, HPP_size, VPP_size);
    outfile2 << "Below is HPP" << std::endl;
    printPP(HPP, outfile2, HPP_size);
    outfile2 << "Below is VPP" << std::endl;
    printPP(VPP, outfile2, VPP_size);

    binHPP = new int[numRows + 2];
    binVPP = new int[numCols + 2];
    binaryThreshold(HPP, thrVal, binHPP, HPP_size);
    binaryThreshold(VPP, thrVal, binVPP, VPP_size);
    outfile2 << "Below is binHPP" << std::endl;
    printPP(binHPP, outfile2, HPP_size);
    outfile2 << "Below is binVPP" << std::endl;
    printPP(binVPP, outfile2, VPP_size);

    boxNode *listhead = new boxNode(0, 0, 0, 0, 0, NULL);
    boxNode *zBox = computeZoneBox(binHPP, binVPP, numRows, numCols, binHPP, binVPP);
    listhead = listInsert(listhead, zBox);
    outfile2 << "Below is the linked list after insert input zone box" << std::endl;
    printBox(listhead, outfile2);

    morphHPP = new int[numRows + 2];
    morphVPP = new int[numCols + 2];
    morphClosing(binHPP, morphHPP, HPP_size);
    morphClosing(binVPP, morphVPP, VPP_size);
    outfile2 << "Below is morphHPP after performing morphClosing on HPP" << std::endl;
    printPP(morphHPP, outfile2, HPP_size);
    outfile2 << "Below is morphVPP after performing morphClosing on VPP" << std::endl;
    printPP(morphVPP, outfile2, VPP_size);

    int runsHPP = computePPruns(morphHPP, numRows);
    int runsVPP = computePPruns(morphVPP, numCols);
    outfile2 << "The number of runs in morphHPP-runsHPP is " << runsHPP << std::endl;
    outfile2 << "The number of runs in morphVPP-runsVPP is " << runsVPP << std::endl;

    int readingDirection = computeDirection(runsHPP, runsVPP, outfile1);
    outfile2 << "Reading direction is " << readingDirection << std::endl;

    if (readingDirection == 1) {
        listhead = computeHorizontalTextBox(listhead, morphHPP, numRows);
    } else if (readingDirection == 2) {
        listhead = computeVerticalTextBox(listhead, morphVPP, numCols);
    }

    overlayBox(listhead, imgAry, numRows, numCols);

    outfile1 << "Below is the input image overlay with bounding boxes" << std::endl;
    imgReformat(imgAry, numRows, numCols, outfile1);
    outfile1 << "Output the boxNode in the list" << std::endl;
    printBox(listhead, outfile1);

    infile.close();
    structfile.close();
    outfile1.close();
    outfile2.close();
}
