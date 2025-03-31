#include <iostream>
#include <vector>
#include <string>

// Function to compute the prefix function (pi table)
std::vector<int> computePrefixFunction(const std::string &pattern) {
    int m = pattern.length();
    std::vector<int> pi(m, 0);
    int k = 0;

    for (int q = 1; q < m; q++) {
        while (k > 0 && pattern[k] != pattern[q]) {
            k = pi[k - 1];
        }
        if (pattern[k] == pattern[q]) {
            k++;
        }
        pi[q] = k;
    }

    return pi;
}

// KMP algorithm
void KMP(const std::string &text, const std::string &pattern) {
    int n = text.length();
    int m = pattern.length();
    std::vector<int> pi = computePrefixFunction(pattern);

    // Print the pi table
    std::cout << "Pi table: ";
    for (int i = 0; i < m; i++) {
        std::cout << pi[i] << " ";
    }
    std::cout << std::endl;

    int q = 0;  // number of characters matched
    for (int i = 0; i < n; i++) {
        while (q > 0 && pattern[q] != text[i]) {
            q = pi[q - 1];
        }
        if (pattern[q] == text[i]) {
            q++;
        }
        if (q == m) {
            std::cout << "Pattern occurs with shift " << i - m + 1 << std::endl;
            q = pi[q - 1];
        }
    }
}

int main() {
    std::string text = "abababcabababcabababc";
    std::string pattern = "abababc";
    
    KMP(text, pattern);
    
    return 0;
}
