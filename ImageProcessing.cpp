#include "ImageProcessing.h"
#include <sstream>

boxNode::boxNode(int b, int m1, int m2, int m3, int m4, boxNode* bx) {
    boxType = b;
    minR = m1;
    minC = m2;
    maxR = m3;
    maxC = m4;
    next = bx;
}

void setzero(int **Ary, int numRows, int numCols) {
    for (int i = 0; i < numRows + 2; i++) {
        for (int j = 0; j < numCols + 2; j++) {
            Ary[i][j] = 0;
        }
    }
}

void loadImage(std::ifstream &infile, int **Ary, int numRows, int numCols) {
    std::string string_array[numRows + 1];
    int *translationarray = new int[numRows * numCols];
    std::string text;
    int j = 0;

    while (!infile.eof()) {
        getline(infile, text);
        string_array[j] = text;
        j++;
        if (j == (numRows + 1)) {
            break;
        }
    }

    int k = 0;
    for (int p = 1; p < numRows + 1; p++) {
        std::string s = string_array[p];
        std::stringstream ss(s);
        std::string word;
        while (ss >> word) {
            translationarray[k] = std::stoi(word);
            k++;
        }
    }

    int l = 0;
    for (int i = 1; i < numRows + 1; i++) {
        for (int j = 1; j < numCols + 1; j++) {
            int value = translationarray[l];
            Ary[i][j] = translationarray[l];
            l++;
        }
    }
}

void imgReformat(int **Ary, int numRows, int numCols, std::ofstream &File) {
    File << numRows << " " << numCols << " " << Ary[1][1] << " " << Ary[numRows][numCols] << std::endl;

    for (int i = 1; i < numRows + 1; i++) {
        for (int j = 1; j < numCols + 1; j++) {
            if (Ary[i][j] > 0) {
                File << Ary[i][j] << " ";
            } else {
                File << ". ";
            }
        }
        File << std::endl;
    }
}

void computePP(int **Ary, int numRows, int numCols, int *&HPP, int *&VPP, int &HPP_size, int &VPP_size) {
    HPP_size = VPP_size = 0;
    HPP = new int[numRows + 2];
    VPP = new int[numCols + 2];

    int count;
    for (int i = 0; i < numRows + 2; i++) {
        count = 0;
        for (int j = 0; j < numCols + 2; j++) {
            if (Ary[i][j] == 1) {
                count++;
            }
        }
        HPP[i] = count;
        HPP_size++;
    }

    for (int j = 0; j < numCols + 2; j++) {
        count = 0;
        for (int i = 0; i < numRows + 2; i++) {
            if (Ary[i][j] == 1) {
                count++;
            }
        }
        VPP[j] = count;
        VPP_size++;
    }
}

void printPP(int *ary, std::ofstream &file, int size) {
    for (int i = 0; i < size; i++) {
        file << ary[i] << " ";
    }
    file << std::endl;
}

void binaryThreshold(int *ary1, int val, int *ary2, int size) {
    for (int i = 0; i < size; i++) {
        ary2[i] = (ary1[i] > 0) ? 1 : 0;
    }
}

boxNode* computeZoneBox(int *Ar1, int* Ar2, int numRows, int numCols, int *&binHPP, int *&binVPP) {
    int minR = 1;
    int minC = 1;
    int maxR = numRows;
    int maxC = numCols;
    
    // Compute minR
    while (Ar1[minR] == 0 && minR <= numRows) {
        minR++;
    }
    
    // Compute maxR
    while (Ar1[maxR] == 0 && maxR >= 1) {
        maxR--;
    }
    
    // Compute minC
    while (Ar2[minC] == 0 && minC <= numCols) {
        minC++;
    }
    
    // Compute maxC
    while (Ar2[maxC] == 0 && maxC >= 1) {
        maxC--;
    }
    
    boxNode* B = new boxNode(1, minR, minC, maxR, maxC, NULL);
    return B;
}

boxNode* listInsert(boxNode* listhead, boxNode* zbox) {
    boxNode *ptr;
    ptr = zbox;
    ptr->next = NULL;

    ptr->next = listhead;
    listhead = ptr;
    return listhead;
}

void printBox(boxNode* box, std::ofstream& file) {
    file << box->boxType << std::endl;
    file << box->minR << " " << box->minC << " " << box->maxR << " " << box->maxC << std::endl;
}

