#ifndef TOPIC_LINKED_LIST
#define TOPIC_LINKED_LIST

#include "def.h"

#define TOPIC_LIST_MAX_TOPICS 1024

typedef struct st_topicLinkedList {
  t_topic *first;
  t_topic *last;

  int size;
  
} t_topicLinkedList;

#endif
