//
// Created by Olcay Taner YILDIZ on 3.06.2023.
//

#include <StringUtils.h>
#include <Dictionary/Word.h>
#include <FileUtils.h>
#include <Memory/Memory.h>
#include "Gazetteer.h"

/**
 * A constructor for a specific gazetteer. The constructor takes name of the gazetteer and file name of the
 * gazetteer as input, reads the gazetteer from the input file.
 * @param name Name of the gazetteer. This name will be used in programming to separate different gazetteers.
 * @param file_name File name of the gazetteer data.
 */
Gazetteer_ptr create_gazetteer(const char *name, const char *file_name) {
    Gazetteer_ptr result = malloc_(sizeof(Gazetteer));
    result->name = str_copy(result->name, name);
    result->data = read_hash_set(file_name);
    return result;
}

/**
 * Frees memory allocated for the Gazetteer object. Frees name and hash set data.
 * @param gazetteer Gazetteer object to deallocate.
 */
void free_gazetteer(Gazetteer_ptr gazetteer) {
    free_hash_set(gazetteer->data, free_);
    free_(gazetteer->name);
    free_(gazetteer);
}

/**
 * The most important method in Gazetteer class. Checks if the given word exists in the gazetteer. The check
 * is done in lowercase form.
 * @param gazetteer Current gazetteer object
 * @param word Word to be search in Gazetteer.
 * @return True if the word is in the Gazetteer, False otherwise.
 */
bool gazetteer_contains(const Gazetteer *gazetteer, const char *word) {
    char *lowerCase = to_lowercase(word);
    bool result = hash_set_contains(gazetteer->data, lowerCase);
    free_(lowerCase);
    return result;
}
