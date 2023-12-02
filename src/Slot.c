//
// Created by Olcay Taner YILDIZ on 3.06.2023.
//

#include <stdlib.h>
#include <StringUtils.h>
#include <string.h>
#include <stdio.h>
#include <Memory/Memory.h>
#include "Slot.h"
#include "Dictionary/Word.h"

Slot_ptr create_slot(Slot_type type, const char *tag) {
    Slot_ptr result = malloc_(sizeof(Slot), "create_slot");
    result->type = type;
    result->tag = str_copy(result->tag, tag);
    return result;
}

Slot_ptr create_slot2(const char *slot) {
    Slot_ptr result = malloc_(sizeof(Slot), "create_slot2");
    if (strcmp(slot, "O") == 0 || strcmp(slot, "o") == 0){
        result->type = O;
        result->tag = NULL;
    } else {
        String_ptr _type = substring(slot, 0, str_find_c(slot, "-"));
        String_ptr _tag = substring2(slot, str_find_c(slot, "-") + 1);
        if (string_equals2(_type, "B")){
            result->type = B;
        } else {
            result->type = I;
        }
        result->tag = str_copy(result->tag, _tag->s);
        free_string_ptr(_type);
        free_string_ptr(_tag);
    }
    return result;
}

char* slot_to_string(Slot_ptr slot) {
    char* result;
    if (slot->type == O){
        result = malloc_(2 * sizeof(char), "slot_to_string");
        sprintf(result, "O");
    } else {
        result = malloc_((3 + strlen(slot->tag)) * sizeof(char), "slot_to_string");
        if (slot->type == B){
            sprintf(result, "B-%s", slot->tag);
        } else {
            sprintf(result, "I-%s", slot->tag);
        }
    }
    return result;
}

void free_slot(Slot_ptr slot) {
    free_(slot->tag);
    free_(slot);
}
