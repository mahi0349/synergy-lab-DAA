#include <stdio.h>

int main() {
    float weight[50], profit[50], ratio[50], Totalvalue = 0, temp, capacity, amount;
    int n, i, j;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Profit and Weight for item[%d]:\n", i + 1);
        scanf("%f %f", &profit[i], &weight[i]);
    }

    printf("Enter the capacity of knapsack: ");
    scanf("%f", &capacity);

    for (i = 0; i < n; i++) {
        ratio[i] = profit[i] / weight[i];
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    printf("Knapsack problem using Greedy Algorithm:\n");

    for (i = 0; i < n; i++) {
        if (weight[i] <= capacity) {
            Totalvalue += profit[i];
            capacity -= weight[i];
        } else {
            Totalvalue += (ratio[i] * capacity);
            break;
        }
    }

    printf("\nThe maximum value is: %f\n", Totalvalue);

    return 0;
}



// Enter the number of items: 10
// Enter Profit and Weight for item[1]:
// 5 2
// Enter Profit and Weight for item[2]:
// 10 3
// Enter Profit and Weight for item[3]:
// 45 20
// Enter Profit and Weight for item[4]:
// 11 3 
// Enter Profit and Weight for item[5]:
// 20 6
// Enter Profit and Weight for item[6]:
// 18 9
// Enter Profit and Weight for item[7]:
// 33 10
// Enter Profit and Weight for item[8]:
// 25 14
// Enter Profit and Weight for item[9]:
// 36 9
// Enter Profit and Weight for item[10]:
// 10 5
// Enter the capacity of knapsack: 100
// Knapsack problem using Greedy Algorithm:

// The maximum value is: 213.000000