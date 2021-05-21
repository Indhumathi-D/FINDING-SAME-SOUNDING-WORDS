# FINDING-SAME-SOUNDING-WORDS
There are lots of words existing in this world. One might get confused with spelling while typing the word if another word also existing with same pronunciation but with different meaning.
Example:
 While typing the word peak, I might get confused whether it should be peek or peak. This package will list the words that have same sound as the word entered by user. So that user will choose appropriate word. There is documentation available called soundex algorithm to develop this concept. I am going to implement code to find same sounding words using that documentation.
The steps involved in the algorithm are:
The Soundex code for a name consists of a letter followed by three numerical digits.
1.Retain the first letter of the name and drop all other occurrences of a, e, i, o, u, y, h, w.
2.Replace consonants with digits as follows (after the first letter):
ob, f, p, v → 1
oc, g, j, k, q, s, x, z → 2
od, t → 3
ol → 4
om, n → 5
or → 6
3.If two or more letters with the same number are adjacent in the original name (before step 1), only retain the first letter; also two letters with the same number separated by 'h' or 'w' are coded as a single number, whereas such letters separated by a vowel are coded twice. This rule also applies to the first letter.
4.If we have too few letters in our word that we can't assign three numbers, append with zeros until there are three numbers. If we have four or more numbers, retain only the first three.
Using this algorithm, both "Robert" and "Rupert" return the same string "R163" which are pronounced as same.

![19mx108](https://user-images.githubusercontent.com/55494211/119179772-c5b19400-ba88-11eb-9722-b3653b7fee76.png)


