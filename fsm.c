#include "fsm.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

fsm_t *fsm_create(const uint8_t *const fsm_name) {
  assert(fsm_name != NULL && "FSM Name cannot be a null");
  if (fsm_name == NULL) {
    return NULL;
  }

  fsm_t *fsm = calloc(1, sizeof(fsm_t));
  if (fsm == NULL) {
    return NULL;
  }

  strncpy(fsm->name, fsm_name, FSM_NAME_SIZE - 1);
  fsm->name[FSM_NAME_SIZE - 1] = '\0';

  return fsm;
}
