// Program: Huffman Coding (Greedy - Data Compression)
// What it does: Assigns shorter binary codes to characters that appear MORE frequently
//               and longer codes to characters that appear LESS frequently.
//               This is used in data compression (like ZIP files).
// Greedy Choice: Always merge the TWO nodes with the smallest frequencies first.
//
// Example Input:
//   Characters: a  b  c  d  e  f
//   Frequency:  5  9  12 13 16 45
// Expected Output: Huffman codes for each character
//   f -> 0, c -> 100, d -> 101, a -> 1100, b -> 1101, e -> 111

#include <iostream>
#include <string>
using namespace std;

// Maximum number of characters we support
#define MAX_CHARS 100

// Structure for a node in the Huffman Tree
struct HuffmanNode {
    char character;           // The character ('$' means internal node)
    int frequency;            // Frequency of character
    int leftChild;            // Index of left child (-1 if none)
    int rightChild;           // Index of right child (-1 if none)
};

// Array to store all nodes (leaves + internal nodes)
HuffmanNode nodes[MAX_CHARS * 2];
int totalNodes = 0;  // Total nodes created so far

// Function to create a new Huffman node
int createNode(char ch, int freq, int left, int right) {
    nodes[totalNodes].character = ch;
    nodes[totalNodes].frequency = freq;
    nodes[totalNodes].leftChild = left;
    nodes[totalNodes].rightChild = right;
    return totalNodes++;  // Return index and increment count
}

// Function to find the index of the node with minimum frequency
// Only considers nodes that are still "active" (in minQueue array)
int findMin(int queue[], int queueSize) {
    int minIndex = 0;
    for (int i = 1; i < queueSize; i++) {
        if (nodes[queue[i]].frequency < nodes[queue[minIndex]].frequency) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to extract the minimum node and remove it from queue array
int extractMin(int queue[], int &queueSize) {
    int minIdx  = findMin(queue, queueSize);
    int minNode = queue[minIdx];

    // Remove this node by shifting elements
    for (int i = minIdx; i < queueSize - 1; i++) {
        queue[i] = queue[i + 1];
    }
    queueSize--;

    return minNode;  // Return the index of the minimum frequency node
}

// Recursive function to print Huffman codes
// 'code' is the binary string built so far (top-down)
void printCodes(int nodeIndex, string code) {
    if (nodeIndex == -1) return;

    // If this is a LEAF node (has a real character), print the code
    if (nodes[nodeIndex].leftChild == -1 && nodes[nodeIndex].rightChild == -1) {
        cout << "  '" << nodes[nodeIndex].character
             << "' (freq=" << nodes[nodeIndex].frequency
             << ") -> Code: " << code << endl;
        return;
    }

    // Traverse left child: add '0' to code
    printCodes(nodes[nodeIndex].leftChild, code + "0");

    // Traverse right child: add '1' to code
    printCodes(nodes[nodeIndex].rightChild, code + "1");
}

// Function to build the Huffman Tree and print codes
void buildHuffmanTree(char characters[], int frequencies[], int n) {
    // Step 1: Create a leaf node for each character
    int queue[MAX_CHARS * 2];   // Priority queue (simulated using array)
    int queueSize = 0;

    for (int i = 0; i < n; i++) {
        // Create leaf node: no children (-1)
        queue[queueSize++] = createNode(characters[i], frequencies[i], -1, -1);
    }

    // Step 2: Build the tree by repeatedly combining two minimum nodes
    while (queueSize > 1) {
        // Extract the two nodes with minimum frequency
        int left  = extractMin(queue, queueSize);
        int right = extractMin(queue, queueSize);

        // Create a new internal node with combined frequency
        // '$' represents an internal (non-leaf) node
        int newNode = createNode('$',
                                  nodes[left].frequency + nodes[right].frequency,
                                  left, right);

        // Add the new internal node back to queue
        queue[queueSize++] = newNode;
    }

    // Step 3: The last remaining node is the root of the Huffman Tree
    int root = queue[0];

    cout << "\nHuffman Codes for each character:" << endl;
    cout << "------------------------------------" << endl;

    // Print codes starting from root with empty code string
    printCodes(root, "");
}

int main() {
    int n;

    cout << "=== Huffman Coding (Greedy) ===" << endl;
    cout << "Enter the number of different characters: ";
    cin >> n;

    char characters[n];
    int  frequencies[n];

    cout << "\nEnter each character and its frequency:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Character " << i + 1 << ": ";
        cin >> characters[i];
        cout << "Frequency of '" << characters[i] << "': ";
        cin >> frequencies[i];
    }

    // Build and display Huffman Tree
    buildHuffmanTree(characters, frequencies, n);

    return 0;
}

/*
============================
Time Complexity:
  Building tree: O(n^2) with this simple approach (O(n log n) with min-heap)
  Printing codes: O(n)
  Overall: O(n^2)

Space Complexity: O(n) -> For tree nodes and queue

Key Concept: More frequent characters get SHORTER codes -> saves memory.
============================
*/
