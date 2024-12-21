#ifndef TOPIC_H
#define TOPIC_H

typedef struct st_topic {
  int ID;
  char *sz_name;
  
#define STATUS_TOPIC_CLOSED
#define STATUS_TOPIC_OPENED
  
  int status;
  
  // topics are kept in a doubly linked list
  struct st_topic *next; 
  struct st_topic *prev;
  
} t_topic;

#endif
