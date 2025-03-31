#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iterator>
using namespace std;

vector<string> solve(int N, vector<vector<string>> Messages) {
    // Map to store characters at their indices (automatically sorted by index)
    map<long long, char> charMap;
    
    // Store all characters at their respective indices
    for (int i = 0; i < N; i++) {
        long long index = stoll(Messages[i][0]);
        char character = Messages[i][1][0];
        charMap[index] = character;
    }
    
    // Store valid messages with their starting indices
    map<long long, string> validMessages;
    
    // Scan for pairs of '*' characters that might form valid messages
    for (auto startIt = charMap.begin(); startIt != charMap.end(); ++startIt) {
        // Check if this is a starting delimiter '*'
        if (startIt->second == '*') {
            long long startIndex = startIt->first;
            
            // Look for ending delimiter '*'
            auto endIt = next(startIt);
            while (endIt != charMap.end()) {
                if (endIt->second == '*') {
                    long long endIndex = endIt->first;
                    
                    // Calculate the message range (between the delimiters)
                    long long messageStart = startIndex + 1;
                    long long messageEnd = endIndex - 1;
                    
                    // Check if there's a valid message between these delimiters
                    if (messageStart <= messageEnd) {
                        string message = "";
                        bool isValid = true;
                        
                        // Verify all characters between delimiters exist
                        for (long long idx = messageStart; idx <= messageEnd; idx++) {
                            if (charMap.find(idx) == charMap.end()) {
                                isValid = false;
                                break;
                            }
                            message += charMap[idx];
                        }
                        
                        // If message is valid and non-empty, add to results
                        if (isValid && !message.empty()) {
                            validMessages[messageStart] = message;
                            break;  // Use the first valid ending delimiter
                        }
                    }
                }
                ++endIt;
            }
        }
    }
    
    // Extract messages in order of their starting indices
    vector<string> result;
    for (const auto& pair : validMessages) {
        result.push_back(pair.second);
    }
    
    return result;
}

int main() {
    // Optimize I/O operations
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    // Create a 2D vector to store index-character pairs
    vector<vector<string>> Messages(N, vector<string>(2));
    
    // Read each index-character pair
    for (int i = 0; i < N; i++) {
        cin >> Messages[i][0] >> Messages[i][1];
    }
    
    // Process the messages and get valid ones
    vector<string> result = solve(N, Messages);
    
    // Print each valid message on a new line
    for (const string& message : result) {
        cout << message << "\n";
    }
    
    return 0;
}
