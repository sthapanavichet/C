#include"StudentInfo.h"

void initializeInfo(struct StudentInfo * student){
    student->lastName[0] = '\0';
    student->studentId = 0;
    for(int i = 0; i < NUM_SUBJECTS; i++) {
        student->subject[i].name[0] = '\0';
        student->subject[i].mark = 0;
    }
}

float calcAverageMark(const struct Subject subject[]) {
    float runningTotal = 0;
    int numMarks = 0;
    int done = 0;
    float average;
    for(int i = 0; i < NUM_SUBJECTS && done == 0; i++) {
        if(subject[i].mark > 0) {
            runningTotal += subject[i].mark;
            numMarks += 1;
            done = 0;
        }
        else if(subject[i].mark <= 0) {
            done = 1;
        }
    }
    return(runningTotal / numMarks);
}
int findMaxMark(const struct Subject subject[]) {
    int done = 0;
    int maxMark = 0;
    int maxMarkIndex;

    for(int i = 0; i < NUM_SUBJECTS && done == 0; i++) {
        if(subject[i].mark > maxMark) {
            maxMark = subject[i].mark;
            maxMarkIndex = i;
        }
        else if(subject[i].mark <= 0) {
            done = 1;
        }
    }
    return maxMarkIndex;
}

int findMinMark(const struct Subject subject[]) {
    int done = 0;
    int minMark = 100;
    int minMarkIndex;

    for(int i = 0; i < NUM_SUBJECTS && done == 0; i++) {
        if(subject[i].mark < minMark && subject[i].mark > 0) {
            minMark = subject[i].mark;
            minMarkIndex = i;
        }
        else if(subject[i].mark <= 0) {
            done = 1;
        }
    }
    return minMarkIndex;
}
