#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "functions.h"
#include <time.h>

int users = 0;//No. of users
int answered = 0; //Answer till 10
int size = -1;
//hash key = Subject/Topic * 100 + Difficulty(1-20)*5 + nth question of that Subject & Difficulty.

int hashCode(int key){
    return key % CAPACITY;
}

struct question* search(int key){
    //get the hash 
   int hashIndex = hashCode(key);  
	
   //move in array until an empty 
   while(hashArray[hashIndex] != NULL) {
	
      if(hashArray[hashIndex]->key == key)
         return hashArray[hashIndex]; 
			
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= CAPACITY;
   }        
	
   return NULL; 

}
void insert(struct question* que){
    //get the hash 
   int hashIndex = hashCode(que->key);

   //move in array until an empty or deleted cell
   while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= CAPACITY;
   }
	
   hashArray[hashIndex] = que;
}

struct question* delete(int key){

    //get the hash 
    int hashIndex = hashCode(key);
    struct question* dummyItem;
    //move in array until an empty
    while(hashArray[hashIndex] != NULL) {
        
        if(hashArray[hashIndex]->key == key) {
            struct question* temp = hashArray[hashIndex]; 
                
            //assign a dummy item at deleted position
            hashArray[hashIndex] = dummyItem; 
            return temp;
        }
            
        //go to next cell
        ++hashIndex;
            
        //wrap around the table
        hashIndex %= CAPACITY;
    }      
        
    return NULL;  
}

