// A Magill
// CS 3358 251 - Dr. Priebe
// TxState Spring 2015
//
// Assignment 7 - Plagiarism Checker
//
// Goal: "Try to (quickly) determine the similarities between documents
//        in a large set to see if you can find out if plagiarism is going
//        on within the group."
//
// Strategy: Read in each text file from a given directory, hashing m-word
//           chunks as file is read (m is given at command line, 5 or 6 are
//           good choices for m). We will store the number of the document
//           being processed as the value corresponding to each key (documents
//           are numbered from 1..num_docs in descending alphabetical order).
//           We will store a particular hash key once per document. We are
//           considering collision between keys in different documents as
//           duplicate m-word chunks, possibly indicating plagiarism. The
//           hashing function will produce some false positives, we hope to
//           minimize these by choosing an effective hashing strategy for
//           the given input (probably 5 or 6 word english strings with no punct.)
//           I have chosen a bitwise hashing functionm written by Justin Sobel
//           to generate hash keys.
//           ...
//
"
//
#include <iostream>
#include <string>

//typedef unsigned int (*HashFunction)(const std::string&);

//unsigned int JSHash  (const std::string& str);

int main() {
    //return true;
}

unsigned int JSHash(const std::string& str) {
    //bitwise hash function written by Justin Sobel
}
