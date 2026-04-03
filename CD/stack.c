#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct stack {
    int s[SIZE];
    int top;
} st;

int isFull() {
    return (st.top == SIZE - 1);
}

int isEmpty() {
    return (st.top == -1);
}

void push(int item) {
    if (isFull()) {
        printf("Stack Overflow!\n");
        return;
    }

    st.top++;
    st.s[st.top] = item;
    printf("%d pushed\n", item);
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow!\n");
        return -1;
    }

    int item = st.s[st.top];
    st.top--;
    return item;
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements:\n");
    for (int i = st.top; i >= 0; i--)
        printf("%d\n", st.s[i]);
}

int main() {
    int choice, item;
    st.top = -1;

    do {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter item: ");
                scanf("%d", &item);
                push(item);
                break;

            case 2:
                item = pop();
                if(item != -1)
                    printf("Popped: %d\n", item);
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 4);

    return 0;
}