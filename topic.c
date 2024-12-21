#include "def.h"

int main(int ac, char **av) {
  t_topic *my_topic;

  if ((my_topic = (t_topic*)malloc(sizeof(t_topic))) != NULL) {
    
    my_topic->ID = 100;
    my_topic->sz_name = "Log Topic";
    
    printf("topic ID = %d\n", my_topic->ID);
    printf("topic name = %s\n", my_topic->sz_name);
    
    free(my_topic);
  } else {
    printf("Topic malloc error\n");
  }
  
  return 0;
}
