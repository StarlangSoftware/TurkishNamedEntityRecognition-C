//
// Created by Olcay Taner YILDIZ on 3.06.2023.
//

#ifndef NAMEDENTITYRECOGNITION_SLOT_H
#define NAMEDENTITYRECOGNITION_SLOT_H

#include "SlotType.h"
#include "StringUtils.h"

struct slot {
    Slot_type type;
    char *tag;
};

typedef struct slot Slot;

typedef Slot *Slot_ptr;

Slot_ptr create_slot(Slot_type type, const char* tag);

Slot_ptr create_slot2(const char* slot);

void free_slot(Slot_ptr slot);

String_ptr slot_to_string(Slot_ptr slot);

#endif //NAMEDENTITYRECOGNITION_SLOT_H
