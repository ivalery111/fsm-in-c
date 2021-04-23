#ifndef FSM_H
#define FSM_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

enum {
  FSM_NAME_SIZE = 32,          /* Finite State Machine Name Size */
  FSM_STATE_NAME_SIZE = 32,    /* State Name Size */
  FSM_TRANS_KEY_SIZE = 64,     /* Transition Key Size */
  FSM_TRANS_TABLE_SIZE = 128,  /* Transition Table Size */
  FSM_MAX_INP_BUFF_SIZE = 128, /* Maximumal Input Buffer Size */
};

typedef struct fsm_state_s fsm_state_t;

/* Transition table  entry*/
typedef struct fsm_trans_table_entry_s {
  char key[FSM_TRANS_KEY_SIZE];
  size_t key_size;

  fsm_state_t *next_state;
} fsm_trans_table_entry_t;

/* Transition table */
typedef struct fsm_trans_table_s {
  fsm_trans_table_entry_t entries[FSM_TRANS_TABLE_SIZE];
} fsm_trans_table_t;

typedef struct fsm_state_s {
  char name[FSM_STATE_NAME_SIZE];

  bool is_final_state;
} fsm_state_t;

typedef struct fsm_s {
  char name[FSM_NAME_SIZE];

  fsm_state_t *init_state;
} fsm_t;

/**
 * APIs
 */
fsm_t *fsm_create(const uint8_t *const fsm_name);

fsm_state_t *fsm_create_state(const uint8_t *const state_name,
                              const bool is_final);

#endif
