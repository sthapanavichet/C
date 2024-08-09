#define MAX_STR 64
#define NUM_SUBJECTS 4

struct Subject {
    char name[MAX_STR];
    int mark;
};

struct StudentInfo {
    char lastName[MAX_STR];
    int studentId;
    struct Subject subject[NUM_SUBJECTS];
};

void initializeInfo(struct StudentInfo * student);
float calcAverageMark(const struct Subject subject[]);
int findMaxMark(const struct Subject subject[]);
int findMinMark(const struct Subject subject[]);