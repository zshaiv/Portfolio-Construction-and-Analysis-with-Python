#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STOCK_NAME "AAPL"
#define INITIAL_PRICE 232.45
#define MAX_PRICE 250.00
#define MIN_PRICE 200.00
#define SIMULATION_DAYS 10

void simulate_market(float prices[], int days) {
    srand(time(0));
    for (int i = 0; i < days; i++) {
        prices[i] = MIN_PRICE + ((float)rand() / RAND_MAX) * (MAX_PRICE - MIN_PRICE);
    }
}

int main() {
    int quantity;
    printf("Enter the number of %s stocks to purchase: ", STOCK_NAME);
    scanf("%d", &quantity);
    
    float purchase_price = INITIAL_PRICE * quantity;
    float prices[SIMULATION_DAYS];
    simulate_market(prices, SIMULATION_DAYS);
    
    printf("\nSimulated Market Prices:\n");
    for (int i = 0; i < SIMULATION_DAYS; i++) {
        printf("Day %d: %.2f\n", i + 1, prices[i]);
    }
    
    float total_profit = 0.0;
    float sell_price = INITIAL_PRICE;
    
    for (int i = 0; i < SIMULATION_DAYS; i++) {
        if (prices[i] > sell_price) {
            sell_price = prices[i];
        }
    }
    
    float sell_value = sell_price * quantity;
    float profit_or_loss = sell_value - purchase_price;
    
    printf("\nStock sold at %.2f per stock.\n", sell_price);
    if (profit_or_loss >= 0) {
        printf("Total Profit: %.2f\n", profit_or_loss);
    } else {
        printf("No Loss Incurred. Stock held until profitable sale.\n");
    }
    
    return 0;

    clock_t begin = clock();
    // Your code here
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", time_spent);
}
