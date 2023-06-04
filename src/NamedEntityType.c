//
// Created by Olcay Taner YILDIZ on 4.06.2023.
//
#include <Dictionary/Word.h>
#include <string.h>
#include "NamedEntityType.h"

/**
 * Function to convert a string entity type to {@link NamedEntityType} type.
 * @param entityType Entity type in string form
 * @return Entity type in {@link NamedEntityType} form
 */
Named_entity_type get_named_entity_type(const char *entity_type) {
    char* upperCase = to_uppercase(entity_type);
    if (strlen(upperCase) == 0){
        return NONE;
    } else {
        if (strcmp(upperCase, "PERSON") == 0){
            return PERSON;
        } else {
            if (strcmp(upperCase, "LOCATION") == 0){
                return LOCATION;
            } else {
                if (strcmp(upperCase, "ORGANIZATION") == 0){
                    return ORGANIZATION;
                } else {
                    if (strcmp(upperCase, "TIME") == 0){
                        return TIME;
                    } else {
                        if (strcmp(upperCase, "MONEY") == 0){
                            return MONEY;
                        } else {
                            return NONE;
                        }
                    }
                }
            }
        }
    }
}

/**
 * Function to convert a {@link NamedEntityType} to string form.
 * @param entityType Entity type in {@link NamedEntityType} form
 * @return Entity type in string form
 */
char *named_entity_type_to_string(Named_entity_type named_entity_type) {
    switch (named_entity_type){
        case PERSON:
            return "PERSON";
        case LOCATION:
            return "LOCATION";
        case ORGANIZATION:
            return "ORGANIZATION";
        case TIME:
            return "TIME";
        case MONEY:
            return "MONEY";
        default:
            return "NONE";
    }
}

