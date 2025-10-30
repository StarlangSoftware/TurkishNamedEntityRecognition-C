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

/**
 * Constructor for the Slot object. Slot object stores the information about more specific entities. The slot
 * type represents the beginning, inside or outside the slot, whereas tag represents the entity tag of the
 * slot.
 * @param type Type of the slot. B, I or O for beginning, inside, outside the slot respectively.
 * @param tag Tag of the slot.
 */
Slot_ptr create_slot(Slot_type type, const char *tag) {
    Slot_ptr result = malloc_(sizeof(Slot));
    result->type = type;
    result->tag = str_copy(result->tag, tag);
    return result;
}

/**
 * Second constructor of the slot for a given slot string. A Slot string consists of slot type and slot tag
 * separated with '-'. For example B-Person represents the beginning of a person. For outside tagging simple 'O' is
 * used.
 * @param slot Input slot string.
 */
Slot_ptr create_slot2(const char *slot) {
    Slot_ptr result = malloc_(sizeof(Slot));
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

/**
 * slot_to_string method of the slot.
 * @return Type and tag separated with '-'. If the type is outside, it returns 'O'.
 */
char* slot_to_string(Slot_ptr slot) {
    char* result;
    if (slot->type == O){
        result = malloc_(2 * sizeof(char));
        sprintf(result, "O");
    } else {
        result = malloc_((3 + strlen(slot->tag)) * sizeof(char));
        if (slot->type == B){
            sprintf(result, "B-%s", slot->tag);
        } else {
            sprintf(result, "I-%s", slot->tag);
        }
    }
    return result;
}

/**
 * Destructor of the Slot object. Frees memory allocated for tag.
 * @param slot Slot object to deallocate.
 */
void free_slot(Slot_ptr slot) {
    free_(slot->tag);
    free_(slot);
}
