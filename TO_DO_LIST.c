#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 10


char task_list[SIZE][100];
int top;


void promptAndAddTask();
void showTasks();
void addRandomTask();
void completeTopTask();



int main() {
    int choice;

    srand(time(NULL));

    while (1) {
        printf("--- My To-Do List ---\n");
        printf("1. Add a New Task\n");
        printf("2. Show All Tasks\n");
        printf("3. Add a Random Task\n");
        printf("4. Complete Top Task\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                promptAndAddTask();
                break;
            case 2:
                showTasks();
                break;
            case 3:
                addRandomTask();
                break;
            case 4:
                completeTopTask();
                break;
            case 5:
                printf("Exiting To-Do List.\n");
                exit(0);
            default:
                printf("Invalid operation. Please choose from 1-5.\n");
                break;
        }
        printf("\n");
    }

    return 0;
}

void addTask(const char* task) {
    if (top >= SIZE - 1) {
        printf("OVERFLOW: To-Do List is full. Cannot add more tasks.\n");
    } else {
        top++;
        strcpy(task_list[top], task);
        printf("Task '%s' added to the list.\n", task);
    }
}

void promptAndAddTask() {
    char buffer[100];

    printf("Enter a task to add: ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        printf("Error reading input.\n");
        return;
    }
    buffer[strcspn(buffer, "\n")] = 0;
    
    addTask(buffer);
}

void showTasks() {
    if (top == -1) {
        printf("UNDERFLOW: To-Do List is empty.\n");
    } else {
        printf("--- Tasks (Newest to Oldest) ---\n");
        for (int i = top; i >= 0; --i) {
            printf("%d. %s\n", top - i + 1, task_list[i]);
        }
    }
}

void addRandomTask() {
    const char* random_tasks[] = {"Do 10 push-ups","Do 20 sit-ups","Drink a glass of water","Read a book for 15 minutes","Go for a short walk","Tidy up your desk"};
    int num_tasks = sizeof(random_tasks) / sizeof(random_tasks[0]);
    int random_index = rand() % num_tasks;

    addTask(random_tasks[random_index]);
}

void completeTopTask() {
    if (top == -1) {
        printf("UNDERFLOW: To-Do List is empty.\n");
    } else {
        printf("Task '%s' marked as completed and removed.\n", task_list[top]);
        top--;
    }
}