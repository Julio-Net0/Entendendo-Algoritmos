#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct{
  Node* head;
  Node* tail;
  int size;
} LinkedList;

LinkedList* createList(){
  LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));

  if(list == NULL){
    return NULL;
  }

  list -> head = NULL;
  list -> tail = NULL;
  list -> size = 0;
  return list;
}

Node *createNode(int value){
  Node* newNode = (Node*)malloc(sizeof(Node));
  if(newNode != NULL){
    newNode->data = value;
    newNode->next = NULL;
  }
  return newNode;
}

void append(LinkedList* list, int value){
  Node *newNode = createNode(value);

  if(newNode == NULL) return;

  if(list->head == NULL){
    list->head = newNode;
    list->tail = newNode;
  }else{
    list->tail->next = newNode;
    list->tail = newNode;
  }

  list->size++;
}

void prepend(LinkedList* list, int value){
  Node *newNode = createNode(value);

  if(newNode == NULL) return;

  if(list->head == NULL){
    list->head = newNode;
    list->tail = newNode;
  }else{
    newNode->next = list->head;
    list->head = newNode;
  }
  list->size++;
}

void insert(LinkedList* list, int value, int index){
  
  if(index == 0 || index == -list->size){
    prepend(list, value);
    return;
  }

  if(index == list->size){
    append(list, value);
    return;
  }

  if(index > list->size || index < -list->size) return;

  if(index < 0){
    index += list->size;
  }

  Node* indexNode = list->head;

  for(int i = 0; i < index - 1; i++){
    indexNode = indexNode->next;
  }

  Node* newNode = createNode(value);

  if(newNode == NULL) return;

  newNode->next = indexNode->next;
  indexNode->next = newNode;
  list->size++;
}

void pop(LinkedList* list, int index){

  if(list->size == 0) return;
  if(index >= list->size || index < -list->size) return;
  
  Node* removedNode;

  if(index == 0 || index == -list->size){
    removedNode = list->head;
    list->head = list->head->next;

    if(list->head == NULL){
      list->tail = NULL;
    }

    list->size--;
    free(removedNode);
    return;
  }

  if(index < 0){
    index += list->size;
  }

  Node* prevNode = list->head;

  for(int i = 0; i < index - 1; i++){
    prevNode = prevNode->next;
  }
  
  removedNode = prevNode->next;
  prevNode->next = removedNode->next;

  if(removedNode == list->tail){
    list->tail = prevNode;
  }

  free(removedNode);
  list->size--;
}

void printList(LinkedList* list){

  if(list==NULL){
    printf("NULL\n");
    return;
  }

  Node* node = list->head;

  while(node != NULL){
    printf("%d -> ", node->data);
    node = node->next;
  }
  printf("NULL\n");
}

void freeListMemory(LinkedList* list){
  if(list == NULL) return;

  Node* node = list->head;

  while (node != NULL) {
    Node* nextNode = node->next;
    free(node);
    node = nextNode;
  }

  free(list);
}

int main()
{
  LinkedList* myList = createList();
  printList(myList);
  printf("\n");

  append(myList, 10);
  append(myList, 20);
  append(myList, 30);
  append(myList, 40);
  append(myList, 50);
  printList(myList);
  printf("\n");

  prepend(myList, 5);
  prepend(myList, 3);
  prepend(myList, 1);
  printList(myList);
  printf("\n");

  insert(myList, 2, 1);
  insert(myList, 4, 3);
  insert(myList, 0, 0);
  insert(myList, 45, -1);
  insert(myList, 35, -3);
  printList(myList);
  printf("\n");

  pop(myList, 6);
  pop(myList, 0);
  pop(myList, -1);
  printList(myList);
  printf("\n");

  freeListMemory(myList);

  return EXIT_SUCCESS;
}
