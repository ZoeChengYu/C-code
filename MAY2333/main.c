#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定義函數指標的巨集
#define GATEVALUE(Gate) int (*GateValue)(struct _Gate*)

// 結構定義
typedef struct _Gate {
    int input1;
    int input2;
    GATEVALUE(Gate);
} Gate;

// 各種邏輯閘的函數
int GateORValue(Gate *gate) {
    return (gate->input1 | gate->input2) & 0x7;
}

int GateANDValue(Gate *gate) {
    return (gate->input1 & gate->input2) & 0x7;
}

int GateNOTValue(Gate *gate) {
    return (~gate->input1) & 0x7;
}

int GateNANDValue(Gate *gate) {
    return (~(gate->input1 & gate->input2)) & 0x7;
}

int GateNORValue(Gate *gate) {
    return (~(gate->input1 | gate->input2)) & 0x7;
}

int GateBUFFERValue(Gate *gate) {
    return gate->input1 & 0x7;
}

// 建立邏輯閘
void CreateGate(Gate *obj, const char *type, int input1, int input2) {
    obj->input1 = input1;
    obj->input2 = input2;

    if (strcmp(type, "A") == 0) {
        obj->GateValue = GateANDValue;
    } else if (strcmp(type, "O") == 0) {
        obj->GateValue = GateORValue;
    } else if (strcmp(type, "N") == 0) {
        obj->GateValue = GateNOTValue;
    } else if (strcmp(type, "B") == 0) {
        obj->GateValue = GateBUFFERValue;
    } else if (strcmp(type, "NA") == 0) {
        obj->GateValue = GateNANDValue;
    } else if (strcmp(type, "NO") == 0) {
        obj->GateValue = GateNORValue;
    }
}

int main() {
    int x1, x2, x3;
    char t1[3], t2[3], t3[3], g1[3], g2[3];
    
    // 讀入輸入值與邏輯閘類型
    scanf("%d %d %d", &x1, &x2, &x3);
    scanf("%s %s %s %s %s", t1, t2, t3, g1, g2);

    // 處理 X1
    Gate gate1;
    CreateGate(&gate1, t1, x1, 0);
    int v1 = gate1.GateValue(&gate1);

    // 處理 X2
    Gate gate2;
    CreateGate(&gate2, t2, x2, 0);
    int v2 = gate2.GateValue(&gate2);

    // 第一組邏輯閘 Y = v1 和 v2 的邏輯運算
    Gate gate3;
    CreateGate(&gate3, g1, v1, v2);
    int y = gate3.GateValue(&gate3);

    // 處理 X3
    Gate gate4;
    CreateGate(&gate4, t3, x3, 0);
    int v3 = gate4.GateValue(&gate4);

    // 第二組邏輯閘 Output = y 和 v3 的邏輯運算
    Gate gate5;
    CreateGate(&gate5, g2, y, v3);
    int output = gate5.GateValue(&gate5);

    // 轉換為 3 位元的二進位格式輸出
    printf("%03d\n", ((output & 4) ? 1 : 0) * 100 + ((output & 2) ? 1 : 0) * 10 + (output & 1));
    
    return 0;
}
