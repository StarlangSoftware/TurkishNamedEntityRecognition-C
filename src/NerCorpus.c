//
// Created by Olcay Taner YILDIZ on 4.06.2023.
//

#include <FileUtils.h>
#include <string.h>
#include <stdlib.h>
#include <Memory/Memory.h>
#include "NerCorpus.h"
#include "NamedEntitySentence.h"

/**
 * Another constructor of NERCorpus which takes a fileName of the corpus as an input, reads the
 * corpus from that file.
 *
 * @param fileName Name of the corpus file.
 */
Corpus_ptr create_ner_corpus(const char *file_name) {
    Corpus_ptr result = create_corpus();
    Array_list_ptr lines = read_lines(file_name);
    for (int i = 0; i < lines->size; i++){
        corpus_add_sentence(result, create_named_entity_sentence(array_list_get(lines, i)));
    }
    free_array_list(lines, free_);
    return result;
}

void free_ner_corpus(Corpus_ptr corpus) {
    free_array_list(corpus->sentences, (void (*)(void *)) free_name_entity_sentence);
    free_array_list(corpus->paragraphs, NULL);
    free_counter_hash_map(corpus->word_list);
    free_(corpus);
}