void add_questions(){
    struct question* q1 = (struct question*) malloc(sizeof(struct question));
    q1->ques = strdup("Which of these best describes an array?");
    q1->a = strdup("A data structure that shows a hierarchical behavior");
    q1->b = strdup("Container of objects of similar types");
    q1->c = strdup("Arrays are immutable once initialised");
    q1->d = strdup("Array is not a data structure");
    q1->count = 1;
    q1->dif = 2;
    q1->sc = 1;
    q1->soln = 2;
    q1->sol = strdup("Container of objects of similar types. Explanation: Array contains elements only of the same type.");
    q1->key = get_key(q1->sc,q1->dif,q1->count);
    insert(q1);

    struct question* q2 = (struct question*) malloc(sizeof(struct question));
    q2->ques = strdup("How do you initialize an array in C?");
    q2->a = strdup("int arr[3] = (1,2,3);");
    q2->b = strdup("int arr(3) = {1,2,3};");
    q2->c = strdup("int arr[3] = {1,2,3};");
    q2->d = strdup("int arr(3) = (1,2,3);");
    q2->count = 1;
    q2->dif = 1;
    q2->sc = 1;
    q2->soln = 3;
    q2->sol = strdup("int arr[3] = {1,2,3}; Explanation: This is the syntax to initialize an array in C.");
    q2->key = get_key(q2->sc,q2->dif,q2->count);
    insert(q2);

    struct question* q3 = (struct question*) malloc(sizeof(struct question));
    q3->ques = strdup("Which of the following concepts make extensive use of arrays?");
    q3->a = strdup("Binary trees");
    q3->b = strdup("Scheduling of processes");
    q3->c = strdup("Caching");
    q3->d = strdup("Spatial locality");
    q3->count = 1;
    q3->dif = 3;
    q3->sc = 1;
    q3->soln = 4;
    q3->sol = strdup("Spatial locality. Explanation: Whenever a particular memory location is referred to, it is likely that the locations nearby are also referred, arrays are stored as contiguous blocks in memory, so if you want to access array elements, spatial locality makes it to access quickly.");
    q3->key = get_key(q3->sc,q3->dif,q3->count);
    insert(q3);

    struct question* q4 = (struct question*) malloc(sizeof(struct question));
    q4->ques = strdup("What are the disadvantages of arrays?");
    q4->a = strdup("Data structure like queue or stack cannot be implemented");
    q4->b = strdup("There are chances of wastage of memory space if elements inserted in an array are lesser than the allocated size");
    q4->c = strdup("Index value of an array can be negative");
    q4->d = strdup("Elements are sequentially accessed");
    q4->count = 1;
    q4->dif = 4;
    q4->sc = 1;
    q4->soln = 2;
    q4->sol = strdup("There are chances of wastage of memory space if elements inserted in an array are lesser than the allocated size. Explanation: Arrays are of fixed size. If we insert elements less than the allocated size, unoccupied positions can’t be used again. Wastage will occur in memory.");
    q4->key = get_key(q4->sc,q4->dif,q4->count);
    insert(q4);

    struct question* q5 = (struct question*) malloc(sizeof(struct question));
    q5->ques = strdup("Assuming int is of 4bytes, what is the size of int arr[15];?");
    q5->a = strdup("15");
    q5->b = strdup("19");
    q5->c = strdup("11");
    q5->d = strdup("60");
    q5->count = 1;
    q5->dif = 5;
    q5->sc = 1;
    q5->soln = 4;
    q5->sol = strdup("60. Explanation: Since there are 15 int elements and each int is of 4bytes, we get 15*4 = 60bytes.");
    q5->key = get_key(q5->sc,q5->dif,q5->count);
    insert(q5);
    
    struct question* q6 = (struct question*) malloc(sizeof(struct question));
    q6->ques = strdup("Process of removing an element from stack is called __________");
    q6->a = strdup("Create");
    q6->b = strdup("Push");
    q6->c = strdup("Evaluation");
    q6->d = strdup("Pop");
    q6->count = 1;
    q6->dif = 6;
    q6->sc = 1;
    q6->soln = 4;
    q6->sol = strdup("Pop. Elements in the stack are removed using pop operation. Pop operation removes the top most element in the stack i.e. last entered element.");
    q6->key = get_key(q6->sc,q6->dif,q6->count);
    insert(q6);

    struct question* q7 = (struct question*) malloc(sizeof(struct question));
    q7->ques = strdup("Which of the following is not the application of stack?");
    q7->a = strdup("A parentheses balancing program");
    q7->b = strdup("Tracking of local variables at run time");
    q7->c = strdup("Compiler Syntax Analyzer");
    q7->d = strdup("Data Transfer between two asynchronous process");
    q7->count = 1;
    q7->dif = 7;
    q7->sc = 1;
    q7->soln = 4;
    q7->sol = strdup("Data Transfer between two asynchronous process. Explanation: Data transfer between the two asynchronous process uses the queue data structure for synchronisation. The rest are all stack applications.");
    q7->key = get_key(q7->sc,q7->dif,q7->count);
    insert(q7);

    struct question* q8 = (struct question*) malloc(sizeof(struct question));
    q8->ques = strdup("What is the value of the postfix expression 6 3 2 4 + - *?");
    q8->a = strdup("1");
    q8->b = strdup("40");
    q8->c = strdup("74");
    q8->d = strdup("-18");
    q8->count = 1;
    q8->dif = 8;
    q8->sc = 1;
    q8->soln = 4;
    q8->sol = strdup("-18. Explanation: Postfix Expression is (6*(3-(2+4))) which results -18 as output.");
    q8->key = get_key(q8->sc,q8->dif,q8->count);
    insert(q8);

    struct question* q9 = (struct question*) malloc(sizeof(struct question));
    q9->ques = strdup("What would be the asymptotic time complexity to insert an element at the front of the linked list (head is known)?");
    q9->a = strdup("O(1)");
    q9->b = strdup("O(n)");
    q9->c = strdup("O(n^2)");
    q9->d = strdup("O(n^3)");
    q9->count = 1;
    q9->dif = 9;
    q9->sc = 1;
    q9->soln = 1;
    q9->sol = strdup("O(1). Explanation: To add an element at the front of the linked list, we will create a new node which holds the data to be added to the linked list and pointer which points to head position in the linked list. The entire thing happens within O (1) time. Thus the asymptotic time complexity is O (1).");
    q9->key = get_key(q9->sc,q9->dif,q9->count);
    insert(q9);

    struct question* q10 = (struct question*) malloc(sizeof(struct question));
    q10->ques = strdup("What is a memory efficient double linked list?");
    q10->a = strdup("Each node has only one pointer to traverse the list back and forth");
    q10->b = strdup("The list has breakpoints for faster traversal");
    q10->c = strdup("An auxiliary singly linked list acts as a helper list to traverse through the doubly linked list");
    q10->d = strdup("A doubly linked list that uses bitwise AND operator for storing addresses");
    q10->count = 1;
    q10->dif = 10;
    q10->sc = 1;
    q10->soln = 1;
    q10->sol = strdup("Each node has only one pointer to traverse the list back and forth. Explanation: Memory efficient doubly linked list has only one pointer to traverse the list back and forth. The implementation is based on pointer difference. It uses bitwise XOR operator to store the front and rear pointer addresses. Instead of storing actual memory address, every node store the XOR address of previous and next nodes.");
    q10->key = get_key(q10->sc,q10->dif,q10->count);
    insert(q10);

    struct question* q11 = (struct question*) malloc(sizeof(struct question));
    q11->ques = strdup("Advantages of linked list representation of binary trees over arrays?");
    q11->a = strdup("dynamic size");
    q11->b = strdup("ease of insertion/deletion");
    q11->c = strdup("ease in randomly accessing a node.");
    q11->d = strdup("both dynamic size and ease in insertion/deletion");
    q11->count = 1;
    q11->dif = 11;
    q11->sc = 1;
    q11->soln = 4;
    q11->sol = strdup("both dynamic size and ease in insertion/deletion. Explanation: It has both dynamic size and ease in insertion and deletion as advantages.");
    q11->key = get_key(q11->sc,q11->dif,q11->count);
    insert(q11);

    struct question* q12 = (struct question*) malloc(sizeof(struct question));
    q12->ques = strdup("Which of the following traversing algorithm is not used to traverse in a tree?");
    q12->a = strdup("Post order");
    q12->b = strdup("Pre order");
    q12->c = strdup("Post order");
    q12->d = strdup("Randomized");
    q12->count = 1;
    q12->dif = 12;
    q12->sc = 1;
    q12->soln = 4;
    q12->sol = strdup("Randomized. Explanation: Generally, all nodes in a tree are visited by using preorder, inorder and postorder traversing algorithms.");
    q12->key = get_key(q12->sc,q12->dif,q12->count);
    insert(q12);

    struct question* q13 = (struct question*) malloc(sizeof(struct question));
    q13->ques = strdup("What is the average case time complexity for finding the height of the binary tree?");
    q13->a = strdup("h = O(loglogn)");
    q13->b = strdup("h = O(nlogn)");
    q13->c = strdup("h = O(n)");
    q13->d = strdup("h = O(log n)");
    q13->count = 1;
    q13->dif = 13;
    q13->sc = 1;
    q13->soln = 4;
    q13->sol = strdup("h = O(log n). Explanation: The nodes are either a part of left sub tree or the right sub tree, so we don’t have to traverse all the nodes, this means the complexity is lesser than n, in the average case, assuming the nodes are spread evenly, the time complexity becomes O(logn).");
    q13->key = get_key(q13->sc,q13->dif,q13->count);
    insert(q13);

    struct question* q14 = (struct question*) malloc(sizeof(struct question));
    q14->ques = strdup("In a full binary tree if number of internal nodes is I, then number of leaves L are?");
    q14->a = strdup("L = 2*I");
    q14->b = strdup("L = I + 1");
    q14->c = strdup("L = I - 1");
    q14->d = strdup("L = 2*I - 1");
    q14->count = 1;
    q14->dif = 14;
    q14->sc = 1;
    q14->soln = 2;
    q14->sol = strdup("L = I + 1. Explanation: Number of Leaf nodes in full binary tree is equal to 1 + Number of Internal Nodes i.e L = I + 1");
    q14->key = get_key(q14->sc,q14->dif,q14->count);
    insert(q14);

    struct question* q15 = (struct question*) malloc(sizeof(struct question));
    q15->ques = strdup("Which of the following is not an application of priority queue?");
    q15->a = strdup("Huffman codes");
    q15->b = strdup("Interrupt handling in operating system");
    q15->c = strdup("Undo operation in text editors");
    q15->d = strdup("Bayesian spam filter");
    q15->count = 1;
    q15->dif = 15;
    q15->sc = 1;
    q15->soln = 3;
    q15->sol = strdup("Undo operation in text editors. Explanation: Undo operation is achieved using a stack.");
    q15->key = get_key(q15->sc,q15->dif,q15->count);
    insert(q15);

    struct question* q16 = (struct question*) malloc(sizeof(struct question));
    q16->ques = strdup("What is the time complexity to insert a node based on key in a priority queue?");
    q16->a = strdup("O(nlogn)");
    q16->b = strdup("O(logn)");
    q16->c = strdup("O(n)");
    q16->d = strdup("O(n^2)");
    q16->count = 1;
    q16->dif = 16;
    q16->sc = 1;
    q16->soln = 3;
    q16->sol = strdup("O(n). Explanation: In the worst case, you might have to traverse the entire list.");
    q16->key = get_key(q16->sc,q16->dif,q16->count);
    insert(q16);

    struct question* q17 = (struct question*) malloc(sizeof(struct question));
    q17->ques = strdup("What is the relation between Sparsity and Density of a matrix?");
    q17->a = strdup("Sparsity = 1 - Density");
    q17->b = strdup("Sparsity = 1 + Density");
    q17->c = strdup("Sparsity = Density*Total number of elements");
    q17->d = strdup("Sparsity = Density/Total number of elements");
    q17->count = 1;
    q17->dif = 17;
    q17->sc = 1;
    q17->soln = 1;
    q17->sol = strdup("Sparsity = 1 - Density. Explanation: Sparsity of a matrix is equal to 1 minus Density of the matrix. The Sparsity of matrix is defined as the total number of Zero Valued elements divided total number of elements.");
    q17->key = get_key(q17->sc,q17->dif,q17->count);
    insert(q17);

    struct question* q18 = (struct question*) malloc(sizeof(struct question));
    q18->ques = strdup("An array consists of n elements. We want to create a heap using the elements. The time complexity of building a heap will be in order of");
    q18->a = strdup("O(n*n*logn)");
    q18->b = strdup("O(n*logn)");
    q18->c = strdup("O(n*n)");
    q18->d = strdup("O(n *logn *logn)");
    q18->count = 1;
    q18->dif = 18;
    q18->sc = 1;
    q18->soln = 2;
    q18->sol = strdup("O(n*logn). Explanation: The total time taken will be N times the complexity of adding a single element to the heap. And adding a single element takes logN time, so That is equal to N*logN.");
    q18->key = get_key(q18->sc,q18->dif,q18->count);
    insert(q18);

    struct question* q19 = (struct question*) malloc(sizeof(struct question));
    q19->ques = strdup("Given an array of element 5, 7, 9, 1, 3, 10, 8, 4. Which of the following are the correct sequences of elements after inserting all the elements in a min-heap?");
    q19->a = strdup("1,3,4,5,7,8,9,10");
    q19->b = strdup("1,4,3,9,8,5,7,10");
    q19->c = strdup("1,3,4,5,8,7,9,10");
    q19->d = strdup("1,3,7,4,8,5,9,10");
    q19->count = 1;
    q19->dif = 19;
    q19->sc = 1;
    q19->soln = 1;
    q19->sol = strdup("1,3,4,5,7,8,9,10. Explanation: Building a min-heap the result will a sorted array so the 1, 3, 4, 5, 7, 8, 9, 10 is correct. If we change the implementation strategy 1, 4, 3, 8, 9, 5, 7, 10 is also correct. (First filling the right child rather than left child first).");
    q19->key = get_key(q19->sc,q19->dif,q19->count);
    insert(q19);
} //Internal function to add the questions

