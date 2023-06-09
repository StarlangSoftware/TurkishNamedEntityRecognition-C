//
// Created by Olcay Taner YILDIZ on 3.06.2023.
//

#include <stdlib.h>
#include <StringUtils.h>
#include <Dictionary/Word.h>
#include <stdio.h>
#include <FileUtils.h>
#include <string.h>
#include "Gazetteer.h"

/**
 * A constructor for a specific gazetteer. The constructor takes name of the gazetteer and file name of the
 * gazetteer as input, reads the gazetteer from the input file.
 * @param name Name of the gazetteer. This name will be used in programming to separate different gazetteers.
 * @param fileName File name of the gazetteer data.
 */
Gazetteer_ptr create_gazetteer(const char *name, const char *file_name) {
    Gazetteer_ptr result = malloc(sizeof(Gazetteer));
    result->name = str_copy(result->name, name);
    result->data = create_hash_set((unsigned int (*)(const void *, int)) hash_function_string,
                                   (int (*)(const void *, const void *)) compare_string);
    FILE* input_file;
    char line[MAX_LINE_LENGTH];
    input_file = fopen(file_name, "r");
    char* input = fgets(line, MAX_LINE_LENGTH, input_file);
    while (input != NULL){
        line[strcspn(line, "\n")] = 0;
        char* word = str_copy(word, line);
        hash_set_insert(result->data, word);
        input = fgets(line, MAX_LINE_LENGTH, input_file);
    }
    fclose(input_file);
    return result;
}

void free_gazetteer(Gazetteer_ptr gazetteer) {
    free_hash_set(gazetteer->data, free);
    free(gazetteer->name);
    free(gazetteer);
}

/**
 * The most important method in {@link Gazetteer} class. Checks if the given word exists in the gazetteer. The check
 * is done in lowercase form.
 * @param word Word to be search in Gazetteer.
 * @return True if the word is in the Gazetteer, False otherwise.
 */
bool gazetteer_contains(const Gazetteer *gazetteer, const char *word) {
    char *lowerCase = to_lowercase(word);
    bool result = hash_set_contains(gazetteer->data, lowerCase);
    free(lowerCase);
    return result;
}
