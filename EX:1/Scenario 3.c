.#include <stdio.h>
#define MAX_GRADES 100
float grades[MAX_GRADES];
int gradeCount = 0;
void add_grade(float grade) {
    if (gradeCount < MAX_GRADES) {
        grades[gradeCount++] = grade;
    }
}
float calculate_average() {
    if (gradeCount == 0) return 0.0;
    float sum = 0;
    for (int i = 0; i < gradeCount; i++) {
        sum += grades[i];
    }
    return sum / gradeCount;
}
void display_grades() {
    if (gradeCount == 0) {
        printf("No grades available.\n");
        return;
    }
    printf("Grades:\n");
    for (int i = 0; i < gradeCount; i++) {
        printf("%.2f\n", grades[i]);
    }
}
int main() {
    add_grade(85.5);
    add_grade(90.2);
    add_grade(78.3);
    display_grades();
    printf("Average grade: %.2f\n", calculate_average());
    return 0;
}
