#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxHealth(int i, int* potions, int N, vector<int>& dp) {
    if (i >= N) return 0; // No more potions left
    
    if (dp[i] != -1) return dp[i]; // Return already computed result

    // Take one potion
    int take_one = potions[i] + (i + 1 < N ? min(maxHealth(i + 2, potions, N, dp), maxHealth(i + 3, potions, N, dp)) : 0);
    
    // Take two potions
    int take_two = potions[i] + (i + 1 < N ? potions[i + 1] : 0) +
                   (i + 2 < N ? min(maxHealth(i + 3, potions, N, dp), maxHealth(i + 4, potions, N, dp)) : 0);

    // Opponent plays optimally to minimize our future score
    return dp[i] = max(take_one, take_two);
}

int solve(int* potions, int N) {
    vector<int> dp(N, -1); // DP table
    return maxHealth(0, potions, N, dp);
}

int main() {
    int N;
    cin >> N;
    int potions[N];

    for (int i = 0; i < N; i++) {
        cin >> potions[i];
    }

    cout << solve(potions, N) << endl;
    return 0;
}