#include "def.h"


int add_topic(char *sz_topicName, int ID) {
  if (topicLinkedList->last == NULL) {
    
    if ((topicLinkedList->last = (t_topic*)malloc(sizeof(t_topic))) == NULL) {
      printf("add_topic: malloc error\n");
    } else {
      topicLinkedList->last->next = NULL;
      topicLinkedList->last->prev = NULL;
      
      topicLinkedList->first = topicLinkedList->last;
    }    
  } else {
    topicLinkedList->last->next = (t_topic*)malloc(sizeof(t_topic));
    topicLinkedList->last->next->prev = topicLinkedList->last;
    topicLinkedList->last = topicLinkedList->last->next;
    topicLinkedList->last->next = NULL;
  }
}