void display_status(struct bank* b){
    printf("No. of Subjects : %i\n",b->sub);
    printf("No. of Questions : %i\n",b->noq);
    int i;
    for(i = 0; i<b->sub; i++){
        printf("Subject : %s, Code : %i", b->list, b->codes[i]);
    }
} //Displays status of question bank

void display() {
   int i = 0;
	
   for(i = 0; i<CAPACITY; i++) {
	
      if(hashArray[i] != NULL)
         printf("(%s,%d)",hashArray[i]->ques,hashArray[i]->key);
      else
         printf(" ~~ ");
   }
	
   printf("\n");
}

int get_key(int sc, int dif, int n){
    return (sc * 100) + (dif * 5) + n;
} //Function to create key

void initialise_bank(struct bank** b){
    *b = (struct bank*) malloc(sizeof(struct bank));
    (*b)->sub = 1;
    (*b)->noq = 20; 
    (*b)->list = strdup("Data Structures & Algorithms");
    (*b)->codes = malloc(sizeof(int));
    (*b)->codes[0] = 1;
}
//Questions are separated in the list by a comma


struct element* pq[SIZE];

struct track* answers[SIZE];


void enqueue(struct question** que, int priority){
    // Increase the size
    size++;
 
    // Insert the element
    pq[size] = (struct element*) malloc(sizeof(struct element));
    pq[size]->question = (*que);
    pq[size]->priority = priority;
}

