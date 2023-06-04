//
// Created by Olcay Taner YILDIZ on 3.06.2023.
//

#include <stdlib.h>
#include <StringUtils.h>
#include <string.h>
#include "Slot.h"
#include "Dictionary/Word.h"

Slot_ptr create_slot(Slot_type type, const char *tag) {
    Slot_ptr result = malloc(sizeof(Slot));
    result->type = type;
    result->tag = str_copy(result->tag, tag);
    return result;
}

Slot_ptr create_slot2(const char *slot) {
    Slot_ptr result = malloc(sizeof(Slot));
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

String_ptr slot_to_string(Slot_ptr slot) {
    if (slot->type == O){
        return create_string2("O");
    } else {
        if (slot->type == B){
            return create_string3("B-", slot->tag);
        } else {
            return create_string3("I-", slot->tag);
        }
    }
}

void free_slot(Slot_ptr slot) {
    free(slot->tag);
    free(slot);
}
