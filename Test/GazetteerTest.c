//
// Created by Olcay Taner YILDIZ on 4.06.2023.
//

#include <stdio.h>
#include <Memory/Memory.h>
#include "../src/Gazetteer.h"

int main(){
    start_memory_check();
    Gazetteer_ptr gazetteer = create_gazetteer("location", "gazetteer-location.txt");
    if (!gazetteer_contains(gazetteer, "bağdat")){
        printf("Error in Gazetteer test 1\n");
    }
    if (!gazetteer_contains(gazetteer, "belçika")){
        printf("Error in Gazetteer test 2\n");
    }
    if (!gazetteer_contains(gazetteer, "körfez")){
        printf("Error in Gazetteer test 3\n");
    }
    if (!gazetteer_contains(gazetteer, "küba")){
        printf("Error in Gazetteer test 4\n");
    }
    if (!gazetteer_contains(gazetteer, "varşova")){
        printf("Error in Gazetteer test 5\n");
    }
    if (!gazetteer_contains(gazetteer, "krallık")){
        printf("Error in Gazetteer test 6\n");
    }
    if (!gazetteer_contains(gazetteer, "berlin")){
        printf("Error in Gazetteer test 7\n");
    }
    if (!gazetteer_contains(gazetteer, "BAĞDAT")){
        printf("Error in Gazetteer test 1\n");
    }
    if (!gazetteer_contains(gazetteer, "BELÇİKA")){
        printf("Error in Gazetteer test 2\n");
    }
    if (!gazetteer_contains(gazetteer, "KÖRFEZ")){
        printf("Error in Gazetteer test 3\n");
    }
    if (!gazetteer_contains(gazetteer, "KÜBA")){
        printf("Error in Gazetteer test 4\n");
    }
    if (!gazetteer_contains(gazetteer, "VARŞOVA")){
        printf("Error in Gazetteer test 5\n");
    }
    if (!gazetteer_contains(gazetteer, "KRALLIK")){
        printf("Error in Gazetteer test 6\n");
    }
    if (!gazetteer_contains(gazetteer, "BERLİN")){
        printf("Error in Gazetteer test 7\n");
    }
    free_gazetteer(gazetteer);
    end_memory_check();
}