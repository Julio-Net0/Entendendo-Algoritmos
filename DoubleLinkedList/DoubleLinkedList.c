#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
  struct Node* previous;
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
    newNode->previous = NULL;
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
    newNode->previous = list->tail;
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
    list->head->previous = newNode;
    newNode->next = list->head;
    list->head = newNode;
  }
  list->size++;
}

Node* searchNode(LinkedList *list, int index){
  Node* searchedNode;

  if(index < list->size / 2){
    searchedNode = list->head;
    for(int i = 0; i < index; i++){
      searchedNode = searchedNode->next;
    }
  }else{
    searchedNode = list->tail;
    for(int i = list->size - 1; i > index; i--){
      searchedNode = searchedNode->previous;
    }
  }
  return searchedNode;
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

  Node* nextNode = searchNode(list, index);
  Node* prevNode = nextNode->previous;

  Node* newNode = createNode(value);

  if(newNode == NULL) return;

  newNode->next = nextNode;
  newNode->previous = prevNode;

  prevNode->next = newNode;

  nextNode->previous = newNode;

  list->size++;
}

void pop(LinkedList* list, int index){

  if(list->size == 0) return;
  if(index >= list->size || index < -list->size) return;
  
  Node* removedNode;

  if(index < 0){
    index += list->size;
  }

  if(index == 0){
    removedNode = list->head;
    list->head = list->head->next;

    if(list->head != NULL){
      list->head->previous = NULL;
    }else{
      list->tail = NULL;
    }

    list->size--;
    free(removedNode);
    return;
  }
  if(index == list->size-1){
    removedNode = list->tail;
    list->tail = list->tail->previous;

    if(list->tail != NULL){
      list->tail->next = NULL;
    }else{
      list->head = NULL;
    }

    list->size--;
    free(removedNode);
    return;
  }

  removedNode = searchNode(list, index);
  Node* prevNode = removedNode->previous;
  Node* nextNode = removedNode->next;

  prevNode->next = nextNode;
  nextNode->previous = prevNode;

  free(removedNode);
  list->size--;
  return;
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

  append(myList, 1);
  append(myList, 3);
  append(myList, 4);

  insert(myList, 2, 1);

  printList(myList);
  printf("\n");
  return EXIT_SUCCESS;
}