void morphClosing(int* ary1, int* ary2, int size) {
    int* ary3 = new int[size];
    for (int i = 1; i < size - 1; i++) {
        if (ary1[i] > 0) {
            ary3[i - 1] = 1;
            ary3[i] = 1;
            ary3[i + 1] = 1;
        }
    }

    for (int i = 1; i < size - 1; i++) {
        if (ary3[i - 1] > 0 && ary3[i] > 0 && ary3[i + 1] > 0) {
            ary2[i] = 1;
        }
    }
}

int computePPruns(int *pp, int lastindex) {
    int numRuns = 0;
    int index = 1;
    while (index <= lastindex) {
        while (pp[index] == 0 && index <= lastindex) {
            if (pp[index] == 0) {
                index++;
            }
        }
        while (pp[index] > 0 && index <= lastindex) {
            if (pp[index] > 0) {
                index++;
            }
        }
        numRuns++;
    }
    return numRuns;
}

int computeDirection(int runHPPP, int runVPP, std::ofstream& file) {
    int factor = 2;
    int direction = 0;
    if (runHPPP <= 2 && runVPP <= 2) {
        file << "The zone may be a non-text zone" << std::endl;
    } else if (runHPPP >= factor * runVPP) {
        file << "The document reading direction is horizontal" << std::endl;
        direction = 1;
    } else if (runVPP >= factor * runHPPP) {
        file << "The document reading direction is vertical" << std::endl;
        direction = 2;
    } else {
        file << "The zone may be a non-text zone" << std::endl;
    }
    return direction;
}

boxNode* computeHorizontalTextBox(boxNode* listhead, int *pp, int lastindex) {
    int minR = listhead->minR;
    int minC = listhead->minC;
    int maxR = minR;
    int maxC = listhead->maxC;
    int b = 0;
    while (pp[maxR] == 0 && maxR <= lastindex) {
        if (pp[maxR] == 0) {
            maxR++;
        }
    }
    minR = maxR;
    while (maxR <= lastindex) {
        while (pp[maxR] > 0 && maxR <= lastindex) {
            if (pp[maxR] > 0) {
                maxR++;
            }
        }
        boxNode* B = new boxNode(2, minR, minC, maxR, maxC, nullptr);
        b++;
        listhead = listInsert(listhead, B);
        minR = maxR;
        while (pp[minR] == 0 && minR <= lastindex) {
            if (pp[minR] == 0) {
                minR++;
            }
        }
        maxR = minR;
    }
    return listhead;
}

boxNode* computeVerticalTextBox(boxNode* listhead, int *pp, int lastindex) {
    int minR = listhead->minR;
    int minC = listhead->minC;
    int maxR = listhead->maxR;
    int maxC = minC;
    int b = 0;
    while (pp[maxC] == 0 && maxC <= lastindex) {
        if (pp[maxC] == 0) {
            maxC++;
        }
    }

    minC = maxC;
    while (maxC <= lastindex) {
        while (pp[maxC] > 0 && maxC <= lastindex) {
            if (pp[maxC] > 0) {
                maxC++;
            }
        }
        boxNode* B = new boxNode(2, minR, minC, maxR, maxC, NULL);
        b++;
        listhead = listInsert(listhead, B);
        minC = maxC;
        while (pp[minC] == 0 && minC <= lastindex) {
            if (pp[minC] == 0) {
                minC++;
            }
        }
        maxC = minC;
    }
    return listhead;
}

void overlayBox(boxNode* listhead, int **ary, int numRows, int numCols) {
    while (listhead != NULL) {
        int minRow = listhead->minR;
        int minCol = listhead->minC;
        int maxRow = listhead->maxR;
        int maxCol = listhead->maxC;
        for (int i = minCol; i < maxCol + 1; i++) {
            ary[minRow][i] = 9;
        }
        for (int i = minCol; i < maxCol + 1; i++) {
            ary[maxRow][i] = 9;
        }
        for (int i = minRow; i < maxRow + 1; i++) {
            ary[i][minCol] = 9;
        }
        for (int i = minRow; i < maxRow + 1; i++) {
            ary[i][maxCol] = 9;
        }
        listhead = listhead->next;
    }
}
