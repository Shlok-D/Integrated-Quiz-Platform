#ifdef WIN32
#include <io.h>
#define F_OK 0
#define access _access
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define CAPACITY 200

typedef struct question{
    int dif;  // Difficulty of Question
    int sc;   // Subject Code
    int count;  //Question No. of that Subject+Difficulty
    int key; //Subject/Topic + Difficulty(1-20) + nth question of that Subject & Difficulty
    int soln; // 1-A, 2-B, 3-C, 4-D
    char* ques; // Question
    char* sol;  // Solution Option String 
    char* a; // Option a
    char* b; //b
    char* c; //c
    char* d; //d
}question;

typedef struct bank{
    int sub; //No. of Subjects
    int noq; //No. of Questions
    char* list; //Subjects List
    int* codes; //subject codes
}bank;

struct question* hashArray[CAPACITY];

int hashCode(int key);
struct question* search(int key);
void insert(struct question* que);
struct question* delete(int key);
void add_questions(); //Internal function to add the questions
void display_status(struct bank* b); //Displays status of question bank
int get_key(int sc, int dif, int n); //Function to create key
void initialise_bank(struct bank** b);
void display();

#define SIZE 10
//Size of Priority Queue

typedef struct element {
    struct question* question;
    int priority; //difference between the difficulties(difficulty of question - 10)
}element;


typedef struct track{
    int a; //Correct - 1, Wrong -0
    int key;//key of the question
}track;


void enqueue(struct question** que, int priority); 
int peek_cr();
int peek_wr();
int peek_0();
void clear(); //clears the queue array
void dequeue(int res);
void initialise_pq(int sc, int low, int high); //Adding all question to the pq (subject code, low diff, high diff)
void update_answers(int a, int key); //update the answers array
int count_correct();
int count_wrong();
void dequeuezero();
void clear_answers();

void quiz_main(int sc, struct bank* b); //Creates quiz, iterates through it, restructres it based on correct/wrong count and iterates 
//till 10 questions are answered

void restructure_main(int sc, int d);
void restructure_correct(int sc); //restructures and re intialises the pq with new high & low
void restructure_wrong(int sc);
struct user* update_user(struct user* user, int sc, struct bank* b); //updates based on array input

typedef struct user{
    char* username; //username of user
    char* password; //passwords of user
    int qc; //no. questions completed correctly
    int* completed; //Subjects Completed Array Input (1-Completed, 0-Not-Completed)
    int* solved; //array of keys for questions solved correctly
}user;


struct user* starting_page(struct user* user, struct bank* b);
//bool find_user(char* username, char* password); //Reading from files to find the concerned user
void add_user(struct user* user, struct bank* b); //Writing to files
struct user* get_user(struct user* user,char* username, char* password); //To get user in login session
struct user* user_initialisation(char* username, char* password, struct bank* b);
void update_user_file(struct user* user, struct bank* b); //Update user file
void display_progress_report(struct user* user,struct bank* b);
struct user* reset(struct user* user, struct bank* b);
void solutions_review(struct user* user);
//void quit(); //closes all files, frees memory etc

int randoms(int lower, int upper);
//int stringcompare(char *a,char *b);  
void display_pq();
#endif