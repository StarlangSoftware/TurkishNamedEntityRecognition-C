//
// Created by Olcay Taner YILDIZ on 4.06.2023.
//

#include <stdio.h>
#include <string.h>
#include "../src/Slot.h"

int main(){
    Slot_ptr slot1 = create_slot2("B-depart_date.month_name");
    if (slot1->type != B){
        printf("Error in Slot 1");
    }
    if (strcmp(slot1->tag, "depart_date.month_name") != 0){
        printf("Error in Slot 2");
    }
    free_slot(slot1);
    Slot_ptr slot2 = create_slot2("O");
    if (slot2->type != O){
        printf("Error in Slot 3");
    }
    free_slot(slot2);
    Slot_ptr slot3 = create_slot2("I-round_trip");
    if (slot3->type != I){
        printf("Error in Slot 4");
    }
    if (strcmp(slot3->tag, "round_trip") != 0){
        printf("Error in Slot 5");
    }
    free_slot(slot3);
}