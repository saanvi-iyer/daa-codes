#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a Huffman tree node
struct HuffmanNode {
    char data;
    unsigned frequency;
    struct HuffmanNode *left, *right;
};

// Priority queue node
struct MinHeapNode {
    struct HuffmanNode* data;
    struct MinHeapNode *next;
};

// Priority queue (min-heap)
struct MinHeap {
    struct MinHeapNode *head;
};

// Function to create a new Huffman tree node
struct HuffmanNode* createHuffmanNode(char data, unsigned frequency) {
    struct HuffmanNode* newNode = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
    newNode->data = data;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a new priority queue node
struct MinHeapNode* createMinHeapNode(struct HuffmanNode* data) {
    struct MinHeapNode* newNode = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new priority queue (min-heap)
struct MinHeap* createMinHeap() {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->head = NULL;
    return minHeap;
}

// Function to insert a new node into the priority queue
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    if (minHeap->head == NULL) {
        minHeap->head = minHeapNode;
    } else if (minHeapNode->data->frequency < minHeap->head->data->frequency) {
        minHeapNode->next = minHeap->head;
        minHeap->head = minHeapNode;
    } else {
        struct MinHeapNode* current = minHeap->head;
        while (current->next != NULL && current->next->data->frequency < minHeapNode->data->frequency) {
            current = current->next;
        }
        minHeapNode->next = current->next;
        current->next = minHeapNode;
    }
}

// Function to extract the node with the minimum frequency from the priority queue
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    if (minHeap->head == NULL) {
        return NULL;
    }

    struct MinHeapNode* temp = minHeap->head;
    minHeap->head = minHeap->head->next;
    return temp;
}

// Function to build the Huffman tree
struct HuffmanNode* buildHuffmanTree(char data[], unsigned frequency[], int size) {
    struct MinHeap* minHeap = createMinHeap();

    // Create a priority queue with all characters and their frequencies
    for (int i = 0; i < size; ++i) {
        struct HuffmanNode* node = createHuffmanNode(data[i], frequency[i]);
        struct MinHeapNode* minHeapNode = createMinHeapNode(node);
        insertMinHeap(minHeap, minHeapNode);
    }

    while (minHeap->head->next != NULL) {
        // Extract the two nodes with the minimum frequency
        struct MinHeapNode* left = extractMin(minHeap);
        struct MinHeapNode* right = extractMin(minHeap);

        // Create a new internal node with a frequency equal to the sum of the two nodes' frequencies
        struct HuffmanNode* newNode = createHuffmanNode('$', left->data->frequency + right->data->frequency);

        // Set the left and right children of the new node
        newNode->left = left->data;
        newNode->right = right->data;

        // Create a new node for the new internal node and insert it back into the priority queue
        struct MinHeapNode* minHeapNode = createMinHeapNode(newNode);
        insertMinHeap(minHeap, minHeapNode);
    }

    // The remaining node is the root of the Huffman tree
    return extractMin(minHeap)->data;
}

// Function to print the Huffman codes from the Huffman tree
void printHuffmanCodes(struct HuffmanNode* root, int arr[], int top, char code[]) {
    if (root->left) {
        arr[top] = 0;
        code[top] = '0';
        printHuffmanCodes(root->left, arr, top + 1, code);
    }

    if (root->right) {
        arr[top] = 1;
        code[top] = '1';
        printHuffmanCodes(root->right, arr, top + 1, code);
    }

    if (!root->left && !root->right) {
        printf("Character: %c, Code: ", root->data);
        for (int i = 0; i < top; ++i) {
            printf("%c", code[i]);
        }
        printf("\n");
    }
}

// Function to perform Huffman encoding
void huffmanEncode(char data[], unsigned frequency[], int size) {
    struct HuffmanNode* root = buildHuffmanTree(data, frequency, size);

    int arr[100], top = 0;
    char code[100];

    printf("\nHuffman Codes:\n");
    printHuffmanCodes(root, arr, top, code);
}

// Function to perform Huffman decoding
void huffmanDecode(struct HuffmanNode* root, char encodedData[]) {
    struct HuffmanNode* current = root;
    printf("Decoded Message: ");
    for (int i = 0; encodedData[i] != '\0'; ++i) {
        if (encodedData[i] == '0') {
            current = current->left;
        } else if (encodedData[i] == '1') {
            current = current->right;
        }

        if (!current->left && !current->right) {
            printf("%c", current->data);
            current = root; // Reset to the root for the next character
        }
    }

    printf("\n");
}

int main() {
    int size;
    scanf("%d", &size);
    char data[size];
    unsigned frequency[size];
    
    for (int i = 0; i < size; ++i) {
        scanf(" %c", &data[i]);}

    for (int i = 0; i < size; ++i) {
        scanf("%u", &frequency[i]);}

    char encodedData[100]; 
    scanf("%s", encodedData);

    huffmanEncode(data, frequency, size);
    huffmanDecode(buildHuffmanTree(data, frequency, size), encodedData);
    return 0;
}