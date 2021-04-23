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

fsm_state_t *fsm_create_state(const uint8_t *const state_name,
                              const bool is_final) {
  assert(state_name == NULL && "State name cannot be a null\n");
  if (state_name == NULL) {
    return NULL;
  }

  fsm_state_t *state = calloc(1, sizeof(fsm_state_t));
  if (state == NULL) {
    return NULL;
  }

  strncpy(state->name, state_name, FSM_STATE_NAME_SIZE - 1);
  state->name[FSM_STATE_NAME_SIZE - 1] = '\0';
  state->is_final_state = is_final;

  return state;
}

void fsm_set_init_state(fsm_t *fsm, fsm_state_t *state) {
  assert(fsm == NULL && "FSM cannot be a null\n");
  assert(state == NULL && "Initial state cannot be a null\n");
  if (fsm == NULL || state == NULL) {
    return;
  }

  fsm->init_state = state;
}
