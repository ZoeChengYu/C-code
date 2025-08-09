#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} Node;

// 建立新節點
Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// 插入節點 (依照次方降序插入，若次方已存在則累加係數)
void insertTerm(Node** poly, int coeff, int exp) {
    if (coeff == 0) return;

    Node* prev = NULL;
    Node* curr = *poly;

    while (curr != NULL && curr->exp > exp) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL && curr->exp == exp) {
        curr->coeff += coeff;
        if (curr->coeff == 0) {
            if (prev == NULL) {
                *poly = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
        }
    } else {
        Node* newNode = createNode(coeff, exp);
        if (prev == NULL) {
            newNode->next = *poly;
            *poly = newNode;
        } else {
            newNode->next = curr;
            prev->next = newNode;
        }
    }
}

// 讀取輸入轉為多項式鏈結串列
void readPolynomial(Node** poly) {
    int coeffs[100];
    int n = 0;
    while (1) {
        int c;
        if (scanf("%d", &c) != 1) break;
        coeffs[n++] = c;
        if (getchar() == '\n') break;
    }
    for (int i = 0; i < n; i++) {
        insertTerm(poly, coeffs[i], n - 1 - i);
    }
}

// 輸出多項式
void printPolynomial(Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }

    Node* curr = poly;
    int first = 1;

    while (curr) {
        int c = curr->coeff;
        int e = curr->exp;

        if (c == 0) {
            curr = curr->next;
            continue;
        }

        // 正負號處理
        if (!first) {
            if (c > 0)
                printf("+");
        }

        // 係數處理
        if (e == 0) {
            printf("%d", c);
        } else if (e == 1) {
            if (c == 1)
                printf("x");
            else if (c == -1)
                printf("-x");
            else
                printf("%dx", c);
        } else {
            if (c == 1)
                printf("x^%d", e);
            else if (c == -1)
                printf("-x^%d", e);
            else
                printf("%dx^%d", c, e);
        }

        first = 0;
        curr = curr->next;
    }
    printf("\n");
}

// 釋放記憶體
void freePolynomial(Node* poly) {
    while (poly) {
        Node* tmp = poly;
        poly = poly->next;
        free(tmp);
    }
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    readPolynomial(&poly1);
    readPolynomial(&poly2);

    // 將 poly2 的所有項目加到 poly1
    Node* curr = poly2;
    while (curr) {
        insertTerm(&poly1, curr->coeff, curr->exp);
        curr = curr->next;
    }

    printPolynomial(poly1);

    // 清除記憶體
    freePolynomial(poly1);
    freePolynomial(poly2);

    return 0;
}
