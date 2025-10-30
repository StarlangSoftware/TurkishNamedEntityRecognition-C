//
// Created by Olcay Taner YILDIZ on 4.06.2023.
//

#include <Corpus.h>
#include <Memory/Memory.h>

#include "../src/NerCorpus.h"

int main(){
    start_large_memory_check();
    Corpus_ptr ner_corpus = create_ner_corpus("nerdata.txt");
    if (corpus_sentence_count(ner_corpus) != 27556){
        printf("Error in ner corpus test 1\n");
    }
    if (corpus_number_of_words(ner_corpus) != 492233){
        printf("Error in ner corpus test 2\n");
    }
    free_ner_corpus(ner_corpus);
    end_memory_check();
}