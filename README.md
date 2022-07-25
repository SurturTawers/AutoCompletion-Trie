# AutoCompletion-Trie
Autocompletion implementation using a Trie.

## Details 
It uses an english dictionary to create a Trie, then, an input word is entered by console.\
It returns K words with the most priority (most searched words) that have the input word as a substring, if there's not enough words, it removes a character from the input word and returns the K words.\
It repeats the process until the input word has no more letters or it finds the K words. Everytime the word is returned it adds one unit to it's priority, it can be seen in the output results file (resultados.txt).
