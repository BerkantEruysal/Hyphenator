# Hyphenator

## Features

Hyphenator fixes the grammar issues if it encounters with an input that conflict following rules : 

- Some certain punctuations, period (.), comma (,), colon (:), semi-colon (;), question mark
(?), and exclamation mark(!), should be followed by a space.

- First letter of a sentence must be uppercase.

- Opening round, square and curly brackets, which are (, [, and {, respectively,
should have a corresponding closing round, square and curly brackets, which are ), ],
and }, respectively.

When Hyphenator checks for this rules, it hyphenates the fixed input. Hyphenator looks to following rules when it hyphenates : 

- In Turkish, the consonant between two vowels forms a syllable with the next
vowel: a-ra-ba, bi-çi-mi-ne, in-sa-nın, ka-ra-ca etc.

- If there are two consonants together, the first one forms a syllable with the vowel
before it while the second one forms a syllable with the vowel after it: al-dı, bir-lik,
sev-mek etc.

- If there are three consonants together, the first two of them form a syllable with
vowel before them, the third consonant forms a syllable with the vowel after it:
alt-lık, Türk-çe, kork-mak etc

This program can only hyphenates Turkish words, but turkish characters are not recognized, so avoid using them.


# LICENSE
[MIT](https://opensource.org/licenses/MIT) license