int peek_cr(){
    int highestPriority = INT_MAX;
    int ind = -1;

    //Correct - It will take the absolute value of priority and only return the least priority among the 
    //questions which have a positive priority.
    for (int i = 0; i <= size; i++) {
 
        if (pq[i]->priority > 0 && highestPriority > pq[i]->priority) {
            highestPriority = pq[i]->priority;
            ind = i;
        }
    }
 
    // Return position of the element
    return ind;
}

int peek_wr(){
    int highestPriority = INT_MAX;
    int ind = -1;
    
    //Wrong - It will take the absolute value of priority and only return the least priority among the 
    //questions which have a negative priority.
    for (int i = 0; i <= size; i++) {
 
        if (pq[i]->priority < 0 && highestPriority > abs(pq[i]->priority)) {
            highestPriority = abs(pq[i]->priority);
            ind = i;
        }
    }
 
    // Return position of the element
    return ind;
}

void clear(){
    for (int i = 0; i <= size; i++){
        pq[i] = NULL;
    }
    size = -1;
} //clears the queue array

void dequeue(int res){
    // res is 0 if previous was wrong
    // res is 1 if previous was correct
    // Find the position of the element
    // with highest priority
    int ind, i;

    if(res == 1)
        ind = peek_cr();
    else
        ind = peek_wr();

    for (i = ind; i < size; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
}

void initialise_pq(int sc, int low, int high){
    int i, k;
    int mid = 10;
    for(i = low + 1; i <= high; i++){
        srand(time(0));
        k = get_key(sc,i,randoms(1,1));
        struct question* q = search(k);
        //printf("%s",q->ques);
        enqueue(&q,i-mid);
    }
} //Adding all question to the pq (subject code, low diff, high diff)

void update_answers(int a, int key){
 
    // Insert the element
    answers[answered] = (struct track*) malloc(sizeof(struct track));
    answers[answered]->a = a;
    answers[answered]->key = key;

    answered++;
}//update the answers array

int count_correct(){
    int i;
    int c = 0;
    for(i = 0; i < answered; i++){
         if (answers[i]->a == 1)
            c += 1;
    }
    return c;
}

int count_wrong(){
    int i;
    int c = 0;
    for(i = 0; i < answered; i++){
         if (answers[i]->a == 0)
            c += 1;
    }
    return c;
}

void display_pq(){
    int i;
    for(i = 0; i <= size; i++){
        printf("%s, %i \n",pq[i]->question->ques, pq[i]->priority);
    }
}

void dequeuezero(){
    int i, ind, j;
    for(i = 0; i<=size;i++){
        if(pq[i]->priority == 0){
            ind = i;
            break;
        }
    }
    for (j = ind; j < size; j++) {
        pq[j] = pq[j + 1];
    }
    size--;
}

int peek_0(){
    int i;
    for(i = 0; i<=size;i++){
        if(pq[i]->priority == 0){
            return i;
        }
    }
    return 0;
}

void clear_answers(){
    for (int i = 0; i <= answered; i++){
        answers[i] = NULL;
    }
    answered = 0;
}

void quiz_main(int sc, struct bank* b){
    initialise_pq(sc,5,15);
    //display_pq();
    int index, ans, a, z = 0, a1, k = 0;
    index = peek_0();
    printf("\nQ1.%s (Dif-%i)\n",pq[index]->question->ques,pq[index]->question->dif);
    printf("A:%s\n",pq[index]->question->a);
    printf("B:%s\n",pq[index]->question->b);
    printf("C:%s\n",pq[index]->question->c);
    printf("D:%s\n",pq[index]->question->d);
    printf("Enter Answer (1-A, 2-B, 3-C, 4-D) : ");
    scanf("%d",&ans);
    if(ans == pq[index]->question->soln)
        a = 1;
    else
        a = 0;
    update_answers(a,pq[index]->question->key);
    if(a == 0){
        printf("Solution : %s\n", pq[index]->question->sol);
        dequeuezero();
        index = peek_wr();
        a1 = 0;
    }
    else if(a == 1){
        printf("Correct!\n");
        dequeuezero();
        index = peek_cr();
        a1 = 1;
    }
    while(answered < 10){
        printf("\nQ%i.%s (Dif-%i)\n",answered+1,pq[index]->question->ques,pq[index]->question->dif);
        printf("A:%s\n",pq[index]->question->a);
        printf("B:%s\n",pq[index]->question->b);
        printf("C:%s\n",pq[index]->question->c);
        printf("D:%s\n",pq[index]->question->d);
        printf("Enter Answer (1-A, 2-B, 3-C, 4-D) : ");
        scanf("%d",&ans);
        if(ans == pq[index]->question->soln)
            a = 1;
        else
            a = 0;
        update_answers(a,pq[index]->question->key);
        if(a == 0){
            printf("Solution : %s\n", pq[index]->question->sol);
        }
        else if(a == 1){
            printf("Correct!\n");
        }
        if(k == 0 && count_correct() == 5 && answered < 10){
            restructure_correct(sc);
            z = 1;
            k = 1;
        }
        if(k == 0 && count_wrong() == 5 && answered < 10){
            restructure_wrong(sc);
            z = 1;
            k = 1;
        }
        if(z == 1){
            index = peek_0();
            //display_pq();
            z = 2;
        }
        else if(z == 2){
            dequeuezero();
            if(a == 0){
                index = peek_wr();
            }
            else if(a == 1){
                index = peek_cr();
            }
            z = 0;
        }
        else if(a == 0){
            if(a1 == 0)
                dequeue(0);
            else
                dequeue(1);
            index = peek_wr();
        }
        else if(a == 1){
            if(a1 == 0)
                dequeue(0);
            else
                dequeue(1);
            index = peek_cr();
        }
        a1 = a;
    }
} //Creates quiz, iterates through it, restructres it based on correct/wrong count and iterates 
//till 10 questions are answered

void restructure_main(int sc, int d){
    if(d == 1){
        int i,j;
        int x = count_wrong();
        for(int i = (5-x); i < 10-x; i++){
            srand(time(0));
            struct question* q = search(get_key(sc,i,randoms(1,1)));
            enqueue(&q,i - 15);
        }
        for(j = 15; j < 20; j++){
            srand(time(0));
            struct question* q = search(get_key(sc,j,randoms(1,1)));
            enqueue(&q,j - 15);
        }
    }
    else if(d == 0)
    {
        int i,j;
        int y = count_correct();
        for(i = (10+y+1); i < 15+y+1; i++){
            srand(time(0));
            struct question* q = search(get_key(sc,i,randoms(1,1)));
            enqueue(&q,i - 5);
        }
        for(j = 1; j < 6; j++){
            srand(time(0));
            struct question* q = search(get_key(sc,j,randoms(1,1)));
            enqueue(&q,j - 5);
        }
    }
    
} //Restructure main function, d decides if it was called from correct(d == 1) or wrong(d == 0) restructure function

void restructure_correct(int sc){
    clear();
    restructure_main(sc,1);
} //restructures and re intialises the pq with new high & low

void restructure_wrong(int sc){
    clear();
    restructure_main(sc,0);
}

struct user* update_user(struct user* user, int sc, struct bank* b){
    //correct questions should be more than 5 to pass the subject
    int i,j,k;
    int q = count_correct();
    //int* new = (int*) malloc(sizeof(int)*10);
    int n = 0;
    bool isthere = false;
    if(user->completed[sc-1] == 0 && user->qc == 0){
        if(q > 5){    
            user->completed[sc-1] = 1;}
        j=user->qc;
        user->qc += q;
        for(k=0; k<answered;k++){
            if(answers[k]->a == 1){
                user->solved[j] = answers[k]->key;
                j++;
            }
        }
    }
    else{
        int k = user->qc;
        int l = user->qc;
        if(q > 5 && user->completed[sc-1] == 0){    
            user->completed[sc-1] = 1;}
        for(i=0;i<answered;i++){
            if(answers[i]->a == 1){
                for(j=0;j<user->qc;j++){
                    if(user->solved[j] == answers[i]->key){
                        isthere = true;
                        break;
                    }   
                }
            if(isthere == false){
                user->solved[k] = answers[i]->key;
                n++;
                k++;
            }
            isthere = false;
            }
        }
        user->qc = l + n;
    }
        
    update_user_file(user,b);
    clear_answers();
    return user;
} //updates based on array input

struct user* starting_page(struct user* user,struct bank* b){
    char s1[30];
    char s2[30];
    int l;
    printf("Sign IN(Enter 1)/ Log IN(Enter 0) : ");
    scanf("%d",&l);
    
    if(l == 0){
        while ((getchar()) != '\n');
        printf("Enter Username: ");
        fgets(s1,30,stdin);
        printf("Enter Password: ");
        fgets(s2,30,stdin);
        //bool b;
        //b = find_user(s1,s2);
        (user) = get_user((user), s1,s2);

        return (user);
    }
    
    while ((getchar()) != '\n');
    printf("Enter Username: ");
    fgets(s1,30,stdin);
    char s3[30];
    do{
        printf("Enter Password: ");
        fgets(s2,30,stdin);
        printf("Confirm Password: ");
        fgets(s3,30,stdin);
    }
    while(strcmp(s2,s3) != 0); 
    (user) = user_initialisation(s1,s2,b);
    add_user((user),b);
    return (user);
}

/*
bool find_user(char* username, char* password){
    int length;
    int bufferLength = 255;
    char buffer1[bufferLength];
    char buffer2[bufferLength];
    length = snprintf(NULL, 0,"%d",1);
    char str[length+1];
    int i = 1;
    sprintf(str, "%d", i);
    char* extension = ".txt";
    char fileSpec[strlen(str)+strlen(extension)+1];

    snprintf( fileSpec, sizeof( fileSpec ), "%s%s", str, extension );
    FILE* fptr;
    while(access(fileSpec,F_OK) == 0){
        fptr = fopen(fileSpec,"r");
        fgets(buffer1, bufferLength, fptr);
        fgets(buffer2, bufferLength, fptr);
        if(strcmp(username,buffer1) == 0){
            if(strcmp(password,buffer2) == 0){
                return true;
            }
            else{
                return false;
            }
        }
        i++;
        sprintf(str, "%d", i);
        snprintf( fileSpec, sizeof( fileSpec ), "%s%s", str, extension );
    }
    fclose(fptr);
    return false;
} //Reading from files to find the concerned user
*/

struct user* get_user(struct user* user, char* username, char* password){
    int length;
    int bufferLength = 25;
    char buffer1[bufferLength];
    char buffer2[bufferLength];
    length = snprintf(NULL, 0,"%d",1);
    char str[length+1];
    int i = 1;
    sprintf(str, "%d", i);
    char* extension = ".txt";
    char fileSpec[strlen(str)+strlen(extension)+1];
    password[strcspn(password,"\n")] = 0;
    username[strcspn(username,"\n")] = 0;
    snprintf( fileSpec, sizeof( fileSpec ), "%s%s", str, extension );
    FILE* fptr;
    int k,z;
    while(access(fileSpec,F_OK) == 0){
        fptr = fopen(fileSpec,"r");
        k = 0;
        z = 0;
        while(k < 2){
            fscanf(fptr, "%s", &buffer1);
            //strncmp(username,buffer1,strlen(username)-1)
            if(k == 0 && strncmp(username,buffer1,strlen(username)) == 0){
                z++;
            }
            if(k == 1 && strncmp(password,buffer1,strlen(password)) == 0){
                z++;
            }
            k++;
        }
        if(z == 2){
            break;
        }
        i++;
        sprintf(str, "%d", i);
        snprintf( fileSpec, sizeof( fileSpec ), "%s%s", str, extension );
    }
    user = (struct user*) malloc(sizeof(struct user));
    user->username = strdup(username);
    user->password = strdup(password);
    int j,l;
    user->completed = malloc(sizeof(int)*1);
    for(j =0; j < 1;j++){
        fscanf(fptr, "%i", &l);
        user->completed[j] = l;
    }
    fscanf(fptr, "%i", &l);
    user->qc = l;
    user->solved = malloc(sizeof(int)*CAPACITY);
    for(j =0; j < user->qc;j++){
        fscanf(fptr, "%i", &l);
        user->solved[j] = l;
    }
    fclose(fptr);
    return user;
}

void add_user(struct user* user, struct bank* b){
    int length;
    length = snprintf(NULL, 0,"%d",1);
    char str[length+1];
    int i = 1;
    sprintf(str, "%d", i);
    char* extension = ".txt";
    char fileSpec[strlen(str)+strlen(extension)+1];

    snprintf( fileSpec, sizeof( fileSpec ), "%s%s", str, extension );
    while(access(fileSpec,F_OK) == 0){
        i++;
        sprintf(str, "%d", i);
        snprintf( fileSpec, sizeof( fileSpec ), "%s%s", str, extension );
    }
    FILE* fptr;
    fptr = fopen(fileSpec, "w");
    fputs(user->username,fptr);
    fputs(user->password,fptr);
    for(i =0; i < b->sub;i++){
        fprintf(fptr, "%d\n", user->completed[i]);
    }
    fprintf(fptr, "%d\n", user->qc);
    for(i =0; i < user->qc;i++){
        fprintf(fptr, "%d\n", user->solved[i]);
    }
    fclose(fptr);
    
} //Writing to files

struct user* user_initialisation(char* username, char* password, struct bank* b){
    struct user* user = (struct user*) malloc(sizeof(struct user));
    user->username = strdup(username);
    user->password = strdup(password);
    int i;
    user->completed = malloc(sizeof(int)*b->sub);
    for(i =0; i < b->sub;i++){
        user->completed[i] = 0;
    }
    user->qc = 0;
    user->solved = malloc(sizeof(int)*CAPACITY);
}

void update_user_file(struct user* user, struct bank* b){
    int length;
    int bufferLength = 255;
    char buffer1[bufferLength];
    char buffer2[bufferLength];
    length = snprintf(NULL, 0,"%d",1);
    char str[length+1];
    int i = 1;
    sprintf(str, "%d", i);
    char* extension = ".txt";
    char fileSpec[strlen(str)+strlen(extension)+1];
    int k,z;
    user->password[strcspn(user->password,"\n")] = 0;
    user->username[strcspn(user->username,"\n")] = 0;
    snprintf( fileSpec, sizeof( fileSpec ), "%s%s", str, extension );
    FILE* fptr;
    while(access(fileSpec,F_OK) == 0){
        fptr = fopen(fileSpec,"r");
        k = 0;
        z = 0;
        while(k < 2){
            fscanf(fptr, "%s", &buffer1);
            //strncmp(username,buffer1,strlen(username)-1)
            if(k == 0 && strncmp(user->username,buffer1,strlen(user->username)) == 0){
                z++;
            }
            if(k == 1 && strncmp(user->password,buffer1,strlen(user->password)) == 0){
                z++;
            }
            k++;
        }
        if(z == 2){
            break;
        }
        i++;
        sprintf(str, "%d", i);
        snprintf( fileSpec, sizeof( fileSpec ), "%s%s", str, extension );
    }
    fclose(fptr);
    FILE* fp;
    fp = fopen(fileSpec,"w");
    fputs(user->username,fp);
    fputs("\n",fp);
    fputs(user->password,fp);
    fputs("\n",fp);
    for(i =0; i < b->sub;i++){
        fprintf(fp, "%d\n", user->completed[i]);
    }
    fprintf(fp, "%d\n", user->qc);
    for(i =0; i < user->qc;i++){
        fprintf(fp, "%d\n", user->solved[i]);
    }
    fclose(fp);
} //Update user file


void display_progress_report(struct user* user, struct bank* b){
    int i,j,k,n;
    printf("Username : %s\n",user->username);
    printf("Subjects Completed : \n");
    n = 0;
    for(i = 0; i < b->sub; i++){
        if(user->completed[i] == 1){
            printf("%s\n",b->list);
            n++;
        }
    }
    if(n == 0){
        printf("None\n");
    }
    printf("Questions Completed : %i\n",user->qc);
    float x1,x2,x3;
    x1 = user->qc;
    x2 = b->noq;
    x3 = x1/x2;
    x3 = x3*100;
    printf("Percentage of Questions Left : %.2f %%.\n", x3);
}

struct user* reset(struct user* user, struct bank* b){
    user = user_initialisation(user->username, user->password, b);
    update_user_file(user,b);
    return user;
}

void solutions_review(struct user* user){
    int i;
    for(i = 0; i < user->qc; i++){
        struct question* q = search(user->solved[i]);
        printf("\nQ%i.%s\n",i+1,q->ques);
        printf("Option %i : ",q->soln);
        printf("%s\n",q->sol);
    }
}

//void quit(){}

//Extra Functions
int randoms(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

//if (access(fname, F_OK) == 0) {
    // file exists
//} else {
    // file doesn't exist
//}

//int bufferLength = 255;
//char buffer[bufferLength];
//int* array = (int*)malloc(sizeof(int)*MAX);

  //while (fgets(buffer, bufferLength, fp)){
    //array[size++] = atoi(buffer);
  //}
/*
int stringcompare(char *a,char *b)  
{  
   int flag=0;  
    while(*a!='\0')  // while loop  
    {  
        if(*a!=*b)  
        {  
            flag=1;  
        }  
        a++;  
        b++;  
    }  
    if(flag==0)  
        return 0;  
    else  
        return 1;  
}
*/