#include "def.h"


int add_topic(t_topicLinkedList *topicLList, char *sz_topicName, int ID_) {

  t_topic *new_topic;
  
  if (topicLList == NULL) {
    return -1;
  }

  if (topicLList->size >= TOPIC_LIST_MAX_TOPICS) {
    printf("max topic linked size reached !");
    return -1;
  }

  if ((new_topic = (t_topic*)malloc(sizeof(t_topic))) == NULL)  {
    printf("add_topic: malloc error\n");
  } else {
    new_topic->ID = ID_;
    new_topic->sz_name = sz_topicName;
    
    new_topic->next = NULL;
    new_topic->prev = topicLList->last;
  
    if (topicLList->first == NULL) {
      topicLList->first = new_topic;
    } 
    topicLList->last->next = new_topic;
    topicLList->size++;      

    topicLList->last = new_topic;
    
  }
}

int del_topic(t_topicLinkedList *topicList, int ID) {
  if (topicList == NULL || topicList->size <= 0) {
    printf("topic linked either NULL or empty size reached !");
    return -1;
  } else {
    t_topic *run = topicList->first;
    while (run != NULL) {
      if (run->ID == ID_) {
	printf("suppressing : topic#%d named %s\n", run->ID, run->sz_name);
	if (run == topicList->first) {
	  topicList->first = topicList->next;
	  topicList->prev = NULL;
	} else if (run == topicList->last) {
	  topicList->last = topicList->last->prev;
	  topicList->last->next = NULL;
	}
	free(run);
	topicList->size--;
	return 0;
      }
      run = run->next;
    }
  }
  return -1;
}

t_topic *find_topic_byID(int ID) {
  if (topicList == NULL || topicList->size <= 0) {
    printf("topic linked either NULL or empty size reached !");
    return -1;
  } else {
    t_topic *run = topicList->first;
    while (run != NULL) {
      if (run->ID == ID_) {
	return run;
      }
      run = run->next;
    }
  }
  
  return NULL;
  
}

t_topic *find_topic_by_name(char *name_) {
  if (topicList == NULL || topicList->size <= 0) {
    printf("topic linked either NULL or empty size reached !");
    return -1;
  } else {
    t_topic *run = topicList->first;
    while (run != NULL) {
      if (strcmp(run->sz_name, name_) == 0) {
	return run;
      }
      run = run->next;
    }
  }
  
  return NULL;
  
}
